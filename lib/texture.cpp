#include "texture.h"

#include <string>
#include <iostream>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "OpenGL/GL.h"
#include "OpenGL/glext.h"


jE::Texture::Texture(unsigned int w, unsigned int h) : level(0), width(w), height(h) {
    glGenTextures(1, &this->id);

    this->loadEmpty();
}

jE::Texture::Texture(unsigned int w, unsigned int h, unsigned int l) : level(l), width(w), height(h) {
    glGenTextures(1, &this->id);

    this->loadEmpty();
}

jE::Texture::Texture(std::string path) : level(0), path(path) {
    glGenTextures(1, &this->id);

    this->loadSurface();
}

jE::Texture::Texture(std::string path, unsigned int l) : level(l), path(path) {
    glGenTextures(1, &this->id);

    this->loadSurface();
}

jE::Texture::~Texture() {
     if(this->id) {
	 glDeleteTextures(1, &this->id);
     }
}

bool jE::Texture::loadSurface() {
    SDL_Surface *tex;
    tex = IMG_Load(this->path.c_str());

    if(tex == NULL) {
        std::cout << "Texture file not found : " << this->path << std::endl;
        return false;
    }

    this->bind();

    // TODO: a texParameter editor
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    this->width = tex->w;
    this->height = tex->h;

    // TODO: format checker
    glTexImage2D(
        GL_TEXTURE_2D,
        0, GL_RGBA,
        tex->w, tex->h,
        0, GL_BGRA,
        GL_UNSIGNED_BYTE, 
        tex->pixels
    );

    this->unbind();
    SDL_FreeSurface(tex);

    return true;
}

bool jE::Texture::loadEmpty() {
    this->bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(
        GL_TEXTURE_2D,
        0, GL_RGBA32F_ARB,
        this->width, this->height,
        0, GL_RGBA,
        GL_UNSIGNED_BYTE, 
        0
    );

    this->unbind();
    return true;
}

void jE::Texture::bind() const {
    glActiveTexture(GL_TEXTURE0+this->level);
    glBindTexture(GL_TEXTURE_2D, this->id);
}

void jE::Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

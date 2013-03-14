#include "renderbuffer.h"

#include "OpenGL/GL.h"
#include "OpenGL/glext.h"


jE::Renderbuffer::Renderbuffer(unsigned int w, unsigned int h) : 
    width(w), height(h) {
    glGenRenderbuffers(1, &this->id);

    this->establish();
}

jE::Renderbuffer::~Renderbuffer() {
    if(this->id) {
        glDeleteRenderbuffers(1, &this->id);
    }
}

void jE::Renderbuffer::bind() const {
    glBindRenderbuffer(GL_RENDERBUFFER, this->id);
}

void jE::Renderbuffer::unbind() const {
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

void jE::Renderbuffer::establish() {
    this->bind();
    
    // TODO: other parameter editor
    glRenderbufferStorage(
        GL_RENDERBUFFER,
        GL_DEPTH_COMPONENT24,
        this->width, this->height
    );

    // TODO: error checker

    this->unbind();
}

/*

   libjEngine - C++ 3D library
Copyright (C) 2013  Jacques Rott <jacques.rott@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "shader.h"
#include "tools.h"

#include "OpenGL/GL.h"
#include "OpenGL/glext.h"
#include "SDL/SDL.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdarg.h>

// TODO: better error checker


jE::Shader::Shader(std::string path, GLuint type) {
    this->path = path;
    this->type = type;

    this->id = glCreateShader(this->type);
    this->load();
}

jE::Shader::~Shader() {
    if(this->id)
        glDeleteShader(this->id);
}

bool jE::Shader::load(void) {
    char *src = (char*) this->readSrc().c_str();

    glShaderSource(this->id, 1, (const GLchar**)&src, NULL);
    glCompileShader(this->id);

    GLint blen = 0;
    GLsizei slen = 0;

    glGetShaderiv(this->id, GL_COMPILE_STATUS, &blen);
    if (blen != GL_TRUE) {
        GLchar* compiler_log = (GLchar*)malloc(blen);
        glGetShaderInfoLog(this->id, blen, &slen, compiler_log);
        std::cout << "compiler_log:\n" << compiler_log << std::endl;
        delete compiler_log;
        return false;
    }
    return true;
}

std::string jE::Shader::readSrc(void) {
    std::ifstream fshade;
    fshade.open(this->path.c_str());

    if(!fshade) {
        std::cout << "Shader file not found : ";
        std::cout << this->path << std::endl;
        return NULL;
    }

    std::stringstream stream;

    stream << fshade.rdbuf();
    fshade.close();

    return stream.str();
}

jE::Program::Program() {
    this->id = glCreateProgram();
}

jE::Program::Program(std::vector<jE::Shader*> shaders) {
    this->id = glCreateProgram();

    this->addShader(shaders);
}

jE::Program::Program(jE::Shader *vs, jE::Shader *fs) {
    this->id = glCreateProgram();

    this->addShader(vs);
    this->addShader(fs);
}

jE::Program::Program(jE::Shader *s) {
    this->id = glCreateProgram();

    this->addShader(s);
}

jE::Program::~Program() {
    if(this->id)
        glDeleteProgram(this->id);
}

bool jE::Program::addShader(std::vector<jE::Shader*> shaders) {
    unsigned int i;
    for(i = 0; i < shaders.size(); ++i) {
        glAttachShader(this->id, (*shaders[i]).id);
    }
    glLinkProgram(this->id);

    return this->getLog();
}

bool jE::Program::addShader(jE::Shader *s) {
    glAttachShader(this->id, s->id);
    glLinkProgram(this->id);

    return this->getLog();
}

bool jE::Program::delShader(jE::Shader *s) {
    glDetachShader(this->id, s->id);
    glLinkProgram(this->id);

    return this->getLog();
}

bool jE::Program::getLog() const {
    GLint blen = 0;
    GLsizei slen = 0;

    glGetProgramiv(this->id, GL_LINK_STATUS, &blen);
    if (blen != GL_TRUE) {
        GLchar* linker_log = (GLchar*)malloc(blen);
        glGetProgramInfoLog(this->id, blen, &slen, linker_log);

        std::cout << "linker_log:\n" << linker_log << std::endl;
        delete linker_log;
        return false;
    }
    return true;
}

void jE::Program::bind() const {
    glUseProgram(this->id);
}

void jE::Program::unbind() const {
    glUseProgram(0);
}

GLint jE::Program::getUniLocation(const std::string name) const {
    return glGetUniformLocation(this->id, (const GLchar *) name.c_str());
}

GLint jE::Program::getAttribLocation(const std::string name) const {
    return glGetAttribLocation(this->id, (const GLchar *) name.c_str());
}


jE::FragmentShader::FragmentShader(std::string path) : Shader(path, GL_FRAGMENT_SHADER) {}
jE::VertexShader::VertexShader(std::string path) : Shader(path, GL_VERTEX_SHADER) {}

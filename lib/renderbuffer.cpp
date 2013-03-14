
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

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

#include "framebuffer.h"

#include "renderbuffer.h"

#include <string>
#include <iostream>

#include "OpenGL/GL.h"
#include "OpenGL/glext.h"

jE::Framebuffer::Framebuffer() :
    colorAttachment(0) {
    glGenFramebuffers(1, &this->id);
}

jE::Framebuffer::Framebuffer(const jE::Texture *tex, const jE::Renderbuffer *rb) : 
    colorAttachment(0) {
    glGenFramebuffers(1, &this->id);
    this->bind();
    if(tex) {
        this->addColorAttachment(tex);
    } 
    if(rb) {
        this->addRenderAttachment(rb);
    }
    this->unbind();
}

jE::Framebuffer::~Framebuffer() {
    if(this->id) {
        glDeleteFramebuffers(1, &this->id);
    }
}

void jE::Framebuffer::bind() const {
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
}

void jE::Framebuffer::unbind() const {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

bool jE::Framebuffer::addColorAttachment(const jE::Texture *tex) {
    glFramebufferTexture2D(
        GL_FRAMEBUFFER,
        GL_COLOR_ATTACHMENT0+this->colorAttachment,
        GL_TEXTURE_2D, tex->id,
        0
    );

    ++this->colorAttachment;
    return this->check();
}

bool jE::Framebuffer::addRenderAttachment(const jE::Renderbuffer *rb) {
    // TODO: attachment type editor
    glFramebufferRenderbuffer(
        GL_DRAW_FRAMEBUFFER,
        GL_DEPTH_ATTACHMENT,
        GL_RENDERBUFFER,
        rb->id
    );

    return this->check();
}


bool jE::Framebuffer::addColorAttachmentWB(const jE::Texture *tex) {
    this->bind();
    bool status = this->addColorAttachment(tex);
    this->unbind();
    return status;
}

bool jE::Framebuffer::addRenderAttachmentWB(const jE::Renderbuffer *rb) {
    this->bind();
    bool status = this->addRenderAttachment(rb);
    this->unbind();
    return status;
}

bool jE::Framebuffer::check() const {
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    std::string msg;
    if(status != GL_FRAMEBUFFER_COMPLETE) {
        switch(status) {
            case GL_FRAMEBUFFER_UNDEFINED:
                msg = "GL_FRAMEBUFFER_UNDEFINED";
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
                msg = "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
                msg = "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
                msg = "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER";
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
                msg = "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER";
                break;
            case GL_FRAMEBUFFER_UNSUPPORTED:
                msg = "GL_FRAMEBUFFER_UNSUPPORTED";
                break;
            case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
                msg = "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE";
                break;
            case 0:
            default:
                msg = "Unknown error";
                break;
        }

        std::cout << "Framebuffer error : " << msg << std::endl;
        return false;
    }
    return true;
}


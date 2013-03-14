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


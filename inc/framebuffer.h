#ifndef __FBO__
#define __FBO__

#include "OpenGL/GL.h"

#include "texture.h"
#include "renderbuffer.h"


namespace jE {
    /*
     *  Generates a OpenGL Framebuffer Object
     *
     */
    class Framebuffer {
    private:
        /*
         *  Check if Attachment linking is error with error expressing
         *  @return: boolean if no error
         */
        bool check(void) const;
        unsigned int colorAttachment; // Texture Attachment color level

    public:
        Framebuffer(void);
        /*
         *  Construct a FBO with Texture as destination and a RBO as
         *  source
         *      tex: Texture draw Color Attachment
         *      rb:  Renderbuffer as depth attachment
         */
        Framebuffer(const Texture *tex, const Renderbuffer *rb);
        ~Framebuffer(void);

        /*
         *  Binds the FBO
         */
        void bind(void) const;

        /* 
         *  Unbinds the FBO
         */
        void unbind(void) const;

        /*
         *  Adds a color Attachment to the FBO
         *      tex:    Texture object destination
         *  @return:    boolean if linking ok
         */
        bool addColorAttachment(const Texture *tex);

        /*
         *  Adds a depth Attachment to the FBO
         *       rb:    Renderbuffer object as depth source
         *  @return:    boolean if linking ok
         */
        bool addRenderAttachment(const Renderbuffer *rb);

        /*
         *  Adds a color Attachment to the FBO With automatic fbo binding and
         *  unbinding
         *      tex:    Texture object destination
         *  @return:    boolean if linking ok
         */
        bool addColorAttachmentWB(const Texture *tex);      // With Binding

        /*
         *  Adds a depth Attachment to the FBO with automatic fbo binding and
         *  unbinding
         *       rb:    Renderbuffer object as depth source
         *  @return:    boolean if linking ok
         */
        bool addRenderAttachmentWB(const Renderbuffer *rb); // With Binding

        GLuint id;  // OpenGL FBO ID
    };
};


#endif

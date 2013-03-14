#ifndef __RBO__
#define __RBO__

#include "OpenGL/GL.h"

// TODO: Add RBO depth parameter

namespace jE {
    /*
     *  Manages a RBO
     */
    class Renderbuffer {
    private:
        /*
         *  Establish the RBO params
         */
        void establish(void);

    public:
        /*
         *  Initialize a RBO
         *      w: RBO draw width
         *      h: RBO draw height
         */
        Renderbuffer(unsigned int w, unsigned int h);
        ~Renderbuffer(void);

        /*
         *  Binds the RBO
         */
        void bind(void) const;
        /*
         *  Unbinds the RBO
         */
        void unbind(void) const;

        unsigned int width;     // RBO draw width
        unsigned int height;    // RBO draw height

        GLuint id;              // OpenGL RBO id
    };
};


#endif

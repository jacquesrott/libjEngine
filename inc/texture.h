#ifndef __TEXTURE__
#define __TEXTURE__

#include <string>

#include "SDL/SDL.h"
#include "OpenGL/GL.h"
#include "OpenGL/glext.h"


namespace jE {
    class Texture {
    private:
        std::string path;   // filesystem path to the texture

        /*
         *  Loads the SDL surface of the picture to the GPU
         *  @return: boolean if no error
         */
        bool loadSurface(void);

        /*
         *  Loads an empty texture to the GPU
         *  @return: boolean if no error
         */
        bool loadEmpty(void);

    public:
        /*
         *  Initializes an empty (black) Texture object
         *      w: texture's width
         *      h: texture's height
         */
        Texture(unsigned int w, unsigned int h);
        /*
         *  Initializes an empty (black) Texture object
         *      w: texture's width
         *      h: texture's height
         *      l: texture's level
         */
        Texture(unsigned int w, unsigned int h, unsigned int l);
        /*
         *  Initilizes a texture from a file
         *      path: filesystem path to the picture
         */
        Texture(std::string path);
        /*
         *  Initilizes a texture from a file
         *      path: filesystem path to the picture
         *      l:    texture's level
         */
        Texture(std::string path, unsigned int l);
        ~Texture(void);

        unsigned int width;     // texture's width
        unsigned int height;    // texture's height

        GLuint id;              // OpenGL Texture object id
        int level;              // Drawing level

        /*
         *  Binds the Texture object
         */
        void bind(void) const;
        /*
         *  Unbinds the Texture objects
         */
        void unbind(void) const;
    };
};


#endif

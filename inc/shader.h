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

#ifndef __SHADER__
#define __SHADER__

#include <string>
#include <vector>

#include "OpenGL/GL.h"
#include "OpenGL/glext.h"

namespace jE {

    /*
     *  Shader parent class
     */
    class Shader {
    private:
        /*
         * Loads and compiles the shader
         * @return: boolean if no compilation error
         */
        bool load(void);

        /*
         *  Loads the shader's source
         *  @return: shader's source
         */
        std::string readSrc(void);
        std::string path;       // shader file system path
        GLuint type;            // Shader type (Vertex or Fragement)

    public:
        Shader(std::string path, GLuint type);
        ~Shader();
        GLuint id;      // Shader OpenGL id
    };


    /*
     *  Fragment Shader type
     */
    class FragmentShader : public Shader {
    public:
        FragmentShader(std::string path);
    };

    /*
     *  Vertex Shader type
     */
    class VertexShader : public Shader {
    public:
        VertexShader(std::string path);
    };


    /*
     *  Program class managing all the shader
     */
    class Program {
    private:
        GLuint id;      // Program OpenGL id

        /*
         *  Prints the shader linking logs
         *  @return: boolean if no error
         */
        bool getLog(void) const;

    public:
        Program(void);
        /*
         * Initialize multiple shaders
         *  shaders:    Shaders list
         */
        Program(std::vector<Shader*> shaders);
        /*
         *  Initializing a Program with a VertexShader and a FragmentShader
         *      vs:     First Shader object to add (mainly Vertex Shader)
         *      fs:     Second Shader object to add (mainly Fragment Shader)
         */
        Program(Shader *vs, Shader *fs);
        /*
         *  Initialize a Program with one shader
         *      s:      Shader object to link
         */
        Program(Shader *s);
        ~Program(void);

        /*
         *  Binds the program
         */
        void bind() const;
        /*
         *  Unbinds the program
         */
        void unbind() const;

        /*
         *  Adds a list of shaders to the program
         *      shaders:    all the shader object to link
         *      @return:    boolean if no error
         */
        bool addShader(std::vector<Shader*> shaders);
        /*
         *  Adds a Shader object to the program
         *      s:       Shader object to link
         *      @return: boolean if no error
         */
        bool addShader(Shader *s);
        /*
         *  Unlink a shader object of the program
         *      s:       Shader object to delete
         *      @return: boolean if no error
         */
        bool delShader(Shader *s);

        /*
         *  Returns the uniform variable location id
         *      name:    uniform variable name
         *      @return: uniform variable location id
         */
        GLint getUniLocation(const std::string name) const;
        /*
         *  Returns the Attribute variable location id
         *      name:    Attribute variable name
         *      @return: Attribute variable location id
         */
        GLint getAttribLocation(const std::string name) const;
    };
};

#endif

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

#ifndef __GEOM__
#define __GEOM__

#include <vector>
#include "OpenGL/GL.h"

#include "attribute.h"

namespace jE {
    /*
     *  Manages VBO and IBO initilization
     *  
     */
    class Geometry {
    private:
        unsigned int dataSize;      // VBO binary size
        unsigned int indexMemSize;  // IBO binary size
        unsigned int indexSize;     // number of indices
        std::vector<Attr> attrList; // List of geometry attribute type, ordered

        GLuint vbo;     // Vertex Buffer Object
        GLuint ibo;     // Index Buffer Object

        /*
         *  Compute the VBO binary data size
         */
        void getDataSize(void);

        /*
         *  Sets all VBO states for drawing
         */
        void setStates(void) const;

        /*
         *  Unsets all VBO states
         */
        void unsetStates(void) const;

        /*
         *  Sets all VBO attributes pointers
         */
        void setPointer(void) const;

        /*
         *  Binds the VBO
         */
        void bind(void) const;
        /*
         *  Unbinds the VBO
         */
        void unbind(void) const;

        /*
         *  Binds the IBO
         */
        void bindIndex(void) const;
        /*
         *  Unbinds the IBO
         */
        void unbindIndex(void) const;

        /*
         *  Sends VBO data to the GPU
         *      mesh: VBO data (Vertices, Normals, Texture coords...
         */
        void boundBuffer(const GLfloat *mesh);
        /*
         *  Sends IBO data to the GPU
         *      i:  indices data
         */
        void boundIndex(const GLuint *i);

    public:
        Geometry(const GLfloat *mesh, const GLuint *i, const int nbIndex, const std::vector<Attr> a);
        ~Geometry(void);

        /*
         *  Draws the geometry
         *      mode:   how to draw (Points, lines, triangles...)
         */
        void draw(const GLenum mode) const;
    };
};

#endif

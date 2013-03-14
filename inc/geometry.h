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

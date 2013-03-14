#include "geometry.h"

#include "attribute.h"

#include "OpenGL/GL.h"
#include "OpenGL/glext.h"

#include <cstddef>
#include <iostream>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

jE::Geometry::Geometry(const GLfloat *mesh, const GLuint *i, const int nbIndex, const std::vector<jE::Attr> a) {
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ibo);

    this->indexMemSize = sizeof(GLuint)*nbIndex;
    this->indexSize = nbIndex;
    this->attrList = a;
    getDataSize();

    boundBuffer(mesh);
    boundIndex(i);
}

jE::Geometry::~Geometry() {
    if(this->vbo) {
        glDeleteBuffers(1, &this->vbo);
        this->vbo = 0;
    }
    if(this->ibo) {
        glDeleteBuffers(1, &this->ibo);
        this->ibo = 0;
    }
}

void jE::Geometry::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
}

void jE::Geometry::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void jE::Geometry::bindIndex() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
}

void jE::Geometry::unbindIndex() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void jE::Geometry::getDataSize() {
    this->dataSize = 0;
    int i;

    for(i = 0; i < this->attrList.size() ; ++i) {
        this->dataSize += this->attrList[i].size * this->attrList[i].number;
    }
    this->dataSize *= sizeof(GLfloat);
}

void jE::Geometry::setStates() const {
    int i;
    for(i = 0 ; i < this->attrList.size() ; ++i) {
        switch(this->attrList[i].type) {
            case ATTYPE_VERTEX:
                glEnableClientState(GL_VERTEX_ARRAY);
                break;
            case ATTYPE_NORMAL:
                glEnableClientState(GL_NORMAL_ARRAY);
                break;
            case ATTYPE_COLOR:
                glEnableClientState(GL_COLOR_ARRAY);
                break;
            case ATTYPE_TEXCOORD:
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                break;
            case ATTYPE_OTHER:
            default:
                break;
        }
    }
}

void jE::Geometry::unsetStates() const {
    int i;
    for(i = ((int) this->attrList.size())-1 ; i >= 0 ; --i) {
        switch(this->attrList[i].type) {
            case ATTYPE_VERTEX:
                glDisableClientState(GL_VERTEX_ARRAY);
                break;
            case ATTYPE_NORMAL:
                glDisableClientState(GL_NORMAL_ARRAY);
                break;
            case ATTYPE_COLOR:
                glDisableClientState(GL_COLOR_ARRAY);
                break;
            case ATTYPE_TEXCOORD:
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                break;
            case ATTYPE_OTHER:
            default:
                break;
        }
    }
}

void jE::Geometry::setPointer() const {
    int i;
    int stride = 0;
    for(i = 0 ; i < this->attrList.size() ; ++i) {
        switch(this->attrList[i].type) {
            case ATTYPE_VERTEX:
                glVertexPointer(
                    this->attrList[i].size, GL_FLOAT, 
                    this->attrList[i].size * sizeof(GLfloat), 
                    BUFFER_OFFSET(stride)
                );
                break;
            case ATTYPE_NORMAL:
                glNormalPointer(
                    GL_FLOAT,
                    this->attrList[i].size * sizeof(GLfloat), 
                    BUFFER_OFFSET(stride)
                );
                break;
            case ATTYPE_COLOR:
                glColorPointer(
                    this->attrList[i].size, GL_FLOAT, 
                    this->attrList[i].size * sizeof(GLfloat), 
                    BUFFER_OFFSET(stride)
                );
                break;
            case ATTYPE_TEXCOORD:
                glTexCoordPointer(
                    this->attrList[i].size, GL_FLOAT, 
                    this->attrList[i].size * sizeof(GLfloat), 
                    BUFFER_OFFSET(stride)
                );
                break;
            case ATTYPE_OTHER:
            default:
                break;
        }
        stride += (this->attrList[i].number * sizeof(GLfloat) * this->attrList[i].size);
    }
}

void jE::Geometry::boundBuffer(const GLfloat *mesh) {
    this->bind();

    glBufferData(GL_ARRAY_BUFFER, this->dataSize, mesh, GL_STATIC_DRAW);

    this->unbind();
}

void jE::Geometry::boundIndex(const GLuint *i) {
    this->bindIndex();

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indexMemSize, i, GL_STATIC_DRAW);

    this->unbindIndex();
}

void jE::Geometry::draw(const GLenum mode) const {
    this->bind();
    this->setStates();
    this->setPointer();
    this->bindIndex();

    glDrawElements(mode, this->indexSize, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

    this->unbindIndex();
    this->unsetStates();
    this->unbind();
}

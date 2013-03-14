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

#include "plane.h"

#include "geometry.h"
#include "attribute.h"

#include <glm/glm.hpp>
#include <vector>
#include <cmath>
#include <iostream>


jE::Plane::Plane(const int w, const int h, const int t) : 
    width(w), height(h), tessaletion(t), up(false), matrix(glm::mat4(1.0)) {
    getGeom();
}

jE::Plane::Plane(const int w, const int h, const int t, const bool u) : 
    width(w), height(h), tessaletion(t), up(u), matrix(glm::mat4(1.0)) {
    getGeom();
}

jE::Plane::~Plane() {
    delete this->geom;
}

void jE::Plane::getGeom() {
    int nbVertex = pow(this->tessaletion, 2);
    float xoff = (float) this->width / (this->tessaletion-1);
    float yoff = (float) this->height / (this->tessaletion-1);
    float uvoff = 1.0f / (this->tessaletion-1);

    std::vector<Attr> attr(3);
    setAttrVertex3( &attr[0], nbVertex );
    setAttrNormal( &attr[1], nbVertex );
    setAttrTexCoord2( &attr[2], nbVertex );

    int meshSize=0;
    int a;
    for(a = 0 ; a < attr.size() ; ++a) {
        meshSize += attr[a].size * attr[a].number;
    }

    GLfloat *mesh = new GLfloat[meshSize];

    int i;
    int buffer = 0;
    for( i = 0 ; i < nbVertex ; ++i ) {
        mesh[buffer]      = xoff * floor(i%this->tessaletion);
        if(this->up) {
            mesh[buffer+1]    = yoff * floor(i/this->tessaletion);
            mesh[buffer+2]    = 0.0f;
        }
        else {
            mesh[buffer+1]    = 0.0f;
            mesh[buffer+2]    = yoff * floor(i/this->tessaletion);
        }
        buffer += 3;
    }
    for( i = 0 ; i < nbVertex ; ++i ) {
        mesh[buffer]      = 0.0f;
        if(this->up) {
            mesh[buffer+1]    = 0.0f;
            mesh[buffer+2]    = -1.0f;
        }
        else {
            mesh[buffer+1]    = 1.0f;
            mesh[buffer+2]    = 0.0f;
        }
        buffer += 3;
    }
    for( i = 0 ; i < nbVertex ; ++i ) {
        mesh[buffer]      = uvoff * floor(i%this->tessaletion);
        mesh[buffer+1]    = uvoff * floor(i/this->tessaletion);
        buffer += 2;
    }

    int nbIndices = pow((this->tessaletion-1), 2)*2*3;

    GLuint *index = new GLuint[nbIndices];
    int offset = 0;
    for( i = 0 ; i < nbVertex-this->tessaletion ; ++i ) {
        if((i+1) % this->tessaletion != 0) {
            if(this->up) {
                index[offset] = i + 1;
                index[offset+1] = i+this->tessaletion;
                index[offset+2] = i;
                index[offset+3] = i+1;
                index[offset+4] = i+this->tessaletion+1;
                index[offset+5] = i+this->tessaletion;
            }
            else {
                index[offset] = i;
                index[offset+1] = i+this->tessaletion;
                index[offset+2] = i + 1;
                index[offset+3] = i+this->tessaletion;
                index[offset+4] = i+this->tessaletion+1;
                index[offset+5] = i+1;
            }

            offset += 6;
        }
    }

    this->geom = new Geometry(mesh, index, nbIndices, attr);

    delete[] mesh;
    delete[] index;
}


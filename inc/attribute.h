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

#ifndef __ATTR__
#define __ATTR__

#include <string>

namespace jE {
    // TODO: complete type list if needed
    
    // Attribute type, used when initializing the VBO
    enum AttrType {
        ATTYPE_VERTEX,
        ATTYPE_NORMAL,
        ATTYPE_COLOR,
        ATTYPE_TEXCOORD,
        ATTYPE_OTHER    // OpenGL 3.* user defined attributes
    };


    typedef struct Attr {
        unsigned int size;
        unsigned int number;
        AttrType type;
        std::string name;
    } Attr;

    // Generating handy default attribute
    void setAttrVertex2(Attr *a, const unsigned int nb);    // 2D vertex
    void setAttrVertex3(Attr *a, const unsigned int nb);    // 3D vertex
    void setAttrNormal(Attr *a, const unsigned int nb);     // Normal
    void setAttrColor3(Attr *a, const unsigned int nb);     // RGB Color
    void setAttrColor4(Attr *a, const unsigned int nb);     // RGBA Color
    void setAttrTexCoord2(Attr *a, const unsigned int nb);  // UV coord
};

#endif

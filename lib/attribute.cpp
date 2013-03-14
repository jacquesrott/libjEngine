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

#include "attribute.h"

void jE::setAttrVertex2(jE::Attr *a, const unsigned int nb) {
    a->size = 2;
    a->number = nb;
    a->type =  ATTYPE_VERTEX;
}

void jE::setAttrVertex3(jE::Attr *a, const unsigned int nb) {
    a->size = 3;
    a->number = nb;
    a->type =  ATTYPE_VERTEX;
}

void jE::setAttrNormal(jE::Attr *a, const unsigned int nb) {
    a->size = 3;
    a->number = nb;
    a->type =  ATTYPE_NORMAL;
}

void jE::setAttrColor3(jE::Attr *a, const unsigned int nb) {
    a->size = 3;
    a->number = nb;
    a->type =  ATTYPE_COLOR;
}

void jE::setAttrColor4(jE::Attr *a, const unsigned int nb) {
    a->size = 4;
    a->number = nb;
    a->type =  ATTYPE_COLOR;
}

void jE::setAttrTexCoord2(jE::Attr *a, const unsigned int nb) {
    a->size = 2;
    a->number = nb;
    a->type =  ATTYPE_TEXCOORD;
}


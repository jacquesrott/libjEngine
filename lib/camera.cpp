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

#include "camera.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;


jE::Camera::Camera() : 
    pos(vec3(0.0)),
    direction(vec3(0.0, 0.0, 1.0)),
    up(vec3(0.0, 1.0, 0.0)) {
    this->refresh();
}

jE::Camera::Camera(vec3 p, vec3 d) : 
    pos(p), 
    direction(d),
    up(vec3(0.0, 1.0, 0.0)) {
    this->refresh();
}

jE::Camera::~Camera() {}

void jE::Camera::refresh() {
    this->matrix = lookAt(
        this->pos,
        this->pos+this->direction,
        this->up
    );
}

void jE::Camera::setDirection(vec3 d) {
    this->direction = d;
    this->refresh();
}

vec3 jE::Camera::getDirection() const {
    return this->direction;
}

void jE::Camera::setPos(vec3 p) {
    this->pos = p;
    this->refresh();
}

vec3 jE::Camera::getPos() const {
    return this->pos;
}


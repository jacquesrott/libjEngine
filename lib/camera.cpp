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


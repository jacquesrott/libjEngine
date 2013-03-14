#include "fpsCamera.h"
#include "camera.h"

#include "jmath.h"

#include <cmath>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;


jE::FPSCamera::FPSCamera() : 
    jE::Camera(), 
    pitch(0.0),
    yaw(0.0),
    roll(0.0),
    mvt(vec3(0.0)),
    mul(1.0),
    sens(2.0) {
}

jE::FPSCamera::FPSCamera(vec3 p, vec3 d, double m, double s) :
    jE::Camera(p, d),
    pitch(0.0),
    yaw(0.0),
    roll(0.0),
    mvt(vec3(0.0)),
    mul(m),
    sens(s) {
}

jE::FPSCamera::FPSCamera(vec3 p, vec3 d) : 
    jE::Camera(p, d), 
    pitch(0.0),
    yaw(0.0),
    roll(0.0),
    mvt(vec3(0.0)),
    mul(1.0),
    sens(2.0) {
}

jE::FPSCamera::FPSCamera(double m, double s) : 
    jE::Camera(), 
    pitch(0.0),
    yaw(0.0),
    roll(0.0),
    mvt(vec3(0.0)),
    mul(m),
    sens(s) {
}

jE::FPSCamera::~FPSCamera() {   }

void jE::FPSCamera::strafeLeft() {
    this->mvt += normalize(cross(-this->direction, this->up));
}

void jE::FPSCamera::strafeRight() {
    this->mvt += normalize(cross(this->direction, this->up));
}

void jE::FPSCamera::forward() {
    this->mvt += normalize(this->direction);
}

void jE::FPSCamera::backward() {
    this->mvt -= normalize(this->direction);
}

void jE::FPSCamera::vertUp() {
    this->mvt += normalize(this->up);
}

void jE::FPSCamera::vertDown() {
    this->mvt -= normalize(this->up);
}

void jE::FPSCamera::motion(double x, double y) {
    //printf("DX : %f - DY : %f\n", x, y);
    this->pitch += x * this->sens;
    this->yaw += -y * this->sens;

    if(this->yaw > 89.0) {
        this->yaw = 89.0;
    } else if(this->yaw < -89.0) {
        this->yaw = -89.0;
    }

    double r = cos(radians(this->yaw));
    double dy = sin(radians(this->yaw));
    double dx = r * cos(radians(this->pitch));
    double dz = r * sin(radians(this->pitch));

    this->setDirection(vec3(dx, dy, dz));
}

void jE::FPSCamera::update(const double dt) {
    if(this->mvt != vec3(0.0)) {
        this->mvt = normalize(this->mvt);
        this->mvt *= this->mul * dt;
        this->setPos(this->pos + this->mvt);
        this->mvt = vec3(0.0);
    }
}

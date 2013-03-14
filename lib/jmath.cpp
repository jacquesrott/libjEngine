#include "jmath.h"
#include <cmath>


double jE::radians(double d) {
    return d * (M_PI / 180.0);
}

double jE::degrees(double r) {
    return r * (180.0 / M_PI);
}

float jE::radiansf(float d) {
    return d * (M_PI / 180.0f);
}

float jE::degreesf(float r) {
    return r * (180.0f / M_PI);
}


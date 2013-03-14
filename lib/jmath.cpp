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


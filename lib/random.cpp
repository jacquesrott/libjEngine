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

#include "random.h"

#include <cstdlib>
#include <ctime>

void jE::setSeed(const int seed) {
    srand(seed);
}

void jE::initSeed(void) {
    srand((unsigned int) time(NULL));
}

float jE::randFloat(const float min, const float max) {
    return ( rand() / (double) RAND_MAX ) * ( max - min ) + min;
}

int jE::randInt(const int min, const int max) {
    return rand() % max + min;
}

bool jE::randBool(void) {
    return (bool) randInt(0, 1);
}


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


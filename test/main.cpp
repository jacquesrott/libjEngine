#include <stdlib.h>
#include <jEngine/plane.h>


int main(int argc, char *argv[]) {
    jE::Plane p(20, 20, 20);

    printf("Tess : %f", p.matrix[0][0]);

    return 0;
}


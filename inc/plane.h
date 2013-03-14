#ifndef __PLANE__
#define __PLANE__

#include "geometry.h"
#include <glm/glm.hpp>

namespace jE {
    /*
     *  Plane class that generates a tesselated plane
     *
     */
    class Plane {
    private:
        int width;          // plane width
        int height;         // plane height
        int tessaletion;    // plane tesseletion level

        bool up;    // is plane vertical or horizontal ?

        /*
         *  Generates plane's geometry (vertex, index, normals...)
         */
        void getGeom(void);

    public:
        Plane(const int w, const int h, const int t);
        Plane(const int w, const int h, const int t, const bool u);
        ~Plane(void);

        glm::mat4 matrix;   // plane matrix
        Geometry *geom;     // plane geometry object
    };
};


#endif

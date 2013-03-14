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

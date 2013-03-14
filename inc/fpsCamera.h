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

#ifndef __FPSCAMERA__
#define __FPSCAMERA__

#include "camera.h"
#include <glm/glm.hpp>

namespace jE {
    /*
     *  Simple First Person Camera
     */
    class FPSCamera : public Camera {
    private:
        glm::vec3 mvt;  // Combined displacement vector

        double pitch;
        double yaw;
        double roll;

        double mul;     // mouvement speed multiplicator
        double sens;    // mouse sensitivity

    public:
        FPSCamera(void);
        /*
         *  Builds a FPS Camera with defined parameter
         *      p:  Camera position vector
         *      d:  Camera direction vector
         *      m:  Speed multiplicator
         *      s:  Mouse sensitivity
         */
        FPSCamera(glm::vec3 p, glm::vec3 d, double m, double s);
        
        /*
         *  Builds a FPS Camera with defined parameter
         *      p:  Camera position vector
         *      d:  Camera direction vector
         */
        FPSCamera(glm::vec3 p, glm::vec3 d);
        FPSCamera(double m, double s);
        ~FPSCamera(void);

        /*
         * Camera moves perpendiculary to the left
         */
        void strafeLeft(void);

        /*
         *  Camera moves perpendiculary to the right
         */
        void strafeRight(void);

        /*
         * Camera moves forward
         */
        void forward(void);
        /*
         *  Camera moves backward
         */
        void backward(void);

        /*
         *  Camera moves vertically up
         */
        void vertUp(void);
        /* 
         * Camera moves vertically down
         */
        void vertDown(void);

        /*
         *  Mouse motion handler
         *      x: x of the new mouse position (screen relative, better)
         *      y: y of the new mouse position (screen relative, better)
         */
        void motion(double dx, double dy);

        /*
         *  Update the camera matrix
         *      dt: delta time in milliseconds
         */
        void update(const double dt);
    };
};


#endif

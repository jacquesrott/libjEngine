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

#ifndef __CAMERA__
#define __CAMERA__

#include <glm/glm.hpp>


namespace jE {
    /*
     *  Camera class with needed attributes
     */
    class Camera {
    private:
        /*
         *  Refresh the camera matrix
         */
        void refresh(void);

    protected:
        glm::vec3 pos;          // Camera XYZ position
        glm::vec3 direction;    // View direction vector
        glm::vec3 up;           // Camera up vector

    public:
        Camera(void);
        /*
         *  Constructor with position and direction override
         *      p:  User's camera position vector
         *      d:  User's camera direction vector
         */
        Camera(glm::vec3 p, glm::vec3 d);
        ~Camera(void);

        glm::mat4 matrix;       // Camera view matrix

        // Direction vector getter/setter
        void setDirection(glm::vec3 d);
        glm::vec3 getDirection(void) const;

        // Postion vector getter/setter
        void setPos(glm::vec3 p);
        glm::vec3 getPos(void) const;
    };
};


#endif

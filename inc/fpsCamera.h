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

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

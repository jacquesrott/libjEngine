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

#ifndef __RBO__
#define __RBO__

#include "OpenGL/GL.h"

// TODO: Add RBO depth parameter

namespace jE {
    /*
     *  Manages a RBO
     */
    class Renderbuffer {
    private:
        /*
         *  Establish the RBO params
         */
        void establish(void);

    public:
        /*
         *  Initialize a RBO
         *      w: RBO draw width
         *      h: RBO draw height
         */
        Renderbuffer(unsigned int w, unsigned int h);
        ~Renderbuffer(void);

        /*
         *  Binds the RBO
         */
        void bind(void) const;
        /*
         *  Unbinds the RBO
         */
        void unbind(void) const;

        unsigned int width;     // RBO draw width
        unsigned int height;    // RBO draw height

        GLuint id;              // OpenGL RBO id
    };
};


#endif

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

#ifndef __TOOLS__
#define __TOOLS__

#include <string>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>


namespace jE {
    unsigned long getFileLength(std::ifstream& file);

    // TODO: remove this functions...
    void color_RGB_to_glFormat(glm::vec4 * color);
    void color_glFormat_to_RGB(glm::vec4 * color);
};

#endif

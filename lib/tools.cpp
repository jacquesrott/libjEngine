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

#include "tools.h"

#include <string>
#include <iostream>
#include <fstream>
#include <glm/glm.hpp>


unsigned long jE::getFileLength(std::ifstream& file)
{
    if(!file.good()) return 0;
    
    //unsigned long pos=file.tellg();
    file.seekg(0, std::ios::end);
    unsigned long len = file.tellg();
    file.seekg(std::ios::beg);
    
    return len;
}

void jE::color_RGB_to_glFormat(glm::vec4 * color) {
    if(color->r > 1 || color->g > 1 || color->b > 1 || color->a > 1) {
        color->r /= 255.0;
        color->g /= 255.0;
        color->b /= 255.0;
        color->a /= 255.0;
    }
}

void jE::color_glFormat_to_RGB(glm::vec4 * color) {
    if(color->r <= 1 || color->g <= 1 || color->b <= 1 || color->a <= 1) {
        color->r *= 255.0;
        color->g *= 255.0;
        color->b *= 255.0;
        color->a *= 255.0;
    }
}


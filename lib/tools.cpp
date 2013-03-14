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


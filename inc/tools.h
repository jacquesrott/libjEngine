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

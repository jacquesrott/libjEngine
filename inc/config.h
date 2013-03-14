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

#ifndef __CONFIG__
#define __CONFIG__

#include <glm/glm.hpp>
#include <jansson.h>
#include <string>


// Old stuff
// TODO: clean config management

namespace jE {
    typedef struct Config {
        const char   * file;
        json_t       * json;
        json_error_t   error;
        
    } Config;

    // init a Config struct
    Config  Config_init(std::string path);

    // get JSON type
    void    config_get_string(  struct Config *conf, std::string key, std::string *dest);
    void    config_get_int(     struct Config *conf, std::string key, int *dest);
    void    config_get_double(  struct Config *conf, std::string key, double *dest);
    void    config_get_float(   struct Config *conf, std::string key, float *dest);
    void    config_get_color(   struct Config *conf, std::string key, glm::vec4 *dest);
    double  config_get_double_from_array(json_t *value, size_t index);
};

#endif

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

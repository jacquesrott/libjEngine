#include "config.h"
#include <glm/glm.hpp>
#include <jansson.h>
#include "tools.h"
#include <string>


// Old stuff
// TODO: get error function

jE::Config jE::Config_init(std::string path) {
    Config config;
    config.file = path.c_str();
    config.json = json_load_file(config.file, 0, &config.error);
    
    return config;
}

void jE::config_get_string(
        struct jE::Config *conf,
        std::string key,
        std::string *dest
    ) {
    json_t *value;
    value = json_object_get(conf->json, key.c_str());
    
    if(json_is_string(value))
        *dest = (char *) json_string_value(value);
    delete[] value;
}

void jE::config_get_int(struct jE::Config *conf, std::string key, int *dest) {
    json_t *value;
    
    value = json_object_get(conf->json, key.c_str());
    
    if(json_is_integer(value))
        *dest = (int) json_integer_value(value);
    delete[] value;
}

void jE::config_get_double(
        struct jE::Config *conf,
        std::string key,
        double *dest
    ) {
    json_t *value;
    
    value = json_object_get(conf->json, key.c_str());
    
    if(json_is_real(value))
        *dest = (double) json_real_value(value);
    delete[] value;
}

void jE::config_get_float(
        struct jE::Config *conf,
        std::string key,
        float *dest
    ) {
    json_t *value;
    
    value = json_object_get(conf->json, key.c_str());
    
    if(json_is_real(value))
        *dest = (float) json_real_value(value);
    delete[] value;
}

void jE::config_get_color(
        struct jE::Config *conf,
        std::string key,
        glm::vec4 *dest
    ) {
    json_t *value;
    
    value = json_object_get(conf->json, key.c_str());
    
    if(json_is_array(value) &&
       (json_array_size(value) == 4 || json_array_size(value) == 3 )) {
        glm::vec4 color;
        color.r = config_get_double_from_array(value, 0);
        color.g = config_get_double_from_array(value, 1);
        color.b = config_get_double_from_array(value, 2);
        
        if(json_array_size(value) == 4)
            color.a = config_get_double_from_array(value, 3);
        else
            color.a = 1.0;
        
        color_RGB_to_glFormat(&color);
        *dest = color;
    } else {
        printf("[WARNING] : not well formated color, initialized to white.\n");
        *dest = glm::vec4(1.0, 1.0, 1.0, 1.0);
    }
    delete[] value;
}

double jE::config_get_double_from_array(json_t *array, size_t index) {
    json_t *value = json_array_get(array, index);
    double value_d;
    if(json_is_real(value)) {
        value_d = (double) json_real_value(value);
    } else {
        value_d = 0;
    }
    delete[] value;
    return value_d;
}

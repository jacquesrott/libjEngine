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

#include "base.h"

#include <string>

#include "OpenGL/GL.h"
#include "OpenGL/glext.h"
#include "SDL/SDL.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "config.h"
#include "tools.h"

jE::Base::Base(std::string config) {
    this->play = true;
    
    this->loadDefaultConf();
    this->loadUserConf(config);
    
    this->initSDL();
    this->initOpenGL();
    this->initView();

    this->printInfos();
}

jE::Base::~Base() {
    SDL_Quit();
}

int jE::Base::loop() {
    
    this->reshape(this->width, this->height);
    this->delay = 1000.0 / this->framerate;
    
    SDL_Event event;
    double mouse_x, mouse_y;
    
    while(this->play) {
        int mouse_x_rel = 0;
        int mouse_y_rel = 0;
        char mouse_buttons[6];
        
        while(SDL_PollEvent(&event))
        {
            switch(event.type) {
                case SDL_QUIT:
                    this->quitEvent();
                    break;
                case SDL_VIDEORESIZE:
                    this->resizeSDL(event.resize.w, event.resize.h);
                    this->reshape(event.resize.w, event.resize.h);
                    this->width  = event.resize.w;
                    this->height = event.resize.h;
                    this->initView();
                    break;
                case SDL_MOUSEMOTION:
                    mouse_x     = event.motion.x;
                    mouse_y     = event.motion.y;
                    mouse_x_rel = event.motion.xrel;
                    mouse_y_rel = event.motion.yrel;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse_buttons[event.button.button-1]=1;
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouse_buttons[event.button.button-1]=0;
                    break;
                default:
                    break;
            }
        }

        Uint8 *keystate = SDL_GetKeyState(NULL);
        this->keyEvent(keystate);
        this->mouseEvent(
            mouse_x, mouse_y,
            mouse_x_rel, mouse_y_rel,
            mouse_buttons
        );
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        this->display();
        
        SDL_GL_SwapBuffers();
        SDL_Delay(this->delay);
    }
    
    return 0;
}

void jE::Base::initSDL() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    SDL_SetVideoMode(this->width, this->height, 0, SDL_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    //SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    //SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    SDL_WM_SetCaption(this->name.c_str(), 0);
}

void jE::Base::initOpenGL() {
    glClearDepth(1.0);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    glViewport( 0, 0, this->width, this->height);
    glClearColor(
        this->colorClear.r,
        this->colorClear.g,
        this->colorClear.b,
        this->colorClear.a
    );
}

void jE::Base::initView() {
    float aspect = ((float) this->width) / ((float) this->height);
    this->projection = glm::perspective(
        this->fov,
        aspect,
        this->near, this->far
    );
    this->view = glm::mat4(1.0);
}

void jE::Base::resizeSDL(int w, int h) {
    SDL_SetVideoMode(w, h, 0, SDL_OPENGL|SDL_VIDEORESIZE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void jE::Base::reshape(int w, int h) {}
void jE::Base::display() {}
void jE::Base::keyEvent(Uint8 *keystate) {}
void jE::Base::mouseEvent(
    double x, double y,
    double x_rel, double y_rel, 
    char buttons[6]
) {}
void jE::Base::quitEvent() {}

void jE::Base::printInfos() {
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL Version : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Renderer : " << glGetString(GL_RENDERER) << std::endl;
}

void jE::Base::loadDefaultConf() {
    Config conf = Config_init(DEFAULT_CONF_FILE);
    this->getConfAttributes(&conf);
    delete conf.json;
}

void jE::Base::loadUserConf(std::string config) {
    Config conf = Config_init(config);
    if(conf.json != NULL) {
        this->getConfAttributes(&conf);
        delete conf.json;
    } else {
        printf("********\nUser Config file error.\n");
        printf("Line %i col %i\n", conf.error.line, conf.error.column);
        printf("%s\n", conf.error.text);
    }
}

void jE::Base::getConfAttributes(jE::Config * conf) {
    config_get_string(conf, "name",      &this->name);
    config_get_int(   conf, "width",     &this->width);
    config_get_int(   conf, "height",    &this->height);
    config_get_float( conf, "fov",       &this->fov);
    config_get_float( conf, "near",      &this->near);
    config_get_float( conf, "far",       &this->far);
    config_get_float( conf, "framerate", &this->framerate);
    config_get_color( conf, "clear",     &this->colorClear);
}

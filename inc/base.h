#ifndef __BASE__
#define __BASE__

#include <string>
#include <SDL/SDL.h>

#include "config.h"
#include "shader.h"

#include "glm/glm.hpp"

using namespace std;
// TODO: move default config path elsewhere.....................
#define DEFAULT_CONF_FILE (const string) "data/default/conf.json"


namespace jE {
    /*
     *  Base class
     *  
     *  Main application must be child of Base class
     *
     */
    class Base 
    {
        /*
         *  Initialize a SDL context with a OpenGL Context
         */
        void initSDL(void);

        /*
         *  Define OpenGL paramter (Back Culling, Depth...)
         */
        void initOpenGL(void);
        /*
         *  Instanciate the View Projection Matrix
         */
        void initView(void);
        
        /*
         *  Load Default config file
         */
        void loadDefaultConf();

        /*
         *  Load user config file and override Default config
         *      config: path to the config file
         */
        void loadUserConf(string config);
        
        /*
         *  Resize Event
         *      w: new screen width
         *      h: new screen height
         */
        void resizeSDL(int w, int h);

        /*
         *  Quering the config attribute list
         *      config: Config file object
         */
        void getConfAttributes(Config * conf);
        
        // TODO: move to Camera
        float fov;      // default fov
        float near;     // near depth
        float far;      // far depth
        
        float framerate;    // fixed framerate
        float delay;        // Delay between buffer swap
        
        string name;        // Application name / windows name
        
        glm::vec4 colorClear;   // RGBA clear Color
        
    public:
        /*
         *  Builds a base application with user's config file
         *      config: path to user's config file
         */
        Base(string config);
        ~Base(void);
        
        int width;      // screen width
        int height;     // screen height
        
        bool play;      // if true, loop turns, else base quits

        void printInfos(void);  // print server infos (OGL version, Shader...)
        
        glm::mat4 projection;   // projection matrix
        // TODO: use only Camera view
        glm::mat4 view;         // view matrix
        
        /*
         *  Application resize Event, to override
         *      w:  new screen width
         *      h:  new screen height
         */
        virtual void reshape(int w, int h);
        
        /*
         *  Application draw function, to override
         */
        virtual void display(void);
        
        /*
         *  Application event key handling
         *      keystate:   Keypressed list
         */
        virtual void keyEvent(Uint8 *keystate);

        /*
         *  Application mouse event handling
         *      x:       absolute x pos
         *      y:       absolute y pos
         *      x_rel:   screen relative x pos
         *      y_rel:   screen relative y pos
         *      buttons: mouse buttons pressed
         */
        virtual void mouseEvent(
            double x, double y,
            double x_rel, double y_rel,
            char buttons[6]
        );
        
        /*
         *  Application quit event
         */
        virtual void quitEvent(void);
        
        /*
         *  Realtime draw loop
         *  everythings happens here...
         */
        int loop(void);
    };
};


#endif

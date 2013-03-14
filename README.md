libjEngine
==========

libjEngine is a light C++ engine with usefull tools for OpenGL Context
rendering.

__NOTA__ : Only avaible for OS X (yet)

It comes with :

 - Base context
 - Basic user events handling
 - Program/Shader management
 - Framebuffer objects management
 - Geometry initialization and drawing
 - Texture management
 - Camera class
 - First Person Camera class
 - Tesselated plane generator


REQUIREMENTS
------------

Only tested on OS X 10.7+ (for the moment), should work on 10.5+

 * *OpenGL*      : Version 2.0+
 * *GLSL*        : Version 1.2+
 * *SDL*         : Version 1.2.\*
  more infos [here](http://www.libsdl.org/)
 * *SDL_image*   : Version 1.2.\*
  more infos [here](http://www.libsdl.org/projects/SDL_image/)
 * *jansson*     : Version 2.3.\*
  more infos [here](http://www.digip.org/jansson/)


INSTALL
-------

Build and install into ‘/usr/local/lib‘ :

	make && sudo make install


UNINSTALL
---------

Type :

	make uninstall

TODO
----

See [TODO](https://github.com/jacquesrott/libjEngine/blob/master/TODO)

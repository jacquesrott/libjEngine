#ifndef __ATTR__
#define __ATTR__

#include <string>

namespace jE {
    // TODO: complete type list if needed
    
    // Attribute type, used when initializing the VBO
    enum AttrType {
        ATTYPE_VERTEX,
        ATTYPE_NORMAL,
        ATTYPE_COLOR,
        ATTYPE_TEXCOORD,
        ATTYPE_OTHER    // OpenGL 3.* user defined attributes
    };


    typedef struct Attr {
        unsigned int size;
        unsigned int number;
        AttrType type;
        std::string name;
    } Attr;

    // Generating handy default attribute
    void setAttrVertex2(Attr *a, const unsigned int nb);    // 2D vertex
    void setAttrVertex3(Attr *a, const unsigned int nb);    // 3D vertex
    void setAttrNormal(Attr *a, const unsigned int nb);     // Normal
    void setAttrColor3(Attr *a, const unsigned int nb);     // RGB Color
    void setAttrColor4(Attr *a, const unsigned int nb);     // RGBA Color
    void setAttrTexCoord2(Attr *a, const unsigned int nb);  // UV coord
};

#endif

#include "attribute.h"

void jE::setAttrVertex2(jE::Attr *a, const unsigned int nb) {
    a->size = 2;
    a->number = nb;
    a->type =  ATTYPE_VERTEX;
}

void jE::setAttrVertex3(jE::Attr *a, const unsigned int nb) {
    a->size = 3;
    a->number = nb;
    a->type =  ATTYPE_VERTEX;
}

void jE::setAttrNormal(jE::Attr *a, const unsigned int nb) {
    a->size = 3;
    a->number = nb;
    a->type =  ATTYPE_NORMAL;
}

void jE::setAttrColor3(jE::Attr *a, const unsigned int nb) {
    a->size = 3;
    a->number = nb;
    a->type =  ATTYPE_COLOR;
}

void jE::setAttrColor4(jE::Attr *a, const unsigned int nb) {
    a->size = 4;
    a->number = nb;
    a->type =  ATTYPE_COLOR;
}

void jE::setAttrTexCoord2(jE::Attr *a, const unsigned int nb) {
    a->size = 2;
    a->number = nb;
    a->type =  ATTYPE_TEXCOORD;
}


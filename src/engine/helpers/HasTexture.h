#ifndef __HAS_TEXTURE_H__
#define __HAS_TEXTURE_H__

#include "ofMain.h"

class HasTexture {
    public:
        virtual ofTexture & getTexture() = 0;
};

#endif
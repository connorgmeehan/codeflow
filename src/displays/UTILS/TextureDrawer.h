#ifndef __TextureDrawer_H__
#define __TextureDrawer_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"
#include "HasTexture.h"

class TextureDrawer : public Channel {
    public:
        TextureDrawer(HasTexture * pHasTexture) {
            mpHasTexture = pHasTexture;
        }
        std::string getName(){ return std::string("TextureDrawerChannel"); }
        void setup() { }
        void update(DrawModel & model, StateModel & state) { 

        }
        void draw(DrawModel & model, StateModel & state) { 
            // auto temp = mpHasTexture->getTexture();
            mpHasTexture->getTexture().draw(0,0);
        }

        void onKick(float amp, float vel) { }
        void onSnare(float amp, float vel) { }
        void onHat(float amp, float vel) { }
    private:
        HasTexture * mpHasTexture;
};

#endif
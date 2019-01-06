#ifndef __FboContext_H__
#define __FboContext_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"
#include "HasTexture.h"

class FboContext : public Context, public HasTexture {
    public:
        std::string getName(){ return std::string("FboContextChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void begin(DrawModel & model, StateModel & state);
        void end(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);

        ofTexture & getTexture();
    private:
        ofFboSettings mSettings;
        ofFbo mFbo;
};

#endif
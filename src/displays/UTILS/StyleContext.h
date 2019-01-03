#ifndef __StyleContext_H__
#define __StyleContext_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"

class StyleContext : public Context {
    public:
        StyleContext(ofColor color);
        std::string getName(){ return std::string("StyleContextChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void begin(DrawModel & model, StateModel & state);
        void end(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        ofColor mColor;
};

#endif
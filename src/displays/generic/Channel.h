#ifndef __CHANNEL_H__
#define __CHANNEL_H__

#include "ofMain.h"
#include "DrawModel.h"

class Channel {
    public:
        virtual void setup() = 0;
        virtual void update(DrawModel & model, StateModel & state) = 0;
        virtual void draw(DrawModel & model, StateModel & state) = 0;

        virtual void onKick(float amp, float vel) = 0;
        virtual void onSnare(float amp, float vel) = 0;
        virtual void onHat(float amp, float vel) = 0;
};

#endif
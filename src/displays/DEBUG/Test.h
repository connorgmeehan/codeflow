#ifndef __Test_H__
#define __Test_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class Test : public Channel {
    public:
           std::string getName(){ return std::string("TestChannel"); }
        void setup();
        void update(DrawModel & model);
        void draw(DrawModel & model);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
};

#endif
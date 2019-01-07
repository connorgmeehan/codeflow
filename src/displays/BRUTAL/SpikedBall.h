#ifndef __SpikedBall_H__
#define __SpikedBall_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class SpikedBall : public Channel {
    public:
        SpikedBall(float radius, int segments);
        std::string getName(){ return std::string("SpikedBallChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void draw(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        int mSegments;
        float mRadius;
        ofMesh mMesh;
};

#endif
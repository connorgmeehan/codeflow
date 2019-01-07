#ifndef __SpikedBall_H__
#define __SpikedBall_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"
#include "ModeManager.h"

enum SpikedModes {
    TRIG_1,
    TRIG_2,
    TRIG_3,
    TRIG_4,
    TRIG_5,
    TRIG_6,
};

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
        ModeManager<SpikedModes> mModeManager;
        int mSegments;
        float mRadius;
        ofMesh mMesh;
};

#endif
#ifndef __PerlinOctopus_H__
#define __PerlinOctopus_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"
#include "ModeManager.h"

enum PerlinOctopusModes {
    PERLIN_1,
    PERLIN_2
};

class PerlinOctopus : public Channel {
    public:
        PerlinOctopus(float reactivity, float segmentStep, float perlinScale, float radius, int armNumber);
        std::string getName(){ return std::string("PerlinOctopusChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void draw(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        // ofMesh mArmMesh;
        of3dPrimitive mArm;

        int mArmNumber;
        float mReactivity, mSegmentStep, mPerlinScale, mRadius;

        std::vector<of3dPrimitive> mArms;

        ModeManager<PerlinOctopusModes> mModeManager;
};

#endif
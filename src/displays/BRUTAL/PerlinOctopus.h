#ifndef __PerlinOctopus_H__
#define __PerlinOctopus_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class PerlinOctopus : public Channel {
    public:
        PerlinOctopus(int segmentNumber, float segmentStep, float perlinScale, float radius, int armNumber);
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

        int mSegmentNumber, mArmNumber;
        float mSegmentStep, mPerlinScale, mRadius;

        std::vector<of3dPrimitive> mArms;

};

#endif
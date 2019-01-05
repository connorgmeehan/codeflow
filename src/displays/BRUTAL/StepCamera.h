#ifndef __StepCamera_H__
#define __StepCamera_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"

class StepCamera : public Context {
    public:
        StepCamera(float speed, float stepDistance, float minDistance, float maxDistance);
        std::string getName(){ return std::string("StepCameraChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void begin(DrawModel & model, StateModel & state);
        void end(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        ofEasyCam mCam;
        float mOffset;
        float mSpeed, mStepDistance;
        float mDistance, mMinDistance, mMaxDistance;
        glm::vec2 mOrbit;
};

#endif
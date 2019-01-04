#ifndef __VibratingContext_H__
#define __VibratingContext_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"

class VibratingContext : public Context {
    public:
        VibratingContext() {}
        VibratingContext(float maxDistance, float power, float interval);
        std::string getName(){ return std::string("VibratingContext"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void begin(DrawModel & model, StateModel & state);
        void end(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        float mMaxDistance, mPowerMultiplier, mCurrentDirection;
        float mSigConstant;
        float mSmoothedAmp;
};

#endif
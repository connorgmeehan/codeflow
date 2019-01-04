#ifndef __BEAT_MODEL_H__
#define __BEAT_MODEL_H__

#include "ofMain.h"

struct BeatModel {
    bool mActive;
    float mAmp, mVel;

    BeatModel(bool active, float amp, float vel);
};

enum BeatState {
    BEAT_OFF,
    BEAT_ON,
    BEAT_COOLDOWN
};

class ProcessBeatModel {
    private:
        static float mTriggerGradient;
        static float mGradientScale;
        static int mTickCount;
        static int mTickDelay;

        BeatState mState;
        int mLastTick;
        int mLocation;
        int mRadius;
        std::vector<float> mHistory;
    public: 
        ProcessBeatModel(int location, int radius, int historySize);
        static void setTriggerGradient(float triggerGradient);
        static void setGradientScale(float gradientScale);
        static void incrementTickCount();
        BeatModel audioIn(const std::vector<float> & fft);

        float getTriggerGradient() { return mTriggerGradient; }
        int getLocation() { return mLocation; }
        int getRadius() { return mRadius; }
        std::vector<float> & getHistory() { return mHistory; }
        void setBeatState(BeatState state){ mState = state; }
};

#endif
#ifndef __BEAT_MODEL_H__
#define __BEAT_MODEL_H__

#include "ofMain.h"

struct BeatModel {
    bool mActive;
    float mAmp, mVel;

    BeatModel(bool active, float amp, float vel);
};

class ProcessBeatModel {
    private:
        static float mTriggerGradient;
        static float mGradientScale;
        static int mTickCount;
        static int mTickDelay;

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
};

#endif
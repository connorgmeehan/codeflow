#include "BeatModel.h"

BeatModel::BeatModel(bool active, float amp, float vel) :
    mActive(active),
    mAmp(amp),
    mVel(vel) {
}

float ProcessBeatModel::mTriggerGradient;
float ProcessBeatModel::mGradientScale;
int ProcessBeatModel::mTickCount = 0;
int ProcessBeatModel::mTickDelay = 20;

ProcessBeatModel::ProcessBeatModel(int location, int radius, int historySize) :
    mLocation(location),
    mRadius(radius) {
    mHistory.resize(historySize, 0.0f);
    mLastTick = 0;
}

void ProcessBeatModel::setTriggerGradient(float triggerGradient) {
    mTriggerGradient = triggerGradient;
}

void ProcessBeatModel::setGradientScale(float gradientScale) {
    mGradientScale = gradientScale;
}

void ProcessBeatModel::incrementTickCount() {
    mTickCount++;
}

void ProcessBeatModel::setBeatState(BeatState state) {
    mState = state;
    mLastTick = mTickCount;
}

BeatState ProcessBeatModel::getBeatState() {
    return mState;
}

BeatModel ProcessBeatModel::audioIn(const std::vector<float> & fft) {
    // update history
    int lowerBounds = ofClamp(mLocation - mRadius, 0, fft.size());
    int upperBounds = ofClamp(mLocation + mRadius, 0, fft.size());
    float avg = std::accumulate(fft.begin() + lowerBounds,fft.begin() + upperBounds, 0.0f) / (upperBounds - lowerBounds);
    mHistory.insert(mHistory.begin(), avg);
    mHistory.pop_back();

    // find gradient
    float gradient = 0.0f;
    for(int i = 0; i < mHistory.size()-1; i++) {
        gradient += mHistory[i+1] - mHistory[i];
    }
    gradient = (gradient*mGradientScale) / mHistory.size();
    
    mTriggerGradient = glm::max(mTriggerGradient, gradient);
    mTriggerGradient -= 0.01f;

    // Calculate state

    bool active = false;

    if(mState == BEAT_OFF) {
        if(gradient >= mTriggerGradient) {
            mState = BEAT_ON;
            active = true;
        }
    } else if(mState == BEAT_ON) {
        active = true;
        // AudioAnalyser will switch this to BEAT_COOLDOWN when it's read
    } else {
        if(mLastTick + mTickDelay < mTickCount) {
            mState = BEAT_OFF;
        }
    }

    // generate BeatModel for returning
    return BeatModel(active , avg, gradient);
}
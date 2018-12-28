#include "BeatModel.h"

BeatModel::BeatModel(bool active, float amp, float vel) :
    mActive(active),
    mAmp(amp),
    mVel(vel) {
}

float ProcessBeatModel::mTriggerGradient;
float ProcessBeatModel::mGradientScale;

ProcessBeatModel::ProcessBeatModel(int location, int radius, int historySize) :
    mLocation(location),
    mRadius(radius) {
    mHistory.resize(historySize, 0.0f);
}

void ProcessBeatModel::setTriggerGradient(float triggerGradient) {
    mTriggerGradient = triggerGradient;
}

void ProcessBeatModel::setGradientScale(float gradientScale) {
    mGradientScale = gradientScale;
}

BeatModel ProcessBeatModel::audioIn(std::vector<float> & fft) {
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

    // generate BeatModel for returning
    return BeatModel(gradient >= mTriggerGradient, avg, gradient);
}
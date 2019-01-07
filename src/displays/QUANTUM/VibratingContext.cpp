#include "VibratingContext.h"

VibratingContext::VibratingContext(float maxDistance, float power) :
    mMaxDistance(maxDistance),
    mPowerMultiplier(power),
    mCurrentDirection(1.0f),
    mSmoothedAmp(0.0f) {
        mSigConstant = std::exp(-1);
}

void VibratingContext::setup(){
}

void VibratingContext::update(DrawModel & model, StateModel & state){
    mSmoothedAmp = glm::max( glm::mix(model.beats[0].mAmp, mSmoothedAmp, 0.5f), mSmoothedAmp) * 0.7;
}

void VibratingContext::begin(DrawModel & model, StateModel & state){
    ofPushMatrix();
        float dist = (1.0 / (1.0 + std::exp(-10 * mSmoothedAmp))) - 0.5;
        mCurrentDirection *= -1.0f;
        ofLog() << "VibratingCotnext::begin() mCurrentDirection ->" << mCurrentDirection * dist * mMaxDistance;

        ofTranslate(
            0,
            0,
            mCurrentDirection * dist * mMaxDistance
        );
        ofScale(1, 1, mCurrentDirection);
}

void VibratingContext::end(DrawModel & model, StateModel & state){
    ofPopMatrix();
}

void VibratingContext::onKick(float amp, float vel){

}

void VibratingContext::onSnare(float amp, float vel){

}

void VibratingContext::onHat(float amp, float vel){

}

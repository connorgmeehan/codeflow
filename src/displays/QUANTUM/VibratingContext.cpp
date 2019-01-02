#include "VibratingContext.h"

Vibrating::Vibrating(float maxDistance, float power, float interval) :
    mMaxDistance(maxDistance),
    mPowerMultiplier(power),
    mInterval(interval),
    mCurrentDirection(1.0f),
    mSmoothedAmp(0.0f) {
        mSigConstant = std::exp(-1);
}

void Vibrating::setup(){
    mLastChange = ofGetElapsedTimef();
}

void Vibrating::update(DrawModel & model, StateModel & state){
    if(mLastChange + mInterval < state.mTime) {
        mLastChange = state.mTime;
        mCurrentDirection *= -1.0f;
    }
    model.beats[0].mAmp = glm::max( glm::mix(model.beats[0].mAmp, mSmoothedAmp, 0.5f), mSmoothedAmp) * 0.95;
}

void Vibrating::begin(DrawModel & model, StateModel & state){
    ofPushMatrix();
        float dist = 1.0f / ( 1.0f + (20.0f*(pow(mSigConstant, mSmoothedAmp) ) ) );
        mInterval = (0.1f - dist*0.2f);

        ofTranslate(
            0,
            0,
            mCurrentDirection * dist * mMaxDistance
        );
        ofScale(1, 1, mCurrentDirection);
}

void Vibrating::end(DrawModel & model, StateModel & state){
    ofPopMatrix();
}

void Vibrating::onKick(float amp, float vel){

}

void Vibrating::onSnare(float amp, float vel){

}

void Vibrating::onHat(float amp, float vel){

}

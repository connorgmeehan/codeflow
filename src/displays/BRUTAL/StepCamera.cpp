#include "StepCamera.h"

StepCamera::StepCamera(float speed, float stepDistance, float minDistance, float maxDistance) :
    mSpeed(speed),
    mStepDistance(stepDistance),
    mMinDistance(minDistance),
    mMaxDistance(maxDistance) {
    mOrbit = glm::vec2(0,0);
    mCam.setFov(120);
}

void StepCamera::setup(){

}

void StepCamera::update(DrawModel & model, StateModel & state){
    float noisePos = state.mTime * mSpeed;
    mDistance = mMinDistance + ofNoise(noisePos) * (float) (mMaxDistance - mMinDistance);

    mOrbit = glm::vec2(
        ofSignedNoise(noisePos + mOffset)*(float)360,
        ofSignedNoise(noisePos + mOffset)*(float)360
    );

    mCam.orbit(mOrbit.x, mOrbit.y, mDistance, glm::vec3(0,0,0));
}

void StepCamera::begin(DrawModel & model, StateModel & state){
    mCam.begin();
}

void StepCamera::end(DrawModel & model, StateModel & state){
    mCam.end();
}

void StepCamera::onKick(float amp, float vel){
    mOffset += mStepDistance;
}

void StepCamera::onSnare(float amp, float vel){

}

void StepCamera::onHat(float amp, float vel){

}
#include "PerlinOctopus.h"
PerlinOctopus::PerlinOctopus(int segmentNumber, float segmentStep, float perlinScale, float radius, int armNumber) {
    mSegmentNumber = segmentNumber;
    mSegmentStep = segmentStep;
    mPerlinScale = perlinScale;
    mRadius = radius;
    mArmNumber = armNumber;

    for(int i = 0; i < mSegmentNumber; i++) {
        mArm.getMesh().addVertex(glm::vec3(0,0,0));
    }

    mModeManager = ModeManager<PerlinOctopusModes>(2, MODE_SHUFFLE, 16);
}

void PerlinOctopus::setup(){

}

void PerlinOctopus::update(DrawModel & model, StateModel & state){
    switch(mModeManager.getMode()) {
        case PERLIN_1:
            for( int i = 0; i < mSegmentNumber; i++ ) {
                float perlinValue = (float) i * mPerlinScale;
                float dist = (float)i/(float)mSegmentNumber * mRadius;
                
                mArm.getMesh().setVertex(i, glm::vec3(
                    ofNoise(perlinValue) * dist,
                    ofNoise(perlinValue + state.mTime) * dist,
                    ofSignedNoise(100.0f + perlinValue + state.mTime) * dist
                ));
            }
        break;
        case PERLIN_2:
            for( int i = 0; i < mSegmentNumber; i++ ) {
                float perlinValue = (float) i * mPerlinScale;
                float dist = (float)i/(float)mSegmentNumber * mRadius;
                
                mArm.getMesh().setVertex(i, glm::vec3(
                    ofNoise(perlinValue - state.mTime) * dist,
                    ofNoise(perlinValue + state.mTime) * dist,
                    ofSignedNoise(100.0f + perlinValue + state.mTime) * dist
                ));
            }
        break;
    }
}

void PerlinOctopus::draw(DrawModel & model, StateModel & state){

    ofFill();

    for(int i = 0; i < mArmNumber; i++) {
        float theta = ((float) i / (float) mArmNumber) * TWO_PI;
        mArm.rollRad(theta);
        mArm.draw();
    }
}

void PerlinOctopus::onKick(float amp, float vel){
    mModeManager.updateMode();
}

void PerlinOctopus::onSnare(float amp, float vel){

}

void PerlinOctopus::onHat(float amp, float vel){

}
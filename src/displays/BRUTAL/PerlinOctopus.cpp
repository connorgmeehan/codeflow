#include "PerlinOctopus.h"
PerlinOctopus::PerlinOctopus(float reactivity, float segmentStep, float perlinScale, float radius, int armNumber) {
    mReactivity = reactivity;
    mSegmentStep = segmentStep;
    mPerlinScale = perlinScale;
    mRadius = radius;
    mArmNumber = armNumber;

    for(int i = 0; i < BUFFER_SIZE; i++) {
        mArm.getMesh().addVertex(glm::vec3(0,0,0));
    }

    mModeManager = ModeManager<PerlinOctopusModes>(2, MODE_SHUFFLE, 16);
}

void PerlinOctopus::setup(){

}

void PerlinOctopus::update(DrawModel & model, StateModel & state){
    auto & fft = model.audio.mFft;

    switch(mModeManager.getMode()) {
        case PERLIN_1: {
            float perlinOffset = state.mTime*mPerlinScale;
            for( int i = 0; i < BUFFER_SIZE; i++ ) {
                float perlinValue = (float) i * mPerlinScale;
                float dist = (float)i/(float)BUFFER_SIZE * mRadius;
              
                mArm.getMesh().setVertex(i, glm::vec3(
                    ofSignedNoise(perlinValue + perlinOffset + fft[i]*mReactivity) * dist,
                    ofSignedNoise(perlinValue - perlinOffset + fft[i]*mReactivity) * dist,
                    ofSignedNoise(perlinValue + perlinOffset + fft[i]*mReactivity + 100.0f) * dist
                ) );
            }
        } break;

        case PERLIN_2: {
            float perlinOffset = state.mTime*mPerlinScale;
            for( int i = 0; i < BUFFER_SIZE; i++ ) {
                float perlinValue = (float) i * mPerlinScale;
                float dist = ofSignedNoise(perlinValue + perlinOffset) * (float) i / (float) BUFFER_SIZE * mRadius;
                
                mArm.getMesh().setVertex(i, glm::vec3(
                    ofSignedNoise(perlinValue - perlinOffset + fft[i]*mReactivity) * dist,
                    ofSignedNoise(perlinValue + perlinOffset + fft[i]*mReactivity) * dist,
                    ofSignedNoise(100.0f + perlinValue + perlinOffset + fft[i]*mReactivity) * dist
                ));
            }
        } break;
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
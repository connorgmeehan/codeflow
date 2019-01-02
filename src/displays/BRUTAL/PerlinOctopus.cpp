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
}

void PerlinOctopus::setup(){

}

void PerlinOctopus::update(DrawModel & model, StateModel & state){
    for( int i = 0; i < mSegmentNumber; i++ ) {
        float perlinValue = (float) i * mPerlinScale;
        
        mArm.getMesh().setVertex(i, glm::vec3(
            ofNoise(perlinValue) * i/mSegmentNumber * mRadius,
            ofNoise(perlinValue + state.mTime) * i/mSegmentNumber * mRadius,
            ofSignedNoise(100.0f + perlinValue + state.mTime) * i/mSegmentNumber * mRadius
        ));
    }
}

void PerlinOctopus::draw(DrawModel & model, StateModel & state){

    ofSetColor(ofColor::white);
    ofFill();

    for(int i = 0; i < mArmNumber; i++) {
        float theta = ((float) i / (float) mArmNumber) * TWO_PI;
        mArm.rollRad(theta);
        mArm.draw();
    }
}

void PerlinOctopus::onKick(float amp, float vel){

}

void PerlinOctopus::onSnare(float amp, float vel){

}

void PerlinOctopus::onHat(float amp, float vel){

}
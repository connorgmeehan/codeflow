#include "SpikedBall.h"

SpikedBall::SpikedBall(float radius, int segments) : mRadius(radius), mSegments(segments) {
    
}

void SpikedBall::setup(){
    for(int segment = 0; segment < mSegments; segment++ ){
        for(int i = 0; i < BUFFER_SIZE; i++) {
            mMesh.addVertex(glm::vec3(0,0,0));
            mMesh.addVertex(glm::vec3(0,0,0));
        }
    }
}

void SpikedBall::update(DrawModel & model, StateModel & state){
    auto & fft = model.audio.mFft;
    
    for(int segment = 0; segment < mSegments; segment++) {

        float segmentValue = ((float) segment / (float) mSegments)*TWO_PI;

        for(int i = 0; i < BUFFER_SIZE; i++) {
            float lineValue = ((float) i / (float) BUFFER_SIZE)*TWO_PI;

            glm::vec3 direction = glm::vec3(
                cos(segmentValue) * cos(lineValue),
                cos(segmentValue) * sin(lineValue),
                sin(segmentValue)
            );
            mMesh.setVertex(segment*mSegments + i*2, direction*mRadius);
            mMesh.setVertex(segment*mSegments + i*2+1, direction*mRadius + direction*fft[i]*50);
        }
    }
}

void SpikedBall::draw(DrawModel & model, StateModel & state){
    mMesh.draw();
}

void SpikedBall::onKick(float amp, float vel){

}

void SpikedBall::onSnare(float amp, float vel){

}

void SpikedBall::onHat(float amp, float vel){

}

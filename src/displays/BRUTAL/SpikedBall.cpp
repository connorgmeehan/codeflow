#include "SpikedBall.h"

SpikedBall::SpikedBall(float radius, int segments) : mRadius(radius), mSegments(segments) {
    mModeManager = ModeManager<SpikedModes>(6, MODE_CYCLE, 16);
    mMesh.setMode(OF_PRIMITIVE_POINTS);

    for(int segment = 0; segment < mSegments; segment++ ){
        for(int i = 0; i < BUFFER_SIZE; i++) {
            mMesh.addVertex(glm::vec3(0,0,0));
        }
    }
}

void SpikedBall::setup(){
    
}

void SpikedBall::update(DrawModel & model, StateModel & state){
    auto & fft = model.audio.mFft;

    float timeVal = state.mTime * 0.25f;

    switch(mModeManager.getMode()) {
        case TRIG_1:
            for(int i = 0; i < BUFFER_SIZE; i++) {
                float phi = ofMap(i, 0, BUFFER_SIZE, 0, TWO_PI);
                for(int segment = 0; segment < mSegments; segment++) {

                    float theta = ((float) segment / (float) mSegments)*TWO_PI;

                    glm::vec3 direction = glm::vec3(
                        sinf(theta- timeVal) * sinf(phi) * tanf(theta),
                        cosf(phi) * cosf(phi) ,
                        cosf(theta) * sinf(phi + timeVal)
                    );
                    mMesh.setVertex(segment*mSegments + i, direction*mRadius + direction*fft[i]*50);
                }
            }
        break;
        case TRIG_2:
            for(int segment = 0; segment < mSegments; segment++) {
                float theta = ((float) segment / (float) mSegments)*TWO_PI;
                for(int i = 0; i < BUFFER_SIZE; i++) {

                    float phi = ofMap(i, 0, BUFFER_SIZE, 0, TWO_PI);

                    glm::vec3 direction = glm::vec3(
                        sinf(theta) * sinf(phi - timeVal),
                        cosf(theta) * atanf(phi),
                        cosf(theta) * sinf(phi+timeVal)
                    );
                    mMesh.setVertex(segment*mSegments + i, direction*mRadius + direction*fft[i]*50);
                }
            }
        break;
        case TRIG_3:
            for(int segment = 0; segment < mSegments; segment++) {
                float theta = ((float) segment / (float) mSegments)*TWO_PI;
                for(int i = 0; i < BUFFER_SIZE; i++) {

                    float phi = ofMap(i, 0, BUFFER_SIZE, 0, TWO_PI);

                    glm::vec3 direction = glm::vec3(
                        cosf(theta + timeVal) * asinf(phi),
                        sinf(theta) * acosf(phi),
                        sinf(theta) * sinf(phi - timeVal)
                    );
                    mMesh.setVertex(segment*mSegments + i, direction*mRadius + direction*fft[i]*50);
                }
            }
        break;
        case TRIG_4:
            for(int i = 0; i < BUFFER_SIZE; i++) {
                float phi = ofMap(i, 0, BUFFER_SIZE, 0, TWO_PI);
                for(int segment = 0; segment < mSegments; segment++) {

                    float theta = ((float) segment / (float) mSegments)*TWO_PI;

                    glm::vec3 direction = glm::vec3(
                        sin(theta) * sin(phi - timeVal),
                        cos(phi) * sin(phi) * tan(theta + timeVal),
                        cos(theta) 
                    );
                    mMesh.setVertex(segment*mSegments + i, direction*mRadius + direction*fft[i]*50);
                }
            }
        break;
        case TRIG_5:
            for(int i = 0; i < BUFFER_SIZE; i++) {
                float phi = ofMap(i, 0, BUFFER_SIZE, 0, TWO_PI);
                for(int segment = 0; segment < mSegments; segment++) {

                    float theta = ((float) segment / (float) mSegments)*TWO_PI;

                    glm::vec3 direction = glm::vec3(
                        sinf(theta) * sinf(phi - timeVal) * tanf(theta + timeVal),
                        cosf(phi) * sinf(phi),
                        cosf(theta) * sinf(phi)
                    );
                    mMesh.setVertex(segment*mSegments + i, direction*mRadius + direction*fft[i]*50);
                }
            }
        break;
        case TRIG_6:
            for(int i = 0; i < BUFFER_SIZE; i++) {
                float phi = ofMap(i, 0, BUFFER_SIZE, 0, TWO_PI);
                for(int segment = 0; segment < mSegments; segment++) {

                    float theta = ((float) segment / (float) mSegments)*TWO_PI;

                    glm::vec3 direction = glm::vec3(
                        sinf(theta) * sinf(phi - timeVal) * tanf(theta + timeVal),
                        cosf(phi) * cosf(phi) ,
                        cosf(theta) * sinf(phi)
                    );
                    mMesh.setVertex(segment*mSegments + i, direction*mRadius + direction*fft[i]*50);
                }
            }
        break;
    }

}

void SpikedBall::draw(DrawModel & model, StateModel & state){
    mMesh.draw();
}

void SpikedBall::onKick(float amp, float vel){
    mModeManager.updateMode();
}

void SpikedBall::onSnare(float amp, float vel){

}

void SpikedBall::onHat(float amp, float vel){

}

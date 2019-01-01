#include "FFTHistoryPlane.h"

FFTHistoryPlane::FFTHistoryPlane(int historyLength) :
    mPointDistance(glm::vec2(2, 2)),
    mMaxHeight(100.0f)
    {
    mHistoryLength = historyLength;
    mFFTHistory.resize(historyLength);
    for(auto & spectrum : mFFTHistory) {
        spectrum.resize(BUFFER_SIZE);
    }

    for(int i = 0; i < historyLength * BUFFER_SIZE; i++) {
        mFFTMesh.addVertex(glm::vec3(0,0,0));
    }

    mFFTMesh.setMode(OF_PRIMITIVE_POINTS);

    mYOffset = BUFFER_SIZE*mPointDistance.y/2;
}

void FFTHistoryPlane::setup(){

}

void FFTHistoryPlane::update(DrawModel & model, StateModel & state){
    mFFTHistory.push_back(model.audio.mFft);
    mFFTHistory.erase(mFFTHistory.begin());

    for(int x = 0; x < mFFTHistory.size(); x++) {
        for(int y = 0; y < mFFTHistory[x].size(); y++) {
            mFFTMesh.setVertex(
                x*mFFTHistory.size() + y, 
                glm::vec3(
                    x * mPointDistance.x,
                    -mYOffset + y * mPointDistance.y,
                    mFFTHistory[x][y] * mMaxHeight
                )
            );
        }
    }
}

void FFTHistoryPlane::draw(DrawModel & model, StateModel & state){
    ofPushMatrix();
        mFFTMesh.draw();
        ofScale(-1, 1, 1);
        mFFTMesh.draw();
    ofPopMatrix();
}

void FFTHistoryPlane::onKick(float amp, float vel){

}

void FFTHistoryPlane::onSnare(float amp, float vel){

}

void FFTHistoryPlane::onHat(float amp, float vel){

}

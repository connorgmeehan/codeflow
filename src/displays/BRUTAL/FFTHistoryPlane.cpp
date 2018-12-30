#include "FFTHistoryPlane.h"

FFTHistoryPlane::FFTHistoryPlane(int historyLength) :
    mPointDistance(glm::vec2(5, 5)),
    mMaxHeight(100.0f)
    {
    mFFTHistory.reserve(historyLength);
    for(auto & spectrum : mFFTHistory) {
        spectrum.resize(BUFFER_SIZE);
    }

    for(int i = 0; i < historyLength * BUFFER_SIZE; i++) {
        mFFTMesh.addVertex(glm::vec3(0,0,0));
    }

    mFFTMesh.setMode(OF_PRIMITIVE_POINTS);
}

void FFTHistoryPlane::setup(){

}

void FFTHistoryPlane::update(DrawModel & model){
    auto & fft = model.audio.mFft;
    mFFTHistory.push_back(fft);

    for(int x = 0; x < mFFTHistory.size(); x++) {
        for(int y = 0; y < mFFTHistory[x].size(); y++) {
            mFFTMesh.setVertex(x*mFFTHistory.size() + y, glm::vec3(x * mPointDistance.x, y*mPointDistance.y, fft[y] * mMaxHeight));
        }
    }
}

void FFTHistoryPlane::draw(DrawModel & model){
    mFFTMesh.draw();
}

void FFTHistoryPlane::onKick(float amp, float vel){

}

void FFTHistoryPlane::onSnare(float amp, float vel){

}

void FFTHistoryPlane::onHat(float amp, float vel){

}

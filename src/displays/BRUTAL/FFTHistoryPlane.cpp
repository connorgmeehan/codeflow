#include "FFTHistoryPlane.h"

FFTHistoryPlane::FFTHistoryPlane(int historyLength) :
    mPointDistance(glm::vec2(4, 4)),
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

    mFFTMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

    mYOffset = BUFFER_SIZE*mPointDistance.y/2;

    mModeManager = ModeManager<FFTLineTypeMode>(2, MODE_SHUFFLE, 16);
}

void FFTHistoryPlane::setup(){

}

void FFTHistoryPlane::update(DrawModel & model, StateModel & state){
    mFFTHistory.push_back(model.audio.mFft);
    mFFTHistory.erase(mFFTHistory.begin());

    for(int x = 0; x < mFFTHistory.size(); x++) {
        for(int y = 0; y < mFFTHistory[x].size(); y++) {
            mFFTMesh.setVertex(
                y + x*mFFTHistory[x].size(), 
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

    switch(mModeManager.getMode()) {
        case FFT_HISTORY_PATCHES:
            mFFTMesh.setMode(OF_PRIMITIVE_PATCHES);
        break;
        case FFT_HISTORY_POINTS:
            mFFTMesh.setMode(OF_PRIMITIVE_POINTS);
        break;
    }

    ofPushMatrix();
        mFFTMesh.draw();
        ofScale(-1, 1, 1);
        mFFTMesh.draw();
    ofPopMatrix();
    // for(int i = 0; i < mFFTMesh.getVertices().size(); i++) {
    //     std::cout << ", v("<<i<<",["<<mFFTMesh.getVertices()[i]<<"])"<<(i%5==0 ? "\n" : "");
    // }
}

void FFTHistoryPlane::onKick(float amp, float vel){
    mModeManager.updateMode();
}

void FFTHistoryPlane::onSnare(float amp, float vel){

}

void FFTHistoryPlane::onHat(float amp, float vel){

}

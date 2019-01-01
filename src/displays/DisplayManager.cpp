#include "DisplayManager.h"

DisplayManager::DisplayManager(AudioAnalyser * pAudioAnalyser) :
    mpAudioAnalyser(pAudioAnalyser) {

}

void DisplayManager::setup(){

    setupChannels();

    for(auto & drawable : mDrawQue) {
        drawable->setup();
    }
}

void DisplayManager::update(DrawModel & model){
    if(model.beats.size() >= 1 && model.beats[0].mActive) {
        for(auto & drawable : mDrawQue) {
            drawable->onKick(model.beats[0].mAmp, model.beats[0].mVel);
        }
    }
    if(model.beats.size() >= 2 && model.beats[1].mActive) {
        for(auto & drawable : mDrawQue) {
            drawable->onSnare(model.beats[1].mAmp, model.beats[1].mVel);
        }
    }
    if(model.beats.size() >= 3 && model.beats[2].mActive) {
        for(auto & drawable : mDrawQue) {
            drawable->onHat(model.beats[2].mAmp, model.beats[2].mVel);
        }
    }

    for(auto & drawable : mDrawQue) {
        drawable->update(model);
    }
}

void DisplayManager::draw(DrawModel & model){
    ofBackground(0);
    
    for(auto & drawable : mDrawQue) {
        drawable->draw(model);
    }
}

void DisplayManager::setupChannels() {

    OrbitCamera * cam = new OrbitCamera;
    mDrawQue.push_back(cam);

    FFTHistoryPlane * historyPlane = new FFTHistoryPlane(100);
    mDrawQue.push_back(historyPlane);

    mDrawQue.push_back(cam);

}
#include "DisplayManager.h"

DisplayManager::DisplayManager(AudioAnalyser * pAudioAnalyser) :
    mpAudioAnalyser(pAudioAnalyser) {
    mStateModel.mResolution = glm::ivec2(1024, 768);
}

void DisplayManager::setup(){

    setupChannels();

    for(auto & drawable : mDrawQue) {
        drawable->setup();
    }
}

void DisplayManager::update(DrawModel & model){

    mStateModel.mTime = ofGetElapsedTimef();

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
        drawable->update(model, mStateModel);
    }
}

void DisplayManager::draw(DrawModel & model){
    ofBackground(0);
    
    for(auto & drawable : mDrawQue) {
        drawable->draw(model, mStateModel);
    }
}

void DisplayManager::setupChannels() {
    OrbitCamera * cam = new OrbitCamera;
    mDrawQue.push_back(cam);

    ContextSwitcher * cswitcher = new ContextSwitcher(SWITCHER_HAT, SWITCHER_CYCLE);
    cswitcher
        ->addContext(new StyleContext(ofColor(255,0,0)))
        ->addContext(new StyleContext(ofColor(0,0,255)));

    FFTHistoryPlane * fftHistory = new FFTHistoryPlane(100);

    PerlinOctopus * perlinOctopus = new PerlinOctopus(200, 5.0f, 0.1f, 400.0f, 20);

    mDrawQue.push_back(cswitcher);

    ChannelSwitcher * switcher = new ChannelSwitcher(SWITCHER_HAT, SWITCHER_CYCLE);
    switcher->addChannel(fftHistory)->addChannel(perlinOctopus);
    mDrawQue.push_back(switcher);

    mDrawQue.push_back(cam);

    Debug * debug = new Debug();
    mDrawQue.push_back(debug);
}
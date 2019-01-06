#include "FboContext.h"

void FboContext::setup(){
    mSettings.width = ofGetWidth();
    mSettings.height = ofGetHeight();
    mSettings.numColorbuffers = 4;
    mFbo.allocate(mSettings);

    // Clear fbo memory
    mFbo.begin();
    ofClear(0,0,0,0);
    mFbo.end();
}

void FboContext::update(DrawModel & model, StateModel & state){

}

void FboContext::begin(DrawModel & model, StateModel & state){
    mFbo.begin();
    ofClear(0,0,0,0);
}

void FboContext::end(DrawModel & model, StateModel & state){
    mFbo.end();
}

void FboContext::onKick(float amp, float vel){

}

void FboContext::onSnare(float amp, float vel){

}

void FboContext::onHat(float amp, float vel){

}

ofTexture & FboContext::getTexture() {
    return mFbo.getTexture();
}
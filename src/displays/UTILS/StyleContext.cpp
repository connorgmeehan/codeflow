#include "StyleContext.h"

StyleContext::StyleContext(ofColor color) : mColor(color) {}

void StyleContext::setup(){

}

void StyleContext::update(DrawModel & model, StateModel & state){

}

void StyleContext::begin(DrawModel & model, StateModel & state){
    ofPushStyle();
    ofSetColor(mColor);
    ofLog() << "StyleContext::begin() -> color = " << mColor.r << ", " << mColor.g << ", " << mColor.b;
}

void StyleContext::end(DrawModel & model, StateModel & state){
    ofPopStyle();
    // ofLog() << "StyleContext::end() -> color = " << mColor.r << ", " << mColor.g << ", " << mColor.b;

}

void StyleContext::onKick(float amp, float vel){

}

void StyleContext::onSnare(float amp, float vel){

}

void StyleContext::onHat(float amp, float vel){

}
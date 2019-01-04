#include "StyleContext.h"

StyleContext::StyleContext(ofColor color) : mColor(color) {}

void StyleContext::setup(){

}

void StyleContext::update(DrawModel & model, StateModel & state){

}

void StyleContext::begin(DrawModel & model, StateModel & state){
    ofPushStyle();
    ofSetColor(mColor);
}

void StyleContext::end(DrawModel & model, StateModel & state){
    ofPopStyle();
}

void StyleContext::onKick(float amp, float vel){

}

void StyleContext::onSnare(float amp, float vel){

}

void StyleContext::onHat(float amp, float vel){

}
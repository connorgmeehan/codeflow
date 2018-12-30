#include "Test.h"

void Test::setup(){

}

void Test::update(DrawModel & model){

}

void Test::draw(DrawModel & model){
    ofBackground(ofColor::red);
    ofSetColor(ofColor::white);
    auto & fft = model.audio.mFft;
    for(int i = 0; i < fft.size(); i++) {
        ofDrawCircle(i * 2, fft[i]*100, 2);
    }
}

void Test::onKick(float amp, float vel){

}

void Test::onSnare(float amp, float vel){

}

void Test::onHat(float amp, float vel){

}

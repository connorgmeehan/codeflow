#include "Debug.h"

void Debug::setup(){

}

void Debug::update(DrawModel & model){

}

void Debug::draw(DrawModel & model){
    ofPolyline fftMesh;
    fftMesh.addVertex(0, 400);
    for(int i = 0; i < model.audio.mFft.size(); i++) {
        fftMesh.addVertex(i*2.0f, 400.0f-400.0f*model.audio.mFft[i]);
    }
    fftMesh.addVertex(model.audio.mFft.size()*2.0f, 400.0f);
    fftMesh.draw();

    ofNoFill();

    // TODO -> figure out why this causes a segfault on AudioAnalyser::getConfigModel() -> BeatAnalyser::getProcessBeats()
    mMainMutex.lock();
    auto configModel = mpAudioAnalyser->getConfigModel();
    mMainMutex.unlock();
    auto processBeatModels = configModel.processBeats;

    for(int i = 0; i < processBeatModels.size(); i++) {
        auto & beat = model.beats[i];
        auto & processBeat = processBeatModels[i];
        if(beat.mActive) {
            ofSetColor(ofColor::green);
        } else {
            ofSetColor(ofColor::red);
        }
        ofDrawRectangle(processBeat.getLocation()*2-processBeat.getRadius(), 400, processBeat.getRadius()*2, -beat.mAmp*400);
        ofDrawLine(processBeat.getLocation()*2-10, 40+beat.mVel*40, processBeat.getLocation()*2+10, 40-beat.mVel*40);
        ofDrawBitmapString(ofToString(beat.mVel, 2), processBeat.getLocation()*2-10, 80);
    }

    std::string debugString = "fps: " + ofToString(ofGetFrameRate(), 2) + "fps\n";
    debugString += "fft bin size = " + ofToString(model.audio.mFft.size()) + "\n";
    debugString += "beat size = " + ofToString(model.beats.size()) + "\n";
    for(auto & beat : model.beats) {
        debugString += "\tbeat(amp: " + ofToString(beat.mAmp) + ", vel " + ofToString(beat.mVel) + ")\n";
    }

    ofDrawBitmapString(debugString, ofGetWidth() - 400, ofGetHeight()/2);
}

void Debug::onKick(float amp, float vel){

}

void Debug::onSnare(float amp, float vel){

}

void Debug::onHat(float amp, float vel){

}

void Debug::setAnalyserPointer(AudioAnalyser * pAudioAnalyser) {
    mpAudioAnalyser = pAudioAnalyser;
}
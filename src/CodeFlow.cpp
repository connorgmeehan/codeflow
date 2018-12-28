#include "CodeFlow.h"

//--------------------------------------------------------------
void CodeFlowApp::setup(){
    mAudioAnalyser.setup();
}

//--------------------------------------------------------------
void CodeFlowApp::update(){

}   

//--------------------------------------------------------------
void CodeFlowApp::draw(){
    ofBackground(0);
    ofSetColor(200);
    DrawModel audioModel = mAudioAnalyser.getDrawModel();
    for(int i = 0; i < audioModel.audio.mFft.size(); i++) {
        ofDrawCircle(i*2, 0 + ofGetHeight() * audioModel.audio.mFft[i], 2);
    }

    ofNoFill();
    for(int i = 0; i < audioModel.beats.size(); i++) {
        auto & beat = audioModel.beats[i];
        if(beat.mActive) {
            ofSetColor(ofColor::green);
        } else {
            ofSetColor(ofColor::red);
        }
        ofDrawRectangle(500 + i*20, 40, 20, 40-beat.mAmp*40);
        ofDrawLine(500 + i*20, 40, 500 + (i+1)*20, 40-beat.mVel*40);
    }

    std::string debugString = "fps: " + ofToString(ofGetFrameRate(), 2) + "fps\n";
    debugString += "fft bin size = " + ofToString(audioModel.audio.mFft.size()) + "\n";
    debugString += "beat size = " + ofToString(audioModel.beats.size()) + "\n";
    for(auto & beat : audioModel.beats) {
        debugString += "\tbeat(amp: " + ofToString(beat.mAmp) + ", vel " + ofToString(beat.mVel) + ")\n";
    }

    ofDrawBitmapString(debugString, ofGetWidth() - 400, ofGetHeight()/2);
}

//--------------------------------------------------------------
void CodeFlowApp::keyPressed(int key){

}

//--------------------------------------------------------------
void CodeFlowApp::keyReleased(int key){

}

//--------------------------------------------------------------
void CodeFlowApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void CodeFlowApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void CodeFlowApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void CodeFlowApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void CodeFlowApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void CodeFlowApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void CodeFlowApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void CodeFlowApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void CodeFlowApp::dragEvent(ofDragInfo dragInfo){ 

}

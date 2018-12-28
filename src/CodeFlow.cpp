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

    ofPolyline fftMesh;
    fftMesh.addVertex(0, 400);
    for(int i = 0; i < audioModel.audio.mFft.size(); i++) {
        fftMesh.addVertex(i*2.0f, 400.0f-400.0f*audioModel.audio.mFft[i]);
    }
    fftMesh.addVertex(audioModel.audio.mFft.size()*2.0f, 400.0f);
    fftMesh.draw();

    ofNoFill();
    auto processBeatModels = mAudioAnalyser.getProcessBeatModels();
    for(int i = 0; i < processBeatModels.size(); i++) {
        auto & beat = audioModel.beats[i];
        auto & processBeat = processBeatModels[i];
        if(beat.mActive) {
            ofSetColor(ofColor::green);
        } else {
            ofSetColor(ofColor::red);
        }
        ofDrawRectangle(processBeat.getLocation()*2-processBeat.getRadius(), 400, processBeat.getRadius()*2, -beat.mAmp*400);
        ofDrawLine(processBeat.getLocation()*2-processBeat.getRadius(), 40, processBeat.getLocation()*2+processBeat.getRadius(), 40-beat.mVel*40);
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

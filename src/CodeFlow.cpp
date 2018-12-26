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
    AudioModel audioModel = mAudioAnalyser.getAudioModel();
    for(int i = 0; i < audioModel.mFft.size(); i++) {
        ofDrawCircle(i*2, 0 + ofGetHeight() * audioModel.mFft[i], 2);
    }
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

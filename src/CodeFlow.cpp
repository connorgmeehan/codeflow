#include "CodeFlow.h"

//--------------------------------------------------------------
void CodeFlowApp::setup(){
    mAudioAnalyser.setup();
    mDisplayManager.setup();
}

//--------------------------------------------------------------
void CodeFlowApp::update(){
    mDrawModel = mAudioAnalyser.getDrawModel();
    mDisplayManager.update(mDrawModel);
}   

//--------------------------------------------------------------
void CodeFlowApp::draw(){
    mDisplayManager.draw(mDrawModel);
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

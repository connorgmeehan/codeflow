
#include "MessageCloud.h"

MessageCloud::MessageCloud(std::string message, int numPoints, float radius, float perlinMultiplier) :
    mRadius(radius),
    mPerlinMultiplier(perlinMultiplier),
    mMessageIndexOffset(0) {
    istringstream in(message);
    copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(mMessages));

    for(int i = 0; i < numPoints; i++) {
        mMesh.addVertex(glm::vec3(0,0,0));
    }

    mMesh.setMode(OF_PRIMITIVE_POINTS);
}

void MessageCloud::setup(){

}

void MessageCloud::update(DrawModel & model, StateModel & state){

    float timeVal = state.mTime * 0.025;

    for(float i = 0; i < mMesh.getVertices().size(); i++) {
        mMesh.setVertex(i, glm::vec3(
            ofSignedNoise(timeVal + i*mPerlinMultiplier) * mRadius,
            ofSignedNoise(timeVal - i*mPerlinMultiplier) * mRadius,
            ofSignedNoise(500 + timeVal + i*mPerlinMultiplier) * mRadius
        ));
    }
    
}

void MessageCloud::draw(DrawModel & model, StateModel & state){
    ofSetSphereResolution(4);

    mMesh.draw();
    
    mMessageIndexOffset ++;

    for(int i = 0; i < mMessages.size(); i++) {
        int pointIndex = i + mMessageIndexOffset % mMesh.getVertices().size();
        ofDrawBitmapString(mMessages[i], mMesh.getVertices()[pointIndex]);
    }
}

void MessageCloud::onKick(float amp, float vel){

}

void MessageCloud::onSnare(float amp, float vel){

}

void MessageCloud::onHat(float amp, float vel){

}

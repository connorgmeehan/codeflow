#include "TrigDeath.h"

TrigDeath::TrigDeath(int latitudeResolution, int longitudeResolution, float radius, float perlinMultiplier) :
    mLatitudeRes(latitudeResolution),
    mLongitudeRes(longitudeResolution),
    mRadius(radius),
    mPerlinMultiplier(perlinMultiplier) {

}

void TrigDeath::setup(){

}

void TrigDeath::update(DrawModel & model, StateModel & state){

}

void TrigDeath::draw(DrawModel & model, StateModel & state){
    ofMesh temp;
    temp.setMode(OF_PRIMITIVE_LINE_LOOP);
    auto & fft = model.audio.mFft;
    float time = state.mTime/2;
    
    float angleMult = 360/mLatitudeRes;

    
    for(int layer = 0; layer < mLatitudeRes; layer++){
        temp.clear();
        
        float radius = mRadius + fft[layer] * mPerlinMultiplier;
        for(int vert = 0; vert < mLongitudeRes; vert++){
            float perlinHoles = ofSignedNoise((float) layer/10, (float) vert/10, time);
            float perlinOffset = ofSignedNoise((float) layer/10, (float) vert/10, time, 1);

            if( perlinHoles < model.beats[0].mAmp){
                temp.draw();
                temp.clear();
                continue;
            }

            glm::vec3 vec = glm::vec3(
                cos(ofDegToRad(layer*angleMult)) * cos(ofDegToRad(vert*angleMult)),
                cos(ofDegToRad(layer*angleMult)) * sin(ofDegToRad(vert*angleMult)),
                sin(ofDegToRad(-layer*angleMult/2))
            );
           
            temp.addVertex(vec * radius + vec*perlinOffset*mPerlinMultiplier);
            temp.addVertex(vec * (radius + fft[layer]*10) + vec*perlinOffset*mPerlinMultiplier);
        }
        temp.draw();
    }
}

void TrigDeath::onKick(float amp, float vel){

}

void TrigDeath::onSnare(float amp, float vel){

}

void TrigDeath::onHat(float amp, float vel){

}


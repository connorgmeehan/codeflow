#ifndef __OrbitCamera_H__
#define __OrbitCamera_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

#include "ofxEasyCam.h"

class OrbitCamera : public Context {
    public:
        std::string getName(){ return std::string("OrbitCameraChannel"); }
        void setup();
        void begin(DrawModel & model);
        void end(DrawModel & model);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
};

void OrbitCamera::setup(){

}

void OrbitCamera::begin(DrawModel & model){

}

void OrbitCamera::end(DrawModel & model){

}

void OrbitCamera::onKick(float amp, float vel){

}

void OrbitCamera::onSnare(float amp, float vel){

}

void OrbitCamera::onHat(float amp, float vel){

}

#endif
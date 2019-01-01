#ifndef __OrbitCamera_H__
#define __OrbitCamera_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"

class OrbitCamera : public Context {
    public:
        std::string getName(){ return std::string("OrbitCameraChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void begin(DrawModel & model, StateModel & state);
        void end(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);

    private:
        ofEasyCam cam;
};

#endif
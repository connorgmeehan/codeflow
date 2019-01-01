#ifndef __OrbitCamera_H__
#define __OrbitCamera_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"

class OrbitCamera : public Context {
    public:
        std::string getName(){ return std::string("OrbitCameraChannel"); }
        void setup();
        void update(DrawModel & model);
        void begin(DrawModel & model);
        void end(DrawModel & model);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);

    private:
        ofEasyCam cam;
};

#endif
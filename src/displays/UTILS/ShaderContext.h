#ifndef __ShaderContext_H__
#define __ShaderContext_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class ShaderContext : public Channel {
    public:
        ShaderContext(std::string shaderPath);
        std::string getName(){ return std::string("ShaderContextContext"); }
        void setup();
        void update(DrawModel & model, StateModel & state);

        void begin(DrawModel & model, StateModel & state);
        void end(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        ofShader mShader;
};

#endif
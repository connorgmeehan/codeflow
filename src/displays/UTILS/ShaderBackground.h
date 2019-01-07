#ifndef __ShaderBackground_H__
#define __ShaderBackground_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class ShaderBackground : public Channel {
    public:
        ShaderBackground(std::string shaderPath = "") : mShaderPath(shaderPath) {
            if(shaderPath != "" ){
                mShader.load(shaderPath);
                mHasShader = true;
            }
        }
        std::string getName(){ return std::string("ShaderBackgroundChannel"); }
        void setup() {}
        void update(DrawModel & model, StateModel & state) {}
        void draw(DrawModel & model, StateModel & state) {
            if(mHasShader) {
                mShader.begin();

                mShader.setUniform2f("u_resolution", state.mResolution.x, state.mResolution.y);
                mShader.setUniform1f("u_time", state.mTime);
                mShader.setUniform1f("kick", model.beats[0].mAmp);
                mShader.setUniform1f("snare", model.beats[1].mAmp);
                mShader.setUniform1f("kick", model.beats[2].mAmp);
            }

            ofDrawPlane(0, 0,10000, 10000);
            
            if(mHasShader) {
                mShader.end();
            }
        }

        void onKick(float amp, float vel) {
            // ofLog() << "Reloading Shader";
            // mShader.load(mShaderPath);
        }
        void onSnare(float amp, float vel) {}
        void onHat(float amp, float vel) {}
    private:
        ofShader mShader;
        std::string mShaderPath;
        bool mHasShader;
};

#endif
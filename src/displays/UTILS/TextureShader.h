#ifndef __TextureShader_H__
#define __TextureShader_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"
#include "HasTexture.h"

class TextureShader : public Context {
    public:
        TextureShader(std::string shaderPath, HasTexture * pHasTexture)
            :mpHasTexture(pHasTexture) {
            mShader.load(shaderPath);
        }
        std::string getName(){ return std::string("TextureShaderContext"); }
        void setup() { }
        void update(DrawModel & model, StateModel & state) {
            
        }
        void begin(DrawModel & model, StateModel & state){
            mShader.begin();
            mShader.setUniformTexture("tex0", mpHasTexture->getTexture(), 0);
            mShader.setUniform2i("u_resolution", state.mResolution.x, state.mResolution.y);
            mShader.setUniform1f("u_time", state.mTime);
        }
        void end(DrawModel & model, StateModel & state){
            mShader.end();
        }

        void onKick(float amp, float vel){ }
        void onSnare(float amp, float vel){ }
        void onHat(float amp, float vel){ }
    private:
        ofShader mShader;
        HasTexture * mpHasTexture;
};

#endif
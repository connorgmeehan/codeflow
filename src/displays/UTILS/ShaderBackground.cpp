#include "ShaderContext.h"

ShaderContext::ShaderContext(std::string shaderPath) {
    mShader.load(shaderPath);
}

void ShaderContext::setup(){

}

void ShaderContext::update(DrawModel & model, StateModel & state){

}

void ShaderContext::begin(DrawModel & model, StateModel & state) {
    mShader.begin();
    mShader.setUniform2i("u_resolution", state.mResolution.x, state.mResolution.y);
    mShader.setUniform1f("u_time", state.mTime);
}

void ShaderContext::end(DrawModel & model, StateModel & state) {
    mShader.end();
}

void ShaderContext::onKick(float amp, float vel){

}

void ShaderContext::onSnare(float amp, float vel){

}

void ShaderContext::onHat(float amp, float vel){

}
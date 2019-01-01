#include "ShaderBackground.h"

ShaderBackground::ShaderBackground(std::string shaderPath) {
    mShader.load(shaderPath);
}

void ShaderBackground::setup(){

}

void ShaderBackground::update(DrawModel & model, StateModel & state){

}

void ShaderBackground::begin(DrawModel & model, StateModel & state) {
    mShader.begin();
    mShader.setUniform2i("u_resolution", state.mResolution.x, state.mResolution.y);
    mShader.setUniform1f("u_time", state.mTime);
}

void ShaderBackground::end(DrawModel & model, StateModel & state) {
    mShader.end();
}

void ShaderBackground::onKick(float amp, float vel){

}

void ShaderBackground::onSnare(float amp, float vel){

}

void ShaderBackground::onHat(float amp, float vel){

}
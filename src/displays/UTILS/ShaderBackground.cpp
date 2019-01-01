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
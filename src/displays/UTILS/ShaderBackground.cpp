#include "ShaderBackground.h"

ShaderBackround::ShaderBackground(std::string shaderPath) {
    mShader.load(shaderPath);
}

void ShaderBackground::setup(){

}

void ShaderBackground::update(DrawModel & model){

}

void ShaderBackground::begin(DrawModel & model) {
    mShader.begin();
}

void ShaderBackground::end(DrawModel & model) {
    mShader.end();
}

void ShaderBackground::onKick(float amp, float vel){

}

void ShaderBackground::onSnare(float amp, float vel){

}

void ShaderBackground::onHat(float amp, float vel){

}
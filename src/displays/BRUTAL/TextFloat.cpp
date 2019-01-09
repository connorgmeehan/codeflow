#include "TextFloat.h"

TextFloat::TextFloat(std::string fontPath, std::string message, int fontSize) {
    mFont.load(fontPath, fontSize, true, true, true);
    mVertWarpShader.load("shaders/base.vert","shaders/utils/perlinwarp.frag");

    istringstream in(message);
    copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(mMessage));
    mTotalWidth = mFont.stringWidth(message);
}

void TextFloat::setup(){

}

void TextFloat::update(DrawModel & model, StateModel & state){

}

void TextFloat::draw(DrawModel & model, StateModel & state){
    mOffset += 2.0f;
    float textOffset = 0.0f;
    for(auto & message : mMessage) {
        mFont.drawString(message, fmodf(mOffset + textOffset, mTotalWidth)-mTotalWidth/2, 0);
        textOffset += mFont.stringWidth(message) + 30.0f;
    }
}

void TextFloat::onKick(float amp, float vel){

}

void TextFloat::onSnare(float amp, float vel){

}

void TextFloat::onHat(float amp, float vel){

}

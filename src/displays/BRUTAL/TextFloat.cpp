#include "TextFloat.h"

TextFloat::TextFloat(std::string fontPath, std::string message, int fontSize) {
    mFont.load(fontPath, fontSize, true, true, true);

    istringstream in(message);
    copy(istream_iterator<string>(in), istream_iterator<string>(), back_inserter(mMessage));
    mTotalWidth = mFont.stringWidth(message);
}

void TextFloat::setup(){

}

void TextFloat::update(DrawModel & model, StateModel & state){

}

void TextFloat::draw(DrawModel & model, StateModel & state){
    float offset = -mTotalWidth/2;
    for(auto & message : mMessage) {
        mFont.drawStringAsShapes(message, offset, 0);
        offset += mFont.stringWidth(message);
    }
}

void TextFloat::onKick(float amp, float vel){

}

void TextFloat::onSnare(float amp, float vel){

}

void TextFloat::onHat(float amp, float vel){

}

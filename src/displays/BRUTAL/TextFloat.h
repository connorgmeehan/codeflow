#ifndef __TextFloat_H__
#define __TextFloat_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class TextFloat : public Channel {
    public:
        TextFloat(std::string fontPath, std::string message, int fontSize);
        std::string getName(){ return std::string("TextFloatChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void draw(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        std::vector<std::string> mMessage;
        ofTrueTypeFont mFont;
        float mTotalWidth;
        float mOffset;
        ofShader mVertWarpShader;
};

#endif
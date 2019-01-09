#ifndef __MessageCloud_H__
#define __MessageCloud_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class MessageCloud : public Channel {
    public:
        MessageCloud(std::string message, int numPoints, float radius, float perlinMultiplier);
        std::string getName(){ return std::string("MessageCloudChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void draw(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        ofMesh mMesh;
        std::vector<std::string> mMessages;
        float mRadius;
        float mPerlinMultiplier;
        int mMessageIndexOffset;
};

#endif
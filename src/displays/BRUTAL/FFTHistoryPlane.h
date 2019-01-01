#ifndef __FFTHistoryPlane_H__
#define __FFTHistoryPlane_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

#include "circular.h"

class FFTHistoryPlane : public Channel {
    public:
        FFTHistoryPlane(int historyLength);

        std::string getName(){ return std::string("FFTHistoryPlaneChannel"); }
        void setup();
        void update(DrawModel & model);
        void draw(DrawModel & model);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);

    private:
        std::vector<std::vector<float>> mFFTHistory;

        int mHistoryLength;
        ofMesh mFFTMesh;
        glm::vec2 mPointDistance;
        float mMaxHeight;
        float mYOffset;
};

#endif
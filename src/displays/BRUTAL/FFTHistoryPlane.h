#ifndef __FFTHistoryPlane_H__
#define __FFTHistoryPlane_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

#include "ModeManager.h"

enum FFTLineTypeMode {
    FFT_HISTORY_LINE_LOOP,
    FFT_HISTORY_LINE_STRIP,
    FFT_HISTORY_LINE_STRIP_ADJACENCY,
    FFT_HISTORY_LINES,
    FFT_HISTORY_PATCHES,
    FFT_HISTORY_POINTS
};

class FFTHistoryPlane : public Channel {
    public:
        FFTHistoryPlane(int historyLength);

        std::string getName(){ return std::string("FFTHistoryPlaneChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void draw(DrawModel & model, StateModel & state);

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
        int mSkipLength;

        ModeManager<FFTLineTypeMode> mModeManager;
};

#endif
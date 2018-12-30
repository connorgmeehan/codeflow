#ifndef __Debug_H__
#define __Debug_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

#include "AudioAnalyser.h"

class Debug : public Channel {
    public:
        void setup();
        void update(DrawModel & model);
        void draw(DrawModel & model);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);

        void setAnalyserPointer(AudioAnalyser * pAudioAnalyser);
    private:
        AudioAnalyser * mpAudioAnalyser = nullptr;
        ofMutex mMainMutex;
};

#endif
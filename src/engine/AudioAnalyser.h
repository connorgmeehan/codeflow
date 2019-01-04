#ifndef __AUDIO_ANALYSER_H__
#define __AUDIO_ANALYSER_H__

#include "ofMain.h"
#include "SignalAnalyser.h"

#include "BeatAnalyser.h"
#include "DrawModel.h"

class AudioAnalyser : public ofBaseApp {
    public:
        void setup();

        DrawModel & getDrawModel();
        ConfigModel getConfigModel();
    private:
        SignalAnalyser mSignalAnalyser;
        BeatAnalyser mBeatAnalyser;

        ProcessAudioModel mProcessAudioModel;
        DrawModel mDrawModel;
};

#endif
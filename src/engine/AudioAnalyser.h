#ifndef __AUDIO_ANALYSER_H__
#define __AUDIO_ANALYSER_H__

#include "ofMain.h"
#include "ofxFft.h"

#include "BeatAnalyser.h"
#include "DrawModel.h"

class AudioAnalyser : public ofBaseApp {
    public:
        void setup();

        DrawModel getDrawModel();
        void audioIn(ofSoundBuffer & buffer);

        ProcessAudioModel getProcessAudioModel();
        std::vector<ProcessBeatModel> getProcessBeatModels();
    private:

        ofxFft * mFft;
        ofSoundStream mSoundStream;
        ofMutex mSoundMutex;

        ProcessAudioModel mProcessAudioModel;
        DrawModel mDrawModel;
        BeatAnalyser mBeatAnalyser;
};

#endif
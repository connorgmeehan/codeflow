#ifndef __AUDIO_ANALYSER_H__
#define __AUDIO_ANALYSER_H__

#include "ofMain.h"
#include "ofxFft.h"

#include "AudioModel.h"

class AudioAnalyser : public ofBaseApp {
    public:
        void setup();

        AudioModel getAudioModel();
        void audioIn(ofSoundBuffer & buffer);
    private:

        ofxFft * mFft;
        ofSoundStream mSoundStream;
        ofMutex mSoundMutex;

        AudioModel mAudioModel;

        float * mFftOutput;
        float * mEqFunction;
};

#endif
#ifndef __SIGNAL_ANALYSER_H__
#define __SIGNAL_ANALYSER_H__

#include "ofxFFTLive.h"
#include "AudioModel.h"

class SignalAnalyser : public ofxFFTBase {
    public:
        SignalAnalyser();
        ~SignalAnalyser();
        void setup();
        void setup(std::string deviceName);
        void setup(ofSoundDevice & device);
        void audioIn(ofSoundBuffer & buffer);
        void setCallback(std::function<void (const std::vector<float> &)> callback);
        AudioModel getAudioModel();
    private:
        ofSoundStream soundStream;
        std::function<void (const std::vector<float> &)> mCallback;
        AudioModel mAudioModel;
};

#endif
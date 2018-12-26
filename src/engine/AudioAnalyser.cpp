#include "AudioAnalyser.h"

void AudioAnalyser::setup() {
    mFft = ofxFft::create(BUFFER_SIZE, OF_FFT_WINDOW_HAMMING, OF_FFT_FFTW);
    
    ofSoundStreamSettings settings;

    mSoundStream.printDeviceList();
	auto devices = mSoundStream.getMatchingDevices("default");
    if(!devices.empty()) {
        settings.setInDevice(devices[0]);
    }

    settings.setInListener(this);
    settings.numInputChannels = 2;
    settings.numOutputChannels = 0;
    settings.numBuffers = 2;
    settings.sampleRate = 44100;
    settings.bufferSize = BUFFER_SIZE;

    mSoundStream.setup(settings);
}

void AudioAnalyser::audioIn(ofSoundBuffer & buffer) { 
    mFft->setSignal(buffer.getBuffer());
    float * curFft = mFft->getAmplitude();
    int binSize = BUFFER_SIZE;

    auto & settingsBin = mAudioModel.mFft;

    for(int i = 0; i < binSize; i++){
        // curFft[i] = abs((curFft[i]/(binSize*(float)1/binSize))*(1+pow(i, exponent)/binSize));//Then make low frequency values weighted lower than high frequency with pow
        settingsBin[i] = std::max(settingsBin[i], curFft[i])*mDecay;
    }

    // Beat analyser business
}

AudioModel AudioAnalyser::getAudioModel(){
    mSoundMutex.lock();
    AudioModel tempModel = mAudioModel;
    mSoundMutex.unlock();
    return tempModel;
}
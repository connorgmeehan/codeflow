#include "AudioAnalyser.h"

void AudioAnalyser::setup() {
    ofLog() << "AudioAnalyser::setup()";
    // Setup FFT and EQ function
    mFft = ofxFft::create(BUFFER_SIZE, OF_FFT_WINDOW_BARTLETT);

    mFftOutput = new float[mFft->getBinSize()];
    mEqFunction = new float[mFft->getBinSize()];

    // removes logorithmic scaling on fft
    for(int i = 0; i < mFft->getBinSize(); i++){
		mEqFunction[i] = (0.54f - 0.46f*(double)cos(2.0f * PI*i)/mFft->getBinSize());
    }
    
    // Initialise sound stream
    ofSoundStreamSettings settings;

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

    mSoundStream.setup(settings);}

void AudioAnalyser::audioIn(ofSoundBuffer & buffer) { 
    int binSize = mFft->getBinSize();
    mFft->setSignal(buffer.getBuffer());
    memcpy(mFftOutput, mFft->getAmplitude(), sizeof(float) * mFft->getBinSize());
    for(int i = 0; i < binSize; i++) {
		mAudioModel.mFft[i] = mFftOutput[i] * mEqFunction[i];
    }


}

AudioModel AudioAnalyser::getAudioModel(){
    mSoundMutex.lock();
    AudioModel tempModel = mAudioModel;
    mSoundMutex.unlock();
    return tempModel;
}
#include "AudioAnalyser.h"

void AudioAnalyser::setup() {
    ofLog() << "AudioAnalyser::setup()";
    mBeatAnalyser.setup();
    
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

    mSoundStream.setup(settings);

}

void AudioAnalyser::audioIn(ofSoundBuffer & buffer) { 
    int binSize = mFft->getBinSize();
    mFft->setSignal(buffer.getBuffer());
    auto & fft = mDrawModel.audio.mFft;
    memcpy(mFftOutput, mFft->getAmplitude(), sizeof(float) * mFft->getBinSize());
    for(int i = 0; i < binSize; i++) {
		fft[i] = mFftOutput[i] * mEqFunction[i];
    }

    mBeatAnalyser.audioIn(fft);
    mDrawModel.beats = mBeatAnalyser.getBeats();
}

DrawModel AudioAnalyser::getDrawModel(){
    mSoundMutex.lock();
    DrawModel tempModel = mDrawModel;
    mSoundMutex.unlock();
    return tempModel;
}
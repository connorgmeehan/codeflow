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
		// mEqFunction[i] = (0.54f - 0.46f*(double)cos(2.0f * PI*i)/mFft->getBinSize());
        mEqFunction[i] = 0.0f;
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

    float curPeak = 0.0f;
    for(int i = 0; i < binSize; i++) {

        // roughly find the average power of each spectrum over time
        mEqFunction[i] = glm::mix(mEqFunction[i], mFftOutput[i], mFftSmoothSpeed);

        // subtract that power from the output
		mFftOutput[i] -= mEqFunction[i];
        
        // Update current peak based on scaled output
        curPeak = glm::max(curPeak, mFftOutput[i]);

        // multiply that by a smoothed peak value
        fft[i] = mFftOutput[i] * 1/mSmoothedPeak;
    }
    // Update smoothed peak by mixing it slowly towards this frames current peak
    mSmoothedPeak = glm::mix(mSmoothedPeak, curPeak, mFftSmoothSpeed);

    ofLog() << "\taudioIn -> mSmoothedPeak: " << mSmoothedPeak;

    mBeatAnalyser.audioIn(fft);
    mDrawModel.beats = mBeatAnalyser.getBeats();
}

DrawModel AudioAnalyser::getDrawModel(){
    mSoundMutex.lock();
    DrawModel tempModel = mDrawModel;
    mSoundMutex.unlock();
    return tempModel;
}
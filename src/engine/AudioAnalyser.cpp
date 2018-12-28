#include "AudioAnalyser.h"

void AudioAnalyser::setup() {
    ofLog() << "AudioAnalyser::setup()";
    mBeatAnalyser.setup();

    // Setup FFT and EQ function
    mFft = ofxFft::create(BUFFER_SIZE, OF_FFT_WINDOW_BARTLETT);

    mProcessAudioModel = ProcessAudioModel(mFft->getSignalSize());
    
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

    auto & fftOutput = mProcessAudioModel.mFftOutput;
    auto & eqFunction = mProcessAudioModel.mEqFunction;
    float smoothedPeak = mProcessAudioModel.mSmoothedPeak;
    float fftSmoothSpeed = mProcessAudioModel.mFftSmoothSpeed;
    float fftDecay = mProcessAudioModel.mFftDecay;

    memcpy(&fftOutput[0], mFft->getAmplitude(), sizeof(float) * mFft->getBinSize());

    float curPeak = 0.0f;
    for(int i = 0; i < binSize; i++) {

        // roughly find the average power of each spectrum over time
        eqFunction[i] = glm::mix(eqFunction[i], fftOutput[i], fftSmoothSpeed);

        // subtract that power from the output
		fftOutput[i] -= eqFunction[i];
        
        // Update current peak based on scaled output
        curPeak = glm::max(curPeak, fftOutput[i]);

        // multiply that by a smoothed peak value
        fft[i] = glm::max(fft[i], glm::abs(fftOutput[i] * 1/smoothedPeak)) * fftDecay;
    }
    // Update smoothed peak by mixing it slowly towards this frames current peak
    mProcessAudioModel.mSmoothedPeak = glm::mix(mProcessAudioModel.mSmoothedPeak, curPeak, fftSmoothSpeed);
    mBeatAnalyser.audioIn(fft);
    mDrawModel.beats = mBeatAnalyser.getBeats();
}

DrawModel AudioAnalyser::getDrawModel(){
    mSoundMutex.lock();
    DrawModel tempModel = mDrawModel;
    mSoundMutex.unlock();
    return tempModel;
}
#include "SignalAnalyser.h"

SignalAnalyser::SignalAnalyser() : ofxFFTBase() {
    soundStream = NULL;
    setMirrorData(true);
}

SignalAnalyser::~SignalAnalyser() {
    if(soundStream == NULL) {
        return;
    }

    soundStream->stop();
    soundStream->close();
    delete soundStream;
    soundStream = NULL;
}

void SignalAnalyser::setup(std::string deviceName) {
    soundStream = new ofSoundStream();

    auto devices = soundStream->getMatchingDevices(deviceName);
    if(!devices.empty()) {
        setup(devices[0]);
        return;
    }
    ofLog(OF_LOG_ERROR) << "SignalAnalyser::setup(deviceName: "<<deviceName<<") -> No devices found! ";
}

void SignalAnalyser::setup(ofSoundDevice & device) {
    soundStream = new ofSoundStream();

    ofLog() << "SignalAnalyser::setup() -> device["<<device.deviceID<<"] " << device.name << " in: " << device.inputChannels << ", out: " << device.outputChannels;
    
    soundStream->setDevice(device);
    soundStream->printDeviceList();
    ofSoundStreamSettings settings;
    settings.setInListener(this);
    settings.numInputChannels = 1;
    settings.numOutputChannels = 0;
    settings.sampleRate = 44100;
    settings.bufferSize = getBufferSize();
    settings.numBuffers = 4;
    settings.setInDevice(device);

    soundStream->setup(settings);
    // soundStream->setup(this,                   // callback obj.
    //                    0,                      // out channels.
    //                    1,                      // in channels.
    //                    44100,                  // sample rate.
    //                    getBufferSize(),        // buffer size.
    //                    4);                     // number of buffers.
    this->soundStream = soundStream;
}

void SignalAnalyser::audioIn(ofSoundBuffer & buffer) {
    ofxFFTBase::audioIn(&buffer.getBuffer()[0]);
    ofxFFTBase::update();
    mAudioModel.mFft = getFftPeakData();
    mCallback(mAudioModel.mFft);
}

void SignalAnalyser::setCallback(std::function<void (const std::vector<float>&)> callback) {
    mCallback = callback;
}

AudioModel SignalAnalyser::getAudioModel() {
    return mAudioModel;
}
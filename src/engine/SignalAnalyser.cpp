#include "SignalAnalyser.h"

SignalAnalyser::SignalAnalyser() : ofxFFTBase() {
    setMirrorData(true);
    setThreshold(0.1f);
    setPeakDecay(0.75f);
    setMaxDecay(0.995f);
}

SignalAnalyser::~SignalAnalyser() {
    soundStream.stop();
    soundStream.close();
}

void SignalAnalyser::setup() {
    auto devices = soundStream.getDeviceList(ofSoundDevice::Api::ALSA);
    for(auto & device : devices) {
        if (device.isDefaultInput) {
            setup(device);
            return;
        }
    }
}

void SignalAnalyser::setup(std::string deviceName) {
    soundStream.printDeviceList();

    auto devices = soundStream.getMatchingDevices(deviceName);
    if(!devices.empty()) {
        setup(devices[0]);
        return;
    }
    ofLog(OF_LOG_ERROR) << "SignalAnalyser::setup(deviceName: "<<deviceName<<") -> No devices found! ";
}

void SignalAnalyser::setup(ofSoundDevice & device) {
    ofLog() << "SignalAnalyser::setup() -> device["<<device.deviceID<<"] " << device.name << " in: " << device.inputChannels << ", out: " << device.outputChannels;
    
    soundStream.setDevice(device);
    ofSoundStreamSettings settings;
    settings.setInDevice(device);
    settings.setInListener(this);
    settings.numInputChannels = 1;
    settings.numOutputChannels = 0;
    settings.sampleRate = 44100;
    settings.bufferSize = getBufferSize();

    soundStream.setup(settings);
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
#include "AudioAnalyser.h"

void AudioAnalyser::setup() {
    ofLog() << "AudioAnalyser::setup()";
    mBeatAnalyser.setup();

    mProcessAudioModel = ProcessAudioModel(mSignalAnalyser.getBufferSize());

    mSignalAnalyser.setBufferSize(BUFFER_SIZE);
    mSignalAnalyser.setCallback(std::bind(&BeatAnalyser::audioIn, &mBeatAnalyser, std::placeholders::_1));    
    mSignalAnalyser.setup("default");
}

DrawModel & AudioAnalyser::getDrawModel() {
    mDrawModel.audio = mSignalAnalyser.getAudioModel();
    mDrawModel.beats = mBeatAnalyser.getBeats();
    return mDrawModel;
}

ConfigModel AudioAnalyser::getConfigModel() {
    auto beatProcessModels = mBeatAnalyser.getProcessBeatModels();
    return ConfigModel{ beatProcessModels, mProcessAudioModel };
}
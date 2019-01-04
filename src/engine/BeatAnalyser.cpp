#include "BeatAnalyser.h"

void BeatAnalyser::setup() {
    addAnalyser(251, 5, 4);
    addAnalyser(20, 10, 4);
    addAnalyser(40, 15, 4);
    ProcessBeatModel::setTriggerGradient(0.5f);
    ProcessBeatModel::setGradientScale(100.0f);
}

void BeatAnalyser::audioIn(const std::vector<float> & fft) {
    for(int i = 0; i < mBeatProcessors.size(); i++) {
        mBeatModels[i] = mBeatProcessors[i].audioIn(fft);
    }

    ProcessBeatModel::incrementTickCount();
}

std::vector<BeatModel> BeatAnalyser::getBeats() {

    for(auto & beatProcessor : mBeatProcessors) {
        beatProcessor.setBeatState(BEAT_COOLDOWN);
    }

    return mBeatModels;
}

void BeatAnalyser::addAnalyser(int location, int radius, int historySize) {
    mBeatProcessors.push_back(ProcessBeatModel(location, radius, historySize));
    mBeatModels.push_back(BeatModel(false, 0, 0));
}

std::vector<ProcessBeatModel> BeatAnalyser::getProcessBeatModels() {
    return mBeatProcessors;
}
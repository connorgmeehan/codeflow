#ifndef __BEAT_ANALYSER_H__
#define __BEAT_ANALYSER_H__

#include "ofMain.h"
#include "BeatModel.h"
#include "DrawModel.h"

class BeatAnalyser {
    public:
        void setup();

        void audioIn(std::vector<float> & fft);
        std::vector<BeatModel> getBeats();

        std::vector<ProcessBeatModel> getProcessBeatModels();
    private:
        void addAnalyser(int location, int radius, int historySize);
        std::vector<ProcessBeatModel> mBeatProcessors;
        std::vector<BeatModel> mBeatModels;
};

#endif
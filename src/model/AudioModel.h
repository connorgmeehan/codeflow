#ifndef __AUDIO_SETTINGS_H__
#define __AUDIO_SETTINGS_H__

#include <vector>

#define BUFFER_SIZE 512

struct AudioModel {
    std::vector<float> mFft;

    AudioModel() {
        mFft.resize(BUFFER_SIZE, 0.0f);
    }
};


/** 
 * name: ProcessAudioModel
 * desc: Stores the config for the fft audio analysis
 */
struct ProcessAudioModel {
    std::vector<float> mFftOutput; // Stores fft output
    std::vector<float> mEqFunction; // Stores a rough time-average of each bin value to be used to re-scale the spectrum between 0-1
    float mSmoothedPeak;
    float mFftSmoothSpeed;
    float mFftDecay;

    ProcessAudioModel(int fftBinSize) {
        mFftOutput.resize(fftBinSize, 0.0f);
        mEqFunction.resize(fftBinSize, 0.0f);
        mFftSmoothSpeed = 0.01f;
        mSmoothedPeak = 0.1f;
        mFftDecay = 0.90f;
    }

    ProcessAudioModel() { }
};

#endif
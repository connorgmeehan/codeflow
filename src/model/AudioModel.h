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

#endif
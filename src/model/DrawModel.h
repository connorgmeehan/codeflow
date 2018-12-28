#ifndef __DRAW_MODEL_H
#define __DRAW_MODEL_H

#include "BeatModel.h"
#include "AudioModel.h"

struct DrawModel {
    std::vector<BeatModel> beats;
    AudioModel audio;
};

#endif
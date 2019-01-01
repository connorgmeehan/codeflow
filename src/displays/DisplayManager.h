#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__


#include "ofMain.h"
#include "DrawModel.h"
#include "StateModel.h"

#include "AudioAnalyser.h"

#include "Channel.h"
#include "DEBUG/Debug.h"
#include "DEBUG/Test.h"

#include "UTILS/OrbitCamera.h"

#include "BRUTAL/FFTHistoryPlane.h"
#include "BRUTAL/PerlinOctopus.h"

class DisplayManager {
    public:
        DisplayManager(){ }
        DisplayManager(AudioAnalyser * pAudioAnalyser);

        void setup();
        void update(DrawModel & model);
    void draw(DrawModel & model);
    private:
        void setupChannels();
        std::vector<Channel*> mDrawQue;

        AudioAnalyser * mpAudioAnalyser;

        StateModel mStateModel;
};

#endif;
#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__


#include "ofMain.h"
#include "DrawModel.h"
#include "StateModel.h"

#include "AudioAnalyser.h"

#include "ofxTimeMeasurements.h"

#include "Channel.h"
#include "DEBUG/Debug.h"
#include "DEBUG/Test.h"

#include "UTILS/OrbitCamera.h"
#include "UTILS/ShaderContext.h"
#include "UTILS/ChannelSwitcher.h"
#include "UTILS/ContextSwitcher.h"
#include "UTILS/StyleContext.h"
#include "UTILS/TextureDrawer.h"
#include "UTILS/FboContext.h"
#include "UTILS/TextureShader.h"
#include "UTILS/ShaderBackground.h"

#include "BRUTAL/FFTHistoryPlane.h"
#include "BRUTAL/PerlinOctopus.h"
#include "BRUTAL/StepCamera.h"

#include "QUANTUM/VibratingContext.h"

class DisplayManager {
    public:
        DisplayManager(){ }
        DisplayManager(AudioAnalyser * pAudioAnalyser);
        ~DisplayManager();

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
#ifndef __ChannelSwitcher_H__
#define __ChannelSwitcher_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

#include "ModeManager.h"

enum SwitcherTrigger {
    SWITCHER_KICK,
    SWITCHER_SNARE,
    SWITCHER_HAT
};

class ChannelSwitcher : public Channel {
    public:
        ChannelSwitcher(SwitcherTrigger trigger, ModeManagerType mode, int interval = 0);
        std::string getName(){ return std::string("ChannelSwitcherChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void draw(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);

        ChannelSwitcher * addChannel(Channel * pChannel);
    private:
        void processBeat(float amp, float vel);
        std::vector<Channel*> mpChannels;
        ModeManager<int> mModeManager;
        SwitcherTrigger mTrigger;
};

#endif
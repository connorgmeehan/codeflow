#ifndef __ChannelSwitcher_H__
#define __ChannelSwitcher_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

enum SwitcherMode {
    CHANNEL_SWITCH_SHUFFLE,
    CHANNEL_SWITCH_CYCLE
};

enum SwitcherTrigger {
    CHANNEL_SWITCH_KICK,
    CHANNEL_SWITCH_SNARE,
    CHANNEL_SWITCH_HAT
};

class ChannelSwitcher : public Channel {
    public:
        ChannelSwitcher(SwitcherTrigger trigger, SwitcherMode mode);
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
        int mCurrentChannel;
        SwitcherTrigger mTrigger;
        SwitcherMode mMode;
};

#endif
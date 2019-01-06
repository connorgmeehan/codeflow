#include "ChannelSwitcher.h"

ChannelSwitcher::ChannelSwitcher(SwitcherTrigger trigger, ModeManagerType mode, int interval) :
    mTrigger(trigger) {
        mModeManager = ModeManager<int>(0, mode, interval);
}

void ChannelSwitcher::setup(){

}

void ChannelSwitcher::update(DrawModel & model, StateModel & state){
    mpChannels[mModeManager.getMode()]->update(model,state);
}

void ChannelSwitcher::draw(DrawModel & model, StateModel & state){
    mpChannels[mModeManager.getMode()]->draw(model,state);
}

void ChannelSwitcher::onKick(float amp, float vel){
    if(mTrigger = SWITCHER_KICK){ 
        processBeat(amp, vel);
    }
    mpChannels[mModeManager.getMode()]->onKick(amp,vel);
}

void ChannelSwitcher::onSnare(float amp, float vel){
    if(mTrigger = SWITCHER_SNARE){ 
        processBeat(amp, vel);
    }
    mpChannels[mModeManager.getMode()]->onKick(amp,vel);
}

void ChannelSwitcher::onHat(float amp, float vel){
    if(mTrigger = SWITCHER_HAT){ 
        processBeat(amp, vel);
    } 
    mpChannels[mModeManager.getMode()]->onKick(amp,vel);
}

ChannelSwitcher * ChannelSwitcher::addChannel(Channel * pChannel) {
    mpChannels.push_back(pChannel);
    mModeManager.setMaxMode(mpChannels.size());
    return this;
}

void ChannelSwitcher::processBeat(float amp, float vel) {
    mModeManager.updateMode();
}
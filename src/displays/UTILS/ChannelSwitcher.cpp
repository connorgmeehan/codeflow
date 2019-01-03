#include "ChannelSwitcher.h"

ChannelSwitcher::ChannelSwitcher(SwitcherTrigger trigger, SwitcherMode mode) :
    mMode(mode),
    mTrigger(trigger) {
}

void ChannelSwitcher::setup(){

}

void ChannelSwitcher::update(DrawModel & model, StateModel & state){
    mpChannels[mCurrentChannel]->update(model,state);
}

void ChannelSwitcher::draw(DrawModel & model, StateModel & state){
    mpChannels[mCurrentChannel]->draw(model,state);
}

void ChannelSwitcher::onKick(float amp, float vel){
    if(mTrigger = SWITCHER_KICK){ 
        processBeat(amp, vel);
    }
    mpChannels[mCurrentChannel]->onKick(amp,vel);
}

void ChannelSwitcher::onSnare(float amp, float vel){
    if(mTrigger = SWITCHER_SNARE){ 
        processBeat(amp, vel);
    }
    mpChannels[mCurrentChannel]->onKick(amp,vel);
}

void ChannelSwitcher::onHat(float amp, float vel){
    if(mTrigger = SWITCHER_HAT){ 
        processBeat(amp, vel);
    } 
    mpChannels[mCurrentChannel]->onKick(amp,vel);
}

ChannelSwitcher * ChannelSwitcher::addChannel(Channel * pChannel) {
    mpChannels.push_back(pChannel);
    mCurrentChannel = mpChannels.size()-1;
    return this;
}

void ChannelSwitcher::processBeat(float amp, float vel) {
    if (mMode == SWITCHER_CYCLE) {
        mCurrentChannel = (mCurrentChannel+1) % mpChannels.size();
    } else if(mMode == SWITCHER_SHUFFLE) {
        mCurrentChannel = (int) ofRandom(0, mpChannels.size());
    }
}
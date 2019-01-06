#include "ContextSwitcher.h"

ContextSwitcher::ContextSwitcher(SwitcherTrigger trigger, ModeManagerType mode, int interval) :
    mTrigger(trigger) {
        mModeManager = ModeManager<int>(0, mode, interval);
}

void ContextSwitcher::setup(){

}

void ContextSwitcher::update(DrawModel & model, StateModel & state){

}

void ContextSwitcher::begin(DrawModel & model, StateModel & state){
    mpContexts[mModeManager.getMode()]->begin(model,state);
}

void ContextSwitcher::end(DrawModel & model, StateModel & state){
    mpContexts[mModeManager.getMode()]->end(model,state);
}

void ContextSwitcher::onKick(float amp, float vel){
    if(mTrigger = SWITCHER_KICK){ 
        processBeat(amp, vel);
    }
    mpContexts[mModeManager.getMode()]->onKick(amp,vel);
}

void ContextSwitcher::onSnare(float amp, float vel){
    if(mTrigger = SWITCHER_SNARE){ 
        processBeat(amp, vel);
    }
    mpContexts[mModeManager.getMode()]->onKick(amp,vel);
}

void ContextSwitcher::onHat(float amp, float vel){
    if(mTrigger = SWITCHER_HAT){ 
        processBeat(amp, vel);
    } 
    mpContexts[mModeManager.getMode()]->onKick(amp,vel);
}

ContextSwitcher * ContextSwitcher::addContext(Context * pContext) {
    mpContexts.push_back(pContext);
    mModeManager.setMaxMode(mpContexts.size());
    return this;
}

void ContextSwitcher::processBeat(float amp, float vel) {
    mModeManager.updateMode();
}
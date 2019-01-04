#include "ContextSwitcher.h"

ContextSwitcher::ContextSwitcher(SwitcherTrigger trigger, SwitcherMode mode) :
    mMode(mode),
    mTrigger(trigger) {
}

void ContextSwitcher::setup(){

}

void ContextSwitcher::update(DrawModel & model, StateModel & state){

}

void ContextSwitcher::begin(DrawModel & model, StateModel & state){
    mpContexts[mCurrentContext]->begin(model,state);
}

void ContextSwitcher::end(DrawModel & model, StateModel & state){
    mpContexts[mCurrentContext]->end(model,state);
}

void ContextSwitcher::onKick(float amp, float vel){
    if(mTrigger = SWITCHER_KICK){ 
        processBeat(amp, vel);
    }
    mpContexts[mCurrentContext]->onKick(amp,vel);
}

void ContextSwitcher::onSnare(float amp, float vel){
    if(mTrigger = SWITCHER_SNARE){ 
        processBeat(amp, vel);
    }
    mpContexts[mCurrentContext]->onKick(amp,vel);
}

void ContextSwitcher::onHat(float amp, float vel){
    if(mTrigger = SWITCHER_HAT){ 
        processBeat(amp, vel);
    } 
    mpContexts[mCurrentContext]->onKick(amp,vel);
}

ContextSwitcher * ContextSwitcher::addContext(Context * pContext) {
    mpContexts.push_back(pContext);
    mCurrentContext = mpContexts.size()-1;
    return this;
}

void ContextSwitcher::processBeat(float amp, float vel) {
    if (mMode == SWITCHER_CYCLE) {
        mCurrentContext = (mCurrentContext+1) % mpContexts.size();
    } else if(mMode == SWITCHER_SHUFFLE) {
        mCurrentContext = (int) ofRandom(0, mpContexts.size());
    }
}
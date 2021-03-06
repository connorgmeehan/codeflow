#ifndef __ContextSwitcher_H__
#define __ContextSwitcher_H__

#include "ofMain.h"
#include "Context.h"
#include "DrawModel.h"
#include "ChannelSwitcher.h"
#include "ModeManager.h"

class ContextSwitcher : public Context {
    public:
        ContextSwitcher(SwitcherTrigger trigger, ModeManagerType mode, int interval = 0);
        std::string getName(){ return std::string("ContextSwitcherContext"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void begin(DrawModel & model, StateModel & state);
        void end(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);

        ContextSwitcher * addContext(Context * pContext);
    private:
        void processBeat(float amp, float vel);
        std::vector<Context*> mpContexts;
        SwitcherTrigger mTrigger;
        ModeManager<int> mModeManager;
};

#endif
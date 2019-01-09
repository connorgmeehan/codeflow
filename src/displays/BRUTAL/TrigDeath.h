#ifndef __TrigDeath_H__
#define __TrigDeath_H__

#include "ofMain.h"
#include "Channel.h"
#include "DrawModel.h"

class TrigDeath : public Channel {
    public:
        TrigDeath(int latitudeResolution, int longitudeResolution, float radius, float perlinMultiplier);
        std::string getName(){ return std::string("TrigDeathChannel"); }
        void setup();
        void update(DrawModel & model, StateModel & state);
        void draw(DrawModel & model, StateModel & state);

        void onKick(float amp, float vel);
        void onSnare(float amp, float vel);
        void onHat(float amp, float vel);
    private:
        int mLatitudeRes, mLongitudeRes;
        float mRadius, mPerlinMultiplier;
};

#endif
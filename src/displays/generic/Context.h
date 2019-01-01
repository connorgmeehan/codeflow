#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "ofMain.h"
#include "DrawModel.h"
#include "Channel.h"

/**
 * name: Context
 * desc: Allows user defined before and after 
 *       behaviours on channel draw buffers
 *       such as ofTranslate, ofShader, etc
 */

class Context : public Channel {
    public:
        virtual void setup() = 0;

        void draw(DrawModel & model) override {
            if(mActive) {
                end(model);
            } else {
                begin(model);
            }

            mActive = !mActive;
        }

        virtual void begin(DrawModel & model) = 0;
        virtual void end(DrawModel & model) = 0;

    private:
        bool mActive = false;
};

#endif
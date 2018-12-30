#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "ofMain.h"
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
        override void update(DrawModel & model) {

        }

        override void draw(DrawModel & model) {
            if(mActive) {
                end(DrawModel & model);
            } else {
                begin(DrawModel & model);
            }

            mActive = !mActive;
        }

        virtual void begin(DrawModel & model) = 0;
        virtual void end(DrawModel & model) = 0;

    private:
        bool mActive;
};
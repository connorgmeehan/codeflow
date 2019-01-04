#ifndef __MODE_MANAGER_H__
#define __MODE_MANAGER_H__

enum ModeManagerType {
    MODE_CYCLE,
    MODE_SHUFFLE
};

template <typename T>
class ModeManager {
    public:
        ModeManager() {}
        ModeManager(int maxMode, ModeManagerType type = MODE_CYCLE, int interval = 0) : mType(type), mInterval(interval), mMaxMode(maxMode) {
            mCurrentMode = static_cast<T>(0);
        }

        void setInterval(int interval) {
            mInterval = interval;
        }

        void updateMode() {
            mTick++;
            if(mTick > mInterval) {
                mTick = 0;
                changeMode();
            }
        }

        void setMaxMode(int max) { mMaxMode = max; }
        T getMode() { return mCurrentMode; }
    private:

        void changeMode() {
            if(mType == MODE_CYCLE) {
                mCurrentModeInt = (mCurrentModeInt + 1) % mMaxMode;
            } else {
                mCurrentModeInt = ofRandom(mMaxMode);
            }
            mCurrentMode = static_cast<T>(mCurrentModeInt);
        }

        T mCurrentMode;
        ModeManagerType mType;
        int mMaxMode, mCurrentModeInt;
        int mInterval, mTick = 0;
};

#endif
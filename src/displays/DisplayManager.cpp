#include "DisplayManager.h"

DisplayManager::DisplayManager(AudioAnalyser * pAudioAnalyser) :
    mpAudioAnalyser(pAudioAnalyser) {
    TIME_SAMPLE_SET_FRAMERATE(60.0f); 

    mStateModel.mResolution = glm::ivec2(1024, 768);
}

void DisplayManager::setup(){
    TS_START("setup");
    setupChannels();

    for(auto & drawable : mDrawQue) {
        drawable->setup();
    }
    TS_STOP("setup");
}

void DisplayManager::update(DrawModel & model){

    TS_START("update");

    mStateModel.mTime = ofGetElapsedTimef();

    if(model.beats.size() >= 1 && model.beats[0].mActive) {
        for(auto & drawable : mDrawQue) {
            drawable->onKick(model.beats[0].mAmp, model.beats[0].mVel);
        }
    }
    if(model.beats.size() >= 2 && model.beats[1].mActive) {
        for(auto & drawable : mDrawQue) {
            drawable->onSnare(model.beats[1].mAmp, model.beats[1].mVel);
        }
    }
    if(model.beats.size() >= 3 && model.beats[2].mActive) {
        for(auto & drawable : mDrawQue) {
            drawable->onHat(model.beats[2].mAmp, model.beats[2].mVel);
        }
    }

    for(auto & drawable : mDrawQue) {
        drawable->update(model, mStateModel);
    }

    TS_STOP("update");
}

void DisplayManager::draw(DrawModel & model){
    TS_START("draw");
    ofBackground(0);
    
    for(auto & drawable : mDrawQue) {
        drawable->draw(model, mStateModel);
    }
    TS_STOP("draw");
}

void DisplayManager::setupChannels() {
    StepCamera * cam = new StepCamera(0.001f, 0.005f, 400.0f, 1000.0f);
    mDrawQue.push_back(cam);

    StyleContext * white = new StyleContext(ofColor::white);
    mDrawQue.push_back(white);

    VibratingContext * vibratingContext = new VibratingContext(200, 1.0, 0.05);
    mDrawQue.push_back(vibratingContext);

    FFTHistoryPlane * fftHistory = new FFTHistoryPlane(200);

    PerlinOctopus * perlinOctopus = new PerlinOctopus(0.5f, 5.0f, 0.1f, 800.0f, 10);
    PerlinOctopus * shortPerlin = new PerlinOctopus(0.5f, 10.0f, 0.1f, 800.0f, 4);

    ChannelSwitcher * switcher = new ChannelSwitcher(SWITCHER_HAT, SWITCHER_CYCLE);
    switcher->addChannel(perlinOctopus)->addChannel(shortPerlin);
    mDrawQue.push_back(fftHistory);
    mDrawQue.push_back(switcher);

    mDrawQue.push_back(vibratingContext);

    mDrawQue.push_back(white);

    mDrawQue.push_back(cam);

    // Debug * debug = new Debug();
    // mDrawQue.push_back(debug);
}

DisplayManager::~DisplayManager() {
    // Remove duplicates so we dont de-alloc the same memory twice
    std::sort( mDrawQue.begin(), mDrawQue.end() );
    mDrawQue.erase( std::unique( mDrawQue.begin(), mDrawQue.end() ), mDrawQue.end() );

    // De-alloc them all
    for(Channel * drawObject : mDrawQue) {
        delete drawObject;
    }
}
#include "DisplayManager.h"

DisplayManager::DisplayManager(AudioAnalyser * pAudioAnalyser) :
    mpAudioAnalyser(pAudioAnalyser) {
    TIME_SAMPLE_SET_FRAMERATE(60.0f); 

    mStateModel.mResolution = glm::vec2(1024, 768);
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
    glPointSize(3.0f);
    ofBackground(0);
    
    for(auto & drawable : mDrawQue) {
        drawable->draw(model, mStateModel);
    }
    TS_STOP("draw");
}

void DisplayManager::setupChannels() {
    StepCamera * cam = new StepCamera(0.001f, 0.005f, 400.0f, 1000.0f);


    // Background
    FboContext * fboContext = new FboContext();
    mDrawQue.push_back(fboContext);
        
        ChannelSwitcher * backgroundSwitcher = new ChannelSwitcher(SWITCHER_KICK, MODE_SHUFFLE, 128);
        backgroundSwitcher
            ->addChannel(new ShaderBackground("shaders/quantum/refract_1"))
            ->addChannel(new ShaderBackground("shaders/quantum/refract_2"))
            ->addChannel(new ShaderBackground("shaders/quantum/refract_3"))
            ->addChannel(new ShaderBackground("shaders/quantum/refract_4"))
            ->addChannel(new ShaderBackground("shaders/quantum/refract_5"));
        mDrawQue.push_back(backgroundSwitcher);

    mDrawQue.push_back(fboContext);
    mDrawQue.push_back(new TextureDrawer(fboContext));

    // Foreground
    VibratingContext * vibrating = new VibratingContext(400, 1.0);
    TextureShader * inverseShader = new TextureShader("shaders/utils/inverse", fboContext);
    mDrawQue.push_back(inverseShader);
        mDrawQue.push_back(cam);
            mDrawQue.push_back(vibrating);

                FFTHistoryPlane * fftHistory = new FFTHistoryPlane(100);
                SpikedBall * spikyball = new SpikedBall(500,20);
                PerlinOctopus * perlinOctopus = new PerlinOctopus(0.5f, 5.0f, 0.1f, 800.0f, 10);
                PerlinOctopus * shortPerlin = new PerlinOctopus(0.5f, 10.0f, 0.1f, 800.0f, 4);


                ChannelSwitcher * switcher1 = new ChannelSwitcher(SWITCHER_HAT, MODE_SHUFFLE, 8);
                switcher1
                    ->addChannel(perlinOctopus)
                    ->addChannel(shortPerlin)
                    ->addChannel(fftHistory)
                    ->addChannel(spikyball);
                mDrawQue.push_back(switcher1);

                ChannelSwitcher * switcher2 = new ChannelSwitcher(SWITCHER_HAT, MODE_SHUFFLE, 8);
                switcher2
                    ->addChannel(perlinOctopus)
                    ->addChannel(shortPerlin)
                    ->addChannel(fftHistory)
                    ->addChannel(spikyball);
                // mDrawQue.push_back(switcher);
                // mDrawQue.push_back(fftHistory);
                mDrawQue.push_back(switcher2);
                    
            mDrawQue.push_back(vibrating);
        mDrawQue.push_back(cam);
    mDrawQue.push_back(inverseShader);


    

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
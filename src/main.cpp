#include "ofMain.h"
#include "CodeFlow.h"

//========================================================================
int main( int argc, char** argv[] ){

	ofGLFWWindowSettings settings;
	settings.setSize(1024, 768);
	settings.setPosition(ofVec2f(0,0));
	settings.resizable = true;
	settings.setGLVersion(3,0);
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	shared_ptr<CodeFlowApp> mainApp(new CodeFlowApp);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}

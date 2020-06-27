#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class Gui {
public:
	Gui();
	void draw();
	void toggle();

	ofxPanel gui;
	ofxFloatSlider test;
	bool show;
};


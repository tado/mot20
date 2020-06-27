#include "Title.h"

Title::Title() {
	titleImg.load("title.png");
	titleImg.resize(titleImg.getWidth() / 2.0, titleImg.getHeight() / 2.0);
	titleLevel = 0.0;
}

void Title::draw() {
	if (ofGetElapsedTimef() < 4.0) {
		titleLevel += 1.0 / 60.0;
		if (titleLevel > 1.0) {
			titleLevel = 1.0;
		}
	}
	if (ofGetElapsedTimef() > 4.0) {
		titleLevel -= 1.0 / 60.0;
		if (titleLevel < 0.0) {
			titleLevel = 0.0;
		}
	}

	ofSetColor(255 * titleLevel);
	titleImg.draw(ofGetWidth() / 2 - titleImg.getWidth() / 2, ofGetHeight() / 2 - titleImg.getHeight()/2);
}
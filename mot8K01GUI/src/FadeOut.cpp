#include "FadeOut.h"
#include "ofApp.h"

FadeOut::FadeOut() {
	fadeOutTime = 120;
	credit.load("credit.png");
#ifdef SHOW8K

#else
	credit.resize(credit.getWidth() / 2.0, credit.getHeight() / 2.0);
#endif
}

void FadeOut::draw() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	if (ofGetElapsedTimef() > fadeOutTime / 5.0 * 4.0) {
		float vol = ofMap(ofGetElapsedTimef(), fadeOutTime / 5.0 * 4.0, fadeOutTime, 1.0, 0.0);
		app->sound->sound.setVolume(vol);
	}
	if (ofGetElapsedTimef() > fadeOutTime) {
		ofSetColor(0);
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		app->sound->sound.setVolume(app->sound->sound.getVolume() / 2.0);
		if (ofGetElapsedTimef() > fadeOutTime + 2 && ofGetElapsedTimef() < fadeOutTime + 4) {
			ofSetColor(255);
			credit.draw(ofGetWidth() / 2.0 - credit.getWidth() / 2.0, ofGetHeight() / 2.0 - credit.getHeight() / 2.0);
		}
	}
}
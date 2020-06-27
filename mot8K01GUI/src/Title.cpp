#include "Title.h"

Title::Title() {
	titleImg.load("title.png");
	titleImg.resize(titleImg.getWidth() / 2.0, titleImg.getHeight() / 2.0);
}

void Title::draw() {
	ofSetColor(255);
	titleImg.draw(ofGetWidth() / 2 - titleImg.getWidth() / 2, ofGetHeight() / 2 - titleImg.getHeight()/2);
}
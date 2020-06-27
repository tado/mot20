#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofToggleFullscreen();
	//ofSetWindowShape(3840 * 2, 2160 * 2); //8K
	ofSetWindowShape(3840, 2160); //4K
	ofSetWindowPosition(0, 0);
	int div = 35;
	dotMatrix = new DotMatrix(glm::vec2(div, int(div / 1.6)));
	gui = new Gui();
	title = new Title();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	dotMatrix->draw();
	title->draw();
	gui->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 't') {
		gui->toggle();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

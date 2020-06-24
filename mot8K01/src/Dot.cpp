#include "Dot.h"

Dot::Dot(glm::vec2 _center) {
	center = _center;
}

void Dot::update() {
	color.r = ofNoise(center.x / ofGetWidth() * 2.0, center.y / ofGetWidth() * 2.0, ofGetElapsedTimef() * 0.1) * 255;
	color.g = ofNoise(center.x / ofGetWidth() * 2.0, center.y / ofGetWidth() * 2.0, ofGetElapsedTimef() * 0.11) * 255;
	color.b = ofNoise(center.x / ofGetWidth() * 2.0, center.y / ofGetWidth() * 2.0, ofGetElapsedTimef() * 0.12) * 255;
	color.a = ofNoise(center.x / ofGetWidth() * 1.0, center.y / ofGetWidth() * 1.0, ofGetElapsedTimef() * 0.13) * 255;
}

void Dot::draw() {
	float r = ofGetWidth() / 900.0;
	ofSetCircleResolution(64);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofPushMatrix();
	ofTranslate(center.x, center.y);
	ofSetColor(255, 0, 0);
	float rrad = ofMap(color.r, 0, 255, 0, r);
	ofDrawCircle(0, -r/3.0, rrad);
	ofRotateDeg(120);
	ofSetColor(0, 255, 0);
	float grad = ofMap(color.g, 0, 255, 0, r);
	ofDrawCircle(0, -r/3.0, rrad);
	ofRotateDeg(120);
	ofSetColor(0, 0, 255);
	float brad = ofMap(color.b, 0, 255, 0, r);
	ofDrawCircle(0, -r/3.0, brad);
	ofPopMatrix();
}
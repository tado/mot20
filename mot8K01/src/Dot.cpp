#include "Dot.h"

Dot::Dot(glm::vec2 _center) {
	center = _center;
	globalLevel = 0.0;
}

void Dot::update() {
	float div = 200.0 / ofGetElapsedTimef() + 2.0;
	float speed = 20000.0 / ofGetElapsedTimef() * 0.1 + 0.5;
	float shiftX = -ofGetElapsedTimef() * 0.1;
	float shiftY = ofGetElapsedTimef() * 0.5;
	color.r = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, ofGetElapsedTimef() * speed) * 255;
	color.g = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, ofGetElapsedTimef() * speed + 0.1) * 255;
	color.b = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, ofGetElapsedTimef() * speed + 0.2) * 255;
	//color.a = ofNoise(center.x / ofGetWidth() * 1.0, center.y / ofGetWidth() * 1.0, ofGetElapsedTimef() * 0.13) * 255;

	globalLevel += 1.0 / 240.0;
	if (globalLevel > 1.0) {
		globalLevel = 1.0;
	}
}

void Dot::draw() {
	int baseColor = 0;
	float r = ofGetWidth() / 800.0;
	float shift = -r / 3.0;
	ofSetCircleResolution(64);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofPushMatrix();
	//float shiftLoc = color.getBrightness() / 255.0 * (ofGetElapsedTimef() / 80.0);
	float shiftLoc = 0;
	if (shiftLoc > 16.0) {
		shiftLoc = 16.0;
	}
	ofTranslate(center.x + shiftLoc, center.y);
	ofSetColor(255, baseColor, baseColor);
	float rrad = ofMap(color.r, 0, 255, 0, r * globalLevel);
	ofDrawCircle(0, shift, rrad);

	ofRotateDeg(120);
	ofSetColor(baseColor, 255, baseColor);
	float grad = ofMap(color.g, 0, 255, 0, r * globalLevel);
	ofDrawCircle(0, shift, grad);

	ofRotateDeg(120);
	ofSetColor(baseColor, baseColor, 255);
	float brad = ofMap(color.b, 0, 255, 0, r * globalLevel);
	ofDrawCircle(0, shift, brad);
	ofPopMatrix();
}
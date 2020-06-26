#include "Dot.h"

Dot::Dot(glm::vec2 _center) {
	center = _center;
	globalLevel = 0.0;
	shiftLevel = 0.0;
}

void Dot::update() {
	float div = 120.0 / ofGetElapsedTimef() + 1.0;
	float speed = 60.0 / ofGetElapsedTimef() + 0.5;
	float shiftX = -ofGetElapsedTimef() * 0.2;
	float shiftY = ofGetElapsedTimef() * 0.5;
	color.r = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, ofGetElapsedTimef() * speed) * 255;
	color.g = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, ofGetElapsedTimef() * speed + 0.12) * 255;
	color.b = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, ofGetElapsedTimef() * speed + 0.24) * 255;

	globalLevel += 1.0 / 600.0;
	if (globalLevel > 1.0) {
		globalLevel = 1.0;
	}
	shiftLevel += 1.0 / 1200.0;
	if (shiftLevel > 1.0) {
		shiftLevel = 1.0;
	}
}

void Dot::draw() {
	int baseColor = 0;
	float r = ofGetWidth() / 400.0;
	float shift = -r / 2.5;
	ofSetCircleResolution(64);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofPushMatrix();
	float shiftLoc = color.getBrightness() / 255.0 * 6.0 * shiftLevel;
	ofTranslate(center.x + shiftLoc, center.y);
	ofScale(globalLevel, globalLevel);
	ofSetColor(255, baseColor, baseColor);
	float rrad = ofMap(color.r, 0, 255, 0, r);
	ofDrawCircle(0, shift, rrad);

	ofRotateDeg(120);
	ofSetColor(baseColor, 255, baseColor);
	float grad = ofMap(color.g, 0, 255, 0, r);
	ofDrawCircle(0, shift, grad);

	ofRotateDeg(120);
	ofSetColor(baseColor, baseColor, 255);
	float brad = ofMap(color.b, 0, 255, 0, r);
	ofDrawCircle(0, shift, brad);
	ofPopMatrix();
}
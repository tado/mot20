#include "Dot.h"
#include "ofApp.h"

Dot::Dot(glm::vec2 _center) {
	center = _center;
	globalLevel = 0.0;
	shiftLevel = 0.0;
}

void Dot::update() {
	ofApp* app = ((ofApp*)ofGetAppPtr());
	//float div = 480.0 / ofGetElapsedTimef() + 1.0;
	//float speed = 240.0 / ofGetElapsedTimef() + 0.5;
	
	float div;
	if (ofGetElapsedTimef() < app->fadeOut->fadeOutTime * 0.5) {
		div = ofMap(ofGetElapsedTimef(), 0, app->fadeOut->fadeOutTime * 0.5, 20.0, 2.0);
	}
	else {
		div = ofMap(ofGetElapsedTimef(), app->fadeOut->fadeOutTime * 0.5, app->fadeOut->fadeOutTime, 2.0, 16.0);
		if (div > 4.0) {
			div = 4.0;
		}
	}
	float speed = (ofMap(ofGetElapsedTimef(), 0, app->fadeOut->fadeOutTime * 1.0, 8.0, 0.0) + 1.0) * ofGetElapsedTimef();

	float shiftX = -ofGetElapsedTimef() * 0.2;
	float shiftY = ofGetElapsedTimef() * 0.5;
	color.r = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, speed) * 255;
	color.g = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, speed + 0.15) * 255;
	color.b = ofNoise(center.x / ofGetWidth() * div + shiftX, center.y / ofGetWidth() * div + shiftY, speed + 0.3) * 255;

	if (ofGetElapsedTimef() > 6.0) {
		if (ofGetElapsedTimef() < app->fadeOut->fadeOutTime / 5.0 * 4.0) {
			globalLevel += 1.0 / 3600.0;
			if (globalLevel > 1.0) {
				globalLevel = 1.0;
			}
			/*globalLevel = ofMap(ofGetElapsedTimef(), 0, app->fadeOut->fadeOutTime / 3.0 * 1.0, 0.0, 1.0);*/
			shiftLevel = ofMap(ofGetElapsedTimef(), 0, app->fadeOut->fadeOutTime / 5.0 * 4.0, 0.0, 1.0);
		}
		else {
			globalLevel = ofMap(ofGetElapsedTimef(), app->fadeOut->fadeOutTime / 5.0 * 4.0, app->fadeOut->fadeOutTime, 1.0, 0.0);
			shiftLevel = ofMap(ofGetElapsedTimef(), app->fadeOut->fadeOutTime / 5.0 * 4.0, app->fadeOut->fadeOutTime, 1.0, 0.0);
		}
		/*
		shiftLevel += 1.0 / 4800.0;
		if (shiftLevel > 1.0) {
			shiftLevel = 1.0;
		}
		*/
	}
}

void Dot::draw() {
	int baseColor = 0;
	float r = ofGetWidth() / 320.0;
	float shift = -r / 2.0;
	ofSetCircleResolution(64);
	ofPushMatrix();
	//float shiftLoc = color.getBrightness() / 255.0 * (ofGetWidth() / 200.0) * shiftLevel;
	float shiftLoc = ofMap(color.getBrightness(), 0, 255, -(ofGetWidth() / 1000.0) * shiftLevel, (ofGetWidth() / 1000.0) * shiftLevel);
	ofTranslate(center.x + shiftLoc, center.y);
	//ofTranslate(center.x, center.y);
	//float rotate = color.getBrightness() / 255.0 * 180.0 * shiftLevel;
	//ofRotateZDeg(rotate);
	
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
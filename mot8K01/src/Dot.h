#pragma once
#include "ofMain.h"

class Dot
{
public:
	Dot(glm::vec2 center);
	void update();
	void draw();

	glm::vec2 center;
	ofColor color;
};


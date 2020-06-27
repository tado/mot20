#pragma once
#include "ofMain.h"
#include "Dot.h"

class DotMatrix
{
public:
	DotMatrix(glm::vec2 div);
	void draw();

	glm::vec2 div;
	glm::vec2 span;
	vector<Dot*> dots;
};


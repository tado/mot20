#include "DotMatrix.h"

DotMatrix::DotMatrix(glm::vec2 _div) {
	float margin = ofGetWidth() / 64.0;
	float screenWidth = ofGetWidth() - margin * 2;
	float screenHeight = ofGetHeight() - margin * 2;
	div = _div;
	span = glm::vec2(screenWidth / div.x, screenHeight / div.y);
	for (int j = 0; j < div.y; j++) {
		for (int i = 0; i < div.x; i++) {
			Dot *d = new Dot(glm::vec2(span.x * i + span.x / 2.0 + margin, span.y * j + span.y / 2.0 + margin));
			dots.push_back(d);
		}
	}
}

void DotMatrix::draw() {
	for (int i = 0; i < dots.size(); i++) {
		dots[i]->update();
		dots[i]->draw();
	}
}
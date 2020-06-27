#include "Gui.h"

Gui::Gui() {
	gui.setup("Setttings");
	gui.setPosition(40, 80);
	gui.add(test.setup("Test", 50, 0, 100));
	show = false;
	ofHideCursor();
}

void Gui::draw() {
	if (show) {
		ofSetColor(255);
		gui.draw();
	}
}

void Gui::toggle() {
	if (show) {
		show = false;
		ofHideCursor();
	}
	else {
		show = true;
		ofShowCursor();
	}
}
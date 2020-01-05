#include "FlowField.h"

void FlowField::setup(int resolution) {
	m_resolution = resolution;
	cols = ofGetWidth() / m_resolution;
	rows = ofGetHeight() / m_resolution;

	field.resize(cols);
	for (int i = 0; i < cols; i++) {
		field[i].resize(rows);
	}

	//seed noise so we get a new flow field every time
	//processing: noiseSeed((int)random(10000));
	float xoff_seed = ofRandom(0, 1);
	float yoff_seed = ofRandom(0, 1);
	float xoff = xoff_seed;
	for (int i = 0; i < cols; i++) {
		float yoff = yoff_seed;
		for (int j = 0; j < rows; j++) {
			float theta = ofMap(ofNoise(xoff, yoff), 0, 1, 0, TWO_PI);
			// Polar to cartesian coordinate transformation to get x and y components of the vector
			field[i][j].set(cos(theta), sin(theta));
			yoff += 0.03;
		}
		xoff += 0.03;
	}
}


void FlowField::draw() {
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			drawVector(field[i][j], i * m_resolution, j * m_resolution, m_resolution - 2);
		}
	}
}


void FlowField::drawVector(const ofVec2f & v, float x, float y, float scale) {

	ofSetColor(ofColor::forestGreen, 127);
	ofPushMatrix();
	float arrowsize = 4;
	ofTranslate(x, y);
	ofRotate(ofVec2f(1, 0).angle(v));
	float len = v.length() * scale;
	// Draw three lines to make an arrow (draw pointing up since we've to rotate it in proper direction)
	ofDrawLine(0, 0, len, 0);
	ofDrawLine(len, 0, len - arrowsize, arrowsize / 2);
	ofDrawLine(len, 0, len - arrowsize, -arrowsize / 2);
	ofPopMatrix();
}

ofVec2f FlowField::lookup(const ofVec2f & lookup) const {
	int column = int(ofClamp(lookup.x / m_resolution, 0, cols - 1));
	int row = int(ofClamp(lookup.y / m_resolution, 0, rows - 1));
	return field[column][row];
}


#pragma once
#include "ofMain.h"

class FlowField {

public:
	void setup(int resolution);
	void draw();
	void drawVector(const ofVec2f & v, float x, float y, float scale);
	ofVec2f lookup(const ofVec2f & lookup) const;

private:
	vector<vector<ofVec2f>> field;
	int cols, rows;
	int m_resolution;
};


#pragma once

#include "ofMain.h"

class Vehicle {

public:
	
	void setup(int x, int y);
	void applyForce(const ofVec2f & force);
	void seek(const ofVec2f & target);
	void arrive(const ofVec2f & target);
	void update();
	void draw();


private:
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float maxSpeed;
	float maxForce;
	int offset;
	vector <ofVec2f> history;
};
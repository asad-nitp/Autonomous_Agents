#pragma once

#include "ofMain.h"
#include "FlowField.h"

class Vehicle {
public:
	Vehicle(ofVec2f & l, float ts, float mf);
	void applyForce(const ofVec2f & force);
	void borders();
	void update();
	void draw();
	void follow(const FlowField & flow);

private:
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;

	float maxSpeed;
	float maxForce;
	int offset;

};
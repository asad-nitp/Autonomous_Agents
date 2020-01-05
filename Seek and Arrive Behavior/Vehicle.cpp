#include "vehicle.h"

void Vehicle::setup(int x, int y) {

	location.set(0, 0);
	velocity.set(0, -2);
	acceleration.set(x, y);

	offset = 6;
	maxForce = 0.1;
	maxSpeed = 4;

}

void Vehicle::applyForce(const ofVec2f & force) {
	acceleration += force;
}

void Vehicle::seek(const ofVec2f & target) {
	ofVec2f desired;
	desired = target - location;

	desired.normalize();
	desired *= maxSpeed;

	ofVec2f steer;
	steer = desired - velocity;
	steer.limit(maxForce);

	applyForce(steer);

}

void Vehicle::arrive(const ofVec2f & target) {
	ofVec2f desired = target - location;

	float d = desired.length();
	desired.normalize();
	if (d < 100) {
		float m = ofMap(d, 0, 100, 0, maxSpeed);
		desired *= m;

	}
	else {
		desired *= maxSpeed;
	}

	ofPoint steer = desired - velocity;
	steer.limit(maxForce);
	applyForce(steer);
}

void Vehicle::update() {
	velocity += acceleration;
	velocity.limit(maxSpeed);
	location += velocity;
	acceleration *= 0;

	history.push_back(location);
	if (history.size() > 100) {
		history.erase(history.begin());
	}

}

void Vehicle::draw() {

	ofSetColor(ofColor::fireBrick);
	for (int i = 1; i < history.size(); i++) {
		ofDrawLine(history[i - 1].x, history[i - 1].y, history[i].x, history[i].y);
	}

	float angle = ofRadToDeg(atan2(velocity.y, velocity.x)) + 90;
	ofPushMatrix();
	ofTranslate(location.x, location.y);
	ofRotate(angle);

	ofBeginShape();
	ofVertex(0, -offset * 2);
	ofVertex(-offset, offset * 2);
	ofVertex(offset, offset * 2);
	ofEndShape();
	ofPopMatrix();



}
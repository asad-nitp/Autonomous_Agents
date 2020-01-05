#include "Vehicle.h"

Vehicle::Vehicle(ofVec2f & loc, float speed, float force) {
	acceleration.set(0.0, 0.0);
	velocity.set(0.0, 0.0);
	location = loc;

	offset = 4;
	maxForce = force;
	maxSpeed = speed;

}

void Vehicle::applyForce(const ofVec2f & force) {
	ofVec2f f(force);
	acceleration += f;
}

void Vehicle::borders() {

	if (location.x < -offset) location.x = ofGetWidth() + offset;
	if (location.y < -offset) location.y = ofGetHeight() + offset;
	if (location.x > ofGetWidth() + offset) location.x = -offset;
	if (location.y > ofGetHeight() + offset) location.y = -offset;

}

void Vehicle::follow(const FlowField & flow) {

	//the vector at that spot in the flow field?
	ofVec2f desired = flow.lookup(location);
	// Scale it up by maxspeed
	desired *= maxSpeed;
	// Steering is desired minus velocity
	ofVec2f steer = desired - velocity;
	steer.limit(maxForce);  // Limit to maximum steering force
	applyForce(steer);
}


void Vehicle::update() {
	velocity += acceleration;
	location += velocity;
	velocity.limit(maxSpeed);
	acceleration *= 0;

}

void Vehicle::draw() {

	ofSetColor(ofColor::red, 127);
	float angle = ofRadToDeg(atan2(velocity.y, velocity.x)) + 90;
	ofFill();
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

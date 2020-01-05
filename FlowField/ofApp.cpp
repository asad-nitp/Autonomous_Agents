#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofEnableSmoothing();
	ofBackground(255);

	flowfield.setup(25);

	for (int i = 0; i < 100; i++) {
		ofVec2f location(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
		vehicles.emplace_back(location, ofRandom(2, 5), ofRandom(0.01, 0.3));
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (auto & vehicle : vehicles) {
		vehicle.follow(flowfield);
		vehicle.update();
		vehicle.borders();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (auto & vehicle : vehicles) {
		vehicle.draw();
	}

	if (isDebugMode) {
		flowfield.draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'd') {
		isDebugMode = !isDebugMode;
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

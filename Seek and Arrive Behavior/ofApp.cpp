#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(ofColor::beige);
	ofEnableSmoothing();
	vehicle.setup(ofGetWidth() / 2, ofGetHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::update() {
	//vehicle.seek(ofVec2f(mouseX, mouseY));
	vehicle.arrive(ofVec2f(mouseX, mouseY));
	vehicle.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	vehicle.draw();
	ofSetColor(ofColor::dodgerBlue, 127);
	ofDrawCircle(mouseX, mouseY, 24);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

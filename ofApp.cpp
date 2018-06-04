#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetLineWidth(1.5);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	for (int x = -1; x <= 1; x++) {

		for (int y = -1; y <= 1; y++) {

			ofPoint location(x * 240, y * 240);
			float radius = 15;

			ofBeginShape();
			for (int deg = 0; deg < 360 * 10; deg++) {

				ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)) + location;
				int noise_value = ofNoise(point.x * 0.003, point.y * 0.003, ofGetFrameNum() * 0.005) * 10 - 5;
				noise_value *= 5;
				point = ofPoint((radius + noise_value) * cos(deg * DEG_TO_RAD), (radius + noise_value) * sin(deg * DEG_TO_RAD)) + location;

				ofVertex(point);
				radius += 0.02;
			}
			ofEndShape();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
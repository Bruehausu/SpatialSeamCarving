#pragma once

#include "ofMain.h"
#include "ofxSeamCarver.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        bool arrayHasXY(ofVec2f** arr, int w, int h,int x, int y);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofImage img1, img2, img3, img4;
    
        ofxSeamCarver seamCarver1, seamCarver2;
    
};

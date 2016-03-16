#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*img1.load("dog.png");
    img2.load("dog.png");
    //img3.load("dog.png");
    seamCarver1.setup(img1.getWidth(), img1.getHeight(), img1.getImageType(), img1);
    //seamCarver2.setup(img2.getWidth(), img2.getHeight(), img2.getImageType());
    
    cout << "beggining carve" << endl;
    for(int i = 0; i < ((img2.getWidth() + img2.getHeight()) / 6); i++){
        img1.setFromPixels(seamCarver1.seamCarve(true,true));
    }
    cout << "carve ended" << endl;
    
    ofVec2f** pixelHomes = seamCarver1.getRemainingPixelHomes();
    
    ofPixels pixels = img2.getPixels();
    for(int i = 0; i < img1.getWidth(); i++){
        for(int j = 0; j < img1.getHeight(); j++){
            pixels.setColor(pixelHomes[i][j].x, pixelHomes[i][j].y,
                            ofColor(0,0,0));
        }
    }
    img2.setFromPixels(pixels);*/
    
    int frame_count = 19247;
    int times_to_carve = 165;
    
    for(int i = 776; i <= frame_count; i++){
        string num = ofToString(i);
        string filename = "image_sequence";
        if (i < 10){
            filename = filename + "000000" + num + ".png";
        } else if (i < 100){
            filename = filename + "00000" + num + ".png";
        } else if (i < 1000){
            filename = filename + "0000" + num + ".png";
        } else if (i < 10000){
            filename = filename + "000" + num + ".png";
        } else if (i < 100000){
            filename = filename + "00" + num + ".png";
        } else {
            filename = filename + num + ".png";
        }
        cout << "processing frame " << filename << endl;
        
        img1.load("in/" + filename);
        img2.load("in/" + filename);
        img3.load("in/" + filename);
        img4.load("in/" + filename);

        seamCarver1.setup(img1.getWidth(), img1.getHeight(), img1.getImageType(), img1);
        for(int i = 0; i < times_to_carve; i++){
            seamCarver1.seamCarve(true,true);
        }
        
        img1.setFromPixels(seamCarver1.getPixels());
        
        ofVec2f** pixelHomes = seamCarver1.getRemainingPixelHomes();
        
        ofPixels pixels = img2.getPixels();
        for(int i = 0; i < img1.getWidth(); i++){
            for(int j = 0; j < img1.getHeight(); j++){
                pixels.setColor(pixelHomes[i][j].x, pixelHomes[i][j].y,
                                ofColor(0,0,0));
            }
        }
        
        img2.clear();
        img2.setFromPixels(pixels);
    
        
        img2.save("out/" + filename);
        
        
        ofPixels pixels2 = img4.getPixels();
        for(int i = 0; i < img4.getWidth(); i++){
            for(int j = 0; j < img4.getHeight(); j++){
                pixels2.setColor(i, j, ofColor(0,0,0));
            }
        }
        for(int i = 0; i < img1.getWidth(); i++){
            for(int j = 0; j < img1.getHeight(); j++){
                pixels2.setColor(pixelHomes[i][j].x, pixelHomes[i][j].y,
                                img1.getColor(i, j));
            }
            //free(pixelHomes[i]);
        }
        
        
        for(int i = 0; i < img1.getWidth(); i++){
            for(int j = 0; j < img1.getHeight(); j++){
                int x = pixelHomes[i][j].x;
                int y = pixelHomes[i][j].y;
                ofColor c;
                if (x > 0){
                    c = pixels.getColor(x -1, y);
                } else if (y > 0){
                    c = pixels.getColor(x, y - 1);
                } else {
                    c = pixels.getColor(x, y + 1);
                }
                int r = c.r > 4 ? c.r + roundtol(ofRandom(-4, 4)) % 256:
                                c.r + roundtol(ofRandom(0, 4)) % 256;
                int g = c.g > 4 ? c.g + roundtol(ofRandom(-4, 4)) % 256:
                                c.g + roundtol(ofRandom(0, 4)) % 256;
                int b = c.b > 4 ? c.b + roundtol(ofRandom(-4, 4)) % 256:
                                c.b + roundtol(ofRandom(0, 4)) % 256;
                
                pixels.setColor(x, y, ofColor(r,g,b));
                
            }
            //free(pixelHomes[i]);
        }
        
        img2.clear();
        img2.setFromPixels(pixels);
        
        
        img2.save("out-filled/" + filename);
        
        img4.clear();
        img4.setFromPixels(pixels2);
        
        pixels.clear();
        pixels2.clear();
        img4.save("out-foc/" + filename);
        
        
        img1.clear();
        img2.clear();
        seamCarver1.clear();
        
        //free(pixelHomes);
    }
    
    img1.load("dog.png");
    img2.load("dog.png");
    
}

bool ofApp::arrayHasXY(ofVec2f** arr, int w, int h,int x, int y){
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if ((arr[i][j].x) == x && (arr[i][j].y == y)){
                return true;
            }
        }
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::update(){
    //img1.setFromPixels(seamCarver1.seamCarve(true,true));
}

//--------------------------------------------------------------
void ofApp::draw(){
    img1.draw(0,0);
    img2.draw(ofGetWidth()/2, 0);
    
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

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    cam.initGrabber(640, 480);
    recording = false;
         
    recorder.setPrefix(ofToDataPath("recording1/frame_")); // this directory must already exist
    recorder.setFormat("jpg"); // png is really slow but high res, bmp is fast but big, jpg is just right
}

//--------------------------------------------------------------
void testApp::update(){
    cam.grabFrame();
	
	if (cam.isFrameNew() && recording){
        recorder.addFrame(cam);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(125);
    cam.draw(0,0);
    
    ofSetColor(255);
    
    stringstream c;
    c << "Recording: " << recording << "\nThread running: " << recorder.isThreadRunning() <<  "\nQueue Size: " << recorder.q.size() << "\n\nPress 'r' to toggle recording.\nPress 't' to toggle worker thread." << endl;
    
    ofDrawBitmapString(c.str(), 650, 10);
}

void testApp::exit(){
    recorder.waitForThread();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'r'){
        recording = !recording;
    }
    
    if(key == 't'){
        if(recorder.isThreadRunning()){
            recorder.stopThread();
        } else {
            recorder.startThread(false, true);   
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
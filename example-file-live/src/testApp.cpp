#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    ofBackground(0);
    
    cam.setNearClip(1e-2);
    cam.setFarClip(1e4);
    cam.setDistance(80);
    cam.lookAt(ofVec3f(0, 20, 0));
    
    selected = 0;
    dir.listDir("");
    dir.sort();
    for (unsigned i = 0; i < dir.size(); ++i)
    {
        fileNames.push_back(dir.getName(i));
    }
}

//--------------------------------------------------------------
void testApp::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
    
    generator.step();
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofSetColor(255, 255, 255);
    cam.begin();
    generator.draw();
    cam.end();
    
    for (unsigned i = 0; i < fileNames.size(); ++i)
    {
        if (i == selected) ofSetColor(0, 255, 0);
        else ofSetColor(255, 0, 0);
        ofDrawBitmapString(fileNames[i], 10, 20 * (i + 1));
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key)
    {
        case OF_KEY_RETURN:
            generator.watchFile(fileNames[selected]);
            break;
        
        case OF_KEY_UP:
            selected = (selected - 1);
            if (selected < 0) selected = fileNames.size() - 1;
            break;
        
        case OF_KEY_DOWN:
            selected = (selected + 1) % fileNames.size();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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
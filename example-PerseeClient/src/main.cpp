// OF
#include "ofMain.h"
// addons
#include "ofxOrbbecPersee/ofxOrbbecPersee.h"
// local

class ofApp : public ofBaseApp{

  public: // methods
    void setup() override;
    void update() override;
    void draw() override;

    // void keyPressed(int key);
    // void keyReleased(int key);
    // void mouseMoved(int x, int y );
    // void mouseDragged(int x, int y, int button);
    // void mousePressed(int x, int y, int button);
    // void mouseReleased(int x, int y, int button);
    // void mouseEntered(int x, int y);
    // void mouseExited(int x, int y);
    // void windowResized(int w, int h);
    // void dragEvent(ofDragInfo dragInfo);
    // void gotMessage(ofMessage msg);

  private: // attributes
    std::string perseeHost = "127.0.0.1"; //"192.168.1.172";
    ofxOrbbecPersee::Client client;
    ofxOrbbecPersee::DepthStreamRef depthStreamRef;
    ofxOrbbecPersee::ColorStreamRef colorStreamRef;
};

void ofApp::setup() {
  ofSetWindowShape(1280,480);
  // use all default options (port 4444, only depth stream enabled, 30fps), only specify the Persee's IP
  client.setup(perseeHost);
  depthStreamRef = client.createDepthStream(); // 640x480 by default
  colorStreamRef = client.createColorStream(); // 1280x720 by default
}

void ofApp::update() {
  // client.update();
  depthStreamRef->update();
  // colorStreamRef->update();
}

void ofApp::draw() {
  ofBackground(0);

  auto tex = depthStreamRef->getTexture();

  if(tex.isAllocated()) {
    tex.draw(0, 0);
  }

  auto tex2 = colorStreamRef->getTexture();

  if(tex2.isAllocated()) {
    tex2.draw(650, 0, tex2.getWidth()/2, tex2.getHeight()/2);
  }
}

//========================================================================

int main( ){
  ofSetupOpenGL(800, 600, OF_WINDOW);
  ofRunApp(new ofApp());
}

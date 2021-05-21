#pragma once

#include "ofMain.h"

struct AStarNode
{
	int f;
	int g;
	int h;
};


class ofApp : public ofBaseApp
{
public:
	ofApp();
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	int m_cellSizeX;
	int m_cellSizeY;
	std::vector<std::vector<ofRectangle>> m_grid;

	void AStarPathFinding(ofVec2f start, ofVec2f end);
	ofVec2f GetXYInGrid(ofVec2f screenPosition) const;
};

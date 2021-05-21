#include "ofApp.h"

ofApp::ofApp() :
	m_cellSizeX(0),
	m_cellSizeY(0)
{

}

//--------------------------------------------------------------
void ofApp::setup()
{
	const int numCells = 10;
	m_cellSizeX = ofGetWindowWidth() / numCells;
	m_cellSizeY = ofGetWindowHeight() / numCells;

	for (int i = 0; i < numCells; i++)
	{
		std::vector<ofRectangle> rectangles;

		for (int j = 0; j < numCells; j++)
		{
			rectangles.emplace_back(j * m_cellSizeX, i * m_cellSizeY, m_cellSizeX, m_cellSizeY);
		}

		m_grid.emplace_back(rectangles);
	}
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i < m_grid.size(); ++i)
	{
		for (int j = 0; j < m_grid[i].size(); ++j)
		{
			auto& rect = m_grid[i][j];

			ofSetColor(255, 0, 0);
			ofNoFill();
			ofDrawRectangle(rect);
			
			ofFill();
			ofSetColor(255, 255, 255);
			
			ofDrawBitmapString(
				"Row: " + std::to_string(i) + "\nCol: " + std::to_string(j), 
				{
					rect.getPosition().x + m_cellSizeX / 2 - 20,
					rect.getPosition().y + m_cellSizeY / 2
				}
			);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	const auto pos = GetXYInGrid({static_cast<float>(x), static_cast<float>(y)});
	std::cout << pos << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

ofVec2f ofApp::GetXYInGrid(const ofVec2f screenPosition) const
{
	return {screenPosition.y / static_cast<float>(m_cellSizeY), screenPosition.x / static_cast<float>(m_cellSizeX)};
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}

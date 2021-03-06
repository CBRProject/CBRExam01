#include "Terrain.h"
int patterns[] = {1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,3,3,3};
int widths[] = {2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4};
int heights[] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,3,3,3,3,3,3,4};
int types[] = {1,2,3,4,1,3,2,4,3,2,1,4,2,3,1,4,2,3,1,2,3,2,3,4,1,2,4,3,1,3,1,4,2,4,2,1,2,3};

vector<int> _blockPattern (patterns, patterns + sizeof(patterns) / sizeof(int));
vector<int> _blockWidths (widths, widths + sizeof(widths) / sizeof(int));
vector<int> _blockHeights (heights, heights + sizeof(heights) / sizeof(int));
vector<int> _blockTypes (types, types + sizeof(types) / sizeof(int));

Terrain::~Terrain () {

	CC_SAFE_RELEASE(_blockPool);
	CC_SAFE_RELEASE(_blocks);
}

Terrain::Terrain()
:_screenSize(CCDirector::sharedDirector()->getWinSize())
,_startTerrain(false)
,_blockPoolIndex(0)
,_currentPatternCnt(1)
,_currentPatternIndex(0)
,_currentTypeIndex(0)
,_currentWidthIndex(0)
,_currentHeightIndex(0)
,_showGap(false)
{
}
Terrain * Terrain::create() {
    Terrain * terrain = new Terrain();
	if (terrain && terrain->initWithFile("blank.png")) {
        terrain->setAnchorPoint(ccp(0,0));
        terrain->initTerrain();
		terrain->autorelease();
		return terrain;
	}
	CC_SAFE_DELETE(terrain);
	return NULL;
}

void Terrain::initTerrain () {
}


void Terrain::checkCollision (Player * player) {


}


void Terrain::move (float xMove) {

}

void Terrain::reset() {

}

void Terrain::addBlocks(int currentWidth) {

}

void Terrain::distributeBlocks() {

}

void Terrain::initBlock(Block * block) {


}


#ifndef __GAMESPRITE_H__
#define __GAMESPRITE_H__

#include "cocos2d.h"


USING_NS_CC;
enum {

    kBackground,
    kMiddleground,
    kForeground
};

class GameSprite : public CCSprite {

protected:
	CCSize _screenSize;

public:

	CC_SYNTHESIZE(CCPoint, _nextPosition, NextPosition);

	CC_SYNTHESIZE(float, _width, Width);

	CC_SYNTHESIZE(float, _height, Height);

	CC_SYNTHESIZE(CCPoint, _vector, Vector);

	GameSprite(void);
	~GameSprite(void);

    inline virtual void place () { this->setPosition(_nextPosition); };

    inline void setSize() {
    	_width = this->boundingBox().size.width;
		_height = this->boundingBox().size.height;
    }


};

#endif // __GAMESPRITE_H__


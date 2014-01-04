#define ACCELERATION 0.5
#include "Player.h"

Player::~Player(){
}


Player::Player() {
    _screenSize = CCDirector::sharedDirector()->getWinSize();
	_floatingTimerMax = 2;
	_floatingTimer = 0;
    _speed = PLAYER_INITIAL_SPEED;
    _maxSpeed = PLAYER_INITIAL_SPEED;
    _floating = false;
    _nextPosition = CCPointZero;
	_nextPosition.y = _screenSize.height * 0.6f;
	_state = kPlayerMoving;
    _jumping = false;
    _hasFloated = false;
}

Player * Player::create () {

    Player * player = new Player();
	if (player && player->initWithFile("blank.png")) {
		player->autorelease();
        player->setSize();
        player->initPlayer();
        return player;
	}
	CC_SAFE_DELETE(player);
	return NULL;
}


void Player::update (float dt) {

}

void Player::reset () {

    _speed = PLAYER_INITIAL_SPEED;
    _maxSpeed = PLAYER_INITIAL_SPEED;
    _vector = ccp(0,0);
    this->setFloating(false);
    this->setRotation(0);
    _nextPosition.y = _screenSize.height * 0.6f;
    this->setPosition(ccp( _screenSize.width * 0.2f, _nextPosition.y ));
    _state = kPlayerMoving;
    _jumping = false;
    _hasFloated = false;
}

void Player::setFloating (bool value) {
	if(_floating == value) return;

	if (value && _hasFloated) return;

	_floating = value;

	if (value) {
		_hasFloated = true;
		_vector.y += PLAYER_JUMP + 0.5f;

	}

}

void Player::initPlayer () {
    this->setAnchorPoint(ccp(0.5f,1.0f));
    this->setPosition(ccp(_screenSize.width * 0.2f, _nextPosition.y));

    _height = 228;
    _width = 180;
    this->setTextureRect(CCRectMake(0,0,_width, _height));
    this->setColor(ccc3(255,255,255));

}

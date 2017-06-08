#pragma once
#ifndef _GAMELAYER_
#define _GAMELAYER_

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
#include "BaseRole.h"
#include "RoleCardController.h"
#include "BaseFSM.h"
#include "BaseAI.h"
#include "BaseRole.h"
#include "BaseTrap.h"
#include "Coin.h"
#include "ConditionLayer.h"
#include "Bullet.h"
USING_NS_CC;

//typedef enum RoleFace
//{
//	FACE_LEFT = 1,
//	FACE_RIGHT,
//}RoleFace;
class ConditionLayer;
class GameLayer : public Layer
{
	
public:
	GameLayer();
	virtual ~GameLayer();
	void onEnter();
	CREATE_FUNC(GameLayer);
	virtual bool init();
	void update(float dt);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	void spriteMoveFinished(Object * pSender);
public:
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	int keyPressedDurationDirection();
	int keyPressedDurationAcion();
	void setViewPointCenter(Point position);
public:
	void purge();
	Point tileCoordForPosition(Point position);
	void setPlayerPosition(Point position);
public:
	BaseRole * hero;
	BaseRole * monster;
	BaseRole * monster2;
	BaseTrap * trap;
	Coin * coin;
	SceneManager * tsm;
	ConditionLayer * layer;
	cocos2d::TMXTiledMap * _tileMap;
	cocos2d::TMXLayer * _meta;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
};
#endif

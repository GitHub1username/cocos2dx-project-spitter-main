#ifndef _BASE_AI_H_
#define _BASE_AI_H_
#pragma once
#include "cocos2d.h"
#include "BaseRole.h"
//#include "GameLayer.h"
USING_NS_CC;

class BaseRole;
//class GameLayer;

class BaseAI : public Ref
{
public:
	BaseAI();
	virtual ~BaseAI();
public:
	static BaseAI * creatAI(BaseRole * role);
	bool init(BaseRole * role);
	void startRoleAI();
	void stopRoleAI();
	void updateFunc(float dt);
	void purge();
public:
	Point tileCoordForPosition(BaseRole * role, Point position);
	void setPlayerPosition(BaseRole * role, Point position);
public:
	BaseRole * baseRole;
	//GameLayer * layer;
	cocos2d::TMXTiledMap * _tileMap;
	cocos2d::TMXLayer * _meta;
};
#endif


#pragma once
#ifndef _BASE_ROLE_H_
#define _BASE_ROLE_H_
#include <iostream>
#include "cocos2d.h"
#include "propertyManager.h"
#include "cocostudio/CocoStudio.h"
#include "BaseFSM.h"
#include "BaseAI.h"
#include "TextSuperEffects.h"
//#include "RoleCardController.h"
USING_NS_CC;
//using namespace CocosDenshion;
using namespace cocostudio;

typedef enum RoleType
{
	TYPE_HERO = 1,
	TYPE_MONSTER = 2,
	TYPE_MONSTER_APC,
}RoleType;

typedef enum RoleState
{
	ROLE_DEFAULT = 1,
	ROLE_MOVE,
	ROLE_DEAD,
	ROLE_FREE,
	ROLE_ATTACK,
	ROLE_JUMP,
}RoleState;

typedef enum RoleFace
{
	FACE_LEFT = 1,
	FACE_RIGHT,
	FACE_UP,
	FACE_DOWN,
}RoleFace;

class BaseFSM;
class BaseAI;
//class RoleCardController;

class BaseRole : public Node
{
public:
	BaseRole();
	virtual ~BaseRole();
	//static BaseRole * create(propertyManager * manager);
	static BaseRole * creatWithProperty(propertyManager * manager);
	bool init(propertyManager * manager);
public:
	virtual void fallHP(const char * hpCount);
	virtual void addCoinAmount(const char * coinCount);
	virtual void purge();
	virtual void jump();
	virtual void jumpEnd();
	virtual void shoot(RoleType type);
	void spriteMoveFinished(Object * pSender);
	//当前角色是英雄或怪物，如果是英雄，只能射一段距离，如果是怪物可以射很远
	//传入当前角色的类型，然后根据类型判断敌人是谁，然后遍历敌人数组
	virtual Rect getRealRect(BaseRole * role,Rect rect);

	virtual void changeFaceDirection(RoleFace face);

	virtual void animationEvent(Armature * pArmature, MovementEventType movmentType, const std::string & movementIDstr);

	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags)override;
	virtual void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
	cocos2d::CustomCommand _customCommand;
public:
	BaseRole * lockRole;

	propertyManager * propertymanager;
	//RoleCardController * rolecardcontroller;
	RoleType type;
	RoleState state;
	RoleFace face;
	int ID;

	CC_SYNTHESIZE(int, coinAmount, coinAmount);
	CC_SYNTHESIZE(Armature *, armature, Armature);
	CC_SYNTHESIZE(BaseFSM *, basefsm, BaseFSM);
public:
	CC_SYNTHESIZE(BaseAI *, baseai, BaseAI);
};
#endif


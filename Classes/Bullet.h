#pragma once
#include "cocos2d.h"
#include <iostream>
#include "BaseRole.h"
#include "cocostudio/CocoStudio.h"
//#include "CocoStudio.h"
USING_NS_CC;
using namespace cocostudio;

typedef enum BulletState
{
	BULLET_COLLIDED = 1,
	BULLET_DEFAULT,
	BULLET_FREE,
}BulletState;

//typedef enum RoleType
//{
//	TYPE_HERO = 1,
//	TYPE_MONSTER = 2,
//}RoleType;
enum RoleType;
//class BaseRole;
class Bullet : public Node
{
public:
	Bullet();
	virtual ~Bullet();
public:
	static Bullet * create(BaseRole * hero,propertyManager * manager);
	bool init(BaseRole * hero,propertyManager * manager);
	void purge();
public:
	BaseRole * hero;
	propertyManager * manager;
	RoleType type;
	BulletState state;
public:
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags)override;
	virtual void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
	cocos2d::CustomCommand _customCommand;
	virtual Rect getRealRect(Bullet * bullet, Rect rect);
//	virtual void animationEvent(Armature * pArmature, MovementEventType movmentType, const std::string & movementIDstr);
public:
	virtual bool isColliding(BaseRole * role);
	//传入子弹射的敌人，与当前敌人的种类（怪物或英雄）
	CC_SYNTHESIZE(Armature *, armature2, Armature);
};


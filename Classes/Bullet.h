#pragma once
#include "cocos2d.h"
#include <iostream>
#include "BaseRole.h"
<<<<<<< HEAD
=======
#include "cocostudio/CocoStudio.h"
//#include "CocoStudio.h"
USING_NS_CC;
using namespace cocostudio;
>>>>>>> leonnnop/master

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
<<<<<<< HEAD
=======
enum RoleType;
//class BaseRole;
>>>>>>> leonnnop/master
class Bullet : public Node
{
public:
	Bullet();
	virtual ~Bullet();
public:
<<<<<<< HEAD
	Bullet * create(BaseRole * hero,propertyManager * manager);
=======
	static Bullet * create(BaseRole * hero,propertyManager * manager);
>>>>>>> leonnnop/master
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
<<<<<<< HEAD
	virtual void animationEvent(Armature * pArmature, MovementEventType movmentType, const std::string & movementIDstr);
public:
	virtual bool isColliding(BaseRole * role,RoleType type);
	CC_SYNTHESIZE(Armature *, armature, Armature);
=======
//	virtual void animationEvent(Armature * pArmature, MovementEventType movmentType, const std::string & movementIDstr);
public:
	virtual bool isColliding(BaseRole * role);
	//�����ӵ���ĵ��ˣ��뵱ǰ���˵����ࣨ�����Ӣ�ۣ�
	CC_SYNTHESIZE(Armature *, armature2, Armature);
>>>>>>> leonnnop/master
};


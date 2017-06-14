#pragma once
#ifndef _PROPS_
#define _PROPS_

#include <iostream>
#include <cocos2d.h>
#include <BaseRole.h>
#include <propertyManager.h>

typedef enum PropsState
{
	PROPS_FREE = 1,
	PROPS_COLLECTED,
	PROPS_DEFAULT,
}PropsState;

typedef enum PropsType
{
	BLOOD_BAG = 1,
	SUPPLY_PACKAGE,

}PropsType;

class Props : public Node
{
public:
	Props();
	virtual ~Props();

public:
	static Props * createWithProperty(propertyManager * manager, BaseRole * hero);
	bool init(propertyManager * manager, BaseRole * hero);
	void purge();
	//void addAmmunitionAmount(int amount);
public:
	BaseRole * hero;
	propertyManager * propertymanager;
	PropsState state;
	PropsType type;
public:
	virtual void draw(cocos2d::Renderer* renderer, const cocos2d::Mat4& transform, uint32_t flags)override;
	virtual void onDraw(const cocos2d::Mat4& transform, uint32_t flags);
	cocos2d::CustomCommand _customCommand;
	virtual Rect getRealRect(Props * prop, Rect rect);
	virtual void animationEvent(Armature * pArmature, MovementEventType movmentType, const std::string & movementIDstr);
public:
	virtual bool isColliding(BaseRole * role);
	CC_SYNTHESIZE(Armature *, armature, Armature);
};

#endif
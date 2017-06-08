#pragma once
#ifndef _BASE_FSM_
#define _BASE_FSM_

#include <iostream>
#include "cocos2d.h"
#include "BaseRole.h"
#include <cstring>
USING_NS_CC;
class BaseRole;
class BaseFSM : public Ref
{
public:
	BaseFSM();
	virtual ~BaseFSM();
public:
	static BaseFSM * createFSM(BaseRole * baserole);
	bool init(BaseRole * baserole);

	void purge();
public:
	void changeToDefault(int i = 0);//Ĭ�ϲ�������д���������壬�����ܼ�� 
	void changeToDead();
	void changeToAttack();
	void changeToJump();
	void changeToLeft();
	void changeToRight();
	void changeToUp();
	void changeToDown();
	//void changeToEnemy();
	void switchMoveState(int state);
	void switchActionState(int state);

public:
	void update(float ft);
public:
	BaseRole * role;
};
#endif

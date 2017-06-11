#include "BaseFSM.h"



BaseFSM::BaseFSM()
{
}


BaseFSM::~BaseFSM()
{
}

BaseFSM * BaseFSM::createFSM(BaseRole * baserole)
{
	BaseFSM * basefsm = new BaseFSM();
	if (basefsm && basefsm->init(baserole))
	{
		basefsm->autorelease();
	} 
	else
	{
		CC_SAFE_DELETE(basefsm);
		//return nullptr;
	}
	return basefsm;
}

bool BaseFSM::init(BaseRole * baserole)
{
	role = baserole;

	return true;
}

void BaseFSM::purge()
{
	role = nullptr;
	CC_SAFE_RELEASE(this);
}

void BaseFSM::changeToDefault(int i)
{
	if (role->state == ROLE_ATTACK && i == 0)
	{
		return;
	}

	if (role->state != ROLE_DEFAULT && role->state != ROLE_DEAD && role->state != ROLE_FREE)
	{
		role->state = ROLE_DEFAULT;
		role->changeFaceDirection(FACE_DOWN);
		role->getArmature()->getAnimation()->play("default");
		if (role->type == TYPE_MONSTER_APC)
		{
			role->unschedule(schedule_selector(BaseFSM::update));
		}
	} 
}


void BaseFSM::changeToDead()
{
	if (role->state != ROLE_DEAD&&role->state!=ROLE_FREE)
	{
		role->state = ROLE_DEAD;
		role->getArmature()->getAnimation()->play("die",-1,0);//不重复播放
	}
}

void BaseFSM::changeToAttack()
{
	if (role->state != ROLE_ATTACK && role->state != ROLE_DEAD)
	{
		role->state = ROLE_ATTACK;
		role->getArmature()->getAnimation()->play("attack",-1,0);
		if (role->type == TYPE_MONSTER_APC)
		{
			//是个远程APC
			role->schedule(schedule_selector(BaseFSM::update), 1.0f); //每隔1.0f执行一次
		}
	}
}

void BaseFSM::changeToJump()
{
	if (role->state == ROLE_ATTACK)
	{
		return;
	}

	if (role->state != ROLE_JUMP && role->state != ROLE_DEAD)
	{
		role->state = ROLE_JUMP;
		role->getArmature()->getAnimation()->play("default", -1, 0);
		
		//CCJumpBy* jump = CCJumpBy::create(1.5f, ccp(0, 0), 10, 1);//强制起跳
		//role->runAction(jump);
		role->jump();
	}
}

void BaseFSM::changeToLeft()
{
	if (role->state == ROLE_ATTACK || role->state == ROLE_JUMP)
	{
		return;
	}

	if (role->state != ROLE_MOVE && role->state != ROLE_DEAD)
	{
		role->state = ROLE_MOVE;
	}

	if (role->face != FACE_LEFT)
	{
		role->changeFaceDirection(FACE_LEFT);
	}

		std::string movement = role->getArmature()->getAnimation()->getCurrentMovementID();
		char * nowMovement = const_cast<char *>(movement.c_str());
		if (strcmp(nowMovement, "run"))
		{
			role->getArmature()->getAnimation()->play("run");
		}
	
	role->setPosition(Vec2(role->getPositionX() - role->propertymanager->getSPEED(), role->getPositionY()));
}

void BaseFSM::changeToRight()
{
	if (role->state == ROLE_ATTACK || role->state == ROLE_JUMP )
	{
		return;
	}

	if (role->state != ROLE_MOVE && role->state != ROLE_DEAD)
	{
		role->state = ROLE_MOVE;
	}

	if (role->face != FACE_RIGHT)
	{
		role->changeFaceDirection(FACE_RIGHT);
	}

	std::string movement = role->getArmature()->getAnimation()->getCurrentMovementID();
	char * nowMovement = const_cast<char *>(movement.c_str());

	if (strcmp(nowMovement, "run"))//if the current movement is not running back ,play it.
	{
		role->getArmature()->getAnimation()->play("run");
	}
	
	role->setPosition(Vec2(role->getPositionX() + role->propertymanager->getSPEED(), role->getPositionY()));
}

void BaseFSM::changeToUp()
{
	if (role->state == ROLE_ATTACK || role->state == ROLE_JUMP)
	{
		return;
	}

	if (role->state != ROLE_MOVE && role->state != ROLE_DEAD)
	{
		role->state = ROLE_MOVE;
	}

	if (role->face != FACE_UP)
	{
		role->changeFaceDirection(FACE_UP);
	}

	std::string movement = role->getArmature()->getAnimation()->getCurrentMovementID();
	char * nowMovement = const_cast<char *>(movement.c_str());

	if (strcmp(nowMovement, "run_up"))//if the current movement is not running back ,play it.
	{
		role->getArmature()->getAnimation()->play("run_up");
	}

	role->setPosition(Vec2(role->getPositionX() , role->getPositionY() + role->propertymanager->getSPEED()));
}

void BaseFSM::changeToDown()
{
	if (role->state == ROLE_ATTACK || role->state == ROLE_JUMP)
	{
		return;
	}

	if (role->state != ROLE_MOVE && role->state != ROLE_DEAD)
	{
		role->state = ROLE_MOVE;
	}

	if (role->face != FACE_DOWN)
	{
		role->changeFaceDirection(FACE_DOWN);
	}

	std::string movement = role->getArmature()->getAnimation()->getCurrentMovementID();
	char * nowMovement = const_cast<char *>(movement.c_str());

	if (strcmp(nowMovement, "run_down"))//if the current movement is not running back ,play it.
	{
		role->getArmature()->getAnimation()->play("run_down");
	}

	role->setPosition(Vec2(role->getPositionX(), role->getPositionY() - role->propertymanager->getSPEED()));
}

void BaseFSM::switchMoveState(int state)
{
	switch (state)
	{
	case 0:
		this->changeToDefault();
		break;
	case FACE_LEFT:
		this->changeToLeft();
		break;
	case FACE_RIGHT:
		this->changeToRight();
		break;
	default:
		role->getArmature()->stopAllActions();
		break;
	}
}

void BaseFSM::switchActionState(int state)
{
	switch (state)
	{
	case 0:
		this->changeToDefault();
		break;
	case ROLE_ATTACK:
		this->changeToAttack();
		break;
	case FACE_LEFT:
		this->changeToLeft();
		break;
	case FACE_RIGHT:
		this->changeToRight();
		break;
	case FACE_DOWN:
		this->changeToDown();
		break;
	case FACE_UP:
		this->changeToUp();
		break;
	default:
		role->getArmature()->stopAllActions();
		break;
	}
}

void BaseFSM::update(float ft)
{
	role->shoot(role->type);
}

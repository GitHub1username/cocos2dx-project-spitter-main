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

void BaseFSM::changeToDefault()
{
	if (role->state != ROLE_DEFAULT && role->state != ROLE_DEAD)
	{
		role->state = ROLE_DEFAULT;
		role->getArmature()->getAnimation()->play("default");
	} 
}


void BaseFSM::changeToDead()
{
	if (role->state != ROLE_DEAD)
	{
		role->state = ROLE_DEAD;
		role->getArmature()->getAnimation()->play("gethit",-1,0);//���ظ�����
	}
}

void BaseFSM::changeToLeft()
{
	if (role->state != ROLE_MOVE && role->state != ROLE_DEAD)
	{
		role->state = ROLE_MOVE;
	}

	if (role->face == FACE_RIGHT)
	{
		role->changeFaceDirection(FACE_LEFT);
	}

		std::string movement = role->getArmature()->getAnimation()->getCurrentMovementID();
		char * nowMovement = const_cast<char *>(movement.c_str());
		if (strcmp(nowMovement, "run_front"))
		{
			role->getArmature()->getAnimation()->play("run_front");
		}
	
	role->setPosition(Vec2(role->getPositionX() - role->propertymanager->getSPEED(), role->getPositionY()));
}

void BaseFSM::changeToRight()
{
	if (role->state != ROLE_MOVE && role->state != ROLE_DEAD)
	{
		role->state = ROLE_MOVE;
	}

	if (role->face == FACE_LEFT)
	{
		role->changeFaceDirection(FACE_RIGHT);
	}

	std::string movement = role->getArmature()->getAnimation()->getCurrentMovementID();
	char * nowMovement = const_cast<char *>(movement.c_str());

	if (strcmp(nowMovement, "run_front"))//if the current movement is not running back ,play it.
	{
		role->getArmature()->getAnimation()->play("run_front");
	}
	
	role->setPosition(Vec2(role->getPositionX() + role->propertymanager->getSPEED(), role->getPositionY()));
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

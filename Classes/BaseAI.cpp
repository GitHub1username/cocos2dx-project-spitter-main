#include "BaseAI.h"
#include "RoleCardController.h"
#include <vector>
#include <cmath>
#include <iostream>
#include "BaseFSM.h"

BaseAI::BaseAI()
{
}


BaseAI::~BaseAI()
{
}

BaseAI * BaseAI::creatAI(BaseRole * role)
{
	BaseAI * ai = new BaseAI();
	if (ai && ai->init(role))
	{
		ai->autorelease();
	} 
	else
	{
		CC_SAFE_DELETE(ai);
	}
	return ai;
}

bool BaseAI::init(BaseRole * role)
{
	this->baseRole = role;
	return true;
}

void BaseAI::startRoleAI()
{
	Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR(BaseAI::updateFunc), this, (float)1 / 60, false);
}

void BaseAI::stopRoleAI()
{
	//Director::getInstance()->getScheduler()->unscheduleAll();
	Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR(BaseAI::updateFunc), this);
}

void BaseAI::updateFunc(float dt)
{
	//int i = 0;
	std::vector<BaseRole *> roleVec;
	if (baseRole->type == TYPE_HERO)
	{
		roleVec = RoleCardController::getInstance()->monsterVec;
	} 
	else
	{
		roleVec = RoleCardController::getInstance()->heroVec;
		//i = 1;
		//std::cout << "check" << std::endl;
	}

	int roleID = 0;
	if (roleVec.size() != 0)
	{
		float distance = Director::getInstance()->getVisibleSize().width;
		for (int i = 0; i < roleVec.size(); i++)
		{
			if (roleVec[i] == nullptr || baseRole == nullptr)
			{
				continue;
			}
			float newDis = abs(baseRole->getPosition().distance((roleVec[i])->getPosition()));
			if (newDis < distance)
			{
				distance = newDis;
				roleID = i;
			}
		}

		if (roleVec[roleID]->getPositionX() > baseRole->getPositionX())
		{
			baseRole->changeFaceDirection(FACE_RIGHT);
		}
		else if (roleVec[roleID]->getPositionX() == baseRole->getPositionX()&& roleVec[roleID]->getPositionY() > baseRole->getPositionY())
		{
			baseRole->changeFaceDirection(FACE_UP);
		}
		else if (roleVec[roleID]->getPositionX() == baseRole->getPositionX() && roleVec[roleID]->getPositionY() < baseRole->getPositionY())
		{
			baseRole->changeFaceDirection(FACE_DOWN);
		}
		else
		{
			baseRole->changeFaceDirection(FACE_LEFT);
		}
	} 
	else
	{
		baseRole->lockRole = nullptr;
		return;
	}

	baseRole->lockRole = roleVec[roleID];

	if (baseRole->type == TYPE_MONSTER)
	{
		Vec2 enemyPos = roleVec[roleID]->getPosition();

		if (baseRole->getPosition().distance(enemyPos) < baseRole->propertymanager->getLockLimit())
		{
			if (baseRole->getPosition().distance(enemyPos) < baseRole->propertymanager->getATKLimit())
			{
				baseRole->getBaseFSM()->changeToAttack();
			}
			else
			{
				Point playerPos = baseRole->getPosition();

				if (baseRole->face == FACE_LEFT && baseRole->state != ROLE_ATTACK)
				{
					baseRole->getBaseFSM()->changeToLeft();
				} 
				else if(baseRole->face == FACE_RIGHT && baseRole->state != ROLE_ATTACK)
				{
					baseRole->getBaseFSM()->changeToRight();
				}
				else if (baseRole->face == FACE_UP && baseRole->state != ROLE_ATTACK)
				{
					baseRole->getBaseFSM()->changeToUp();
				}
				else if (baseRole->face == FACE_DOWN && baseRole->state != ROLE_ATTACK)
				{
					baseRole->getBaseFSM()->changeToDown();
				}
				setPlayerPosition(baseRole, playerPos);
			}
		}
		else
		{
			baseRole->getBaseFSM()->changeToDefault();
		}
	}
}

void BaseAI::purge()
{
	stopRoleAI();
	baseRole = nullptr;
	CC_SAFE_RELEASE(this);
}

Point BaseAI::tileCoordForPosition(BaseRole * role, Point position)
{
	int x;
	int y;
	if (role->face == FACE_RIGHT)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40) / _tileMap->getTileSize().height);
	}
	else if (role->face == FACE_LEFT)
	{
		x = static_cast<int>((position.x - 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40) / _tileMap->getTileSize().height);
	}
	else if (role->face == FACE_UP)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) - 40) / _tileMap->getTileSize().height);

	}
	else if (role->face == FACE_DOWN)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40) / _tileMap->getTileSize().height);

	}

	return Point(x, y);
}

void BaseAI::setPlayerPosition(BaseRole * role, Point position)
{
	Point tileCoord = this->tileCoordForPosition(role, role->getPosition());
	int tileGid = _meta->getTileGIDAt(tileCoord);
	if (tileGid)
	{
		auto properties = _tileMap->getPropertiesForGID(tileGid).asValueMap();
		if (!properties.empty())
		{
			auto collision = properties["Collidable"].asString();
			if ("True" == collision)
			{
				role->stopActionByTag(233);
				//position.y -= 5;
				role->setPosition(position);
				//hero->getBaseFSM()->changeToDefault();

				return;
			}
		}
	}
	//hero->setPosition(position);
}

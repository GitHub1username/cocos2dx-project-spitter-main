#include "Bullet.h"



Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

Bullet * Bullet::create(BaseRole * hero,propertyManager * manager)
{
	Bullet * bullet = new Bullet;
	if (bullet && bullet->init(hero,manager))
	{
		bullet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(bullet);
		return nullptr;
	}
	return bullet;
}

bool Bullet::init(BaseRole * hero , propertyManager * manager)
{
	this->hero = hero;
	this->manager = manager;
	type = hero->type;
	//this->addChild("res/mushroom.png");
	ArmatureDataManager::getInstance()->addArmatureFileInfo(manager->getDataName());
	armature = Armature::create(manager->getArmatureName());
	armature->getAnimation()->play("coin");

	this->addChild(armature);

	armature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(Bullet::animationEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

	return true;
}

void Bullet::purge()
{
	removeFromParent();
}

void Bullet::draw(cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform, uint32_t flags)
{
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(Bullet::onDraw, this, transform, flags);
	renderer->addCommand(&_customCommand);
}

void Bullet::onDraw(const cocos2d::Mat4 & transform, uint32_t flags)
{
	Director * director = Director::getInstance();
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	CHECK_GL_ERROR_DEBUG();

	Rect rect = manager->getHitRect();
	DrawPrimitives::setDrawColor4B(0, 0, 255, 255);
	DrawPrimitives::drawRect(Vec2(rect.getMinX(), rect.getMinY()), Vec2(rect.getMaxX(), rect.getMaxY()));

	//rect = propertymanager->getGetHitRect();
	//DrawPrimitives::setDrawColor4B(0, 255, 0, 255);
	//DrawPrimitives::drawRect(Vec2(rect.getMinX(), rect.getMinY()), Vec2(rect.getMaxX(), rect.getMaxY()));

	CHECK_GL_ERROR_DEBUG();
	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

Rect Bullet::getRealRect(Bullet * bullet, Rect rect)
{
	return Rect(rect.origin.x + bullet->getPositionX(), rect.origin.y + bullet->getPositionY(), rect.size.width, rect.size.height);
}

void Bullet::animationEvent(Armature * pArmature, MovementEventType movmentType, const std::string & movementIDstr)
{
	const char * movementID = movementIDstr.c_str();

	if (!strcmp(movementID, "coin"))
	{
		if (this->state == BULLET_COLLIDED)
		{
			armature->runAction(Sequence::create(FadeOut::create(.1f), CallFunc::create([=]() {state = BULLET_FREE; }), NULL));
		}
	}
}

bool Bullet::isColliding(BaseRole * role, RoleType type)
{
	return getRealRect(this, this->manager->getHitRect()).intersectsRect(role->getRealRect(role, role->propertymanager->getGetHitRect()));
}

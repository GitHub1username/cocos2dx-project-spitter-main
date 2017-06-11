#include "Props.h"



Props::Props()
{
}


Props::~Props()
{
}

Props * Props::createWithProperty(propertyManager * manager, BaseRole * hero)
{
	Props * prop = new Props;
	if (prop&&prop->init(manager, hero))
	{
		prop->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(prop);
		return nullptr;
	}
	return prop;
}

bool Props::init(propertyManager * manager, BaseRole * hero)
{
	this->hero = hero;
	this->propertymanager = manager;
	//状态没有初始化，状态没有初始化，状态没有初始化
	//this->addChild("res/mushroom.png");
	ArmatureDataManager::getInstance()->addArmatureFileInfo(propertymanager->getDataName());
	armature = Armature::create(propertymanager->getArmatureName());
<<<<<<< HEAD
<<<<<<< HEAD
	armature->getAnimation()->play("default");

	this->addChild(armature);

	//armature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(Props::animationEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
=======
=======
>>>>>>> leonnnop/Map
	armature->getAnimation()->play("supply");

	this->addChild(armature);

	armature->getAnimation()->setMovementEventCallFunc(CC_CALLBACK_0(Props::animationEvent, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
<<<<<<< HEAD
>>>>>>> leonnnop/Map
=======
>>>>>>> leonnnop/Map

	return true;
}

void Props::purge()
{
	removeFromParent();
}

//void Props::addAmmunitionAmount(int amount)
//{
//	hero->setcoinAmount(amount + hero->getAmmunitionAmount());
//	__String * coinStr = __String::createWithFormat("%d", amount);
//}

void Props::draw(cocos2d::Renderer * renderer, const cocos2d::Mat4 & transform, uint32_t flags)
{
	_customCommand.init(_globalZOrder);
	_customCommand.func = CC_CALLBACK_0(Props::onDraw, this, transform, flags);
	renderer->addCommand(&_customCommand);
}

void Props::onDraw(const cocos2d::Mat4 & transform, uint32_t flags)
{
	Director * director = Director::getInstance();
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

	CHECK_GL_ERROR_DEBUG();

	Rect rect = propertymanager->getHitRect();
	DrawPrimitives::setDrawColor4B(0, 0, 255, 255);
	DrawPrimitives::drawRect(Vec2(rect.getMinX(), rect.getMinY()), Vec2(rect.getMaxX(), rect.getMaxY()));

	//rect = propertymanager->getGetHitRect();
	//DrawPrimitives::setDrawColor4B(0, 255, 0, 255);
	//DrawPrimitives::drawRect(Vec2(rect.getMinX(), rect.getMinY()), Vec2(rect.getMaxX(), rect.getMaxY()));

	CHECK_GL_ERROR_DEBUG();
	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

Rect Props::getRealRect(Props * prop, Rect rect)
{
	return Rect(rect.origin.x + prop->getPositionX(), rect.origin.y + prop->getPositionY(), rect.size.width, rect.size.height);
}

void Props::animationEvent(Armature * pArmature, MovementEventType movmentType, const std::string & movementIDstr)
{
	const char * movementID = movementIDstr.c_str();

<<<<<<< HEAD
<<<<<<< HEAD
	if (!strcmp(movementID, "default"))
=======
	if (!strcmp(movementID, "supply"))
>>>>>>> leonnnop/Map
=======
	if (!strcmp(movementID, "supply"))
>>>>>>> leonnnop/Map
	{
		if (this->state == PROPS_COLLECTED)
		{
			armature->runAction(Sequence::create(FadeOut::create(.5f), CallFunc::create([=]() {state = PROPS_FREE; }), NULL));
		}
	}
}

bool Props::isColliding(BaseRole * role)
{
	return getRealRect(this, this->propertymanager->getHitRect()).intersectsRect(role->getRealRect(role, role->propertymanager->getGetHitRect()));
}

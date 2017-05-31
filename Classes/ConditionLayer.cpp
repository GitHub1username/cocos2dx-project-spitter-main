#include "ConditionLayer.h"



ConditionLayer::ConditionLayer()
{
}


ConditionLayer::~ConditionLayer()
{
}

bool ConditionLayer::init()
{
	Size winSize = Director::getInstance()->getWinSize();

	MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 20),
		CC_CALLBACK_1(ConditionLayer::menuCallBack, this));
	menuItem->setTag(101);
	menuItem->setPosition(Vec2(winSize.width * 0.95, winSize.height * 0.1));

	Menu * menu = Menu::create(menuItem, NULL, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);
	return true;
}

void ConditionLayer::menuCallBack(Ref * pSender)
{
	switch (((MenuItem *)pSender)->getTag())
	{
		case 101:
		{
			tsm->goOpenScene();
		}
	break;
	}
}

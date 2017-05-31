#include "HelpLayer.h"



HelpLayer::HelpLayer()
{
}


HelpLayer::~HelpLayer()
{
}

bool HelpLayer::init()
{
	Size winSize = Director::getInstance()->getWinSize();
	Label * label = Label::createWithTTF("Preparing...", "fonts/Marker Felt.ttf", 32);
	//auto size = Director::getInstance()->getWinSize();

	label->setPosition(Point(winSize.width / 2, winSize.height / 2));

	//	auto point = label->getPosition();

	this->addChild(label);

	MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 20),
		CC_CALLBACK_1(HelpLayer::menuCallBack, this));
	menuItem->setTag(101);
	menuItem->setPosition(Vec2(winSize.width * 0.95, winSize.height * 0.1));

	Menu * menu = Menu::create(menuItem, NULL, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

void HelpLayer::menuCallBack(Ref * pSender)
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

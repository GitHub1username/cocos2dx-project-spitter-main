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

	m_pProgressView = new ProgressView();
	m_pProgressView->setPosition(ccp(150, 450));
	m_pProgressView->setScale(3.2f);
	m_pProgressView->setScaleX(4.4f);
	m_pProgressView->setBackgroundTexture("res/xue_back.png");
	m_pProgressView->setForegroundTexture("res/xue_fore.png");
	m_pProgressView->setTotalProgress(100.0f);
	m_pProgressView->setCurrentProgress(100.0f);
	this->addChild(m_pProgressView, 2);

	return true;
}

void ConditionLayer::menuCallBack(Ref * pSender)
{
	switch (((MenuItem *)pSender)->getTag())
	{
		case 101:
		{
			this->layer->unscheduleAllSelectors();
			
			tsm->goOpenScene();
		}
	break;
	}
}

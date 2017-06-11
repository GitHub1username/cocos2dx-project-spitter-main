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
	this->setcoinNum(0);
	this->setammunition(45);

	CCLabelTTF* pCoin = CCLabelTTF::create("Coin Number:", "Arial", 28);
	//CC_BREAK_IF(pCoinNum == NULL);
	pCoin->setPosition(ccp(winSize.width*0.83, winSize.height*0.9));
	pCoin->setColor(ccc3(0, 0, 0));
	addChild(pCoin);

	pCoinNum = CCLabelTTF::create("0", "Arial", 28);
	//CC_BREAK_IF(pCoinNum == NULL);
	pCoinNum->setPosition(ccp(winSize.width*0.95, winSize.height*0.9));
	pCoinNum->setColor(ccc3(0, 0, 0));
	addChild(pCoinNum);

	CCLabelTTF* ammunition = CCLabelTTF::create("Ammunition Number:", "Arial", 28);
	//CC_BREAK_IF(pCoinNum == NULL);
	ammunition->setPosition(ccp(winSize.width*0.77, winSize.height*0.8));
	ammunition->setColor(ccc3(0, 0, 0));
	addChild(ammunition);

	ammunitionNum = CCLabelTTF::create("45", "Arial", 28);
	//CC_BREAK_IF(pCoinNum == NULL);
	ammunitionNum->setPosition(ccp(winSize.width*0.95, winSize.height*0.8));
	ammunitionNum->setColor(ccc3(0, 0, 0));
	addChild(ammunitionNum);

	MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 20),
		CC_CALLBACK_1(ConditionLayer::menuCallBack, this));
	menuItem->setTag(101);
	menuItem->setPosition(Vec2(winSize.width * 0.90, winSize.height * 0.1));

	Menu * menu = Menu::create(menuItem, NULL, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	progressView = ProgressView::create();
<<<<<<< HEAD
	progressView->setPosition(ccp(270, 450));
=======
<<<<<<< HEAD
	progressView->setPosition(ccp(200, 450));
=======
	progressView->setPosition(ccp(270, 450));
>>>>>>> refs/remotes/origin/master
>>>>>>> leonnnop/Map
	progressView->setScale(3.2f);
	progressView->setScaleX(6.4f);

	this->addChild(progressView, 2);

	return true;
}

void ConditionLayer::menuCallBack(Ref * pSender)
{
	switch (((MenuItem *)pSender)->getTag())
	{
		case 101:
		{
			this->layer->unscheduleAllSelectors();
			auto itr = RoleCardController::getInstance()->monsterVec.begin();
			while (itr!= RoleCardController::getInstance()->monsterVec.end())
			{
				(*itr)->getBaseAI()->stopRoleAI();
				itr++;
			}
			
			tsm->goOpenScene();
		}
	break;
	}
}

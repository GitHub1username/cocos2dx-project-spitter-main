#include "GameLayer.h"




GameLayer::GameLayer()
{
}


GameLayer::~GameLayer()
{
}

void GameLayer::onEnter()
<<<<<<< HEAD
{
	Layer::onEnter();

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = true;
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = false;
	};

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->setSwallowTouches(true);

	listener2->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		return true;
	};
	listener2->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

bool GameLayer::init()
{
	
	_tileMap = TMXTiledMap::create("TileMap.tmx");
	_tileMap->setPosition(ccp(0, 0));

	addChild(_tileMap, -1);

	TMXObjectGroup* group = _tileMap->getObjectGroup("Objects");
	ValueMap spawnPoint = group->getObject("SpawnPoint");

	_meta = _tileMap->getLayer("Meta");
	_meta->setVisible(true);

	float x = spawnPoint["x"].asFloat();
	float y = spawnPoint["y"].asFloat();
	log("%f %f", x, y);
	this->onEnter();

	this->scheduleUpdate();
	//Director::getInstance()->getScheduler()->schedule(schedule_selector(ControlLayer::update), this, (float)1 / 60, false);
/*
=======
{
	Layer::onEnter();

>>>>>>> leonnnop/master
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = true;
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = false;
	};

	auto listener2 = EventListenerTouchOneByOne::create();
	listener2->setSwallowTouches(true);

	listener2->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		return true;
	};
	listener2->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
<<<<<<< HEAD
*/
=======

}

bool GameLayer::init()
{
	
	_tileMap = TMXTiledMap::create("TileMap.tmx");
	_tileMap->setPosition(ccp(0, 0));

	addChild(_tileMap, -1);

	TMXObjectGroup* group = _tileMap->getObjectGroup("Objects");
	ValueMap spawnPoint = group->getObject("SpawnPoint");

	_meta = _tileMap->getLayer("Meta");
	_meta->setVisible(true);

	float x = spawnPoint["x"].asFloat();
	float y = spawnPoint["y"].asFloat();
	log("%f %f", x, y);
	this->onEnter();

	this->scheduleUpdate();
	//Director::getInstance()->getScheduler()->schedule(schedule_selector(ControlLayer::update), this, (float)1 / 60, false);

>>>>>>> leonnnop/master
	propertyManager * pManager = propertyManager::create();
	pManager->setID(1);
	pManager->setATK(50);
	pManager->setHP(100);
	pManager->setArmatureName("New_Hero");
	pManager->setDataName("New_Hero/New_Hero.ExportJson");
	pManager->setSPEED(2);//前进后退速度应该不一致，有待修改
	pManager->setGetHitRect({ { -40,-40 },{ 80,80 } });
	pManager->setHitRect({ { 40,-40 },{ 80,80 } });
	pManager->setHitPoint(pManager->getHitRect().origin);
	pManager->setGetHitPoint(pManager->getGetHitRect().origin);
	pManager->setATKLimit(100);
	pManager->setLockLimit(400);
	pManager->retain();

	hero = BaseRole::creatWithProperty(pManager);
	hero->setPosition(Vec2(x, y));
	hero->type = static_cast<RoleType>(1);

	this->addChild(hero, 1, 1);

	//缺少一个生成类，复制粘贴是什么辣鸡

<<<<<<< HEAD
	propertyManager * pManager2 = propertyManager::create();
	pManager2->setID(2);
	pManager2->setATK(10);
	pManager2->setHP(100);
	pManager2->setArmatureName("enemy");
	pManager2->setDataName("enemy/enemy.ExportJson");
	pManager2->setSPEED(1);//前进后退速度应该不一致，有待修改
	pManager2->setGetHitRect({ { -40,-40 },{ 80,80 } });
	pManager2->setHitRect({ { 40,-40 },{ 80,80 } });
	pManager2->setHitPoint(pManager2->getHitRect().origin);
	pManager2->setGetHitPoint(pManager2->getGetHitRect().origin);
	pManager2->setATKLimit(100);
	pManager2->setLockLimit(200);
	pManager2->retain();

	monster = BaseRole::creatWithProperty(pManager2);
	monster->setPosition(Vec2(600, 200));
	monster->type = static_cast<RoleType>(2);

	this->addChild(monster, 1, 1);

	propertyManager * pManager3 = propertyManager::create();
	pManager3->setID(3);
	pManager3->setATK(10);
	pManager3->setHP(100);
	pManager3->setArmatureName("hero");
	pManager3->setDataName("hero/hero.ExportJson");
	pManager3->setSPEED(1);//前进后退速度应该不一致，有待修改
	pManager3->setGetHitRect({ { -40,-40 },{ 80,80 } });
	pManager3->setHitRect({ { 40,-40 },{ 80,80 } });
	pManager3->setHitPoint(pManager3->getHitRect().origin);
	pManager3->setGetHitPoint(pManager3->getGetHitRect().origin);
	pManager3->setATKLimit(100);
	pManager3->setLockLimit(200);
	pManager3->retain();

	monster2 = BaseRole::creatWithProperty(pManager3);
	monster2->setPosition(Vec2(400, 200));
	monster2->type = static_cast<RoleType>(2);

	this->addChild(monster2, 1, 1);
=======
	for (int i =0;i<2;i++)
	{
		propertyManager * pManager2 = propertyManager::create();
		pManager2->setID(2);
		pManager2->setATK(10);
		pManager2->setHP(100);
		pManager2->setArmatureName("enemy");
		pManager2->setDataName("enemy/enemy.ExportJson");
		pManager2->setSPEED(1);//前进后退速度应该不一致，有待修改
		pManager2->setGetHitRect({ { -40,-40 },{ 80,80 } });
		pManager2->setHitRect({ { 40,-40 },{ 80,80 } });
		pManager2->setHitPoint(pManager2->getHitRect().origin);
		pManager2->setGetHitPoint(pManager2->getGetHitRect().origin);
		pManager2->setATKLimit(100);
		pManager2->setLockLimit(200);
		pManager2->retain();

		auto monster = BaseRole::creatWithProperty(pManager2);
		monster->setPosition(Vec2(400 + i*100, 200));
		monster->type = static_cast<RoleType>(2);
		//monster->retain();

		this->addChild(monster, 1, 1);

		BaseFSM * basefsm2 = BaseFSM::createFSM(monster);
		basefsm2->retain();
		monster->setBaseFSM(basefsm2);

		BaseAI * ai = BaseAI::creatAI(monster);
		ai->retain();
		monster->setBaseAI(ai);

		ai->startRoleAI();

		RoleCardController::getInstance()->monsterVec.push_back(monster);
	}
>>>>>>> leonnnop/master

	propertyManager * pManager4 = propertyManager::create();
	pManager4->setHitRect({ { -40,-40 },{ 80,80 } });
	pManager4->setHitPoint(pManager4->getHitRect().origin);
	pManager4->setArmatureName("trap1");
	pManager4->setDataName("trap1/trap1.ExportJson");
	pManager4->retain();

	auto trap = BaseTrap::createWithProperty(pManager4, hero);
	//trap = static_cast<BaseTrap *>(Sprite::create("res/mushroom.png"));
	//trap->autorelease();
	trap->init(pManager4, hero);
	trap->setPosition(Vec2(800, 100));
	this->addChild(trap, 1, 1);

	propertyManager * pManager5 = propertyManager::create();
	pManager5->setHitRect({ { -40,-40 },{ 80,80 } });
	pManager5->setHitPoint(pManager5->getHitRect().origin);
	pManager5->setArmatureName("coin");
	pManager5->setDataName("coin/coin.ExportJson");
	pManager5->retain();

	auto coin = Coin::createWithProperty(pManager5, hero);
	coin->setPosition(Vec2(1000, 200));
	this->addChild(coin, 1, 1);

	propertyManager * pManager6 = propertyManager::create();
	pManager6->setHitRect({ { -40,-40 },{ 80,80 } });
	pManager6->setHitPoint(pManager6->getHitRect().origin);
	pManager6->setArmatureName("supply1");
	pManager6->setDataName("supply1/supply1.ExportJson");
	pManager6->retain();

	auto supply1 = Props::createWithProperty(pManager6, hero);
	supply1->setPosition(Vec2(1000, 400));
	supply1->type = BLOOD_BAG;
	this->addChild(supply1, 1, 1);
	RoleCardController::getInstance()->propVec.push_back(supply1);

	propertyManager * pManager7 = propertyManager::create();
	pManager7->setHitRect({ { -40,-40 },{ 80,80 } });
	pManager7->setHitPoint(pManager7->getHitRect().origin);
	pManager7->setArmatureName("supply2");
	pManager7->setDataName("supply2/supply2.ExportJson");
	pManager7->retain();

	auto supply2 = Props::createWithProperty(pManager7, hero);
	supply2->setPosition(Vec2(1000, 600));
	supply2->type = SUPPLY_PACKAGE;
	this->addChild(supply2, 1, 1);
	RoleCardController::getInstance()->propVec.push_back(supply2);

	RoleCardController::getInstance()->heroVec.push_back(hero);
	RoleCardController::getInstance()->setHeroID(hero->propertymanager->getID());
	//RoleCardController::getInstance()->monsterVec.push_back(monster);
	//RoleCardController::getInstance()->monsterVec.push_back(monster2);
	RoleCardController::getInstance()->trapVec.push_back(trap);
	RoleCardController::getInstance()->coinVec.push_back(coin);
	RoleCardController::getInstance()->retain();

	BaseFSM * basefsm = BaseFSM::createFSM(hero);
	basefsm->retain();
	hero->setBaseFSM(basefsm);

	auto winSize = Director::getInstance()->getWinSize();
	auto bg_pic = Sprite::create("res/Map/background.jpg");
	bg_pic->setPosition(Point(winSize.width / 2, winSize.height / 2));
	this->addChild(bg_pic);
	
	return true;
}

void GameLayer::update(float dt)
{
	Node::update(dt);
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW,
		rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW,
		upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW,
		downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW,
		a = EventKeyboard::KeyCode::KEY_A;


	layer->progressView->setCurrentProgress((float)(hero->propertymanager->getHP()));

<<<<<<< HEAD
=======
	hero->propertymanager->setHP(hero->propertymanager->getHP() - 1.0/60);
	//不赶紧走就会死哦~~

	auto itr3 = RoleCardController::getInstance()->bulletVec.begin();
	while (itr3 != RoleCardController::getInstance()->bulletVec.end())
	{
		if ((*itr3)->state == BULLET_FREE)
		{
			(*itr3)->purge();
			RoleCardController::getInstance()->bulletVec.erase(itr3);
			break;
		}
		++itr3;
	}
>>>>>>> leonnnop/master

	auto itr = RoleCardController::getInstance()->monsterVec.begin();
	while (itr != RoleCardController::getInstance()->monsterVec.end())
	{
		if ((*itr)->state == ROLE_FREE)
		{
			(*itr)->purge();
			RoleCardController::getInstance()->monsterVec.erase(itr);
			break;
		}
		++itr;
	}
	if (RoleCardController::getInstance()->monsterVec.size() == 0)
	{
		//this->purge();
		//赢啦，应该转到胜利界面，或下一关数据读取界面。
		return;
	}

	itr = RoleCardController::getInstance()->heroVec.begin();
	while (itr != RoleCardController::getInstance()->heroVec.end())
	{
		if ((*itr)->state == ROLE_FREE)
		{
			(*itr)->purge();
			RoleCardController::getInstance()->heroVec.erase(itr);
			break;
		}
		++itr;
	}
	if (RoleCardController::getInstance()->heroVec.size() == 0)
	{
		//this->purge();
		//输了，转到嘲讽界面2333
		return;
	}

	auto trap_itr = RoleCardController::getInstance()->trapVec.begin();
	while (trap_itr != RoleCardController::getInstance()->trapVec.end())
	{
		if (hero->state != ROLE_DEAD&&hero->state != ROLE_FREE && (*trap_itr)->isColliding(hero))
		{
			__String * hpStr = __String::createWithFormat("%d", 10);
			hero->fallHP(hpStr->getCString());
			hero->propertymanager->setHP(hero->propertymanager->getHP() - 10);
			if (hero->propertymanager->getHP() <= 0)
			{
				//lockRole->getBaseAI()->stopRoleAI();
				hero->getBaseFSM()->changeToDead();
				hero->state = ROLE_FREE;
			}
		}
		++trap_itr;
	}

	//auto enbullert_itr = RoleCardController::getInstance()->bulletVec.begin();
	//while (enbullert_itr != RoleCardController::getInstance()->bulletVec.end())
	//{
	//	for (auto mitr = RoleCardController::getInstance()->monsterVec.begin();mitr != RoleCardController::getInstance()->monsterVec.end();mitr++)
	//	{
	//		if (hero->state != ROLE_DEAD&&hero->state != ROLE_FREE && (*enbullert_itr)->isColliding((*mitr), (*mitr)->type))
	//		{
	//			__String * hpStr = __String::createWithFormat("%d", 10);
	//			(*mitr)->fallHP(hpStr->getCString());
	//			(*mitr)->propertymanager->setHP((*mitr)->propertymanager->getHP() - 10);
	//			if ((*mitr)->propertymanager->getHP() <= 0)
	//			{
	//				//lockRole->getBaseAI()->stopRoleAI();
	//				(*mitr)->getBaseFSM()->changeToDead();
	//				(*mitr)->state = ROLE_FREE;
	//			}
	//			break;
	//		}
	//	}
	//	++enbullert_itr;
	//}

	auto bullert_itr = RoleCardController::getInstance()->bulletVec.begin();
	auto mitr = RoleCardController::getInstance()->monsterVec.begin();
	while (bullert_itr != RoleCardController::getInstance()->bulletVec.end())
	{
		mitr = RoleCardController::getInstance()->monsterVec.begin();
		while (mitr != RoleCardController::getInstance()->monsterVec.end())
		{
			if (hero->state != ROLE_DEAD && hero->state != ROLE_FREE && (*bullert_itr)->isColliding((*mitr)))
			{
				__String * hpStr = __String::createWithFormat("%d", 1);
				(*mitr)->fallHP(hpStr->getCString());
				(*mitr)->propertymanager->setHP((*mitr)->propertymanager->getHP() - 1);
				if ((*mitr)->propertymanager->getHP() <= 0)
				{
					//lockRole->getBaseAI()->stopRoleAI();
					(*mitr)->getBaseFSM()->changeToDead();
					(*mitr)->state = ROLE_FREE;
				}
				//break;
			}
			mitr++;
		}
		++bullert_itr;
	}

	auto coin_itr = RoleCardController::getInstance()->coinVec.begin();
	while (coin_itr != RoleCardController::getInstance()->coinVec.end())
	{
		if ((*coin_itr)->state == COIN_FREE)
		{
			(*coin_itr)->purge();
			RoleCardController::getInstance()->coinVec.erase(coin_itr);
			continue;
			//这个free掉，后面继续
		}

		if (hero->state != ROLE_DEAD&&hero->state != ROLE_FREE && (*coin_itr)->isColliding(hero))
		{
			if ((*coin_itr)->state == COIN_COLLECTED)
			{
				break;
			}
			__String * coinStr = __String::createWithFormat("%d", 1);
			hero->addCoinAmount(coinStr->getCString());
			(*coin_itr)->addCoinAmount(1);
			this->layer->setcoinNum(this->layer->getcoinNum() + 1);
			(*coin_itr)->state = COIN_COLLECTED;
			break;//一次收集一个
		}
		++coin_itr;
	}

	auto prop_itr = RoleCardController::getInstance()->propVec.begin();
	while (prop_itr != RoleCardController::getInstance()->propVec.end())
	{
		if ((*prop_itr)->state == PROPS_FREE)
		{
			(*prop_itr)->purge();
			RoleCardController::getInstance()->propVec.erase(prop_itr);
			continue;
			//这个free掉，后面继续
		}

		if (hero->state != ROLE_DEAD&&hero->state != ROLE_FREE && (*prop_itr)->type==SUPPLY_PACKAGE&&(*prop_itr)->isColliding(hero))
		{
			//__String * propStr = __String::createWithFormat("%d", 1);
			//hero->addCoinAmount(coinStr->getCString());
			//(*coin_itr)->addCoinAmount(1);
			if ((*prop_itr)->state == PROPS_COLLECTED)
			{
				break;
			}
			this->layer->setammunition(this->layer->getammunition() + 45);
			(*prop_itr)->state = PROPS_COLLECTED;
			break;//一次收集一个
		}

		if (hero->state != ROLE_DEAD&&hero->state != ROLE_FREE && (*prop_itr)->type == BLOOD_BAG && (*prop_itr)->isColliding(hero))
		{ 
			//__String * propStr = __String::createWithFormat("%d", 1);
			//hero->addCoinAmount(coinStr->getCString());
			//(*coin_itr)->addCoinAmount(1);
			if ((*prop_itr)->state == PROPS_COLLECTED)
			{
				break;
			}
			hero->propertymanager->setHP(hero->propertymanager->getHP() + 10);
			(*prop_itr)->state = PROPS_COLLECTED;
			break;//一次收集一个
		}
		++prop_itr;
	}

	if (hero->state != ROLE_FREE && hero->state != ROLE_DEAD)
	{
		auto playerPos = hero->getPosition();
		hero->getBaseFSM()->switchActionState(keyPressedDurationAcion());
		this->setPlayerPosition(playerPos);
	}

	this->setViewPointCenter(hero->getPosition());

	char str[100] = { '0' };
	sprintf(str, "%d", this->layer->getcoinNum());
	this->layer->pCoinNum->setString(str);
	this->layer->pCoinNum->setVisible(true);

	sprintf(str, "%d", this->layer->getammunition());
	this->layer->ammunitionNum->setString(str);
	this->layer->ammunitionNum->setVisible(true);
	
}

void GameLayer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	log("touch");
	if (this->layer->getammunition()==0)
	{
		return;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto pManager = propertyManager::create();
	pManager->setHitRect({ { -40,-40 },{ 80,80 } });
	pManager->setHitPoint(pManager->getHitRect().origin);
	pManager->setArmatureName("coin");
	pManager->setDataName("coin/coin.ExportJson");
	pManager->retain();

	auto projectile = Bullet::create(hero, pManager);
	RoleCardController::getInstance()->bulletVec.push_back(projectile);
	projectile->setPosition(hero->getPosition());

	projectile->state = BULLET_DEFAULT;

	this->addChild(projectile);

	auto realDest = Point(0, 0);

	if (hero->face == FACE_LEFT)
	{
		realDest = Point(projectile->getPositionX() - 300, projectile->getPositionY());
	}
	else if (hero->face == FACE_RIGHT)
	{
		realDest = Point(projectile->getPositionX() + 300, projectile->getPositionY());
	}
	else if (hero->face == FACE_UP)
	{
		realDest = Point(projectile->getPositionX(), projectile->getPositionY() + 300);
	}
	else if (hero->face == FACE_DOWN)
	{
		realDest = Point(projectile->getPositionX(), projectile->getPositionY() - 300);
	}

	log("check");
	projectile->runAction(
		Sequence::create(MoveTo::create(.3f, realDest),
			CallFuncN::create(CC_CALLBACK_1(GameLayer::spriteMoveFinished, this)),
			NULL));

	this->layer->setammunition(this->layer->getammunition() - 1);
}

void GameLayer::spriteMoveFinished(Object * pSender)
{
	Bullet * sprite = (Bullet *) pSender;
	//this->removeChild(sprite);
	sprite->state = BULLET_FREE;

}

void GameLayer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	log("touch");
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//auto touchPoint = touch->getLocation();
	//log("%f %f", touchPoint.x, touchPoint.y);
	//touchPoint = _tileMap-> convertToWorldSpace(touchPoint);
	//touchPoint = CCDirector::sharedDirector()->convertToGL(touchPoint);

	auto projectile = Sprite::create("Projectile.png", Rect(0, 0, 20, 20));
	projectile->setPosition(hero->getPosition());

	// Determine offset of location to projectile
	//int offX = touchPoint.x - projectile->getPosition().x;
	//int offY = touchPoint.y - projectile->getPosition().y;
	//log("%f %f", touchPoint.x, touchPoint.y);
	//log("%f %f", projectile->getPosition().x, projectile->getPosition().y);

	// Bail out if we are shooting down or backwards
	//if (offX <= 0) return;

	// Ok to add now - we've double checked position
	this->addChild(projectile);

	//auto point = CCDirector::sharedDirector()->convertToGL(projectile->getPosition());
	//log("%f %f", point.x, point.y);
	// Determine where we wish to shoot the projectile to
	//int realX = visibleSize.width + (projectile->getContentSize().width / 2);
	//float ratio = -(float)offY / (float)offX;
	//int realY = ((realX - point.x) * ratio) + point.y;
	auto realDest = Point(projectile->getPositionX()+100, projectile->getPositionY());

	// Determine the length of how far we're shooting
	//int offRealX = realX - point.x;
	//int offRealY = realY - point.y;
	//float length = sqrtf((offRealX*offRealX) + (offRealY*offRealY));
	//float velocity = 960 / 1; 	// 960pixels/1sec
	//float realMoveDuration = length / velocity;

	// Move projectile to actual endpoint
	projectile->runAction(
		Sequence::create(MoveTo::create(.5f, realDest),
			CallFuncN::create(CC_CALLBACK_1(GameLayer::spriteMoveFinished, this)),
			NULL));
}

void GameLayer::spriteMoveFinished(Object * pSender)
{
	Sprite * sprite = (Sprite *) pSender;
	this->removeChild(sprite);
}

bool GameLayer::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GameLayer::keyPressedDurationDirection()
{
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW,
		rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	if (isKeyPressed(leftArrow))
	{
		return FACE_LEFT;
	}
	else if (isKeyPressed(rightArrow))
	{
		return FACE_RIGHT;
	}
	else
	{
		return 0;
	}
}

int GameLayer::keyPressedDurationAcion()
{
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW,
		rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW,
		upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW,
		downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW,
		a = EventKeyboard::KeyCode::KEY_A,
		space = EventKeyboard::KeyCode::KEY_SPACE;
	if (isKeyPressed(a))
	{
		return ROLE_ATTACK;
	}
	//else if (isKeyPressed(space))
	//{
	//	return ROLE_JUMP;
	//}
	else if (isKeyPressed(leftArrow))
	{
		return FACE_LEFT;
	}
	else if (isKeyPressed(rightArrow))
	{
		return FACE_RIGHT;
	}
	else if (isKeyPressed(upArrow))
	{
		return FACE_UP;
	}
	else if (isKeyPressed(downArrow))
	{
		return FACE_DOWN;
	}

	return 0;
}

void GameLayer::setViewPointCenter(Point position)
{

	Size visibleSize = Director::getInstance()->getVisibleSize();
	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);
	x = MIN(x, (_tileMap->getMapSize().width * _tileMap->getTileSize().width)
		- visibleSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height)
		- visibleSize.height / 2);


	//屏幕中心点
	Point pointA = Point(visibleSize.width / 2, visibleSize.height / 2);
	//使精灵处于屏幕中心，移动地图目标位置
	Point pointB = Point(x, y);
	//log("目标位置 (%f ,%f) ", pointB.x, pointB.y);


	//地图移动偏移量
	Point offset = pointA - pointB;


	//log("offset (%f ,%f) ", offset.x, offset.y);
	this->setPosition(offset);
}

void GameLayer::purge()
{
	//释放还活着的，防止内存泄漏
	Director::getInstance()->getScheduler()->unschedule(schedule_selector(GameLayer::update), this);
	RoleCardController::getInstance()->purge();
	this->removeFromParent();
}

Point GameLayer::tileCoordForPosition(Point position)
{
	int x;
<<<<<<< HEAD
	if (hero->face == FACE_RIGHT)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
	}
	else
	{
		x = static_cast<int>((position.x - 40) / _tileMap->getTileSize().width);
	}
	
	int y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40)/ _tileMap->getTileSize().height);
=======
	int y;
	if (hero->face == FACE_RIGHT)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40) / _tileMap->getTileSize().height);
	}
	else if(hero->face == FACE_LEFT)
	{
		x = static_cast<int>((position.x - 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40) / _tileMap->getTileSize().height);
	}
	else if (hero->face == FACE_UP)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) - 40) / _tileMap->getTileSize().height);

	}
	else if (hero->face == FACE_DOWN)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
		y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40) / _tileMap->getTileSize().height);

	}
	
	
>>>>>>> leonnnop/master
	return Point(x, y);
}

void GameLayer::setPlayerPosition(Point position)
{
	Point tileCoord = this->tileCoordForPosition(hero->getPosition());
	int tileGid = _meta->getTileGIDAt(tileCoord);
	if (tileGid) 
	{
		auto properties = _tileMap->getPropertiesForGID(tileGid).asValueMap();
		if (!properties.empty()) 
		{
			auto collision = properties["Collidable"].asString();
			if ("True" == collision) 
			{
				hero->stopActionByTag(233);
				//position.y -= 5;
				hero->setPosition(position);
				//hero->getBaseFSM()->changeToDefault();

				return;
			}
		}
	}
	//hero->setPosition(position);
}
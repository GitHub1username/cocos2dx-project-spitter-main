#include "GameLayer.h"




GameLayer::GameLayer()
{
}


GameLayer::~GameLayer()
{
}

void GameLayer::onEnter()
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

	addChild(_tileMap, -1);

	TMXObjectGroup* group = _tileMap->getObjectGroup("Objects");
	ValueMap spawnPoint = group->getObject("SpawnPoint");

	_meta = _tileMap->getLayer("Meta");
	_meta->setVisible(true);

	float x = spawnPoint["x"].asFloat();
	float y = spawnPoint["y"].asFloat();

	this->onEnter();

	this->scheduleUpdate();
	//Director::getInstance()->getScheduler()->schedule(schedule_selector(ControlLayer::update), this, (float)1 / 60, false);
/*
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = true;
	};

	listener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		keys[keyCode] = false;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
*/
	propertyManager * pManager = propertyManager::create();
	pManager->setID(1);
	pManager->setATK(50);
	pManager->setHP(100);
	pManager->setArmatureName("NewHero");
	pManager->setDataName("NewHero/NewHero.ExportJson");
	pManager->setSPEED(2);//ǰ�������ٶ�Ӧ�ò�һ�£��д��޸�
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

	//ȱ��һ�������࣬����ճ����ʲô����

	propertyManager * pManager2 = propertyManager::create();
	pManager2->setID(2);
	pManager2->setATK(10);
	pManager2->setHP(100);
	pManager2->setArmatureName("enemy");
	pManager2->setDataName("enemy/enemy.ExportJson");
	pManager2->setSPEED(1);//ǰ�������ٶ�Ӧ�ò�һ�£��д��޸�
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
	pManager3->setSPEED(1);//ǰ�������ٶ�Ӧ�ò�һ�£��д��޸�
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

	propertyManager * pManager4 = propertyManager::create();
	pManager4->setHitRect({ { -40,-40 },{ 80,80 } });
	pManager4->setHitPoint(pManager4->getHitRect().origin);
	pManager4->setArmatureName("trap1");
	pManager4->setDataName("trap1/trap1.ExportJson");
	pManager4->retain();

	trap = BaseTrap::createWithProperty(pManager4, hero);
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

	coin = Coin::createWithProperty(pManager5, hero);
	//trap = static_cast<BaseTrap *>(Sprite::create("res/mushroom.png"));
	//trap->autorelease();
	//coin->init(pManager5, hero);
	coin->setPosition(Vec2(1000, 200));
	this->addChild(coin, 1, 1);

	RoleCardController::getInstance()->heroVec.push_back(hero);
	RoleCardController::getInstance()->setHeroID(hero->propertymanager->getID());
	RoleCardController::getInstance()->monsterVec.push_back(monster);
	RoleCardController::getInstance()->monsterVec.push_back(monster2);
	RoleCardController::getInstance()->trapVec.push_back(trap);
	RoleCardController::getInstance()->coinVec.push_back(coin);
	RoleCardController::getInstance()->retain();

	BaseFSM * basefsm = BaseFSM::createFSM(hero);
	basefsm->retain();
	hero->setBaseFSM(basefsm);

	BaseFSM * basefsm2 = BaseFSM::createFSM(monster);
	basefsm2->retain();
	monster->setBaseFSM(basefsm2);

	BaseFSM * basefsm3 = BaseFSM::createFSM(monster2);
	basefsm3->retain();
	monster2->setBaseFSM(basefsm3);

	BaseAI * ai2 = BaseAI::creatAI(monster);
	ai2->retain();
	monster->setBaseAI(ai2);

	BaseAI * ai = BaseAI::creatAI(monster2);
	ai->retain();
	monster2->setBaseAI(ai);

	ai2->startRoleAI();
	ai->startRoleAI();

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
		a = EventKeyboard::KeyCode::KEY_A;


	layer->progressView->setCurrentProgress((float)(hero->propertymanager->getHP()));


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
		//Ӯ����Ӧ��ת��ʤ�����棬����һ�����ݶ�ȡ���档
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
		//���ˣ�ת���������2333
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
			}
		}
		++trap_itr;
	}

	auto coin_itr = RoleCardController::getInstance()->coinVec.begin();
	while (coin_itr != RoleCardController::getInstance()->coinVec.end())
	{
		if (hero->state != ROLE_DEAD&&hero->state != ROLE_FREE && (*coin_itr)->isColliding(hero))
		{
			__String * coinStr = __String::createWithFormat("%d", 1);
			hero->addCoinAmount(coinStr->getCString());
			(*coin_itr)->addCoinAmount(1);
			(*coin_itr)->state = COIN_COLLECTED;
			RoleCardController::getInstance()->collectedVec.push_back(*coin_itr);
			RoleCardController::getInstance()->coinVec.erase(coin_itr);
			break;
		}
		++coin_itr;
	}

	auto collected_itr = RoleCardController::getInstance()->collectedVec.begin();
	while (collected_itr != RoleCardController::getInstance()->collectedVec.end())
	{
		if ((*collected_itr)->state == COIN_FREE)
		{
			(*collected_itr)->purge();
			RoleCardController::getInstance()->collectedVec.erase(collected_itr);
			break;
		}
		++collected_itr;
	}

	if (hero->state != ROLE_FREE && hero->state != ROLE_DEAD)
	{
		auto playerPos = hero->getPosition();
		hero->getBaseFSM()->switchActionState(keyPressedDurationAcion());
		this->setPlayerPosition(playerPos);
	}

	this->setViewPointCenter(hero->getPosition());
}

void GameLayer::onTouchEnded(cocos2d::Touch * touch, cocos2d::Event * event)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto touchPoint = touch->getLocation();

	auto projectile = Sprite::create("Projectile.png", Rect(0, 0, 20, 20));
	projectile->setPosition(hero->getPosition());

	// Determine offset of location to projectile
	int offX = touchPoint.x - projectile->getPosition().x;
	int offY = touchPoint.y - projectile->getPosition().y;

	// Bail out if we are shooting down or backwards
	if (offX <= 0) return;

	// Ok to add now - we've double checked position
	this->addChild(projectile);

	// Determine where we wish to shoot the projectile to
	int realX = visibleSize.width + (projectile->getContentSize().width / 2);
	float ratio = (float)offY / (float)offX;
	int realY = (realX * ratio) + projectile->getPosition().y;
	auto realDest = Point(realX, realY);

	// Determine the length of how far we're shooting
	int offRealX = realX - projectile->getPosition().x;
	int offRealY = realY - projectile->getPosition().y;
	float length = sqrtf((offRealX*offRealX) + (offRealY*offRealY));
	float velocity = 960 / 1; 	// 960pixels/1sec
	float realMoveDuration = length / velocity;

	// Move projectile to actual endpoint
	projectile->runAction(
		Sequence::create(MoveTo::create(realMoveDuration, realDest),
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
		a = EventKeyboard::KeyCode::KEY_A,
		space = EventKeyboard::KeyCode::KEY_SPACE;
	if (isKeyPressed(a))
	{
		return ROLE_ATTACK;
	}
	else if (isKeyPressed(space))
	{
		return ROLE_JUMP;
	}
	else if (isKeyPressed(leftArrow))
	{
		return FACE_LEFT;
	}
	else if (isKeyPressed(rightArrow))
	{
		return FACE_RIGHT;
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


	//��Ļ���ĵ�
	Point pointA = Point(visibleSize.width / 2, visibleSize.height / 2);
	//ʹ���鴦����Ļ���ģ��ƶ���ͼĿ��λ��
	Point pointB = Point(x, y);
	log("Ŀ��λ�� (%f ,%f) ", pointB.x, pointB.y);


	//��ͼ�ƶ�ƫ����
	Point offset = pointA - pointB;


	log("offset (%f ,%f) ", offset.x, offset.y);
	this->setPosition(offset);
}

void GameLayer::purge()
{
	//�ͷŻ����ŵģ���ֹ�ڴ�й©
	Director::getInstance()->getScheduler()->unschedule(schedule_selector(GameLayer::update), this);
	RoleCardController::getInstance()->purge();
	this->removeFromParent();
}

Point GameLayer::tileCoordForPosition(Point position)
{
	int x;
	if (hero->face == FACE_RIGHT)
	{
		x = static_cast<int>((position.x + 40) / _tileMap->getTileSize().width);
	}
	else
	{
		x = static_cast<int>((position.x - 40) / _tileMap->getTileSize().width);
	}
	
	int y = static_cast<int>((((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) + 40)/ _tileMap->getTileSize().height);
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
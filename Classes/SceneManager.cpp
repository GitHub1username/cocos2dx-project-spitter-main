#include "SceneManager.h"
#include "LoadLayer.h"
#include "OpenLayer.h"
#include "GameLayer.h"
#include "HelpLayer.h"
#include "ConditionLayer.h"



SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::createLoadScene()
{
	loadScene = Scene::create();
	LoadLayer * layer = LoadLayer::create();
	layer->tsm = this;
	loadScene->addChild(layer);
}
void SceneManager::goOpenScene()
{
	openScene = Scene::create();
	OpenLayer * layer = OpenLayer::create();
	layer->tsm = this;
	openScene->addChild(layer);
	Director::getInstance()->replaceScene(openScene);
}

void SceneManager::goGameScene()
{
	gameScene = Scene::create();
	//显示物理世界调试状态, 显示红色的框, 方便调试
	//gameScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	GameLayer * layer = GameLayer::create();
	layer->tsm = this;
	gameScene->addChild(layer);
	ConditionLayer * layer_condition = ConditionLayer::create();
	layer_condition->tsm = this;
	layer_condition->layer = layer;
	layer->layer = layer_condition;
	gameScene->addChild(layer_condition);
	Director::getInstance()->replaceScene(gameScene);
}

void SceneManager::goHelpScene()
{
	helpScene = Scene::create();
	//显示物理世界调试状态, 显示红色的框, 方便调试
	//gameScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	HelpLayer * layer = HelpLayer::create();
	layer->tsm = this;
	helpScene->addChild(layer);
	Director::getInstance()->replaceScene(helpScene);
}

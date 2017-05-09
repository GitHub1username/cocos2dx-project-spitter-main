#include "SceneManager.h"
#include "LoadLayer.h"
#include "OpenLayer.h"
#include "GameLayer.h"



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
	GameLayer * layer = GameLayer::create();
	layer->tsm = this;
	gameScene->addChild(layer);
	Director::getInstance()->replaceScene(gameScene);
}

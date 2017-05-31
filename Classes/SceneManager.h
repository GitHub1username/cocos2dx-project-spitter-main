#pragma once
#ifndef _SCENEMANAGER_
#define _SCENEMANAGER_

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();
	Scene * loadScene;
	Scene * openScene;
	Scene * gameScene;
	Scene * helpScene;

	void createLoadScene();
	void goOpenScene();
	void goGameScene();
	void goHelpScene();
};
#endif

#pragma once
#include "cocos2d.h"
#include "SceneManager.h"
#include "ProgressView.h"
#include "GameLayer.h"

USING_NS_CC;

class GameLayer;
class ConditionLayer : public Layer
{
public:
	ConditionLayer();
	virtual ~ConditionLayer();
public:
	CREATE_FUNC(ConditionLayer);
	virtual bool init();
	void menuCallBack(Ref * pSender);
public:
	SceneManager * tsm;

	ProgressView * progressView;

	GameLayer * layer;
};



#include "ProgressView.h"  

ProgressView::ProgressView()
	: progressBackground(NULL)
	, progressForeground(NULL)
	, totalProgress(0.0f)
	, currentProgress(0.0f)
	, scale(1.0f)
{

}
ProgressView * ProgressView::create()
{
	ProgressView * view = new ProgressView;
	if (view&&view->init())
	{
		view->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(view);
		return nullptr;
	}
	return view;
}
bool ProgressView::init()
{
	this->setBackgroundTexture("res/xue_back.png");
	this->setForegroundTexture("res/xue_fore.png");
	this->setTotalProgress(100.0f);
	this->setCurrentProgress(100.0f);

	return true;
}
void ProgressView::setBackgroundTexture(const char *pName)
{
	progressBackground = CCSprite::create(pName);
	this->addChild(progressBackground);
}

void ProgressView::setForegroundTexture(const char *pName)
{
	progressForeground = CCSprite::create(pName);
	progressForeground->setAnchorPoint(ccp(0.0f, 0.5f));//设置锚点  
	progressForeground->setPosition(ccp(-progressForeground->getContentSize().width * 0.5f, 0));
	this->addChild(progressForeground);
}

void ProgressView::setTotalProgress(float total)
{
	if (progressForeground == NULL) { return; }
	scale = progressForeground->getContentSize().width / total;
	totalProgress = total;
}

void ProgressView::setCurrentProgress(float progress)
{
	if (progressForeground == NULL) { return; }
	if (progress < 0.0f) { progress = 0.0f; }
	if (progress > totalProgress) { progress = totalProgress; }
	currentProgress = progress;
	float rectWidth = progress * scale;
	const CCPoint from = progressForeground->getTextureRect().origin;
	const CCRect rect = CCRectMake(from.x, from.y, rectWidth, progressForeground->getContentSize().height);
	setForegroundTextureRect(rect);
}

void ProgressView::setForegroundTextureRect(const CCRect &rect)
{
	progressForeground->setTextureRect(rect);
}



float ProgressView::getCurrentProgress() const
{
	return currentProgress;
}

float ProgressView::getTotalProgress() const
{
	return totalProgress;
}
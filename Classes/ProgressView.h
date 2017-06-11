
#ifndef __PROGRESSVIEW_H__  
#define __PROGRESSVIEW_H__  

#include "cocos2d.h"  
USING_NS_CC;

class ProgressView : public Node
{
public:
	ProgressView();

public:
	static ProgressView * create();
	bool init();
	//����Ѫ������  
	void setBackgroundTexture(const char *pName);
	//����Ѫ��ǰ��  
	void setForegroundTexture(const char *pName);
	//������Ѫ��  
	void setTotalProgress(float total);
	//���õ�ǰѪ��  
	void setCurrentProgress(float progress);
	//�õ���ǰѪ��  
	float getCurrentProgress() const;
	//�õ���Ѫ��  
	float getTotalProgress() const;

private:
	//����ǰ��Ѫ����ʾ�ĳ���  
	void setForegroundTextureRect(const CCRect &rect);

private:
	CCSprite *progressBackground;//����Ѫ��  
	CCSprite *progressForeground;//ǰ��Ѫ��  
	float totalProgress;//��Ѫ��  
	float currentProgress;//��ǰѪ��  
	float scale;//�Ŵ���  
};

#endif  


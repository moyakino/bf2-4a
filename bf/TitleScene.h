#pragma once
#include "AbstractScene.h"

class Title :public AbstractScene
{
private:
	int g_TitleImage = 0;
	int g_TitleImage2 = 0;
	int g_TitleImage3 = 0;
public:
	
	//�R���X�g���N�^
	Title();

	//�f�X�g���N�^
	virtual ~Title();

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

};
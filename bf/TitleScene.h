#pragma once
#include "AbstractScene.h"

//���D�J�[�\���A�j���[�V����
#define CURSOR_BALLOON2_0 0
#define CURSOR_BALLOON2_1 1
#define CURSOR_BALLOON2_2 2
#define CURSOR_BALLOON2_3 3

class Title :public AbstractScene
{
private:

	//���D�J�[�\���摜 �����ǂݍ��ݗp�ϐ�
	int	T_CursorImg[4];
	int T_BalloonImg;
	int i;

	int	g_MenuNumber;		// ���j���[�J�[�\���ʒu
	int g_MenuY;				// ���j���[�J�[�\���̂x���W

	int g_TitleImage1;
	int g_TitleImage2;
	int g_TitleImage3;

	//FPS�ƕb���J�E���g
	int	T_FPS;
	int	T_Seconas1;

	int Select;

public:
	
	//�R���X�g���N�^
	Title();

	//�f�X�g���N�^
	virtual ~Title();

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update()override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;

	int Cursor_Anim();

};
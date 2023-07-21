#include"DxLib.h"
#include "Thunder.h"
#include"GameMain.h"

Thunder::Thunder()
{
	//��(���)�摜�f�[�^�̕����ǂݍ���
	if (LoadDivGraph("images/Stage/Stage_ThunderAnimation.png", 6, 6, 1, 64, 64, ThunderImg)) {}

	//��(���̒e)�摜�f�[�^�̕����ǂݍ���
	if (LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, EffectImg)) {}

	ThunderImg[6];
	T_Img = 0;

	EffectImg[3];
	E_Img = 0;

	S_FPS = 0;
	S_Seconas1 = 0;
}

Thunder::~Thunder()
{

}

void Thunder::Update()
{
	if (S_FPS > 29) {
		S_FPS = 0;
		S_Seconas1++;
	}// P_FPS_INC �� �b��������Ă���
	else if (S_Seconas1 > 3) {
		S_Seconas1 = 0;
	}

	T_Img = Thunder_Anim();
	E_Img = Effect_Anim();
}

int Thunder::Thunder_Anim()
{
	int C_AnimImg = 0;

	// 0 ���� 3 �b
	if (S_Seconas1 == 0) {
		C_AnimImg = ThunderImg[THUNDER_ANIM1_0];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		C_AnimImg = ThunderImg[THUNDER_ANIM1_1];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		C_AnimImg = ThunderImg[THUNDER_ANIM1_2];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		C_AnimImg = ThunderImg[THUNDER_ANIM1_3];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		C_AnimImg = ThunderImg[THUNDER_ANIM1_4];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		C_AnimImg = ThunderImg[THUNDER_ANIM1_5];
	}
	

	return C_AnimImg;
}

int Thunder::Effect_Anim()
{
	int E_AnimImg = 0;

	// 0 ���� 3 �b
	if (S_Seconas1 == 0) {
		E_AnimImg = EffectImg[THUNDER_EFFECT_ANIM1_0];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		E_AnimImg = EffectImg[THUNDER_EFFECT_ANIM1_1];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		E_AnimImg = EffectImg[THUNDER_EFFECT_ANIM1_2];
	}

	return E_AnimImg;
}

void Thunder::Draw() const
{
	//���j���[�J�[�\���i���D�j�̕\��
	DrawGraph(400, 100, T_Img, TRUE);
	
	//���j���[�J�[�\���i���D�j�̕\��
	DrawGraph(400, 200, E_Img, TRUE);
}
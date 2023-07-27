#include"DxLib.h"
#include "Thunder.h"
#include"GameMain.h"
#include <corecrt_math_defines.h>
#include <corecrt_math.h>

Thunder::Thunder()
{
	//�_�摜�f�[�^�̓ǂݍ���
	if ((CloudImg = LoadGraph("images/Stage/Stage_Cloud01.png")) == -1);
	if (LoadDivGraph("images/Stage/Stage_CloudAnimation.png", 3, 3, 1,64, 64, Cloud_AnimImg)) {}

	//��(���)�摜�f�[�^�̕����ǂݍ���
	if (LoadDivGraph("images/Stage/Stage_ThunderAnimation.png", 6, 6, 1, 64, 64, ThunderImg)) {}
	//��(���̒e)�摜�f�[�^�̕����ǂݍ���
	if (LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, EffectImg)) {}

	ThunderImg[6];
	T_Img = 0;

	EffectImg[3];
	E_Img = 0;

	S_FPS1 = 0;
	S_FPS2 = 0;
	S_Seconas1 = 0;
	S_Seconas2 = 0;

	// �ϐ��̏����ݒ�
	BallX = 300;
	BallY = 200;
}

Thunder::~Thunder()
{

}

void Thunder::Update()
{
	S_FPS1++;
	S_FPS2++;

	//��(���)��FPS
	if (S_FPS1 > 14) {
		S_FPS1 = 0;
		S_Seconas1++;
	}// P_FPS_INC �� �b��������Ă���
	else if (S_Seconas1 > 6) {
		S_Seconas1 = 0;
	}

	//��(���̒e)��FPS
	if (S_FPS2 > 29) {
		S_FPS2 = 0;
		S_Seconas2++;
	}// P_FPS_INC �� �b��������Ă���
	else if (S_Seconas2 > 3) {
		S_Seconas2 = 0;
	}

	if (BallFlg != 2) {
		BallX += MoveX;
		BallY += MoveY;
	}

	// �ǁE�V��ł̔���
	if (BallX < 4 || BallX > 640 - 4) { // ���̕�
		if (BallX < 4) {
			BallX = 4;
		}
		else {
			BallX = 640 - 4;
		}
		BallAngle = (1 - BallAngle) + 0.5f;
		if (BallAngle > 1) BallAngle -= 1.0f;
		ChangeAngle();
	}
	if (BallY < 8) { // ��̕�
		BallAngle = (1 - BallAngle);
		ChangeAngle();

	}

	// �}�E�X���N���b�N�ŃQ�[���X�^�[�g
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		&& BallFlg == 2) {

		BallFlg = 0;
		// �X�s�[�h�ƃA���O���ɂ��ړ��ʌv�Z
		Speed = 3;
		BallAngle = 0.625f;
		ChangeAngle();
	}

	//if (BallY > 480 + 4) {
	//	// �{�[�����X�^�[�g��Ԃɂ���
	//	BallFlg = 2;
	//	if (--RestBall <= 0) {
	//		if (g_Score >= g_Ranking[9].score) {
	//			g_GameState = 7;  //�����L���O���͏�����
	//		}
	//		else {
	//			g_GameState = 5;  //�Q�[���I�[�o�[������
	//		}
	//	}
	//}

	T_Img = Thunder_Anim();
	E_Img = Effect_Anim();
	C_Img = Cloud_Anim();
}

void Thunder::ChangeAngle() 
{
	float rad = BallAngle * (float)M_PI * 2;
	MoveX = (int)(Speed * cosf(rad));
	MoveY = (int)(Speed * sinf(rad));
}

int Thunder::Thunder_Anim()
{
	int T_AnimImg = 0;

	// 0 ���� 5 �b
	if (S_Seconas1 == 0) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_0];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_1];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_2];
	}
	else if (S_Seconas1 > 2 && S_Seconas1 < 4) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_3];
	}
	else if (S_Seconas1 > 3 && S_Seconas1 < 5) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_4];
	}
	else if (S_Seconas1 > 4 && S_Seconas1 < 6) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_5];
	}
	

	return T_AnimImg;
}

int Thunder::Effect_Anim()
{
	int E_AnimImg = 0;

	// 0 ���� 3 �b
	if (S_Seconas1 == 0) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_0];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_1];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_2];
	}

	return E_AnimImg;
}

int Thunder::Cloud_Anim()
{
	int C_AnimImg = 0;

	// 0 ���� 3 �b
	if (S_Seconas2 == 0) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_0];
	}
	else if (S_Seconas2 > 0 && S_Seconas1 < 2) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_1];
	}
	else if (S_Seconas2 > 1 && S_Seconas1 < 3) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_2];
	}

	return C_AnimImg;
}

void Thunder::Draw() const
{
	//���j���[�J�[�\���i���D�j�̕\��
	DrawGraph(400, 100, T_Img, TRUE);
	
	//���j���[�J�[�\���i���D�j�̕\��
	DrawGraph(BallX, BallY, E_Img, TRUE);

	//
	DrawGraph(320, 90, CloudImg, TRUE);
	DrawGraph(500, 90, C_Img, TRUE);
}
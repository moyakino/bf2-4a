#include"DxLib.h"
#include "Thunder.h"
#include"GameMain.h"
#include <math.h>

Thunder::Thunder()
{
	//�_�摜�f�[�^�̓ǂݍ���
	if ((CloudImg = LoadGraph("images/Stage/Stage_Cloud01.png")) == -1){}
	if (LoadDivGraph("images/Stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, Cloud_AnimImg)) {}

	//��(���)�摜�f�[�^�̕����ǂݍ���
	if (LoadDivGraph("images/Stage/Stage_ThunderAnimation.png", 6, 6, 1, 64, 64, ThunderImg)) {}
	//��(���̒e)�摜�f�[�^�̕����ǂݍ���
	if (LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, EffectImg)) {}

	T_Img = 0;
	E_Img = 0;
	C_Img = 0;

	S_FPS1 = 0;
	S_FPS2 = 0;

	S_Seconas1 = 0;
	S_Seconas2 = 0;

	// �ϐ��̏����ݒ�
	BallX = 280;
	BallY = 200 - 5;

	BallFlg = 0;
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

	T_Img = Thunder_Anim();
	E_Img = Effect_Anim();
	C_Img = Cloud_Anim();

}


// //�{�[���̈ړ�����
void Thunder::MoveBall()
{
	// �}�E�X���N���b�N�ŃQ�[���X�^�[�g
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) && BallFlg == 2)
	{
		BallFlg = 0;
		// �X�s�[�h�ƃA���O���ɂ��ړ��ʌv�Z
		Speed = 5;
		BallAngle = 0.625f;
		ChangeAngle();
	}

	//�{�[���̈ړ�����
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
	if (BallY > 480 + 4) {
		//�{�[�����X�^�[�g��Ԃɂ���
		BallFlg = 2;
	}

	ChangeAngle();
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

	if (S_FPS2 % 20 == 0 || S_FPS2 % 20 == 1 || S_FPS2 % 20 == 2 || S_FPS2 % 20 == 3 || S_FPS2 % 20 == 4) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_0];
	}
	else if (S_FPS2 % 20 == 5 || S_FPS2 % 20 == 6 || S_FPS2 % 20 == 7 || S_FPS2 % 20 == 8 || S_FPS2 % 20 == 9) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_1];
	}
	else if (S_FPS2 % 20 == 10 || S_FPS2 % 20 == 11 || S_FPS2 % 20 == 12 || S_FPS2 % 20 == 13 || S_FPS2 % 20 == 14) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_2];
	}

	return E_AnimImg;
}

int Thunder::Cloud_Anim()
{
	int C_AnimImg = 0;

	// 5�t���[��
	if (S_FPS2 % 20 == 0 || S_FPS2 % 20 == 1 || S_FPS2 % 20 == 2 || S_FPS2 % 20 == 3 || S_FPS2 % 20 == 4) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_0];
	}
	else if (S_FPS2 % 20 == 5 || S_FPS2 % 20 == 6 || S_FPS2 % 20 == 7 || S_FPS2 % 20 == 8 || S_FPS2 % 20 == 9) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_1];
	}
	else if (S_FPS2 % 20 == 10 || S_FPS2 % 20 == 11 || S_FPS2 % 20 == 12 || S_FPS2 % 20 == 13 || S_FPS2 % 20 == 14) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_2];
	}

	return C_AnimImg;
}

void Thunder::HitThunder()
{
	int Delete = 0;

	DrawFormatString(0, 360, GetColor(255, 255, 255), "Delete:%d", Delete);
	if (PLAYER::px1 < MoveX - 15 && PLAYER::py1 < MoveY - 15 && MoveX - 15 < PLAYER::px2 && MoveY + 15 < PLAYER::py2 && Delete == 0) {
		H_flg = 1;
		if (H_flg == 1) {
			DeleteGraph(E_Img);
			DrawFormatString(MoveX, MoveY, GetColor(255, 0, 0), "Hit");
			Delete++;
		}
	}
	else {
		H_flg = 0;
	}
}

void Thunder::Draw() const
{
	//���i����j�̕\��
	DrawGraph(280, 145, T_Img, TRUE);
	
	//���i���̒e�j�̕\��
	DrawGraph(BallX, BallY, E_Img, TRUE);

	DrawCircle(BallX, BallY, 5, 0xffffff, TRUE);

	//
	DrawGraph(310, 90, CloudImg, TRUE);
	DrawGraph(285, 90, C_Img, TRUE);

	DrawFormatString(0, 340, GetColor(255, 255, 255), "H_flg:%d", H_flg);
}
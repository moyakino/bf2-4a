#include "DxLib.h"
#include "FPS.h"
#include "Player.h"
#include "PadInput.h"

Fps fps;

Player::Player()
{
	//�v���C���[�摜�f�[�^�̓ǂݍ���
	if (D_PlayerImg[0] = LoadGraph("images/REDApple.png")) {}

	if (LoadDivGraph("images/Player/Player_animation_d.png", 32, 8, 4, 64, 64, P_PlayerImg));
	//if (D_PlayerImg[1] = LoadGraph("images/GOLDApple.png")) {}
	//if (D_PlayerImg[2] = LoadGraph("images/BLUEApple.png")) {}
	P_Move_X = 200;
	P_Move_Y = 400;
	P_MoveR_Flg = FALSE;
	P_MoveL_Flg = FALSE;
	P_Img = 0;

}

void Player::Update()
{
	//�E�ړ�
	if (32768 > PAD_INPUT::GetLStickX() && PAD_INPUT::GetLStickX() > 128 || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) == 1)  {
		P_Move_X += 2;
		P_MoveR_Flg = TRUE;
		P_Img = Player::Animation(P_MoveR_Flg, P_MoveL_Flg);
	}else {
		P_MoveR_Flg = FALSE;
		P_Img = Player::Animation(P_MoveR_Flg, P_MoveL_Flg);
	}

	//XINPUT_BUTTON_DPAD_LEFT

	//���ړ�
	if (-32769 < PAD_INPUT::GetLStickX() && PAD_INPUT::GetLStickX() < 128 || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) == 1) {
		P_Move_X -= 2;
		P_MoveL_Flg = TRUE;
		P_Img = Player::Animation(P_MoveR_Flg, P_MoveL_Flg);
	}else {
		P_MoveL_Flg = FALSE;
		P_Img = Player::Animation(P_MoveR_Flg, P_MoveL_Flg);
	}

	//����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) == 1) {
		P_Move_Y -= 70;
	}

	// A�{�^����������Ă��Ȃ��� Y���W 400�܂ō~��
	if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A) == 0 && P_Move_Y <= 400) {
		P_Move_Y++;
	}
}

int Player::Animation(int Anim1, int Anim2)
{
	int AnimImg = 0;

	if (Anim1 == FALSE && Anim2 == FALSE) {
		AnimImg = D_PlayerImg[0];
	}
	else if (Anim1 == TRUE) {
		AnimImg = D_PlayerImg[1];
	}
	else if (Anim2 == TRUE) {
		AnimImg = D_PlayerImg[2];
	}

	return AnimImg;
}

//int Stand_by_Anim()
//{
//
//}

int Player::R_Player_MoveX()const
{
	return P_Move_X;
}

int Player::R_Player_MoveY()const
{
	return P_Move_Y;
}

void Player::Draw()const
{
	//A�{�^���`��
	DrawFormatString(0, 100, GetColor(255, 0, 0), " �����ꂽ�u�ԁF%d �����ꂽ�u�ԁF%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

	DrawFormatString(0, 150, GetColor(255, 0, 0), " ���X�e�B�b�N�FX���W %d Y���W %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

	DrawFormatString(0, 200, GetColor(255, 0, 0), " �ړ��t���O�F���ړ� %d �E�ړ� %d", P_MoveL_Flg, P_MoveR_Flg);

	//DrawFormatString(300, 200, GetColor(255, 0, 0), " FPS�F%.1f",fps.R_Fps());

	DrawRotaGraph(P_Move_X, P_Move_Y, 1, 0, P_PlayerImg[0], TRUE);
}

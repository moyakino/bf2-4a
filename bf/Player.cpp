#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"

Player::Player()
{
	//�^�C�g���摜�f�[�^�̓ǂݍ���
	if ((D_PlayerImg = LoadGraph("images/REDApple.png")) == -1);
	//L_Stick_X = PAD_INPUT::GetLStickX();
	//L_Stick_Y = PAD_INPUT::GetLStickY();
	P_Move_X = 200;
	P_Move_Y = 400;
}

void Player::Update()
{
	if (32768 > PAD_INPUT::GetLStickX() && PAD_INPUT::GetLStickX() > 128) {
		P_Move_X += 2;
	}

	if (-32769 < PAD_INPUT::GetLStickX() && PAD_INPUT::GetLStickX() < 128) {
		P_Move_X -= 2;
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) == 1) {
		P_Move_Y -= 70;
	}

	if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A) == 0 && P_Move_Y <= 400) {
		P_Move_Y++;
	}
}

void Player::Draw()const
{
	//A�{�^���`��
	DrawFormatString(0, 100, GetColor(255, 0, 0), " �����ꂽ�u�ԁF%d �����ꂽ�u�ԁF%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

	DrawFormatString(0, 150, GetColor(255, 0, 0), " ���X�e�B�b�N�FX���W %d Y���W %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

	DrawRotaGraph(P_Move_X, P_Move_Y, 0.10, 0, D_PlayerImg, TRUE);
}

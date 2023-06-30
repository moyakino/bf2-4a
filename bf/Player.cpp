#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"

Player::Player()
{
	//タイトル画像データの読み込み
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
	//Aボタン描画
	DrawFormatString(0, 100, GetColor(255, 0, 0), " 押された瞬間：%d 離された瞬間：%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

	DrawFormatString(0, 150, GetColor(255, 0, 0), " 左スティック：X座標 %d Y座標 %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

	DrawRotaGraph(P_Move_X, P_Move_Y, 0.10, 0, D_PlayerImg, TRUE);
}

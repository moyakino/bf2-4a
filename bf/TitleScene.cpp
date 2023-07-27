#include "DxLib.h"
#include "PadInput.h"
#include "TitleScene.h"
#include "GameMain.h"

Title::Title()
{
	//メニューカーソル画像データの読み込み
	if (LoadDivGraph("images/Title/Title_CursorAnimation.png", 4, 4, 1, 32, 64, T_CursorImg)) {}

	if ((g_TitleImage1 = LoadGraph("images/Title/Title_Logo.png"))){}
	if ((g_TitleImage2 = LoadGraph("images/Title/Title_ModeSelect.png"))){}
	if ((g_TitleImage3 = LoadGraph("images/Title/Title_Credit.png"))){}

	T_FPS = 0;
	T_Seconas1 = 0;
	i = 0;
	T_BalloonImg = 0;
	g_MenuNumber = 0;
	g_MenuY = 0;
}

Title::~Title()
{

}

//入力側を書く
AbstractScene* Title::Update()
{
	T_FPS++;

	if (CheckHitKey(KEY_INPUT_0) || PAD_INPUT::OnButton(XINPUT_BUTTON_START) == 1) {
		return new GameMain();
	}

	T_BalloonImg = Cursor_Anim();

	if (T_FPS > 30) {
		T_FPS = 0;
		T_Seconas1++;
	}// P_FPS_INC は 秒数を取っている
	else if (T_Seconas1 > 3) {
		T_Seconas1 = 0;
	}

	//十字キー↑入力
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
		{
			g_MenuNumber--;
			if (g_MenuNumber < 0)g_MenuNumber = 3;
		}
		//十字キー↓入力
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
		{
			g_MenuNumber++;
			if (g_MenuNumber > 3)g_MenuNumber = 0;
		}

		//メニューカーソル（三角形）の表示
		g_MenuY = g_MenuNumber * 31;

	return this;
}

int Title::Cursor_Anim()
{
	int C_AnimImg = 0;

	// 0 から 3 秒
	if (T_Seconas1 == 0) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_0];
	}
	else if (T_Seconas1 > 0 && T_Seconas1 < 2) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_1];
	}
	else if (T_Seconas1 > 1 && T_Seconas1 < 3) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_2];
	}
	else if (T_Seconas1 > 2 && T_Seconas1 < 4) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_3];
	}
	else if (T_Seconas1 > 3) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_3];
	}
	else if (T_Seconas1 > 4) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_2];
	}
	else if (T_Seconas1 > 5) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_1];
	}
	else if (T_Seconas1 > 6) {
		C_AnimImg = T_CursorImg[CURSOR_BALLOON2_0];
	}

	return C_AnimImg;
}

void Title::Draw()const
{
	//メニューカーソル（風船）の表示
	DrawGraph(100, g_MenuY + 280, T_BalloonImg, TRUE);

	DrawGraph(25, 0, g_TitleImage1, TRUE);
	DrawGraph(150, 300, g_TitleImage2, TRUE);
	DrawGraph(150, 450, g_TitleImage3, TRUE);
	
}
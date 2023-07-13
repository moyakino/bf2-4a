#include "DxLib.h"
#include "PadInput.h"
#include "TitleScene.h"
#include "GameMain.h"

//入力側を書く
AbstractScene* Title::Update()
{
	if (CheckHitKey(KEY_INPUT_0) || PAD_INPUT::OnButton(XINPUT_BUTTON_START) == 1) {
		return new GameMain();
	}

	return this;
}

Title::Title()
{
	if ((g_TitleImage = LoadGraph("images/Title/Title_Logo.png"))){}
	if ((g_TitleImage2 = LoadGraph("images/Title/Title_ModeSelect.png"))){}
	if ((g_TitleImage3 = LoadGraph("images/Title/Title_Credit.png"))){}
}

Title::~Title()
{

}

void Title::Draw()const
{
	
	DrawGraph(25, 0, g_TitleImage, TRUE);
	DrawGraph(150, 300, g_TitleImage2, TRUE);
	DrawGraph(150, 450, g_TitleImage3, TRUE);
	DrawFormatString(0, 50, GetColor(255, 0, 0), "Title");
	
}
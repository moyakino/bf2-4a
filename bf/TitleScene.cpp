#include "DxLib.h"
#include "PadInput.h"
#include "TitleScene.h"
#include "GameMain.h"

//ì¸óÕë§ÇèëÇ≠
AbstractScene* Title::Update()
{
	if (CheckHitKey(KEY_INPUT_0) || PAD_INPUT::OnButton(XINPUT_BUTTON_START) == 1) {
		return new GameMain();
	}

	return this;
}

Title::Title()
{
	if ((g_TitleImage = LoadGraph("images/Title/Title_Logo.png")) == -1);
	if ((g_TitleImage2 = LoadGraph("images/Title/Title_ModeSelect.png")) == -1);

}

Title::~Title()
{

}

void Title::Draw()const
{
	
	DrawGraph(25, 0, g_TitleImage, TRUE);
	DrawGraph(150, 300, g_TitleImage2, TRUE);
	DrawFormatString(0, 50, GetColor(255, 0, 0), "Title");
	
}
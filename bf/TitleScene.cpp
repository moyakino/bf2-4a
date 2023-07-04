#include "DxLib.h"
#include "PadInput.h"
#include "TitleScene.h"
#include "GameMain.h"

//“ü—Í‘¤‚ğ‘‚­
AbstractScene* Title::Update()
{
	if (CheckHitKey(KEY_INPUT_0) || PAD_INPUT::OnButton(XINPUT_BUTTON_A) == 1) {
		return new GameMain();
	}

	return this;
}

void Title::Draw()const
{
	DrawFormatString(0, 50, GetColor(255, 0, 0), "Title");
}
#include "DxLib.h"
#include "PadInput.h"
#include "TitleScene.h"
#include "GameMain.h"

//入力側を書く
AbstractScene* Title::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return new GameMain();
	}
	return this;
}

void Title::Draw()const
{
	DrawString(0, 20, "title",0xffffff);
}
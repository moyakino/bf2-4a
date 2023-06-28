#include "DxLib.h"
#include "TitleScene.h"
#include "GameMain.h"

//入力側を書く
AbstractScene* Title::Update()
{
	if (CheckHitKey(KEY_INPUT_0)) {
		return new GameMain();
	}

	return this;
}

void Title::Draw()const
{
	DrawFormatString(0, 50, GetColor(255, 0, 0), "Title");
}
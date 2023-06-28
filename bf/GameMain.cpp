#include"DxLib.h"
#include"FPS.h"
#include"GameMain.h"


AbstractScene* GameMain::Update()
{


	return this;
}


void GameMain::Draw()const
{
	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
}
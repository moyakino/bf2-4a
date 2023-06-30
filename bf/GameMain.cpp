#include"DxLib.h"
#include"GameMain.h"


//コンストラクタ
GameMain::GameMain()
{
	player = new Player();
}

AbstractScene* GameMain::Update()
{

	player->Update();

	return this;
}


void GameMain::Draw()const
{
	player->Draw();

	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
}
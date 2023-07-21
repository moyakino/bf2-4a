#include"DxLib.h"
#include"GameMain.h"


//コンストラクタ
GameMain::GameMain()
{


	Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);

	player = new PLAYER();
	bubble = new Bubble();
	stage = new Stage();
	thunder = new Thunder();
}

GameMain::~GameMain()
{
	delete stage;
	delete player;
	delete bubble;
	delete thunder;

}


AbstractScene* GameMain::Update()
{
	stage->Update();
	player->Update();
	bubble->Update();
	thunder->Update();


	return this;
}


void GameMain::Draw()const
{

	stage->Draw();

	player->Draw();

	bubble->Draw();

	thunder->Draw();


	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
	
}
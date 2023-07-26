#include"DxLib.h"
#include"GameMain.h"


//コンストラクタ
GameMain::GameMain()
{
	Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);

	//player = new PLAYER();
	bubble = new Bubble();
	stage = new Stage();
	testP = new testPlayer();
}

GameMain::~GameMain()
{
	delete stage;
	//delete player;
	delete bubble;

	delete testP;

}


AbstractScene* GameMain::Update()
{
	stage->Update();

	testP->Update();

	//player->Update();
	bubble->Update();

	return this;
}


void GameMain::Draw()const
{
	stage->Draw();


	testP->Draw();

	//player->Draw();

	bubble->Draw();




	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
	
}
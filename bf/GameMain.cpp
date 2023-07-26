#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"
#include "testPlayer.h"


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
	//player->Update();
	bubble->Update();

	testP->Update();

	return this;
}


void GameMain::Draw()const
{

	stage->Draw();

	//player->Draw();

	bubble->Draw();

	testP->Draw();

	//DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
	
}
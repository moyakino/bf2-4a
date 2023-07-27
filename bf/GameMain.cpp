#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"
#include "testPlayer.h"


//コンストラクタ
GameMain::GameMain()
{


	/*Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);*/

	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	enemybird = new EnemyBird();
	//bubble = new Bubble();
	stage = new Stage();
	thunder = new Thunder();
}

GameMain::~GameMain()
{
	delete stage;
	delete player;
	delete bubble;
	delete thunder;
	delete fish;
	delete enemybird;
	//delete bubble;


}


AbstractScene* GameMain::Update()
{
	stage->Update();
	player->Update();
	bubble->Update();
	fish->Update();
	//enemybird->Update(player->GetLocationX(), player->GetLocationY());
	bubble->Update();
	thunder->Update();

	//bubble->Update();

	return this;
}


void GameMain::Draw()const
{

	/*画像の描画*/
	
	//空中の足場
	//DrawGraph(180, 280, StageFoot[0],TRUE);

	//地面と海
	//DrawGraph(0, 416, StageLand_L, TRUE);
	//DrawGraph(480, 416, StageLand_R, TRUE);
	//DrawGraph(160,444,StageSea,TRUE);

	stage->Draw();
	player->Draw();
	fish->Draw();
	//enemybird->Draw();

	//bubble->Draw();


	thunder->Draw();


	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
	
}
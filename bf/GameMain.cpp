#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"
#include "testPlayer.h"


//コンストラクタ
GameMain::GameMain()
{


	/*Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);*/
	ui = new UI();
	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	//enemybird = new EnemyBird();
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
	delete ui;
	//delete enemybird;


}


AbstractScene* GameMain::Update()
{
	stage->Update();
	player->Update();
	//enemybird->Update(PLAYER::P_Move_X, PLAYER::P_Move_Y);
	bubble->Update();
	fish->Update();
	//enemybird->Update(player->GetLocationX(), player->GetLocationY());
	thunder->Update();

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
	
	//enemybird->Draw();
	//enemybird->Draw();
	bubble->Draw();
	ui->Draw();
	thunder->Draw();
	player->Draw();
	
	
}
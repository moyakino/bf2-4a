#include"DxLib.h"
#include"GameMain.h"


//コンストラクタ
GameMain::GameMain()
{


	Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);

	player = new PLAYER();
	enemybird = new EnemyBird();
	bubble = new Bubble();
	stage = new Stage();
}

GameMain::~GameMain()
{
	delete stage;
	delete player;
	delete enemybird;
	delete bubble;

}


AbstractScene* GameMain::Update()
{
	stage->Update();
	player->Update();
	enemybird->Update(player->GetLocationX(), player->GetLocationY());
	bubble->Update();


	return this;
}


void GameMain::Draw()const
{

	stage->Draw();

	player->Draw();
	enemybird->Draw();

	bubble->Draw();

	//DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
	
}
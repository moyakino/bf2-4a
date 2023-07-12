#include"DxLib.h"
#include"GameMain.h"


//コンストラクタ
GameMain::GameMain()
{
	/*画像の読み込み*/
	//空中の足場
	if ((StageFoot[0] = LoadGraph("images/Stage/Stage_Footing01.png")) == -1){}
	//地面(左)
	if ((StageLand_L = LoadGraph("images/Stage/Stage_Land_Left01.png")) == -1){}
	//地面(右)
	if ((StageLand_R = LoadGraph("images/Stage/Stage_Land_Right01.png")) == -1){}
	//海
	if ((StageSea = LoadGraph("images/Stage/Stage_Sea01.png")) == -1){}

	player = new PLAYER();
	bubble = new Bubble();
}

GameMain::~GameMain()
{
	delete player;
	delete bubble;
}


AbstractScene* GameMain::Update()
{

	player->Update();
	bubble->Update();

	return this;
}


void GameMain::Draw()const
{

	//当たり判定の仮表示

	//空中の足場
	DrawBox(180, 280, 460, 297, 0x00ff00,FALSE);

	//地面
	DrawBox(0,416,160,480,0x00ff00,FALSE);	//左
	DrawBox(480, 416, 640, 480, 0x00ff00, FALSE);	//右

	//海
	DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);



	/*画像の描画*/
	
	//空中の足場
	//DrawGraph(180, 280, StageFoot[0],TRUE);

	//地面と海
	//DrawGraph(0, 416, StageLand_L, TRUE);
	//DrawGraph(480, 416, StageLand_R, TRUE);
	//DrawGraph(160,444,StageSea,TRUE);

	player->Draw();

	bubble->Draw();

	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
}
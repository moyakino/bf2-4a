#include"DxLib.h"
#include"GameMain.h"


//コンストラクタ
GameMain::GameMain()
{
	Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);

	/*画像の読み込み*/
	//空中の足場
	StageFoot[0] = LoadGraph("images/Stage/Stage_Footing01.png");
	//地面(左)
	StageLand_L = LoadGraph("images/Stage/Stage_Land_Left01.png");
	//地面(右)
	StageLand_R = LoadGraph("images/Stage/Stage_Land_Right01.png");
	//海
	StageSea = LoadGraph("images/Stage/Stage_Sea01.png");

	StageSample = LoadGraph("images/StageSample/Stage_1.png");

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
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawGraph(0, 0, StageSample, FALSE);
	//元に戻す。しかし、ここで特定の画像が半透明になる。                
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

	//当たり判定の仮表示

	//空中の足場
	DrawBox(180, 285, 460, 305, 0x00ff00,FALSE);

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
	fish->Draw();

	bubble->Draw();

	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
	
}
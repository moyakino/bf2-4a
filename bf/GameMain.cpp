#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"
#include "testPlayer.h"

#include "PadInput.h"

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
	//stage = new Stage();
	thunder = new Thunder();


	switch (Snum)
	{
	case 0:

		for (int i = 0; i < 3; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}

		break;
	}

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
	//stage->Update();
	player->Update();
	enemybird->Update(PLAYER::P_Move_X, PLAYER::P_Move_Y);
	bubble->Update();
	fish->Update();
	//enemybird->Update(player->GetLocationX(), player->GetLocationY());
	bubble->Update();
	thunder->Update();

	//bubble->Update();


	
	fps++;

	// Xボタン単押し
	int X_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_X);
	if (X_Btn == 1) {
		if (fps % 2 == 0) {
			if (++Snum > 4) {
				Snum = 0;
			}
		}
	}


	switch (Snum)
	{
	case 0:

		for (int i = 0; i < 3; i++)
		{
			if (StageFoot[i]->HitCollider(player) == true)
			{
				Stage::Stand = TRUE;
			}

		}
		break;
	}



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


	switch (Snum)
	{
	case 0:

		for (int i = 0; i < 3; i++)
		{
			StageFoot[i]->Draw();
		}

		break;
	}


	//stage->Draw();
	player->Draw();
	//enemybird->Draw();
	enemybird->Draw();

	bubble->Draw();


	thunder->Draw();


	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	DrawFormatString(400, 50, GetColor(255, 0, 0), "Snum:%d", Snum);
	
}
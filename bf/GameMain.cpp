#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"
#include "testPlayer.h"
#include"enemybird.h"

#include "PadInput.h"

//コンストラクタ
GameMain::GameMain()
{


	/*Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);*/
	ui = new UI();
	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	enemybird = new EnemyBird();
	//bubble = new Bubble();
	//stage = new Stage();
	thunder = new Thunder();

	Snum = 0;

	switch (Snum)
	{
	case 0:
		//ステージの生成
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
	delete ui;
	delete enemybird;

}


AbstractScene* GameMain::Update()
{
	//stage->Update();
	player->Update();
	//enemybird->Update(PLAYER::P_Move_X, PLAYER::P_Move_Y);
	bubble->Update();
	fish->Update(player->GetLocation().x , player->GetLocation().y);
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


	//当たり判定
	switch (Snum)
	{
	case 0:

		for (int i = 0; i < 3; i++)
		{
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true)
			{
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true) 
				{
					player->Player_Move();
				}
				else
				{
					player->SetStandFlg(false);
				}

				//それ以外の場所なら跳ね返る
				if (StageFoot[i]->L_SideBoxCollider(player) == true) 
				{

				}

				if (StageFoot[i]->R_SideBoxCollider(player) == true) 
				{

				}
			}

			////敵が足場に当たっているか
			//if (StageFoot[i]->HitCollider(Enemy[i]) == true)
			//{
			//	//かつ、足場の上に立っているかどうか
			//	if (StageFoot[i]->TopBoxCollider(Enemy[i]) == true)
			//	{
			//		Enemy[i]->Update();
			//	}
			//}

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
		//ステージの描画
		for (int i = 0; i < 3; i++)
		{
			StageFoot[i]->Draw();
		}


		break;
	}


	//stage->Draw();
	enemybird->Draw();
	//enemybird->Draw();
	fish->Draw();

	ui->Draw();

	thunder->Draw();
	ui->Draw();

	DrawFormatString(400, 50, GetColor(255, 0, 0), "Snum:%d", Snum);
	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
}
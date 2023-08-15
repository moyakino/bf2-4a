#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"

#include "PadInput.h"



//コンストラクタ
GameMain::GameMain()
{
	if (StageSea = LoadGraph("images/Stage/Stage_Sea01.png")) {}


	Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);

	ui = new UI();
	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	enemybird = new EnemyBird();
	//bubble = new Bubble();
	//stage = new Stage();
	thunder = new Thunder();

	Snum = 0;

	for (int i = 0; i < 3; i++)
	{
		StageFoot[i] = new Stage(Snum, i);
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
	fps++;

	// Xボタン単押し
	int X_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_X);
	if (X_Btn == 1)
	{
		if (fps % 2 == 0)
		{
			++Snum;
	
			//リセット
			if (Snum > 4) {
				Snum = 0;
			}
			CreateStage();
		}
	}

	bool TouchFlg = false;
	
	//当たり判定
	switch (Snum)
	{
	case 0:
		for (int i = 0; i < 3; i++){
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true){
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true){
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}	
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 1:
		for (int i = 0; i < 5; i++) {
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 2:
		for (int i = 0; i < 10; i++) {
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 3:
		for (int i = 0; i < 7; i++) {
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 4:
		for (int i = 0; i < 8; i++) {
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}
		break;
	}


	//stage->Update();
	player->Update();
	//enemybird->Update(PLAYER::P_Move_X, PLAYER::P_Move_Y);
	bubble->Update();
	fish->Update(player->GetLocation().x , player->GetLocation().y);
	enemybird->Update();
	thunder->Update();

	bubble->Update();

	
	return this;
}

void GameMain::CreateStage()
{
	//ステージの生成
	switch (Snum)
	{
	case 0:
		for (int i = 0; i < 3; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 1:
		for (int i = 0; i < 5; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 2:
		for (int i = 0; i < 10; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 3:
		for (int i = 0; i < 7; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 4:
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;
	}
}

void GameMain::Draw()const
{
	//ステージの描画
	switch (Snum)
	{
	case 0:
		for (int i = 0; i < 3; i++)
		{
			StageFoot[i]->Draw();
		}
		break;
		
	case 1:
		for (int i = 0; i < 5; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 2:
		for (int i = 0; i < 10; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 3:
		for (int i = 0; i < 7; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 4:
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i]->Draw();

		}
		break;
	}


	//海
	//DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
	DrawGraph(160, 445, StageSea, TRUE);

	//stage->Draw();
	player->Draw();

	enemybird->Draw();
	fish->Draw();
	bubble->Draw();
	//ui->Draw();
	thunder->Draw();
	//ui->Draw();
	player->Draw();

}
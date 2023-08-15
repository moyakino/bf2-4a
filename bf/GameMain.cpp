#include"DxLib.h"
#include"GameMain.h"
#include "PadInput.h"
#include "Player.h"

//コンストラクタ
GameMain::GameMain()
{
	if (StageSea = LoadGraph("images/Stage/Stage_Sea01.png")) {}

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

	if (ui->GetGameOver() == TRUE) {
		DrawGameOver = TRUE;
		if (fps > 59) {
			if (fps % 2 == 0) {
				Cnt++;
			}
		}
		if (Cnt > 3) {
			return new Title();
			Cnt = 0;
		}
	}

	//stage->Update();
	player->Update();
	ui->Update();
	bubble->Update(player->GetLocation().x, player->GetLocation().y);
	fish->Update(player->GetLocation().x , player->GetLocation().y);
	enemybird->Update();
	thunder->Update(player->GetLocation().x, player->GetLocation().y);


	
	

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

	if (fps > 59) {
		fps = 0;
	}
	
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
	
	ui->Draw();

	if (DrawGameOver == FALSE) {
		//enemybird->Draw();
		bubble->Draw();
		thunder->Draw();
		player->Draw();
		fish->Draw();
	}
	
	//DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	//DrawFormatString(400, 50, GetColor(255, 0, 0), "Snum:%d", Snum);
	
}
#include"DxLib.h"
#include "TitleScene.h"
#include"GameMain.h"
#include "PadInput.h"
#include "Player.h"
#include "TitleScene.h"
#include"enemybird.h"

bool GameMain::PauseFlg;

//コンストラクタ
GameMain::GameMain()
{
	if (StageSea = LoadGraph("images/Stage/Stage_Sea01.png")) {}

	MainBgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(MainBgm, DX_PLAYTYPE_BACK);
	ui = new UI();
	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	//enemybird = new EnemyBird();
	//bubble = new Bubble();
	//stage = new Stage();
	thunder = new Thunder();

	Snum = 0;

	for (int i = 0; i < 4; i++)
	{
		StageFoot[i] = new Stage(Snum, i);
	}

	for (int j = 0; j < 3; j++)
	{
		Enemy[j] = new EnemyBird(Snum, j);
	}

	PauseFlg = TRUE;
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
	////ポーズフラグ切り替え処理
	//if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	//{
	//	PauseFlg = !PauseFlg;
	//}

	//ポーズ中でないなら
	if (PauseFlg == FALSE) {

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
	fish->Update(player->GetLocation().x, player->GetLocation().y);
	ui->Update(player->PlayerLife, player->FishHit);
	bubble->Update(player->GetLocation().x, player->GetLocation().y);
	fish->Update(player->GetLocation().x , player->GetLocation().y);
	//enemybird->Update(player->GetLocation().x, player->GetLocation().y);
	thunder->Update(player->GetLocation().x, player->GetLocation().y);

	for (int j = 0; j < 3; j++){
		Enemy[j]->Update(player->GetLocation().x, player->GetLocation().y);
	}
	

	// Xボタン単押し
	int X_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_X);
	if (X_Btn == 1)
	{
		if (fps % 2 == 0)
		{
			++Snum;
			UI::i++;
			//リセット
			if (Snum > 4) {
				Snum = 0;
				UI::i = 1;
			}
			CreateStage();
		}
	}

	bool TouchFlg = false;
	bool tHitFlg = false;
	
	//当たり判定
	switch (Snum)
	{
	case 0:	//1面

		//足場の当たり判定
		for (int i = 0; i < 4; i++)
		{
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true){
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//プレイヤーの跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true){
				player->CheckBound(StageFoot[i]);
			}

			//雷
			if (thunder->StageHit(StageFoot[i]) == true) {
				tHitFlg = true;
			}	
			

		}

		//足場の上に立っていたらStandFlgをTRUEにする
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//足場の上に立っていなかったらStandFlgをFALSEにする
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

		//敵の当たり判定
		for (int j = 0; j < 3; j++)
		{
			switch (player->EnemyCollider(Enemy[j]))
			{
			case 1://左にあたったとき

				//敵が待機状態以外の時は跳ね返るif文を書く

				player->BoundMinusX();
				Enemy[j]->BoundPlusX();

				////プレイヤーが敵より上
				//if (player->GetLocation().y < enemybird->GetLocation().y + 25)
				//{

				//}

				////プレイヤーが敵より下
				//if (player->GetLocation().y > enemybird->GetLocation().y + 25)
				//{

				//}

				break;

			case 2://右にあたったとき
				player->BoundPlusX();
				Enemy[j]->BoundMinusX();
				break;

			case 3://上にあたったとき
				player->BoundMinusY();
				Enemy[j]->BoundPlusY();
				break;

			case 4://下にあたったとき
				player->BoundPlusY();
				Enemy[j]->BoundMinusY();
				break;
			}
		}

		break;

	case 1:	//2面

		//足場の当たり判定
		for (int i = 0; i < 6; i++) 
		{
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//プレイヤーの跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		//足場の上に立っていたらStandFlgをTRUEにする
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//足場の上に立っていなかったらStandFlgをFALSEにする
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

			break;

	case 2:	//3面

		//足場の当たり判定
		for (int i = 0; i < 11; i++) 
		{
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//プレイヤーの跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		//足場の上に立っていたらStandFlgをTRUEにする
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//足場の上に立っていなかったらStandFlgをFALSEにする
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

			break;

	case 3:	//4面

		//足場の当たり判定
		for (int i = 0; i < 8; i++) 
		{
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//プレイヤーの跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		//足場の上に立っていたらStandFlgをTRUEにする
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//足場の上に立っていなかったらStandFlgをFALSEにする
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

			break;

	case 4:	//5面

		//足場の当たり判定
		for (int i = 0; i < 9; i++) 
		{
			//プレイヤーが足場に当たっているか
			if (StageFoot[i]->HitCollider(player) == true) {
				//かつ、足場の上に立っているかどうか
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//プレイヤーの跳ね返りの判定
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}

		}

		//足場の上に立っていたらStandFlgをTRUEにする
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//足場の上に立っていなかったらStandFlgをFALSEにする
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}
		break;
	}

		if (fps > 59) {
			fps = 0;
		}

	}
	return this;
	
}

//敵・ステージの生成
void GameMain::CreateStage()
{
	switch (Snum)
	{
	case 0:	//1面

		//ステージの生成
		for (int i = 0; i < 4; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}

		//敵の生成
		for (int j = 0; j < 3; j++)
		{
			Enemy[j] = new EnemyBird(Snum, j);
		}

		break;

	case 1:	//2面

		//ステージの生成
		for (int i = 0; i < 6; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 2:	//3面

		//ステージの生成
		for (int i = 0; i < 11; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 3:	//4面

		//ステージの生成
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 4:	//5面

		//ステージの生成
		for (int i = 0; i < 9; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;
	}
}

void GameMain::Draw()const
{
	//描画
	switch (Snum)
	{
	case 0:	//1面

		//ステージの描画
		for (int i = 0; i < 4; i++)
		{
			StageFoot[i]->Draw();
		}

		//敵の描画
		for (int j = 0; j < 3; j++)
		{
			Enemy[j]->Draw();
		}
		break;
		
	case 1:	//2面

		//ステージの描画
		for (int i = 0; i < 6; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 2:	//3面

		//ステージの描画
		for (int i = 0; i < 11; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 3:	//4面

		//ステージの描画
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 4:	//5面

		//ステージの描画
		for (int i = 0; i < 9; i++)
		{
			StageFoot[i]->Draw();

		}
		break;
	}


	//海
	//DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
	//DrawGraph(160, 445, StageSea, TRUE);

	//stage->Draw();


	ui->Draw();

	if (DrawGameOver == FALSE) {
		//enemybird->Draw();
		bubble->Draw();
		thunder->Draw();
		player->Draw();
		fish->Draw();
	}

	DrawGraph(160, 445, StageSea, TRUE);
	
	//DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	//DrawFormatString(400, 50, GetColor(255, 0, 0), "Snum:%d", Snum);
	
	//一時停止中の描画
	if (PauseFlg == TRUE)
	{
	
		/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);*/
		DrawBox(0, 0, 1000, 780, 0x000000, FALSE);
		/*SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);*/
		DrawString(120, 70, "ポーズメニュー表示", GetColor(255, 255, 255));
	}
}
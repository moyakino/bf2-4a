#include"DxLib.h"
#include "UI.h"
#include "Bubble.h"
#include "Player.h"
#include "TitleScene.h"
#include "GameMain.h"

UI::UI()
{
	if(LoadDivGraph("images/UI/UI_NumAnimation.png",10,10,1,32,30,Number)){}
	NowScore = LoadGraph("images/UI/UI_Score.png");
	HiScore = LoadGraph("images/UI/UI_HiScore.png");
	Stock1 = LoadGraph("images/UI/UI_Stock.png");
	Stock2 = 0;
	Phase = LoadGraph("images/UI/UI_Phase.png");
	GameOver = LoadGraph("images/UI/UI_GameOver.png");
	gScore = 0;
	TotalScore = 500;
	PosX = 200;
	Respawn_Cnt = 0;
	GameOver_Flg = 0;
	Remaining_lives = 0;
	Fish_PlayerHit = 0;

	//配列の初期化
	for (int i = 0; i < 10; i++) {
		Number[i] = 0;
	}
}

UI::~UI()
{

}

void UI::Update(int life, int Fish_Death)
{
	Remaining_lives = life;
	Fish_PlayerHit = Fish_Death;


	//gScore = Bubble::H_flg;

	//TempScore = 750;

	///*if (CheckHitKey(KEY_INPUT_E))
	//{
	//	DrawGraph(200, 200, GameOver, FALSE);
	//}*/

	//if (gScore == 1) {
	//	Cnt += 1;
	//	//TempScore = TempScore % 10;
	//	TempScore /= 10;
	//	PosX -= 30;
	//}
	//fpsCnt++;

	/*do {
		DrawGraph(PosX, 30, Number[TotalScore % 10], TRUE);
		TotalScore /= 10;
		PosX -= 30;
	} while (TotalScore > 0);*/

	if (Remaining_lives == TRUE || Fish_PlayerHit == 16 && PLAYER::FishDeath == TRUE || Fish_PlayerHit == 32 && PLAYER::FishDeath == TRUE || Fish_PlayerHit == 48 && PLAYER::FishDeath == TRUE ||
		Fish_PlayerHit == 64 && PLAYER::FishDeath == TRUE) {
		Respawn_Cnt = Respawn_Cnt + 1;
	}

	if (Respawn_Cnt == 4) {
		GameOver_Flg = TRUE;
	}
}

void UI::Draw() const
{
	

	DrawGraph(60, 12, NowScore, TRUE);
	DrawGraph(240, 15, HiScore, TRUE);

	if (Respawn_Cnt == 0) {
		DrawGraph(145, 35, Stock1, TRUE);
		DrawGraph(165, 35, Stock1, TRUE);
	}
	//残機の残り 2個
	else if (Respawn_Cnt == 1) {
		DrawGraph(145, 35, Stock1, TRUE);
		DrawGraph(165, 35, Stock2, TRUE);
	}
	//残機の残り 1個
	else if (Respawn_Cnt == 2) {
		DrawGraph(145, 35, Stock2, TRUE);
		DrawGraph(165, 35, Stock2, TRUE);
	}

	if (GameOver_Flg == TRUE) {
		DrawGraph(220, 240, GameOver, TRUE);
	}

	//DrawFormatString(0, 200, GetColor(255, 255, 255), " Respawn_Cnt：%d", Respawn_Cnt);
	//DrawFormatString(0, 300, GetColor(255, 255, 255), " Cnt ：%d", Cnt);
	//DrawFormatString(0, 340, GetColor(255, 255, 255), " FishHit：%d", Test);

	DrawGraph(200, 300, Number[gScore], TRUE);

	//DrawFormatString(0, 200, GetColor(255, 255, 255), "TempScore : %d", TempScore);


	/*if (Cnt >= 1) {
		DrawGraph(PosX, 30, Number[TempScore], TRUE);
	}*/
	
}

int UI::GetGameOver()const
{
	return GameOver_Flg;
}
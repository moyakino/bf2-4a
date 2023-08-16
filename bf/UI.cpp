#include"DxLib.h"
#include "UI.h"
#include "Bubble.h"
#include "Player.h"
#include "TitleScene.h"

UI::UI()
{
	if(LoadDivGraph("images/UI/UI_NumAnimation.png",10,10,1,32,30,Number)){}
	Score = LoadGraph("images/UI/UI_Score.png");
	HiScore = LoadGraph("images/UI/UI_HiScore.png");
	Stock1 = LoadGraph("images/UI/UI_Stock.png");
	Stock2 = 0;
	Phase = LoadGraph("images/UI/UI_Phase.png");
	GameOver = LoadGraph("images/UI/UI_GameOver.png");
	gScore = 0;
	TotalScore = 500;
	PosX = 200;
	Cnt = 0;
	Respawn_Cnt = 0;
	Beaten_Cnt = 0;
	GameOver_Flg = 0;
	fpsCnt = 0;
	byou = 0;
	Test = 0;

	//配列の初期化
	for (int i = 0; i < 10; i++) {
		Number[i] = 0;
	}
}

UI::~UI()
{

}

void UI::Update(int Player_zanki, int Fish_Death)
{
	fpsCnt++;

	byou = Player_zanki;
	Test = Fish_Death;


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

	// 10以下なら1の位ですむ
	//if (TotalScore > 10) {
	//	gScore = TotalScore % 10;
	//	// 100 以下なら 10のくらいで済む
	//}

	/*do {
		DrawGraph(PosX, 30, Number[TotalScore % 10], TRUE);
		TotalScore /= 10;
		PosX -= 30;
	} while (TotalScore > 0);*/

	/*if (Test == 16 && PLAYER::FishDeath == TRUE) {
		Beaten_Cnt = Beaten_Cnt + 1;
	}
	else if (Test == 32 && PLAYER::FishDeath == TRUE) {
		Beaten_Cnt = Beaten_Cnt + 1;
	}
	else if (Test == 48 && PLAYER::FishDeath == TRUE) {
		Beaten_Cnt = Beaten_Cnt + 1;
	}*/

	/*if (Test == 32) {
		Beaten_Cnt = Beaten_Cnt + 1;
	}

	if (Test == 48) {
		GameOver_Flg = TRUE;
	}*/

	/*if (PLAYER::DeathCnt == R_Cnt - 1) {
		oooo++;
	}*/

	if (byou == TRUE || Test == 16 && PLAYER::FishDeath == TRUE || Test == 32 && PLAYER::FishDeath == TRUE || Test == 48 && PLAYER::FishDeath == TRUE) {
		//Cnt = 1;
		Respawn_Cnt = Respawn_Cnt + 1;
	}

	if (Respawn_Cnt == 4) {
		GameOver_Flg = TRUE;
	}

	if (fpsCnt > 59) {
		fpsCnt = 0;
	}
}

void UI::Draw() const
{
	DrawGraph(60,12,Score,TRUE);
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

	DrawFormatString(0, 200, GetColor(255, 255, 255), " Respawn_Cnt：%d", Respawn_Cnt);
	DrawFormatString(0, 300, GetColor(255, 255, 255), " Cnt ：%d", Cnt);
	DrawFormatString(0, 340, GetColor(255, 255, 255), " FishHit：%d", Test);

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
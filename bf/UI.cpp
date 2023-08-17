#include"DxLib.h"
#include "UI.h"
#include "Bubble.h"
#include "Player.h"
#include "TitleScene.h"
#include "GameMain.h"
int UI::GameOver_BGM;
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
	GameOver_Flg = 0;
	fpsCnt = 0;
	byou = 0;
	GameOver_BGM = LoadSoundMem("sounds/SE_GameOver.wav");
	CheckSoundMem(GameMain::MainBgm);

	//配列の初期化
	for (int i = 0; i < 10; i++) {
		Number[i] = 0;
	}
}

UI::~UI()
{

}

void UI::Update()
{
	fpsCnt++;

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
	if (TotalScore > 10) {
		gScore = TotalScore % 10;
		// 100 以下なら 10のくらいで済む
	}



	/*do {
		DrawGraph(PosX, 30, Number[TotalScore % 10], TRUE);
		TotalScore /= 10;
		PosX -= 30;
	} while (TotalScore > 0);*/


	if (PLAYER::zanki == TRUE) {
		Cnt += 1;
		Respawn_Cnt = Respawn_Cnt + Cnt;
	}

	if (Respawn_Cnt > 3) {
		GameOver_Flg = TRUE;
	}

	if (fpsCnt > 59) {
		fpsCnt = 0;
	}
}

void UI::Draw() const
{
	

		DrawGraph(60, 12, Score, TRUE);
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
			//もしGameOver画面ならMainBgmストップ
			if (CheckSoundMem(GameMain::MainBgm) == 1) {
				StopSoundMem(GameMain::MainBgm);
			}
			DrawGraph(220, 240, GameOver, TRUE);
			PlaySoundMem(GameOver_BGM, DX_PLAYTYPE_BACK, FALSE);
		}

	//DrawFormatString(0, 200, GetColor(255, 255, 255), " リスポーン：%d", Respawn_Cnt);
	//DrawFormatString(0, 300, GetColor(255, 255, 255), " Cnt		  ：%d", Cnt);

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
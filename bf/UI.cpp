#include"DxLib.h"
#include "UI.h"
#include "Bubble.h"
#include "Player.h"
#include "TitleScene.h"
#include "GameMain.h"

int UI::TotalScore;
int UI::Stage;
int UI::i;
UI::UI()
{
	if(LoadDivGraph("images/UI/UI_NumAnimation.png",10,10,1,32,30,Number)){}
	NowScore = LoadGraph("images/UI/UI_Score.png");
	HiScore = LoadGraph("images/UI/UI_HiScore.png");
	Stock1 = LoadGraph("images/UI/UI_Stock.png");
	Stock2 = 0;
	Phase = LoadGraph("images/UI/UI_Phase.png");
	GameOver = LoadGraph("images/UI/UI_GameOver.png");
	TotalScore = 0;
	HighScore = 50000;
	PosX = 200;
	Respawn_Cnt = 0;
	GameOver_Flg = 0;
	fpsCnt = 0;
	H_Score ;
	T_Score ;
	i = 1;
	Stage = Number[0];


	////配列の初期化
	//for (int i = 0; i < 10; i++) {
	//	Number[i] = 0;
	//}
}
UI::~UI()
{

}

void UI::Update(int life, int Fish_Death)
{
	//NowScore();
	Score1 = TotalScore % 10;
	Score10 = (TotalScore % 100) / 10;
	Score100 = (TotalScore % 1000) / 100;
	Score1000 = (TotalScore % 10000) / 1000;
	Score10000 = (TotalScore % 100000) / 10000;
	Score100000 = TotalScore / 100000;

	gScore1 = Number[Score1];
	gScore10 = Number[Score10];
	gScore100 = Number[Score100];
	gScore1000 = Number[Score1000];
	gScore10000 = Number[Score10000];
	gScore100000 = Number[Score100000];


	HighScore1 = HighScore % 10;
	HighScore10 = (HighScore % 100) / 10;
	HighScore100 = (HighScore % 1000) / 100;
	HighScore1000 = (HighScore % 10000) / 1000;
	HighScore10000 = (HighScore % 100000) / 10000;
	HighScore100000 = HighScore / 100000;

	HiScore1 = Number[HighScore1];
	HiScore10 = Number[HighScore10];
	HiScore100 = Number[HighScore100];
	HiScore1000 = Number[HighScore1000];
	HiScore10000 = Number[HighScore10000];
	HiScore100000 = Number[HighScore100000];

	
	//これで各位の数が求められる
	//Score1が一の位
	//Score10が十の位
	if (PLAYER::zanki == TRUE) {
		Cnt += 1;
		Respawn_Cnt = Respawn_Cnt + Cnt;
	}

	if (Respawn_Cnt == 4) {
		GameOver_Flg = TRUE;
		if (HighScore < TotalScore) {
			T_Score = TotalScore;
			H_Score = T_Score;
			HiScore1 = Number[Score1];
			HiScore10 = Number[Score10];
			HiScore100 = Number[Score100];
			HiScore1000 = Number[Score1000];
			HiScore10000 = Number[Score10000];
			HiScore100000 = Number[Score100000];
		}
	}
}

void UI::Draw() const
{

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

	/*DrawFormatString(0, 20, GetColor(255, 255, 255), " UI Cnt：%d", Respawn_Cnt);
	DrawFormatString(0, 40, GetColor(255, 255, 255), " GameOver：%d", GameOver_Flg);*/
	//DrawFormatString(0, 200, GetColor(255, 255, 255), "TempScore : %d", TempScore);

	//スコア
	DrawGraph(57, 13, Score, TRUE); //「I-」表示
	DrawGraph(72, 8, gScore100000,TRUE);
	DrawGraph(92, 8, gScore10000, TRUE);
	DrawGraph(112, 8, gScore1000, TRUE);
	DrawGraph(132, 8, gScore100, TRUE);
	DrawGraph(152, 8, gScore10, TRUE);
	DrawGraph(172, 8, gScore1, TRUE);
	
	//ハイスコア
	DrawGraph(230, 15, HiScore, TRUE); //「TOP-」表示
	DrawGraph(265, 7, HiScore100000, TRUE);
	DrawGraph(285, 7, HiScore10000, TRUE);
	DrawGraph(305, 7, HiScore1000, TRUE);
	DrawGraph(325, 7, HiScore100, TRUE);
	DrawGraph(345, 7, HiScore10, TRUE);
	DrawGraph(365, 7, HiScore1, TRUE);

	//フェーズ
	DrawGraph(230, 35, Phase, TRUE);
	DrawGraph(345, 25, Stage, TRUE);
	DrawGraph(365, 25, Number[i], TRUE);

	/*if (Cnt >= 1) {
		DrawGraph(PosX, 30, Number[TempScore], TRUE);
	}*/
	
}

int UI::GetGameOver()const
{
	return GameOver_Flg;
}
void UI::NowScore()const 
{/*
	int a;
	int y = 12;
	int x = 100;
	int i;
	for(a = 6 - 1; a > 0; a--)
	{
		i = TotalScore % 100;

		DrawGraph(x, (y * 20), Number[i], 6);
	}*/
	
}

//
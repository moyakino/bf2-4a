#include"DxLib.h"
#include "UI.h"
#include "Bubble.h"

UI::UI()
{
	if(LoadDivGraph("images/UI/UI_NumAnimation.png",10,10,1,32,30,Number)){}
	Score = LoadGraph("images/UI/UI_Score.png");
	HiScore = LoadGraph("images/UI/UI_HiScore.png");
	Stock1 = LoadGraph("images/UI/UI_Stock.png");
	Stock2 = LoadGraph("images/UI/UI_Stock.png");
	Phase = LoadGraph("images/UI/UI_Phase.png");
	GameOver = LoadGraph("images / UI / UI_GameOver.png");
	gScore = 0;
	TempScore = 0;
	PosX = 200;
	Cnt = 0;
}

UI::~UI()
{

}

void UI::Update()
{
	gScore = Bubble::H_flg;

	TempScore = 750;

	/*if (CheckHitKey(KEY_INPUT_E))
	{
		DrawGraph(200, 200, GameOver, FALSE);
	}*/

	if (gScore == 1) {
		Cnt += 1;
		//TempScore = TempScore % 10;
		TempScore /= 10;
		PosX -= 30;
	}
	
}

void UI::Draw() const
{
	//DrawGraph(60,12,Score,TRUE);
	//DrawGraph(250, 0, HiScore, FALSE);
	//DrawGraph(100,30, Stock1, TRUE);
	//DrawGraph(140, 30, Stock2, TRUE);

	//DrawGraph(73, 6, Number[0], TRUE);
	//DrawGraph(92, 6, Number[0], TRUE);
	//DrawGraph(111, 6, Number[4], TRUE);
	//DrawGraph(111, 6, Number[0], TRUE);

	//DrawGraph(0, 200, gScore, TRUE);

	//DrawFormatString(0, 200, GetColor(255, 255, 255), "TempScore : %d", TempScore);


	/*if (Cnt >= 1) {
		DrawGraph(PosX, 30, Number[TempScore], TRUE);
	}*/
}

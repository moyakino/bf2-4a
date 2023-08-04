#include "UI.h"
#include"DxLib.h"
UI::UI()
{
	if(LoadDivGraph("images/UI/UI_NumAnimation.png",10,10,1,32,30,Number)){}
	gScore = Number[8];
	Score = LoadGraph("images/UI/UI_Score.png");
	HiScore = LoadGraph("images/UI/UI_HiScore.png");
	Stock1 = LoadGraph("images/UI/UI_Stock.png");
	Stock2 = LoadGraph("images/UI/UI_Stock.png");
	Phase = LoadGraph("images/UI/UI_Phase.png");
	GameOver = LoadGraph("images / UI / UI_GameOver.png");
}

UI::~UI()
{
}

void UI::Update()
{
	if (CheckHitKey(KEY_INPUT_E))
	{
		DrawGraph(200, 200, GameOver, FALSE);
	}
	//for (int i = 0; i <= 6; i++) {
	//	for (int j = 0; j <= 1; j++) {
	//		DrawGraph(150, 0, gScore, FALSE);

	//	}
	//}
}

void UI::Draw() const
{
	DrawGraph(130, -5, gScore, TRUE);
	DrawGraph(100,0,Score,FALSE);
	DrawGraph(250, 0, HiScore, FALSE);
	DrawGraph(100,30, Stock1, TRUE);
	DrawGraph(140, 30, Stock2, TRUE);
}

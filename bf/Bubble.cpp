#include"DxLib.h"
#include"Bubble.h"
#include"Player.h"
#include"PadInput.h"
#include"FPS.h"
#include"UI.h"
#include "GameMain.h"

Bubble::Bubble()
{
	if (LoadDivGraph("images/stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg)) {}
	if(BubbleScoreImg = LoadGraph("images/Score/GetScore_750.png")){}
	B_Img = BubbleImg[0];
	BubbleMoveflg = 0;
	B_flg = 0;
	ScoreFlg = 0;
	H_flg = 0;
	MoveX = 330;
	//MoveY = 245;
	MoveY = 420;
	B_FPS = 0;
	seconds = 0;
	SpeedX = 0.0f;
	SpeedY = 30.0f;
	
	PlayerX = 0, PlayerY = 0;
	
	D_flg = TRUE;
	
}

Bubble::~Bubble()
{

}

void Bubble::Update(float x, float y)
{
	B_FPS++;

	PlayerX = x;
	PlayerY = y;

	if (MoveY <= -30) {
		MoveY = 245;
	}

	if (CheckHitKey(KEY_INPUT_Z)) {
		B_flg = TRUE;
	}

	if (B_flg == TRUE) {
		//BubbleMove();
		BubbleMoveAnim();
		MoveY -= 0.5f;

		Hit();

		if (H_flg == TRUE) {
			Score();

		}
	}

	if (ScoreFlg == TRUE) {
		if (B_FPS > 59) {
			seconds++;
			if (seconds > 2) {
				ScoreFlg = FALSE;
				seconds = 0;
			}
		}
	}

	if (B_FPS > 59) {
		B_FPS = 0;
	}
}

void Bubble::Draw() const 
{
	//ポーズ画面じゃないとき描写
	if (GameMain::PauseFlg == FALSE) {

		if (B_flg == TRUE) {
			DrawRotaGraph(MoveX, MoveY, 1.0f, 1, B_Img, TRUE);
		}

		if (ScoreFlg == TRUE) {
			DrawGraph(MoveX - 15, MoveY - 50, BubbleScoreImg, TRUE);
		}

		//DrawBoxAA(MoveX - 20, MoveY - 20, MoveX + 20, MoveY + 20, GetColor(255, 255, 255), FALSE);
		//DrawLine(MoveX - 20, MoveY - 15, MoveX - 20, MoveY + 15, GetColor(255, 0, 0), 1);		//左
		//DrawLine(MoveX + 20, MoveY - 15, MoveX + 20, MoveY + 15, GetColor(255, 0, 0), 1);		//右
		//DrawLine(MoveX - 20, MoveY - 15, MoveX + 20, MoveY - 15, GetColor(255, 255, 255), 1);	//上
		//DrawLine(MoveX - 20, MoveY + 15, MoveX + 20, MoveY + 15, GetColor(255, 255, 255), 1);	//下

		//DrawFormatString(0, 400, GetColor(255, 255, 255), "X : %0.1f Y : %0.1f", PlayerX, PlayerY);
		//DrawFormatString(0, 300, GetColor(255, 255, 255), "MoveX:%0.1f MoveY:%0.1f", MoveX, MoveY);
		//DrawFormatString(0, 320, GetColor(255, 255, 255), "Bubbleflg:%d", Bubbleflg);
		//DrawFormatString(0, 340, GetColor(255, 255, 255), "Bubble Hit:%d", H_flg);
	}

}

void Bubble::Hit()
{
	if (PlayerX + 5 < MoveX - 20 && PlayerX + 57 > MoveX - 20 && PlayerY + 8 < MoveY - 15 && PlayerY + 68 > MoveY + 15 || //左
		PlayerX + 5 < MoveX + 20 && PlayerX + 57 > MoveX - 20 && PlayerY + 8 < MoveY - 15 && PlayerY + 68 > MoveY + 15 || //右
		PlayerX + 5 < MoveX - 20 && PlayerX + 57 > MoveX + 20 && PlayerY + 8 < MoveY - 15 && PlayerY + 68 > MoveY - 15 || //上
		PlayerX + 5 < MoveX - 20 && PlayerX + 57 > MoveX + 20 && PlayerY + 8 < MoveY + 15 && PlayerY + 68 > MoveY + 15 ){ //下

		//　上記の線がPlayerのBoxの範囲に入っていたら HIt!
		H_flg = TRUE;
	}
}

void Bubble::Score()
{
	if (B_FPS > 59) {
		seconds++;
		if (seconds <= 1) {
			B_Img = BubbleImg[3];
		}
		else {
			seconds = 0;
			B_flg = FALSE;
			H_flg = FALSE;
			ScoreFlg = TRUE;
			UI::TotalScore += 750;
		}
	}
};

void Bubble::BubbleMoveAnim()
{
	if (H_flg == FALSE) {
		if (B_FPS >= 0 && B_FPS < 15) {
			B_Img = BubbleImg[BUBBLEMOVE2];
		}
		else if (B_FPS > 14 && B_FPS < 30) {
			B_Img = BubbleImg[BUBBLEMOVE1];
		}
		else if (B_FPS > 29 && B_FPS < 45) {
			B_Img = BubbleImg[BUBBLEMOVE2];
		}
		else if (B_FPS > 44 && B_FPS <= 60) {
			B_Img = BubbleImg[BUBBLEMOVE3];
		}
	}
}

void Bubble::BubbleMove()
{
	/*if (MoveX == 400) {
		SpeedX = 0.7f;
	}
	if (SpeedX <= 0) {
		BubbleMoveflg = 1;
	}
	if (SpeedX >= 10) {
		BubbleMoveflg = 0;
	}
	if (BubbleMoveflg == 1) {
		SpeedX++;
		MoveX++;;
	}
	else {
		SpeedX--;
		MoveX--;
	}*/

	// 290 380

	//if(MoveX )
}
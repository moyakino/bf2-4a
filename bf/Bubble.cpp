
#include"DxLib.h"
#include"Bubble.h"
#include"Player.h"
#include"PadInput.h"
#include"FPS.h"

Bubble::Bubble()
{
	if (LoadDivGraph("images/stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg)){}
B_Img = BubbleImg[0];
Bubbleflg = 0;
MoveX = 338;
MoveY = 245;
SpeedY = 30;
B_FPS = 0;
B_flg = 0;
}

void Bubble::Update()
{
	B_FPS++;
	

	if (CheckHitKey(KEY_INPUT_Z))
	{
		B_flg = TRUE;
	}

	if (MoveY <= -30) {
		MoveY = 245;
	}
		
	if (MoveY!= 0 && B_flg == TRUE) {
			MoveY -= 0.4f;
			B_Img = BubbleControl();
			/*if (MoveY == -10) {
				B_flg = FALSE;
			}*/
	}
	if (B_FPS > 60) {
		B_FPS = 0;
		seconds++;
	}// B_FPS_INC ÇÕ ïbêîÇéÊÇ¡ÇƒÇ¢ÇÈ
	else if (seconds > 3) {
		seconds = 0;
	}
}

void Bubble::Draw() const {
	DrawRotaGraph(MoveX, MoveY,1.0f,1,B_Img,TRUE);
	DrawBox(MoveX - 15, MoveY - 15, MoveX + 15, MoveY + 15, GetColor(255, 255, 255), FALSE);
	/*DrawFormatString(0, 320, GetColor(255, 255, 255), "MoveX:%0.1f MoveY:%0.1f", MoveX,MoveY);
	DrawFormatString(0, 340, GetColor(255, 255, 255), "Bubbleflg:%d", Bubbleflg);*/

}

int Bubble::BubbleControl()
{
	if (MoveX == 460) {
		SpeedX = 0.7f;
	}
	if (SpeedX <= 0) {
		Bubbleflg = 1;
	}
	if (SpeedX >= 10) {
		Bubbleflg = 0;
	}
	if (Bubbleflg == 1) {
		SpeedX++;
		MoveX++;;
	}
	else {
		SpeedX--;
		MoveX--;
	}
	
			
	int B_AnimImg = 0;

	// 5ÉtÉåÅ[ÉÄ
	if (B_FPS % 15 == 0 || B_FPS % 15 == 1 || B_FPS % 15 == 2 || B_FPS % 15 == 3 || B_FPS % 15 == 4) {
		B_AnimImg = BubbleImg[0];
	}
	else if (B_FPS % 15 == 5 || B_FPS % 15 == 6 || B_FPS % 15 == 7 || B_FPS % 15 == 8 || B_FPS % 15 == 9) {
		B_AnimImg = BubbleImg[1];
	}
	else if (B_FPS % 15 == 10 || B_FPS % 15 == 11 || B_FPS % 15 == 12 || B_FPS % 15 == 13 || B_FPS % 15 == 14) {
		B_AnimImg = BubbleImg[2];
	}

	return B_AnimImg;
}



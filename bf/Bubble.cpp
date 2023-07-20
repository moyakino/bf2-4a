
#include"DxLib.h"
#include"Bubble.h"
#include"Player.h"
#include"PadInput.h"
#include"FPS.h"

Bubble::Bubble()
{
	if (LoadDivGraph("images/stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg)){}
B_Img = BubbleImg[0];
BallFlg = 0;
MoveX = 338;
MoveY = 245;
SpeedY = 30;
B_FPS = 0;
}



void Bubble::Update()
{
	B_FPS++;
	if (B_FPS > 60) {
		B_FPS = 0;
		seconds++;
	}// P_FPS_INC ‚Í •b”‚ðŽæ‚Á‚Ä‚¢‚é
	else if (seconds > 3) {
		seconds = 0;
	}
	if (MoveY != 0) {
		MoveY -= 0.4f;
		BubbleControl();
		}
	/*while (MoveY == 0) {
		
	}*/
   /* if (CheckHitKey(KEY_INPUT_A)) {
        MoveX -= 0.4;
		 B_Img = BubbleControl();
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		MoveX += 0.4;
		B_Img = BubbleControl();
	}
	 if (CheckHitKey(KEY_INPUT_W)) {
		MoveY -= 0.3;
		B_Img = BubbleControl();
	}*/

}

void Bubble::Draw() const {
	DrawRotaGraph(MoveX, MoveY,1.0f,1,B_Img,TRUE);
	DrawBox(MoveX - 15, MoveY - 15, MoveX + 15, MoveY + 15, GetColor(255, 255, 255), FALSE);
}

int Bubble::BubbleControl()
{

	int B_AnimImg = 0;
	
		if (B_FPS % 20 == 0 || B_FPS % 20 == 1 || B_FPS % 20 == 2 || B_FPS % 20 == 3 || B_FPS % 20 == 4) {
			B_AnimImg = BubbleImg[0];
		}
		else if (B_FPS % 20 == 5 || B_FPS % 20 == 6 || B_FPS % 20 == 7 || B_FPS % 20 == 8 || B_FPS % 20 == 9) {
			B_AnimImg = BubbleImg[1];
		}
		else if (B_FPS % 20 == 10 || B_FPS % 20 == 11 || B_FPS % 20 == 12 || B_FPS % 20 == 13 || B_FPS % 20 == 14) {
			B_AnimImg = BubbleImg[2];
		}
	return B_AnimImg;
}



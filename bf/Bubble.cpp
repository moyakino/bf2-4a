#include"DxLib.h"
#include"Bubble.h"

Bubble::Bubble()
{
	BubbleImg = LoadGraph("images/ball.jpg");
X = 0;
Y = 0;
BallFlg = 0;
BallX = 0;
BallY = 0;
MoveX = 25;
MoveY = 60;
}

void Bubble::Update()
{
	if(CheckHitKey(KEY_INPUT_Z)){
		BallY = BallY + MoveY;
	}
}

void Bubble::Draw() const {
	DrawGraph(200, 200, BubbleImg,TRUE);
}



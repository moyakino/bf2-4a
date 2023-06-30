#include"DxLib.h"
#include"Bubble.h"

Bubble::Bubble()
{
	BubbleImg = LoadGraph("images/ball.jpg");
X = 128;
Y = 225;
BallFlg = 0;
BallX = 0;
BallY = 0;
MoveX = 25;
MoveY = 60;
}

void Bubble::Update()
{
	if(CheckHitKey(KEY_INPUT_Z)){
		BallY = Y + MoveY;
	}
}

void Bubble::Draw() const {
	DrawGraph(X, Y, BubbleImg,TRUE);
}



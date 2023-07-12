#include"DxLib.h"
#include"Bubble.h"
#include"Player.h"
#include"PadInput.h"

Bubble::Bubble()
{

X = 20;
Y = 20;
BallFlg = 0;
BallX = 0;
BallY = 0;
MoveX = 200;
MoveY = 455;
}

void Bubble::Update()
{
    if (CheckHitKey(KEY_INPUT_A)) {
        MoveX -= 0.4;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		MoveX = MoveX+  0.4;
	}
	 if (CheckHitKey(KEY_INPUT_W)) {
		MoveY -= 0.3;
	}

}

void Bubble::Draw() const {
	DrawCircle(MoveX, MoveY,10, GetColor(255, 255, 255), TRUE);
	DrawBox(MoveX - 11, MoveY - 11, MoveX + 12, MoveY + 12, GetColor(255, 255, 255), FALSE);
}



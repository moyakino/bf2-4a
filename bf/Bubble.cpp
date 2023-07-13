#include"DxLib.h"
#include"Bubble.h"
#include"Player.h"
#include"PadInput.h"

Bubble::Bubble()
{
	if (LoadDivGraph("images/stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg));
X = 20;
Y = 20;
BallFlg = 0;
BallX = 0;
BallY = 0;
MoveX = 338;
MoveY = 245;
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
	DrawRotaGraph(MoveX, MoveY,1.0f,1,BubbleImg[0],TRUE);
	DrawBox(MoveX - 11, MoveY - 11, MoveX + 12, MoveY + 12, GetColor(255, 255, 255), FALSE);
}

int Bubble::BubbleControl(void)
{/* for(int i = 0; i < )*/

	return 0;
}



#include"DxLib.h"
#include "Thunder.h"
#include"GameMain.h"

Thunder::Thunder()
{
	//雷画像データの読み込み
	if (LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 64, 64, S_ThunderImg)) {}

	S_Img = 0;
	S_FPS = 0;
	S_Seconas1 = 0;
}

Thunder::~Thunder()
{

}

void Thunder::Update()
{
	if (S_FPS > 30) {
		S_FPS = 0;
		S_Seconas1++;
	}// P_FPS_INC は 秒数を取っている
	else if (S_Seconas1 > 3) {
		S_Seconas1 = 0;
	}

	S_Img = Thunder_Anim();
}

int Thunder::Thunder_Anim()
{
	int C_AnimImg = 0;

	// 0 から 3 秒
	if (S_Seconas1 == 0) {
		C_AnimImg = S_ThunderImg[THUNDER_ANIM1_0];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		C_AnimImg = S_ThunderImg[THUNDER_ANIM1_0];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		C_AnimImg = S_ThunderImg[THUNDER_ANIM1_0];
	}

	return C_AnimImg;
}

void Thunder::Draw() const
{
	//メニューカーソル（風船）の表示
	DrawGraph(400, 200, S_Img, TRUE);
}
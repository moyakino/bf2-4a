#include"DxLib.h"
#include "Thunder.h"
#include"GameMain.h"
#include <corecrt_math_defines.h>
#include <corecrt_math.h>

Thunder::Thunder()
{
	//雲画像データの読み込み
	if ((CloudImg = LoadGraph("images/Stage/Stage_Cloud01.png")) == -1);
	if (LoadDivGraph("images/Stage/Stage_CloudAnimation.png", 3, 3, 1,64, 64, Cloud_AnimImg)) {}

	//雷(稲光)画像データの分割読み込み
	if (LoadDivGraph("images/Stage/Stage_ThunderAnimation.png", 6, 6, 1, 64, 64, ThunderImg)) {}
	//雷(雷の弾)画像データの分割読み込み
	if (LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, EffectImg)) {}

	ThunderImg[6];
	T_Img = 0;

	EffectImg[3];
	E_Img = 0;

	S_FPS1 = 0;
	S_FPS2 = 0;
	S_Seconas1 = 0;
	S_Seconas2 = 0;

	// 変数の初期設定
	BallX = 300;
	BallY = 200;
}

Thunder::~Thunder()
{

}

void Thunder::Update()
{
	S_FPS1++;
	S_FPS2++;

	//雷(稲光)のFPS
	if (S_FPS1 > 14) {
		S_FPS1 = 0;
		S_Seconas1++;
	}// P_FPS_INC は 秒数を取っている
	else if (S_Seconas1 > 6) {
		S_Seconas1 = 0;
	}

	//雷(雷の弾)のFPS
	if (S_FPS2 > 29) {
		S_FPS2 = 0;
		S_Seconas2++;
	}// P_FPS_INC は 秒数を取っている
	else if (S_Seconas2 > 3) {
		S_Seconas2 = 0;
	}

	if (BallFlg != 2) {
		BallX += MoveX;
		BallY += MoveY;
	}

	// 壁・天井での反射
	if (BallX < 4 || BallX > 640 - 4) { // 横の壁
		if (BallX < 4) {
			BallX = 4;
		}
		else {
			BallX = 640 - 4;
		}
		BallAngle = (1 - BallAngle) + 0.5f;
		if (BallAngle > 1) BallAngle -= 1.0f;
		ChangeAngle();
	}
	if (BallY < 8) { // 上の壁
		BallAngle = (1 - BallAngle);
		ChangeAngle();

	}

	// マウス左クリックでゲームスタート
	if (((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		&& BallFlg == 2) {

		BallFlg = 0;
		// スピードとアングルによる移動量計算
		Speed = 3;
		BallAngle = 0.625f;
		ChangeAngle();
	}

	//if (BallY > 480 + 4) {
	//	// ボールをスタート状態にする
	//	BallFlg = 2;
	//	if (--RestBall <= 0) {
	//		if (g_Score >= g_Ranking[9].score) {
	//			g_GameState = 7;  //ランキング入力処理へ
	//		}
	//		else {
	//			g_GameState = 5;  //ゲームオーバー処理へ
	//		}
	//	}
	//}

	T_Img = Thunder_Anim();
	E_Img = Effect_Anim();
	C_Img = Cloud_Anim();
}

void Thunder::ChangeAngle() 
{
	float rad = BallAngle * (float)M_PI * 2;
	MoveX = (int)(Speed * cosf(rad));
	MoveY = (int)(Speed * sinf(rad));
}

int Thunder::Thunder_Anim()
{
	int T_AnimImg = 0;

	// 0 から 5 秒
	if (S_Seconas1 == 0) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_0];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_1];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_2];
	}
	else if (S_Seconas1 > 2 && S_Seconas1 < 4) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_3];
	}
	else if (S_Seconas1 > 3 && S_Seconas1 < 5) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_4];
	}
	else if (S_Seconas1 > 4 && S_Seconas1 < 6) {
		T_AnimImg = ThunderImg[THUNDER_ANIM1_5];
	}
	

	return T_AnimImg;
}

int Thunder::Effect_Anim()
{
	int E_AnimImg = 0;

	// 0 から 3 秒
	if (S_Seconas1 == 0) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_0];
	}
	else if (S_Seconas1 > 0 && S_Seconas1 < 2) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_1];
	}
	else if (S_Seconas1 > 1 && S_Seconas1 < 3) {
		E_AnimImg = EffectImg[EFFECT_ANIM1_2];
	}

	return E_AnimImg;
}

int Thunder::Cloud_Anim()
{
	int C_AnimImg = 0;

	// 0 から 3 秒
	if (S_Seconas2 == 0) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_0];
	}
	else if (S_Seconas2 > 0 && S_Seconas1 < 2) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_1];
	}
	else if (S_Seconas2 > 1 && S_Seconas1 < 3) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_2];
	}

	return C_AnimImg;
}

void Thunder::Draw() const
{
	//メニューカーソル（風船）の表示
	DrawGraph(400, 100, T_Img, TRUE);
	
	//メニューカーソル（風船）の表示
	DrawGraph(BallX, BallY, E_Img, TRUE);

	//
	DrawGraph(320, 90, CloudImg, TRUE);
	DrawGraph(500, 90, C_Img, TRUE);
}
#include"DxLib.h"
#include "Thunder.h"
#include"GameMain.h"
#include <math.h>

Thunder::Thunder()
{
	//雲画像データの読み込み
	if (CloudImg = LoadGraph("images/Stage/Stage_Cloud01.png")) {};
	//雲画像アニメーションの読み込み
	if (LoadDivGraph("images/Stage/Stage_CloudAnimation.png", 3, 3, 1, 128, 64, Cloud_AnimImg)) {}

	//雷(稲光)画像データの分割読み込み
	if (LoadDivGraph("images/Stage/Stage_ThunderAnimation.png", 6, 6, 1, 64, 64, ThunderImg)) {}
	//雷(雷の弾)画像データの分割読み込み
	if (LoadDivGraph("images/Stage/Stage_ThunderEffectAnimation.png", 3, 3, 1, 32, 32, EffectImg)) {}

	T_Img = 0;
	E_Img = 0;
	C_Img = 0;

	T_Thunder_Flg = FALSE;
	T_Effect_Flg = TRUE;
	T_Cloud_Flg = FALSE;

	S_FPS1 = 0;
	S_FPS2 = 0;
	S_Seconas1 = 0;
	S_Seconas2 = 0;
	S_Seconas3 = 0;

	BallFlg = 0;
	BallX = 345;
	BallY = 105;
	BallAngle = 0;

	MoveX = 0;
	MoveY = 0;

	PlayerX = 0, PlayerY = 0;

	Subject = rand() % 3;

	flg = 0;
	
}

Thunder::~Thunder()
{

}

void Thunder::Update(float x, float y)
{
	S_FPS1++;
	S_FPS2++;

	PlayerX = x;
	PlayerY = y;

	T_Img = Thunder_Anim();
	E_Img = Effect_Anim();
	C_Img = Cloud_Anim();

	MoveBall();

	//雷(稲光)用 FPS
	if (S_FPS1 > 34) {
		S_FPS1 = 0;
		S_Seconas1++;
	}// P_FPS_INC は 秒数を取っている
	else if (S_Seconas1 > 3) {
		S_Seconas1 = 0;
	}

	//雷(雷の弾)用 FPS
	if (S_FPS2 > 59) {
		S_FPS2 = 0;
		S_Seconas2++;
	}
}

void Thunder::MoveBall()
{
	if (S_Seconas2 > 30)
	{
		S_Seconas2 = 0;
		BallFlg = 1;
		Speed = 2;
		BallAngle = 0.625f;  //左上
		//BallAngle = 0.375f;  //左下
		//BallAngle = 0.875f;  //右上
		//BallAngle = 0.125f;  //右上
		T_Effect_Flg = TRUE;
		ChangeAngle();
	}

	// マウス左クリックでゲームスタート
	if (CheckHitKey(KEY_INPUT_1))
	{
		BallFlg = 1;
		Speed = 2;
		BallAngle = 0.625f;  //左上
		//BallAngle = 0.375f;  //左下
		//BallAngle = 0.875f;  //右上
		//BallAngle = 0.125f;  //右上
		T_Effect_Flg = TRUE;
		ChangeAngle();
	}
	
	// 2でリセット
	if(CheckHitKey(KEY_INPUT_2))BallFlg = 2;
		
	//ボールの移動処理
	if (BallFlg != 2) 
	{
		BallX += MoveX;
		BallY += MoveY;
	}

	//壁・天井での反射
	if (BallX < 4 || BallX > 610) // 横の壁
	{ 
		if (BallX < 4) {
			BallX = 4;
		}
		else {
			BallX = 610;
		}
		BallAngle = (1 - BallAngle) + 0.5f;
		if (BallAngle > 1) BallAngle -= 1.0f;
		ChangeAngle();
	}
	if (BallY < 8 || BallY > 460) // 上下の壁
	{ 
		if (BallY < 8) {
			ChangeAngle();
			//BallY = 8;
		}
		else if(BallY > 460){
			ChangeAngle();		
		}
		BallAngle = (1 - BallAngle);		
		ChangeAngle();
	}
	//if (BallY < 8) { // 上の壁
	//	BallAngle = (1 - BallAngle);
	//	ChangeAngle();
	//}
	if (BallY > 480 + 4) //(海)
	{
		BallFlg = 2;
	}
	//ボールをスタート状態にする
	if (BallFlg == 2)
		{
			BallX = 345;
			BallY = 105;
	}

	//ChangeAngle();
}

void Thunder::ThunderBallInit()
{

}

void Thunder::ChangeAngle()
{
	float rad = BallAngle * (float)M_PI * 2;
	MoveX = (int)(Speed * cosf(rad));
	MoveY = (int)(Speed * sinf(rad));
}

void Thunder::HitThunder()
{
	//ボールとバーの当たり判定
	//int mx0, mx1, my0, my1, sx0, sx1, sy0, sy1;


	////座標位置の事前計算
	//mx0 = BallX - 4;
	//mx1 = BallX + 4;
	//my0 = BallY - 4;
	//my1 = BallY + 4;
	//sx0 = 0;
	//sx1 = 0;
	//sy0 = 0;
	//sy1 = 0;

	//// ボールとバーの当たり判定
	//if (sx0 <= mx1 && sx1 >= mx0 &&
	//	sy0 <= my1 && sy1 >= my0) {
	//	if (BallFlg == 0) {
	//		BallAngle = (0.3f / 60) * (mx1 - sx0) + 0.6f;
	//		ChangeAngle();

	//		BallFlg = 1;
	//	}
	//}
	//else {
	//	if (BallFlg != 2)BallFlg = 0;
	//}

	//ChangeAngle();
}

int Thunder::Thunder_Anim()
{
	int T_AnimImg = 0;

	// 0 から 5 秒
	/*if (T_Thunder_Flg == TRUE) {
		if (S_Seconas2 == 0) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_0];
		}
		else if (S_Seconas2 > 0 && S_Seconas2 < 2) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_1];
		}
		else if (S_Seconas2 > 1 && S_Seconas2 < 3) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_2];
		}
		else if (S_Seconas2 > 2 && S_Seconas2 < 4) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_3];
		}
		else if (S_Seconas2 > 3 && S_Seconas2 < 5) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_4];
		}
		else if (S_Seconas2 > 4 && S_Seconas2 < 6) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_5];
		}
	}*/

	if (T_Thunder_Flg == TRUE) {

		if (S_FPS2 >= 0 && S_FPS2 < 10) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_0];
		}
		else if (S_FPS2 > 9 && S_FPS2 < 20) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_1];
		}
		else if (S_FPS2 > 19 && S_FPS2 < 30) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_2];
		}
		else if (S_FPS2 > 29 && S_FPS2 < 40) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_3];
		}
		else if (S_FPS2 > 39 && S_FPS2 < 50) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_4];
		}
		else if (S_FPS2 > 49 && S_FPS2 < 60) {
			T_AnimImg = ThunderImg[THUNDER_ANIM1_5];
		}
	}

	return T_AnimImg;
}

int Thunder::Effect_Anim()
{
	int E_AnimImg = 0;

	//if (T_Effect_Flg == TRUE) {
	//	// 5フレーム
	//	if (S_FPS1 % 20 == 0 || S_FPS1 % 20 == 1 || S_FPS1 % 20 == 2 || S_FPS1 % 20 == 3 || S_FPS1 % 20 == 4) {
	//		E_AnimImg = EffectImg[EFFECT_ANIM1_0];
	//	}
	//	else if (S_FPS1 % 20 == 5 || S_FPS1 % 20 == 6 || S_FPS1 % 20 == 7 || S_FPS1 % 20 == 8 || S_FPS1 % 20 == 9) {
	//		E_AnimImg = EffectImg[EFFECT_ANIM1_1];
	//	}
	//	else if (S_FPS1 % 20 == 10 || S_FPS1 % 20 == 11 || S_FPS1 % 20 == 12 || S_FPS1 % 20 == 13 || S_FPS1 % 20 == 14) {
	//		E_AnimImg = EffectImg[EFFECT_ANIM1_2];
	//	}
	//}

	if (T_Effect_Flg == TRUE) {

		if (S_FPS1 >= 0 && S_FPS1 < 10) {
			E_AnimImg = EffectImg[EFFECT_ANIM1_0];
		}
		else if (S_FPS1 > 9 && S_FPS1 < 20) {
			E_AnimImg = EffectImg[EFFECT_ANIM1_1];
		}
		else if (S_FPS1 > 19 && S_FPS1 < 30) {
			E_AnimImg = EffectImg[EFFECT_ANIM1_2];
		}
	}
	
	return E_AnimImg;
}

int Thunder::Cloud_Anim()
{
	int C_AnimImg = 0;

	// 0 から 3 秒
	/*if (S_Seconas2 == 0) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_0];
	}
	else if (S_Seconas2 > 0 && S_Seconas1 < 2) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_1];
	}
	else if (S_Seconas2 > 1 && S_Seconas1 < 3) {
		C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_2];
	}*/

	if (T_Cloud_Flg == TRUE) {

		if (S_FPS1 >= 0 && S_FPS1 < 10) {
			C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_0];
		}
		else if (S_FPS1 > 9 && S_FPS1 < 20) {
			C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_1];
		}
		else if (S_FPS1 > 19 && S_FPS1 < 30) {
			C_AnimImg = Cloud_AnimImg[CLOUD_ANIM1_2];
		}
	}

	return C_AnimImg;
}

void Thunder::Draw() const
{
	//雲の描画
	DrawGraph(320, 90, CloudImg, TRUE);
	DrawGraph(295, 90, C_Img, TRUE);

	//雷（稲光）の表示
	DrawGraph(400, 100, T_Img, TRUE);
	
	//雷（雷の弾）の表示
	DrawGraph(BallX, BallY, E_Img, TRUE);

	DrawFormatString(0, 300, GetColor(255, 255, 255), " 雷発生 :%d", S_Seconas2);

	DrawBox(BallX + 2, BallY + 4, BallX + 28, BallY + 26, GetColor(255, 0, 0), FALSE);
}
#include"DxLib.h"
#include "Thunder.h"
#include"GameMain.h"
#include <math.h>
#include <stdlib.h>

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
	location.x = 345;
	location.y = 105;
	erea.Width = 32;
	erea.Height = 32;

	BallAngle = 0;

	MoveX = 0;
	MoveY = 0;

	PlayerX = 0, PlayerY = 0;

	HitFlg = 0;

	flg = FALSE;
	
}

Thunder::~Thunder()
{

}

void Thunder::Update(float x, float y)
{
	BallX = location.x;
	BallY = location.y;

	S_FPS1++;
	S_FPS2++;

	PlayerX = x;
	PlayerY = y;

	T_Img = Thunder_Anim();
	E_Img = Effect_Anim();
	C_Img = Cloud_Anim();

	ThunderBallInit();
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
	//if (S_Seconas2 > 30)
	//{
	//	S_Seconas2 = 0;
	//	BallFlg = 1;
	//	Speed = 2;
	//	BallAngle = 0.625f;  //左上
	//	//BallAngle = 0.375f;  //左下
	//	//BallAngle = 0.875f;  //右上
	//	//BallAngle = 0.125f;  //右上
	//	T_Effect_Flg = TRUE;
	//	ChangeAngle();
	//}

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
		location.x += MoveX;
		location.y += MoveY;
	}


	//壁・天井での反射
	if (location.x < 4 || location.x > 610) // 横の壁
	{ 
		if (location.x < 4) {
			location.x = 4;
		}
		else {
			location.x = 610;
		}
		BallAngle = (1 - BallAngle) + 0.5f;
		if (BallAngle > 1) BallAngle -= 1.0f;
		ChangeAngle();
	}
	if (location.y < 8 /*|| location.y > 460*/) // 上下の壁
	{ 
		if (location.y < 8) {
			BallAngle = (1 - BallAngle);		
		    ChangeAngle();
		}
		
	}
	
	if (flg == TRUE)
	{
		BallAngle = (1 - BallAngle) + 0.5f;
		if (BallAngle > 1) BallAngle -= 1.0f;
		ChangeAngle();
	}

	if (BallY > 480 + 4) //(海)
	{
		BallFlg = 2;
	}

	//ボールをスタート状態にする
	if (BallFlg == 2)
		{
			location.x = 345;
			location.y = 105;
	}

}

void Thunder::ThunderBallInit()
{
	if (PlayerX + 5 < BallX + 2  && PlayerX + 57 > BallX + 2  && PlayerY + 8 < BallY + 4  && PlayerY + 68 > BallY + 26 || //左
		PlayerX + 5 < BallX + 28 && PlayerX + 57 > BallX + 28 && PlayerY + 8 < BallY + 4  && PlayerY + 68 > BallY + 26 || //右
		PlayerX + 5 < BallX + 2  && PlayerX + 57 > BallX + 28 && PlayerY + 8 < BallY + 4  && PlayerY + 68 > BallY + 4  || //上
		PlayerX + 5 < BallX + 2  && PlayerX + 57 > BallX + 28 && PlayerY + 8 < BallY + 26 && PlayerY + 68 > BallY + 26) { //下

		//　上記の線がPlayerのBoxの範囲に入っていたら HIt!
		HitFlg = TRUE;
	}
	else {
		HitFlg = FALSE;
	}
}

void Thunder::ChangeAngle()
{
	float rad = BallAngle * (float)M_PI * 2;
	MoveX = (int)(Speed * cosf(rad));
	MoveY = (int)(Speed * sinf(rad));
}

bool Thunder::StageHit(BoxCollider* b_col)
{
	int re =false;

	//ステージ
	float sx1 = b_col->GetLocation().x;
	float sy1 = b_col->GetLocation().y;
	float sx2 = sx1 + b_col->GetErea().Width;
	float sy2 = sy1 + b_col->GetErea().Height;

	//雷
	float tx1 = location.x;
	float tx2 = tx1 + erea.Width;
	float ty1 = location.y;
	float ty2 = ty1 + erea.Height;


	//当たり判定
	if ((tx1 < sx2) && (sx1 < tx2) && (ty1 < sy2) && (ty2 > sy1))
	{
		////左
		//if ((tx1 < sx2) && (sx1 > tx2 - (erea.Width / 4))) 
		//{
		//	BallAngle = (1 - BallAngle) + 0.5f;
		//	if (BallAngle > 1) BallAngle -= 1.0f;
		//	ChangeAngle();
		//}

		////右
		//if((sx1 < tx2) && (sx2 < tx2 + (erea.Width / 4)))
		//{
		//	BallAngle = (1 - BallAngle) + 0.5f;
		//	if (BallAngle > 1) BallAngle -= 1.0f;
		//	ChangeAngle();
		//}

		BallAngle = (1 - BallAngle) + 0.5f;
		if (BallAngle > 1) BallAngle -= 1.0f;
		ChangeAngle();

		////下
		//if ((sy2 > ty1) && (sy2 < ty2 + (erea.Height / 4)))
		//{
		//	BallAngle = (1 - BallAngle)+0.5f;

		//	ChangeAngle();
		//}

		//上
		if ((sy1 < ty2) && (sy1 > sy1 - (erea.Height / 4)))
		{
			BallAngle = (1 - BallAngle);
			ChangeAngle();
		}

		re = true;
	}

	return re;
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

	//DrawFormatString(0, 280, GetColor(255, 255, 255), " 雷 Hit! :%d", HitFlg);

	DrawFormatString(0, 300, GetColor(255, 255, 255), " 雷発生 :%d", S_Seconas2);
	DrawFormatString(0, 320, GetColor(255, 255, 255), " flg :%d", flg);

	//DrawBox(BallX + 2, BallY + 4, BallX + 28, BallY + 26, GetColor(255, 0, 0), FALSE);

	DrawLine(BallX + 2, BallY + 4, BallX + 2, BallY + 26, GetColor(255, 0, 0), 1);
	DrawLine(BallX + 28, BallY + 4, BallX + 28, BallY + 26, GetColor(255, 0, 0), 1);
	DrawLine(BallX + 2, BallY + 4, BallX + 28, BallY + 4, GetColor(255, 255, 255), 1);
	DrawLine(BallX + 2, BallY + 26, BallX + 28, BallY + 26, GetColor(255, 255, 255), 1);
}
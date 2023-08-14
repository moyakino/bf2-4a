#pragma once
#include "BoxCollider.h"

//プレイヤー 待機中アニメーション (風船が二つの場合)
#define STAND_BY_BALLOON2_0 0
#define STAND_BY_BALLOON2_1 1
#define STAND_BY_BALLOON2_2 2
#define STAND_BY_BALLOON2_3 3

//プレイヤー 待機中アニメーション (風船が一つの場合)
#define STAND_BY_BALLOON1_0 4
#define STAND_BY_BALLOON1_1 5
#define STAND_BY_BALLOON1_2 6
#define STAND_BY_BALLOON1_3 7

//プレイヤー X軸方向の移動アニメーション (風船が二つの場合)
#define RUN_BALLOON2_0 8
#define RUN_BALLOON2_1 9
#define RUN_BALLOON2_2 10
#define RUN_BALLOON2_3 11
#define RUN_BALLOON2_4 12

//プレイヤー X軸方向の移動アニメーション (風船が一つの場合)
#define RUN_BALLOON1_0 13
#define RUN_BALLOON1_1 14
#define RUN_BALLOON1_2 15
#define RUN_BALLOON1_3 16

//プレイヤー Y軸方向の浮上アニメーション (風船が二つの場合)
#define LEVITATION_BALLOON2_0 17
#define LEVITATION_BALLOON2_1 18
#define LEVITATION_BALLOON2_2 19
#define LEVITATION_BALLOON2_3 20
#define LEVITATION_BALLOON2_4 21

//プレイヤー Y軸方向の浮上アニメーション (風船が一つの場合)
#define LEVITATION_BALLOON1_0 22
#define LEVITATION_BALLOON1_1 23
#define LEVITATION_BALLOON1_2 24
#define LEVITATION_BALLOON1_3 25
#define LEVITATION_BALLOON1_4 26

//プレイヤー やられアニメーション
#define FALL_0 27
#define FALL_1 28
#define FALL_2 29
#define FALL_3 30

//スティックの傾き具合からプレイヤーの状態を取得
#define LEFT_MOVE -2000
#define RIGHT_MOVE 2000

class PLAYER :public BoxCollider
{
private:
	//(仮)プレイヤー画像 分割読み込み用変数
	int		P_ArrayImg[33];

	//(仮)プレイヤー画像 描画用変数
	int		P_Img;

	//(仮)左スティック
	int		P_L_Stick;
	//(仮)左スティックが倒されているか
	int		P_L_Stick_Flg;

	//(仮)デジタル方向ボタン右
	int		P_Right_Btn;
	//(仮)デジタル方向ボタン左
	int		P_Left_Btn;
	//(仮)Aボタン
	int		P_A_Btn;	//単押し

	//(仮)Bボタン長押し
	int		P_B_Btn;

	//(仮)Yボタン単押し
	int		P_Y_Btn;
	//(仮)やられアニメーションの再生
	int		Beaten_Flg;
	int		AnimCnt;

	//(仮)
	int		P_A_BtnFlg;
	int		P_Air_R_Flg;
	int		P_Air_L_Flg;

	//プレイヤーの地上スピード X座標
	float	P_XSpeed;
	//プレイヤーの地上スピード Y座標
	float	P_YSpeed;

	//(仮)プレイヤー右移動フラグ 移動無し:0 右移動:1
	int		P_MoveR_Flg;
	//(仮)プレイヤー左移動フラグ 移動無し:0 左移動:1
	int		P_MoveL_Flg;
	//(仮)風船情報 1:2個 0:1個
	int		P_Balloon_Flg;
	int		Respawn_Flg;

	//FPSと秒数カウント
	int		P_FPS;
	int		P_Seconas1;
	int		FishCnt;
	int		F_Seconas1;
	int		MouseX;
	int		MouseY;

	int rand;

public:
	//立っている状態のフラグ
	static int		P_Stand_Flg;
	//Player  X座標用変数
	static float	P_Move_X;
	//Player  Y座標用変数
	static float	P_Move_Y;
	static int		FishFlg;
	/*(仮)画像の左右反転用フラグ FALSE:普通に描画 TRUE:左右反転*/
	static	int		P_TurnFlg;
	static	int		F_TurnFlg;
	static	int		zanki;

	//コンストラクタ
	PLAYER();

	//デストラクタ
	~PLAYER();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;

		//関数化
	void Player_Warp();
	void Player_Img();
	void Player_Move();
	void Player_Gravity();
	void Player_Levitation_Move();
	void Player_Air_A();
	void Player_Air_B();

	//Player初期処理
	void Player_Init();
	//Playerのリスポーンアニメーション
	void Respawn_Anim();
	//Playerの待機状態中のアニメーション
	void Stand_by_Anim();
	//Playerが走っている時のアニメーション
	void Run_Anim();
	//Playerが滑空している時のアニメーション 
	void Gliding_Anim();
	//Playerが上昇している時のアニメーション
	void Rise_Anim_A();
	void Rise_Anim();
	//Playerやられアニメーション
	void Beaten_Anim();
	//Playerが地面についているかを取る
	void Stand_Foot();

	void SetStandFlg(bool b) { P_Stand_Flg = b; }

	Location GetLocation() { return location; }

};
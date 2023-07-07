#pragma once
//プレイヤーの待機中アニメーション (風船が二つの場合)
#define P_STAND_BY_BL2_ANIM_0 0
#define P_STAND_BY_BL2_ANIM_1 1
#define P_STAND_BY_BL2_ANIM_2 2
//プレイヤーの待機中アニメーション (風船が一つの場合)
#define P_STAND_BY_BL1_ANIM_0 3
#define P_STAND_BY_BL1_ANIM_1 4
#define P_STAND_BY_BL1_ANIM_2 5
//プレイヤーの X軸方向の移動アニメーション
#define P_RUNNING_ANIM_0 8
#define P_RUNNING_ANIM_1 9
#define P_RUNNING_ANIM_2 10
#define P_RUNNING_ANIM_3 11
//プレイヤーの Y軸方向の浮上アニメーション
#define P_FLY_TO_THE_SKY_ANIM_0 16
#define P_FLY_TO_THE_SKY_ANIM_1 17
#define P_FLY_TO_THE_SKY_ANIM_2 18
#define P_FLY_TO_THE_SKY_ANIM_3 19
#define P_FLY_TO_THE_SKY_ANIM_4 20

//スティックの傾き具合からプレイヤーの状態を取得
#define P_LEFT_MOVE -2000
#define P_RIGHT_MOVE 2000

//プレイヤーの走るスピード
#define P_RUN_SPEED 1
#define P_SPEED_UP  0.2
#define P_SPEED_UP1 0.2

class PLAYER
{
private:
	//(仮)プレイヤー画像 分割読み込み用変数
	int		P_PlayerImg[33];

	//(仮)プレイヤー画像 描画用変数
	int		P_Img;

	//(仮)左スティック
	int		P_L_Stick;

	//(仮)デジタル方向ボタン右
	int		P_Right_Btn;
	//(仮)デジタル方向ボタン左
	int		P_Left_Btn;
	//(仮)Aボタン
	int		P_A_Btn;

	//Player  X座標用変数
	float		P_Move_X;
	//Player  Y座標用変数
	float	P_Move_Y;
	//プレイヤーのスピード
	float	P_Speed;

	//(仮)プレイヤー右移動フラグ 移動無し:0 右移動:1
	int		P_MoveR_Flg;
	//(仮)プレイヤー左移動フラグ 移動無し:0 左移動:1
	int		P_MoveL_Flg;
	//(仮)プレイヤー浮上フラグ
	int		P_Air_Flg;
	//(仮)風船情報 1:2個 0:1個
	int		P_Balloon_Flg;
	//(仮)画像の左右反転用フラグ FALSE:普通に描画 TRUE:左右反転
	int		P_TurnFlg;

	//FPSと秒数カウント
	int		P_FPS;
	int		P_Seconas;
	

public:
	PLAYER();

	//デストラクタ
	~PLAYER();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;
	
	//プレイヤーの右移動処理
	//int P_Move_Flg();
	//Playerの待機状態中のアニメーション
	int Stand_by_Anim();
	//Playerが走っている時のアニメーション
	int Run_Anim();
	
};
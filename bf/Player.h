#pragma once
//プレイヤー 待機中アニメーション (風船が二つの場合)
#define STAND_BY_BALLOON2_0 0
#define STAND_BY_BALLOON2_1 1
#define STAND_BY_BALLOON2_2 2

//プレイヤー 待機中アニメーション (風船が一つの場合)
#define STAND_BY_BALLOON1_0 3
#define STAND_BY_BALLOON1_1 4
#define STAND_BY_BALLOON1_2 5

//プレイヤー X軸方向の移動アニメーション (風船が二つの場合)
#define RUN_BALLOON2_0 8
#define RUN_BALLOON2_1 9
#define RUN_BALLOON2_2 10
#define RUN_BALLOON2_3 11

//プレイヤー X軸方向の移動アニメーション (風船が一つの場合)
#define RUN_BALLOON1_0 12
#define RUN_BALLOON1_1 13
#define RUN_BALLOON1_2 14
#define RUN_BALLOON1_3 15

//プレイヤー Y軸方向の浮上アニメーション (風船が二つの場合)
#define LEVITATION_BALLOON2_0 16
#define LEVITATION_BALLOON2_1 17
#define LEVITATION_BALLOON2_2 18
#define LEVITATION_BALLOON2_3 19
#define LEVITATION_BALLOON2_4 20

//プレイヤー Y軸方向の浮上アニメーション (風船が一つの場合)
#define LEVITATION_BALLOON1_0 24
#define LEVITATION_BALLOON1_1 25
#define LEVITATION_BALLOON1_2 26
#define LEVITATION_BALLOON1_3 27
#define LEVITATION_BALLOON1_4 28

//プレイヤー 落下アニメーション
#define FALL_0 21
#define FALL_1 22
#define FALL_2 23

//プレイヤー 雷やられアニメーション
#define THUNDER_0 29
#define THUNDER_1 30

//スティックの傾き具合からプレイヤーの状態を取得
#define LEFT_MOVE -2000
#define RIGHT_MOVE 2000

//プレイヤーの走るスピード
#define RUN_SPEED 1
#define SPEED_UP  0.2
#define SPEED_UP1 0.2

class PLAYER
{
private:
	//(仮)プレイヤー画像 分割読み込み用変数
	int		P_ArrayImg[33];

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
	//(仮)Aボタン長押し
	int		P_A_Pressed;

	//Player  X座標用変数
	float	P_Move_X;
	//Player  Y座標用変数
	float	P_Move_Y;
	//プレイヤーの地上スピード
	float	P_Speed;
	//プレイヤーの空中スピード
	float	P_AirSpeed;

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
	int		P_Seconas1;
	
	int MouseX;
	int MouseY;

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
	//Playerが浮上している時のアニメーション 
	int Levitation_Anim1();
	int Levitation_Anim2();
};
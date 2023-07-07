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


//X座標の Stick の初期値
#define STICK_X_INITIAL_VALUE 128
#define P_MOVE_Y 350


#define e 0.800		//反発係数
#define g 0.900		//重力加速度

class Player
{
private:

	//Player x y 座標用変数
	int P_Move_X;
	float P_Move_Y;

	//プレイヤー画面端(仮)
	/*int P_Left;
	int P_Move_X_Left;*/


	//(仮)プレイヤー画像用変数
	int P_PlayerImg[33];
	//(仮)プレイヤー出力用変数
	int P_Img;

	//(仮)プレイヤー右移動フラグ 移動無し:0 右移動:1
	int P_MoveR_Flg;
	//(仮)プレイヤー左移動フラグ 移動無し:0 右移動:1
	int P_MoveL_Flg;
	//(仮)空中にいるかの判定フラグ
	int P_Air_Flg;
	//画像を反転するかどうかのフラグ
	int Trun_Flg;

	//FPSと秒数カウント
	int P_FPS;
	int P_FPS_INC;
	int P_FPS_FLY;

	int P_AnimL_Flg;
	int P_AnimR_Flg;
	//(仮)待機中専用フラグ
	int P_Std_Anim_Flg;

	float P_Air_Multiply;

	int a;

public:
	Player();

	//デストラクタ
	~Player();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;
	
	//Playerの待機中
	int Stand_by_Anim();
	//Playerが浮上している時のアニメーション
	int Fly_To_The_Sky_Anim_1();

	//仮
	int Fly_To_The_Sky_Anim_2();

	//Playerが走っている時のアニメーション
	int Running_Anim();

	//Playerの X座標 Y座標 を戻り値として返す
	int R_Player_MoveX()const;
	float R_Player_MoveY()const;
};
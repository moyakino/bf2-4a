#pragma once

#define e 0.800		//反発係数
#define g 0.900		//重力加速度

class Player
{
private:

	//Aボタンの格納用変数
	//int L_Stick_X;
	//int L_Stick_Y;
	//Player x y 座標用変数
	int P_Move_X;
	int P_Move_Y;
	//(仮)プレイヤー画像用変数
	int D_PlayerImg[3];

	int P_PlayerImg[33];

	int P_Img;

	//(仮)プレイヤー右移動フラグ 移動無し:0 右移動:1
	int P_MoveR_Flg;
	//(仮)プレイヤー左移動フラグ 移動無し:0 右移動:1
	int P_MoveL_Flg;


public:
	Player();

	//デストラクタ
	~Player() { };

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;

	//アニメーション
	int Animation(int Anim1, int Anim2);

	//Playerの待機中
	int Stand_by_Anim();

	//Playerの X座標 Y座標 を戻り値として返す
	int R_Player_MoveX()const;
	int R_Player_MoveY()const;
};
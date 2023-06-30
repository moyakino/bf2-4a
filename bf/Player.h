#pragma once

class Player
{
private:

	//Aボタンの格納用変数
	int L_Stick_X;
	int L_Stick_Y;
	//Player x y 座標用変数
	int P_Move_X;
	int P_Move_Y;
	//(仮)プレイヤー画像用変数
	int D_PlayerImg;

public:
	Player();

	//デストラクタ
	~Player() { };

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;
};
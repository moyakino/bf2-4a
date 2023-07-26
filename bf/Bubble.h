#pragma once

class Bubble {
private:
	//シャボン玉の画像（仮）
	int BubbleImg[4];
	int B_Img;
	int Bubbleflg;
	int B_flg;
	int H_flg;
	//シャボン玉の初期位置
	float MoveX;
	float MoveY;
	//プレイヤー座標
	float PlayerX;
	float PlayerY;
    //シャボン玉の動き
	float SpeedY;
    float SpeedX;
	int B_FPS;
	int seconds;
	int HitBox;
public:
	Bubble();

	//デストラクタ
	~Bubble() { };

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;


	int BubbleControl();
	int  Hit();
	//PLAYER* player;
};

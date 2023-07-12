#pragma once
class Bubble{
private:
	//シャボン玉の画像（仮）
	int BubbleImg;
	int BallFlg;
	//シャボン玉の初期位置
	int X, Y;
	//シャボン玉の座標更新
	int BallX;
	int BallY;
	//シャボン玉の動く距離
	int MoveX;
	int MoveY;
	//重力
	int Speed;
public:
	Bubble();

	//デストラクタ
	~Bubble() { };

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;
};

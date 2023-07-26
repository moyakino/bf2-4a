#pragma once
//シャボン玉のアニメーション
#define Bubble_Anim_0 0
#define Bubble_Anim_1 1
#define Bubble_Anim_2 2
#define Bubble_Anim_3 3

class Bubble {
private:
	//シャボン玉の画像（仮）
	int BubbleImg[3];
	int B_Img;
	int Bubbleflg;
	int B_flg;
	//シャボン玉の初期位置
	float MoveX;
	float MoveY;
    //シャボン玉の動き
	float SpeedY;
    float SpeedX;
	int B_FPS;
	int seconds;
	int tick;
	int i;
public:
	Bubble();

	//デストラクタ
	~Bubble() { };

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;

	int BubbleControl(void);
};

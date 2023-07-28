#pragma once

class Bubble {
private:
	int BubbleImg[4];
	int B_Img;
	int Bubbleflg;
	int B_flg;
	int H_flg;
	int Img;
	int B_AnimImg;
	float MoveX;
	float MoveY;
	int B_FPS;
	int seconds;
	int HitBox;
	float Player;
	float PlayerY;
	int D_flg;
	int F_flg;
	int FontHandle;
	int Delete;
	int SpeedX,SpeedY;
public:
	Bubble();
	~Bubble();
	void Update();
	void Draw()const;
	int BubbleControl();
	void  Hit();
	void BubbleMove();
	int  BubbleAnim();
	void Score();

};
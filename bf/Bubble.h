#pragma once
#include "BoxCollider.h"

class Bubble{
private:
	int BubbleImg[4];
	int B_Img;
	int Bubbleflg;
	int B_flg;
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
	float SpeedX,SpeedY;
	int BubbleScore;
public:

	static int H_flg;

	Bubble();
	~Bubble();
	void Update();
	void Draw()const;
	int BubbleControl();
	void  Check();
	void BubbleMove();
	int  BubbleAnim();
	void Score();
	void Hit();
	void Oncollision();
};
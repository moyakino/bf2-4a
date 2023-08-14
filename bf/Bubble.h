#pragma once
#define BUBBLEMOVE1 0
#define BUBBLEMOVE2 1
#define BUBBLEMOVE3 2

class Bubble {
private:
	int BubbleImg[4];
	int B_Img;
	int BubbleScoreImg;
	int BubbleMoveflg;
	int B_flg;
	int ScoreFlg;
	float MoveX;
	float MoveY;
	int B_FPS;
	int seconds;
	int D_flg;
	float SpeedX,SpeedY;
	int H_flg;

	float PlayerX, PlayerY;

public:

	Bubble();
	~Bubble();
	void Update(float x, float y);
	void Draw()const;
	void  Hit();
	void BubbleMove();
	void Score();
	void BubbleMoveAnim();
};
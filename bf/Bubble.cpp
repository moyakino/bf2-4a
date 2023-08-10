#include"DxLib.h"
#include"Bubble.h"
#include"Player.h"
#include"PadInput.h"
#include"FPS.h"

int Bubble::H_flg;

Bubble::Bubble()
{
	if (LoadDivGraph("images/stage/Stage_BubbleAnimation.png", 4, 4, 1, 64, 64, BubbleImg)) {}
	B_Img = BubbleImg[0];
	Bubbleflg = 0;
	B_flg = 0;
	H_flg = 0;
	Img = 0;
	B_AnimImg = 0;
	MoveX = 338;
	MoveY = 245;
	B_FPS = 0;
	seconds = 0;
	HitBox = 0;
	Player = 0.0f;
	PlayerY = 0.0f;
	FontHandle = 0;
	Delete = 0;
	SpeedX = 0.0f;
	SpeedY = 30.0f;
	
	
	D_flg = TRUE;
	F_flg = FALSE;
	
}
Bubble::~Bubble()
{
}
void Bubble::Update()
{


	Player = PLAYER::p_uc;
	PlayerY = PLAYER::py2 + PLAYER::py1;

	B_FPS++;

	if (CheckHitKey(KEY_INPUT_Z)) {
		B_flg = TRUE;
		BubbleMove();
	}
	if (MoveY <= -30) {
		MoveY = 245;
	}
	Hit();
	F_flg = FALSE;


	if (MoveY != 0 && B_flg == TRUE) {
		MoveY -= 0.09f;
		B_Img = BubbleControl();
		Hit();

	}


	if (B_FPS > 60) {
		if (B_FPS > 59) {
			B_FPS = 0;
			seconds++;
		}
		else if (seconds > 3) {
			seconds = 0;
		}
	}
}

void Bubble::Draw() const {

	DrawRotaGraphF(MoveX, MoveY, 1.0f, 1.0, B_Img, TRUE);
	/*DrawBoxAA(MoveX - 15, MoveY - 15, MoveX + 15, MoveY + 15, GetColor(255, 255, 255), FALSE);*/
	SetFontSize(14);
	DrawRotaGraphF(MoveX, MoveY, 1.0f, 1, B_Img, TRUE);
	DrawLineAA(MoveX - 15, MoveY - 15, MoveX - 15, MoveY + 15, GetColor(255, 0, 0), 1); //左
	DrawLineAA(MoveX + 15, MoveY - 15, MoveX + 15, MoveY + 15, GetColor(255, 0, 0), 1); //右
	DrawLineAA(MoveX - 15, MoveY - 15, MoveX + 15, MoveY - 15, GetColor(0, 255, 0), 1); //上
	DrawLineAA(MoveX - 15, MoveY + 15, MoveX + 15, MoveY + 15, GetColor(0, 255, 0), 1); //下
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Player X???W : %0.1f Y???W : %0.1f", Player, PlayerY);
	DrawFormatString(0, 300, GetColor(255, 255, 255), "MoveX:%0.1f MoveY:%0.1f", MoveX, MoveY);
	DrawFormatString(0, 320, GetColor(255, 255, 255), "Bubbleflg:%d", Bubbleflg);
	DrawFormatString(0, 340, GetColor(255, 255, 255), "H_flg:%d", H_flg);

}
int  Bubble::BubbleControl()
{
		int B_AnimImg = 0;
	if (B_FPS % 15 == 0 || B_FPS % 15 == 1 || B_FPS % 15 == 2 || B_FPS % 15 == 3 || B_FPS % 15 == 4) {
		B_AnimImg = BubbleImg[0];
	}
	else if (B_FPS % 15 == 5 || B_FPS % 15 == 6 || B_FPS % 15 == 7 || B_FPS % 15 == 8 || B_FPS % 15 == 9) {
		B_AnimImg = BubbleImg[1];
	}
	else if (B_FPS % 15 == 10 || B_FPS % 15 == 11 || B_FPS % 15 == 12 || B_FPS % 15 == 13 || B_FPS % 15 == 14) {
		B_AnimImg = BubbleImg[2];
	}
	return B_AnimImg;
}
void Bubble::Check()
{

	int Delete = 0;

	DrawFormatString(0, 360, GetColor(255, 255, 255), "Delete:%d", Delete);
	//if (PLAYER::px1 < MoveX - 15 && PLAYER::py1 < MoveY - 15 && MoveX - 15 < PLAYER::px2 && MoveY + 15 < PLAYER::py2 /*&& Delete == 0*/){
		H_flg = 1;
		if (H_flg == 1) {
			Score();
			DeleteGraph(B_Img);
			DrawFormatString(MoveX, MoveY, GetColor(255, 0, 0), "750");
			Delete++;
		}
	/*}*/
	/*else */{
		H_flg = 0;
	}
}
void Bubble::BubbleMove()
	{
		if (MoveX == 400) {
		SpeedX = 0.7f;
	}
	if (SpeedX <= 0) {
		Bubbleflg = 1;
	}
	if (SpeedX >= 10) {
		Bubbleflg = 0;
	}
	if (Bubbleflg == 1) {
		SpeedX++;
		MoveX++;;
	}
	else {
		SpeedX--;
		MoveX--;
	}
}
void Bubble::Score()
{

	if (B_FPS % 15 == 0 || B_FPS % 15 == 1 || B_FPS % 15 == 2 || B_FPS % 15 == 3 || B_FPS % 15 == 4 && D_flg == TRUE) {
		B_Img = BubbleImg[3];
	}
	else if (B_FPS % 15 == 5 || B_FPS % 15 == 6 || B_FPS % 15 == 7 || B_FPS % 15 == 8 || B_FPS % 15 == 9 && D_flg == TRUE) {
		B_Img = BubbleImg[3];
	}
	else if (B_FPS % 15 == 10 || B_FPS % 15 == 11 || B_FPS % 15 == 12 || B_FPS % 15 == 13 || B_FPS % 15 == 14 && D_flg == TRUE) {
		B_Img = BubbleImg[3];
	}
};
void Bubble::Hit()
{
	int Delete = 0;

	//if (location.x + 59 > MoveX - 15 && location.y + 10 > MoveY - 15 && MoveX - 15 > location.x + 59 && MoveY + 15 > location.x + 66    //プレイヤー　右　敵　左
	//	|| location.x + 5 > MoveX + 15 && location.y + 10 > MoveY - 15 && MoveX + 15 > location.x + 5 && MoveY - 15 > location.y + 66   //プレイヤー　左　敵　右
	//	|| location.x + 5 > MoveX + 15 && location.y + 10  >MoveY + 15 && MoveX + 15 > location.x + 59 && MoveY + 15 > location.y + 10  //プレイヤー　上　敵　下
	//	|| location.x + 5 > MoveX - 15 && location.y + 66 >MoveY - 15 && MoveX + 15 >location.x + 59 && MoveY - 15 > location.y + 66)//プレイヤー　下　敵　上
	//{
	if(0){
		
		DrawFormatString(0, 360, GetColor(255, 255, 255), "Delete:%d", Delete);
		//if (PLAYER::px1 < MoveX - 15 && PLAYER::py1 < MoveY - 15 && MoveX - 15 < PLAYER::px2 && MoveY + 15 < PLAYER::py2 /*&& Delete == 0*/){
		H_flg = 1;
		if (H_flg == 1) {
			Score();
			DeleteGraph(B_Img);
			DrawFormatStringF(MoveX, MoveY, GetColor(255, 0, 0), "750");
			Delete++;
		}
		/*}*/
		/*else */ {
			H_flg = 0;
		}
	}


}
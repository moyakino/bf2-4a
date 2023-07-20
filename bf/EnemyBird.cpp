#include "EnemyBird.h"
#include"DxLib.h"
#include"GameMain.h"


EnemyBird::EnemyBird()
{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_P)) {}
	/*if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_G)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_R)) {}*/
	x = 0;
	y = 0;
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(int playerx,int playery)
{
	//Player  X座標用変数
	float	E_Move_X;
	//Player  Y座標用変数
	float	E_Move_Y;
	x = playerx;
	y = playery;
}

void EnemyBird::Draw() const
{
	DrawGraph(x,y, E_ArrayImg_P[0],TRUE);
	
}

//int EnemyBird::Stand_by_Anim()
//{
//    int S_AnimImg = 0;
//
//    // 0 から 3 秒
//    if (P_Seconas1 == 0) {
//        S_AnimImg = E_ArrayImg[STAND_BY_BALLOON2_1];
//    }
//    else if (P_Seconas1 > 0 && P_Seconas1 < 2) {
//        S_AnimImg = E_ArrayImg[STAND_BY_BALLOON2_0];
//    }
//    else if (P_Seconas1 > 1 && P_Seconas1 < 3) {
//        S_AnimImg = E_ArrayImg[STAND_BY_BALLOON2_1];
//    }
//    else if (P_Seconas1 > 2 && P_Seconas1 < 4) {
//        S_AnimImg = E_ArrayImg[STAND_BY_BALLOON2_2];
//    }
//
//    return S_AnimImg;
//}


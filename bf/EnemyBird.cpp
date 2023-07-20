#include"DxLib.h"
#include"GameMain.h"
#include "EnemyBird.h"


EnemyBird::EnemyBird()
{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_P)) {}
	/*if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_G)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_R)) {}*/
	x = 0;
    y = 0;

    E_Move_X = 300.0f;
    E_Move_Y = 200.0f;

    //敵の座標
    ex1 = 0, ex2 = 0, ey1 = 0,ey2 = 0, e_uc = 0;
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(int playerx,int playery)
{
    PlayerPos = playerx, playery;
	//x = playerx;
	//y = playery;
    E_FPS++;

    if (E_FPS > 60) {
        E_FPS = 0;
        seconds++;
    }// P_FPS_INC は 秒数を取っている
    else if (seconds > 3) {
        seconds = 0;
    }
   
}

void EnemyBird::Draw() const
{
	DrawGraph(E_Move_X, E_Move_Y, E_ArrayImg_P[0],TRUE);
	
}
void EnemyBird::Stand_Foot()
{
    //足場の座標
    sx1 = 180;
    sx2 = sx1 + 280;
    sy1 = 285;
    sy2 = sy1 + 20;

    //中心
    e_uc = (ex1 + ex2) / 2;

    //空を飛んでいても飛んでいなくても着地させたい
    if (-53 <= e_uc && e_uc < 160 && 415 >= ey2 && ey2 >= 413 || 180 <= e_uc && e_uc <= 460 && 287 >= ey2 && ey2 >= 283 || 480 < e_uc && e_uc <= 740 && 415 >= ey2 && ey2 >= 413) {

        E_Stand_Flg = TRUE;
    }
    else {
        E_Stand_Flg = FALSE;
    }
}
//int EnemyBird::E_GetLocationX()
//{
//    return ex1;
//}
//
//int EnemyBird::E_GetLocationX()
//{
//    return ey1;
//}
//


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

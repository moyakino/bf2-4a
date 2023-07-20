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

    E_Move_X = 300.0f;
    E_Move_Y = 200.0f;
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(int playerx,int playery)
{

	//x = playerx;
	//y = playery;
    E_FPS++;
    if (E_FPS > 60) {
        E_FPS = 0;
        seconds++;
    }// P_FPS_INC ‚Í •b”‚ğæ‚Á‚Ä‚¢‚é
    else if (seconds > 3) {
        seconds = 0;
    }
    E_Move_X == playerx;
    E_Move_Y == playery;
}

void EnemyBird::Draw() const
{
	DrawGraph(E_Move_X, E_Move_Y, E_ArrayImg_P[0],TRUE);
	
}
void EnemyBird::Stand_Foot()
{
    //‘«ê‚ÌÀ•W
    sx1 = 180;
    sx2 = sx1 + 280;
    sy1 = 285;
    sy2 = sy1 + 20;

    //’†S
    e_uc = (ex1 + ex2) / 2;

    //‹ó‚ğ”ò‚ñ‚Å‚¢‚Ä‚à”ò‚ñ‚Å‚¢‚È‚­‚Ä‚à’…’n‚³‚¹‚½‚¢
    if (-53 <= e_uc && e_uc < 160 && 415 >= ey2 && ey2 >= 413 || 180 <= e_uc && e_uc <= 460 && 287 >= ey2 && ey2 >= 283 || 480 < e_uc && e_uc <= 740 && 415 >= ey2 && ey2 >= 413) {

        E_Stand_Flg = TRUE;
    }
    else {
        E_Stand_Flg = FALSE;
    }
}

//int EnemyBird::Stand_by_Anim()
//{
//    int S_AnimImg = 0;
//
//    // 0 ‚©‚ç 3 •b
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


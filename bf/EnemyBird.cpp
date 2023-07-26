#include"DxLib.h"
#include"GameMain.h"
#include "EnemyBird.h"
#include"Player.h"
#include<math.h>

EnemyBird::EnemyBird()
{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_P)) {}
	/*if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_G)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_R)) {}*/
	x = 0;
    y = 0;

    E_Move_X = 200.0f;
    E_Move_Y = 200.0f;

    //敵の座標
    ex1 = 0, ex2 = 0, ey1 = 0,ey2 = 0, e_uc = 0;

    E_FPS = 0;

    //空中でのスピード
    E_AirSpeed = 0.0;
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(int Return_MoveX, int Return_MoveY)
{
     PlayerPos= Return_MoveX, Return_MoveY;
	//x = playerx;
	//y = playery;
    E_FPS++;

    if (E_FPS > 479) {
        E_FPS = 0;
        if (E_FPS > 59) {
            seconds++;
        }
    }// P_FPS_INC は 秒数を取っている
    else if (seconds > 3) {
        seconds = 0;
    }

    //プレイヤーに追尾する
    Chase();

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
void EnemyBird::Chase()
{
    float E_Speed = 0.2f;
    EnemyPos = E_Move_X, E_Move_Y;

    // プレイヤーと敵の距離を計算
    int distance = static_cast<int>(sqrt(ex1 * ex2 + ey1 * ey2));

    if (PlayerPos == EnemyPos) {
        E_Air_Flg = TRUE;
        E_Move_X = E_Move_X +0.2f;
    }
    else if (PlayerPos>=EnemyPos) {
        E_Air_Flg = FALSE;
        EnemyPos + 0.5f;
    }

    // 移動
    enemy.x += E_Move_X;
    enemy.y += E_Move_Y;


}

int EnemyBird::Return_MoveX()
{
    return E_Move_X;
}
int EnemyBird::Return_MoveY()
{
    return E_Move_Y;
}

void EnemyBird::Draw() const
{
    DrawGraph(E_Move_X, E_Move_Y, E_ArrayImg_P[0], TRUE);

    //敵の当たり判定
    DrawBox(E_Move_X + 30, E_Move_Y + 37, E_Move_X + 35, E_Move_Y + 65, GetColor(255, 255, 255), FALSE);

    ////風船の当たり判定
    //DrawBox(E_Move_X + 15, E_Move_Y + 5, E_Move_X + 59, E_Move_Y + 37, GetColor(255, 255, 255), FALSE);

    //DrawBox(ex1, ey1, ex2, ey2, GetColor(255, 0, 0), FALSE);

}
//int PLAYER::Return_MoveX()const
//{
//    return P_Move_X;
//}
//
//int PLAYER::Return_MoveY()const
//{
//    return P_Move_Y;
//}

//int EnemyBird::E_GetLocationX()
//{
//    return ex1;
//}
//
//int EnemyBird::E_GetLocationX()
//{
//    return ey1;
//}

//int EnemyBird::Stand_by_Anim()
//{
//    int E_AnimImg = 0;
//
//     0 から 3 秒
//    if (seconds == 0) {
//        E_AnimImg = E_ArrayImg_P[1];
//    }
//    else if (seconds > 0 && seconds < 2) {
//        E_AnimImg = E_ArrayImg_P[6];
//    }
//    else if (seconds > 1 && seconds < 3) {
//        E_AnimImg = E_ArrayImg_P[10];
//    }
//    else if (seconds > 2 && seconds < 4) {
//        E_AnimImg = E_ArrayImg_P[18];
//    }
//
//    return E_AnimImg;
//}

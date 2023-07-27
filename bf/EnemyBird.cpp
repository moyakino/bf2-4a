#include"DxLib.h"
#include"GameMain.h"
#include "EnemyBird.h"
#include"Player.h"
#include"PadInput.h"
#include<math.h>

EnemyBird::EnemyBird()
{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_P)) {}
	/*if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_G)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_R)) {}*/

   /* E_location_X = 200.0f;
    E_location_Y = 200.0f;*/
    E_Img = 0;
    E_Move_X = 200.0f;
    E_Move_Y = 220.0f;

    //E_MoveR_Flg = 0;
    //E_MoveL_Flg = 0;
    E_Air_Flg = 0;
    E_Balloon_Flg = 1;
  /*  E_TurnFlg = TRUE;*/
    E_A_BtnFlg = 0;
    E_Air_R_Flg = 0;
    E_Air_L_Flg = 0;

    E_Accele = 0.0f;
    E_Air_Multiply = 1.0f;

    //立ち状態フラグ
    E_Stand_Flg = FALSE;
    //落下状態フラグ
    E_Foll_Flg = 0;

    E_FPS = 0;
    SpeedX = 2;

    //敵の座標
    ex1 = 0, ex2 = 0, ey1 = 0,ey2 = 0, e_uc = 0;
    //地上のスピード
    E_XSpeed = 0.0f;
    E_YSpeed = 0.0f;

    //空中でのスピード
    E_AirSpeed = 0.0;

   /* E_Img = 0;*/
    E_L_Stick = 0;
    E_Right_Btn = 0;
    E_Left_Btn = 0;
    E_A_Btn = 0;
    E_B_Btn = 0;
    E_A_Pressed = 0;
    E_Seconas1 = 0;
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(int playerx, int playery)
{
   /*  PlayerPos= Return_MoveX, Return_MoveY;*/
	x = playerx;
	y = playery;
    E_FPS++;

    //if (E_FPS > 479) {
    //    E_FPS = 0;
    //    if (E_FPS > 59) {
    //        seconds++;
    //    }
    //}// P_FPS_INC は 秒数を取っている
    //else if (seconds > 3) {
    //    seconds = 0;
    //}
    // 
    // 
    //60fps == 1秒　で超えたら fpsを 0 にする
    if (E_FPS > 59) {
        E_FPS = 0;
        E_Seconas1++;
    }// P_FPS_INC は 秒数を取っている
    else if (E_Seconas1 > 3) {
        E_Seconas1 = 0;
    }
   
    ////プレイヤーに追尾する
    //Chase();
    Enemy_Levitation_Move_X();
    Enemy_Levitation_Move_Y();
    Enemy_Gravity();
    Enemy_Warp();
    Stand_Foot();

    if (E_Air_Flg == TRUE && E_Stand_Flg == FALSE) {
        Enemy_Levitation_Move_X();
        Enemy_Levitation_Move_Y();
    }
}

void EnemyBird::Draw() const
{
    DrawGraph(E_Move_X, E_Move_Y, E_ArrayImg_P[0], TRUE);

    //敵の当たり判定
    DrawBox(E_Move_X + 30, E_Move_Y + 37, E_Move_X + 35, E_Move_Y + 65, GetColor(255, 255, 255), FALSE);

    DrawFormatString(0, 160, GetColor(255, 255, 255), " enemy座標：X座標 %0.1f Y座標 %0.1f", E_Move_X, E_Move_Y);

    ////風船の当たり判定
    //DrawBox(E_Move_X + 15, E_Move_Y + 5, E_Move_X + 59, E_Move_Y + 37, GetColor(255, 255, 255), FALSE);

    //DrawBox(ex1, ey1, ex2, ey2, GetColor(255, 0, 0), FALSE);
}

void EnemyBird::Stand_Foot()
{
    //足場の座標
    sx1 = 180;
    sx2 = sx1 + 280;
    sy1 = 285;
    sy2 = sy1 + 20;
    SpeedX = 0;

    //敵の座標
    ex1 = E_Move_X;
    ex2 = E_Move_X + 64;
    ey1 = E_Move_Y;
    ey2 = E_Move_Y + 64;

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
void EnemyBird::Enemy_Warp()
{
    //左ワープ
    if (E_Move_X <= -53) {
        E_Move_X = 700;
    }
    //右ワープ
    else if (E_Move_X >= 700) {
        E_Move_X = -53;
    }

    //天井
    if (E_Move_Y <= -25) {
        E_Move_Y = 250;
    }
}

void EnemyBird::Enemy_Levitation_Move_X()
{
        
    if (E_Stand_Flg == FALSE) {
        if (E_Move_X >= PLAYER::P_Move_X) {
            SpeedX -= 0.5f;
        }
        if (E_Move_X <= PLAYER::P_Move_X) {
            SpeedX += 0.5f;
        }
        if (SpeedX <= -1.0f) {
            SpeedX = -0.1f;
        }
        if (SpeedX >= 1.0f) {
            SpeedX = 0.1f;
        }
    }
    if (E_Stand_Flg == TRUE) {
        SpeedX = 0;
    }
    E_Move_X += SpeedX;
}
void EnemyBird::Enemy_Levitation_Move_Y()
{
    if (E_Stand_Flg == FALSE) {
        if (E_Move_Y >= PLAYER::P_Move_Y) {
            SpeedY -= 0.1f;
        }
        if (E_Move_Y <= PLAYER::P_Move_Y) {
            SpeedY += 0.5f;
        }
        if (SpeedY <= -1.0f) {
            SpeedY = -0.1f;
        }
        if (SpeedY >= 1.0f) {
            SpeedY = 0.1f;
        }
    }
   /* if (E_Stand_Flg == TRUE) {
        SpeedY = 0;
        E_Img = Stand_by_Anim();
    }*/
    
    E_Move_Y += SpeedY;
}


void EnemyBird::Enemy_Gravity()
{
    E_Air_Flg = TRUE;
    E_YSpeed = E_YSpeed + 0.01f;
    E_location_Y = E_location_Y + E_YSpeed;
    if (E_YSpeed >= 1.0f) {//速度制限
        E_YSpeed = 1.0f;
    }
}


int EnemyBird::Stand_by_Anim()
{
    int S_AnimImg = 0;

    // 0 から 3 秒
    if (E_Seconas1 == 0) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_BALLOON1_1];
    }
    else if (E_Seconas1 > 0 && E_Seconas1 < 2) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_BALLOON1_1];
    }
    else if (E_Seconas1 > 0 && E_Seconas1 < 2) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_BALLOON1_2];
    }
    else if (E_Seconas1 > 1 && E_Seconas1 < 3) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_BALLOON1_3];
    }
    else if (E_Seconas1 > 1 && E_Seconas1 < 3) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_BALLOON1_4];
    }
    else if (E_Seconas1 > 2 && E_Seconas1 < 4) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_BALLOON1_5];
    }
    else if (E_Seconas1 > 2 && E_Seconas1 < 4) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_BALLOON1_6];
    }

    return S_AnimImg;
}
int EnemyBird::Levitation_Anim1()
{
    int F1_AnimImg = 0;

    // 5フレーム
    if (E_FPS % 20 == 0 || E_FPS % 20 == 1 || E_FPS % 20 == 2 || E_FPS % 20 == 3 || E_FPS % 20 == 4) {
        F1_AnimImg = E_ArrayImg_P[LEVITATION_BALLOON1_0];
    }
    else if (E_FPS % 20 == 5 || E_FPS % 20 == 6 || E_FPS % 20 == 7 || E_FPS % 20 == 8 || E_FPS % 20 == 9) {
        F1_AnimImg = E_ArrayImg_P[LEVITATION_BALLOON1_1];
    }
    else if (E_FPS % 20 == 10 || E_FPS % 20 == 11 || E_FPS % 20 == 12 || E_FPS % 20 == 13 || E_FPS % 20 == 14) {
        F1_AnimImg = E_ArrayImg_P[LEVITATION_BALLOON1_2];
    }
    else if (E_FPS % 20 == 15 || E_FPS % 20 == 16 || E_FPS % 20 == 17 || E_FPS % 20 == 18 || E_FPS % 20 == 19) {
        F1_AnimImg = E_ArrayImg_P[LEVITATION_BALLOON1_3];
    }
    else if (E_FPS % 20 == 20 || E_FPS % 20 == 21 || E_FPS % 20 == 22 || E_FPS % 20 == 23 || E_FPS % 20 == 24) {
        F1_AnimImg = E_ArrayImg_P[LEVITATION_BALLOON1_4];
    }

    return F1_AnimImg;
}

int EnemyBird::Return_MoveX()
{
    return E_location_X;
}
int EnemyBird::Return_MoveY()
{
    return E_location_Y;
}
//void EnemyBird::Chase()
//{
//
//   /* EnemyPos = E_Move_X, E_Move_Y;*/
//
//    // プレイヤーと敵の距離を計算
//  
//    int dx = PLAYER::P_Move_X - E_location_X;
//    int dy = PLAYER::P_Move_Y - E_location_Y;
//
//    int distance = static_cast<int>(sqrt(ex1 * ex2 + ey1 * ey2));
//
//    if (distance > 0) {
//        E_Move_X = dx * Speed / distance;
//        E_Move_Y = dy * Speed / distance;
//
//        // 移動
//        E_location_X += E_Move_X;
//        E_location_Y += E_Move_Y;
//    }
//
//    WaitTimer(16);
//
//   /* if (PlayerPos == EnemyPos) {
//      E_Air_Flg = TRUE;
//      E_Move_X = E_Move_X +0.2f;
//  }
//  else if (PlayerPos>=EnemyPos) {
//      E_Air_Flg = FALSE;
//      EnemyPos + 0.5f;
//  }*/
//
//}
////右移動
//if (E_L_Stick > RIGHT_MOVE || E_Right_Btn == 1) {
//    E_MoveR_Flg = TRUE;
//    E_XSpeed = 1.0f;
//    E_Move_X = E_Move_Y + E_XSpeed;
//   
//}
//else {
//    E_MoveR_Flg = FALSE;
//}

////左移動
//if (E_L_Stick < LEFT_MOVE || E_Left_Btn == 1) {
//    E_MoveL_Flg = TRUE;
//    E_XSpeed = -1.0f;
//    E_Move_X = E_Move_Y + E_XSpeed;
//   
//}
//else {
//    E_MoveL_Flg = FALSE;
//}

////待機中
//if (E_MoveL_Flg == FALSE && E_MoveR_Flg == FALSE) {
//    E_XSpeed = 0.0f;
//  
//}

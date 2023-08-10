#include"DxLib.h"
#include"GameMain.h"
#include "EnemyBird.h"
#include"Player.h"
#include"PadInput.h"
#include<math.h>

EnemyBird::EnemyBird()

{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_P)) {}
	if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_G)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_R)) {}

    E_AnimImg = 0;
    E_Move_X = 200.0f;
    E_Move_Y = 220.0f;

    E_Balloon_Flg = 1;
  /*  E_TurnFlg = TRUE;*/

    E_Air_Flg = FALSE;

    E_Accele = 0.0f;
    E_Air_Multiply = 1.0f;

    //立ち状態フラグ
    E_Stand_Flg = FALSE;
    //落下状態フラグ
    E_Foll_Flg = 0;

    E_FPS = 0;
    SpeedX = 0;
    SpeedY = 0;
    E_Speed = 0;

    //敵の座標
    ex1 = 0, ex2 = 0, ey1 = 0,ey2 = 0, e_uc = 0;
    sx1 = 0, sy1 = 0, sx2 = 0, sy2 = 0;
    //地上のスピード
    E_XSpeed = 0.0f;
    E_YSpeed = 0.0f;

    //空中でのスピード
    E_AirSpeed = 0.0f;

    E_Second = 0;
    CntWait = 0;
    Cnt = 0;

    E_Balloon_Flg = 0;
    EnemyState = ENEMY_STATE::START;
    
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update()
{

   /*  PlayerPos= Return_MoveX, Return_MoveY;*/
    E_FPS++;

    Enemy_Warp();
    
    if (EnemyState == ENEMY_STATE::FLY_LEFT) {
        Fly_Anim();
        Enemy_Levitation_Move_Y();
        Enemy_Levitation_Move_X();
    }

    if (EnemyState == ENEMY_STATE::START) {
        Start_Anim();
    }
    
    //if (E_Air_Flg == TRUE && E_Stand_Flg == FALSE) {
    //    SpeedY = SpeedY;
    //    //SpeedX = SpeedX;
    //    E_Move_Y = E_Move_Y + SpeedY;
    //    //E_Move_X = E_Move_X + SpeedX;
    //}

    //60fps == 1秒　で超えたら fpsを 0 にする
    if (E_FPS > 59) {
        E_FPS = 0;
        E_Second++;
    }// P_FPS_INC は 秒数を取っている
    else if (E_Second > 2) {
        E_Second = 0;
    }
   
    ////プレイヤーに追尾する
    //Chase();
    //
    //
    //Enemy_Gravity();
    
    //Stand_Foot();
    
    
 /*   Start_Anim();*/

    
}


void EnemyBird::Enemy_Levitation_Move_X()
{
    E_Air_Flg = TRUE;
    if (E_Stand_Flg == FALSE) {
        if (E_Move_X >= PLAYER::P_Move_X) {
            SpeedX -= 0.5f;
            EnemyState = ENEMY_STATE::FLY_LEFT;
        }
        if (E_Move_X <= PLAYER::P_Move_X) {
            SpeedX += 0.5f;
            EnemyState = ENEMY_STATE::FLY_RIGHT;
        }
        if (SpeedX <= -1.0f) {
            SpeedX = -0.1f;
            EnemyState = ENEMY_STATE::FLY_LEFT;
        }
        if (SpeedX >= 1.0f) {
            SpeedX = 0.1f;
            EnemyState = ENEMY_STATE::FLY_RIGHT;
        }
    }
    if (E_Stand_Flg == TRUE) {
        SpeedX = 0;
    }
    E_Move_X += SpeedX;
}
//void EnemyBird::Enemy_Levitation_Move_Y()
//{
//    E_Air_Flg = TRUE;
//    if (E_Stand_Flg == FALSE) {
//        if (E_Move_Y >= PLAYER::P_Move_Y) {
//            SpeedY -= 0.5f;
//
//        }
//        if (E_Move_Y <= PLAYER::P_Move_Y) {
//            SpeedY += 0.05f;
//        }
//        if (SpeedY <= -1.0f) {
//            SpeedY = -0.4f;
//
//        }
//        if (SpeedY >= 0.05f) {
//            SpeedY = 0.01f;
//        }
//    }
//    if (E_Stand_Flg == TRUE) {
//        SpeedY = 0;
//       /* EnemyState= ENEMY_STATE::START;*/
//    }
//    
//    E_Move_Y += SpeedY;
//}

//void EnemyBird::Enemy_Gravity()
//{
//    E_Air_Flg = TRUE;
//    E_YSpeed = E_YSpeed + 0.01f;
//    E_Move_Y = E_Move_Y + E_YSpeed;
//    if (E_YSpeed >= 1.0f) {//速度制限
//        E_YSpeed = 1.0f;
//    }
//}

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

    ////天井
    //if (E_Move_Y <= -25) {
    //    E_Move_Y = 250;
    //}

    if (E_Move_Y <= -25) {
        E_Move_Y = -20;
        if (SpeedY < 0) {
            SpeedY = SpeedY * -0.8f;
        }
    }
}


void EnemyBird::Start_Anim()
{
    EnemyState = ENEMY_STATE::START;
    int startTime = GetNowCount();
    int elapsedTime = GetNowCount() - startTime;
    if (elapsedTime >= 3000) {
        if (E_FPS % 120 == 0) {
            Cnt++;
            if (Cnt >= 8) {
                Cnt = 0;
            }
        }
    }
}
void EnemyBird::Fly_Anim()
{
    E_Air_Flg = TRUE;
    if (E_Stand_Flg == FALSE) {
        if (E_Move_X >= PLAYER::P_Move_X) {
            SpeedX -= 0.01f;
            EnemyState = ENEMY_STATE::FLY_LEFT;
        }
        if (E_Move_X <= PLAYER::P_Move_X) {
            SpeedX += 0.01f;
            EnemyState = ENEMY_STATE::FLY_RIGHT;
        }
        if (SpeedX <= -0.7f) {
            SpeedX = -0.7f;
        }
        if (SpeedX >= 0.7f) {
            SpeedX = 0.7f;
        }
    }
    /*if (E_Stand_Flg == TRUE) {
        SpeedX = 0;
    }*/
    E_Move_X += SpeedX;
}

void EnemyBird::Enemy_Levitation_Move_Y()
{
    E_Air_Flg = TRUE;
    if (E_Stand_Flg == FALSE) {
        if (E_Move_Y <= PLAYER::P_Move_Y) {
            SpeedY -= 0.01f;

        }
        /*if (E_Move_Y <= PLAYER::P_Move_Y) {
            SpeedY += 0.05f;
        }*/
        if (SpeedY <= -0.7f) {
            SpeedY = -0.7f;

        }
        /*if (SpeedY >= 0.05f) {
            SpeedY = 0.05f;
        }*/
    }
    /*if (E_Stand_Flg == TRUE) {
        SpeedY = 0;
        EnemyState= ENEMY_STATE::START;
    }*/
    
    /*if (E_Second == 0.0f) {
        E_Img = E_ArrayImg_P[STAND_BY_ENEMY_0];
    }
    else if (E_Second > 0.5f) {
        E_Img = E_ArrayImg_P[STAND_BY_ENEMY_1];
    }
}

void EnemyBird::Start_Anim()
{
    EnemyState = ENEMY_STATE::START;
    if (E_FPS % 60 == 0) {
        ++Cnt;
        if (Cnt > 7) {
            EnemyState = ENEMY_STATE::FLY_LEFT;
        }
    }
}

//上昇のみ
void EnemyBird::Fly_Anim()
{
    
    if (E_FPS % 20 == 0) {
        Cnt++;
        CntWait = 4;
        if (Cnt >= 13) {
            Cnt = 9;
        }
    }
   */
}

//int EnemyBird::Stand_by_Anim()
//{
//    int S_AnimImg = 0;
//
//    // 0 から 3 秒
//    if (E_Second == 0) {
//        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_0];
//    }
//    else if (E_Second > 0 && E_Second < 2) {
//        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_1];
//    }
//    else if (E_Second > 1 && E_Second < 3) {
//        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_2];
//    }
//    else if (E_Second > 2 && E_Second < 4) {
//        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_3];
//    }
//    else if (E_Second > 3 && E_Second < 5) {
//        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_4];
//    }
//
//    return S_AnimImg;
//}

void EnemyBird::Draw() const
{
   /* DrawGraphF(E_Move_X, E_Move_Y, E_Img, TRUE);*/

    //敵の当たり判定
    DrawBox(E_Move_X + 30, E_Move_Y + 37, E_Move_X + 35, E_Move_Y + 65, GetColor(255, 255, 255), FALSE);
    DrawFormatStringF(0, 160, GetColor(255, 255, 255), " enemy座標：X座標 %0.1f Y座標 %0.1f", E_Move_X, E_Move_Y);

    ////風船の当たり判定
    //DrawBox(E_Move_X + 15, E_Move_Y + 5, E_Move_X + 59, E_Move_Y + 37, GetColor(255, 255, 255), FALSE);
    //DrawBox(ex1, ey1, ex2, ey2, GetColor(255, 0, 0), FALSE);


    switch (EnemyState)
    {
    case  ENEMY_STATE::START:
        DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
        break;
    case  ENEMY_STATE::FLY_LEFT:
        DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
        break;
    case  ENEMY_STATE::FLY_RIGHT:
        DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
        break;
    case  ENEMY_STATE::FALL:
        DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
        break;
    case  ENEMY_STATE::WAIT:
        DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
        break;
    }
}

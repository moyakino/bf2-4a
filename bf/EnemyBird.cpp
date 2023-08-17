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

    location = 0;

    PlayerX = 0, PlayerY = 0;

    H_Flg = 0;
    EnemyFlyFlg = 0;
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(float x,float y)
{
    E_FPS++;

    /*if (E_Second == 12) {
        PlayerX = x;
        PlayerY = y;
    }*/
    /*else if (E_Second < 13 && E_Move_X == PlayerX -50 || E_Second < 13 && E_Move_Y == PlayerY) {
        PlayerX = x;
        PlayerY = y;
    }*/
    
    PlayerX = x;
    PlayerY = y;

    Enemy_Warp();

    //Hit();
    
    if (EnemyFlyFlg == TRUE) {
        Fly_Anim();
        Enemy_Levitation_Move_Y();
        Enemy_Levitation_Move_X();
    }

    if (EnemyState == ENEMY_STATE::START) {
        Start_Anim();
    }
    
    //60fps == 1秒　で超えたら fpsを 0 にする
    if (E_FPS > 59) {
        E_FPS = 0;
        E_Second++;
    }// P_FPS_INC は 秒数を取っている
    else if (E_Second > 12) {
        E_Second = 0;
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

    if (E_Move_Y <= -25) {
        E_Move_Y = -20;
        if (SpeedY < 0) {
            SpeedY = SpeedY * -0.8f;
        }
    }
}

void EnemyBird::Enemy_Levitation_Move_X()
{
   // E_Move_X + 10, E_Move_Y + 37, E_Move_X + 50, E_Move_Y + 65,
    
    //Playerが敵の真上にいる場合は、その時点で向いている方向に加速する
    if (E_Move_Y - 60 > PlayerY && PlayerY < E_Move_Y && E_Move_X < PlayerX && PlayerX < E_Move_X + 60) {
        if (EnemyState == ENEMY_STATE::FLY_LEFT) {
            SpeedX += -0.5f;
            E_Move_X += SpeedX;
            if (SpeedX <= -0.8f) {
                SpeedX = -0.8f;
            }
        }
        else {
            if (EnemyState == ENEMY_STATE::FLY_RIGHT) {
                SpeedX += 0.5f;
                E_Move_X += SpeedX;
                if (SpeedX >= 0.8f) {
                    SpeedX = 0.8f;
                }
            }
        }
    }
    else {
        //Playerが敵より左にいるときは左に敵が移動しようとする
        if (E_Move_X > PlayerX - 30) {
            E_Air_Flg = TRUE;
            //SpeedX += -0.02f;
            SpeedX += -0.09f;
            if (SpeedX <= -0.3f) {  // 0.4f
                SpeedX = -0.3f;
            }
            EnemyState = ENEMY_STATE::FLY_LEFT;
        }
        else {
            //Playerが敵より右にいるときは右に敵が移動しようとする
            if (E_Move_X - 30 < PlayerX) {
                E_Air_Flg = TRUE;
                //SpeedX += 0.02f;
                SpeedX += 0.09f;
                if (SpeedX >= 0.3f) {   // 0.4f
                    SpeedX = 0.3f;
                }
                EnemyState = ENEMY_STATE::FLY_RIGHT;
            }
        }

        E_Move_X += SpeedX;
    }
}

void EnemyBird::Enemy_Levitation_Move_Y()
{
    //Playerが敵より上にいるときは上昇し、下にいるときは上昇をやめる 上昇をやめるのは重力がかかるってこと？
    if (E_Move_Y > PlayerY) {
        if (E_FPS % 10 == 0) {
            E_Air_Flg = TRUE;
            //SpeedY -= 0.025f;
            SpeedY += -0.2;
            if (SpeedY <= -0.6f) { // 0.35f
                SpeedY = -0.6f;
            }
        }
    }
    else {
        //SpeedY+= 0.01f;
        SpeedY += 0.02f;
        if (SpeedY >= 0.4f) {   // 0.3f
            SpeedY = 0.4f;
        }
    }

    E_Move_Y += SpeedY;
}

void EnemyBird::Enemy_Just_Above()
{

}

//void EnemyBird::Enemy_Gravity()
//{
//    E_Air_Flg = TRUE;
//    E_YSpeed = E_YSpeed + 0.01f;
//    E_Move_Y = E_Move_Y + E_YSpeed;
//    if (E_YSpeed >= 1.0f) {//速度制限
//        E_YSpeed = 1.0f;
//    }
//}

void EnemyBird::Start_Anim()
{
    if (E_FPS % 30 == 0) {
        ++Cnt;
        if (Cnt > 7) {
            //EnemyState = ENEMY_STATE::FLY_LEFT;
            EnemyFlyFlg = TRUE;
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
}

void EnemyBird::Hit()
{
    if (PlayerX + 5 < E_Move_X - 20 && PlayerX + 57 > E_Move_X - 20 && PlayerY + 8 < E_Move_Y - 15 && PlayerY + 68 > E_Move_Y + 15 || //左
        PlayerX + 5 < E_Move_X + 20 && PlayerX + 57 > E_Move_X - 20 && PlayerY + 8 < E_Move_Y - 15 && PlayerY + 68 > E_Move_Y + 15 || //右
        PlayerX + 5 < E_Move_X - 20 && PlayerX + 57 > E_Move_X + 20 && PlayerY + 8 < E_Move_Y - 15 && PlayerY + 68 > E_Move_Y - 15 || //上
        PlayerX + 5 < E_Move_X - 20 && PlayerX + 57 > E_Move_X + 20 && PlayerY + 8 < E_Move_Y + 15 && PlayerY + 68 > E_Move_Y + 15) { //下

        //　上記の線がPlayerのBoxの範囲に入っていたら Hit!
        H_Flg = TRUE;
    }
}

void EnemyBird::Draw() const
{
    //ポーズ画面じゃないとき描写
    if (GameMain::PauseFlg == FALSE) {

        //DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);

        DrawFormatString(0, 280, GetColor(255, 255, 255), " 敵 Yspeed :%0.1f ", SpeedY);
        DrawFormatString(0, 300, GetColor(255, 255, 255), " 敵 Xspeed :%0.1f ", SpeedX);
        DrawFormatString(0, 320, GetColor(255, 255, 255), " 秒数      : %d ", E_Second);

        ////敵の当たり判定
        DrawBox(E_Move_X, E_Move_Y - 60, E_Move_X + 60, E_Move_Y, GetColor(255, 255, 255), FALSE);
        //DrawFormatStringF(0, 160, GetColor(255, 255, 255), " enemy座標：X座標 %0.1f Y座標 %0.1f", E_Move_X, E_Move_Y);

        ////風船の当たり判定
        //DrawBox(E_Move_X + 15, E_Move_Y + 5, E_Move_X + 59, E_Move_Y + 37, GetColor(255, 255, 255), FALSE);
        //DrawBox(ex1, ey1, ex2, ey2, GetColor(255, 0, 0), FALSE);
        // 
        //敵の当たり判定
        //DrawLine(E_Move_X + 10, E_Move_Y + 35, E_Move_X + 10, E_Move_Y + 65, GetColor(255, 0, 0), 1);		//左
        //DrawLine(E_Move_X + 55, E_Move_Y + 35, E_Move_X + 55, E_Move_Y + 65, GetColor(255, 0, 0), 1);		//右
        //DrawLine(E_Move_X + 10, E_Move_Y + 35, E_Move_X + 55, E_Move_Y + 35, GetColor(255, 255, 255), 1);	//上
        //DrawLine(E_Move_X + 15, E_Move_Y + 65, E_Move_X + 50, E_Move_Y + 65, GetColor(255, 255, 255), 1);	//下
        ////風船の当たり判定
        //DrawLine(E_Move_X + 15, E_Move_Y + 10, E_Move_X + 15, E_Move_Y + 35, GetColor(255, 255, 0), 1);		//左
        //DrawLine(E_Move_X + 50, E_Move_Y + 10, E_Move_X + 50, E_Move_Y + 35, GetColor(255, 255, 0), 1);		//右
        //DrawLine(E_Move_X + 5, E_Move_Y + 10, E_Move_X + 60, E_Move_Y + 10, GetColor(255, 255, 255), 1);	//上
        //DrawLine(E_Move_X + 5, E_Move_Y + 68, E_Move_X + 60, E_Move_Y + 68, GetColor(255, 255, 255), 1);	//下


        switch (EnemyState)
        {
        case  ENEMY_STATE::START:
            DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
            break;
        case  ENEMY_STATE::FLY_LEFT:
            DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
            break;
        case  ENEMY_STATE::FLY_RIGHT:
            DrawTurnGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
            break;
        case  ENEMY_STATE::FALL:
            DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
            break;
        case  ENEMY_STATE::WAIT:
            DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[Cnt], TRUE);
            break;
        }
    }
}

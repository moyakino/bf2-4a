#include"DxLib.h"
#include"GameMain.h"
#include "EnemyBird.h"
#include"Player.h"
#include"PadInput.h"
#include<math.h>

int EnemyBird::EnemyBoundY;

EnemyBird::EnemyBird(int num,int i)
{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_P)) {}
	if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_G)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_R)) {}

    //敵の生成
    switch (num)
    {
    case 0:
        switch (i)
        {
        case 0:
            location.x = 200.0f;
            location.y = 220.0f;
            erea.Width = 35;
            erea.Height = 50;
            E_Img = E_ArrayImg_P[0];
            break;

        case 1:
            location.x = 280.0f;
            location.y = 220.0f;
            erea.Width = 35;
            erea.Height = 50;
            E_Img = E_ArrayImg_P[0];
            break;

        case 2:
            location.x = 360.0f;
            location.y = 220.0f;
            erea.Width = 35;
            erea.Height = 50;
            E_Img = E_ArrayImg_P[0];
            break;
        }

        break;

    case 1:
        break;
    }

    E_AnimImg = 0;


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

    PlayerX = 0, PlayerY = 0;

    H_Flg = 0;
    EnemyFlyFlg = 0;
    EnemyBoundY = 0;
    EnemyHit = 0;
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(float x,float y)
{
    E_FPS++;
    
    PlayerX = x;
    PlayerY = y;

    Enemy_Warp();

    EnemybottomHit();
    
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
    if (location.x <= -53) {
        location.x = 700;
    }
    //右ワープ
    else if (location.x >= 700) {
        location.x = -53;
    }

    if (location.y < -25) {
        location.y = -20;
        if (SpeedY < 0) {
            SpeedY = SpeedY * -0.8f;
        }
    }
}

void EnemyBird::BoundPlusX()
{
    if (location.x != location.x + 5)
    {
        location.x += 0.1f;
    }

    if (E_XSpeed < 0) {
        E_XSpeed = (E_XSpeed * -1) * 0.8f;
    }
}

void EnemyBird::BoundMinusX()
{
    if (location.x != location.x - 5)
    {
        location.x -= 0.1f;
    }

    if (E_XSpeed > 0) {
        E_XSpeed = (E_XSpeed * -1) * 0.8f;
    }
}

void EnemyBird::BoundPlusY()
{
    if (location.y != location.y + 5)
    {
        location.y += 0.1f;
    }

    if (E_YSpeed < 0) {
        E_YSpeed = (E_YSpeed * -1) * 0.8f;
    }
}

void EnemyBird::BoundMinusY()
{
    if (location.y != location.y - 5)
    {
        location.y -= 0.1f;
    }

    if (E_YSpeed > 0) {
        E_YSpeed = (E_YSpeed * -1) * 0.8f;
    }
}

void EnemyBird::Enemy_Levitation_Move_X()
{
    //Playerが敵の真上にいる場合は、その時点で向いている方向に加速する
    if (location.y - 60 > PlayerY && PlayerY < location.y && location.x < PlayerX && PlayerX < location.x + 60) {
        if (EnemyState == ENEMY_STATE::FLY_LEFT) {
            SpeedX += -0.5f;
            location.x += SpeedX;
            if (SpeedX <= -0.8f) {
                SpeedX = -0.8f;
            }
        }
        else {
            if (EnemyState == ENEMY_STATE::FLY_RIGHT) {
                SpeedX += 0.5f;
                location.x += SpeedX;
                if (SpeedX >= 0.8f) {
                    SpeedX = 0.8f;
                }
            }
        }
    }
    else {
        //Playerが敵より左にいるときは左に敵が移動しようとする
        if (location.x > PlayerX - 30) {
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
            if (location.x - 30 < PlayerX) {
                E_Air_Flg = TRUE;
                //SpeedX += 0.02f;
                SpeedX += 0.09f;
                if (SpeedX >= 0.3f) {   // 0.4f
                    SpeedX = 0.3f;
                }
                EnemyState = ENEMY_STATE::FLY_RIGHT;
            }
        }

        location.x += SpeedX;
    }
}

void EnemyBird::Enemy_Levitation_Move_Y()
{
    //Playerが敵より上にいるときは上昇し、下にいるときは上昇をやめる 上昇をやめるのは重力がかかるってこと？
    if (location.y >  PlayerY) {
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

    location.y += SpeedY;
}

void EnemyBird::EnemybottomHit()
{
    if (PlayerX + 5 < location.x - 20 && PlayerX + 57 > location.x + 20 && PlayerY + 8 < location.y - 15 && PlayerY + 68 > location.y - 15){
        EnemyHit = TRUE;
    }
}

void EnemyBird::Enemy_Just_Above()
{

}


void EnemyBird::Start_Anim()
{
    if (E_FPS % 30 == 0) {
        ++Cnt;
        if (Cnt > 7) {
            //EnemyState = ENEMY_STATE::FLY_LEFT;
            EnemyFlyFlg = TRUE;
        }
    }

    E_Img = E_ArrayImg_P[Cnt];
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

    E_Img = E_ArrayImg_P[Cnt];

}

void EnemyBird::Draw() const
{
    //ポーズ画面じゃないとき描写
    if (GameMain::PauseFlg == FALSE) {

        DrawGraph(location.x, location.y, E_Img, TRUE);

       
    }
}

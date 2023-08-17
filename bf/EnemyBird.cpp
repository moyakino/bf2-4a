#include"DxLib.h"
#include"GameMain.h"
#include "EnemyBird.h"
#include"Player.h"
#include"PadInput.h"
#include<math.h>

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

   

}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update(float x,float y)
{
    E_FPS++;

    PlayerX = x;
    PlayerY = y;

    E_Move_X = location.x;
    E_Move_Y = location.y;

    Enemy_Warp();

    //Hit();
    
    if (EnemyState == ENEMY_STATE::FLY_LEFT) {
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
    else if (E_Second > 2) {
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

    if (E_Move_Y <= -25) {
        E_Move_Y = -20;
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
    E_Air_Flg = TRUE;

   // E_Move_X + 10, E_Move_Y + 37, E_Move_X + 50, E_Move_Y + 65,

    if (E_Stand_Flg == FALSE) {
        if (location.x + 10 <= PLAYER::P_Move_X && location.y + 37 <= PLAYER::P_Move_X + 10) {
            SpeedX -= 0.01f;
            if (SpeedX <= -0.2f) {
                SpeedX = -0.2f;
            }
            EnemyState = ENEMY_STATE::FLY_LEFT;
        }
        else {

        }
        if (location.x + 50 <= PLAYER::P_Move_X && location.y + 37 <= PLAYER::P_Move_Y + 37) {
            SpeedX += 0.01f;
            EnemyState = ENEMY_STATE::FLY_RIGHT;
        }
        if (SpeedX <= -0.7f) {
            SpeedX = -0.7f;
        }
        if (SpeedX >= 0.7f) {
            SpeedX = 0.7f;

            if (SpeedY <= -0.7f) {
                SpeedY = -0.7f;

            }
            if (SpeedY >= 0.05f) {
                SpeedY = 0.05f;
            }
        }
    }

    location.x += SpeedX;
}

void EnemyBird::Enemy_Levitation_Move_Y()
{
    E_Air_Flg = TRUE;
    if (E_Stand_Flg == FALSE) {
        if (location.y <= PLAYER::P_Move_Y) {
            SpeedY -= 0.01f;
            if (SpeedY <= -0.2f) {
                SpeedY = -0.2f;
            }

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
    location.y += SpeedY;
}

void EnemyBird::Enemy_Gravity()
{
    E_Air_Flg = TRUE;
    E_YSpeed = E_YSpeed + 0.01f;
    E_Move_Y = E_Move_Y + E_YSpeed;
    if (E_YSpeed >= 1.0f) {//速度制限
        E_YSpeed = 1.0f;
    }
}

void EnemyBird::Start_Anim()
{
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
}

//bool EnemyBird::Hit(BoxCollider* b_col)
//{
//
//    int re = false;
//
//    //if (PlayerX + 5 < E_Move_X - 20 && PlayerX + 57 > E_Move_X - 20 && PlayerY + 8 < E_Move_Y - 15 && PlayerY + 68 > E_Move_Y + 15 || //左
//    //    PlayerX + 5 < E_Move_X + 20 && PlayerX + 57 > E_Move_X - 20 && PlayerY + 8 < E_Move_Y - 15 && PlayerY + 68 > E_Move_Y + 15 || //右
//    //    PlayerX + 5 < E_Move_X - 20 && PlayerX + 57 > E_Move_X + 20 && PlayerY + 8 < E_Move_Y - 15 && PlayerY + 68 > E_Move_Y - 15 || //上
//    //    PlayerX + 5 < E_Move_X - 20 && PlayerX + 57 > E_Move_X + 20 && PlayerY + 8 < E_Move_Y + 15 && PlayerY + 68 > E_Move_Y + 15) { //下
//
//    //    //　上記の線がPlayerのBoxの範囲に入っていたら Hit!
//    //    H_Flg = TRUE;
//    //}
//
//     //プレイヤー
//    float px1 = b_col->GetLocation().x + 15;
//    float py1 = b_col->GetLocation().y + 15;
//    float px2 = px1 + b_col->GetErea().Width;
//    float py2 = py1 + b_col->GetErea().Height;
//
//    //敵
//    float ex1 = location.x + 15;
//    float ex2 = ex1 + erea.Width;
//    float ey1 = location.y + 15;
//    float ey2 = ey1 + erea.Height;
//
//    e_uc = (ey1 + ey2) / 2;
//
//    //当たり判定
//    if ((ex1 < px2) && (px1 < ex2) && (ey1 < py2) && (ey2 > py1))
//    {
//        if (((ey1 + ey2) / 2) > py2 && ey1 > ((py1 + py2) / 2))
//        {
//        
//            
//        }
//        if (((ey1 + ey2) / 2) < py2 && ((py1 + py2) / 2) > ey2) 
//        {
//            re = true;
//        }
//
//        if (((ey1 + ey2) / 2) == ((py1 + py2) / 2)) 
//        {
//
//        }
//
//    }
//
// 
//
//    return re;
//}


void EnemyBird::Draw() const
{
    //ポーズ画面じゃないとき描写
    if (GameMain::PauseFlg == FALSE) {

        DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[0], TRUE);
    DrawGraph(location.x, location.y, E_Img, TRUE);

    //当たり判定
    DrawBoxAA(location.x + 15, location.y + 15, location.x + 15 + erea.Width, location.y + 15 + erea.Height, GetColor(255, 255, 255), FALSE);
    DrawLine(location.x + 15, e_uc, location.x + 15 + erea.Width, e_uc, GetColor(255, 255, 255), 1);	//下


    //DrawFormatString(400, 50, GetColor(255, 0, 0), "H_Flg:%d", H_Flg);


        ////敵の当たり判定
        //DrawBox(E_Move_X + 30, E_Move_Y + 37, E_Move_X + 35, E_Move_Y + 65, GetColor(255, 255, 255), FALSE);
        //DrawFormatStringF(0, 160, GetColor(255, 255, 255), " enemy座標：X座標 %0.1f Y座標 %0.1f", E_Move_X, E_Move_Y);

    ////風船の当たり判定
    //DrawBox(E_Move_X + 15, E_Move_Y + 5, E_Move_X + 59, E_Move_Y + 37, GetColor(255, 255, 255), FALSE);
    //DrawBox(ex1, ey1, ex2, ey2, GetColor(255, 0, 0), FALSE);
    // 
    ////敵の当たり判定
    //DrawLine(E_Move_X + 10, E_Move_Y + 35, E_Move_X + 10, E_Move_Y + 65, GetColor(255, 0, 0), 1);		//左
    //DrawLine(E_Move_X + 55, E_Move_Y + 35, E_Move_X + 55, E_Move_Y + 65, GetColor(255, 0, 0), 1);		//右
    //DrawLine(E_Move_X + 10, E_Move_Y + 35, E_Move_X + 55, E_Move_Y + 35, GetColor(255, 255, 255), 1);	//上
    //DrawLine(E_Move_X + 15, E_Move_Y + 65, E_Move_X + 50, E_Move_Y + 65, GetColor(255, 255, 255), 1);	//下
    ////風船の当たり判定
    //DrawLine(E_Move_X + 15, E_Move_Y + 10, E_Move_X +15, E_Move_Y + 35, GetColor(255, 255, 0), 1);		//左
    //DrawLine(E_Move_X + 50, E_Move_Y + 10, E_Move_X + 50, E_Move_Y + 35, GetColor(255, 255, 0), 1);		//右
    //DrawLine(E_Move_X + 5, E_Move_Y + 10, E_Move_X + 60, E_Move_Y + 10, GetColor(255, 255, 255), 1);	//上
    //DrawLine(E_Move_X + 5, E_Move_Y + 68, E_Move_X + 60, E_Move_Y + 68, GetColor(255, 255, 255), 1);	//下



    //switch (EnemyState)
    //{
    //case  ENEMY_STATE::START:
    //    DrawGraphF(location.x, location.y, E_ArrayImg_P[Cnt], TRUE);
    //    break;
    //case  ENEMY_STATE::FLY_LEFT:
    //    DrawGraphF(location.x, location.y, E_ArrayImg_P[Cnt], TRUE);
    //    break;
    //case  ENEMY_STATE::FLY_RIGHT:
    //    DrawGraphF(location.x, location.y, E_ArrayImg_P[Cnt], TRUE);
    //    break;
    //case  ENEMY_STATE::FALL:
    //    DrawGraphF(location.x, location.y, E_ArrayImg_P[Cnt], TRUE);
    //    break;
    //case  ENEMY_STATE::WAIT:
    //    DrawGraphF(location.x, location.y, E_ArrayImg_P[Cnt], TRUE);
    //    break;
    //}
}

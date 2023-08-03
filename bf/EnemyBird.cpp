#include"DxLib.h"
#include"GameMain.h"
#include "EnemyBird.h"
#include"Player.h"
#include"PadInput.h"
#include<math.h>

EnemyBird::EnemyBird()

{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_P)){}
	if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_G)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg_R)) {}

   /* E_location_X = 200.0f;
    E_location_Y = 200.0f;*/
    E_AnimImg = 0;
    E_Move_X = 200.0f;
    E_Move_Y = 220.0f;

    //E_MoveR_Flg = 0;
    //E_MoveL_Flg = 0;
    E_Air_Flg = 0;
    E_Balloon_Flg = 1;
  /*  E_TurnFlg = TRUE;*/

    E_Air_Flg = FALSE;

    E_Accele = 0.0f;
    E_Air_Multiply = 1.0f;

    //������ԃt���O
    E_Stand_Flg = FALSE;
    //������ԃt���O
    E_Foll_Flg = 0;

    E_FPS = 0;
    SpeedX = 2;
    SpeedY = 0;
    E_Speed = 0;

    //�G�̍��W
    ex1 = 0, ex2 = 0, ey1 = 0,ey2 = 0, e_uc = 0;
    sx1 = 0, sy1 = 0, sx2 = 0, sy2 = 0;
    //�n��̃X�s�[�h
    E_XSpeed = 0.0f;
    E_YSpeed = 0.0f;

    //�󒆂ł̃X�s�[�h
    E_AirSpeed = 0.0f;

   /* E_Img = 0;*/
  
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

    //if (E_FPS > 479) {
    //    E_FPS = 0;
    //    if (E_FPS > 59) {
    //        seconds++;
    //    }
    //}// P_FPS_INC �� �b��������Ă���
    //else if (seconds > 3) {
    //    seconds = 0;
    //}

    //60fps == 1�b�@�Œ������� fps�� 0 �ɂ���
    if (E_FPS > 59) {
        E_FPS = 0;
        E_Second++;
    }// P_FPS_INC �� �b��������Ă���
    else if (E_Second > 3) {
        E_Second = 0;
    }
   
    ////�v���C���[�ɒǔ�����
    //Chase();
    Enemy_Levitation_Move_X();
    Enemy_Levitation_Move_Y();
    Enemy_Gravity();
    Enemy_Warp();
    Stand_Foot();
    Start_Anim();
    Fly_Anim();
 /*   Start_Anim();*/

    if (E_Air_Flg == TRUE && E_Stand_Flg == FALSE) {
        Enemy_Levitation_Move_X();
        Enemy_Levitation_Move_Y();
    }
}

void EnemyBird::Stand_Foot()
{
    //����̍��W
    sx1 = 180;
    sx2 = sx1 + 280;
    sy1 = 285;
    sy2 = sy1 + 20;
    SpeedX = 0;

    //�G�̍��W
    ex1 = E_Move_X;
    ex2 = E_Move_X + 64;
    ey1 = E_Move_Y;
    ey2 = E_Move_Y + 64;

    //���S
    e_uc = (ex1 + ex2) / 2;

    //�����ł��Ă����ł��Ȃ��Ă����n��������
    if (-53 <= e_uc && e_uc < 160 && 415 >= ey2 && ey2 >= 413 || 180 <= e_uc && e_uc <= 460 && 287 >= ey2 && ey2 >= 283 || 480 < e_uc && e_uc <= 740 && 415 >= ey2 && ey2 >= 413) {

        E_Stand_Flg = TRUE;
    }
    else {
        E_Stand_Flg = FALSE;
    }
}

void EnemyBird::Enemy_Warp()
{
    //�����[�v
    if (E_Move_X <= -53) {
        E_Move_X = 700;
    }
    //�E���[�v
    else if (E_Move_X >= 700) {
        E_Move_X = -53;
    }

    //�V��
    if (E_Move_Y <= -25) {
        E_Move_Y = 250;
    }
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
        }
        if (SpeedX >= 1.0f) {
            SpeedX = 0.1f;
        }
    }
  /*  if (E_Stand_Flg == TRUE) {
        SpeedX = 0;
    }*/
    E_Move_X += SpeedX;
}
void EnemyBird::Enemy_Levitation_Move_Y()
{
    E_Air_Flg = TRUE;
    if (E_Stand_Flg == FALSE) {
        if (E_Move_Y >= PLAYER::P_Move_Y) {
            SpeedY -= 0.5f;

        }
        if (E_Move_Y <= PLAYER::P_Move_Y) {
            SpeedY += 0.05f;
        }
        if (SpeedY <= -1.0f) {
            SpeedY = -0.1f;
        }
        if (SpeedY >= 0.05f) {
            SpeedY = 0.1f;
        }
    }
  /*  if (E_Stand_Flg == TRUE) {
        SpeedY = 0;
        EnemyState= ENEMY_STATE::START;
    }*/
    
    E_Move_Y += SpeedY;
}

void EnemyBird::Enemy_Gravity()
{
    E_Air_Flg = TRUE;
    E_YSpeed = E_YSpeed + 0.01f;
    E_Move_Y = E_Move_Y + E_YSpeed;
    if (E_YSpeed >= 1.0f) {//���x����
        E_YSpeed = 1.0f;
    }
}

void EnemyBird::Start_Anim()
{
    EnemyState = ENEMY_STATE::START;
    if (E_FPS % 20 == 0) {
        Cnt++;
        if (Cnt >= 8) {
            Cnt = 0;
        }
    }
}
void EnemyBird::Fly_Anim()
{
    EnemyState = ENEMY_STATE::FLY_LEFT;
    EnemyState = ENEMY_STATE::FLY_RIGHT;
    if (E_FPS % 20 == 0) {
        Cnt++;
        CntWait = 4;
        if (Cnt >= 13) {
            Cnt = 9;
        }
    }
}

int EnemyBird::Stand_by_Anim()
{
    int S_AnimImg = 0;

    // 0 ���� 3 �b
    if (E_Second == 0) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_0];
    }
    else if (E_Second > 0 && E_Second < 2) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_1];
    }
    else if (E_Second > 1 && E_Second < 3) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_2];
    }
    else if (E_Second > 2 && E_Second < 4) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_3];
    }
    else if (E_Second > 3 && E_Second < 5) {
        S_AnimImg = E_ArrayImg_P[STAND_BY_ENEMY_4];
    }

    return S_AnimImg;
}
void EnemyBird::Draw() const
{
    DrawGraphF(E_Move_X, E_Move_Y, E_ArrayImg_P[0], TRUE);

    //�G�̓����蔻��
    DrawBox(E_Move_X + 30, E_Move_Y + 37, E_Move_X + 35, E_Move_Y + 65, GetColor(255, 255, 255), FALSE);
    DrawFormatStringF(0, 160, GetColor(255, 255, 255), " enemy���W�FX���W %0.1f Y���W %0.1f", E_Move_X, E_Move_Y);

    ////���D�̓����蔻��
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

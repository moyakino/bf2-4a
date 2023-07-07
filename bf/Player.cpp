#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"

PLAYER::PLAYER()
{
    //プレイヤー画像データの読み込み
    if (LoadDivGraph("images/Player/Player_animation_d.png", 32, 8, 4, 64, 64, P_PlayerImg)){}
    P_Img = P_PlayerImg[1];
    P_L_Stick = 0;
    P_Right_Btn = 0;
    P_Left_Btn = 0;
    P_A_Btn = 0;
    P_Move_X = 100.0;
    P_Move_Y = 370.0;
    P_Speed = 0.0;
    P_MoveR_Flg = 0;
    P_MoveL_Flg = 0;
    P_Air_Flg = 0;
    P_Balloon_Flg = 1;
    P_TurnFlg = TRUE;
    P_FPS = 0;
    P_Seconas = 0;

}

void PLAYER::Update()
{
    //フレーム取得
    P_FPS++;

    //左スティック 右ボタン 左ボタンの状態取得
    P_L_Stick = PAD_INPUT::GetLStickX();
    P_Right_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT);
    P_Left_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT);
    P_A_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_A);

    //右移動
    if (P_L_Stick > P_RIGHT_MOVE && P_Air_Flg == FALSE || P_Right_Btn == 1) {
        P_MoveR_Flg = TRUE;
        P_TurnFlg = TRUE;
        //P_Move_X += 2;
        P_Img = PLAYER::Run_Anim();
        if (P_Speed <= 4.0f) {
            P_Speed = P_Speed + 0.1f;
            P_Move_X = P_Move_X + P_Speed;
        }
        else if(P_Speed >= 4.0f){
            P_Speed = 4.0f;
            P_Move_X = P_Move_X + P_Speed;
        }
    }
    else{
        P_MoveR_Flg = FALSE;
    }

    //左移動
    if (P_L_Stick < P_LEFT_MOVE && P_Air_Flg == FALSE || P_Left_Btn == 1) {
        P_MoveL_Flg = TRUE;
        P_TurnFlg = FALSE;
        //P_Move_X -= 2;
        P_Img = PLAYER::Run_Anim();
        if (P_Speed >= -4.0f) {
            P_Speed = P_Speed + -0.1f;
            P_Move_X = P_Move_X + P_Speed;
        }
        else if (P_Speed <= -4.0f) {
            P_Speed = -4.0f;
            P_Move_X = P_Move_X + P_Speed;
        }
    }
    else {
        P_MoveL_Flg = FALSE;
    }

    //待機中
    if (P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE && P_Air_Flg == FALSE) {
        P_Img = PLAYER::Stand_by_Anim();
        P_Speed = P_Speed * 0.95f;
        P_Move_X = P_Move_X + P_Speed;
    }
    
    //浮上
    if (P_A_Btn == 1) {
        P_Move_Y -= 20;
    }
    else {
        //重力
        if (P_A_Btn == 0 && P_Move_Y <= 350.0) {
            P_Move_Y += 0.3;
            //P_TurnFlg = P_Move_Flg();
            P_Air_Flg = TRUE;
        }
        else {
            P_Air_Flg = FALSE;
        }
    }

    //60fps == 1秒　で超えたら fpsを 0 にする
    if (P_FPS > 60) {
        P_FPS = 0;
        P_Seconas++;
    }// P_FPS_INC は 秒数を取っている
    else if (P_Seconas > 3) {
        P_Seconas = 0;
    }

    if (P_Move_X <= 0 || P_Move_X > 640) {
        if (P_Move_X <= -32) {
            P_Move_X = 640;
            //P_Left = TRUE;

        }
        if (P_Move_X > 640) {
            P_Move_X = -32;
        }
        else{
            //P_Left = FALSE;
        }

    }

    if (P_Move_Y < -10) {
        P_Move_Y = -10;
    }
}

int PLAYER::Stand_by_Anim()
{
    int S_AnimImg = 0;

    //プレイヤーの画像の切り替えは秒数にしている フレームだと点滅する
    if (P_Seconas == 0) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_1];
    }
    else if (P_Seconas > 0 && P_Seconas < 2) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_0];
    }
    else if (P_Seconas > 1 && P_Seconas < 3) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_1];
    }
    else if (P_Seconas > 2 && P_Seconas < 4) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_2];
    }

    return S_AnimImg;
}

int PLAYER::Run_Anim()
{
    int R_AnimImg = 0;

    if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_0];
    }
    else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_1];
    }
    else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_2];
    }
    else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_3];
    }

    return R_AnimImg;
}

PLAYER::~PLAYER()
{

}

void PLAYER::Draw()const
{
    //Aボタン描画
    DrawFormatString(0, 100, GetColor(255, 255, 255), " 押された瞬間：%d 離された瞬間：%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

    DrawFormatString(0, 120, GetColor(255, 255, 255), " 左スティック：横軸値 %d 縦軸値 %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

    DrawFormatString(0, 140, GetColor(255, 255, 255), " プレイヤー：X座標 %0.1f Y座標 %0.01f", P_Move_X, P_Move_Y);

    DrawFormatString(0, 160, GetColor(255, 255, 255), " 移動フラグ：左移動 %d 右移動 %d", P_MoveL_Flg, P_MoveR_Flg);

    DrawFormatString(330, 120, GetColor(255, 255, 255), " FPS：%d", P_FPS);

    // TurnFlag: 画像の左右反転を行うかのフラグ
    //DrawRotaGraph(P_Move_X, P_Move_Y, 1, 0, P_Img, TRUE, P_TurnFlg);

    //最初は右向きで描画される
    if (P_TurnFlg == TRUE) {
        DrawTurnGraph(P_Move_X, P_Move_Y, P_Img, TRUE);
    }
    else {
        if (P_TurnFlg == FALSE) {
            DrawGraph(P_Move_X, P_Move_Y, P_Img, TRUE);
        }
    }
}

#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"

PLAYER::PLAYER()
{
    //プレイヤー画像データの読み込み
    if (LoadDivGraph("images/Player/Player_animation_d.png", 32, 8, 4, 64, 64, P_ArrayImg)){}
    P_Img = 0;
    P_L_Stick = 0;
    P_Right_Btn = 0;
    P_Left_Btn = 0;
    P_A_Btn = 0;
    P_A_Pressed = 0;
    P_Move_X = 100.0;
    P_Move_Y = 350.0;
    P_Speed = 0.0;
    P_AirSpeed = 0.0;
    P_MoveR_Flg = 0;
    P_MoveL_Flg = 0;
    P_Air_Flg = 0;
    P_Balloon_Flg = 1;
    P_TurnFlg = TRUE;
    P_FPS = 0;
    P_Seconas1 = 0;
    MouseX = 0;
    MouseY = 0;
}

void PLAYER::Update()
{
    //フレーム取得
    P_FPS++;

    //マウスから座標を読み取る
    GetMousePoint(&MouseX, &MouseY);

    //左スティック 右ボタン 左ボタンの状態取得
    P_L_Stick = PAD_INPUT::GetLStickX();
    P_Right_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT);
    P_Left_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT);
    P_A_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_A);
    P_A_Pressed = PAD_INPUT::OnPressed(XINPUT_BUTTON_A);

    if (P_Move_X <= -30) {
        P_Move_X = 630;
    }
    else if (P_Move_X >= 630) {
        P_Move_X = -30;
    }

    //右移動
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        P_MoveR_Flg = TRUE;
        P_TurnFlg = TRUE;
        //P_Move_X += 2;
        P_Img = Run_Anim();
        //慣性
        if (P_Speed <= 2.0f) {
            P_Speed = P_Speed + 0.05f;
            P_Move_X = P_Move_X + P_Speed;
        }
        else if(P_Speed >= 2.0f){
            P_Speed = 2.0f;
            P_Move_X = P_Move_X + P_Speed;
        }
    }
    else{
        P_MoveR_Flg = FALSE;
    }

    //右空中移動
    if (P_Air_Flg == TRUE && P_L_Stick > RIGHT_MOVE || P_Air_Flg == TRUE && P_Right_Btn == 1) {
        P_TurnFlg = TRUE;
        //慣性
        if (P_AirSpeed <= 2.0f) {
            P_AirSpeed = P_AirSpeed + 0.05f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
        else if (P_AirSpeed >= 2.0f) {
            P_AirSpeed = 2.0f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
    }

    //右浮上移動
    if (P_A_Pressed == 1 && P_L_Stick > RIGHT_MOVE || P_A_Pressed == 1 && P_Right_Btn == 1) {
        P_TurnFlg = TRUE;
        P_Move_Y -= 0.5;
        P_Img = Levitation_Anim2();
        if (P_AirSpeed <= 3.0f) {
            P_AirSpeed = P_AirSpeed + 0.05f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
        else if (P_AirSpeed >= 3.0f) {
            P_AirSpeed = 3.0f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
    }

    //左移動
    if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        P_MoveL_Flg = TRUE;
        P_TurnFlg = FALSE;
        //P_Move_X -= 2;
        P_Img = Run_Anim();
        //慣性
        if (P_Speed >= -2.0f) {
            P_Speed = P_Speed + -0.05f;
            P_Move_X = P_Move_X + P_Speed;
        }
        else if (P_Speed <= -2.0f) {
            P_Speed = -2.0f;
            P_Move_X = P_Move_X + P_Speed;
        }
    }
    else {
        P_MoveL_Flg = FALSE;
    }

    //左空中移動
    if (P_Air_Flg == TRUE && P_L_Stick < LEFT_MOVE || P_Air_Flg == TRUE && P_Left_Btn == 1) {
        P_TurnFlg = FALSE;
        //慣性
        if (P_AirSpeed >= -2.0f) {
            P_AirSpeed = P_AirSpeed + -0.05f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
        else if (P_AirSpeed <= -2.0f) {
            P_AirSpeed = -2.0f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
    }

    //左浮上移動
    if (P_A_Pressed == 1 && P_L_Stick < LEFT_MOVE || P_A_Pressed == 1 && P_Left_Btn == 1) {
        P_TurnFlg = FALSE;
        P_Move_Y -= 0.5;
        P_Img = Levitation_Anim2();
        if (P_AirSpeed >= -3.0f) {
            P_AirSpeed = P_AirSpeed + -0.05f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
        else if (P_AirSpeed <= -3.0f) {
            P_AirSpeed = -3.0f;
            P_Move_X = P_Move_X + P_AirSpeed;
        }
    }
    

    //待機中
    if (P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE && P_Air_Flg == FALSE) {
        P_Img = Stand_by_Anim();
        //慣性
        P_Speed = P_Speed * 0.97f;
        P_Move_X = P_Move_X + P_Speed;
    }

    //浮上 ただ浮くだけ
    if (P_A_Btn == 1) {
        //インターバルをとる
        if (P_FPS % 3 == 0 || P_FPS % 3 == 1 || P_FPS % 3 == 2 || P_FPS % 3 == 3) {
            P_Img = Levitation_Anim1();
            P_Move_Y -= 10;
        }
    }
    else {
        //重力
        if (P_A_Btn == 0 && P_Move_Y <= 350.0) {
            P_Move_Y += 0.3;
            P_Speed = 0;
            P_Img = Levitation_Anim2();
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
        P_Seconas1++;
    }// P_FPS_INC は 秒数を取っている
    else if (P_Seconas1 > 3) {
        P_Seconas1 = 0;
    }  
}

int PLAYER::Stand_by_Anim()
{
    int S_AnimImg = 0;

    // 0 から 3 秒
    if (P_Seconas1 == 0) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_1];
    }
    else if (P_Seconas1 > 0 && P_Seconas1 < 2) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_0];
    }
    else if (P_Seconas1 > 1 && P_Seconas1 < 3) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_1];
    }
    else if (P_Seconas1 > 2 && P_Seconas1 < 4) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_2];
    }

    return S_AnimImg;
}

int PLAYER::Run_Anim()
{
    int R_AnimImg = 0;

    // 5フレーム
    if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_0];
    }
    else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_1];
    }
    else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_2];
    }
    else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_3];
    }

    return R_AnimImg;
}

int PLAYER::Levitation_Anim1()
{
    int F1_AnimImg = 0;

    // 5フレーム
    if (P_FPS % 15 == 0 || P_FPS % 15 == 1 || P_FPS % 15 == 2 || P_FPS % 15 == 3 || P_FPS % 15 == 4) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_0];
    }
    else if (P_FPS % 15 == 5 || P_FPS % 15 == 6 || P_FPS % 15 == 7 || P_FPS % 15 == 8 || P_FPS % 15 == 9) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_1];
    }
    else if (P_FPS % 15 == 10 || P_FPS % 15 == 11 || P_FPS % 15 == 12 || P_FPS % 15 == 13 || P_FPS % 15 == 14) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_2];
    }

    return F1_AnimImg;
}

int PLAYER::Levitation_Anim2()
{
    int F2_AnimImg = 0;

    if (P_FPS % 15 == 0 || P_FPS % 15 == 1 || P_FPS % 15 == 2 || P_FPS % 15 == 3 || P_FPS % 15 == 4) {
        F2_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_3];
    }
    else if (P_FPS % 15 == 5 || P_FPS % 15 == 6 || P_FPS % 15 == 7 || P_FPS % 15 == 8 || P_FPS % 15 == 9) {
        F2_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_2];
    }
    else if (P_FPS % 15 == 10 || P_FPS % 15 == 11 || P_FPS % 15 == 12 || P_FPS % 15 == 13 || P_FPS % 15 == 14) {
        F2_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_4];
    }

    return F2_AnimImg;
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

    DrawFormatString(0, 180, GetColor(255, 255, 255), " マウス座標：X座標 %d Y座標 %d", MouseX, MouseY);

    DrawFormatString(330, 120, GetColor(255, 255, 255), " FPS：%d", P_FPS);

    //プレイヤーの当たり判定
    DrawBox(P_Move_X + 20, P_Move_Y + 37, P_Move_X + 47, P_Move_Y + 65, GetColor(255, 255, 255), FALSE);

    //風船の当たり判定
    DrawBox(P_Move_X + 5, P_Move_Y + 10, P_Move_X + 59, P_Move_Y + 37, GetColor(255, 255, 255), FALSE);

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

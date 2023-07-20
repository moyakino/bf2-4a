#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"

PLAYER::PLAYER()
{
    //プレイヤー画像データの読み込み
    if (LoadDivGraph("images/Player/Player_Animation.png", 32, 8, 4, 64, 64, P_ArrayImg)){}
    P_Img = 0;
    P_L_Stick = 0;
    P_Right_Btn = 0;
    P_Left_Btn = 0;
    P_A_Btn = 0;
    P_A_Pressed = 0;

    P_Move_X = 100.0f;
    //P_Move_Y = 350.0f;
    P_Move_Y = 200.0f;

    //地上のスピード
    P_XSpeed = 0.0f;
    P_YSpeed = 0.0f;

    //空中でのスピード
    P_AirSpeed = 0.0;

    P_Accele = 0.0f;
    P_Air_Multiply = 1.0f;

    P_MoveR_Flg = 0;
    P_MoveL_Flg = 0;
    P_Air_Flg = 0;
    P_Balloon_Flg = 1;
    P_TurnFlg = TRUE;
    P_A_BtnFlg = 0;
    P_Air_R_Flg = 0;
    P_Air_L_Flg = 0;
    P_FPS = 0;
    P_Seconas1 = 0;
    MouseX = 0;
    MouseY = 0;

    //足場の座標
    sx1 = 0, sx2 = 0, sy1 = 0, sy2 = 0;

    //プレイヤーの座標
    px1 = 0, px2 = 0, py1 = 0, py2 = 0, p_uc = 0;

    //立ち状態フラグ
    P_Stand_Flg = 0;
    //落下状態フラグ
    P_Foll_Flg = 0;
}

void PLAYER::Update()
{
    //フレーム取得
    P_FPS++;

    //マウスから座標を読み取る
    GetMousePoint(&MouseX, &MouseY);

    //左スティック
    P_L_Stick = PAD_INPUT::GetLStickX();

    //デジタル方向右ボタン
    P_Right_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT);

    //デジタル方向左ボタン
    P_Left_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT);

    // Aボタン単押し
    P_A_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_A);

    // Bボタン長押し
    P_B_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_B);

    //ワープ用
    Player_Warp();

    //立っているかの判定
    Stand_Foot();

    //画像切り替え用
    Player_Img();

    //ステージの足場に立っていたら地上の移動に入る
    if (P_Stand_Flg == TRUE) {
        //地上の移動
        Player_Move();
    }

    if (P_A_Btn == 1) {
        Player_Air_A();
    }

    if (P_B_Btn == 1) {
        Player_Air_B();
    }

    if (P_Stand_Flg == FALSE && P_B_Btn == 0) {
        Player_Gravity();
    }

    //60fps == 1秒　で超えたら fpsを 0 にする
    if (P_FPS > 59) {
        P_FPS = 0;
        P_Seconas1++;
    }// P_FPS_INC は 秒数を取っている
    else if (P_Seconas1 > 3) {
        P_Seconas1 = 0;
    }

    
}

void PLAYER::Player_Warp()
{
    //左ワープ
    if (P_Move_X <= -53) {
        P_Move_X = 700;
    }
    //右ワープ
    else if (P_Move_X >= 700) {
        P_Move_X = -53;
    }

    //天井
    if (P_Move_Y <= -25) {
        P_Move_Y = 250;
    }
}

void PLAYER::Player_Img()
{
    //右移動で反転描画
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        P_TurnFlg = TRUE;
    }
    //左移動で通常描画
    else if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        P_TurnFlg = FALSE;
    }
}

void PLAYER::Player_Move()
{
    P_Air_Flg = FALSE;
    P_YSpeed = 0.0f;

    //右移動
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        P_MoveR_Flg = TRUE;
        P_XSpeed = 1.0f;
        P_Move_X = P_Move_X + P_XSpeed;
        P_Img = Run_Anim();
    }
    else {
        P_MoveR_Flg = FALSE;
    }

    //左移動
    if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        P_MoveL_Flg = TRUE;
        P_XSpeed = -1.0f;
        P_Move_X = P_Move_X + P_XSpeed;
        P_Img = Run_Anim();
    }
    else {
        P_MoveL_Flg = FALSE;
    }

    //待機中
    if (P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE) {
        P_Img = Stand_by_Anim();
    }
}

void PLAYER::Player_Levitation_Move()
{

}


void PLAYER::Player_Gravity()
{
    P_Air_Flg = TRUE;
    P_YSpeed = P_YSpeed + 0.05f;
    P_Move_Y = P_Move_Y + P_YSpeed;
    if (P_YSpeed >= 1.5f) {//速度制限
        P_YSpeed = 1.5f;
        P_Move_X = P_Move_X + P_Speed;
    }

    //空中の慣性
    if (P_Air_Flg == TRUE && P_Air_L_Flg == FALSE && P_Air_R_Flg == FALSE) {
        P_AirSpeed = P_AirSpeed * 0.98f;
        P_Move_X = P_Move_X + P_AirSpeed;
    }
void PLAYER::Player_Air_A()
{
    // Aボタン単押し
    if (P_FPS % 4 == 0) {
        P_Air_Flg = TRUE;
        P_YSpeed = P_YSpeed + -2.0f;
        P_Move_Y = P_Move_Y + P_YSpeed;
        //P_Move_Y--;
        if (P_YSpeed <= -10.0f) {
            P_YSpeed = -10.0f;
        }
        } 
    }
}

void PLAYER::Player_Air_B()
{
    // Bボタン長押し
    P_Air_Flg = TRUE;
    P_YSpeed = P_YSpeed + -0.05f;
    P_Move_Y = P_Move_Y + P_YSpeed;
    //P_Move_Y--;
    if (P_YSpeed <= -2.0f) {
        P_YSpeed = -2.0f;
    }
}


void PLAYER::Stand_Foot()
{
    //足場の座標
    sx1 = 180;
    sx2 = sx1 + 280;
    sy1 = 285;
    sy2 = sy1 + 20;

    //プレイヤーの座標
    px1 = P_Move_X;
    px2 = P_Move_X + 64;
    py1 = P_Move_Y;
    py2 = P_Move_Y + 64;

    //中心
    p_uc = (px1 + px2) / 2;
    
    //空を飛んでいても飛んでいなくても着地させたい
    if (-53 <= p_uc && p_uc < 160 && 415 >= py2 && py2 >= 413 || 180 <= p_uc && p_uc <= 460 && 287 >= py2 && py2 >= 283 || 480 < p_uc && p_uc <= 740 && 415 >= py2 && py2 >= 413) {

        P_Stand_Flg = TRUE;
    }
    else {
        P_Stand_Flg = FALSE;
    }
 }

int PLAYER::GetLocationX()
{
    return px1;
}

int PLAYER::GetLocationY()
{
    return py1;
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
    if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_0];
    }
    else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_1];
    }
    else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_2];
    }
    else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_3];
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

    DrawFormatString(0, 140, GetColor(255, 255, 255), " プレイ左上：X座標 %0.1f Y座標 %0.01f", P_Move_X, P_Move_Y);

    DrawFormatString(0, 160, GetColor(255, 255, 255), " 移動フラグ：左移動 %d 右移動 %d", P_MoveL_Flg, P_MoveR_Flg);

    DrawFormatString(0, 180, GetColor(255, 255, 255), " マウス座標：X座標 %d Y座標 %d", MouseX, MouseY);

    DrawFormatString(330, 120, GetColor(255, 255, 255), " FPS：%d", P_FPS);

    DrawFormatString(0, 200, GetColor(255, 255, 255), " 地上 Stand_Flg： %d ", P_Stand_Flg);
    DrawFormatString(0, 220, GetColor(255, 255, 255), " 海   Foll_Flg ： %d ", P_Foll_Flg);
    DrawFormatString(0, 240, GetColor(255, 255, 255), " 空   Air_Flg  ： %d ", P_Air_Flg);
    DrawFormatString(0, 260, GetColor(255, 255, 255), " p_uc X: %0.1f ", p_uc);
    DrawFormatString(0, 280, GetColor(255, 255, 255), " py2  Y:  %0.1f ", py2);

    DrawCircle(p_uc, py2, 2, 0xffff00, TRUE);


    //プレイヤーの当たり判定
    DrawBox(P_Move_X + 30, P_Move_Y + 37, P_Move_X + 35, P_Move_Y + 65, GetColor(255, 255, 255), FALSE);

    //風船の当たり判定
    DrawBox(P_Move_X + 5, P_Move_Y + 10, P_Move_X + 59, P_Move_Y + 37, GetColor(255, 255, 255), FALSE);

    DrawBox(px1, py1, px2, py2, GetColor(255, 0, 0), FALSE);

    //DrawBox(P_Move_X, P_Move_Y, P_Move_X + 64, P_Move_Y + 64, GetColor(255, 0, 0), FALSE);

    //縦線
    DrawLine(sx1, 0, sx1, 480, 0xff0000);
    DrawLine(sx2, 0, sx2, 480, 0xff0000);

    //横線
    DrawLine(0, sy1, 640, sy1, 0xff0000);


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

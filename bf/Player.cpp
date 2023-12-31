#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"
#include "Stage.h"
#include "Fish.h"
#include "GameMain.h"

#define SLIDE 15

int PLAYER::FishFlg;
int PLAYER::P_TurnFlg;
int PLAYER::F_TurnFlg;
int PLAYER::P_Stand_Flg;
int PLAYER::PlayerLife;
int PLAYER::FishHit;
int PLAYER::FishDeath;

float PLAYER::P_Move_X;
float PLAYER::P_Move_Y;

PLAYER::PLAYER()
{
    //プレイヤー画像データ
    if (LoadDivGraph("images/Player/Player_Animation.png", 32, 8, 4, 64, 64, P_ArrayImg)){}
    P_Img = 0;

    //プレイヤー　操作系
    P_L_Stick = 0;
   
    P_Right_Btn = 0;
    P_Left_Btn = 0;
    P_A_Btn = 0;
    P_B_Btn = 0;
    P_Y_Btn = 0;

    //プレイヤー　フラグ
    
    P_MoveR_Flg = 0;
    P_MoveL_Flg = 0;
    P_Air_R_Flg = 0;
    P_Air_L_Flg = 0;

    location.x = 20.0f;
    location.y = 353.2f;
    erea.Height = 50;
    erea.Width = 35;
    //P_Move_Y = 200.0f;

    P_Move_X = location.x;
    P_Move_Y = location.y;

    //地上のスピード
    P_XSpeed = 0.0f;
    P_YSpeed = 0.0f;

    P_Balloon_Flg = TRUE;
    P_TurnFlg = TRUE;
    
    P_FPS = 0;
    P_Seconas1 = 0;
    
    MouseX = 0;
    MouseY = 0;
    PlayerLife = 0;
    FishHit = 0;
    FishDeath = 0;
    Y_flg = TRUE;
    LightningFlg = TRUE;
    LightningCnt = 0;

    //サカナ
    FishCnt = 0;
    F_Seconas1 = 0;
    rand = 0;

    //立ち状態フラグ
    P_Stand_Flg = FALSE;
    Beaten_Flg = FALSE;
    AnimCnt = 0;
    Respawn_Flg = TRUE;

    FishFlg = FALSE;
    CheckSoundMem(UI::GameOver_BGM);
    P_Jump_SE = LoadSoundMem("sounds/SE_PlayerJump.wav");
    P_Respawn_BGM = LoadSoundMem("sounds/SE_Restart.wav");
   
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

    //Yボタン単押し
    //P_Y_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_Y);

    // Bボタン長押し
    P_B_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_B);

    P_Move_X = location.x;
    P_Move_Y = location.y;

    FishDeath = FALSE;

    //サカナの判定
    Fish_Respawn();

    //ワープ用
    Player_Warp();

    if (Respawn_Flg == TRUE) {
        Respawn_Anim();
    }

    //デバック用 Yボタン
    if (P_Y_Btn == 1) {
        if (P_FPS % 2 == 0) {
            AnimCnt++;
        }
        if (AnimCnt > 2) {
            AnimCnt = 2;
        }
    }

    if (AnimCnt == 1) {
        P_Balloon_Flg = FALSE;
    }
    if (AnimCnt == 2) {
        Beaten_Flg = TRUE;
        AnimCnt = 0;
    }

    //画像切り替え用
    Player_Img();

    PlayerLife = FALSE;

    //雷の玉に当たったか？
    if (Thunder::HitFlg == FALSE) {
        if (Beaten_Flg == FALSE) {
            
            //ステージの足場に立っていたら地上の移動に入る
            if (P_Stand_Flg == TRUE) {
                Player_Move();
            }

            if (P_A_Btn == 0 && P_B_Btn == 0 && P_Stand_Flg == FALSE) {
                Gliding_Anim();
            }
            else {
                if (P_B_Btn == 1 || P_B_Btn == 1 && P_Air_R_Flg == TRUE || P_B_Btn == 1 && P_Air_L_Flg == TRUE) {
                    Respawn_Flg = FALSE;
                    Rise_Anim_B();
                    Player_Air_B();
                }

                if (P_A_Btn == 1 || P_A_Btn == 1 && P_Air_R_Flg == TRUE || P_A_Btn == 1 && P_Air_L_Flg == TRUE) {
                    Respawn_Flg = FALSE;
                    Rise_Anim_A();
                    Player_Air_A();
                }
            }

            if (P_Stand_Flg == FALSE) {
                Player_Levitation_Move();
            }

            if (P_Stand_Flg == FALSE || P_Stand_Flg == FALSE && P_B_Btn == 0 || P_Stand_Flg == FALSE && P_A_Btn == 0) {
                Player_Gravity();
            }

            //Player が 海に落ちてしまった時の復活
            if (location.y > 500.0f) {
                PlayerLife = TRUE;
                Player_Init();
            }
        }
        else {
            if (Beaten_Flg == TRUE) {
                if (location.y < 500.0f) {
                    if (Y_flg == TRUE) {
                        P_YSpeed = -1;
                        Y_flg = FALSE;
                    }
                    P_YSpeed = P_YSpeed + 0.01f;
                    location.y = location.y + P_YSpeed;
                    Beaten_Anim();
                }
                else {
                    if (location.y > 500.0f) {
                        PlayerLife = TRUE;
                        Player_Init();
                    }
                    Beaten_Flg = FALSE;
                }
            }
        }
    }
    else {

        if (Thunder::HitFlg == TRUE) {
            if (location.y < 500.0f) {
                if (LightningFlg == FALSE) {
                    Beaten_Anim();
                }
                else {
                    Struck_by_Lightning_Anim();
                }
                if (Y_flg == TRUE) {
                    P_YSpeed = -1;
                    Y_flg = FALSE;
                }
                P_YSpeed = P_YSpeed + 0.01f;
                location.y = location.y + P_YSpeed;
            }
            else {
                if (location.y > 500.0f) {
                    PlayerLife = TRUE;
                    Player_Init();
                }
            }
        }

    }
    
    //60fps == 1秒　で超えたら fpsを 0 にする
    if (P_FPS > 59) {
        P_FPS = 0;
        P_Seconas1++;

    }// P_FPS_INC は 秒数を取っている
    else if (P_Seconas1 > 3) {
        P_Seconas1 = 0;
    }
    //もしゲームオーバー画面に遷移したらリスポーンBGMを切る
    if (CheckSoundMem(UI::GameOver_BGM) == 1) {
        StopSoundMem(P_Respawn_BGM);
    }
}

void PLAYER::Player_Init()
{
    P_XSpeed = 0;
    P_YSpeed = 0;
    location.x = 20.0f;
    location.y = 353.2f;
    P_TurnFlg = TRUE;
    Respawn_Flg = TRUE;
    P_Balloon_Flg = TRUE;
    PlaySoundMem(P_Respawn_BGM, DX_PLAYTYPE_BACK, FALSE);
    
    Y_flg = TRUE;
    Thunder::HitFlg = FALSE;
    LightningFlg = TRUE;
    LightningCnt = 0;
}

void PLAYER::Player_Warp()
{
    //左ワープ
    if (location.x <= -50) {
        location.x = 630;
    }
    //右ワープ
    else if (location.x >= 630) {
        location.x = -50;
    }

    //天井で跳ね返る
    if (location.y <= -25) {
        location.y = -20;
        BoundPlusY();
    }
    
}


void PLAYER::BoundPlusY()
{
    if (location.y != location.y + 5)
    {
        location.y += 0.1f;
    }

    if (P_YSpeed < 0) {
        P_YSpeed = (P_YSpeed * -1) * 0.8f;
    }
}

void PLAYER::BoundMinusY()
{
    if (location.y != location.y - 5)
    {
        location.y -= 0.1f;
    }

    if (P_YSpeed > 0) {
        P_YSpeed = (P_YSpeed * -1) * 0.8f;
    }
}

void PLAYER::BoundPlusX()
{
    if (location.x != location.x + 5)
    {
        location.x += 0.1f;
    }

    if (P_XSpeed < 0) {
        P_XSpeed = (P_XSpeed * -1) * 0.8f;
    }
}

void PLAYER::BoundMinusX()
{
    if (location.x != location.x - 5)
    {
        location.x -= 0.1f;
    }

    if (P_XSpeed > 0) {
        P_XSpeed = (P_XSpeed * -1) * 0.8f;
    }
}

void PLAYER::CheckBound(BoxCollider* b_col)
{

    //ステージの座標
    float sx1 = b_col->GetLocation().x;
    float sy1 = b_col->GetLocation().y;
    float sx2 = sx1 + b_col->GetErea().Width;
    float sy2 = sy1 + b_col->GetErea().Height;

    //プレイヤーの座標
    float px1 = location.x + 15;
    float px2 = px1 + erea.Width;
    float py1 = location.y + 15;
    float py2 = py1 + erea.Height;


    //当たり判定
    if ((px1 < sx2) && (sx1 < px2) && (py1 < sy2) && (py2 > sy1))
    {
        if (P_Stand_Flg == FALSE)
        {
            //左の壁にあたった時
            if ((px1 < sx2) && (sx1 > px1 - (erea.Width / 4))) {
                BoundMinusX();
            }

            //右の壁にあたったとき
            if ((sx1 < px2) && (sx2 < px2 + (erea.Width / 4))) {
                BoundPlusX();
            }

            //下の壁にあたったとき
            if ((sy2 > py1) && (py2 > sy2 + (erea.Height / 4))) {
                BoundPlusY();
            }
        }
    }
}

int PLAYER::EnemyCollider(BoxCollider* b_col)
{
    int re = 0;

    //敵の座標
    float ex1 = b_col->GetLocation().x + 15;
    float ey1 = b_col->GetLocation().y + 15;
    float ex2 = ex1 + b_col->GetErea().Width;
    float ey2 = ey1 + b_col->GetErea().Height;

    //プレイヤーの座標
    float px1 = location.x + 15;
    float px2 = px1 + erea.Width;
    float py1 = location.y + 15;
    float py2 = py1 + erea.Height;

    //当たり判定
    if ((px1 < ex2) && (ex1 < px2) && (py1 < ey2) && (py2 > ey1))
    {
        //プレイヤーが敵の左側にあたったとき
        if ((ex1 < px2) && (px1 < ex1 - (erea.Width / 4))) {
            re = 1;
        }

        //プレイヤーが敵の右側にあたったとき
        if ((ex2 > px1) && (px2 > ex2 + (erea.Width / 4))) {
            re = 2;
        }

        //プレイヤーが敵の上側にあたったとき
        if ((ey1 < py2) && (py1 < ey1 - (erea.Height / 4))){
            re = 3;
        }

        //プレイヤーが敵の下側にあたったとき
        if ((ey2 > py1) && (py2 > ey2 + (erea.Height / 4))) {
            re = 4;
        }

    }
    return re;
}


void PLAYER::Player_Img()
{
    //右移動で反転描画
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        Respawn_Flg = FALSE;
        P_TurnFlg = TRUE;
    }
    //左移動で通常描画
    else if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        Respawn_Flg = FALSE;
        P_TurnFlg = FALSE;
    } 
}

void PLAYER::Player_Move()
{
    P_YSpeed = 0.0f;

    //右移動
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        P_MoveR_Flg = TRUE;

        //加速度
        P_XSpeed = 1.0f;

        location.x = location.x + P_XSpeed;
        Run_Anim();
    }
    else {
        P_MoveR_Flg = FALSE;

    }

    //左移動
    if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        P_MoveL_Flg = TRUE;

        //加速度
        P_XSpeed = -1.0f;

        location.x = location.x + P_XSpeed;
        Run_Anim();
    }
    else {
        P_MoveL_Flg = FALSE;
    }

    //待機中
    if (Respawn_Flg == FALSE && P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE) {
        //初期値にもどす
        P_XSpeed = 0.0f;
        Stand_by_Anim();
    }
}

void PLAYER::Player_Levitation_Move()
{
    //空中右移動
    if (P_B_Btn == 1 && P_L_Stick > RIGHT_MOVE || P_A_Btn == 1 && P_L_Stick > RIGHT_MOVE || P_B_Btn == 1 && P_Right_Btn == 1 || P_A_Btn == 1 && P_Right_Btn == 1) {
        P_Air_R_Flg = TRUE;

        P_XSpeed = P_XSpeed + 0.09f;        //速度加算
        location.x = location.x + P_XSpeed;
        if (P_XSpeed >= 1.3f) {             //速度制限
            P_XSpeed = 1.3f;                //速度上限値
        }
    }
    else {
        // Bボタンが押されていない　スティックを倒されていない
        P_Air_R_Flg = FALSE;
    }

    //空中左移動
    if (P_B_Btn == 1 && P_L_Stick < LEFT_MOVE || P_A_Btn == 1&& P_L_Stick < LEFT_MOVE || P_B_Btn == 1 && P_Left_Btn == 1 || P_A_Btn == 1 && P_Left_Btn == 1) {
        P_Air_L_Flg = TRUE;

        P_XSpeed = P_XSpeed + -0.09f;
        location.x = location.x + P_XSpeed;
        if (P_XSpeed <= -1.3f) {
            P_XSpeed = -1.3f;
        }
    }
    else {
        P_Air_L_Flg = FALSE;
    }

    if (P_Stand_Flg == FALSE && P_Air_L_Flg == FALSE && P_Air_R_Flg == FALSE) {
        P_XSpeed *= 0.999f;
        location.x = location.x + P_XSpeed;
    }
}

void PLAYER::Player_Gravity()
{

    if (P_Balloon_Flg == TRUE) {
        P_Stand_Flg = FALSE;
        P_YSpeed = P_YSpeed + 0.01f;
        location.y = location.y + P_YSpeed;
        if (P_YSpeed >= 1.3f) {         //速度制限
            P_YSpeed = 1.3f;
        }
    }
    else {
        P_YSpeed = P_YSpeed + 0.02f;
        location.y = location.y + P_YSpeed;
        if (P_YSpeed >= 1.0f) {         //速度制限
            P_YSpeed = 1.0f;
        }
    }
}

void PLAYER::Player_Air_A()
{
    if (P_Balloon_Flg == TRUE) {
        // Aボタン単押し
        if (P_FPS % 2 == 0) {
            P_Stand_Flg = FALSE;
            
            P_YSpeed = P_YSpeed + -0.4f;
            P_Move_Y = P_Move_Y + P_YSpeed;
            if (P_YSpeed <= -1.0f) {        //速度制限
                P_YSpeed = -1.0f;
            }
        }
    }
    else {
        if (P_FPS % 2 == 0) {
            P_Stand_Flg = FALSE;
            
            P_YSpeed = P_YSpeed + -0.6f;
            P_Move_Y = P_Move_Y + P_YSpeed;
            if (P_YSpeed <= -1.0f) {        //速度制限
                P_YSpeed = -1.0f;
            }
        }
    }
}

void PLAYER::Player_Air_B()
{
    if (P_Balloon_Flg == TRUE) {
        if (P_FPS % 8 == 0) {
            P_Stand_Flg = FALSE;
            P_YSpeed = P_YSpeed + -0.2f;
            P_Move_Y = P_Move_Y + P_YSpeed;
            if (P_YSpeed <= -1.0f) {        //速度
                P_YSpeed = -1.0f;
            }
        }
    }
    else {
        if (P_FPS % 10 == 0) {
            P_Stand_Flg = FALSE;
            P_YSpeed = P_YSpeed + -0.4f;
            P_Move_Y = P_Move_Y + P_YSpeed;
            if (P_YSpeed <= -1.0f) {        //速度制限
                P_YSpeed = -1.0f;
            }
        }
    }
}

void PLAYER::Fish_Respawn()
{
    int fpscount = 0;

    //魚の出現
    if (location.x > 160 && location.x < 480 && location.y > 380 && location.y < 430)
    {
        //60fps == 1秒　で超えたら fpsを 0 にする
        if (P_FPS > 59) {
           // P_FPS = 0;
            F_Seconas1++;
        }
        if (F_Seconas1 == 3) {
            rand = GetRand(99);
            F_Seconas1 = 0;
            if (rand < 30)
            {
                //確率が30以下だったらサカナがPlayerのY座標に出てくる
                FishFlg = TRUE;

            }

        }
    }
    else {
        FishCnt = 0;
    }
    //魚の向き
    if (P_TurnFlg == TRUE) 
    {
        F_TurnFlg = TRUE;
    }
    else {
        F_TurnFlg = FALSE;
    }
    //魚にあたったときリスポーン
    if (Fish::FishEatP_flg == TRUE) {
        if (Fish::F_Seconds2 == 8) {
                FishHit += 1;
                FishDeath = TRUE;
                if (FishHit < 49) {
                    Player_Init();
                    Respawn_Anim();
                }
        }
    }
 }

void PLAYER::Respawn_Anim()
{
    if (P_Balloon_Flg == TRUE) {

        if (P_FPS >= 0 && P_FPS < 30) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_1];
        }
        else if (P_FPS > 29 && P_FPS <= 60) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_3];
        }
    }
    else {
        if (P_FPS >= 0 && P_FPS < 30) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_1];
        }
        else if (P_FPS > 29 && P_FPS <= 60) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_3];
        }
    }
}

void PLAYER::Stand_by_Anim()
{
    if (P_Balloon_Flg == TRUE) {
        // 0 から 3 秒
        if (P_Seconas1 == 0) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_1];
        }
        else if (P_Seconas1 > 0 && P_Seconas1 < 2) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_0];
        }
        else if (P_Seconas1 > 1 && P_Seconas1 < 3) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_1];
        }
        else if (P_Seconas1 > 2 && P_Seconas1 < 4) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_2];
        }
    }
    else {
        // 0 から 3 秒
        if (P_Seconas1 == 0) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_1];
        }
        else if (P_Seconas1 > 0 && P_Seconas1 < 2) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_0];
        }
        else if (P_Seconas1 > 1 && P_Seconas1 < 3) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_1];
        }
        else if (P_Seconas1 > 2 && P_Seconas1 < 4) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_2];
        }
    }
}

void PLAYER::Run_Anim()
{
    if (P_Balloon_Flg == TRUE) {
        // 5フレーム
        if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
            P_Img = P_ArrayImg[RUN_BALLOON2_0];
        }
        else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
            P_Img = P_ArrayImg[RUN_BALLOON2_1];
        }
        else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
            P_Img = P_ArrayImg[RUN_BALLOON2_2];
        }
        else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
            P_Img = P_ArrayImg[RUN_BALLOON2_3];
        }
    }
    else {
        // 5フレーム
        if (P_FPS % 15 == 0 || P_FPS % 15 == 1 || P_FPS % 15 == 2 || P_FPS % 15 == 3 || P_FPS % 15 == 4) {
            P_Img = P_ArrayImg[RUN_BALLOON1_0];
        }
        else if (P_FPS % 15 == 5 || P_FPS % 15 == 6 || P_FPS % 15 == 7 || P_FPS % 15 == 8 || P_FPS % 15 == 9) {
            P_Img = P_ArrayImg[RUN_BALLOON1_1];
        }
        else if (P_FPS % 15 == 10 || P_FPS % 15 == 11 || P_FPS % 15 == 12 || P_FPS % 15 == 13 || P_FPS % 15 == 14) {
            P_Img = P_ArrayImg[RUN_BALLOON1_2];
        }
    }
    
}

void PLAYER::Gliding_Anim()
{
    if (P_Balloon_Flg == TRUE) {
        if (P_FPS >= 0 && P_FPS < 15) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_2];
        }
        else if (P_FPS > 14 && P_FPS < 30) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_3];
        }
        else if (P_FPS > 29 && P_FPS < 45) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_2];
        }
        else if (P_FPS > 44 && P_FPS <= 60) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_4];
        }
    }
    else {
        if (P_FPS >= 0 && P_FPS < 15) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_2];
        }
        else if (P_FPS > 14 && P_FPS < 30) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_3];
        }
        else if (P_FPS > 29 && P_FPS < 45) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_2];
        }
        else if (P_FPS > 44 && P_FPS <= 60) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_4];
        }
    }
}

void PLAYER::Rise_Anim_A()
{
    if (P_Balloon_Flg == TRUE) {

        if (P_FPS >= 0 && P_FPS < 15) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_0];
        }
        else if (P_FPS > 14 && P_FPS < 30) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_1];
        }
        else if (P_FPS > 29 && P_FPS < 45) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_2];
        }
        else if (P_FPS > 44 && P_FPS <= 60) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_1];
        }
    }
    else {
        if (P_FPS % 8 == 0 || P_FPS % 8 == 1) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_0];
        }
        else if (P_FPS % 8 == 2 || P_FPS % 8 == 3) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_1];
        }
        else if (P_FPS % 8 == 4 || P_FPS % 8 == 5) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_2];
        }
        else if (P_FPS % 8 == 6 || P_FPS % 8 == 7) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_1];
        }
    }
}

void PLAYER::Rise_Anim_B()
{
    if (P_Balloon_Flg == TRUE) {

        if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_0];
        }
        else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_1];
        }
        else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_2];
        }
        else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_1];
        }
    }
    else {
        if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_0];
        }
        else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_1];
        }
        else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_2];
        }
        else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_1];
        }
    }
}

void PLAYER::Beaten_Anim()
{
    if (P_FPS >= 0 && P_FPS < 15) {
        P_Img = P_ArrayImg[FALL_0];
    }
    else if (P_FPS > 14 && P_FPS < 30) {
        P_Img = P_ArrayImg[FALL_1];
    }
    else if (P_FPS > 29 && P_FPS < 45) {
        P_Img = P_ArrayImg[FALL_2];
    }
    else if (P_FPS > 44 && P_FPS <= 60) {
        P_Img = P_ArrayImg[FALL_1];
    }
}

void PLAYER::Struck_by_Lightning_Anim()
{
    if (LightningFlg == TRUE && LightningCnt < 45) {
        if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
            P_Img = P_ArrayImg[FALL_3];
        }
        else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
            P_Img = P_ArrayImg[FALL_0];
        }
        else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
            P_Img = P_ArrayImg[FALL_3];
        }
        else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
            P_Img = P_ArrayImg[FALL_0];
            LightningCnt++;
        }
    }
    else {
        LightningFlg = FALSE;
    }
}

PLAYER::~PLAYER()
{

}

void PLAYER::Draw()const
{
    //ポーズ画面じゃないとき描写
    if (GameMain::PauseFlg == FALSE) {

        //DrawFormatString(0, 20, GetColor(255, 255, 255), " FPS：%d", P_FPS); 
            //DrawFormatString(100, 340, GetColor(255, 255, 255), " F_Seconas1：%d", F_Seconas1);
        //Aボタン描画
        //DrawFormatString(0, 40, GetColor(255, 255, 255), " 押された瞬間：%d 離された瞬間：%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

        //DrawFormatString(0, 60, GetColor(255, 255, 255), " 左スティック：横軸値 %d 縦軸値 %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

        DrawFormatString(0, 80, GetColor(255, 255, 255), " プレイ左上：X座標 %0.1f Y座標 %0.01f", P_Move_X, P_Move_Y);

        //DrawFormatString(0, 100, GetColor(255, 255, 255), " 移動フラグ：左移動 %d 右移動 %d", P_MoveL_Flg, P_MoveR_Flg);

        DrawFormatString(0, 120, GetColor(255, 255, 255), " マウス座標：X座標 %d Y座標 %d", MouseX, MouseY);

        //DrawFormatString(0, 140, GetColor(255, 255, 255), " AnimCnt：%d", AnimCnt);

        //DrawFormatString(0, 320, GetColor(255, 255, 255), " zanki ： %d ", zanki); 
        //DrawFormatString(0, 160, GetColor(255, 255, 255), " やられ   Beaten_Flg ： %d ", Beaten_Flg);
        DrawFormatString(0, 180, GetColor(255, 255, 255), " 風船   FishHit  ： %d ", FishHit);

        DrawFormatString(0, 240, GetColor(255, 255, 255), " P_YSpeed :%0.1f ", P_YSpeed);
        DrawFormatString(0, 260, GetColor(255, 255, 255), " P_XSpeed :%0.1f ", P_XSpeed);
        //DrawFormatString(0, 280, GetColor(255, 255, 255), " 確率 :%d", rand);
        //DrawFormatString(0, 300, GetColor(255, 255, 255), " P_Air_R_Flg :%d", P_Air_R_Flg);
        //DrawFormatString(0, 320, GetColor(255, 255, 255), " L_Stick :%d", P_L_Stick_Flg);
        //DrawFormatString(0, 320, GetColor(255, 255, 255), " Fish :%d", FishFlg);

        //DrawLine(160, 417, 480, 417, 0xffffff, TRUE);

        //DrawCircle(p_uc, py2, 2.0f, 0xff0000, TRUE);

        //DrawCircleAA(p_uc, py2 - 54.0f, 2.0f, 0xfffff0, TRUE);

    //プレイヤーの当たり判定
    DrawBoxAA(location.x + 15, location.y + 15, location.x + 15+erea.Width, location.y + 15+erea.Height, GetColor(255, 255, 255), FALSE);
   
    //プレイヤーの当たり判定 敵用    Playerの体
    //DrawBoxAA(location.x + 17, location.y + 37, location.x + 48, location.y + 65, GetColor(255, 255, 255), FALSE);

        //DrawBoxAA(location.x + 12, location.y + 37, location.x + 53, location.y + 65, GetColor(255, 255, 255), FALSE);

        //プレイヤーの当たり判定 敵用    Playerの風船
        //DrawBoxAA(location.x + 9, location.y + 11, location.x + 55, location.y + 35, GetColor(255, 255, 255), FALSE);

        //DrawLine(location.x + 9, location.y + 35, location.x + 60, location.y + 35, GetColor(255, 0, 0), 1);

        //プレイヤー　風船を含めた当たり判定　シャボン玉用
        //DrawBoxAA(location.x + 5, location.y + 8, location.x + 57, location.y + 68, GetColor(255, 255, 255), FALSE);

        //風船の当たり判定
        //DrawBoxAA(location.x + 5, location.y + 10, location.x + 59, location.y + 37, GetColor(255, 255, 255), FALSE);

        //DrawBoxAA(px1, py1, px2, py2, GetColor(255, 0, 0), FALSE);

        //DrawBox(location.x, location.y, location.x + 64, location.y + 64, GetColor(255, 0, 0), FALSE);

        ////縦線
        //DrawLine(sx1, 0, sx1, 480, 0xff0000);
        //DrawLine(sx2, 0, sx2, 480, 0xff0000);

        ////横線
        //DrawLine(0, sy1, 640, sy1, 0xff0000);

        //最初は右向きで描画される
        if (P_TurnFlg == TRUE) {
            DrawTurnGraphF(location.x, location.y, P_Img, TRUE);
        }
        else {
            if (P_TurnFlg == FALSE) {
                DrawGraphF(location.x, location.y, P_Img, TRUE);
            }
        }
        if (P_A_Btn == 1) {
            PlaySoundMem(P_Jump_SE, DX_PLAYTYPE_BACK, TRUE);
        }
    }
}

#pragma once
#include"Player.h"

//エネミー  待機中アニメーション (空気を入れる)
#define STAND_BY_BALLOON1_0 1
#define STAND_BY_BALLOON1_1 2
#define STAND_BY_BALLOON1_2 3
#define STAND_BY_BALLOON1_3 4
#define STAND_BY_BALLOON1_4 5
#define STAND_BY_BALLOON1_5 6
#define STAND_BY_BALLOON1_6 7
#define STAND_BY_BALLOON1_7 8

//エネミー  浮上アニメーション 
#define LEVITATION_BALLOON1_0 9
#define LEVITATION_BALLOON1_1 10
#define LEVITATION_BALLOON1_2 11
#define LEVITATION_BALLOON1_3 12
#define LEVITATION_BALLOON1_4 13

//エネミーやられアニメーション
#define FALL_0 14
#define FALL_1 15

//エネミーパラシュートアニメーション
#define parachute_0 16
#define parachute_1 17
#define parachute_2 18

class EnemyBird {
private:
    int x, y;
    int my;
    int hp;
    int cnt;
    float SpeedX;
    float SpeedY;


    int E_ArrayImg_P[18];
    int E_ArrayImg_G[18];
    int E_ArrayImg_R[18];

    //フレーム取得
    int E_FPS;
    int E_Seconas1;

    int PlayerPos;
    int EnemyPos;

    //立っている状態のフラグ
    int		E_Stand_Flg;
    //海に落下する状態のフラグ
    int		E_Foll_Flg;

    float	sx1, sy1, sx2, sy2;
    float	ex1, ey1, ex2, ey2, e_uc;

    //敵の座標
    float E_location_X;
    float E_location_Y;

    float E_Move_X;
    float E_Move_Y;

    //空中でのスピード
    float E_AirSpeed;
    float E_Air_Flg;

    //(仮)左スティック
    int		E_L_Stick;

    int      E_R_Stick;

    //(仮)デジタル方向ボタン右
    int		E_Right_Btn;
    //(仮)デジタル方向ボタン左
    int		E_Left_Btn;
    //(仮)Aボタン
    int		E_A_Btn;

    //(仮)Bボタン長押し
    int		E_B_Btn;

    //(仮)Aボタン長押し
    int		E_A_Pressed;
    //(仮)
    int		E_A_BtnFlg;
    int		E_Air_R_Flg;
    int		E_Air_L_Flg;
    int     E_Img;

    //プレイヤーの地上スピード X座標
    float	E_XSpeed;
    //プレイヤーの地上スピード Y座標
    float	E_YSpeed;

    float   E_Speed;

    float	E_Accele;

    float	E_Air_Multiply;


    float E_MoveR_Flg;
    float E_MoveL_Flg;
    float E_Balloon_Flg;

    
public:

    ////Player  X座標用変数
    //static float	E_Move_X;
    ////Player  Y座標用変数
    //static float	E_Move_Y;

    //コンストラクタ
    EnemyBird();
    // デストラクタ
    ~EnemyBird();
    // 更新処理を実装する
    void Update(int playerx, int playery);
    // 描画処理を実装する
    void Draw() const;
    //地面に立たせる
    void Stand_Foot();

    int  Balloon_Anim(void);
    //空中で移動しているときのアニメーション
    int Levitation_Anim1();

    int Stand_by_Anim();

    int E_GetLocationX();
    int E_GetLocationY();
    int Return_MoveX();
    int Return_MoveY();

    void Enemy_Levitation_Move_X();
    void Enemy_Levitation_Move_Y();

    void Enemy_Gravity();
    void Enemy_Warp();
};

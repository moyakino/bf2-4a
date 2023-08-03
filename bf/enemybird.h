#pragma once
#include"Player.h"

//エネミー  待機中アニメーション (空気を入れる)
#define STAND_BY_ENEMY_0 1
#define STAND_BY_ENEMY_1 2
#define STAND_BY_ENEMY_2 3
#define STAND_BY_ENEMY_3 4
#define STAND_BY_ENEMY_4 5
#define STAND_BY_ENEMY_5 6
#define STAND_BY_ENEMY_6 7
#define STAND_BY_ENEMY_7 8

//エネミー  浮上アニメーション 
#define LEVITATION_ENEMY_0 9
#define LEVITATION_ENEMY_1 10
#define LEVITATION_ENEMY_2 11
#define LEVITATION_ENEMY_3 12
#define LEVITATION_ENEMY_4 13

//エネミーやられアニメーション
#define FALL_ENEMY_0 14
#define FALL_ENEMY_1 15

//エネミーパラシュートアニメーション
#define parachute_0 16
#define parachute_1 17
#define parachute_2 18

enum class ENEMY_STATE {
    START,
    FLY_LEFT,
    FLY_RIGHT,
    FALL,
    WAIT,
};


class EnemyBird {
private:
    int Cnt;
    int CntWait;
    float SpeedX;
    float SpeedY;


    int E_ArrayImg_P[18];
    int E_ArrayImg_G[18];
    int E_ArrayImg_R[18];

    //フレーム取得
    int E_FPS;
    int E_Second;

    //立っている状態のフラグ
    int		E_Stand_Flg;
    //海に落下する状態のフラグ
    int		E_Foll_Flg;

    float	sx1, sy1, sx2, sy2;
    float	ex1, ey1, ex2, ey2, e_uc;

    //敵の座標

    float E_Move_X;
    float E_Move_Y;

    //空中でのスピード
    float E_AirSpeed;
    float E_Air_Flg;

    //敵の移動
    float E_Balloon_Flg;
    int     E_AnimImg;

    //プレイヤーの地上スピード X座標
    float	E_XSpeed;
    //プレイヤーの地上スピード Y座標
    float	E_YSpeed;
    float   E_Speed;
    float	E_Accele;

    float	E_Air_Multiply;

    ENEMY_STATE EnemyState;
    
    
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
    void Update();
    // 描画処理を実装する
    void Draw() const;
    //地面に立たせる
    void Stand_Foot();

    int  Balloon_Anim(void);
    //空中で移動しているときのアニメーション

    int Stand_by_Anim();
    void Start_Anim();
    void Fly_Anim();

    void Enemy_Levitation_Move_X();
    void Enemy_Levitation_Move_Y();

    void Enemy_Gravity();
    void Enemy_Warp();
};

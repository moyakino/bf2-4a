#pragma once
#include"Player.h"

class EnemyBird {
private:
    int x, y;
    int my;
    int hp;
    int cnt;
    float speed;

    int E_ArrayImg_P[17];
    int E_ArrayImg_G[17];
    int E_ArrayImg_R[17];

    //フレーム取得
    int E_FPS;
    int seconds;

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

    //プレイヤーの座標
    float P_Move_X;
    float P_Move_Y;

    //空中でのスピード
    float E_AirSpeed;

    float E_Air_Flg;

    
public:

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

    int Stand_by_Anim();

    int E_GetLocationX();

    int E_GetLocationY();

    int Return_MoveX();

    int Return_MoveY();

    void Chase();
};

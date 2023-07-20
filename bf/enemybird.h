#pragma once

class EnemyBird {
private:
    int x, y;
    int my;
    int hp;
    int cnt;


    //フレーム取得
    int E_FPS;
    int seconds;


public:
    int E_ArrayImg_P[18];
    int E_ArrayImg_G[18];
    int E_ArrayImg_R[18];

    //立っている状態のフラグ
    int		E_Stand_Flg;
    //海に落下する状態のフラグ
    int		E_Foll_Flg;

    float	sx1, sy1, sx2, sy2;

    float	ex1, ey1, ex2, ey2, e_uc;

    int E_Move_X;
    int E_Move_Y;

    //コンストラクタ
    EnemyBird();
    // デストラクタ
    ~EnemyBird();
    // 更新処理を実装する
    void Update(int playerx,int playery);
    // 描画処理を実装する
    void Draw() const;
    //地面に立たせる
    void Stand_Foot();

    int Stand_by_Anim();
};

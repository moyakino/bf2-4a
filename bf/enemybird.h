#pragma once
class EnemyBird {
private:
    int x, y;
    int my;
    int hp;


public:
    int E_ArrayImg[19];


    //コンストラクタ
    EnemyBird();
    // デストラクタ
    ~EnemyBird();
    // 更新処理を実装する
    void Update();
    // 描画処理を実装する
    void Draw() const;
};

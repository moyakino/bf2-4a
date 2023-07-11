#pragma once
class EnemyBird {
private:
    int x, y;
    int my;
    int hp;
    bool Attack();
    bool isAttack;
public:

    //コンストラクタ
    EnemyBird();

    // デストラクタ
    ~EnemyBird();

    // 更新処理を実装する
    void Update();

    // 描画処理を実装する
    void Draw() const;

    bool Attack();

    bool Damage(int damage);
};

#pragma once
class EnemyBird {
public:

    //コンストラクタ
    EnemyBird();

    // デストラクタ
    ~EnemyBird();

    // 更新処理を実装する
    void Update();

    // 描画処理を実装する
    void Draw() const;
};

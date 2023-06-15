#pragma once
// デフォルトの抽象シーンクラス
// ユーザーはこれを継承してシーンを実装すると楽

class AbstractScene {
public:
    // デストラクタ
    virtual ~AbstractScene() {}

    // 更新処理を実装する
    virtual AbstractScene* Update() = 0;

    // 描画処理を実装する
    virtual void Draw() const = 0;
};

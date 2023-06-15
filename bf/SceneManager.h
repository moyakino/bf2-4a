#pragma once
#include "AbstractScene.h"

// シーンマネージャークラス
// 各シーンの切り替えを管理する
class SceneManager :public AbstractScene {
private:
    AbstractScene* mScene; // 現在のシーン

public:
    // コンストラクタ
    SceneManager(AbstractScene* scene) : mScene(scene) {}

    // デストラクタ
    ~SceneManager() {
        delete mScene;
    }

    // 更新処理を実行する
    AbstractScene* Update()override;

    // 描画処理を実行する
    void Draw() const;
};
#pragma once
//雷アニメーション
#define THUNDER_ANIM1_0 0
#define THUNDER_ANIM1_1 1
#define THUNDER_ANIM1_2 2

class Thunder {

private:

    //雷画像 分割読み込み用変数
    int	S_ThunderImg[3];
    int S_Img;

    //FPSと秒数カウント
    int	S_FPS;
    int	S_Seconas1;

public:

    //コンストラクタ
    Thunder();

    // デストラクタ
    ~Thunder();

    // 更新処理を実装する
    void Update();

    // 描画処理を実装する
    void Draw() const;

    int Thunder_Anim();
};
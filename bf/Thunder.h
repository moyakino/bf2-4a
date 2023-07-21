#pragma once
//雷アニメーション
#define THUNDER_ANIM1_0 0
#define THUNDER_ANIM1_1 1
#define THUNDER_ANIM1_2 2
#define THUNDER_ANIM1_3 3
#define THUNDER_ANIM1_4 5
#define THUNDER_ANIM1_5 6

#define THUNDER_EFFECT_ANIM1_0 0
#define THUNDER_EFFECT_ANIM1_1 1
#define THUNDER_EFFECT_ANIM1_2 2

class Thunder {

private:

    //雷画像 分割読み込み用変数
    int	ThunderImg[6];
    int T_Img;

    int	EffectImg[3];
    int E_Img;

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
    int Effect_Anim();
};
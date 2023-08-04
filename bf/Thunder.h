#pragma once
#define _USE_MATH_DEFINES
//雷アニメーション
#define THUNDER_ANIM1_0 0
#define THUNDER_ANIM1_1 1
#define THUNDER_ANIM1_2 2
#define THUNDER_ANIM1_3 3
#define THUNDER_ANIM1_4 5
#define THUNDER_ANIM1_5 6

#define EFFECT_ANIM1_0 0
#define EFFECT_ANIM1_1 1
#define EFFECT_ANIM1_2 2

#define CLOUD_ANIM1_0 0
#define CLOUD_ANIM1_1 1
#define CLOUD_ANIM1_2 2

class Thunder {

private:

    //雷画像 分割読み込み用変数
    int	ThunderImg[7];
    int T_Img;

    int	EffectImg[3];
    int E_Img;
    
    //雲画像　分割読込耀変数
    int	CloudImg;
    int	Cloud_AnimImg[3];
    int C_Img;

    //FPSと秒数カウント
    int	S_FPS1;
    int	S_FPS2;
    int	S_Seconas1;
    int	S_Seconas2;

    int BallFlg;                //ボールの状態(0...移動中 1...バー接触2:スタート状態)
    int RestBall;               //残りのボールの数

    //ボールの変数
    int BallX, BallY;
    //ボールの移動量
    int MoveX, MoveY;
    int Speed;                  //ボールのスピード
    float BallAngle;            //ボールの角度

    int MouseX, MouseY;         // マウスの座標
    int BarX, BarY;             // バーの座標

    int H_flg;

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

    int Cloud_Anim();

    //void MoveBall();
    //void HitThunder();
    //void ChangeAngle();     //ボールの角度

};
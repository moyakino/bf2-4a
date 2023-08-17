#pragma once
#include "BoxCollider.h"

//プレイヤー 待機中アニメーション (風船が二つの場合)
#define STAND_BY_BALLOON2_0 0
#define STAND_BY_BALLOON2_1 1
#define STAND_BY_BALLOON2_2 2
#define STAND_BY_BALLOON2_3 3

//プレイヤー 待機中アニメーション (風船が一つの場合)
#define STAND_BY_BALLOON1_0 4
#define STAND_BY_BALLOON1_1 5
#define STAND_BY_BALLOON1_2 6
#define STAND_BY_BALLOON1_3 7

//プレイヤー X軸方向の移動アニメーション (風船が二つの場合)
#define RUN_BALLOON2_0 8
#define RUN_BALLOON2_1 9
#define RUN_BALLOON2_2 10
#define RUN_BALLOON2_3 11
#define RUN_BALLOON2_4 12

//プレイヤー X軸方向の移動アニメーション (風船が一つの場合)
#define RUN_BALLOON1_0 13
#define RUN_BALLOON1_1 14
#define RUN_BALLOON1_2 15
#define RUN_BALLOON1_3 16

//プレイヤー Y軸方向の浮上アニメーション (風船が二つの場合)
#define LEVITATION_BALLOON2_0 17
#define LEVITATION_BALLOON2_1 18
#define LEVITATION_BALLOON2_2 19
#define LEVITATION_BALLOON2_3 20
#define LEVITATION_BALLOON2_4 21

//プレイヤー Y軸方向の浮上アニメーション (風船が一つの場合)
#define LEVITATION_BALLOON1_0 22
#define LEVITATION_BALLOON1_1 23
#define LEVITATION_BALLOON1_2 24
#define LEVITATION_BALLOON1_3 25
#define LEVITATION_BALLOON1_4 26

//プレイヤー やられアニメーション
#define FALL_0 27
#define FALL_1 28
#define FALL_2 29
#define FALL_3 30

//スティックの傾き具合からプレイヤーの状態を取得
#define LEFT_MOVE -2000
#define RIGHT_MOVE 2000

class PLAYER :public BoxCollider
{
private:
	
	int		P_ArrayImg[33];		//(仮)プレイヤー画像 分割読み込み用変数
	int		P_Img;				//(仮)プレイヤー画像 描画用変数


	int		P_L_Stick;			//左スティック
	int		P_Right_Btn;		//デジタル方向ボタン右
	int		P_Left_Btn;			//デジタル方向ボタン左
	int		P_A_Btn;			//Aボタン 単押し
	int		P_B_Btn;			//Bボタン 長押し
	int		P_Y_Btn;			//(仮)Yボタン 単押し

	float	P_XSpeed;			//プレイヤーの地上スピード X座標
	float	P_YSpeed;			//プレイヤーの地上スピード Y座標

	int		P_MoveR_Flg;		//プレイヤー右移動フラグ 移動無し:0 右移動:1
	int		P_MoveL_Flg;		//プレイヤー左移動フラグ 移動無し:0 左移動:1
	int		P_Air_R_Flg;		//空中かつ左スティックを使いながら、右に移動しているか？
	int		P_Air_L_Flg;		//空中かつ左スティックを使いながら、左に移動しているか？
	int		P_Balloon_Flg;		//風船情報 TRUE:2個 FALSE:1個
	int		Respawn_Flg;		//リスポーンした際の点滅アニメーション再生用フラグ
	int		Y_flg;				//やられアニメーション再生時の落下用フラグ
	int		LightningFlg;		//雷やられアニメーション用フラグ
	int		LightningCnt;		//雷やられアニメーション用カウント

	
	int		Beaten_Flg;			//やられアニメーションの再生
	int		AnimCnt;			//デバック用
	int		MouseX;				//デバック用マウスX
	int		MouseY;				//デバック用マウスY

	int		P_FPS;				//FPSCnt
	int		P_Seconas1;			//秒数

	int		FishCnt;			//魚用カウント
	int		F_Seconas1;			//魚用秒数
	int		rand;				//魚用確率

    int  P_Jump_SE;
	int  P_Respawn_BGM;

	
public:
	
	static int		P_Stand_Flg;	//立っている状態のフラグ
	static float	P_Move_X;		//Player  X座標用変数
	static float	P_Move_Y;		//Player  Y座標用変数
	static	int		P_TurnFlg;		//画像の左右反転用フラグ FALSE:普通に描画 TRUE:左右反転
	static	int		PlayerLife;		//Playerの残機用
	static	int		FishHit;		//魚に当たったか？
	static	int		FishDeath;		//魚用死亡判定
	static	int		zanki;

	static int		FishFlg;		//魚用フラグ
	static	int		F_TurnFlg;		//魚用画像左右反転フラグ

	//コンストラクタ
	PLAYER();

	//デストラクタ
	~PLAYER();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;

	void Player_Warp();				//Player画面端移動関数
	void Player_Img();				//Player画像左右反転関数
	void Player_Move();				//Player地上移動関数
	void Player_Gravity();			//Player重力関数
	void Player_Levitation_Move();	//Player空中移動関数
	void Player_Air_A();			//Aボタン単押しの際の上昇関数
	void Player_Air_B();			//Bボタン長押しの際の上昇関数

	void Player_Init();				//Player初期処理

	void Respawn_Anim();			//Playerのリスポーンアニメーション
	void Stand_by_Anim();			//Playerの待機状態中のアニメーション
	void Run_Anim();				//Playerが走っている時のアニメーション
	void Gliding_Anim();			//Playerが滑空している時のアニメーション 
	void Rise_Anim_A();				//Playerが上昇している時のアニメーション Aボタン用
	void Rise_Anim_B();				//Playerが上昇している時のアニメーション Bボタン用
	void Beaten_Anim();				//Playerやられアニメーション
	void Struck_by_Lightning_Anim();//Player雷やられアニメーション

	void Fish_Respawn();			//魚出現関数

	//下方向へ跳ね返る処理
	void BoundPlusX();

	//上方向へ跳ね返る処理
	void BoundMinusX();

	//右方向へ跳ね返る処理
	void BoundPlusY();

	//左方向へ跳ね返る処理
	void BoundMinusY();

	//プレイヤーが跳ね返る処理
	void CheckBound(BoxCollider* b_col);

	//プレイヤーと敵の当たり判定
	int EnemyCollider(BoxCollider* b_col);

	Location GetLocation() { return location; }

};
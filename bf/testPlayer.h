#pragma once
#include "BoxCollider.h"

//スティックの傾き具合からプレイヤーの状態を取得
#define LEFT_MOVE -2000
#define RIGHT_MOVE 2000

#define PLAYER_WID 
#define PLAYER_HEI 

//プレイヤーの走るスピード
#define RUN_SPEED	1
#define FLY_SPEED2	0.2
#define FLY_SPEED1	0.2

enum class PLAYER_FLG
{
	STAND,
	WALK,
	FLY,
	FOLL,
};

class testPlayer :public BoxCollider 
{
private:
	PLAYER_FLG PlayerFlg;	//プレイヤーの現在の状態

	float Speed;	//移動速度
	float VelX;	//初速x
	float VelY;	//初速y
	float Gravity;	//重力
	float Reflect;	//反発

private:

	//アニメーション用画像
	int pStandImg_Bloon2[4];	//待機アニメーション(風船2個)	0～3
	int pStandImg_Bloon1[4];	//待機アニメーション(風船1個)	4～7

	int pWalkImg_Bloon2[5];		//歩行アニメーション(風船2個)	8～12
	int pWalkImg_Bloon1[4];		//歩行アニメーション(風船1個)	13～16

	int pFlyImg_Bloon2[5];		//飛行アニメーション(風船2個)	17～21
	int pFlyImg_Bloon1[5];		//飛行アニメーション(風船1個)	22～26

	int pFallImg[4];			//やられアニメーション			27～30

	int P_ArrayImg[33];	//画像格納

	int sCnt;	//待機中アニメ カウント用変数
	int wCnt;	//歩行アニメ カウント用変数

	int P_Img;	//画像

	int fps;	//fps

	int pLeft;

public:
	//コンストラクタ
	testPlayer();

	//デストラクタ
	~testPlayer();

	//更新
	void Update();

	//描画
	void Draw() const;

	//地上での移動
	void Player_StandMove();

	//浮上
	void Player_Fly();


	//反発
	void Player_Bound();



	//待機中アニメーション
	int StandAnim();

	//歩行アニメーション
	int WalkAnim();

};


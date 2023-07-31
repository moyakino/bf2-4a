#pragma once
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"

#define GREEN_FOOT_WIDTH_1 280.0
#define GREEN_FOOT_HEIGHT_1 17.0

#define GREEN_FOOT_WIDTH_2 112
#define GREEN_FOOT_HEIGHT_2 17

#define GREEN_FOOT_WIDTH_3 81
#define GREEN_FOOT_HEIGHT_3 18

#define GREEN_FOOT_WIDTH_4 61
#define GREEN_FOOT_HEIGHT_4 68

#define GREEN_FOOT_WIDTH_5 42
#define GREEN_FOOT_HEIGHT_5 18

#define RED_FOOT_WIDTH_1 62
#define RED_FOOT_HEIGHT_1 18

#define RED_FOOT_WIDTH_2 22
#define RED_FOOT_HEIGHT_2 51

#define RED_FOOT_WIDTH_3 21
#define RED_FOOT_HEIGHT_3 67

#define RAND_WIDTH 160
#define RAND_HEIGHT 64


class Stage
{
private:
	int StageFoot[8];
	int StageLand_R;
	int StageLand_L;
	int StageSea;

	int StageSample1;
	int StageSample2;
	int StageSample3;
	int StageSample4;
	int StageSample5;

	int Snum;

	int sFps;

	Stage1* s1;
	Stage2* s2;
	Stage3* s3;
	Stage4* s4;
	Stage5* s5;

public:

	static int Bound;
	static int Stand;

	static int Death;

	//コンストラクタ
	Stage();

	//デストラクタ
	~Stage();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;

	void StandRand();

};
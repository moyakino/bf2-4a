#include "Stage2.h"
#include "Stage.h"
#include "Player.h"

Stage2::Stage2()
{
	//足場
	sx1 = 180.0;
	sx2 = sx1 + GREEN_FOOT_WIDTH_1;
	sy1 = 285.0;
	sy2 = sy1 + GREEN_FOOT_HEIGHT_1;

}

Stage2::~Stage2()
{
}

void Stage2::Update()
{

	float px1 = PLAYER::P_Move_X + 17;
	float px2 = PLAYER::P_Move_X + 48;
	float py1 = PLAYER::P_Move_Y + 37;
	float py2 = PLAYER::P_Move_Y + 65;


	//空中足場
	if ((sx1 < px2) && (sx2 > px1) && (sy1 < py2) && (sy2 > py1))
	{
		if ((sx1 < px2) && (sx2 > px1) && (sy1 < py2) && (sy1 - 20 > py1))
		{
			Stage::Stand = TRUE;
		}
		Stage::Bound = TRUE;
	}
	//左足場
	else if ((-55 < px2) && (RAND_WIDTH > px1) && (480 - RAND_HEIGHT < py2) && (480 > py1))
	{
	if ((-55 < px2) && (RAND_WIDTH > px1) && (480 - RAND_HEIGHT < py2) && ((480 - RAND_HEIGHT) - 20 > py1))
	{
		Stage::Stand = TRUE;
	}
	Stage::Bound = TRUE;
	}
	//右足場
	else if ((640 - RAND_WIDTH < px1) && (740 > px2) && (480 - RAND_HEIGHT < py2) && (480 > py1))  //足場の上下にプレイヤーが接触したら
	{
	if ((640 - RAND_WIDTH < px1) && (740 > px2) && (480 - RAND_HEIGHT < py2) && ((480 - RAND_HEIGHT) - 20 > py1))
	{
		Stage::Stand = TRUE;
	}
	Stage::Bound = TRUE;
	}
	else {
	Stage::Stand = FALSE;
	Stage::Bound = FALSE;
	}
}

void Stage2::Draw() const
{
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//DrawGraph(0, 0, StageSample2, FALSE);
	//SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


	//空中の足場
	DrawBox(180, 285, 460, 305, 0x00ff00, FALSE);
	DrawBox(100, 165, 220, 182, 0x00ff00, FALSE);
	DrawBox(460, 150, 580, 165, 0x00ff00, FALSE);
}

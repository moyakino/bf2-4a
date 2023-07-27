#include "DxLib.h"
#include "Player.h"
#include "Stage1.h"
#include "Stage.h"


Stage1::Stage1()
{
	//足場
	sx1 = 180.0;
	sx2 = sx1 + GREEN_FOOT_WIDTH_1;
	sy1 = 285.0;
	sy2 = sy1 + GREEN_FOOT_HEIGHT_1;

	px1 = PLAYER::P_Move_X + 17;
	px2 = PLAYER::P_Move_X + 48;
	py1 = PLAYER::P_Move_Y + 37;
	py2 = PLAYER::P_Move_Y + 65;

	p_uc = (px1 + px2) / 2;

}

Stage1::~Stage1()
{

}

void Stage1::Update()
{

	px1 = PLAYER::P_Move_X + 17;
	px2 = PLAYER::P_Move_X + 48;
	py1 = PLAYER::P_Move_Y + 37;
	py2 = PLAYER::P_Move_Y + 65;

	p_uc = (px1 + px2) / 2;

	//空中足場
	if ((sx1 < px2) && (sx2 > px1) &&(sy1 < py2) && (sy2 > py1))  
	{
		Stage::Bound = TRUE;

	}
	//左足場
	else if ((-55 < px2) && (RAND_WIDTH > px1) && (480 - RAND_HEIGHT < py2) && (480 > py1))
	{
		Stage::Bound = TRUE;
	}
	//右足場
	else if ((640 - RAND_WIDTH < px1) && (740 > px2) && (480 - RAND_HEIGHT < py2) && (480 > py1))  //足場の上下にプレイヤーが接触したら
	{
		Stage::Bound = TRUE;
	}
	else {
		Stage:: Bound = FALSE;
	}




	
}

int Stage1::HitBox()
{

	return 0;


}

void Stage1::Draw() const
{
	DrawFormatString(400, 20, 0xffffff, "px1 :%d", px1);


	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//DrawGraph(0, 0, StageSample1, FALSE);
	//SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

	//空中の足場
	DrawBox(sx1, sy1, sx2, sy2, 0x00ff00, FALSE);

	//空中の足場
	//DrawGraph(180, 280, StageFoot[0],TRUE);

	//地面と海
	//DrawGraph(0, 418, StageLand_L, TRUE);
	//DrawGraph(480, 418, StageLand_R, TRUE);
	//DrawGraph(160,444,StageSea,TRUE);
}

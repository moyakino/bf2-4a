#include "DxLib.h"
#include "Player.h"
#include "Stage1.h"

#include "testPlayer.h"


Stage1::Stage1()
{
	//足場
	sx1 = 180.0;
	sx2 = sx1 + GREEN_FOOT_WIDTH_1;
	sy1 = 285.0;
	sy2 = sy1 - GREEN_FOOT_HEIGHT_1;

	px1 = location.x;
	px2 = location.x;
	py1 = location.y;
	py2 = location.y;


	Bound = 0;

}

Stage1::~Stage1()
{

}

void Stage1::Update()
{


}

int Stage1::HitBox()
{
	if ((sx1 < px2) && (sx2 > px1) &&   //足場の左右にプレイヤーのが接触したら
		(sy1 < py2) && (sy2 > py1))   //足場の上下にプレイヤーが接触したら
	{
		Bound = TRUE;

	}
	else {
		Bound = FALSE;
	}

	return Bound;
}

void Stage1::Draw() const
{

	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//DrawGraph(0, 0, StageSample1, FALSE);
	//SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

	//空中の足場
	DrawBox(sx1, sy1, sx2, sy2, 0x00ff00, FALSE);
	DrawFormatString(400, 0, 0xffffff, "Bound :%d", Bound);
	DrawFormatString(400, 20, 0xffffff, "px1 :%d", px1);
	DrawFormatString(400, 40,0xffffff, "py1 :%d", py1);

	//空中の足場
	//DrawGraph(180, 280, StageFoot[0],TRUE);

	//地面と海
	//DrawGraph(0, 418, StageLand_L, TRUE);
	//DrawGraph(480, 418, StageLand_R, TRUE);
	//DrawGraph(160,444,StageSea,TRUE);
}

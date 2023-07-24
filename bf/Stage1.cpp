#include "DxLib.h"
#include "Player.h"
#include "Stage1.h"

PLAYER player;

Stage1::Stage1()
{
	//足場
	x1 = 180;
	x2 = x1 + GREEN_FOOT_WIDTH_1;
	y1 = 285;
	y2 = y1 - GREEN_FOOT_HEIGHT_1;

	px1 = player.Return_MoveX() + 17;
	px2 = player.Return_MoveX() + 48;
	py1 = player.Return_MoveY() + 37;
	py2 = player.Return_MoveY() + 65;

	//中心
	p_uc = (px1 + px2) / 2;

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
	if ((x1 < px2) && (x2 > px1) &&   //足場の左右にプレイヤーのが接触したら
		(y1 < py2) && (y2 > py1))   //足場の上下にプレイヤーが接触したら
	{
		Bound = TRUE;

	}
	else {
		Bound = FALSE;
	}
}

void Stage1::Draw() const
{

	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//DrawGraph(0, 0, StageSample1, FALSE);
	//SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

	//空中の足場
	DrawBox(x1, y1, x2, y2, 0x00ff00, FALSE);
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

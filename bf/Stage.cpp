#include "DxLib.h"
#include "Player.h"
#include "Stage.h"
#include "PadInput.h"


int Stage::Stand;
int Stage::Bound;
int Stage::Death;


Stage::Stage(int num,int i)
{
	/*画像の読み込み*/
	//空中の足場
	if(StageFoot[0] = LoadGraph("images/Stage/Stage_Footing01.png")){}
	//地面(左)
	if(StageLand_L = LoadGraph("images/Stage/Stage_Land_Left01.png")){}
	//地面(右)
	if(StageLand_R = LoadGraph("images/Stage/Stage_Land_Right01.png")){}
	//海
	if(StageSea = LoadGraph("images/Stage/Stage_Sea01.png")){}


	if (StageSample1 = LoadGraph("images/StageSample/Stage_1.png")) {}
	if (StageSample2 = LoadGraph("images/StageSample/Stage_2.png")) {}
	if (StageSample3 = LoadGraph("images/StageSample/Stage_3.png")) {}
	if (StageSample4 = LoadGraph("images/StageSample/Stage_4.png")) {}
	if (StageSample5 = LoadGraph("images/StageSample/Stage_5.png")) {}


	Stand = TRUE;

	Death = FALSE;


	switch (num) {
	case 0:
		switch (i)
		{
		case 0:
			//空中の足場の座標
			location.x = 180.0;
			location.y = 285.0;
			erea.Width = 280.0;
			erea.Height = 20.0;
			break;

		case 1:
			//地上　右の足場の座標
			location.x = 0.0;
			location.y = 418.0;
			erea.Width = 160.0;
			erea.Height = 62.0;
			break;

		case 2:
			//地上　左の足場の座標
			location.x = 480.0;
			location.y = 418.0;
			erea.Width = 160.0;
			erea.Height = 62.0;
			break;

		}
		break;
	case 1:
		break;
	}

}

Stage::~Stage()
{

}

void Stage::Update()
{





	//左右の陸の判定を作りたい


	/*-53 <= p_uc && p_uc < 160 && 415 >= py2 && py2 >= 413 ||
	180 <= p_uc && p_uc <= 460 && 287 >= py2 && py2 >= 283 ||
	480 < p_uc && p_uc <= 740 && 415 >= py2 && py2 >= 413*/



}

void Stage::Draw() const
{

	DrawBox(location.x, location.y, location.x + erea.Width, location.y + erea.Height, 0x00ff00, FALSE);


	//DrawFormatString(400, 20, GetColor(255, 255, 255), " Stage:  %d ", Snum);
	//DrawFormatString(400, 0, 0xffffff, "Stand :%d", Stand);

	////当たり判定の仮表示
	//switch (Snum)
	//{
	//case 0:
	//	s1->Draw();
	//	break;

	//case 1:

	//	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	////DrawGraph(0, 0, StageSample2, FALSE);
	////SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


	////空中の足場
	//DrawBox(180, 285, 460, 305, 0x00ff00, FALSE);
	//	DrawBox(100, 165, 220, 182, 0x00ff00, FALSE);
	//	DrawBox(460, 150, 580, 165, 0x00ff00, FALSE);
	//	break;
	//case 2:

	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//	DrawGraph(0, 0, StageSample3, FALSE);
	//	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


	//	//空中の足場
	//	DrawBox(280, 368, 360, 385, 0x00ff00, FALSE);

	//	DrawBox(201, 98, 239, 117, 0x00ff00, FALSE);

	//	DrawBox(160, 268, 220, 284, 0x00ff00, FALSE);
	//	DrawBox(182, 284, 200, 335, 0x00ff00, FALSE);

	//	DrawBox(320, 183, 380, 199, 0x00ff00, FALSE);
	//	DrawBox(342, 199, 360, 250, 0x00ff00, FALSE);

	//	DrawBox(500, 99, 558, 116, 0x00ff00, FALSE);
	//	DrawBox(522, 116, 540, 165, 0x00ff00, FALSE);

	//	break;

	//case 3:

	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//	DrawGraph(0, 0, StageSample4, FALSE);
	//	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


	//	DrawBox(120, 266, 182, 284, 0xff8c00, FALSE);
	//	DrawBox(240, 300, 302, 318, 0xff8c00, FALSE);
	//	DrawBox(360, 368, 422, 386, 0xff8c00, FALSE);
	//	DrawBox(460, 284, 522, 302, 0xff8c00, FALSE);
	//	DrawBox(320, 183, 382, 201, 0xff8c00, FALSE);

	//	break;

	//case 4:
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//	DrawGraph(0, 0, StageSample5, FALSE);
	//	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

	//	DrawBox(220, 80, 282, 98, 0xff8c00, FALSE);
	//	DrawBox(200, 335, 262, 353, 0xff8c00, FALSE);
	//	DrawBox(380, 335, 442, 353, 0xff8c00, FALSE);

	//	DrawBox(500, 150, 521, 217, 0xff8c00, FALSE);
	//	DrawBox(260, 165, 281, 216, 0xff8c00, FALSE);
	//	DrawBox(100, 200, 121, 251, 0xff8c00, FALSE);

	//	break;
	//}

	///*画像の描画*/

	////地面
	//DrawBox(0, 418, 160, 480, 0x00ff00, FALSE);	//左
	//DrawBox(480, 418, 640, 480, 0x00ff00, FALSE);	//右

	//海
	DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);


}

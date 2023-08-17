#include "DxLib.h"
#include "Stage.h"
Stage::Stage(int num,int i)
{
	/*画像の読み込み*/
	//空中の足場
	if (StageFoot[0] = LoadGraph("images/Stage/Stage_Footing01.png")) {}
	if (StageFoot[1] = LoadGraph("images/Stage/Stage_Footing02.png")) {}
	if (StageFoot[2] = LoadGraph("images/Stage/Stage_Footing03.png")) {}
	if (StageFoot[3] = LoadGraph("images/Stage/Stage_Footing04.png")) {}
	if (StageFoot[4] = LoadGraph("images/Stage/Stage_Footing05.png")) {}
	if (StageFoot[5] = LoadGraph("images/Stage/Stage_Footing06.png")) {}
	if (StageFoot[6] = LoadGraph("images/Stage/Stage_Footing07.png")) {}
	if (StageFoot[7] = LoadGraph("images/Stage/Stage_Footing08.png")) {}

	//地面(左)
	if (StageLand_L[0] = LoadGraph("images/Stage/Stage_Land_Left01.png")) {}
	if(StageLand_L[1] = LoadGraph("images/Stage/Stage_Land_Left02.png")) {}

	//地面(右)
	if (StageLand_R[0] = LoadGraph("images/Stage/Stage_Land_Right01.png")) {}
	if(StageLand_R[1] = LoadGraph("images/Stage/Stage_Land_Right02.png")) {}

	//海


	switch (num) {
	case 0:	//1面
	
		switch (i)
		{

		case 0:
			//地上　左の足場の座標
			location.x = 0.0;
			location.y = 418.0;
			erea.Width = 160.0;
			erea.Height = 62.0;
			StageImg = StageLand_L[0];
			break;

		case 1:
			//地上　右の足場の座標
			location.x = 480.0;
			location.y = 418.0;
			erea.Width = 180.0;
			erea.Height = 62.0;
			StageImg = StageLand_R[0];
			break;

		case 2:
			//ワープ用の見えない足場
			location.x = -50.0;
			location.y = 418.0;
			erea.Width = 60.0;
			erea.Height = 62.0;
			break;

		case 3:
			//空中の足場の座標
			location.x = 180.0;
			location.y = 285.0;
			erea.Width = 280.0;
			erea.Height = 20.0;
			StageImg = StageFoot[0];
			break;
		}
		break;

	case 1://2面
	
		switch (i)
		{
		case 0:
			//地上　左の足場の座標
			location.x = 0.0;
			location.y = 418.0;
			erea.Width = 160.0;
			erea.Height = 62.0;
			StageImg = StageLand_L[0];
			break;

		case 1:
			//地上　右の足場の座標
			location.x = 480.0;
			location.y = 418.0;
			erea.Width = 180.0;
			erea.Height = 62.0;
			StageImg = StageLand_R[0];
			break;

		case 2:
			//ワープ用の見えない足場
			location.x = -50.0;
			location.y = 418.0;
			erea.Width = 60.0;
			erea.Height = 62.0;
			break;

		case 3:
			//空中の足場の座標
			location.x = 180.0;
			location.y = 285.0;
			erea.Width = 280.0;
			erea.Height = 20.0;
			StageImg = StageFoot[0];
			break;

		case 4:
			location.x = 100.0;
			location.y = 165.0;
			erea.Width = 122.0;
			erea.Height = 17.0;
			StageImg = StageFoot[1];
			break;

		case 5:
			location.x = 460.0;
			location.y = 150.0;
			erea.Width = 122.0;
			erea.Height = 17.0;
			StageImg = StageFoot[1];
			break;
		}
		break;

	case 2://3面
	
		switch (i)
		{
		case 0:
			//地上　左の足場の座標
			location.x = 0.0;
			location.y = 418.0;
			erea.Width = 160.0;
			erea.Height = 62.0;
			StageImg = StageLand_L[0];
			break;

		case 1:
			//地上　右の足場の座標
			location.x = 480.0;
			location.y = 418.0;
			erea.Width = 180.0;
			erea.Height = 62.0;
			StageImg = StageLand_R[0];
			break;

		case 2:
			//ワープ用の見えない足場
			location.x = -50.0;
			location.y = 418.0;
			erea.Width = 60.0;
			erea.Height = 62.0;
			break;

		case 3:
			location.x = 280.0;
			location.y = 368.0;
			erea.Width = 81.0;
			erea.Height = 18.0;
			StageImg = StageFoot[2];
			break;

		case 4:
			location.x = 201.0;
			location.y = 98.0;
			erea.Width = 42.0;
			erea.Height = 18.0;
			StageImg = StageFoot[4];
			break;

			
		case 5: //足場の部分
			location.x = 160.0;
			location.y = 268.0;
			erea.Width = 60.0;
			erea.Height = 16.0;
			StageImg = StageFoot[3];
			break;

		case 6:	//鍾乳石の部分
			location.x = 182.0;
			location.y = 283.0;
			erea.Width = 18.0;
			erea.Height = 52.0;
			break;

		case 7:	//足場の部分
			location.x = 320.0;
			location.y = 183.0;
			erea.Width = 60.0;
			erea.Height = 16.0;
			StageImg = StageFoot[3];
			break;

		case 8:	//鍾乳石の部分
			location.x = 342.0;
			location.y = 198.0;
			erea.Width = 18.0;
			erea.Height = 52.0;
			break;

		case 9:	//足場の部分
			location.x = 500.0;
			location.y = 99.0;
			erea.Width = 60.0;
			erea.Height = 16.0;
			StageImg = StageFoot[3];
			break;

		case 10: //鍾乳石の部分
			location.x = 522.0;
			location.y = 114.0;
			erea.Width = 18.0;
			erea.Height = 52.0;
			break;
	
		}
		break;

	case 3://4面

		switch (i)
		{
		case 0:
			//地上　左の足場の座標
			location.x = 0.0;
			location.y = 418.0;
			erea.Width = 160.0;
			erea.Height = 62.0;
			StageImg = StageLand_L[1];
			break;

		case 1:
			//地上　右の足場の座標
			location.x = 480.0;
			location.y = 418.0;
			erea.Width = 180.0;
			erea.Height = 62.0;
			StageImg = StageLand_R[1];
			break;

		case 2:
			//ワープ用の見えない足場
			location.x = -50.0;
			location.y = 418.0;
			erea.Width = 60.0;
			erea.Height = 62.0;
			break;

		case 3:
			location.x = 120.0;
			location.y = 266.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];
			break;

		case 4:
			location.x = 240.0;
			location.y = 335.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];
			break;

		case 5:
			location.x = 360.0;
			location.y = 368.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];

			break;

		case 6:
			location.x = 460.0;
			location.y = 284.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];

			break;

		case 7:
			location.x = 320.0;
			location.y = 183.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];

			break;
		}
		break;

	case 4://5面

		switch (i)
		{
		case 0:
			//地上　左の足場の座標
			location.x = 0.0;
			location.y = 418.0;
			erea.Width = 160.0;
			erea.Height = 62.0;
			StageImg = StageLand_L[1];
			break;

		case 1:
			//地上　右の足場の座標
			location.x = 480.0;
			location.y = 418.0;
			erea.Width = 180.0;
			erea.Height = 62.0;
			StageImg = StageLand_R[1];
			break;

		case 2:
			//ワープ用の見えない足場
			location.x = -50.0;
			location.y = 418.0;
			erea.Width = 60.0;
			erea.Height = 62.0;
			break;
		
		case 3:
			location.x = 220.0;
			location.y = 80.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];

			break;

		case 4:
			location.x = 200.0;
			location.y = 335.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];

			break;

		case 5:
			location.x = 380.0;
			location.y = 335.0;
			erea.Width = 62.0;
			erea.Height = 18.0;
			StageImg = StageFoot[5];

			break;

		case 6:
			location.x = 500.0;
			location.y = 150.0;
			erea.Width = 21.0;
			erea.Height = 67.0;
			StageImg = StageFoot[7];

			break;

		case 7:
			location.x = 260.0;
			location.y = 165.0;
			erea.Width = 21.0;
			erea.Height = 51.0;
			StageImg = StageFoot[6];

			break;

		case 8:
			location.x = 100.0;
			location.y = 200.0;
			erea.Width = 21.0;
			erea.Height = 51.0;
			StageImg = StageFoot[6];

			break;
		}
		break;
	}
	
}

Stage::~Stage()
{

}

void Stage::Update()
{

}

void Stage::Draw() const
{
	//当たり判定の描画
	DrawBox(location.x, location.y, location.x + erea.Width, location.y + erea.Height, 0x00ff00, FALSE);

	//ステージ画像の描画
	DrawGraph(location.x, location.y, StageImg, TRUE);

}

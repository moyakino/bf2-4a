#include "DxLib.h"
#include "Stage.h"
#include "PadInput.h"

Stage::Stage()
{
	/*�摜�̓ǂݍ���*/
	//�󒆂̑���
	if(StageFoot[0] = LoadGraph("images/Stage/Stage_Footing01.png")){}
	//�n��(��)
	if(StageLand_L = LoadGraph("images/Stage/Stage_Land_Left01.png")){}
	//�n��(�E)
	if(StageLand_R = LoadGraph("images/Stage/Stage_Land_Right01.png")){}
	//�C
	if(StageSea = LoadGraph("images/Stage/Stage_Sea01.png")){}


	if (StageSample1 = LoadGraph("images/StageSample/Stage_1.png")) {}
	if (StageSample2 = LoadGraph("images/StageSample/Stage_2.png")) {}
	if (StageSample3 = LoadGraph("images/StageSample/Stage_3.png")) {}
	if (StageSample4 = LoadGraph("images/StageSample/Stage_4.png")) {}
	if (StageSample5 = LoadGraph("images/StageSample/Stage_5.png")) {}


	Snum = 0;
	X_Btn = 0;
	sFps = 0;
}

Stage::~Stage()
{

}

void Stage::Update()
{
	// A�{�^���P����
	X_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_X);

	sFps++;

	if (X_Btn == 1) {
		if (sFps % 2 == 0) {
			if (++Snum > 4) {
				Snum = 0;
			}
		}
	}


}

void Stage::Draw() const
{
	DrawFormatString(0, 20, GetColor(255, 255, 255), " Stage:  %d ", Snum);

	//�����蔻��̉��\��
	switch (Snum)
	{
	case 0:

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, StageSample1, FALSE);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

		//�󒆂̑���
		DrawBox(180, 285, 460, 305, 0x00ff00, FALSE);

		//�n��
		DrawBox(0, 418, 160, 480, 0x00ff00, FALSE);	//��
		DrawBox(480, 418, 640, 480, 0x00ff00, FALSE);	//�E

		//�C
		DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);

		//�󒆂̑���
		//DrawGraph(180, 280, StageFoot[0],TRUE);

		//�n�ʂƊC
		//DrawGraph(0, 418, StageLand_L, TRUE);
		//DrawGraph(480, 418, StageLand_R, TRUE);
		//DrawGraph(160,444,StageSea,TRUE);

		break;

	case 1:

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, StageSample2, FALSE);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


		//�󒆂̑���
		DrawBox(180, 285, 460, 305, 0x00ff00, FALSE);
		DrawBox(100, 165, 220, 182, 0x00ff00, FALSE);
		DrawBox(460, 150, 580, 165, 0x00ff00, FALSE);

		//�n��
		DrawBox(0, 418, 160, 480, 0x00ff00, FALSE);	//��
		DrawBox(480, 418, 640, 480, 0x00ff00, FALSE);	//�E

		//�C
		DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
		break;
	case 2:

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, StageSample3, FALSE);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


		//�󒆂̑���
		DrawBox(280, 368, 360, 385, 0x00ff00, FALSE);

		DrawBox(201, 98, 239, 117, 0x00ff00, FALSE);

		DrawBox(160, 268, 220, 284, 0x00ff00, FALSE);
		DrawBox(182, 284, 200, 335, 0x00ff00, FALSE);

		DrawBox(320, 183, 380, 199, 0x00ff00, FALSE);
		DrawBox(342, 199, 360, 250, 0x00ff00, FALSE);

		DrawBox(500, 99, 558, 116, 0x00ff00, FALSE);
		DrawBox(522, 116, 540, 165, 0x00ff00, FALSE);


		//�n��
		DrawBox(0, 418, 160, 480, 0x00ff00, FALSE);	//��
		DrawBox(480, 418, 640, 480, 0x00ff00, FALSE);	//�E

		//�C
		DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
		break;

	case 3:

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, StageSample4, FALSE);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);


		DrawBox(120, 266, 182, 284, 0xff8c00, FALSE);
		DrawBox(240, 300, 302, 318, 0xff8c00, FALSE);
		DrawBox(360, 368, 422, 386, 0xff8c00, FALSE);
		DrawBox(460, 284, 522, 302, 0xff8c00, FALSE);
		DrawBox(320, 183, 382, 201, 0xff8c00, FALSE);


		//�n��
		DrawBox(0, 418, 160, 480, 0xff8c00, FALSE);	//��
		DrawBox(480, 418, 640, 480, 0xff8c00, FALSE);	//�E

		//�C
		DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
		break;

	case 4:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawGraph(0, 0, StageSample5, FALSE);
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

		DrawBox(220, 80, 282, 98, 0xff8c00, FALSE);
		DrawBox(200, 335, 262, 353, 0xff8c00, FALSE);
		DrawBox(380, 335, 442, 353, 0xff8c00, FALSE);

		DrawBox(500, 150, 521, 217, 0xff8c00, FALSE);
		DrawBox(260, 165, 281, 216, 0xff8c00, FALSE);
		DrawBox(100, 200, 121, 251, 0xff8c00, FALSE);


		//�n��
		DrawBox(0, 418, 160, 480, 0xff8c00, FALSE);	//��
		DrawBox(480, 418, 640, 480, 0xff8c00, FALSE);	//�E

		//�C
		DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
		break;
	}

	/*�摜�̕`��*/



}

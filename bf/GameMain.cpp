#include"DxLib.h"
#include"FPS.h"
#include"GameMain.h"

GameMain::GameMain()
{
	if ((StageFoot[0] = LoadGraph("images/Stage/Stage_Footing01.png")) == -1);

	if ((StageLand_L = LoadGraph("images/Stage/Stage_Land_Left01.png")) == -1);
	if ((StageLand_R = LoadGraph("images/Stage/Stage_Land_Right01.png")) == -1);
	if ((StageSea = LoadGraph("images/Stage/Stage_Sea01.png")) == -1);
}

GameMain::~GameMain()
{

}

AbstractScene* GameMain::Update()
{
	return this;
}


void GameMain::Draw()const
{
	DrawString(0, 20, "GameMain", 0xffffff);

	//�����蔻��̉��\��

	//�󒆂̑���
	DrawBox(180, 280, 460, 297, 0x00ff00,FALSE);

	//�n��
	DrawBox(0,416,160,480,0x00ff00,FALSE);	//��
	DrawBox(480, 416, 640, 480, 0x00ff00, FALSE);	//�E

	//�C
	DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);



	/*�摜�̕`��*/
	
	//�󒆂̑���
	//DrawGraph(180, 280, StageFoot[0],TRUE);

	//�n�ʂƊC
	//DrawGraph(0, 416, StageLand_L, TRUE);
	//DrawGraph(480, 416, StageLand_R, TRUE);
	//DrawGraph(160,444,StageSea,TRUE);

}
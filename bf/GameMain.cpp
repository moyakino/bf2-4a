#include"DxLib.h"
#include"GameMain.h"


//�R���X�g���N�^
GameMain::GameMain()
{
	Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);

	/*�摜�̓ǂݍ���*/
	//�󒆂̑���
	StageFoot[0] = LoadGraph("images/Stage/Stage_Footing01.png");
	//�n��(��)
	StageLand_L = LoadGraph("images/Stage/Stage_Land_Left01.png");
	//�n��(�E)
	StageLand_R = LoadGraph("images/Stage/Stage_Land_Right01.png");
	//�C
	StageSea = LoadGraph("images/Stage/Stage_Sea01.png");

	StageSample = LoadGraph("images/StageSample/Stage_1.png");

	player = new PLAYER();
	bubble = new Bubble();
}

GameMain::~GameMain()
{
	delete player;
	delete bubble;
}


AbstractScene* GameMain::Update()
{

	player->Update();
	bubble->Update();

	return this;
}


void GameMain::Draw()const
{
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawGraph(0, 0, StageSample, FALSE);
	//���ɖ߂��B�������A�����œ���̉摜���������ɂȂ�B                
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);

	//�����蔻��̉��\��

	//�󒆂̑���
	DrawBox(180, 285, 460, 305, 0x00ff00,FALSE);

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

	player->Draw();
	fish->Draw();

	bubble->Draw();

	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	
	
}
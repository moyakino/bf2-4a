#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"
#include "testPlayer.h"

#include "PadInput.h"

//�R���X�g���N�^
GameMain::GameMain()
{


	/*Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);*/
	ui = new UI();
	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	enemybird = new EnemyBird();
	//bubble = new Bubble();
	//stage = new Stage();
	thunder = new Thunder();

	Snum = 0;

	switch (Snum)
	{
	case 0:
		//�X�e�[�W�̐���
		for (int i = 0; i < 3; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}

		break;
	}

}

GameMain::~GameMain()
{
	delete stage;
	delete player;
	delete bubble;
	delete thunder;
	delete fish;
	delete ui;
	delete enemybird;

}


AbstractScene* GameMain::Update()
{
	//stage->Update();
	player->Update();
	//enemybird->Update(PLAYER::P_Move_X, PLAYER::P_Move_Y);
	bubble->Update();
	fish->Update(player->GetLocation().x , player->GetLocation().y);
	enemybird->Update();
	thunder->Update();

	bubble->Update();


	
	fps++;

	// X�{�^���P����
	int X_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_X);
	if (X_Btn == 1) {
		if (fps % 2 == 0) {
			if (++Snum > 4) {
				Snum = 0;
			}
		}
	}


	//�����蔻��
	switch (Snum)
	{
	case 0:

		for (int i = 0; i < 3; i++)
		{
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == 1)
			{
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == 1) 
				{
					player->P_Stand_Flg = TRUE;
					//player->Player_Move();
					//player->SetStandFlg(1);
				}
				else
				{
					//player->SetStandFlg(0);
					player->P_Stand_Flg = FALSE;
				}

				//����ȊO�̏ꏊ�Ȃ璵�˕Ԃ�
				if (StageFoot[i]->L_SideBoxCollider(player) == 1) 
				{

				}

				if (StageFoot[i]->R_SideBoxCollider(player) == 1) 
				{

				}
			}

			////�G������ɓ������Ă��邩
			//if (StageFoot[i]->HitCollider(Enemy[i]) == true)
			//{
			//	//���A����̏�ɗ����Ă��邩�ǂ���
			//	if (StageFoot[i]->TopBoxCollider(Enemy[i]) == true)
			//	{
			//		Enemy[i]->Update();
			//	}
			//}

		}
		break;
	}



	return this;
}


void GameMain::Draw()const
{

	/*�摜�̕`��*/
	
	//�󒆂̑���
	//DrawGraph(180, 280, StageFoot[0],TRUE);

	//�n�ʂƊC
	//DrawGraph(0, 416, StageLand_L, TRUE);
	//DrawGraph(480, 416, StageLand_R, TRUE);
	//DrawGraph(160,444,StageSea,TRUE);


	switch (Snum)
	{
	case 0:
		//�X�e�[�W�̕`��
		for (int i = 0; i < 3; i++)
		{
			StageFoot[i]->Draw();
		}


		break;
	}


	//stage->Draw();
	
	//enemybird->Draw();
	enemybird->Draw();
	fish->Draw();
	bubble->Draw();
	//ui->Draw();
	thunder->Draw();
	//ui->Draw();
	player->Draw();

	DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	DrawFormatString(400, 50, GetColor(255, 0, 0), "Snum:%d", Snum);
	
}
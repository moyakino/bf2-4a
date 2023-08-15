#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"

#include "PadInput.h"



//�R���X�g���N�^
GameMain::GameMain()
{
	if (StageSea = LoadGraph("images/Stage/Stage_Sea01.png")) {}


	Bgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(Bgm, DX_PLAYTYPE_BACK);

	ui = new UI();
	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	enemybird = new EnemyBird();
	//bubble = new Bubble();
	//stage = new Stage();
	thunder = new Thunder();

	Snum = 0;

	for (int i = 0; i < 3; i++)
	{
		StageFoot[i] = new Stage(Snum, i);
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
	fps++;

	// X�{�^���P����
	int X_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_X);
	if (X_Btn == 1)
	{
		if (fps % 2 == 0)
		{
			++Snum;
	
			//���Z�b�g
			if (Snum > 4) {
				Snum = 0;
			}
			CreateStage();
		}
	}

	bool TouchFlg = false;
	
	//�����蔻��
	switch (Snum)
	{
	case 0:
		for (int i = 0; i < 3; i++){
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true){
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//���˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true){
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}	
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 1:
		for (int i = 0; i < 5; i++) {
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//���˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 2:
		for (int i = 0; i < 10; i++) {
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//���˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 3:
		for (int i = 0; i < 7; i++) {
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//���˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}

		break;

	case 4:
		for (int i = 0; i < 8; i++) {
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//���˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		if (TouchFlg == true)
		{
			player->P_Stand_Flg = TRUE;
		}
		if (TouchFlg == false)
		{
			player->P_Stand_Flg = FALSE;
		}
		break;
	}


	//stage->Update();
	player->Update();
	//enemybird->Update(PLAYER::P_Move_X, PLAYER::P_Move_Y);
	bubble->Update();
	fish->Update(player->GetLocation().x , player->GetLocation().y);
	enemybird->Update();
	thunder->Update();

	bubble->Update();

	
	return this;
}

void GameMain::CreateStage()
{
	//�X�e�[�W�̐���
	switch (Snum)
	{
	case 0:
		for (int i = 0; i < 3; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 1:
		for (int i = 0; i < 5; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 2:
		for (int i = 0; i < 10; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 3:
		for (int i = 0; i < 7; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 4:
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;
	}
}

void GameMain::Draw()const
{
	//�X�e�[�W�̕`��
	switch (Snum)
	{
	case 0:
		for (int i = 0; i < 3; i++)
		{
			StageFoot[i]->Draw();
		}
		break;
		
	case 1:
		for (int i = 0; i < 5; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 2:
		for (int i = 0; i < 10; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 3:
		for (int i = 0; i < 7; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 4:
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i]->Draw();

		}
		break;
	}


	//�C
	//DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
	DrawGraph(160, 445, StageSea, TRUE);

	//stage->Draw();
	player->Draw();

	enemybird->Draw();
	fish->Draw();
	bubble->Draw();
	//ui->Draw();
	thunder->Draw();
	//ui->Draw();
	player->Draw();

}
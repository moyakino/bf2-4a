#include"DxLib.h"
#include "TitleScene.h"
#include"GameMain.h"
#include "PadInput.h"
#include "Player.h"
#include "TitleScene.h"
#include"enemybird.h"

bool GameMain::PauseFlg;

//�R���X�g���N�^
GameMain::GameMain()
{
	if (StageSea = LoadGraph("images/Stage/Stage_Sea01.png")) {}

	MainBgm = LoadSoundMem("sounds/SE_Start.wav");
	PlaySoundMem(MainBgm, DX_PLAYTYPE_BACK);
	ui = new UI();
	player = new PLAYER();
	bubble = new Bubble();
	fish = new Fish();
	//enemybird = new EnemyBird();
	//bubble = new Bubble();
	//stage = new Stage();
	thunder = new Thunder();

	Snum = 0;

	for (int i = 0; i < 4; i++)
	{
		StageFoot[i] = new Stage(Snum, i);
	}

	for (int j = 0; j < 3; j++)
	{
		Enemy[j] = new EnemyBird(Snum, j);
	}

	PauseFlg = TRUE;
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
	////�|�[�Y�t���O�؂�ւ�����
	//if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	//{
	//	PauseFlg = !PauseFlg;
	//}

	//�|�[�Y���łȂ��Ȃ�
	if (PauseFlg == FALSE) {

		fps++;

		if (ui->GetGameOver() == TRUE) {
			DrawGameOver = TRUE;
			if (fps > 59) {
				if (fps % 2 == 0) {
					Cnt++;
				}
			}
			if (Cnt > 3) {
				return new Title();
				Cnt = 0;
			}
		}

	//stage->Update();
	player->Update();
	fish->Update(player->GetLocation().x, player->GetLocation().y);
	ui->Update(player->PlayerLife, player->FishHit);
	bubble->Update(player->GetLocation().x, player->GetLocation().y);
	fish->Update(player->GetLocation().x , player->GetLocation().y);
	//enemybird->Update(player->GetLocation().x, player->GetLocation().y);
	thunder->Update(player->GetLocation().x, player->GetLocation().y);

	for (int j = 0; j < 3; j++){
		Enemy[j]->Update(player->GetLocation().x, player->GetLocation().y);
	}
	

	// X�{�^���P����
	int X_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_X);
	if (X_Btn == 1)
	{
		if (fps % 2 == 0)
		{
			++Snum;
			UI::i++;
			//���Z�b�g
			if (Snum > 4) {
				Snum = 0;
				UI::i = 1;
			}
			CreateStage();
		}
	}

	bool TouchFlg = false;
	bool tHitFlg = false;
	
	//�����蔻��
	switch (Snum)
	{
	case 0:	//1��

		//����̓����蔻��
		for (int i = 0; i < 4; i++)
		{
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true){
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//�v���C���[�̒��˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true){
				player->CheckBound(StageFoot[i]);
			}

			//��
			if (thunder->StageHit(StageFoot[i]) == true) {
				tHitFlg = true;
			}	
			

		}

		//����̏�ɗ����Ă�����StandFlg��TRUE�ɂ���
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//����̏�ɗ����Ă��Ȃ�������StandFlg��FALSE�ɂ���
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

		//�G�̓����蔻��
		for (int j = 0; j < 3; j++)
		{
			switch (player->EnemyCollider(Enemy[j]))
			{
			case 1://���ɂ��������Ƃ�

				//�G���ҋ@��ԈȊO�̎��͒��˕Ԃ�if��������

				player->BoundMinusX();
				Enemy[j]->BoundPlusX();

				////�v���C���[���G����
				//if (player->GetLocation().y < enemybird->GetLocation().y + 25)
				//{

				//}

				////�v���C���[���G��艺
				//if (player->GetLocation().y > enemybird->GetLocation().y + 25)
				//{

				//}

				break;

			case 2://�E�ɂ��������Ƃ�
				player->BoundPlusX();
				Enemy[j]->BoundMinusX();
				break;

			case 3://��ɂ��������Ƃ�
				player->BoundMinusY();
				Enemy[j]->BoundPlusY();
				break;

			case 4://���ɂ��������Ƃ�
				player->BoundPlusY();
				Enemy[j]->BoundMinusY();
				break;
			}
		}

		break;

	case 1:	//2��

		//����̓����蔻��
		for (int i = 0; i < 6; i++) 
		{
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//�v���C���[�̒��˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		//����̏�ɗ����Ă�����StandFlg��TRUE�ɂ���
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//����̏�ɗ����Ă��Ȃ�������StandFlg��FALSE�ɂ���
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

			break;

	case 2:	//3��

		//����̓����蔻��
		for (int i = 0; i < 11; i++) 
		{
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//�v���C���[�̒��˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		//����̏�ɗ����Ă�����StandFlg��TRUE�ɂ���
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//����̏�ɗ����Ă��Ȃ�������StandFlg��FALSE�ɂ���
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

			break;

	case 3:	//4��

		//����̓����蔻��
		for (int i = 0; i < 8; i++) 
		{
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//�v���C���[�̒��˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}
		}

		//����̏�ɗ����Ă�����StandFlg��TRUE�ɂ���
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//����̏�ɗ����Ă��Ȃ�������StandFlg��FALSE�ɂ���
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}

			break;

	case 4:	//5��

		//����̓����蔻��
		for (int i = 0; i < 9; i++) 
		{
			//�v���C���[������ɓ������Ă��邩
			if (StageFoot[i]->HitCollider(player) == true) {
				//���A����̏�ɗ����Ă��邩�ǂ���
				if (StageFoot[i]->TopBoxCollider(player) == true)
				{
					TouchFlg = true;
				}
			}

			//�v���C���[�̒��˕Ԃ�̔���
			if (StageFoot[i]->TopBoxCollider(player) != true) {
				player->CheckBound(StageFoot[i]);
			}

		}

		//����̏�ɗ����Ă�����StandFlg��TRUE�ɂ���
		if (TouchFlg == true){
			player->P_Stand_Flg = TRUE;
		}

		//����̏�ɗ����Ă��Ȃ�������StandFlg��FALSE�ɂ���
		if (TouchFlg == false){
			player->P_Stand_Flg = FALSE;
		}
		break;
	}

		if (fps > 59) {
			fps = 0;
		}

	}
	return this;
	
}

//�G�E�X�e�[�W�̐���
void GameMain::CreateStage()
{
	switch (Snum)
	{
	case 0:	//1��

		//�X�e�[�W�̐���
		for (int i = 0; i < 4; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}

		//�G�̐���
		for (int j = 0; j < 3; j++)
		{
			Enemy[j] = new EnemyBird(Snum, j);
		}

		break;

	case 1:	//2��

		//�X�e�[�W�̐���
		for (int i = 0; i < 6; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 2:	//3��

		//�X�e�[�W�̐���
		for (int i = 0; i < 11; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 3:	//4��

		//�X�e�[�W�̐���
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;

	case 4:	//5��

		//�X�e�[�W�̐���
		for (int i = 0; i < 9; i++)
		{
			StageFoot[i] = new Stage(Snum, i);
		}
		break;
	}
}

void GameMain::Draw()const
{
	//�`��
	switch (Snum)
	{
	case 0:	//1��

		//�X�e�[�W�̕`��
		for (int i = 0; i < 4; i++)
		{
			StageFoot[i]->Draw();
		}

		//�G�̕`��
		for (int j = 0; j < 3; j++)
		{
			Enemy[j]->Draw();
		}
		break;
		
	case 1:	//2��

		//�X�e�[�W�̕`��
		for (int i = 0; i < 6; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 2:	//3��

		//�X�e�[�W�̕`��
		for (int i = 0; i < 11; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 3:	//4��

		//�X�e�[�W�̕`��
		for (int i = 0; i < 8; i++)
		{
			StageFoot[i]->Draw();
		}
		break;

	case 4:	//5��

		//�X�e�[�W�̕`��
		for (int i = 0; i < 9; i++)
		{
			StageFoot[i]->Draw();

		}
		break;
	}


	//�C
	//DrawBox(160, 444, 480, 480, 0x0000ff, FALSE);
	//DrawGraph(160, 445, StageSea, TRUE);

	//stage->Draw();


	ui->Draw();

	if (DrawGameOver == FALSE) {
		//enemybird->Draw();
		bubble->Draw();
		thunder->Draw();
		player->Draw();
		fish->Draw();
	}

	DrawGraph(160, 445, StageSea, TRUE);
	
	//DrawFormatString(0, 50, GetColor(255, 0, 0), "GameMain");
	//DrawFormatString(400, 50, GetColor(255, 0, 0), "Snum:%d", Snum);
	
	//�ꎞ��~���̕`��
	if (PauseFlg == TRUE)
	{
	
		/*SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);*/
		DrawBox(0, 0, 1000, 780, 0x000000, FALSE);
		/*SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);*/
		DrawString(120, 70, "�|�[�Y���j���[�\��", GetColor(255, 255, 255));
	}
}
#include "DxLib.h"
#include "testPlayer.h"
#include "PadInput.h"

testPlayer::testPlayer()
{
	location.x = 100;
	location.y = 350;

	Speed = 0;	//�ړ����x
	VelX = 0;	//����x
	VelY = 0;	//����y

	Gravity = 0.6;	//�d��
	Reflect = 0.8;	//����

	sCnt = 0;
	wCnt = 0;
	fCnt = 0;

	PlayerFlg = PLAYER_FLG::STAND;

	fps = 0;

	//�v���C���[�摜�f�[�^�̓ǂݍ���
	if (LoadDivGraph("images/Player/Player_Animation.png", 32, 8, 4, 64, 64, P_ArrayImg)) {}

	pLeft = FALSE;

}

testPlayer::~testPlayer()
{
}

void testPlayer::Update()
{

	fps++;

	//�����[�v
	if (location.x < 0) 
	{
		location.x = 640;
	}

	//�E���[�v
	if (location.x > 640)
	{
		location.x = 0;
	}

	//�V��
	if (location.y < 0) 
	{
		location.y = 0;
	}


	//����
	if (location.y < 350) {
		VelY = Gravity;
		location.y += VelY;
	}

	//�A�j���[�V�����Ǘ�
	switch (PlayerFlg)
	{
	case PLAYER_FLG::STAND:
		StandAnim();
		break;
	case PLAYER_FLG::WALK:
		WalkAnim();
		break;
	case PLAYER_FLG::FLY:
		FlyAnim();
		break;
	}


	Player_StandMove();
	Player_Fly();

}

void testPlayer::Player_StandMove() 
{

	if (PlayerFlg != PLAYER_FLG::FLY) 
	{
		//���ړ�
		if (PAD_INPUT::GetLStick().x < LEFT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT)) {
			PlayerFlg = PLAYER_FLG::WALK;

			//���������Ă邩
			pLeft = TRUE;

			Speed = RUN_SPEED;

			location.x = location.x - Speed * (VelX / 10);

		}
		//�E�ړ�
		else if (PAD_INPUT::GetLStick().x > RIGHT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT)) {
			PlayerFlg = PLAYER_FLG::WALK;

			//���������Ă邩
			pLeft = FALSE;

			Speed = RUN_SPEED;

			location.x = location.x + Speed * (VelX / 10);
		}
		else {
			PlayerFlg = PLAYER_FLG::STAND;
			VelX = 0;
			Speed = 0;
		}

		//����
		if (PlayerFlg == PLAYER_FLG::WALK && VelX < 15) {

			VelX += 0.5;
		}
	}
	


}

void testPlayer::Player_Fly() 
{
	//A�{�^���P����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		//�C���^�[�o������������
		if (fps % 2 == 0) {

			PlayerFlg = PLAYER_FLG::FLY;
			VelY *= Gravity;
			location.y -= VelY;
		}
	}

	//A�{�^���P����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		//�C���^�[�o������������
		if (fps % 2 == 0)
		{
			//������ړ�
			if (PAD_INPUT::GetLStick().x < LEFT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
			{
				PlayerFlg = PLAYER_FLG::FLY;

				if (VelY <= 15)
				{
					VelX += Gravity;
					VelY += Gravity;
				}

				location.x -= VelX;
				location.y -= VelY;
			}
			//�E����ړ�
			else if (PAD_INPUT::GetLStick().x > RIGHT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
			{
				PlayerFlg = PLAYER_FLG::FLY;


				if (VelY <= 15)
				{
					VelX += Gravity;
					VelY += Gravity;
				}

				location.x += VelX;
				location.y -= VelY;

			}
		}
	}


	//B�{�^��������
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B))
	{
		PlayerFlg = PLAYER_FLG::FLY;
		VelY += Gravity;
		location.y -= VelY;
	}

	//B�{�^��������
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) 
	{
		//������ړ�
		if (PAD_INPUT::GetLStick().x < LEFT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
		{
			PlayerFlg = PLAYER_FLG::FLY;

			if (VelY <= 15)
			{
				VelX += Gravity;
				VelY += Gravity;
			}

			location.x -= VelX;
			location.y -= VelY;

		}
		//�E����ړ�
		else if (PAD_INPUT::GetLStick().x > RIGHT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
		{
			PlayerFlg = PLAYER_FLG::FLY;

			if (VelY <= 15)
			{
				VelX += Gravity;
				VelY += Gravity;
			}

			location.x += VelX;
			location.y -= VelY;
		}
	}

}

void testPlayer::Player_Bound()
{


}



int testPlayer::StandAnim() 
{

	if (fps % 60 == 0)
	{
		++sCnt;

		if (sCnt > 3) {
			sCnt = 0;
		}
	}

	switch (sCnt)
	{
	case 0:
		P_Img = P_ArrayImg[1];
		break;
	case 1:
		P_Img = P_ArrayImg[0];
		break;
	case 2:
		P_Img = P_ArrayImg[1];
		break;
	case 3:
		P_Img = P_ArrayImg[2];
		break;
	}

	return P_Img;
}

int testPlayer::WalkAnim()
{

	if (fps % 20 == 0){
		++wCnt;
		if (wCnt > 3) {
			wCnt = 0;
		}
	}

	switch (wCnt)
	{
	case 0:
		P_Img = P_ArrayImg[8];
		break;
	case 1:
		P_Img = P_ArrayImg[9];
		break;
	case 2:
		P_Img = P_ArrayImg[10];
		break;
	case 3:
		P_Img = P_ArrayImg[11];
		break;
	}

	return P_Img;
}

int testPlayer::FlyAnim()
{
	if (fps % 15 == 0)
	{
		++fCnt;

		if (fCnt > 4) {
			fCnt = 0;
		}
	}

	switch (fCnt)
	{
	case 0:
		P_Img = P_ArrayImg[17];
		break;
	case 1:
		P_Img = P_ArrayImg[18];
		break;
	case 2:
		P_Img = P_ArrayImg[19];
		break;
	case 3:
		P_Img = P_ArrayImg[20];
		break;
	case 4:
		P_Img = P_ArrayImg[21];
		break;

	}

	return P_Img;
}



void testPlayer::Draw() const
{

	DrawFormatString(0, 20, 0xffffff, "VelX:%d", VelX);
	DrawFormatString(0, 40, 0xffffff, " VelY:%f", VelY);
	DrawFormatString(0, 60, 0xffffff, " Speed:%f", Speed);
	DrawFormatString(0, 80, 0xffffff, " x:%f", location.x);
	DrawFormatString(0, 100, 0xffffff, " y:%f", location.y);

	//�ŏ��͉E�����ŕ`�悳���
	if (pLeft==FALSE) {
		DrawTurnGraph(location.x, location.y, P_Img, TRUE);
	}
	else if(pLeft==TRUE) {
		DrawGraph(location.x, location.y, P_Img, TRUE);
	}
}

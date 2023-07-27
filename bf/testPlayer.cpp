#include "DxLib.h"
#include "testPlayer.h"
#include "PadInput.h"

testPlayer::testPlayer()
{
	location.x = 100;
	location.y = 350;

	Speed = 0;	//移動速度
	VelX = 0;	//初速x
	VelY = 0;	//初速y

	Gravity = 0.6;	//重力
	Reflect = 0.8;	//反発

	sCnt = 0;
	wCnt = 0;
	fCnt = 0;

	PlayerFlg = PLAYER_FLG::STAND;

	fps = 0;

	//プレイヤー画像データの読み込み
	if (LoadDivGraph("images/Player/Player_Animation.png", 32, 8, 4, 64, 64, P_ArrayImg)) {}

	pLeft = FALSE;

}

testPlayer::~testPlayer()
{
}

void testPlayer::Update()
{

	fps++;

	//左ワープ
	if (location.x < 0) 
	{
		location.x = 640;
	}

	//右ワープ
	if (location.x > 640)
	{
		location.x = 0;
	}

	//天井
	if (location.y < 0) 
	{
		location.y = 0;
	}


	//落下
	if (location.y < 350) {
		VelY = Gravity;
		location.y += VelY;
	}

	//アニメーション管理
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
		//左移動
		if (PAD_INPUT::GetLStick().x < LEFT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT)) {
			PlayerFlg = PLAYER_FLG::WALK;

			//左を向いてるか
			pLeft = TRUE;

			Speed = RUN_SPEED;

			location.x = location.x - Speed * (VelX / 10);

		}
		//右移動
		else if (PAD_INPUT::GetLStick().x > RIGHT_MOVE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT)) {
			PlayerFlg = PLAYER_FLG::WALK;

			//左を向いてるか
			pLeft = FALSE;

			Speed = RUN_SPEED;

			location.x = location.x + Speed * (VelX / 10);
		}
		else {
			PlayerFlg = PLAYER_FLG::STAND;
			VelX = 0;
			Speed = 0;
		}

		//加速
		if (PlayerFlg == PLAYER_FLG::WALK && VelX < 15) {

			VelX += 0.5;
		}
	}
	


}

void testPlayer::Player_Fly() 
{
	//Aボタン単押し
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		//インターバルを持たせる
		if (fps % 2 == 0) {

			PlayerFlg = PLAYER_FLG::FLY;
			VelY *= Gravity;
			location.y -= VelY;
		}
	}

	//Aボタン単押し
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		//インターバルを持たせる
		if (fps % 2 == 0)
		{
			//左浮上移動
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
			//右浮上移動
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


	//Bボタン長押し
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B))
	{
		PlayerFlg = PLAYER_FLG::FLY;
		VelY += Gravity;
		location.y -= VelY;
	}

	//Bボタン長押し
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_B)) 
	{
		//左浮上移動
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
		//右浮上移動
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

	//最初は右向きで描画される
	if (pLeft==FALSE) {
		DrawTurnGraph(location.x, location.y, P_Img, TRUE);
	}
	else if(pLeft==TRUE) {
		DrawGraph(location.x, location.y, P_Img, TRUE);
	}
}

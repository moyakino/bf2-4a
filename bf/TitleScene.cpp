#include "DxLib.h"
#include "PadInput.h"
#include "TitleScene.h"
#include "GameMain.h"

Title::Title()
{
	//���j���[�J�[�\���摜�f�[�^�̓ǂݍ���
	if (LoadDivGraph("images/Title/Title_CursorAnimation.png", 4, 4, 1, 64, 64, T_CursorImg)) {}

	if ((g_TitleImage1 = LoadGraph("images/Title/Title_Logo.png"))){}
	if ((g_TitleImage2 = LoadGraph("images/Title/Title_ModeSelect.png"))){}
	if ((g_TitleImage3 = LoadGraph("images/Title/Title_Credit.png"))){}

	T_FPS = 0;
	T_Seconas1 = 0;

	i = 0;
	x = 0;
    y = 0;

}

Title::~Title()
{

}

//���͑�������
AbstractScene* Title::Update()
{
	if (CheckHitKey(KEY_INPUT_0) || PAD_INPUT::OnButton(XINPUT_BUTTON_START) == 1) {
		return new GameMain();
	}

	//60fps == 1�b�@�Œ������� fps�� 0 �ɂ���
	if (T_FPS > 60) {
		T_FPS = 0;
		T_Seconas1++;
	}// P_FPS_INC �� �b��������Ă���
	else if (T_Seconas1 > 3) {
		T_Seconas1 = 0;
	}

	return this;
}

int Title::Cursor_Anim()
{
	int C_AnimImg = 0;

	// 0 ���� 3 �b
	if (T_Seconas1 == 0) {
		C_AnimImg = T_CursorImg[STAND_BY_BALLOON2_0];
	}
	else if (T_Seconas1 > 0 && T_Seconas1 < 2) {
		C_AnimImg = T_CursorImg[STAND_BY_BALLOON2_1];
	}
	else if (T_Seconas1 > 1 && T_Seconas1 < 3) {
		C_AnimImg = T_CursorImg[STAND_BY_BALLOON2_2];
	}
	else if (T_Seconas1 > 2 && T_Seconas1 < 4) {
		C_AnimImg = T_CursorImg[STAND_BY_BALLOON2_3];
	}

	return C_AnimImg;
}

void Title::Draw()const
{
	//���j���[�J�[�\���i���D�j�̕\��
	DrawGraph(100, 200, T_CursorImg[i], TRUE);

	DrawGraph(25, 0, g_TitleImage1, TRUE);
	DrawGraph(150, 300, g_TitleImage2, TRUE);
	DrawGraph(150, 450, g_TitleImage3, TRUE);

	
}
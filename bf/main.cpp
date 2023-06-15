#include "DxLib.h"
#include "FPS.h"
#include"SceneManager.h"
#include"AbstractScene.h"
#include"PadInput.h"
#include"FPS.h"
#define FRAMERATE 60.0 //�t���[�����[�g

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	Fps fps;
	SetMainWindowText("BAROON FIGHT");
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)  return -1; // DX���C�u��������������
	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���
	DrawPixel(320, 240, GetColor(255, 255, 255)); // �_��ł�
	WaitKey(); // �L�[���͑҂�
	SceneManager* sceneMng;
	DxLib_End(); // DX���C�u�����g�p�̏I������
	return 0; // �\�t�g�̏I��

	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr))
	{

		ClearDrawScreen();		// ��ʂ̏�����
		PAD_INPUT::UpdateKey();
		sceneMng->Draw();
		//�����I��
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}
		fps.Update();	//�X�V
		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
		fps.Wait();		//�ҋ@
	}
	return 0;
}
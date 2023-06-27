#include "DxLib.h"
#include "FPS.h"
#include "SceneManager.h"
#include "AbstractScene.h"
#include "PadInput.h"
#include "TitleScene.h"

#define FRAMERATE 60.0 //�t���[�����[�g

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	//�^�C�g����
	SetMainWindowText("BAROON FIGHT");

	//�E�C���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//��ʃT�C�Y�w��
	if(SetGraphMode(640, 480, 32) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// DX���C�u��������������
	if (DxLib_Init() == -1) 
	{
		return -1;
	}
		
	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new Title()));;
	Fps fps;

	while ((ProcessMessage() == 0) && (sceneMng.Update() != nullptr))
	{

		ClearDrawScreen();		// ��ʂ̏�����
		PAD_INPUT::UpdateKey();
		sceneMng.Draw();

		//�����I��
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}

		//fps
		fps.Update();	//�X�V

		fps.Draw();
		ScreenFlip();	// ����ʂ̓��e��\��ʂɔ��f

		fps.Wait();		//�ҋ@
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End(); 

	return 0;
}
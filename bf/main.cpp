#include "DxLib.h"
#include "FPS.h"
#include "SceneManager.h"
#include "AbstractScene.h"
#include "PadInput.h"
#include "TitleScene.h"

#define FRAMERATE 60.0 //フレームレート

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	//タイトル名
	SetMainWindowText("BAROON FIGHT");

	//ウインドウモードで起動
	ChangeWindowMode(TRUE);

	//画面サイズ指定
	if(SetGraphMode(640, 480, 32) != DX_CHANGESCREEN_OK)
	{
		return -1;
	}

	// DXライブラリ初期化処理
	if (DxLib_Init() == -1) 
	{
		return -1;
	}
		
	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SceneManager sceneMng(dynamic_cast<AbstractScene*>(new Title()));;
	Fps fps;

	while ((ProcessMessage() == 0) && (sceneMng.Update() != nullptr))
	{

		ClearDrawScreen();		// 画面の初期化
		PAD_INPUT::UpdateKey();
		sceneMng.Draw();

		//強制終了
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}

		//fps
		fps.Update();	//更新

		fps.Draw();
		ScreenFlip();	// 裏画面の内容を表画面に反映

		fps.Wait();		//待機
	}

	// DXライブラリ使用の終了処理
	DxLib_End(); 

	return 0;
}
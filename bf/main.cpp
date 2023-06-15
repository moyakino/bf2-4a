#include "DxLib.h"
#include "FPS.h"
#include"SceneManager.h"
#include"AbstractScene.h"
#include"PadInput.h"
#include"FPS.h"
#define FRAMERATE 60.0 //フレームレート

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	Fps fps;
	SetMainWindowText("BAROON FIGHT");
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)  return -1; // DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする
	DrawPixel(320, 240, GetColor(255, 255, 255)); // 点を打つ
	WaitKey(); // キー入力待ち
	SceneManager* sceneMng;
	DxLib_End(); // DXライブラリ使用の終了処理
	return 0; // ソフトの終了

	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr))
	{

		ClearDrawScreen();		// 画面の初期化
		PAD_INPUT::UpdateKey();
		sceneMng->Draw();
		//強制終了
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}
		fps.Update();	//更新
		ScreenFlip();			// 裏画面の内容を表画面に反映
		fps.Wait();		//待機
	}
	return 0;
}
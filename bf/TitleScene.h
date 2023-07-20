#pragma once
#include "AbstractScene.h"

//風船カーソルアニメーション
#define CURSOR_BALLOON2_0 0
#define CURSOR_BALLOON2_1 1
#define CURSOR_BALLOON2_2 2
#define CURSOR_BALLOON2_3 3

class Title :public AbstractScene
{
private:

	//風船カーソル画像 分割読み込み用変数
	int	T_CursorImg[4];
	int i;
	int x, y;

	int g_TitleImage1;
	int g_TitleImage2;
	int g_TitleImage3;

	//FPSと秒数カウント
	int	T_FPS;
	int	T_Seconas1;

public:
	
	//コンストラクタ
	Title();

	//デストラクタ
	virtual ~Title();

	//描画以外の更新を実装する
	virtual AbstractScene* Update()override;

	//描画に関することを実装する
	virtual void Draw() const override;

	int Cursor_Anim();

};
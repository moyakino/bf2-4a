#pragma once
#include "DxLib.h"
class Stage2
{
private:
	float sx1, sx2;
	float sy1, sy2;

public:
	//コンストラクタ
	Stage2();

	//デストラクタ
	~Stage2();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;
};


#pragma once

#define GREEN_FOOT_WIDTH_1 280
#define GREEN_FOOT_HEIGHT_1 17

class Stage1
{
private:
	int x1, x2;
	int y1, y2;

	float	px1, py1, px2, py2, p_uc;
	int Bound;

public:
	//コンストラクタ
	Stage1();

	//デストラクタ
	~Stage1();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;

	int HitBox();

};


#pragma once



class Stage1
{
private:
	float sx1, sx2;
	float sy1, sy2;

	float	px1, py1, px2, py2;

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


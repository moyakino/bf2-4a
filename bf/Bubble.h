#pragma once
class Bubble{



private:
	int BubbleImg;
	int x;
	int y;


public:
	Bubble();

	//デストラクタ
	~Bubble() { };

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;
};

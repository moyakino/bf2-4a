#pragma once
class Stage
{
private:
	int StageFoot[8];
	int StageLand_R;
	int StageLand_L;
	int StageSea;


	int StageSample1;
	int StageSample2;
	int StageSample3;
	int StageSample4;
	int StageSample5;


	int X_Btn;

	int Snum;

	int sFps;

public:
	//コンストラクタ
	Stage();

	//デストラクタ
	~Stage();

	//描画以外の更新を実装する
	void Update();

	//描画処理
	void Draw() const;

};
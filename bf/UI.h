#pragma once
#define R_Cnt 30

class UI {
private:
	int Number[10];			//スコア用配列
	int NowScore;			//現在の合計スコア画像用変数
	int HiScore;			//HiScore画像用変数
	int Stock1;				//残機画像用変数
	int Stock2;				//残機が1つ減少すると描画一つ分をこの変数に切り替える
	int Phase;
	int gScore;
	int GameOver;			//GameOver画像用変数
	int TotalScore;
	int PosX;
	int Respawn_Cnt;		//残機の描画のカウント
	int Remaining_lives;	//Playerが死んだかどうかを返す
	int Fish_PlayerHit;		//Playerが魚に当たり、死んだかどうかを返す
	int GameOver_Flg;		//GameOverならTRUE
	
public:	

	UI();
	~UI();
	void Update(int Player_zanki, int Fish_Death);
	void Draw()const;
	int GetGameOver()const;

};
#pragma once
#define R_Cnt 30

class UI {
private:
	int Number[10];
	int Score;
	int HiScore;
	int Stock1;
	int Stock2;
	int Phase;
	int gScore;
	int GameOver;
	int TotalScore;
	int PosX;
	int Cnt;
	int Respawn_Cnt;
	int Beaten_Cnt;
	int fpsCnt;
	int byou;
	int Test;
	int GameOver_Flg;
	
public:	

	UI();
	~UI();
	void Update(int Player_zanki, int Fish_Death);
	void Draw()const;
	int GetGameOver()const;

};
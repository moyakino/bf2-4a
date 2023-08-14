#pragma once
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
	int fpsCnt;
	int byou;
	int GameOver_Flg;
public:	

	UI();
	~UI();
	void Update();
	void Draw()const;
	int GetGameOver()const;

};
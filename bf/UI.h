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
	/*int GameOver_BGM;*/
public:	
	static int GameOver_BGM;
	UI();
	~UI();
	void Update();
	void Draw()const;
	int GetGameOver()const;

};
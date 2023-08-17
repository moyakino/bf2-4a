#pragma once
#define R_Cnt 30

class UI {
private:
	int Number[10];
	int Score;
	int HiScore; // ‰æ‘œ—p•Ï”
	int HighScore; //ˆ——p•Ï”
	int H_Score;
	int T_Score;
	int Stock1;
	int Stock2;
	int Phase;
	int gScore1;
	int gScore10;
	int gScore100;
	int gScore1000;
	int gScore10000;
	int gScore100000;
	int GameOver;
	int Respawn_Cnt;
	int GameOver_Flg;
	int Score1, Score10, Score100, Score1000, Score10000, Score100000;
	int HiScore1, HiScore10, HiScore100, HiScore1000, HiScore10000, HiScore100000;
	int HighScore1, HighScore10, HighScore100, HighScore1000, HighScore10000, HighScore100000;
	int Remaining_lives;
	int Fish_PlayerHit;

public:	
	static int TotalScore;
	static int Stage;
	static int i;
	UI();
	~UI();
	void Update(int life, int Fish_Death);
	void Draw()const;
	int GetGameOver()const;

	void NowScore()const;

};
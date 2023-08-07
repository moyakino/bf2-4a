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
	int TempScore;
	int PosX;
	int Cnt;
public:
	UI();
	~UI();
	void Update();
	void Draw()const;

};
#pragma once
class UI {
private:
	int Number[9];
	int Score;
	int HiScore;
	int Stock1;
	int Stock2;
	int Phase;
	int gScore;
	int GameOver;
public:
	UI();
	~UI();
	void Update();
	void Draw()const;

};
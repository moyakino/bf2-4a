#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Bubble.h"
#include "Stage.h"
#include "Thunder.h"
#include "Fish.h"
#include "enemybird.h"
#include "UI.h"



class GameMain:
	public AbstractScene
{
private:

	int fps;
	int Cnt;
	int DrawGameOver;

	/*int MainBgm;*/
	int StageSea;
	int StageImg;
	void CreateStage();
	
	//bool PauseFlashFlg;
	//int PauseFlashTime;
public:
	static bool PauseFlg;
	static int MainBgm;
	int Snum;

	Stage* StageFoot[11];
	EnemyBird* Enemy[10];

	GameMain();
	~GameMain();
	void Draw()const;
	virtual AbstractScene* Update()override;
	
	EnemyBird* enemybird;

	PLAYER* player;
	Bubble* bubble;
	Stage* stage;
	Thunder* thunder;
	Fish* fish;
	UI* ui;
};

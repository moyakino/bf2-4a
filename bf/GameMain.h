#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include"Bubble.h"
#include "Stage.h"
#include "Thunder.h"
#include "Fish.h"
#include "enemybird.h"
#include"UI.h"
#include "testPlayer.h"

class GameMain:
	public AbstractScene
{
private:

	int Bgm;
	int StageSample;

public:
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

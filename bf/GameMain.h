#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "EnemyBird.h"
#include"Bubble.h"
#include "Stage.h"
#include "Fish.h"

class GameMain:
	public AbstractScene
{
private:
	

	int Bgm;
public:
	GameMain();
	~GameMain();
	void Draw()const;
	virtual AbstractScene* Update()override;

	PLAYER* player;
	EnemyBird* enemybird;
	Bubble* bubble;
	Stage* stage;
	Fish* fish;
};

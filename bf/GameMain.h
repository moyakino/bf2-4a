#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include"Bubble.h"
#include "Stage.h"

#include "testPlayer.h"

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
	Bubble* bubble;
	Stage* stage;

	//
	testPlayer* testP;
};

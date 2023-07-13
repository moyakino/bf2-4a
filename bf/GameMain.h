#pragma once
#include "AbstractScene.h"
#include "Player.h"

class GameMain:
	public AbstractScene
{
private:
	int StageFoot[8];
	int StageLand_R;
	int StageLand_L;
	int StageSea;

	int StageSample;
	
public:
	GameMain();
	~GameMain();
	void Draw()const;
	virtual AbstractScene* Update()override;

	PLAYER* player;
};

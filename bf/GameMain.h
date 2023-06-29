#pragma once
#include "AbstractScene.h"
#include "Player.h"

class GameMain:
	public AbstractScene
{
private:
	
public:
	
	GameMain();

	~GameMain() {};

	virtual AbstractScene* Update()override;

	void Draw()const;

	Player* player;
};

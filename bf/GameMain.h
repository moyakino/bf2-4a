#pragma once
#include "AbstractScene.h"
#include"DxLib.h"
class GameMain:
	public AbstractScene
{
private:
	
public:
	void Draw()const;
	virtual AbstractScene* Update()override;


};

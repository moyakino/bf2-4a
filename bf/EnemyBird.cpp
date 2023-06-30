#include "EnemyBird.h"
#include"DxLib.h"
#include"GameMain.h"


EnemyBird::EnemyBird()
{
}

EnemyBird::~EnemyBird()
{
}

void EnemyBird::Update()
{
	
}

void EnemyBird::Draw() const
{
	DrawFormatString(10, 10, 0xffffff, "Åú", TRUE);
}

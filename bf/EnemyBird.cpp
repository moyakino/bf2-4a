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

bool EnemyBird::Damage(int damage) {
	//PlaySoundMem(HitSE, DX_PLAYTYPE_BACK);
	hp -= damage;
	return hp <= 0;
}

bool EnemyBird::Attack() {
	if (y > 640 && !isAttack) {
		isAttack = true;
		return true;
	}

	return false;
}

void EnemyBird::Draw() const
{
	DrawFormatString(10, 10, 0xffffff, "Åú", TRUE);
}

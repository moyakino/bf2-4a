#include "EnemyBird.h"
#include"DxLib.h"
#include"GameMain.h"


EnemyBird::EnemyBird()
{}

			EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update()
{
	//Player  X座標用変数
	float	E_Move_X;
	//Player  Y座標用変数
	float	E_Move_Y;
	
}

//bool EnemyBird::Damage(int damage) {
//	//PlaySoundMem(HitSE, DX_PLAYTYPE_BACK);
//	hp -= damage;
//	return hp <= 0;
//}
//
//bool EnemyBird::Attack() {
//	if (y > 640 && !isAttack) {
//		isAttack = true;
//		return true;
//	}
//
//	return false;
//}

void EnemyBird::Draw() const
{
	DrawFormatString(10, 10, 0xffffff, "●", TRUE);
}


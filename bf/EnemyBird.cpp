#include "EnemyBird.h"
#include"DxLib.h"
#include"GameMain.h"


EnemyBird::EnemyBird()
{
	if (LoadDivGraph("images/Enemy/Enemy_P_Animation.png", 18, 6, 3, 64, 64,E_ArrayImg)) {}
	if (LoadDivGraph("images/Enemy/Enemy_G_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg)) {}
	if (LoadDivGraph("images/Enemy/Enemy_R_Animation.png", 18, 6, 3, 64, 64, E_ArrayImg)) {}
  
}

EnemyBird::~EnemyBird()
{

}

void EnemyBird::Update()
{
	//Player  X���W�p�ϐ�
	float	E_Move_X;
	//Player  Y���W�p�ϐ�
	float	E_Move_Y;
	
}

void EnemyBird::Draw() const
{
	//DrawFormatString(10, 10, 0xffffff, "��", TRUE);
	////�v���C���[�̓����蔻��
	//DrawBox(P_Move_X + 20, P_Move_Y + 37, P_Move_X + 47, P_Move_Y + 65, GetColor(255, 255, 255), FALSE);

	////���D�̓����蔻��
	//DrawBox(P_Move_X + 5, P_Move_Y + 10, P_Move_X + 59, P_Move_Y + 37, GetColor(255, 255, 255), FALSE);
}


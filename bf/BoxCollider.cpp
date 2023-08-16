#include "BoxCollider.h"
#include "Player.h"

bool BoxCollider::HitCollider(BoxCollider* b_col)
{
	int re = false;

	//プレイヤー 敵
	float px1 = b_col->GetLocation().x +15;
	float py1 = b_col->GetLocation().y +15;
	float px2 = px1 + b_col->GetErea().Width;
	float py2 = py1 + b_col->GetErea().Height;

	//ステージ
	float sx1 = location.x;
	float sx2 = location.x + erea.Width;
	float sy1 = location.y;
	float sy2 = location.y + erea.Height;

	//当たり判定
	if ((sx1 < px2) && (px1 < sx2) && (sy1 < py2) && (sy2 > py1))
	{
		re = true;
	}
	
	//ステージ
	stage_x1 = sx1;
	box_x1 = px1;

	stage_x2 = sx2;
	box_x2 = px2;

	stage_y = sy1;
	box_y = py2;

	return re;
}

bool BoxCollider::TopBoxCollider(BoxCollider* b_col)
{
	int re = false;

	if (static_cast<int>(stage_y) ==  static_cast<int>(box_y)) 
	{
		re = true;
	}


	return re;
}

bool BoxCollider::L_SideBoxCollider(BoxCollider* b_col)
{
	int re = false;

	if (static_cast<int>(stage_x1) == static_cast<int>(box_x2)) 
	{
		re = true;
	}

	return re;
}

bool BoxCollider::R_SideBoxCollider(BoxCollider* b_col)
{
	int re = false;

	if (static_cast<int>(stage_x2) == static_cast<int>(box_x1))
	{
		re = true;
	}

	return re;
}

//int BoxCollider::BubbleHit(BoxCollider* bubble) {
//
//	bool Hit = false;
//
//	float px1 = PLAYER::P_Move_X;
//	float px2 = PLAYER::P_Move_X + 64;
//	/*float py1 = PLAYER::P_Move_Y;*/
//	float py2 = PLAYER::P_Move_Y + 64;
//
//	float p_uc = (px1 + px2) / 2;
//}

Location BoxCollider::GetLocation()
{
	return location;
}

Erea BoxCollider::GetErea()
{
	return erea;
}

void BoxCollider::SetLocation(Location location)
{
	this->location = location;
}


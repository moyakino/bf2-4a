#include "BoxCollider.h"
#include "Player.h"

int BoxCollider::HitCollider(BoxCollider* b_col)
{
	int re = false;

	//プレイヤー
	float px1 = b_col->GetLocation().x + 17;
	float px2 = b_col->GetLocation().x + 48;
	float py1 = b_col->GetLocation().y + 37;
	float py2 = b_col->GetLocation().y + 65;

	//ステージ
	float sx1 = location.x;
	float sx2 = location.x + erea.Width;
	float sy1 = location.y;
	float sy2 = location.y + erea.Height;

	//空中足場
	if ((sx1 < px2) && (sx2 > px1) && (sy1 < py2) && (sy2 > py1))
	{
		re = true;
	}
	
	//ステージ
	stage_x1 = sx1;
	stage_x2 = sx2;

	stage_y = sy1;

	box_x1 = px1;
	box_x2 = px2;

	box_y = py2;

	return re;
}

int BoxCollider::TopBoxCollider(BoxCollider* b_col)
{
	int re = false;

	if (static_cast<int>(stage_y) ==  static_cast<int>(box_y)) 
	{
		re = true;
	}

	return re;
}

int BoxCollider::L_SideBoxCollider(BoxCollider* b_col)
{
	int re = false;

	if (static_cast<int>(stage_x1) == static_cast<int>(box_x1)) 
	{
		re = true;
	}

	return re;
}

int BoxCollider::R_SideBoxCollider(BoxCollider* b_col)
{
	int re = false;

	if (static_cast<int>(stage_x2) == static_cast<int>(box_x2))
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


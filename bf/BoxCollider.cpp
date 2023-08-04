#include "BoxCollider.h"

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

	return re;
}

int BoxCollider::TopBoxCollider()
{
	int re = false;



	return re;
}

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


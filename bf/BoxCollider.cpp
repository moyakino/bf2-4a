#include "BoxCollider.h"

int BoxCollider::HitCollider(BoxCollider* b_col)
{
	int re = false;

	//ƒvƒŒƒCƒ„[
	float px1 = b_col->GetLocation().x + 17;
	float px2 = b_col->GetLocation().x + 48;
	float py1 = b_col->GetLocation().y + 37;
	float py2 = b_col->GetLocation().y + 65;

	//“G
	float ex1 = 0;
	float ex2 = 0;
	float ey1 = 0;
	float ey2 = 0;

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


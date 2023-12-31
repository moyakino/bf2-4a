#pragma once

struct Location
{
	float x;
	float y;
};

struct Erea
{
	float Height;
	float Width;
};

class BoxCollider
{
protected:
	Location location;
	Erea erea;

public:

	float stage_y;
	float box_y;

	float stage_x1;
	float stage_x2;

	float box_x1;
	float box_x2;

	//Boxに当たっているかどうか判定する
	bool HitCollider(BoxCollider* b_col);

	//Boxの上に立っているかどうかを判定する
	bool TopBoxCollider(BoxCollider* b_col);

	int BubbleHit(BoxCollider* bubble);

	Location GetLocation();
	Erea GetErea();

	void SetLocation(Location location);

};


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

	int HitCollider(BoxCollider* b_col);
	int TopBoxCollider(BoxCollider* b_col);
	int L_SideBoxCollider(BoxCollider* b_col);
	int R_SideBoxCollider(BoxCollider* b_col);

	int BubbleHit(BoxCollider* bubble);

	Location GetLocation();
	Erea GetErea();

	void SetLocation(Location location);

};


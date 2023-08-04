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

	int HitCollider(BoxCollider* b_col);
	int TopBoxCollider();

	Location GetLocation();
	Erea GetErea();

	void SetLocation(Location location);

};


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

	//Box�ɓ������Ă��邩�ǂ������肷��
	bool HitCollider(BoxCollider* b_col);

	//Box�̏�ɗ����Ă��邩�ǂ����𔻒肷��
	bool TopBoxCollider(BoxCollider* b_col);


	Location GetLocation();
	Erea GetErea();

	void SetLocation(Location location);

};


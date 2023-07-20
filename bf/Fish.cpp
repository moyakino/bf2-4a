#include "Fish.h"
#include"DxLib.h"
#include"GameMain.h"

Fish::Fish()
{
	if (LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, Fish_ArrayImg)) {}
}

Fish::~Fish()
{

}

void Fish::Update()
{

}

void Fish::Draw() const
{
	//DrawGraph(300, 700, Fish_ArrayImg[i], TRUE);
}

//int Fish::Fish_Anim()
//{
//
//	return 0;
//}

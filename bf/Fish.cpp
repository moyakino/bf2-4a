#include "Fish.h"
#include"DxLib.h"
#include"GameMain.h"

Fish::Fish()
{
	if (LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, Fish_ArrayImg)) {}
	Fish_Img = Fish_ArrayImg[0];
}

Fish::~Fish()
{

}

void Fish::Update()
{

}

void Fish::Draw() const
{
	DrawRotaGraph(300,410, 1.0f, 0, Fish_Img, TRUE);
	/*DrawGraph(300, 700, Fish_Img, TRUE);*/
}

//int Fish::Fish_Anim()
//{
//
//	return 0;
//}

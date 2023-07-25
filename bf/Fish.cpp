#include "Fish.h"
#include"DxLib.h"
#include"GameMain.h"

Fish::Fish()
{
    f_fps = 0;
    F_Seconas1 = 0;

	if (LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, Fish_ArrayImg)) {}
}

Fish::~Fish()
{

}

void Fish::Update()
{
    f_fps++;

    if (f_fps > 59) {
        f_fps = 0;
        F_Seconas1++;

    }
    if (F_Seconas1 > 5) {
        F_Seconas1 = 0;
    }
}

int Fish::Fish_Anim()
{


    switch (F_Seconas1)
    {
    case 0:
        F_AnimImg = Fish_ArrayImg[FISH_0];
        break;
    case 1:
        F_AnimImg = Fish_ArrayImg[FISH_1];
        break;
    case 2:
        F_AnimImg = Fish_ArrayImg[FISH_2];
        break;
    case 3:
        F_AnimImg = Fish_ArrayImg[FISH_3];
        break;
    case 4:
        F_AnimImg = Fish_ArrayImg[FISH_4];
        break;
    case 5:
        F_AnimImg = Fish_ArrayImg[FISH_5];
    }
    return F_AnimImg;
}
void Fish::Draw() const
{
    DrawFormatString(0, 20, 0xffffff, "Second:%d", F_Seconas1);
    DrawFormatString(100, 400, 0xffffff, "f_fps:%d", f_fps);
	DrawRotaGraph(300,410, 1.0f, 0, F_AnimImg, TRUE);
	/*DrawGraph(300, 410, Fish_Img, TRUE);*/
}


    //// 0 ���� 3 �b
    //if (F_Seconas1 == 0) {
    //    F_AnimImg = Fish_ArrayImg[FISH_0];
    //}
    //else if (F_Seconas1 > 0 && F_Seconas1 < 2) {
    //    F_AnimImg = Fish_ArrayImg[FISH_1];
    //}
    //else if (F_Seconas1 > 1 && F_Seconas1 < 3) {
    //    F_AnimImg = Fish_ArrayImg[FISH_2];
    //}
    //else if (F_Seconas1 > 2 && F_Seconas1 < 4) {
    //    F_AnimImg = Fish_ArrayImg[FISH_3];
    //}
    //else if (F_Seconas1 > 3 && F_Seconas1 < 5) {
    //    F_AnimImg = Fish_ArrayImg[FISH_4];
    //}

   

#include "Fish.h"
#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"


Fish::Fish()
{
    
    PlayerX = 0;
    PlayerY = 0;


    f_fps = 0;
    F_Seconas2 = 0;

	if (LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, Fish_ArrayImg)) {}
    ChengeImg = 0;

    
}


Fish::~Fish()
{
    
}

void Fish::Update(int x,int y)
{
    f_fps++;
    PlayerX =x;
    PlayerY = y;
    if (f_fps > 20) {
      /*  F_Seconas2++;*/
        f_fps = 0;
        //魚のアニメーション
        if (PLAYER::FishFlg == TRUE) {
         //   /* if (f_fps / 1==0) {*/
         //    if (f_fps % 10 == 0 || f_fps % 10 == 1 || f_fps % 10 == 2 || f_fps % 10 == 3 || f_fps % 10 == 4 || f_fps % 10 ==5) {
            if (F_Seconas2++) {
                ChengeImg++;
                if (ChengeImg > 5) {
                    ChengeImg = 0;
                    PLAYER::FishFlg = FALSE;
                }
            }
           /* }*/
        }
    }
}
   
void Fish::Draw() const
{
    DrawFormatString(0, 20, 0xffffff, "Second:%d", F_Seconas2);
    if (PLAYER::FishFlg == TRUE) 
    {
        if (PLAYER::F_TurnFlg == TRUE)
        {
            /*DrawRotaGraph(PlayerX + 30, PlayerY+30, 1.0f, 0, Fish_ArrayImg[ChengeImg], TRUE);*/
            DrawGraph(PlayerX , 390, Fish_ArrayImg[ChengeImg], TRUE);
        }
        else {
            if (PLAYER::F_TurnFlg == FALSE) {
                DrawTurnGraph(PlayerX , 390, Fish_ArrayImg[ChengeImg], TRUE);
            }
        }
       /* if (PLAYER::F_TurnFlg == FALSE)
        {
            DrawTurnGraph(PlayerX - 30, PlayerY + 30, Fish_ArrayImg[ChengeImg], TRUE);*/
            /*DrawTurnGraph(PlayerX - 30, 420, Fish_ArrayImg[ChengeImg], TRUE);*/
       /* }*/
    }
    /*DrawRotaGraph(300,410, 1.0f, 0, F_AnimImg, TRUE);*/
    /*DrawGraph(300, 410, Fish_Img, TRUE410);*/
   /* DrawGraph(300, 410, Fish_Img, TRUE);*/
   

}
    //if (PLAYER::FishFlg == TRUE)
    //{
    //    //Fish_Img = Fish_Anim();

    //   
    //}


//int Fish::Fish_Anim()
//{ 
    /*if (f_fps % 20 == 0) {

        F_Seconas1++;*/

        /*if (F_Seconas1 > 5) {
            F_Seconas1 = 0;
        }*/
    //}


   /* switch (F_Seconas1)
    {
    case 0:
        F_AnimImg = Fish_ArrayImg[0];
        break;
    case 1:
        F_AnimImg = Fish_ArrayImg[1];
        break;
    case 2:
        F_AnimImg = Fish_ArrayImg[2];
        break;
    case 3:
        F_AnimImg = Fish_ArrayImg[3];
        break;
    case 4:
        F_AnimImg = Fish_ArrayImg[4];
        break;
    case 5:
        F_AnimImg = Fish_ArrayImg[5];
//        break;
//    
//    }*/
//
//    return F_AnimImg;
//
//}



    //// 0 から 3 秒
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

   

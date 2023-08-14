#include "Fish.h"
#include"DxLib.h"
#include"GameMain.h"
#include "Player.h"

int Fish::FishEatP_flg;
int Fish::F_Seconds2;
Fish::Fish()
{
    i = 0;
    PlayerX = 0;
    PlayerY = 0;
    fx1 = 0;
    fy1 = 0;
    fx2 = 0;
    fy2 = 0;
    Fish_Img = 0;
    f_fps = 0;
    F_Seconds2 = 0;
    FishEatP_flg = 0;
	if (LoadDivGraph("images/Enemy/Enemy_FishAnimation.png", 10, 5, 2, 64, 64, Fish_ArrayImg)) {}
    ChengeImg = 0;
    FishEatP_flg = FALSE;
   
}


Fish::~Fish()
{
    
}

void Fish::Fish_NAnim()
{
    
}

void Fish::Update(int x,int y)
{
    f_fps++;
    PlayerX =x;
    PlayerY = y;
    fx1 = x;
    fy1 = y;
    fx2 = x+55;
    fy2 = y+50;
    if (f_fps > 15) {
        f_fps = 0;
        //���̃A�j���[�V����
        if (PLAYER::FishFlg == TRUE) {
            {
                //�����蔻��
                if (PlayerX >= fx1 && PlayerX < fx2 && PlayerY>380 && PlayerY < 500) {
                    FishEatP_flg = TRUE;
                }
                else if (PlayerX <= fx1 && PlayerX > fx2 && PlayerY < 380 && PlayerY > 500) {
                    FishEatP_flg = FALSE;
                }

                //�����H���Ȃ�������
                if (FishEatP_flg == FALSE) {

                    if (F_Seconds2 == 0) {
                        Fish_Img = 0;
                    }
                    else if (F_Seconds2 == 1) {
                        Fish_Img = 1;
                    }
                    else if (F_Seconds2 == 2) {
                        Fish_Img = 2;
                    }
                    else if (F_Seconds2 == 3) {
                        Fish_Img = 3;
                    }
                    else if (F_Seconds2 == 4) {
                        Fish_Img = 4;
                    }
                    else if (F_Seconds2 == 5) {
                        Fish_Img = 5;
                    }
                    else if (F_Seconds2 == 6) {
                        F_Seconds2 = 7;
                        Fish_Img = 0;
                    }
                }
                //player�ߐH
                if (FishEatP_flg == TRUE) {

                    if (F_Seconds2 == 0) {
                        Fish_Img = 0;
                    }
                    else if (F_Seconds2 == 1) {
                        Fish_Img = 1;
                    }
                    else if (F_Seconds2 == 2) {
                        Fish_Img = 2;
                    }
                    else if (F_Seconds2 == 3) {
                        Fish_Img = 6;
                    }
                    else if (F_Seconds2 == 4) {
                        Fish_Img = 3;
                    }
                    else if (F_Seconds2 == 5) {
                        Fish_Img = 4;
                    }
                    else if (F_Seconds2 == 6) {
                        Fish_Img = 5;
                    }
                    else if (F_Seconds2 == 7) {
                        FishEatP_flg = FALSE;
                        Fish_Img = 0;
                    }
                 
                }
                //�A�j���[�V�����p�b��
                F_Seconds2++;
                if (F_Seconds2 == 8) {
                    F_Seconds2 = 0;
                    PLAYER::FishFlg = FALSE;
                }
            }

        }
    }
    
}



void Fish::Draw() const
{
    //DrawFormatString(400, 20, 0xffffff, "F_Second2:%d", F_Seconds2);
    //DrawFormatString(400, 40, 0xffffff, "Fish_Img_:%d", Fish_Img);
    
   
    if (PLAYER::FishFlg == TRUE)
    {

        if (PLAYER::F_TurnFlg == TRUE)
        {
            DrawGraph(PlayerX, 390, Fish_ArrayImg[Fish_Img], TRUE);
            DrawBoxAA(fx1 , 410 , fx2, 500, GetColor(255, 255, 255), FALSE);
        }
        else {
            if (PLAYER::F_TurnFlg == FALSE) {
                DrawTurnGraph(PlayerX, 390, Fish_ArrayImg[Fish_Img], TRUE);
                DrawBoxAA(fx1, 410, fx2, 500, GetColor(255, 255, 255), FALSE);
            }
        }

    }

}







   

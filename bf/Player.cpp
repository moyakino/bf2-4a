#include "DxLib.h"
#include "FPS.h"
#include "Player.h"
#include "PadInput.h"

Fps fps;

Player::Player()
{
    //�v���C���[�摜�f�[�^�̓ǂݍ���
    if (LoadDivGraph("images/Player/Player_animation_d.png", 32, 8, 4, 64, 64, P_PlayerImg)){}
    //������
    P_Move_X = 100;
    P_Move_Y = 350.0;
    P_MoveR_Flg = FALSE;
    P_MoveL_Flg = FALSE;
    P_Air_Flg = FALSE;
    Trun_Flg = TRUE;
    P_Img = 0;
    P_FPS = 0;
    P_FPS_INC = 0;
    P_FPS_FLY = 0;
    P_AnimL_Flg = FALSE;
    P_AnimR_Flg = TRUE;
    P_Std_Anim_Flg = FALSE;
    P_Air_Multiply = 1.0;
}

void Player::Update()
{
    

    //�t���[���擾
    P_FPS++;

    //�ҋ@��
    if (P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE && P_Move_Y >= P_MOVE_Y) {
        P_Img = Player::Stand_by_Anim();
        /*if (P_FPS_INC < 11 && P_Anim_Flg == TRUE) {
            P_Anim_Flg = FALSE;
        }*/
    }
    /*else
    {
        P_MoveR_Flg = FALSE;
        P_MoveL_Flg = FALSE;
    }*/

    //�E�ړ�
    if (32768 > PAD_INPUT::GetLStickX() && PAD_INPUT::GetLStickX() > 128 && P_Air_Flg == FALSE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT) == 1)  {
        P_Move_X += 2;
        P_Img = Player::Running_Anim();
        P_MoveR_Flg = TRUE;
        P_AnimR_Flg = TRUE;
        P_AnimL_Flg = FALSE;
    }else {	//���� else �͑ҋ@���̃A�j���[�V�����摜�ɖ߂�
        P_MoveR_Flg = FALSE;
        //P_Img = Player::Stand_by_Anim(P_MoveR_Flg, P_MoveL_Flg);
    }

    //XINPUT_BUTTON_DPAD_LEFT

    //���ړ�
    if (-32769 < PAD_INPUT::GetLStickX() && PAD_INPUT::GetLStickX() < 128 && P_Air_Flg == FALSE || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT) == 1) {
        P_Move_X -= 2;
        P_Img = Player::Running_Anim();
        P_MoveL_Flg = TRUE;
        P_AnimL_Flg = TRUE;
        P_AnimR_Flg = FALSE;
    }else {
        P_MoveL_Flg = FALSE;
        //P_Img = Player::Stand_by_Anim(P_MoveR_Flg, P_MoveL_Flg);
    }

    //����
    if (PAD_INPUT::OnButton(XINPUT_BUTTON_A) == 1) {
        //���t���[���̃C���^�[�o��
       if (P_FPS % 2 == 0) {
            P_Move_Y -= (10 * P_Air_Multiply);
            P_Air_Multiply += 0.15;
            //P_Air_Flg = TRUE;
       }
    }
    else if (P_FPS_INC == 3) { //������ɍs�������x��߂��Ă���@3�b�Ɉ�x
        P_Air_Multiply = 1.0;
    }

    //��
    if (P_Move_Y < 350) {
        P_Img = Player::Fly_To_The_Sky_Anim_1();
    }

    // A�{�^����������Ă��Ȃ���  �Ɓ@L_Stick�������Ă��Ȃ��� Y���W 400�܂ō~��
    if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A) == 0 && P_Move_Y <= P_MOVE_Y) {
        P_Move_Y += 0.3;	//�d��
        P_Img = Player::Fly_To_The_Sky_Anim_2();
        P_Air_Flg = TRUE;
    }
    else {
        P_Air_Flg = FALSE;
    }

    //60fps == 1�b�@�Œ������� fps�� 0 �ɂ���
    if (P_FPS > 60) {
        P_FPS = 0;
        P_FPS_INC++;
        P_FPS_FLY++;
    }
    // P_FPS_INC �� �b��������Ă���
    else if (P_FPS_INC > 4) {
        P_FPS_INC = 0;
    }
    else if (P_FPS_FLY > 2) {
        P_FPS_FLY = 0;
    }

    if (P_Move_X <= 0 || P_Move_X > 640) {
        if (P_Move_X <= -32) {
            P_Move_X = 640;
            //P_Left = TRUE;

        }
        if (P_Move_X > 640) {
            P_Move_X = -32;
        }
        else{
            //P_Left = FALSE;
        }

    }

    if (P_Move_Y < -10) {
        P_Move_Y = -10;
    }
}

int Player::Stand_by_Anim()
{
    int S_AnimImg = 0;

    //�v���C���[�̉摜�̐؂�ւ��͕b���ɂ��Ă��� �t���[�����Ɠ_�ł���
    if (P_FPS_INC >= 0 && P_FPS_INC <= 1) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_1];
    }
    else if(P_FPS_INC > 1 && P_FPS_INC <= 2){
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_0];
    }
    else if (P_FPS_INC > 2 && P_FPS_INC <= 3 ) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_1];
    }
    else if (P_FPS_INC > 3 && P_FPS_INC <= 4) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_2];
    }

    return S_AnimImg;
}

int Player::Fly_To_The_Sky_Anim_1()
{
    int F_AnimImg = 0;

    /*if (P_FPS >= 0 && P_FPS < 12) {
        F_AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_0];
    }
    else if (P_FPS > 11 && P_FPS < 24) {
        F_AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_1];
    }
    else if (P_FPS > 23 && P_FPS < 36) {
        F_AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_2];
    }
    else if (P_FPS > 35 && P_FPS < 48) {
        F_AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_3];
    }
    else if (P_FPS > 47 && P_FPS <= 60) {
        F_AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_4];
    }*/

    if (P_FPS_FLY >= 0 && P_FPS_FLY < 1) {
        F_AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_1];
    }
    else if (P_FPS_FLY > 0 && P_FPS_FLY < 2) {
        F_AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_0];
    }

    return F_AnimImg;
}

int Player::Fly_To_The_Sky_Anim_2()
{
    int AnimImg = 0;

    if (P_FPS >= 0 && P_FPS < 20) {
        AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_2];
    }
    else if (P_FPS > 19 && P_FPS < 40) {
        AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_3];
    }
    else if (P_FPS > 39 && P_FPS < 60) {
        AnimImg = P_PlayerImg[P_FLY_TO_THE_SKY_ANIM_4];
    }

    return AnimImg;
}

int Player::Running_Anim()
{
    int R_AnimImg = 0;

    if (P_FPS >= 0 && P_FPS < 15) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_0];
        //P_Std_Anim_Flg = TRUE;
    }
    else if (P_FPS > 14 && P_FPS < 30) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_1];
        //P_Anim_Flg = TRUE;
    }
    else if (P_FPS > 29 && P_FPS < 45) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_2];
        //P_Anim_Flg = FALSE;
    }
    else if (P_FPS > 44 && P_FPS <= 60) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_3];
        //P_Anim_Flg = FALSE;
    }

    return R_AnimImg;
}

int Player::R_Player_MoveX()const
{
    return P_Move_X;
}

float Player::R_Player_MoveY()const
{
    return P_Move_Y;
}

Player::~Player()
{

}

void Player::Draw()const
{
    //A�{�^���`��
    DrawFormatString(0, 100, GetColor(255, 0, 0), " �����ꂽ�u�ԁF%d �����ꂽ�u�ԁF%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

    DrawFormatString(0, 150, GetColor(255, 0, 0), " ���X�e�B�b�N�FX���W %d Y���W %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

    DrawFormatString(0, 200, GetColor(255, 0, 0), " �ړ��t���O�F���ړ� %d �E�ړ� %d", P_MoveL_Flg, P_MoveR_Flg);

    DrawFormatString(300, 200, GetColor(255, 0, 0), " FPS�F%d P_FPS_INC %d", P_FPS, P_FPS_INC);


    DrawFormatString(0, 20, GetColor(255, 0, 0), "P_Move_X:%d", P_Move_X);
    //DrawRotaGraph(P_Move_X, P_Move_Y, 1, 0, P_PlayerImg[0], TRUE);

    //�ŏ��͉E�����ŕ`�悳���
    if (P_AnimR_Flg == TRUE) {
        DrawTurnGraph(P_Move_X, P_Move_Y, P_Img, TRUE);
    }
    else {
        DrawGraph(P_Move_X, P_Move_Y, P_Img, TRUE);
    }


    /*if (P_Left == TRUE) {
        DrawRectExtendGraph(610, P_Move_Y, 610+ 32, P_Move_Y + 64, 0, 0, 32, 64, P_Img, TRUE);
    }*/
    //DrawRectExtendGraph(P_Move_X, P_Move_Y, P_Move_X + 32, P_Move_Y + 64, 32, 0, 32, 64, P_Img, TRUE);

	//DrawRotaGraph(P_Move_X, P_Move_Y, 1, 0, P_PlayerImg[0], TRUE);

	DrawCircle(P_Move_X, P_Move_Y,2, GetColor(255, 255, 0), TRUE);
    //DrawGraph(P_Move_X, P_Move_Y, P_Img, TRUE);
}

#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"
#include "Stage.h"

int PLAYER::FishFlg;
int PLAYER::P_TurnFlg;

float PLAYER::p_uc;
float PLAYER::P_Move_X;
float PLAYER::P_Move_Y;
float PLAYER::px1;
float PLAYER::py1;
float PLAYER::px2;
float PLAYER::py2;
float PLAYER::py_u;
PLAYER::PLAYER()
{
    //�v���C���[�摜�f�[�^�̓ǂݍ���
    if (LoadDivGraph("images/Player/Player_Animation.png", 32, 8, 4, 64, 64, P_ArrayImg)){}
    P_Img = 0;
    P_L_Stick = 0;
    P_L_Stick_Flg = 0;
    P_Right_Btn = 0;
    P_Left_Btn = 0;
    P_A_Btn = 0;
    P_B_Btn = 0;
    P_Y_Btn = 0;

    location.x = 20.0f;
    location.y = 350.0f;
    //P_Move_Y = 200.0f;

    P_Move_X = location.x;
    P_Move_Y = location.y;

    //�n��̃X�s�[�h
    P_XSpeed = 0.0f;
    P_YSpeed = 0.0f;

    //�󒆂ł̃X�s�[�h
    P_AirSpeed = 0.0;

    P_Accele = 0.0f;
    P_Air_Multiply = 1.0f;

    P_MoveR_Flg = 0;
    P_MoveL_Flg = 0;
    P_Air_Flg = 0;
    P_Balloon_Flg = TRUE;
    P_TurnFlg = TRUE;
    P_A_BtnFlg = 0;
    P_Air_R_Flg = 0;
    P_Air_L_Flg = 0;
    P_FPS = 0;
    P_Seconas1 = 0;
    MouseX = 0;
    MouseY = 0;

    rand = 0;

    //������ԃt���O
    P_Stand_Flg = 0;
    //������ԃt���O
    P_Foll_Flg = 0;
    Beaten_Flg = FALSE;
    AnimCnt = 0;
    Respawn_Flg = TRUE;

    FishFlg = FALSE;
}

void PLAYER::Update()
{
    //�t���[���擾
    P_FPS++;

    //�}�E�X������W��ǂݎ��
    GetMousePoint(&MouseX, &MouseY);

    //���X�e�B�b�N
    P_L_Stick = PAD_INPUT::GetLStickX();

    //�f�W�^�������E�{�^��
    P_Right_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT);

    //�f�W�^���������{�^��
    P_Left_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT);

    // A�{�^���P����
    P_A_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_A);

    //Y�{�^���P����
    P_Y_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_Y);

    // B�{�^��������
    P_B_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_B);

    //���[�v�p
    Player_Warp();

    if (Respawn_Flg == TRUE) {
        Respawn_Anim();
    }

    if (P_Y_Btn == 1) {
        if (P_FPS % 2 == 0) {
            AnimCnt++;
        }
        if (AnimCnt > 2) {
            AnimCnt = 2;
        }
    }

    if (AnimCnt == 1) {
        P_Balloon_Flg = FALSE;
    }
    if (AnimCnt == 2) {
        Beaten_Flg = TRUE;
        AnimCnt = 0;
    }

    //�����Ă��邩�̔���
    Stand_Foot();

    //�摜�؂�ւ��p
    Player_Img();

    if (Beaten_Flg == FALSE) {

        if (P_A_Btn == 1) {
            Respawn_Flg = FALSE;
            Player_Air_A();

        }

        if (P_B_Btn == 1) {
            Respawn_Flg = FALSE;
            Player_Air_B();
        }

        if (P_Stand_Flg == FALSE) {
            Player_Levitation_Move();
        }

        if (P_Stand_Flg == FALSE && P_B_Btn == 0 || P_A_Btn == 0 ) {
            Player_Gravity();
        }
    }
    else {
        if (Beaten_Flg == TRUE) {
            if (location.y < 500.0f) {
                location.y = location.y + 1.0f;
                Beaten_Anim();
            }
            else {
                Beaten_Flg = FALSE;
                Player_Init();
            }
        }
    }

    //60fps == 1�b�@�Œ������� fps�� 0 �ɂ���
    if (P_FPS > 59) {
        P_FPS = 0;
        P_Seconas1++;

    }// P_FPS_INC �� �b��������Ă���
    else if (P_Seconas1 > 3) {
        P_Seconas1 = 0;
    }

}

void PLAYER::Player_Init()
{
    P_XSpeed = 0;
    P_YSpeed = 0;
    location.x = 20.0f;
    location.y = 350.0f;
    Respawn_Flg = TRUE;
    P_Balloon_Flg = TRUE;
}

void PLAYER::Player_Warp()
{
    //�����[�v
    if (location.x <= -52) {
        location.x = 640;
    }
    //�E���[�v
    else if (location.x >= 680) {
        location.x = -50;
    }

    //�V��
    /*if (P_Move_Y <= -25) {
        P_Move_Y = 250;
    }*/

    //�V��Œ��˕Ԃ�
    if (location.y <= -25) {
        location.y = -20;
        if (P_YSpeed < 0) {
            P_YSpeed = P_YSpeed * -0.8f;
        }
    }
    
}

void PLAYER::Player_Img()
{
    //�E�ړ��Ŕ��]�`��
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        Respawn_Flg = FALSE;
        P_TurnFlg = TRUE;
    }
    //���ړ��Œʏ�`��
    else if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        Respawn_Flg = FALSE;
        P_TurnFlg = FALSE;
    } 
}

void PLAYER::Player_Move()
{
    P_Stand_Flg = TRUE;
    P_YSpeed = 0.0f;

    //�E�ړ�
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        P_MoveR_Flg = TRUE;

        //�����x
        P_XSpeed = 1.0f;

        location.x = location.x + P_XSpeed;
        Run_Anim();
    }
    else {
        P_MoveR_Flg = FALSE;

    }

    //���ړ�
    if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        P_MoveL_Flg = TRUE;

        //�����x
        P_XSpeed = -1.0f;

        location.x = location.x + P_XSpeed;
        Run_Anim();
    }
    else {
        P_MoveL_Flg = FALSE;
    }

    //�ҋ@��
    if (Respawn_Flg == FALSE && P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE) {
        //�����l�ɂ��ǂ�
        P_XSpeed = 0.0f;
        Stand_by_Anim();
    }
}

void PLAYER::Player_Levitation_Move()
{
    //��������������Ƒ������Ă����������ɂȂ邽�ߌ�����������

    //�󒆉E�ړ�
    if (P_B_Btn == 1 && P_L_Stick > 128 && P_L_Stick > RIGHT_MOVE || P_A_Btn == 1 && P_L_Stick > RIGHT_MOVE) {
        P_Air_R_Flg = TRUE;

        P_XSpeed = P_XSpeed + 0.09f;    //���x���Z
        location.x = location.x + P_XSpeed;
        if (P_XSpeed >= 1.3f) {          //���x����
            P_XSpeed = 1.3f;                //���x����l
        }
    }
    else {
        // B�{�^����������Ă��Ȃ��@�X�e�B�b�N��|����Ă��Ȃ�
        P_Air_R_Flg = FALSE;
    }

    //�󒆍��ړ�
    if (P_B_Btn == 1 && P_L_Stick < LEFT_MOVE || P_A_Btn == 1&& P_L_Stick < LEFT_MOVE) {
        P_Air_L_Flg = TRUE;

        P_XSpeed = P_XSpeed + -0.09f;
        location.x = location.x + P_XSpeed;
        if (P_XSpeed <= -1.3f) {
            P_XSpeed = -1.3f;
        }
    }
    else {
        P_Air_L_Flg = FALSE;
    }

    /*�󒆂̊��� P_XSpeed�����̐��Ȃ猸�炵�ā@���̐��Ȃ瑝�₷�@B�{�^����������Ă��Ȃ��č��X�e�B�b�N�������ĂȂ������炱���ɗ��邩��
    �����ŏ�肭������������ΐ�������͂�*/

    if (P_Stand_Flg == FALSE && P_Air_L_Flg == FALSE && P_Air_R_Flg == FALSE) {
        //P_XSpeed = P_XSpeed;
        P_XSpeed *= 0.999f;
        Gliding_Anim();
        location.x = location.x + P_XSpeed;
    }
}


void PLAYER::Player_Gravity()
{
    if (P_Stand_Flg == FALSE)
    {
        //P_YSpeed = P_YSpeed + 0.009f;
        P_YSpeed = P_YSpeed + 0.01f;
        location.y = location.y + P_YSpeed;
        if (P_YSpeed >= 1.0f) {         //���x����  �O�� 1.3f
            P_YSpeed = 1.0f;
        }
    }
}

void PLAYER::Player_Air_A()
{
    // A�{�^���P����
    P_Stand_Flg = FALSE;
    Rise_Anim();
    P_YSpeed = P_YSpeed + -0.2f;
    location.y = location.y + P_YSpeed;
    //P_Move_Y--;
    if (P_YSpeed <= -1.0f) {        //���x����
        P_YSpeed = -1.0f;
    }
}

void PLAYER::Player_Air_B()
{
    /*A�{�^����B�{�^���̏����𓯂��ɂ��邽�߂�B�{�^�����ɂ��C���^�[�o��������
      B�{�^���͒������Ȃ̂ŋC�ɂȂ�Ȃ��͂�*/

    // B�{�^��������
    //P_Stand_Flg = FALSE;

    //P_YSpeed = P_YSpeed + -0.04f;
    ////P_YSpeed = P_YSpeed + -0.2;
    //P_Move_Y = P_Move_Y + P_YSpeed;
    ////P_Move_Y--;
    //if (P_YSpeed <= -1.0f) {
    //    P_YSpeed = -1.0f;
    //}

    P_Stand_Flg = FALSE;
    Rise_Anim();
    if (P_FPS % 2 == 0) {
        P_YSpeed = P_YSpeed + -0.05f;
        location.y = location.y + P_YSpeed;
        //P_Move_Y--;
        if (P_YSpeed <= -1.0f) {        //���x����
            P_YSpeed = -1.0f;
        }
    }
}


void PLAYER::Stand_Foot()
{
    //�����ő���̔���Ƃ�Ȃ��Ă���

    int fpscount = 0;

    //���̏o��
    if (py_u > 420)
    {
        rand = GetRand(100);

        if (rand <= 30) 
        {
            FishFlg = TRUE;

        }
    }
   /* else {
        FishFlg = FALSE;
    }*/
 }

void PLAYER::Respawn_Anim()
{
    if (P_Balloon_Flg == TRUE) {

        if (P_FPS >= 0 && P_FPS < 30) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_1];
        }
        else if (P_FPS > 29 && P_FPS <= 60) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_3];
        }
    }
    else {
        if (P_FPS >= 0 && P_FPS < 30) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_1];
        }
        else if (P_FPS > 29 && P_FPS <= 60) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_3];
        }
    }
}

void PLAYER::Stand_by_Anim()
{
    if (P_Balloon_Flg == TRUE) {
        // 0 ���� 3 �b
        if (P_Seconas1 == 0) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_1];
        }
        else if (P_Seconas1 > 0 && P_Seconas1 < 2) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_0];
        }
        else if (P_Seconas1 > 1 && P_Seconas1 < 3) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_1];
        }
        else if (P_Seconas1 > 2 && P_Seconas1 < 4) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON2_2];
        }
    }
    else {
        // 0 ���� 3 �b
        if (P_Seconas1 == 0) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_1];
        }
        else if (P_Seconas1 > 0 && P_Seconas1 < 2) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_0];
        }
        else if (P_Seconas1 > 1 && P_Seconas1 < 3) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_1];
        }
        else if (P_Seconas1 > 2 && P_Seconas1 < 4) {
            P_Img = P_ArrayImg[STAND_BY_BALLOON1_2];
        }
    }
}

void PLAYER::Run_Anim()
{
    if (P_Balloon_Flg == TRUE) {
        // 5�t���[��
        if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
            P_Img = P_ArrayImg[RUN_BALLOON2_0];
        }
        else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
            P_Img = P_ArrayImg[RUN_BALLOON2_1];
        }
        else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
            P_Img = P_ArrayImg[RUN_BALLOON2_2];
        }
        else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
            P_Img = P_ArrayImg[RUN_BALLOON2_3];
        }
    }
    else {
        // 5�t���[��
        if (P_FPS % 15 == 0 || P_FPS % 15 == 1 || P_FPS % 15 == 2 || P_FPS % 15 == 3 || P_FPS % 15 == 4) {
            P_Img = P_ArrayImg[RUN_BALLOON1_0];
        }
        else if (P_FPS % 15 == 5 || P_FPS % 15 == 6 || P_FPS % 15 == 7 || P_FPS % 15 == 8 || P_FPS % 15 == 9) {
            P_Img = P_ArrayImg[RUN_BALLOON1_1];
        }
        else if (P_FPS % 15 == 10 || P_FPS % 15 == 11 || P_FPS % 15 == 12 || P_FPS % 15 == 13 || P_FPS % 15 == 14) {
            P_Img = P_ArrayImg[RUN_BALLOON1_2];
        }
    }
    
}

void PLAYER::Gliding_Anim()
{
    if (P_Balloon_Flg == TRUE) {

        if (P_FPS >= 0 && P_FPS < 15) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_2];
        }
        else if (P_FPS > 14 && P_FPS < 30) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_3];
        }
        else if (P_FPS > 29 && P_FPS < 45) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_2];
        }
        else if (P_FPS > 44 && P_FPS <= 60) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_4];
        }
    }
    else {
        if (P_FPS >= 0 && P_FPS < 15) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_2];
        }
        else if (P_FPS > 14 && P_FPS < 30) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_3];
        }
        else if (P_FPS > 29 && P_FPS < 45) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_2];
        }
        else if (P_FPS > 44 && P_FPS <= 60) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_4];
        }
    }
}

void PLAYER::Rise_Anim()
{
    if (P_Balloon_Flg == TRUE) {

        if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_0];
        }
        else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_1];
        }
        else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_2];
        }
        else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON2_1];
        }
    }
    else {
        if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_0];
        }
        else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_1];
        }
        else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_2];
        }
        else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
            P_Img = P_ArrayImg[LEVITATION_BALLOON1_1];
        }
    }
}

void PLAYER::Beaten_Anim()
{
    if (P_FPS >= 0 && P_FPS < 15) {
        P_Img = P_ArrayImg[FALL_0];
    }
    else if (P_FPS > 14 && P_FPS < 30) {
        P_Img = P_ArrayImg[FALL_1];
    }
    else if (P_FPS > 29 && P_FPS < 45) {
        P_Img = P_ArrayImg[FALL_2];
    }
    else if (P_FPS > 44 && P_FPS <= 60) {
        P_Img = P_ArrayImg[FALL_1];
    }
}

PLAYER::~PLAYER()
{

}

void PLAYER::Draw()const
{
    DrawFormatString(0, 20, GetColor(255, 255, 255), " FPSCnt�F%d", P_FPS);

    //A�{�^���`��
    //DrawFormatString(0, 40, GetColor(255, 255, 255), " �����ꂽ�u�ԁF%d �����ꂽ�u�ԁF%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

    DrawFormatString(0, 60, GetColor(255, 255, 255), " ���X�e�B�b�N�F�����l %d �c���l %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

    DrawFormatString(0, 80, GetColor(255, 255, 255), " �v���C����FX���W %0.1f Y���W %0.01f", P_Move_X, P_Move_Y);

    DrawFormatString(0, 100, GetColor(255, 255, 255), " �ړ��t���O�F���ړ� %d �E�ړ� %d", P_MoveL_Flg, P_MoveR_Flg);

    DrawFormatString(0, 120, GetColor(255, 255, 255), " �}�E�X���W�FX���W %d Y���W %d", MouseX, MouseY);

    //DrawFormatString(330, 120, GetColor(255, 255, 255), " AnimCnt�F%d", AnimCnt);

    DrawFormatString(0, 140, GetColor(255, 255, 255), " �n��     Stand_Flg�F %d ", P_Stand_Flg);
    DrawFormatString(0, 160, GetColor(255, 255, 255), " ����   Beaten_Flg �F %d ", Beaten_Flg);
    //DrawFormatString(0, 160, GetColor(255, 255, 255), " �C   Foll_Flg �F %d ", P_Foll_Flg);
    DrawFormatString(0, 180, GetColor(255, 255, 255), " ���D   Balloon_Flg  �F %d ", P_Balloon_Flg);
    DrawFormatString(0, 200, GetColor(255, 255, 255), " p_uc X: %0.1f ", p_uc);
    DrawFormatString(0, 220, GetColor(255, 255, 255), " py2  Y: %0.1f ", py2);
    DrawFormatString(0, 240, GetColor(255, 255, 255), " P_YSpeed :%0.1f ", P_YSpeed);
    DrawFormatString(0, 260, GetColor(255, 255, 255), " P_XSpeed :%0.1f ", P_XSpeed);
    DrawFormatString(0, 280, GetColor(255, 255, 255), " P_Air_L_Flg :%d", P_Air_L_Flg);
    DrawFormatString(0, 300, GetColor(255, 255, 255), " P_Air_R_Flg :%d", P_Air_R_Flg);
    DrawFormatString(0, 320, GetColor(255, 255, 255), " L_Stick :%d", P_L_Stick_Flg);

    DrawCircle(p_uc, py2, 2.0f, 0xff0000, TRUE);

    //DrawCircleAA(p_uc, py2 - 54.0f, 2.0f, 0xfffff0, TRUE);

    //�v���C���[�̓����蔻��
    DrawBoxAA(location.x + 30, location.y + 37, location.x + 35, location.y + 65, GetColor(255, 255, 255), FALSE);

    //���D�̓����蔻��
    DrawBoxAA(location.x + 5, location.y + 10, location.x + 59, location.y + 37, GetColor(255, 255, 255), FALSE);

    //DrawBoxAA(px1, py1, px2, py2, GetColor(255, 0, 0), FALSE);

    //DrawBox(P_Move_X, P_Move_Y, P_Move_X + 64, P_Move_Y + 64, GetColor(255, 0, 0), FALSE);

    ////�c��
    //DrawLine(sx1, 0, sx1, 480, 0xff0000);
    //DrawLine(sx2, 0, sx2, 480, 0xff0000);

    ////����
    //DrawLine(0, sy1, 640, sy1, 0xff0000);


    // TurnFlag: �摜�̍��E���]���s�����̃t���O
    //DrawRotaGraph(P_Move_X, P_Move_Y, 1, 0, P_Img, TRUE, P_TurnFlg);

    //�ŏ��͉E�����ŕ`�悳���
    if (P_TurnFlg == TRUE) {
        DrawTurnGraphF(location.x, location.y, P_Img, TRUE);
    }
    else {
        if (P_TurnFlg == FALSE) {
            DrawGraphF(location.x, location.y, P_Img, TRUE);
        }
    }
}

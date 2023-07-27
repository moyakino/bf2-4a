#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"
#include "Stage.h"

int PLAYER::FishFlg;

float PLAYER::P_Move_X;
float PLAYER::P_Move_Y;

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
    P_A_Pressed = 0;

    P_Move_X = 100.0f;
    P_Move_Y = 350.0f;
    //P_Move_Y = 200.0f;

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
    P_Balloon_Flg = 1;
    P_TurnFlg = TRUE;
    P_A_BtnFlg = 0;
    P_Air_R_Flg = 0;
    P_Air_L_Flg = 0;
    P_FPS = 0;
    P_Seconas1 = 0;
    MouseX = 0;
    MouseY = 0;

    //����̍��W
    sx1 = 0, sx2 = 0, sy1 = 0, sy2 = 0;

    //�v���C���[�̍��W
    px1 = 0, px2 = 0, py1 = 0, py2 = 0, p_uc = 0;

    //������ԃt���O
    P_Stand_Flg = 0;
    //������ԃt���O
    P_Foll_Flg = 0;

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
    //���X�e�B�b�N���|����Ă��邩
    P_L_Stick_Flg = PAD_INPUT::GetStickOn();

    //�f�W�^�������E�{�^��
    P_Right_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT);

    //�f�W�^���������{�^��
    P_Left_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT);

    // A�{�^���P����
    P_A_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_A);

    // B�{�^��������
    P_B_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_B);

    //���[�v�p
    Player_Warp();

    //�����Ă��邩�̔���
    Stand_Foot();

    //�摜�؂�ւ��p
    Player_Img();

    //�X�e�[�W�̑���ɗ����Ă�����n��̈ړ��ɓ���
    if (P_Stand_Flg == TRUE) {
        //�n��̈ړ�
        Player_Move();
    }

    if (P_A_Btn == 1) {
        Player_Air_A();
    }

    if (P_B_Btn == 1) {
        Player_Air_B();
    }

    if (P_Stand_Flg == FALSE) {
        Player_Levitation_Move();
    }

    //Player_Levitation_Move();

    /*if (P_Stand_Flg == FALSE && P_B_Btn == 0) {
        P_XSpeed = P_XSpeed + -0.1f;
        if (P_XSpeed <= 0.5f) {
            P_XSpeed = 0.5f;
        }
    }*/

    if (P_Stand_Flg == FALSE && P_B_Btn == 0) {
        Player_Gravity();
    }

    //���[�v�p
    Player_Warp();

    //60fps == 1�b�@�Œ������� fps�� 0 �ɂ���
    if (P_FPS > 59) {
        P_FPS = 0;
        P_Seconas1++;
    }// P_FPS_INC �� �b��������Ă���
    else if (P_Seconas1 > 3) {
        P_Seconas1 = 0;
    }


    
}

void PLAYER::Player_Warp()
{
    //�����[�v
    if (P_Move_X <= -52) {
        P_Move_X = 640;
    }
    //�E���[�v
    else if (P_Move_X >= 680) {
        P_Move_X = -50;
    }

    //�V��
    /*if (P_Move_Y <= -25) {
        P_Move_Y = 250;
    }*/

    //�V��Œ��˕Ԃ�
    if (P_Move_Y <= -25) {
        P_Move_Y = -20;
        if (P_YSpeed < 0) {
            P_YSpeed = P_YSpeed * -0.8f;
        }
    }
    
}

void PLAYER::Player_Img()
{
    //�E�ړ��Ŕ��]�`��
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        P_TurnFlg = TRUE;
    }
    //���ړ��Œʏ�`��
    else if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        P_TurnFlg = FALSE;
    }
}

void PLAYER::Player_Move()
{
    //P_Air_Flg = FALSE;
    P_YSpeed = 0.0f;

    //�E�ړ�
    if (P_L_Stick > RIGHT_MOVE || P_Right_Btn == 1) {
        P_MoveR_Flg = TRUE;

        //�����x
        P_XSpeed = 1.0f;

        P_Move_X = P_Move_X + P_XSpeed;
        P_Img = Run_Anim();
    }
    else {
        P_MoveR_Flg = FALSE;
    }

    //���ړ�
    if (P_L_Stick < LEFT_MOVE || P_Left_Btn == 1) {
        P_MoveL_Flg = TRUE;

        //�����x
        P_XSpeed = -1.0f;

        P_Move_X = P_Move_X + P_XSpeed;
        P_Img = Run_Anim();
    }
    else {
        P_MoveL_Flg = FALSE;
    }

    //�ҋ@��
    if (P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE) {
        //�����l�ɂ��ǂ�
        P_XSpeed = 0.0f;
        P_Img = Stand_by_Anim();
    }
}

void PLAYER::Player_Levitation_Move()
{
    //��������������Ƒ������Ă����������ɂȂ邽�ߌ�����������

    //�󒆉E�ړ�
    if (P_B_Btn == 1 && P_L_Stick > 128 && P_L_Stick > RIGHT_MOVE) {
        P_Air_R_Flg = TRUE;
        //P_XSpeed = P_XSpeed + 0.8f;
        /*P_XSpeed = 1.5f;
        P_Move_X = P_Move_X + P_XSpeed;*/

        //if (P_XSpeed <= 2.0f) {
        //    P_XSpeed = P_XSpeed + 0.01f;    //���x���Z
        //    P_Move_X = P_Move_X + P_XSpeed;
        //}
        //else if(P_XSpeed >= 2.0f){          //���x����
        //    P_XSpeed = 2.0f;                //���x����l
        //    P_Move_X = P_Move_X + P_XSpeed;
        //}
        P_XSpeed = P_XSpeed + 0.08f;    //���x���Z
        P_Move_X = P_Move_X + P_XSpeed;
        if (P_XSpeed >= 3.5f) {          //���x����
            P_XSpeed = 3.5f;                //���x����l
            //P_Move_X = P_Move_X + P_XSpeed;
        }
    }
    else {
        // B�{�^����������Ă��Ȃ��@�X�e�B�b�N��|����Ă��Ȃ�
        P_Air_R_Flg = FALSE;

        //if (P_B_Btn == 0 && LEFT_MOVE < P_L_Stick && RIGHT_MOVE > P_L_Stick) {
        //    //����������
        //    P_XSpeed = P_XSpeed + 0.001;
        //    P_Move_X = P_Move_X + P_XSpeed;
        //    if (P_XSpeed >= 2.0f) {
        //        P_XSpeed = 2.0f;
        //    }
        //}

        /*if (P_Stand_Flg == FALSE && P_B_Btn == 0 && P_L_Stick_Flg == FALSE) {
            P_XSpeed = P_XSpeed + 0.01f;
            P_Move_X = P_Move_X + P_XSpeed;
            if (P_XSpeed >= 0.1f) {
                P_XSpeed = 0.1f;
            }
        }*/
        
        //vP_XSpeed = P_XSpeed + -0.01f;
        /*if (P_XSpeed <= 0.3f) {
            P_XSpeed = 0.3f;
        }*/

        /*if (P_B_Btn == 0 && ) {
            P_XSpeed = P_XSpeed + 0.1f;
            P_Move_X = P_Move_X + P_XSpeed;
            if (P_XSpeed >= 2.0f) {
                P_XSpeed = 2.0f;
            }
        }*/
        /*if (P_Air_Flg == TRUE && P_Stand_Flg == FALSE && P_B_Btn == 0) {
            P_XSpeed = P_XSpeed - 0.01f;
            P_Move_X = P_Move_X + P_XSpeed;
        }
        else if(P_XSpeed <= 1.0f) {
            P_XSpeed = 1.0f;
            P_Move_X = P_Move_X + P_XSpeed;
        }*/
    }

    /*if (P_Stand_Flg == FALSE && P_Air_R_Flg == FALSE) {
        P_XSpeed = P_XSpeed
    }*/

    //�󒆍��ړ�
    if (P_B_Btn == 1 && P_L_Stick < LEFT_MOVE) {
        P_Air_L_Flg = TRUE;
        /*P_XSpeed = -1.5f;
        P_Move_X = P_Move_X + P_XSpeed;*/

        /*if (P_XSpeed >= -1.9f) {
            P_XSpeed = P_XSpeed + -0.1f;
            P_Move_X = P_Move_X + P_XSpeed;
        }
        else if (P_XSpeed <= -1.9f) {
            P_XSpeed = -1.9f;
            P_Move_X = P_Move_X + P_XSpeed;
        }*/

        P_XSpeed = P_XSpeed + -0.08f;
        P_Move_X = P_Move_X + P_XSpeed;
        if (P_XSpeed <= -3.5f) {
            P_XSpeed = -3.5f;
        }
    }
    else {
        P_Air_L_Flg = FALSE;
    }

    /*�󒆂̊��� P_XSpeed�����̐��Ȃ猸�炵�ā@���̐��Ȃ瑝�₷�@B�{�^����������Ă��Ȃ��č��X�e�B�b�N�������ĂȂ������炱���ɗ��邩��
    �����ŏ�肭������������ΐ�������͂�*/

    if (P_Stand_Flg == FALSE && P_Air_L_Flg == FALSE && P_Air_R_Flg == FALSE) {
        P_XSpeed = P_XSpeed * 0.99f;
        P_Move_X = P_Move_X + P_XSpeed;
    }
}


void PLAYER::Player_Gravity()
{
    P_Stand_Flg = FALSE;
    P_YSpeed = P_YSpeed + 0.02f;
    P_Move_Y = P_Move_Y + P_YSpeed;
    //if (P_YSpeed >= 0.8f) {         //���x����
    //    P_YSpeed = 0.8f;
    //}
}

void PLAYER::Player_Air_A()
{
    // A�{�^���P����
    //P_Stand_Flg = FALSE;
    //P_YSpeed = P_YSpeed + -0.2f;
    //P_Move_Y = P_Move_Y + P_YSpeed;
    ////P_Move_Y--;
    //if (P_YSpeed <= -1.0f) {        //���x����
    //    P_YSpeed = -1.0f;
    //}
}

void PLAYER::Player_Air_B()
{
    // B�{�^��������
    P_Stand_Flg = FALSE;
    P_YSpeed = P_YSpeed + -0.07f;
    P_Move_Y = P_Move_Y + P_YSpeed;
    //P_Move_Y--;
    /*if (P_YSpeed <= -0.9f) {
        P_YSpeed = -0.9f;
    }*/
}


void PLAYER::Stand_Foot()
{
    //����̍��W
    sx1 = 180;
    sx2 = sx1 + 280;
    sy1 = 285;
    sy2 = sy1 + 20;

    //�v���C���[�̍��W
    px1 = P_Move_X;
    px2 = P_Move_X + 64;
    py1 = P_Move_Y;
    py2 = P_Move_Y + 64;

    //���S
    p_uc = (px1 + px2) / 2;
    py_u = (py1 + py2) / 2;
    
    //�����ł��Ă����ł��Ȃ��Ă����n��������
    if (Stage::Stand == TRUE) {

        P_Stand_Flg = TRUE;
    }
    else {
        P_Stand_Flg = FALSE;
    }

    int fpscount = 0;


    if (py_u > 444)
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

int PLAYER::Stand_by_Anim()
{
    int S_AnimImg = 0;

    // 0 ���� 3 �b
    if (P_Seconas1 == 0) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_1];
    }
    else if (P_Seconas1 > 0 && P_Seconas1 < 2) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_0];
    }
    else if (P_Seconas1 > 1 && P_Seconas1 < 3) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_1];
    }
    else if (P_Seconas1 > 2 && P_Seconas1 < 4) {
        S_AnimImg = P_ArrayImg[STAND_BY_BALLOON2_2];
    }

    return S_AnimImg;
}

int PLAYER::Run_Anim()
{
    int R_AnimImg = 0;

    // 5�t���[��
    if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_0];
    }
    else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_1];
    }
    else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_2];
    }
    else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
        R_AnimImg = P_ArrayImg[RUN_BALLOON2_3];
    }

    return R_AnimImg;
}

int PLAYER::Levitation_Anim1()
{
    int F1_AnimImg = 0;

    // 5�t���[��
    if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_0];
    }
    else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_1];
    }
    else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_2];
    }
    else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
        F1_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_3];
    }

    return F1_AnimImg;
}

int PLAYER::Levitation_Anim2()
{
    int F2_AnimImg = 0;

    if (P_FPS % 15 == 0 || P_FPS % 15 == 1 || P_FPS % 15 == 2 || P_FPS % 15 == 3 || P_FPS % 15 == 4) {
        F2_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_3];
    }
    else if (P_FPS % 15 == 5 || P_FPS % 15 == 6 || P_FPS % 15 == 7 || P_FPS % 15 == 8 || P_FPS % 15 == 9) {
        F2_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_2];
    }
    else if (P_FPS % 15 == 10 || P_FPS % 15 == 11 || P_FPS % 15 == 12 || P_FPS % 15 == 13 || P_FPS % 15 == 14) {
        F2_AnimImg = P_ArrayImg[LEVITATION_BALLOON2_4];
    }

    return F2_AnimImg;
}

PLAYER::~PLAYER()
{

}

void PLAYER::Draw()const
{
    DrawFormatString(0, 20, GetColor(255, 255, 255), " FPS�F%d", P_FPS);

    //A�{�^���`��
    //DrawFormatString(0, 40, GetColor(255, 255, 255), " �����ꂽ�u�ԁF%d �����ꂽ�u�ԁF%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

    //DrawFormatString(0, 60, GetColor(255, 255, 255), " ���X�e�B�b�N�F�����l %d �c���l %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

    DrawFormatString(0, 80, GetColor(255, 255, 255), " �v���C����FX���W %0.1f Y���W %0.01f", P_Move_X, P_Move_Y);

    DrawFormatString(0, 100, GetColor(255, 255, 255), " �ړ��t���O�F���ړ� %d �E�ړ� %d", P_MoveL_Flg, P_MoveR_Flg);

    DrawFormatString(0, 120, GetColor(255, 255, 255), " �}�E�X���W�FX���W %d Y���W %d", MouseX, MouseY);

    DrawFormatString(0, 180, GetColor(255, 255, 255), " �}�E�X���W�FX���W %d Y���W %d", MouseX, MouseY);

    DrawFormatString(330, 120, GetColor(255, 255, 255), " rand�F%d", rand);

    DrawFormatString(0, 140, GetColor(255, 255, 255), " �n�� Stand_Flg�F %d ", P_Stand_Flg);
    //DrawFormatString(0, 160, GetColor(255, 255, 255), " �C   Foll_Flg �F %d ", P_Foll_Flg);
    //DrawFormatString(0, 180, GetColor(255, 255, 255), " ��   Air_Flg  �F %d ", P_Air_Flg);
    DrawFormatString(0, 200, GetColor(255, 255, 255), " p_uc X: %0.1f ", p_uc);
    DrawFormatString(0, 220, GetColor(255, 255, 255), " py2  Y: %0.1f ", py2);
    DrawFormatString(0, 240, GetColor(255, 255, 255), " P_YSpeed :%0.1f ", P_YSpeed);
    DrawFormatString(0, 260, GetColor(255, 255, 255), " P_XSpeed :%0.1f ", P_XSpeed);
    DrawFormatString(0, 280, GetColor(255, 255, 255), " P_Air_L_Flg :%d", P_Air_L_Flg);
    DrawFormatString(0, 300, GetColor(255, 255, 255), " P_Air_R_Flg :%d", P_Air_R_Flg);
    DrawFormatString(0, 320, GetColor(255, 255, 255), " L_Stick :%d", P_L_Stick_Flg);

    DrawCircleAA(p_uc, py2, 2.0f, 0xffff00, TRUE);

    DrawCircleAA(p_uc, py2 - 54.0f, 2.0f, 0xfffff0, TRUE);

    //�v���C���[�̓����蔻��
    DrawBoxAA(P_Move_X + 30, P_Move_Y + 37, P_Move_X + 35, P_Move_Y + 65, GetColor(255, 255, 255), FALSE);

    //���D�̓����蔻��
    DrawBoxAA(P_Move_X + 5, P_Move_Y + 10, P_Move_X + 59, P_Move_Y + 37, GetColor(255, 255, 255), FALSE);

    DrawBoxAA(px1, py1, px2, py2, GetColor(255, 0, 0), FALSE);

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
        DrawTurnGraphF(P_Move_X, P_Move_Y, P_Img, TRUE);
    }
    else {
        if (P_TurnFlg == FALSE) {
            DrawGraphF(P_Move_X, P_Move_Y, P_Img, TRUE);
        }
    }
}

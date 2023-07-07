#include "DxLib.h"
#include "Player.h"
#include "PadInput.h"

PLAYER::PLAYER()
{
    //�v���C���[�摜�f�[�^�̓ǂݍ���
    if (LoadDivGraph("images/Player/Player_animation_d.png", 32, 8, 4, 64, 64, P_PlayerImg)){}
    P_Img = P_PlayerImg[1];
    P_L_Stick = 0;
    P_Right_Btn = 0;
    P_Left_Btn = 0;
    P_A_Btn = 0;
    P_Move_X = 100.0;
    P_Move_Y = 370.0;
    P_Speed = 0.0;
    P_MoveR_Flg = 0;
    P_MoveL_Flg = 0;
    P_Air_Flg = 0;
    P_Balloon_Flg = 1;
    P_TurnFlg = TRUE;
    P_FPS = 0;
    P_Seconas = 0;

}

void PLAYER::Update()
{
    //�t���[���擾
    P_FPS++;

    //���X�e�B�b�N �E�{�^�� ���{�^���̏�Ԏ擾
    P_L_Stick = PAD_INPUT::GetLStickX();
    P_Right_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT);
    P_Left_Btn = PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT);
    P_A_Btn = PAD_INPUT::OnButton(XINPUT_BUTTON_A);

    //�E�ړ�
    if (P_L_Stick > P_RIGHT_MOVE && P_Air_Flg == FALSE || P_Right_Btn == 1) {
        P_MoveR_Flg = TRUE;
        P_TurnFlg = TRUE;
        //P_Move_X += 2;
        P_Img = PLAYER::Run_Anim();
        if (P_Speed <= 4.0f) {
            P_Speed = P_Speed + 0.1f;
            P_Move_X = P_Move_X + P_Speed;
        }
        else if(P_Speed >= 4.0f){
            P_Speed = 4.0f;
            P_Move_X = P_Move_X + P_Speed;
        }
    }
    else{
        P_MoveR_Flg = FALSE;
    }

    //���ړ�
    if (P_L_Stick < P_LEFT_MOVE && P_Air_Flg == FALSE || P_Left_Btn == 1) {
        P_MoveL_Flg = TRUE;
        P_TurnFlg = FALSE;
        //P_Move_X -= 2;
        P_Img = PLAYER::Run_Anim();
        if (P_Speed >= -4.0f) {
            P_Speed = P_Speed + -0.1f;
            P_Move_X = P_Move_X + P_Speed;
        }
        else if (P_Speed <= -4.0f) {
            P_Speed = -4.0f;
            P_Move_X = P_Move_X + P_Speed;
        }
    }
    else {
        P_MoveL_Flg = FALSE;
    }

    //�ҋ@��
    if (P_MoveL_Flg == FALSE && P_MoveR_Flg == FALSE && P_Air_Flg == FALSE) {
        P_Img = PLAYER::Stand_by_Anim();
        P_Speed = P_Speed * 0.95f;
        P_Move_X = P_Move_X + P_Speed;
    }
    
    //����
    if (P_A_Btn == 1) {
        P_Move_Y -= 20;
    }
    else {
        //�d��
        if (P_A_Btn == 0 && P_Move_Y <= 350.0) {
            P_Move_Y += 0.3;
            //P_TurnFlg = P_Move_Flg();
            P_Air_Flg = TRUE;
        }
        else {
            P_Air_Flg = FALSE;
        }
    }

    //60fps == 1�b�@�Œ������� fps�� 0 �ɂ���
    if (P_FPS > 60) {
        P_FPS = 0;
        P_Seconas++;
    }// P_FPS_INC �� �b��������Ă���
    else if (P_Seconas > 3) {
        P_Seconas = 0;
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

int PLAYER::Stand_by_Anim()
{
    int S_AnimImg = 0;

    //�v���C���[�̉摜�̐؂�ւ��͕b���ɂ��Ă��� �t���[�����Ɠ_�ł���
    if (P_Seconas == 0) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_1];
    }
    else if (P_Seconas > 0 && P_Seconas < 2) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_0];
    }
    else if (P_Seconas > 1 && P_Seconas < 3) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_1];
    }
    else if (P_Seconas > 2 && P_Seconas < 4) {
        S_AnimImg = P_PlayerImg[P_STAND_BY_BL2_ANIM_2];
    }

    return S_AnimImg;
}

int PLAYER::Run_Anim()
{
    int R_AnimImg = 0;

    if (P_FPS % 20 == 0 || P_FPS % 20 == 1 || P_FPS % 20 == 2 || P_FPS % 20 == 3 || P_FPS % 20 == 4) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_0];
    }
    else if (P_FPS % 20 == 5 || P_FPS % 20 == 6 || P_FPS % 20 == 7 || P_FPS % 20 == 8 || P_FPS % 20 == 9) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_1];
    }
    else if (P_FPS % 20 == 10 || P_FPS % 20 == 11 || P_FPS % 20 == 12 || P_FPS % 20 == 13 || P_FPS % 20 == 14) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_2];
    }
    else if (P_FPS % 20 == 15 || P_FPS % 20 == 16 || P_FPS % 20 == 17 || P_FPS % 20 == 18 || P_FPS % 20 == 19) {
        R_AnimImg = P_PlayerImg[P_RUNNING_ANIM_3];
    }

    return R_AnimImg;
}

PLAYER::~PLAYER()
{

}

void PLAYER::Draw()const
{
    //A�{�^���`��
    DrawFormatString(0, 100, GetColor(255, 255, 255), " �����ꂽ�u�ԁF%d �����ꂽ�u�ԁF%d", PAD_INPUT::OnButton(XINPUT_BUTTON_A), PAD_INPUT::OnRelease(XINPUT_BUTTON_A));

    DrawFormatString(0, 120, GetColor(255, 255, 255), " ���X�e�B�b�N�F�����l %d �c���l %d", PAD_INPUT::GetLStickX(), PAD_INPUT::GetLStickY());

    DrawFormatString(0, 140, GetColor(255, 255, 255), " �v���C���[�FX���W %0.1f Y���W %0.01f", P_Move_X, P_Move_Y);

    DrawFormatString(0, 160, GetColor(255, 255, 255), " �ړ��t���O�F���ړ� %d �E�ړ� %d", P_MoveL_Flg, P_MoveR_Flg);

    DrawFormatString(330, 120, GetColor(255, 255, 255), " FPS�F%d", P_FPS);

    // TurnFlag: �摜�̍��E���]���s�����̃t���O
    //DrawRotaGraph(P_Move_X, P_Move_Y, 1, 0, P_Img, TRUE, P_TurnFlg);

    //�ŏ��͉E�����ŕ`�悳���
    if (P_TurnFlg == TRUE) {
        DrawTurnGraph(P_Move_X, P_Move_Y, P_Img, TRUE);
    }
    else {
        if (P_TurnFlg == FALSE) {
            DrawGraph(P_Move_X, P_Move_Y, P_Img, TRUE);
        }
    }
}

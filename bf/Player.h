#pragma once
#include "BoxCollider.h"

//�v���C���[ �ҋ@���A�j���[�V���� (���D����̏ꍇ)
#define STAND_BY_BALLOON2_0 0
#define STAND_BY_BALLOON2_1 1
#define STAND_BY_BALLOON2_2 2
#define STAND_BY_BALLOON2_3 3

//�v���C���[ �ҋ@���A�j���[�V���� (���D����̏ꍇ)
#define STAND_BY_BALLOON1_0 4
#define STAND_BY_BALLOON1_1 5
#define STAND_BY_BALLOON1_2 6
#define STAND_BY_BALLOON1_3 7

//�v���C���[ X�������̈ړ��A�j���[�V���� (���D����̏ꍇ)
#define RUN_BALLOON2_0 8
#define RUN_BALLOON2_1 9
#define RUN_BALLOON2_2 10
#define RUN_BALLOON2_3 11
#define RUN_BALLOON2_4 12

//�v���C���[ X�������̈ړ��A�j���[�V���� (���D����̏ꍇ)
#define RUN_BALLOON1_0 13
#define RUN_BALLOON1_1 14
#define RUN_BALLOON1_2 15
#define RUN_BALLOON1_3 16

//�v���C���[ Y�������̕���A�j���[�V���� (���D����̏ꍇ)
#define LEVITATION_BALLOON2_0 17
#define LEVITATION_BALLOON2_1 18
#define LEVITATION_BALLOON2_2 19
#define LEVITATION_BALLOON2_3 20
#define LEVITATION_BALLOON2_4 21

//�v���C���[ Y�������̕���A�j���[�V���� (���D����̏ꍇ)
#define LEVITATION_BALLOON1_0 22
#define LEVITATION_BALLOON1_1 23
#define LEVITATION_BALLOON1_2 24
#define LEVITATION_BALLOON1_3 25
#define LEVITATION_BALLOON1_4 26

//�v���C���[ ����A�j���[�V����
#define FALL_0 27
#define FALL_1 28
#define FALL_2 29
#define FALL_3 30

//�X�e�B�b�N�̌X�������v���C���[�̏�Ԃ��擾
#define LEFT_MOVE -2000
#define RIGHT_MOVE 2000

class PLAYER :public BoxCollider
{
private:
	//(��)�v���C���[�摜 �����ǂݍ��ݗp�ϐ�
	int		P_ArrayImg[33];

	//(��)�v���C���[�摜 �`��p�ϐ�
	int		P_Img;

	//(��)���X�e�B�b�N
	int		P_L_Stick;
	//(��)���X�e�B�b�N���|����Ă��邩
	int		P_L_Stick_Flg;

	//(��)�f�W�^�������{�^���E
	int		P_Right_Btn;
	//(��)�f�W�^�������{�^����
	int		P_Left_Btn;
	//(��)A�{�^��
	int		P_A_Btn;	//�P����

	//(��)B�{�^��������
	int		P_B_Btn;

	//(��)Y�{�^���P����
	int		P_Y_Btn;
	//(��)����A�j���[�V�����̍Đ�
	int		Beaten_Flg;
	int		AnimCnt;

	//(��)
	int		P_A_BtnFlg;
	int		P_Air_R_Flg;
	int		P_Air_L_Flg;

	//�v���C���[�̒n��X�s�[�h X���W
	float	P_XSpeed;
	//�v���C���[�̒n��X�s�[�h Y���W
	float	P_YSpeed;

	//(��)�v���C���[�E�ړ��t���O �ړ�����:0 �E�ړ�:1
	int		P_MoveR_Flg;
	//(��)�v���C���[���ړ��t���O �ړ�����:0 ���ړ�:1
	int		P_MoveL_Flg;
	//(��)���D��� 1:2�� 0:1��
	int		P_Balloon_Flg;
	int		Respawn_Flg;

	//FPS�ƕb���J�E���g
	int		P_FPS;
	int		P_Seconas1;
	int		FishCnt;
	int		F_Seconas1;
	int		MouseX;
	int		MouseY;

	int rand;

public:
	//�����Ă����Ԃ̃t���O
	static int		P_Stand_Flg;
	//Player  X���W�p�ϐ�
	static float	P_Move_X;
	//Player  Y���W�p�ϐ�
	static float	P_Move_Y;
	static int		FishFlg;
	/*(��)�摜�̍��E���]�p�t���O FALSE:���ʂɕ`�� TRUE:���E���]*/
	static	int		P_TurnFlg;
	static	int		F_TurnFlg;
	static	int		zanki;

	//�R���X�g���N�^
	PLAYER();

	//�f�X�g���N�^
	~PLAYER();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;

		//�֐���
	void Player_Warp();
	void Player_Img();
	void Player_Move();
	void Player_Gravity();
	void Player_Levitation_Move();
	void Player_Air_A();
	void Player_Air_B();

	//Player��������
	void Player_Init();
	//Player�̃��X�|�[���A�j���[�V����
	void Respawn_Anim();
	//Player�̑ҋ@��Ԓ��̃A�j���[�V����
	void Stand_by_Anim();
	//Player�������Ă��鎞�̃A�j���[�V����
	void Run_Anim();
	//Player�����󂵂Ă��鎞�̃A�j���[�V���� 
	void Gliding_Anim();
	//Player���㏸���Ă��鎞�̃A�j���[�V����
	void Rise_Anim_A();
	void Rise_Anim();
	//Player����A�j���[�V����
	void Beaten_Anim();
	//Player���n�ʂɂ��Ă��邩�����
	void Stand_Foot();

	void SetStandFlg(bool b) { P_Stand_Flg = b; }

	Location GetLocation() { return location; }

};
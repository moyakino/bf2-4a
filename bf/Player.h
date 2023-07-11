#pragma once
//�v���C���[ �ҋ@���A�j���[�V���� (���D����̏ꍇ)
#define STAND_BY_BALLOON2_0 0
#define STAND_BY_BALLOON2_1 1
#define STAND_BY_BALLOON2_2 2

//�v���C���[ �ҋ@���A�j���[�V���� (���D����̏ꍇ)
#define STAND_BY_BALLOON1_0 3
#define STAND_BY_BALLOON1_1 4
#define STAND_BY_BALLOON1_2 5

//�v���C���[ X�������̈ړ��A�j���[�V���� (���D����̏ꍇ)
#define RUN_BALLOON2_0 8
#define RUN_BALLOON2_1 9
#define RUN_BALLOON2_2 10
#define RUN_BALLOON2_3 11

//�v���C���[ X�������̈ړ��A�j���[�V���� (���D����̏ꍇ)
#define RUN_BALLOON1_0 12
#define RUN_BALLOON1_1 13
#define RUN_BALLOON1_2 14
#define RUN_BALLOON1_3 15

//�v���C���[ Y�������̕���A�j���[�V���� (���D����̏ꍇ)
#define LEVITATION_BALLOON2_0 16
#define LEVITATION_BALLOON2_1 17
#define LEVITATION_BALLOON2_2 18
#define LEVITATION_BALLOON2_3 19
#define LEVITATION_BALLOON2_4 20

//�v���C���[ Y�������̕���A�j���[�V���� (���D����̏ꍇ)
#define LEVITATION_BALLOON1_0 24
#define LEVITATION_BALLOON1_1 25
#define LEVITATION_BALLOON1_2 26
#define LEVITATION_BALLOON1_3 27
#define LEVITATION_BALLOON1_4 28

//�v���C���[ �����A�j���[�V����
#define FALL_0 21
#define FALL_1 22
#define FALL_2 23

//�v���C���[ ������A�j���[�V����
#define THUNDER_0 29
#define THUNDER_1 30

//�X�e�B�b�N�̌X�������v���C���[�̏�Ԃ��擾
#define LEFT_MOVE -2000
#define RIGHT_MOVE 2000

//�v���C���[�̑���X�s�[�h
#define RUN_SPEED 1
#define SPEED_UP  0.2
#define SPEED_UP1 0.2

class PLAYER
{
private:
	//(��)�v���C���[�摜 �����ǂݍ��ݗp�ϐ�
	int		P_ArrayImg[33];

	//(��)�v���C���[�摜 �`��p�ϐ�
	int		P_Img;

	//(��)���X�e�B�b�N
	int		P_L_Stick;

	//(��)�f�W�^�������{�^���E
	int		P_Right_Btn;
	//(��)�f�W�^�������{�^����
	int		P_Left_Btn;
	//(��)A�{�^��
	int		P_A_Btn;
	//(��)A�{�^��������
	int		P_A_Pressed;

	//Player  X���W�p�ϐ�
	float	P_Move_X;
	//Player  Y���W�p�ϐ�
	float	P_Move_Y;
	//�v���C���[�̒n��X�s�[�h
	float	P_Speed;
	//�v���C���[�̋󒆃X�s�[�h
	float	P_AirSpeed;

	//(��)�v���C���[�E�ړ��t���O �ړ�����:0 �E�ړ�:1
	int		P_MoveR_Flg;
	//(��)�v���C���[���ړ��t���O �ړ�����:0 ���ړ�:1
	int		P_MoveL_Flg;
	//(��)�v���C���[����t���O
	int		P_Air_Flg;
	//(��)���D��� 1:2�� 0:1��
	int		P_Balloon_Flg;
	//(��)�摜�̍��E���]�p�t���O FALSE:���ʂɕ`�� TRUE:���E���]
	int		P_TurnFlg;

	//FPS�ƕb���J�E���g
	int		P_FPS;
	int		P_Seconas1;
	
	int MouseX;
	int MouseY;

public:
	PLAYER();

	//�f�X�g���N�^
	~PLAYER();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;
	
	//�v���C���[�̉E�ړ�����
	//int P_Move_Flg();

	//Player�̑ҋ@��Ԓ��̃A�j���[�V����
	int Stand_by_Anim();
	//Player�������Ă��鎞�̃A�j���[�V����
	int Run_Anim();
	//Player�����サ�Ă��鎞�̃A�j���[�V���� 
	int Levitation_Anim1();
	int Levitation_Anim2();
};
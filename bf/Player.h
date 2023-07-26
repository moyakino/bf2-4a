#pragma once
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

	//(��)B�{�^��������
	int		P_B_Btn;

	//(��)A�{�^��������
	int		P_A_Pressed;
	//(��)
	int		P_A_BtnFlg;
	int		P_Air_R_Flg;
	int		P_Air_L_Flg;

	//Player  X���W�p�ϐ�
	float	P_Move_X;
	//Player  Y���W�p�ϐ�
	float	P_Move_Y;
	//�v���C���[�̒n��X�s�[�h X���W
	float	P_XSpeed;
	//�v���C���[�̒n��X�s�[�h Y���W
	float	P_YSpeed;
	//�v���C���[�̋󒆃X�s�[�h
	float	P_AirSpeed;

	float P_Speed;

	float	P_Accele;

	float	P_Air_Multiply;

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


	//�����Ă����Ԃ̃t���O
	int		P_Stand_Flg;
	//�C�ɗ��������Ԃ̃t���O
	int		P_Foll_Flg;

	float	sx1, sy1, sx2, sy2;

	float	px1, py1, px2, py2, p_uc;

	//FPS�ƕb���J�E���g
	int		P_FPS;
	int		P_Seconas1;
	
	int		MouseX;
	int		MouseY;

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

		//�֐���
	void Player_Warp();
	void Player_Img();
	void Player_Move();
	void Player_Gravity();
	void Player_Levitation_Move();
	void Player_Air_A();
	void Player_Air_B();

	int Return_MoveX();
	int Return_MoveY();

	//Player�̑ҋ@��Ԓ��̃A�j���[�V����
	int Stand_by_Anim();
	//Player�������Ă��鎞�̃A�j���[�V����
	int Run_Anim();
	//Player�����サ�Ă��鎞�̃A�j���[�V���� 
	int Levitation_Anim1();
	int Levitation_Anim2();

	void Stand_Foot();

	/*int GetLocationX();

	int GetLocationY();*/
};
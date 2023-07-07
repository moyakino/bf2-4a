#pragma once
//�v���C���[�̑ҋ@���A�j���[�V���� (���D����̏ꍇ)
#define P_STAND_BY_BL2_ANIM_0 0
#define P_STAND_BY_BL2_ANIM_1 1
#define P_STAND_BY_BL2_ANIM_2 2
//�v���C���[�̑ҋ@���A�j���[�V���� (���D����̏ꍇ)
#define P_STAND_BY_BL1_ANIM_0 3
#define P_STAND_BY_BL1_ANIM_1 4
#define P_STAND_BY_BL1_ANIM_2 5
//�v���C���[�� X�������̈ړ��A�j���[�V����
#define P_RUNNING_ANIM_0 8
#define P_RUNNING_ANIM_1 9
#define P_RUNNING_ANIM_2 10
#define P_RUNNING_ANIM_3 11
//�v���C���[�� Y�������̕���A�j���[�V����
#define P_FLY_TO_THE_SKY_ANIM_0 16
#define P_FLY_TO_THE_SKY_ANIM_1 17
#define P_FLY_TO_THE_SKY_ANIM_2 18
#define P_FLY_TO_THE_SKY_ANIM_3 19
#define P_FLY_TO_THE_SKY_ANIM_4 20

//�X�e�B�b�N�̌X�������v���C���[�̏�Ԃ��擾
#define P_LEFT_MOVE -2000
#define P_RIGHT_MOVE 2000

//�v���C���[�̑���X�s�[�h
#define P_RUN_SPEED 1
#define P_SPEED_UP  0.2
#define P_SPEED_UP1 0.2

class PLAYER
{
private:
	//(��)�v���C���[�摜 �����ǂݍ��ݗp�ϐ�
	int		P_PlayerImg[33];

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

	//Player  X���W�p�ϐ�
	float		P_Move_X;
	//Player  Y���W�p�ϐ�
	float	P_Move_Y;
	//�v���C���[�̃X�s�[�h
	float	P_Speed;

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
	int		P_Seconas;
	

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
	
};
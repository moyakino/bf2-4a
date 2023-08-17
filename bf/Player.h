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
	
	int		P_ArrayImg[33];		//(��)�v���C���[�摜 �����ǂݍ��ݗp�ϐ�
	int		P_Img;				//(��)�v���C���[�摜 �`��p�ϐ�


	int		P_L_Stick;			//���X�e�B�b�N
	int		P_Right_Btn;		//�f�W�^�������{�^���E
	int		P_Left_Btn;			//�f�W�^�������{�^����
	int		P_A_Btn;			//A�{�^�� �P����
	int		P_B_Btn;			//B�{�^�� ������
	int		P_Y_Btn;			//(��)Y�{�^�� �P����

	float	P_XSpeed;			//�v���C���[�̒n��X�s�[�h X���W
	float	P_YSpeed;			//�v���C���[�̒n��X�s�[�h Y���W

	int		P_MoveR_Flg;		//�v���C���[�E�ړ��t���O �ړ�����:0 �E�ړ�:1
	int		P_MoveL_Flg;		//�v���C���[���ړ��t���O �ړ�����:0 ���ړ�:1
	int		P_Air_R_Flg;		//�󒆂����X�e�B�b�N���g���Ȃ���A�E�Ɉړ����Ă��邩�H
	int		P_Air_L_Flg;		//�󒆂����X�e�B�b�N���g���Ȃ���A���Ɉړ����Ă��邩�H
	int		P_Balloon_Flg;		//���D��� TRUE:2�� FALSE:1��
	int		Respawn_Flg;		//���X�|�[�������ۂ̓_�ŃA�j���[�V�����Đ��p�t���O
	int		Y_flg;				//����A�j���[�V�����Đ����̗����p�t���O
	int		LightningFlg;		//������A�j���[�V�����p�t���O
	int		LightningCnt;		//������A�j���[�V�����p�J�E���g

	
	int		Beaten_Flg;			//����A�j���[�V�����̍Đ�
	int		AnimCnt;			//�f�o�b�N�p
	int		MouseX;				//�f�o�b�N�p�}�E�XX
	int		MouseY;				//�f�o�b�N�p�}�E�XY

	int		P_FPS;				//FPSCnt
	int		P_Seconas1;			//�b��

	int		FishCnt;			//���p�J�E���g
	int		F_Seconas1;			//���p�b��
	int		rand;				//���p�m��

    int  P_Jump_SE;
	int  P_Respawn_BGM;

	
public:
	
	static int		P_Stand_Flg;	//�����Ă����Ԃ̃t���O
	static float	P_Move_X;		//Player  X���W�p�ϐ�
	static float	P_Move_Y;		//Player  Y���W�p�ϐ�
	static	int		P_TurnFlg;		//�摜�̍��E���]�p�t���O FALSE:���ʂɕ`�� TRUE:���E���]
	static	int		PlayerLife;		//Player�̎c�@�p
	static	int		FishHit;		//���ɓ����������H
	static	int		FishDeath;		//���p���S����
	static	int		zanki;

	static int		FishFlg;		//���p�t���O
	static	int		F_TurnFlg;		//���p�摜���E���]�t���O

	//�R���X�g���N�^
	PLAYER();

	//�f�X�g���N�^
	~PLAYER();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;

	void Player_Warp();				//Player��ʒ[�ړ��֐�
	void Player_Img();				//Player�摜���E���]�֐�
	void Player_Move();				//Player�n��ړ��֐�
	void Player_Gravity();			//Player�d�͊֐�
	void Player_Levitation_Move();	//Player�󒆈ړ��֐�
	void Player_Air_A();			//A�{�^���P�����̍ۂ̏㏸�֐�
	void Player_Air_B();			//B�{�^���������̍ۂ̏㏸�֐�

	void Player_Init();				//Player��������

	void Respawn_Anim();			//Player�̃��X�|�[���A�j���[�V����
	void Stand_by_Anim();			//Player�̑ҋ@��Ԓ��̃A�j���[�V����
	void Run_Anim();				//Player�������Ă��鎞�̃A�j���[�V����
	void Gliding_Anim();			//Player�����󂵂Ă��鎞�̃A�j���[�V���� 
	void Rise_Anim_A();				//Player���㏸���Ă��鎞�̃A�j���[�V���� A�{�^���p
	void Rise_Anim_B();				//Player���㏸���Ă��鎞�̃A�j���[�V���� B�{�^���p
	void Beaten_Anim();				//Player����A�j���[�V����
	void Struck_by_Lightning_Anim();//Player������A�j���[�V����

	void Fish_Respawn();			//���o���֐�

	//�������֒��˕Ԃ鏈��
	void BoundPlusX();

	//������֒��˕Ԃ鏈��
	void BoundMinusX();

	//�E�����֒��˕Ԃ鏈��
	void BoundPlusY();

	//�������֒��˕Ԃ鏈��
	void BoundMinusY();

	//�v���C���[�����˕Ԃ鏈��
	void CheckBound(BoxCollider* b_col);

	//�v���C���[�ƓG�̓����蔻��
	int EnemyCollider(BoxCollider* b_col);

	Location GetLocation() { return location; }

};
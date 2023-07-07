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


//X���W�� Stick �̏����l
#define STICK_X_INITIAL_VALUE 128
#define P_MOVE_Y 350


#define e 0.800		//�����W��
#define g 0.900		//�d�͉����x

class Player
{
private:

	//Player x y ���W�p�ϐ�
	int P_Move_X;
	float P_Move_Y;

	//�v���C���[��ʒ[(��)
	/*int P_Left;
	int P_Move_X_Left;*/


	//(��)�v���C���[�摜�p�ϐ�
	int P_PlayerImg[33];
	//(��)�v���C���[�o�͗p�ϐ�
	int P_Img;

	//(��)�v���C���[�E�ړ��t���O �ړ�����:0 �E�ړ�:1
	int P_MoveR_Flg;
	//(��)�v���C���[���ړ��t���O �ړ�����:0 �E�ړ�:1
	int P_MoveL_Flg;
	//(��)�󒆂ɂ��邩�̔���t���O
	int P_Air_Flg;
	//�摜�𔽓]���邩�ǂ����̃t���O
	int Trun_Flg;

	//FPS�ƕb���J�E���g
	int P_FPS;
	int P_FPS_INC;
	int P_FPS_FLY;

	int P_AnimL_Flg;
	int P_AnimR_Flg;
	//(��)�ҋ@����p�t���O
	int P_Std_Anim_Flg;

	float P_Air_Multiply;

	int a;

public:
	Player();

	//�f�X�g���N�^
	~Player();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;
	
	//Player�̑ҋ@��
	int Stand_by_Anim();
	//Player�����サ�Ă��鎞�̃A�j���[�V����
	int Fly_To_The_Sky_Anim_1();

	//��
	int Fly_To_The_Sky_Anim_2();

	//Player�������Ă��鎞�̃A�j���[�V����
	int Running_Anim();

	//Player�� X���W Y���W ��߂�l�Ƃ��ĕԂ�
	int R_Player_MoveX()const;
	float R_Player_MoveY()const;
};
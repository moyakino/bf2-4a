#pragma once

#define e 0.800		//�����W��
#define g 0.900		//�d�͉����x

class Player
{
private:

	//A�{�^���̊i�[�p�ϐ�
	//int L_Stick_X;
	//int L_Stick_Y;
	//Player x y ���W�p�ϐ�
	int P_Move_X;
	int P_Move_Y;
	//(��)�v���C���[�摜�p�ϐ�
	int D_PlayerImg[3];

	int P_PlayerImg[33];

	int P_Img;

	//(��)�v���C���[�E�ړ��t���O �ړ�����:0 �E�ړ�:1
	int P_MoveR_Flg;
	//(��)�v���C���[���ړ��t���O �ړ�����:0 �E�ړ�:1
	int P_MoveL_Flg;


public:
	Player();

	//�f�X�g���N�^
	~Player() { };

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;

	//�A�j���[�V����
	int Animation(int Anim1, int Anim2);

	//Player�̑ҋ@��
	int Stand_by_Anim();

	//Player�� X���W Y���W ��߂�l�Ƃ��ĕԂ�
	int R_Player_MoveX()const;
	int R_Player_MoveY()const;
};
#pragma once

class Player
{
private:

	//A�{�^���̊i�[�p�ϐ�
	int L_Stick_X;
	int L_Stick_Y;
	//Player x y ���W�p�ϐ�
	int P_Move_X;
	int P_Move_Y;
	//(��)�v���C���[�摜�p�ϐ�
	int D_PlayerImg;

public:
	Player();

	//�f�X�g���N�^
	~Player() { };

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;
};
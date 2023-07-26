#pragma once
#include "BoxCollider.h"

//�X�e�B�b�N�̌X�������v���C���[�̏�Ԃ��擾
#define LEFT_MOVE -2000
#define RIGHT_MOVE 2000

#define PLAYER_WID 
#define PLAYER_HEI 

//�v���C���[�̑���X�s�[�h
#define RUN_SPEED	1
#define FLY_SPEED2	0.2
#define FLY_SPEED1	0.2

enum class PLAYER_FLG
{
	STAND,
	WALK,
	FLY,
	FOLL,
};

class testPlayer :public BoxCollider 
{
private:
	PLAYER_FLG PlayerFlg;	//�v���C���[�̌��݂̏��

	float Speed;	//�ړ����x
	float VelX;	//����x
	float VelY;	//����y
	float Gravity;	//�d��
	float Reflect;	//����

private:

	//�A�j���[�V�����p�摜
	int pStandImg_Bloon2[4];	//�ҋ@�A�j���[�V����(���D2��)	0�`3
	int pStandImg_Bloon1[4];	//�ҋ@�A�j���[�V����(���D1��)	4�`7

	int pWalkImg_Bloon2[5];		//���s�A�j���[�V����(���D2��)	8�`12
	int pWalkImg_Bloon1[4];		//���s�A�j���[�V����(���D1��)	13�`16

	int pFlyImg_Bloon2[5];		//��s�A�j���[�V����(���D2��)	17�`21
	int pFlyImg_Bloon1[5];		//��s�A�j���[�V����(���D1��)	22�`26

	int pFallImg[4];			//����A�j���[�V����			27�`30

	int P_ArrayImg[33];	//�摜�i�[

	int sCnt;	//�ҋ@���A�j�� �J�E���g�p�ϐ�
	int wCnt;	//���s�A�j�� �J�E���g�p�ϐ�

	int P_Img;	//�摜

	int fps;	//fps

	int pLeft;

public:
	//�R���X�g���N�^
	testPlayer();

	//�f�X�g���N�^
	~testPlayer();

	//�X�V
	void Update();

	//�`��
	void Draw() const;

	//�n��ł̈ړ�
	void Player_StandMove();

	//����
	void Player_Fly();


	//����
	void Player_Bound();



	//�ҋ@���A�j���[�V����
	int StandAnim();

	//���s�A�j���[�V����
	int WalkAnim();

};


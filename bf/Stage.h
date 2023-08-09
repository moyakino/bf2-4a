#pragma once
#include "BoxCollider.h"

#define GREEN_FOOT_WIDTH_1 280.0
#define GREEN_FOOT_HEIGHT_1 17.0

#define GREEN_FOOT_WIDTH_2 112
#define GREEN_FOOT_HEIGHT_2 17

#define GREEN_FOOT_WIDTH_3 81
#define GREEN_FOOT_HEIGHT_3 18

#define GREEN_FOOT_WIDTH_4 61
#define GREEN_FOOT_HEIGHT_4 68

#define GREEN_FOOT_WIDTH_5 42
#define GREEN_FOOT_HEIGHT_5 18

#define RED_FOOT_WIDTH_1 62
#define RED_FOOT_HEIGHT_1 18

#define RED_FOOT_WIDTH_2 22
#define RED_FOOT_HEIGHT_2 51

#define RED_FOOT_WIDTH_3 21
#define RED_FOOT_HEIGHT_3 67

#define RAND_WIDTH 160
#define RAND_HEIGHT 64


class Stage :public BoxCollider
{
private:
	int StageFoot[8];
	int StageLand_R;
	int StageLand_L;
	int StageSea;

	int StageSample1;
	int StageSample2;
	int StageSample3;
	int StageSample4;
	int StageSample5;


public:

	//�R���X�g���N�^
	Stage(int num,int i);

	//�f�X�g���N�^
	~Stage();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;


};
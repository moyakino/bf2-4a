#pragma once
#include "BoxCollider.h"

#define GREEN_FOOT_WIDTH_1 280.0
#define GREEN_FOOT_HEIGHT_1 17.0

class Stage1 :public BoxCollider
{
private:
	float sx1, sx2;
	float sy1, sy2;

	float	px1, py1, px2, py2, p_uc;
	int Bound;

public:
	//�R���X�g���N�^
	Stage1();

	//�f�X�g���N�^
	~Stage1();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;

	int HitBox();

};


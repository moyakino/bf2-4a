#pragma once

#define GREEN_FOOT_WIDTH_1 280
#define GREEN_FOOT_HEIGHT_1 17

class Stage1
{
private:
	int x1, x2;
	int y1, y2;

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


#pragma once
#include "DxLib.h"
class Stage2
{
private:
	float sx1, sx2;
	float sy1, sy2;

public:
	//�R���X�g���N�^
	Stage2();

	//�f�X�g���N�^
	~Stage2();

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;
};


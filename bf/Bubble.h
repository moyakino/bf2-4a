#pragma once
class Bubble{



private:
	int BubbleImg;
	int x;
	int y;


public:
	Bubble();

	//�f�X�g���N�^
	~Bubble() { };

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;
};

#pragma once
class Bubble{
private:
	//�V���{���ʂ̉摜�i���j
	int BubbleImg;
	int BallFlg;
	//�V���{���ʂ̏����ʒu
	int X, Y;
	//�V���{���ʂ̍��W�X�V
	int BallX;
	int BallY;
	//�V���{���ʂ̓�������
	int MoveX;
	int MoveY;
	//�d��
	int Speed;
public:
	Bubble();

	//�f�X�g���N�^
	~Bubble() { };

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;
};

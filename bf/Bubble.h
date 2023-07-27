#pragma once

class Bubble {
private:
	//�V���{���ʂ̉摜�i���j
	int BubbleImg[4];
	int B_Img;
	int Bubbleflg;
	int B_flg;
	int H_flg;
	int Img;
	int B_AnimImg;
	//�V���{���ʂ̏����ʒu
	float MoveX;
	float MoveY;
	//�v���C���[���W
	float PlayerX;
	float PlayerY;
    //�V���{���ʂ̓���
	float SpeedY;
    float SpeedX;
	int B_FPS;
	int seconds;
	int HitBox;
	float Player;
	int D_flg;
	int F_flg;
	int FontHandle;
	int Delete;
public:
	Bubble();

	//�f�X�g���N�^
	~Bubble() { };

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;


	int BubbleControl();
	void  Hit();
	void BubbleMove();
	int  BubbleAnim();
	void Score();

};

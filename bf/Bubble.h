#pragma once
//�V���{���ʂ̃A�j���[�V����
#define Bubble_Anim_0 0
#define Bubble_Anim_1 1
#define Bubble_Anim_2 2
#define Bubble_Anim_3 3

class Bubble {
private:
	//�V���{���ʂ̉摜�i���j
	int BubbleImg[3];
	int B_Img;
	int Bubbleflg;
	int B_flg;
	//�V���{���ʂ̏����ʒu
	float MoveX;
	float MoveY;
    //�V���{���ʂ̓���
	float SpeedY;
    float SpeedX;
	int B_FPS;
	int seconds;
	int tick;
	int i;
public:
	Bubble();

	//�f�X�g���N�^
	~Bubble() { };

	//�`��ȊO�̍X�V����������
	void Update();

	//�`�揈��
	void Draw() const;

	int BubbleControl(void);
};

#pragma once
#define _USE_MATH_DEFINES
//���A�j���[�V����
#define THUNDER_ANIM1_0 0
#define THUNDER_ANIM1_1 1
#define THUNDER_ANIM1_2 2
#define THUNDER_ANIM1_3 3
#define THUNDER_ANIM1_4 5
#define THUNDER_ANIM1_5 6

#define EFFECT_ANIM1_0 0
#define EFFECT_ANIM1_1 1
#define EFFECT_ANIM1_2 2

#define CLOUD_ANIM1_0 0
#define CLOUD_ANIM1_1 1
#define CLOUD_ANIM1_2 2

class Thunder {

private:

    //���摜 �����ǂݍ��ݗp�ϐ�
    int	ThunderImg[7];
    int T_Img;

    int	EffectImg[3];
    int E_Img;
    
    //�_�摜�@�����Ǎ��s�ϐ�
    int	CloudImg;
    int	Cloud_AnimImg[3];
    int C_Img;

    //FPS�ƕb���J�E���g
    int	S_FPS1;
    int	S_FPS2;
    int	S_Seconas1;
    int	S_Seconas2;

    int BallFlg;                //�{�[���̏��(0...�ړ��� 1...�o�[�ڐG2:�X�^�[�g���)
    int RestBall;               //�c��̃{�[���̐�

    //�{�[���̕ϐ�
    int BallX, BallY;
    //�{�[���̈ړ���
    int MoveX, MoveY;
    int Speed;                  //�{�[���̃X�s�[�h
    float BallAngle;            //�{�[���̊p�x

    int MouseX, MouseY;         // �}�E�X�̍��W
    int BarX, BarY;             // �o�[�̍��W

    int H_flg;

public:

    //�R���X�g���N�^
    Thunder();

    // �f�X�g���N�^
    ~Thunder();

    // �X�V��������������
    void Update();

    // �`�揈������������
    void Draw() const;

    int Thunder_Anim();
    int Effect_Anim();

    int Cloud_Anim();

    //void MoveBall();
    //void HitThunder();
    //void ChangeAngle();     //�{�[���̊p�x

};
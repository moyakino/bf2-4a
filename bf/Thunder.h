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

class Thunder
{
private:

    //���i����j�摜 �����ǂݍ��ݗp�ϐ�
    int	ThunderImg[7];
    int T_Img;
    int T_Thunder_Flg;
    //���i�e�j�摜 �����ǂݍ��ݗp�ϐ�
    int	EffectImg[3];
    int E_Img;
    int T_Effect_Flg;
    
    //�_�摜�@�����Ǎ��p�ϐ�
    int	CloudImg;
    int	Cloud_AnimImg[3];
    int C_Img;
    int T_Cloud_Flg;

    //FPS�ƕb���J�E���g
    int	S_FPS1;
    int	S_FPS2;
    int	S_Seconas1;
    int	S_Seconas2;

    int BallFlg;                //�{�[���̏��(0...�ړ��� 1...Player�ڐG2:�X�^�[�g���)
    int BallX, BallY;           //�{�[���̕ϐ�
    int MoveX, MoveY;           //�{�[���̈ړ���
    int Speed;                  //�{�[���̃X�s�[�h
    float BallAngle;            //�{�[���̊p�x

    int MouseX, MouseY;         // �}�E�X�̍��W

    int H_flg;

public:

    Thunder(); //�R���X�g���N�^
    ~Thunder();// �f�X�g���N�^
    
    void Update();// �X�V��������������

    void Draw() const;// �`�揈������������

    int Thunder_Anim();
    int Effect_Anim();

    int Cloud_Anim();

    void MoveBall();
    void HitThunder();
    void ChangeAngle();     //�{�[���̊p�x

};
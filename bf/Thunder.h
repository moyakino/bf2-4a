#pragma once
//���A�j���[�V����
#define THUNDER_ANIM1_0 0
#define THUNDER_ANIM1_1 1
#define THUNDER_ANIM1_2 2
#define THUNDER_ANIM1_3 3
#define THUNDER_ANIM1_4 5
#define THUNDER_ANIM1_5 6

#define THUNDER_EFFECT_ANIM1_0 0
#define THUNDER_EFFECT_ANIM1_1 1
#define THUNDER_EFFECT_ANIM1_2 2

class Thunder {

private:

    //���摜 �����ǂݍ��ݗp�ϐ�
    int	ThunderImg[6];
    int T_Img;

    int	EffectImg[3];
    int E_Img;

    //FPS�ƕb���J�E���g
    int	S_FPS;
    int	S_Seconas1;

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
};
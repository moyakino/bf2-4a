#pragma once
//���A�j���[�V����
#define THUNDER_ANIM1_0 0
#define THUNDER_ANIM1_1 1
#define THUNDER_ANIM1_2 2

class Thunder {

private:

    //���摜 �����ǂݍ��ݗp�ϐ�
    int	S_ThunderImg[3];
    int S_Img;

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
};
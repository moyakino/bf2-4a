#pragma once
#include"Player.h"

//�G�l�~�[  �ҋ@���A�j���[�V���� (��C������)
#define STAND_BY_ENEMY_0 0
#define STAND_BY_ENEMY_1 1
#define STAND_BY_ENEMY_2 2
#define STAND_BY_ENEMY_3 3
#define STAND_BY_ENEMY_4 4
#define STAND_BY_ENEMY_5 5
#define STAND_BY_ENEMY_6 6
#define STAND_BY_ENEMY_7 7

//�G�l�~�[  ����A�j���[�V���� 
#define LEVITATION_ENEMY_0 8
#define LEVITATION_ENEMY_1 9
#define LEVITATION_ENEMY_2 10
#define LEVITATION_ENEMY_3 11
#define LEVITATION_ENEMY_4 12

//�G�l�~�[����A�j���[�V����
#define FALL_ENEMY_0 13
#define FALL_ENEMY_1 14

//�G�l�~�[�p���V���[�g�A�j���[�V����
#define parachute_0 15
#define parachute_1 16
#define parachute_2 17

enum class ENEMY_STATE {
    START,
    FLY_LEFT,
    FLY_RIGHT,
    FALL,
    WAIT,
};


class EnemyBird {
private:
    int Cnt;
    int CntWait;
    int E_Img;
    float SpeedX;
    float SpeedY;


    int E_ArrayImg_P[18];
    int E_ArrayImg_G[18];
    int E_ArrayImg_R[18];

    //�t���[���擾
    int E_FPS;
    float E_Second;

    //�����Ă����Ԃ̃t���O
    int		E_Stand_Flg;
    //�C�ɗ��������Ԃ̃t���O
    int		E_Foll_Flg;

    int StartTime;

    float	sx1, sy1, sx2, sy2;
    float	ex1, ey1, ex2, ey2, e_uc;

    //�G�̍��W

    float E_Move_X;
    float E_Move_Y;

    //�󒆂ł̃X�s�[�h
    float E_AirSpeed;
    float E_Air_Flg;

    //�G�̈ړ�
    float E_Balloon_Flg;
    int     E_AnimImg;

    //�v���C���[�̒n��X�s�[�h X���W
    float	E_XSpeed;
    //�v���C���[�̒n��X�s�[�h Y���W
    float	E_YSpeed;
    float   E_Speed;
    float	E_Accele;

    float	E_Air_Multiply;

    ENEMY_STATE EnemyState;
    
    
public:

    ////Player  X���W�p�ϐ�
    //static float	E_Move_X;
    ////Player  Y���W�p�ϐ�
    //static float	E_Move_Y;

    //�R���X�g���N�^
    EnemyBird();
    // �f�X�g���N�^
    ~EnemyBird();
    // �X�V��������������
    void Update();
    // �`�揈������������
    void Draw() const;
    //�n�ʂɗ�������
    void Stand_Foot();

    int  Balloon_Anim(void);
    //�󒆂ňړ����Ă���Ƃ��̃A�j���[�V����

    void Stand_by_Anim();
    void Start_Anim();
    void Fly_Anim();

    void Enemy_Levitation_Move_X();
    void Enemy_Levitation_Move_Y();

    void Enemy_Gravity();
    void Enemy_Warp();
    void Anim();
};

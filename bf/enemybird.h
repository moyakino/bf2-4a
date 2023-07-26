#pragma once
#include"Player.h"

class EnemyBird {
private:
    int x, y;
    int my;
    int hp;
    int cnt;
    float speed;

    int E_ArrayImg_P[17];
    int E_ArrayImg_G[17];
    int E_ArrayImg_R[17];

    //�t���[���擾
    int E_FPS;
    int seconds;

    int PlayerPos;
    int EnemyPos;

    //�����Ă����Ԃ̃t���O
    int		E_Stand_Flg;
    //�C�ɗ��������Ԃ̃t���O
    int		E_Foll_Flg;

    float	sx1, sy1, sx2, sy2;

    float	ex1, ey1, ex2, ey2, e_uc;

    //�G�̍��W
    float E_location_X;
    float E_location_Y;

    //�v���C���[�̍��W
    float P_Move_X;
    float P_Move_Y;

    //�󒆂ł̃X�s�[�h
    float E_AirSpeed;

    float E_Air_Flg;

    
public:

    //�R���X�g���N�^
    EnemyBird();
    // �f�X�g���N�^
    ~EnemyBird();
    // �X�V��������������
    void Update(int playerx, int playery);
    // �`�揈������������
    void Draw() const;
    //�n�ʂɗ�������
    void Stand_Foot();

    int  Balloon_Anim(void);

    int Stand_by_Anim();

    int E_GetLocationX();

    int E_GetLocationY();

    int Return_MoveX();

    int Return_MoveY();

    void Chase();
};

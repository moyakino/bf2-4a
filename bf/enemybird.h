#pragma once

class EnemyBird {
private:
    int x, y;
    int my;
    int hp;
    int cnt;


public:
    int E_ArrayImg[18];
    int E_ArrayImg1[18];
    int E_ArrayImg2[18];

    //�����Ă����Ԃ̃t���O
    int		E_Stand_Flg;
    //�C�ɗ��������Ԃ̃t���O
    int		E_Foll_Flg;

    float	sx1, sy1, sx2, sy2;

    float	ex1, ey1, ex2, ey2, p_uc;

    //�R���X�g���N�^
    EnemyBird();
    // �f�X�g���N�^
    ~EnemyBird();
    // �X�V��������������
    void Update(int playerx,int playery);
    // �`�揈������������
    void Draw() const;

    int Stand_by_Anim();
};

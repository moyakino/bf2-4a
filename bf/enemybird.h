#pragma once
class EnemyBird {
private:
    int x, y;
    int my;
    int hp;


public:
    int E_ArrayImg[19];


    //�R���X�g���N�^
    EnemyBird();
    // �f�X�g���N�^
    ~EnemyBird();
    // �X�V��������������
    void Update();
    // �`�揈������������
    void Draw() const;
};

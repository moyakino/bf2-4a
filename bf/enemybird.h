#pragma once
class EnemyBird {
private:
    int x, y;
    int my;
    int hp;
    bool Attack();
    bool isAttack;
public:

    //�R���X�g���N�^
    EnemyBird();

    // �f�X�g���N�^
    ~EnemyBird();

    // �X�V��������������
    void Update();

    // �`�揈������������
    void Draw() const;

    bool Attack();

    bool Damage(int damage);
};

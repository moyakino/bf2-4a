#pragma once
class EnemyBird {
private:
    bool Attack();

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

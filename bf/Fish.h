#pragma once
class Fish {
private:
  int  Fish_ArrayImg[9];
  int Fish_Img = 0;
  int i = 0;

public:

    //�R���X�g���N�^
    Fish();

    // �f�X�g���N�^
    ~Fish();

    // �X�V��������������
    void Update();

    // �`�揈������������
    void Draw() const;

    int Fish_Anim();
};

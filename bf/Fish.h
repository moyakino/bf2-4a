#pragma once

#define FISH_0 0
#define FISH_1 1
#define FISH_2 2
#define FISH_3 3
#define FISH_4 4
#define FISH_5 5

class Fish {
private:
  int  Fish_ArrayImg[9];
  int fx1;
  int fy1;
  int fx2;
  int fy2;
  int	F_Seconds2;
  int F_AnimImg ;
  int Fish_Img;
  int f_fps;
  int ChengeImg;
  int FishEatP_flg;
  //�v���C���[���W
  float PlayerX;
  float PlayerY;

public:

    //�R���X�g���N�^
    Fish();

    // �f�X�g���N�^
    ~Fish();

    // �X�V��������������
    void Update(int x, int y);

    // �`�揈������������
    void Draw() const;

    void Fish_NAnim();
};

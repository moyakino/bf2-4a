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
  //プレイヤー座標
  float PlayerX;
  float PlayerY;

public:

    //コンストラクタ
    Fish();

    // デストラクタ
    ~Fish();

    // 更新処理を実装する
    void Update(int x, int y);

    // 描画処理を実装する
    void Draw() const;

    void Fish_NAnim();
};

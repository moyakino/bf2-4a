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
  int i = 0;
  int	F_Seconas1;
  int F_AnimImg = 0;
  int Fish_Img = 0;
  int f_fps;
 

public:

    //コンストラクタ
    Fish();

    // デストラクタ
    ~Fish();

    // 更新処理を実装する
    void Update();

    // 描画処理を実装する
    void Draw() const;

    int Fish_Anim();
};

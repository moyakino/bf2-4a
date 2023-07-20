#pragma once
class Fish {
private:
  int  Fish_ArrayImg[9];
  int Fish_Img = 0;
  int i = 0;

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

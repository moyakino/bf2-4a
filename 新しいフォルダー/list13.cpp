#include <stdio.h>
#include <math.h>

//fps
#define FPS (60)

//秒
#define SECOND(_sec)    ((_sec) * FPS)

#define M(_m)       (_m)

#define M_S(_speed)     (M(_speed) / SECOND(1.0f))

#define M_S2(_acc)      (M(_acc) / (SECOND(1.0f) * SECOND(1.0f)))

typedef struct {
    float x, y;
} Point;

typedef struct {
    float x, y;
} Vector;

//（座標）+（ベクトル）
Point Add_Point_Vector(Point p, Vector v) {
    Point r;
    r.x = p.x + v.x;
    r.y = p.y + v.y;
    return r;
}

//（ベクトル）+（ベクトル）
Vector Add_Vector_Vector(Vector v0, Vector v1) {
    Vector r;
    r.x = v0.x + v1.x;
    r.y = v0.y + v1.y;
    return r;
}

//（ベクトル）×（スカラー）
Vector Mul_Vector_Scalar(Vector v, float s) {
    Vector r;
    r.x = v.x * s;
    r.y = v.y * s;
    return r;
}

//ベクトルの長さを獲得
float Vector_Length(Vector v) {
    float l = sqrtf(v.x * v.x + v.y * v.y);
    return l;
}

//ベクトルを正規化
Vector Vector_Normalize(Vector v) {
    float l = Vector_Length(v);
    Vector n;
    n.x = v.x / l;
    n.y = v.y / l;
    return n;
}

//ベクトルの長さを設定
Vector Vector_SetLength(Vector v, float length) {
    v = Vector_Normalize(v);
    v = Mul_Vector_Scalar(v, length);
    return v;
}

 //移動処理 1次元
 void Move(float *pos, float *speed, float acceleration) {
     //加速度の影響を速度に与える
     *(speed) += acceleration;

     //速度の影響を座標に与える
     *(pos) += *(speed);
 }

//移動処理 2次元
void Move(Point* pos, Vector* speed, Vector acceleration) {
    //加速度の影響を速度に与える
    *(speed) = Add_Vector_Vector(*(speed), acceleration);

    //速度の影響を座標に与える
    *(pos) = Add_Point_Vector(*(pos), *(speed));
}

int main(void) {
     //リスト7.13 ベクトルに速度と加速度をつける
     //ベクトルに速度（30 m/s）を設定
     Vector vec_speed;
     vec_speed.x = 1.0f;
     vec_speed.y = 1.0f;
     vec_speed = Vector_SetLength(vec_speed, M_S(30.0f));
     printf("30 m/s -> (%f, %f)\n", vec_speed.x, vec_speed.y);

     //ベクトルに加速度（2 m/s^2）を設定
     Vector vec_acc;
     vec_acc.x = 1.0f;
     vec_acc.y = 1.0f;
     vec_acc = Vector_SetLength(vec_acc, M_S2(2.0f));
     printf("2 m/s^2 -> (%f, %f)\n", vec_acc.x, vec_acc.y);

    return 0;
}
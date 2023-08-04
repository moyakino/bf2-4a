#include <stdio.h>
#include <math.h>

//fps
#define FPS (60)

//�b
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

//�i���W�j+�i�x�N�g���j
Point Add_Point_Vector(Point p, Vector v) {
    Point r;
    r.x = p.x + v.x;
    r.y = p.y + v.y;
    return r;
}

//�i�x�N�g���j+�i�x�N�g���j
Vector Add_Vector_Vector(Vector v0, Vector v1) {
    Vector r;
    r.x = v0.x + v1.x;
    r.y = v0.y + v1.y;
    return r;
}

//�i�x�N�g���j�~�i�X�J���[�j
Vector Mul_Vector_Scalar(Vector v, float s) {
    Vector r;
    r.x = v.x * s;
    r.y = v.y * s;
    return r;
}

//�x�N�g���̒������l��
float Vector_Length(Vector v) {
    float l = sqrtf(v.x * v.x + v.y * v.y);
    return l;
}

//�x�N�g���𐳋K��
Vector Vector_Normalize(Vector v) {
    float l = Vector_Length(v);
    Vector n;
    n.x = v.x / l;
    n.y = v.y / l;
    return n;
}

//�x�N�g���̒�����ݒ�
Vector Vector_SetLength(Vector v, float length) {
    v = Vector_Normalize(v);
    v = Mul_Vector_Scalar(v, length);
    return v;
}

 //�ړ����� 1����
 void Move(float *pos, float *speed, float acceleration) {
     //�����x�̉e���𑬓x�ɗ^����
     *(speed) += acceleration;

     //���x�̉e�������W�ɗ^����
     *(pos) += *(speed);
 }

//�ړ����� 2����
void Move(Point* pos, Vector* speed, Vector acceleration) {
    //�����x�̉e���𑬓x�ɗ^����
    *(speed) = Add_Vector_Vector(*(speed), acceleration);

    //���x�̉e�������W�ɗ^����
    *(pos) = Add_Point_Vector(*(pos), *(speed));
}

int main(void) {
     //���X�g7.13 �x�N�g���ɑ��x�Ɖ����x������
     //�x�N�g���ɑ��x�i30 m/s�j��ݒ�
     Vector vec_speed;
     vec_speed.x = 1.0f;
     vec_speed.y = 1.0f;
     vec_speed = Vector_SetLength(vec_speed, M_S(30.0f));
     printf("30 m/s -> (%f, %f)\n", vec_speed.x, vec_speed.y);

     //�x�N�g���ɉ����x�i2 m/s^2�j��ݒ�
     Vector vec_acc;
     vec_acc.x = 1.0f;
     vec_acc.y = 1.0f;
     vec_acc = Vector_SetLength(vec_acc, M_S2(2.0f));
     printf("2 m/s^2 -> (%f, %f)\n", vec_acc.x, vec_acc.y);

    return 0;
}
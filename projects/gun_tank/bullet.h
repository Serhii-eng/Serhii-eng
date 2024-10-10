#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

typedef struct Bullet{
    double x, y;
    double speedV, speedH;
    char symbol;
} Bullet;

Bullet createBullet(double y, double x, double speed, double angle, char c);

void runBullet(Bullet *b, double dt);

#endif // BULLET_H_INCLUDED

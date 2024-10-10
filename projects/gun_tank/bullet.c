#include "common.h"
#include "bullet.h"
#include <math.h>

#define PI 3.1415926

Bullet createBullet(double y, double x, double speed, double angle, char c){
    Bullet b;
    b.y = y;
    b.x = x;
    double rad = angle * PI / 180.0;
    b.speedH = speed * cos(rad);
    b.speedV = speed * sin(rad);
    b.symbol = c;
    return b;
}

void runBullet(Bullet *b, double dt){
    b->x += b->speedH*dt;
    b->y += b->speedV*dt;
    b->speedV -= G*dt;
}

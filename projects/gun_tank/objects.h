#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

#include "viewport.h"
#include "bullet.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

//typedef enum Types {GUN, TANK} Types;

typedef struct Gun{
    double x, y;
    double width, high;
    char symbol;
} Gun;

typedef struct Tank{
    double x, y;
    double width, high;
    char** matrix_tank;
    double conf_life_tank;
    double life;
    char symbol;
} Tank;

Gun createGun(double y, double x, double high, double width, char c);
Tank createTank(ViewPort *vp, double y, double x, double high, double width, double life, char c);
void putTankToMatrix(ViewPort *vp, Tank *t);
void gunToViewPort(ViewPort *vp, Gun *g);
void tankToViewPort(ViewPort *vp, Tank *t);
bool checkTankDamage(ViewPort *vp, Bullet *b, Tank *t);
bool isEndOfGame(ViewPort *vp, Gun *g, Bullet *b1, Tank *t, double x_text, double y_text);
void enterData(ViewPort *vp, Bullet *b1, Tank *t, double x_data, double y_data);
void freeObjTank(ViewPort *vp, Tank *t);


#endif // OBJECTS_H_INCLUDED

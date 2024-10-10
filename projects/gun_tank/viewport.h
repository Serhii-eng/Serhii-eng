#ifndef VIEWPORT_H_INCLUDED
#define VIEWPORT_H_INCLUDED

#include "objects.h"
#include "bullet.h"

typedef struct ViewPort{
    int H, W;
    double WorldH, WorldW;
    char** current_cadr;
    char** cadr1;
    char** cadr2;
    double kx, ky;
} ViewPort;

ViewPort createViewPort(int H, int W, double WorldH, double WorldW);
void clearCadrSeparate(ViewPort *vp);
void clearCadr(char** cadr, int m, int n);
void charToViewPort(ViewPort *vp, double WorldY, double WorldX, char c);
void showViewPort(ViewPort *vp);
void freeViewPort(ViewPort *vp);
void swapCadr(ViewPort *vp);

#endif // VIEWPORT_H_INCLUDED

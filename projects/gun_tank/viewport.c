#include "common.h"
#include "objects.h"
#include "viewport.h"
#include <stdio.h>
#include <stdlib.h>

char** createCharMatrix(int m, int n){
    char** matr = (char**) malloc(sizeof(char*) * m);
    for (int i=0; i<m; i++){
        matr[i] = (char*) malloc(sizeof(char) * n);
    }

    clearCadr(matr, m, n);
    return matr;
}

void clearCadr(char** cadr, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cadr[i][j] = 32;
        }
    }
}

void clearCadrSeparate(ViewPort *vp){
    for (int i=0; i < vp->H; i++){
        for (int j=0; j < vp->W; j++){
            vp->current_cadr[i][j] = 32;
        }
    }
}

void removeCharMatrix(char **matr, int m){
    for (int i=0; i<m; i++) free(matr[i]);
    free(matr);
}

ViewPort createViewPort(int H, int W, double WorldH, double WorldW){
    ViewPort vp;
    vp.H = H;
    vp.W = W;
    vp.WorldH = WorldH;
    vp.WorldW = WorldW;
    vp.cadr1 = createCharMatrix(H, W);
    vp.cadr2 = createCharMatrix(H, W);
    vp.current_cadr = vp.cadr1;
    vp.ky = H/WorldH;
    vp.kx = W/WorldW;
    return vp;
}

void charToViewPort(ViewPort *vp, double WorldY, double WorldX, char c){
    if (WorldY < 0 || WorldY >= vp->WorldH) return;
    if (WorldX < 0 || WorldX >= vp->WorldW) return;
    int y = floor(WorldY * vp->ky);
    int x = floor(WorldX * vp->kx);
    //clearCadr(vp->current_cadr, vp->H, vp->W); чистимо кадр в мейні
    vp->current_cadr[y][x] = c;
}


void showFrame(ViewPort *vp){
    int m = vp->H;
    int n = vp->W;
    setCur(0, 0); putchar('+');
    for (int j=0; j<n; j++){
        putchar('-');
    }
    putchar('+');

    for (int i=0; i<m; i++){
        setCur(i+1, 0); putchar('|');
        setCur(i+1, n+1); putchar('|');
    }

    setCur(m+1, 0); putchar('+');
    for (int j=0; j<n; j++){
        putchar('-');
    }
    putchar('+');
}

void showViewPort(ViewPort *vp){
    int m = vp->H;
    int n = vp->W;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (vp->cadr1[m-i-1][j] != vp->cadr2[m-i-1][j]){
                setCur(i+1, j+1);
                putchar(vp->current_cadr[m-i-1][j]);
                vp->cadr1[m-i-1][j] = vp->current_cadr[m-i-1][j];
                vp->cadr2[m-i-1][j] = vp->current_cadr[m-i-1][j];
            }
        }
    }
    setCur(m+1, n);
}

void freeViewPort(ViewPort *vp){
    removeCharMatrix(vp->cadr1, vp->H);
    removeCharMatrix(vp->cadr2, vp->H);
    vp->cadr1 = NULL;
    vp->cadr2 = NULL;
    vp->current_cadr = NULL;
}

void swapCadr(ViewPort *vp){
    if (vp->current_cadr == vp->cadr1){
        vp->current_cadr = vp->cadr2; //було прирівнювання ==
    }
    else {
        vp->current_cadr = vp->cadr1; // було прирівнювання ==
    }
    clearCadr(vp->current_cadr, vp->H, vp->W);
}







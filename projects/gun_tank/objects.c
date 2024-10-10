#include "objects.h"
#include <windows.h>


Gun createGun(double y, double x, double high, double width, char c){
    Gun g;

    g.y = y;
    g.x = x;
    g.width = width;
    g.high = high;
    g.symbol = c;
    return g;
}


Tank createTank(ViewPort *vp, double y, double x, double high, double width, double life, char c)
{
    Tank t;

    t.y = y;
    t.x = x;
    t.width = width;
    t.high = high;

    int h = floor(t.high * vp->ky);
    int w = floor(t.width * vp->kx);
    t.matrix_tank = createCharMatrix(h, w);

    double ky1, kx1;
    kx1 = vp->kx;
    ky1 = vp->ky;

    t.symbol = c;
    putTankToMatrix(vp, &t);

    t.life = (life > 100) ? 100 : life;

    t.conf_life_tank = 100.0 / (h*w); //100 максимальне життя яке може бути в танка.

    return t;
}


void putTankToMatrix(ViewPort *vp, Tank *t)
{
    int h = floor(t->high * vp->ky);
    int w = floor(t->width * vp->kx);

    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            char v = t->symbol;
            v = 0;
            v = t->symbol;
            t->matrix_tank[j][i] = t->symbol;
        }
    }
}


void gunToViewPort(ViewPort *vp, Gun *g){
    if (g->y < 0 || g->y >= vp->WorldH) return;
    if (g->x < 0 || g->x >= vp->WorldW) return;
    if ((g->y + g->high) < 0 || (g->y + g->high) >= vp->WorldH) return;
    if ((g->x + g->width) < 0 || (g->x + g->width) >= vp->WorldW) return;
    int y = floor(g->y * vp->ky);
    int x = floor(g->x * vp->kx);
    int h = floor(g->high * vp->ky);
    int w = floor(g->width * vp->kx);

    int tmp_point_X = x;
    int tmp_point_Y = y+2;

    for(int i = (w + x)-1; i >= x; i--)
    {
        vp->current_cadr[tmp_point_Y][tmp_point_X] = g->symbol;
        tmp_point_X++;
        tmp_point_Y++;
    }

    for(int i = x; i < (w + x); i++)
        for(int j = y + (h/2)-1; j < h + y; j++)
            vp->current_cadr[j][i] = g->symbol;
}


void tankToViewPort(ViewPort *vp, Tank *t)
{
    if (t->y < 0 || t->y >= vp->WorldH) return;
    if (t->x < 0 || t->x >= vp->WorldW) return;
    if ((t->y + t->high) < 0 || (t->y + t->high) >= vp->WorldH) return;
    if ((t->x + t->width) < 0 || (t->x + t->width) >= vp->WorldW) return;

    int y = floor(t->y * vp->ky);
    int x = floor(t->x * vp->kx);
    int h = floor(t->high * vp->ky);
    int w = floor(t->width * vp->kx);

    int tmp_X = 0;
    int tmp_Y = 0;
    for(int i = x; i < x+w; i++)
    {
        for(int j = y; j < y+h; j++)
        {
            vp->current_cadr[j][i] = t->matrix_tank[tmp_Y][tmp_X];
            tmp_Y++;
        }
        tmp_Y = 0;
        tmp_X++;
    }
}


bool isEndOfGame(ViewPort *vp, Gun *g, Bullet *b1, Tank *t, double x_text, double y_text)
{
    if (x_text < 0 || x_text >= vp->WorldW) return;
    if (y_text < 0 || y_text >= vp->WorldH) return;
    int x = floor(x_text * vp->kx);
    int y = vp->H - floor(y_text * vp->ky);

    setCur(y, x);
    printf("Press 'Space' to continium game or 'Escape' for exit");

    while(true)
    {
        if(GetKeyState(VK_ESCAPE) < 0)
        {
            setCur(y, x);
            printf("                                                    ");

            return true;
        }

        if(GetKeyState(VK_SPACE) < 0)
        {
            setCur(y, x);
            printf("                                                    ");

            *vp = createViewPort(25, 80, 3000, 8000); //перше ар. був 25.
            *b1 = createBullet(500, 400, 240, 50, '*'); //225start y500 x400 130, 70.
            *g = createGun(100, 100, 300, 300, '@');
            *t = createTank(vp, 0, 6000, 600, 1200, 2, '#'); //якщо 100 то танк має бути знищений повністю
            return false;
        }
    }
}


void removeBulletFromScreen(ViewPort *vp, Bullet *b)
{
    charToViewPort(vp, b->y, b->x, ' ');
}


void enterData(ViewPort *vp, Bullet *b1, Tank *t, double x_data, double y_data)
{
    if (x_data < 0 || x_data >= vp->WorldW) return;
    if (y_data < 0 || y_data >= vp->WorldH) return;
    int x = floor(x_data * vp->kx);
    int y = vp->H - floor(y_data * vp->ky);

    showcursor();
    //ShowCursor(TRUE);

    setCur(y-2, x-7);
    printf("Speed:       ");
    setCur(y-1, x-7);
    printf("Angle:       ");
    setCur(y, x-7);
    printf("Life:  %.1lf", t->life);

    double angle, speed;
    setCur(y-2, x);
    scanf("%lf", &speed);
    setCur(y-1, x);
    scanf("%lf", &angle);
    *b1 = createBullet(500, 400, speed, angle, '*');

    hidecursor();
}


bool checkTankDamage(ViewPort *vp, Bullet *b, Tank *t)
{
    if (t->y < 0 || t->y >= vp->WorldH) return;
    if (t->x < 0 || t->x >= vp->WorldW) return;
    if ((t->y + t->high) < 0 || (t->y + t->high) >= vp->WorldH) return;
    if ((t->x + t->width) < 0 || (t->x + t->width) >= vp->WorldW) return;

    int b_y = floor(b->y * vp->ky);
    int b_x = floor(b->x * vp->kx);

    int y = floor(t->y * vp->ky);
    int x = floor(t->x * vp->kx);
    int h = floor(t->high * vp->ky);
    int w = floor(t->width * vp->kx);

    int tmp_X = 0;
    int tmp_Y = 0;
    if(b_x+1 > x && b_y < y + h && b_x < x+w && b_y >= y)
    {
        if(t->matrix_tank[b_y - y][b_x-x] == t->symbol)
        {
            t->matrix_tank[b_y - y][b_x-x] = 32;
            return true;
            //exit(1);
        }
    }
    return false;

}


void freeObjTank(ViewPort *vp, Tank *t)
{
     removeCharMatrix(t->matrix_tank, vp->H);
     t->matrix_tank = NULL;
}

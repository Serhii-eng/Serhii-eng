#include "objects.h"
#include "common.h"
#include "bullet.h"
#include "viewport.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>



int main()
{
    ViewPort vp = createViewPort(25, 80, 3000, 8000); //перше ар. був 25.
    Bullet b1 = createBullet(500, 400, 240, 50, '*'); //225start y500 x400 130, 70.
    Gun g = createGun(100, 100, 300, 300, '@');
    Tank t = createTank(&vp, 0, 6000, 600, 1200, 2, '#'); //якщо 100 то танк має бути знищений повністю

    while(true)
    {
        double remember_life = t.life;
        double remember_high = t.high;
        double remember_width = t.width;

        showFrame(&vp);

        tankToViewPort(&vp, &t);
        charToViewPort(&vp, b1.y, b1.x, b1.symbol);
        gunToViewPort(&vp, &g);
        showViewPort(&vp);

        while(t.life > 0)
        {
            enterData(&vp, &b1, &t, 1000, 2400);  //функція вводу.

            setCur(1, 1);
            printf("Fly ");

            bool damage = false;
            while(true)
            {
                runBullet(&b1, 0.2);
                damage = checkTankDamage(&vp, &b1, &t);

                swapCadr(&vp);
                tankToViewPort(&vp, &t);
                charToViewPort(&vp, b1.y, b1.x, b1.symbol);
                gunToViewPort(&vp, &g);

                showViewPort(&vp);

                if(b1.y <= 0) break;
                if(damage) break;

                Sleep(10);
            }

            removeBulletFromScreen(&vp, &b1);
            showViewPort(&vp);

            setCur(1, 1);
            printf("Stop");

            if(damage) t.life -= t.conf_life_tank;
        }

        remember_life += 1; //додаємо 15 відсотків до життя танка, таким чином танк буде тяжче зруйнувати.
        remember_high -= 3000 / 25; //зменшуємо висоту танка на один рядок.
        remember_width -= 8000 / 80; //зменшуємо ширину танка на один стовбець.

        t = createTank(&vp, 0, 6000, remember_high, remember_width, remember_life, '#');
        b1 = createBullet(500, 400, 0, 0, '*');

        swapCadr(&vp);
        removeBulletFromScreen(&vp, &b1);

        if((remember_high < 3000 / 25) || (remember_width < 8000 / 80)) // якщо танк знищений
            if(isEndOfGame(&vp, &g, &b1, &t, 1800, 1500)) break;    //Кінець гри, чи продовжуємо?
    }

    freeViewPort(&vp);
    freeObjTank(&vp, &t);
    exit(0);
}

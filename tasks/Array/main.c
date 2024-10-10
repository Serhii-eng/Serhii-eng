#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define PI 3.1415926535

//my favorite programm
int main()
{
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);

    srand(t);

    Array141();
    return 0;
}

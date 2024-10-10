#include "matr.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);
    srand(132);

    void matr100();
    matr100();

    return 0;
}


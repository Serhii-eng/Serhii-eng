#include <stdio.h>
#include <stdlib.h>

void int30();

int main()
{
    int H = 1;
    int M = 7;
    int S = 3;

    printf("%03d:%05d:%02d\n", H, M, S);

    int30();
    return 0;
}

void int30()
{
    int Y;
    printf(" Y = "); scanf("%d", &Y);

    int C_c = (Y - 1)  / 100 +1;

    printf(" C_c = %d\n", C_c);
}

void int29()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int Num_of_C = (A / C) * (B / C); //кол. квадратов со стороной С в прямоугольнике.
    int t_S_C = Num_of_C * C * C; //Общая площадь квадратов со стороной С в прямоугольнике.
    int r_S = (A * B) - t_S_C; //Незаполненая площадь квадратами С в прямоугольниве.

    printf(" Count_C = %d\n", Num_of_C);
    printf(" unfulfilled area in a rectangle = %d\n", r_S);
}

void int28()
{
    int D, N;
    printf(" D = "); scanf("%d", &D);
    printf(" N = "); scanf("%d", &N);

    int DW = ((D + N-1) % 7) +1;

    printf(" DW = %d\n", DW);
}

void int27()
{
    int D;
    printf(" D = "); scanf("%d", &D);

    int DW = ((D + 5) % 7) +1;

    printf(" DW = %d\n", DW);
}


void int26()
{
    int D;
    printf(" D = "); scanf("%d", &D);

    int DW = ((D + 1) % 7) +1;

    printf(" DW = %d\n", DW);
}


void int25()
{
    int D;
    printf(" D = "); scanf("%d", &D);

    int DW = (D + 3) % 7;

    printf(" DW = %d\n", DW);
}

void int24()
{
    int D;
    printf(" D = "); scanf("%d", &D);

    int DW = D % 7  ;

    printf(" DW = %d\n", DW);
}

void int23()
{
    int N;
    printf(" N = "); scanf("%d", &N);

    int M = N % (60 * 60) / 60;

    printf(" M = %d\n", M);
}

void int22()
{
    int N;
    printf(" N = "); scanf("%d", &N);

    int S = N % (60 * 60);

    printf(" S = %d\n", S);
}

void int21()
{
    int N;
    printf(" N = "); scanf("%d", &N);

    int S = N % 60;

    printf(" S = %d\n", S);
}

void int20()
{
    int N;
    printf(" N = "); scanf("%d", &N);

    int H = N / (60*60);

    printf(" H = %d\n", H);
}

void int19()
{
    int N;
    printf(" N = "); scanf("%d", &N);

    int S = N / 60;

    printf(" S = %d\n", S);
}


void int18()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d3 = d / 1000 % 10;

    printf(" d3 = %d\n", d3);
}


void int17()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d2 = d / 100 % 10;

    printf(" d2 = %d\n", d2);
}

void int16()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d0 = d / 1 % 10;
    int d1 = d / 10 % 10;
    int d2 = d / 100 % 10;

    int D = d2 * 100 + d0 * 10 + d1 * 1;

    printf(" D = %d\n", D);
}

void int15()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d0 = d / 1 % 10;
    int d1 = d / 10 % 10;
    int d2 = d / 100 % 10;

    int D = d1 * 100 + d2 * 10 + d0 * 1;

    printf(" D = %d\n", D);
}

void int14()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d0 = d / 1 % 10;
    int d1 = d / 10 % 10;
    int d2 = d / 100 % 10;

    int D = d0 * 100 + d2 * 10 + d1 * 1;

    printf(" D = %d\n", D);
}

void int13()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d0 = d / 1 % 10;
    int d1 = d / 10 % 10;
    int d2 = d / 100 % 10;

    int D = d1 * 100 + d0 * 10 + d2 * 1;

    printf(" D = %d\n", D);
}

void int12()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d0 = d / 1 % 10;
    int d1 = d / 10 % 10;
    int d2 = d / 100 % 10;

    int D = d0 * 100 + d1 * 10 + d2 * 1;

    printf(" D = %d\n", D);
}

void int11()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d0 = d / 1 % 10;
    int d1 = d / 10 % 10;
    int d2 = d / 100 % 10;

    int S = d0 + d1 + d2;
    int M = d0 * d1 * d2;

    printf(" S = %d\n", S);
    printf(" M = %d\n", M);
}

void int10()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d1 = d / 10 % 10;
    int d0 = d / 1 % 10;
    int D = d0 * 10 + d1 * 1;

    printf(" D = %d\n", D);
}

void int09()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    d /= 100;

    printf(" d = %d\n", d);

}

void int08()
{
    int d;
    printf(" d = "); scanf("%d", &d);

    int d0 = d / 1 % 10;
    int d1 = d / 10 % 10;
    int D = d0 *10 + d1 * 1;

    printf(" D = %d\n", D);
}

void int07()
{
    int D;
    printf(" D = "); scanf("%d", &D);

    int d1 = D / 10 % 10;
    int d0 = D / 1 % 10;
    int S = d0 + d1;
    int M = d0 * d1;

    printf(" S = %d\n", S);
    printf(" M = %d\n", M);

}void int06()
{
    int D;
    printf(" D = "); scanf("%d", &D);

    int d0 = D / 1 % 10;
    int d1 = D / 10 % 10;

    printf(" d0 = %d\n", d0);
    printf(" d1 = %d\n", d1);
}

void int05()
{
    int A, B;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);

    int Count = A % B;

    printf(" Count = %d\n", Count);
}

void int04()
{
    int A, B;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);

    int Count = A / B;

    printf(" Count = %d\n", Count);
}

void int03()
{
    int B;
    printf(" B = "); scanf("%d", &B);

    B/=1024;

    printf(" kB = %d\n", B);
}

void int02()
{
    int M;
    printf(" M = "); scanf("%d", &M);

    M/=1000;

    printf(" M_tonn = %d\n", M);
}

void int01()
{
    int L;
    printf(" L = "); scanf("%d", &L);

    L/=100;

    printf(" L_meter = %d\n", L);
}

void int00()
{
    int x;
    printf(" x = "); scanf("%d", &x); // x = 1234
    // 1 * 10^3 + 2 * 10^2 + 3 * 10^1 + 4 * 10^0
    int d0 = x / 1 % 10; // 4
    int d1 = x / 10 % 10; // 3
    int d2 = x / 100 % 10; // 2
    int d3 = x / 1000 % 10; // 1

    int y = d0*1000 + d1*100 + d2*10 + d3*1;
    printf(" y = %d\n", y);
}

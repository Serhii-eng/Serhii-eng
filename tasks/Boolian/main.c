#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main()
{
    void bool_40();
    bool_40();
    return 0;
}

void bool_40()
{

    int x1, y1, x2, y2;
    printf(" x1 = "); scanf("%d", &x1);
    printf(" y1 = "); scanf("%d", &y1);
    printf(" x2 = "); scanf("%d", &x2);
    printf(" y2 = "); scanf("%d", &y2);


    int ok = (abs(x1 - x2) == 1 &&  abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 &&  abs(y1 - y2) == 1);

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_39()
{

    int x1, y1, x2, y2;
    printf(" x1 = "); scanf("%d", &x1);
    printf(" y1 = "); scanf("%d", &y1);
    printf(" x2 = "); scanf("%d", &x2);
    printf(" y2 = "); scanf("%d", &y2);


    int ok = abs(x1 - x2) == abs(y1 - y2) || (x1 == x2) || (y1 == y2);

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_38()
{
    int x1, y1, x2, y2;
    printf(" x1 = "); scanf("%d", &x1);
    printf(" y1 = "); scanf("%d", &y1);
    printf(" x2 = "); scanf("%d", &x2);
    printf(" y2 = "); scanf("%d", &y2);

    int ok = abs(x1 - x2) == abs(y1 - y2);

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_37()
{

    int x1, y1, x2, y2;
    printf(" x1 = "); scanf("%d", &x1);
    printf(" y1 = "); scanf("%d", &y1);
    printf(" x2 = "); scanf("%d", &x2);
    printf(" y2 = "); scanf("%d", &y2);


    //int ok = ((x2 <= x1+1) && (x2 >= x1-1)) && ((y2 <= y1 + 1) && (y2 >= y1-1));
    int ok = abs(x1 - x2) < 2 && abs(y1 - y2) < 2;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_36()
{

    int x1, y1, x2, y2;
    printf(" x1 = "); scanf("%d", &x1);
    printf(" y1 = "); scanf("%d", &y1);
    printf(" x2 = "); scanf("%d", &x2);
    printf(" y2 = "); scanf("%d", &y2);


    int ok = x1 == x2 || y1 == y2;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_35()
{

    int x1, y1, x2, y2;
    printf(" x1 = "); scanf("%d", &x1);
    printf(" y1 = "); scanf("%d", &y1);
    printf(" x2 = "); scanf("%d", &x2);
    printf(" y2 = "); scanf("%d", &y2);


    int ok = (x1 + y1) % 2 == (x2 + y2) % 2;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_34()
{

    int a, b;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);


    int ok = (a + b) % 2 != 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_33()
{

    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    int ok = (a + b > c) && (a + c > b) && (b + c > a); // Со скобками читабельней.

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_32()
{
    // 7, 24, 25. 3 4 5  6 8 10
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    int ok = (a*a==b*b+c*c) || (b*b==a*a+c*c) || (c*c==a*a+b*b);

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_31()
{
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    int ok = a == b || b == c || a == c;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_30()
{
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    int ok = a == b && b == c;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_29()
{
    double x, y, x1, y1, x2, y2;
    printf(" x = "); scanf("%lf", &x);
    printf(" y = "); scanf("%lf", &y);
    printf(" x1 = "); scanf("%lf", &x1);
    printf(" y1 = "); scanf("%lf", &y1);
    printf(" x2 = "); scanf("%lf", &x2);
    printf(" y2 = "); scanf("%lf", &y2);

    int ok = (x1 <= x && x <= x2) && (y1 >= y && y >= y2);

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_28()
{
    double x, y;
    printf(" x = "); scanf("%lf", &x);
    printf(" y = "); scanf("%lf", &y);

    //int ok = x > 0 && y > 0 || x < 0 && y < 0;
    int ok = x * y > 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_27()
{
    double x, y;
    printf(" x = "); scanf("%lf", &x);
    printf(" y = "); scanf("%lf", &y);

    int ok = x < 0 && y != 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_26()
{
    double x, y;
    printf(" x = "); scanf("%lf", &x);
    printf(" y = "); scanf("%lf", &y);

    int ok = x < 0 && y > 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_25()
{
    double x, y;
    printf(" x = "); scanf("%lf", &x);
    printf(" y = "); scanf("%lf", &y);

    int ok = x > 0 && y < 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_24()
{
    double A, B, C;
    printf(" A = "); scanf("%lf", &A);
    printf(" B = "); scanf("%lf", &B);
    printf(" C = "); scanf("%lf", &C);

    double D = B * B - 4 * A * C;

    int ok = D >= 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_23()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int d0 = A / 1 % 10;
    int d1 = A / 10 % 10;
    int d2 = A / 100 % 10;
    int d3 = A / 1000 % 10;

    int ok = d0 == d3 && d1 == d2;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_22()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int d0 = A / 1 % 10;
    int d1 = A / 10 % 10;
    int d2 = A / 100 % 10;

    int ok = d0 > d1 && d1 > d2 || d0 < d1 && d1 < d2 ;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_21()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int d0 = A / 1 % 10;
    int d1 = A / 10 % 10;
    int d2 = A / 100 % 10;

    int ok = d0 > d1 && d1 > d2;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_20()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int d0 = A / 1 % 10;
    int d1 = A / 10 % 10;
    int d2 = A / 100 % 10;

    int ok = d0 != d1 && d1 != d2 && d0 != d2;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_19()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int ok = A == -B || B == -C || A == -C;

    printf(" Exactly one number is positive of A, B, C is positive = %s\n", ok ? "true": "false");
}

void bool_18()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int ok = A == B || B == C || A == C;

    printf(" Exactly one number is positive of A, B, C is positive = %s\n", ok ? "true": "false");
}

void bool_17()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int ok = ((A / 10) != 0) && ((A / 10) < 10) && ((A % 2) == 0);

    printf(" Exactly one number is positive of A, B, C is positive = %s\n", ok ? "true": "false");
}

void bool_16()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int ok = 10 <= A && A <= 99 && A % 2 == 0;

    printf(" Exactly one number is positive of A, B, C is positive = %s\n", ok ? "true": "false");
}


void bool_15()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int ok = ((A > 0) + (B > 0) + (C > 0)) == 2;

    printf(" Exactly one number is positive of A, B, C is positive = %s\n", ok ? "true": "false");
}


void bool_14()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int ok = ((A > 0) + (B > 0) + (C > 0)) == 1;

    printf(" Exactly one number is positive of A, B, C is positive = %s\n", ok ? "true": "false");
}

void bool_13()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int ok = A > 0 || B > 0 || C > 0;

    printf(" At least one number of A, B, C is positive = %s\n", ok ? "true": "false");
}

void bool_12()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int ok = A > 0 && B > 0 && C > 0;

    printf(" A, B, C is positive = %s\n", ok ? "true": "false");
}

void bool_11()
{
    int A, B;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);

    int ok = A % 2 == B % 2;

    printf(" A and B even numbers = %s\n", ok ? "true": "false");
}

void bool_10()
{
    int A, B;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);

    int ok = A % 2 != B % 2;

    //int ok = ((A%2!=0) && (B%2==0) )||((A%2==0) && (B%2!=0) );//ok = (A % 2) ^ (B % 2);

    printf(" A or B odd number = %s\n", ok ? "true": "false");
}

void bool_9()
{
    int A, B;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);

    int ok = A % 2 || B % 2;

    printf(" A or B odd number = %s\n", ok ? "true": "false");
}


void bool_8()
{
    int A, B;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);

    int ok = A % 2 != 0 && B % 2 != 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_7()
{
    int A, B, C;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);
    printf(" C = "); scanf("%d", &C);

    int ok = A < B && B < C || C < B && B < A;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_6()
{
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    int ok = a < b && b < c;

    printf(" ok = %s\n", ok ? "true": "false");

}

void bool_5()
{
    int A, B;
    printf(" A = "); scanf("%d", &A);
    printf(" B = "); scanf("%d", &B);

    int ok = A >= 0 || B < -2;

    printf(" ok = %s\n", ok ? "true": "false");

}

void bool_4()
{
    int a, b;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);

    int ok = a > 2 && b <= 3;

    printf(" ok = %s\n", ok ? "true": "false");

}

void bool_3()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int ok = A % 2 == 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_2()
{
    int A;
    printf(" A = "); scanf("%d", &A);

    int ok = A % 2 != 0;

    printf(" ok = %s\n", ok ? "true": "false");
}

void bool_1()
{
    int a;
    printf(" a = "); scanf("%d", &a);

    int ok = a > 0;

    printf(" ok = %s\n", ok ? "true": "false");

}



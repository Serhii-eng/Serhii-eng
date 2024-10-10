#include <stdio.h>
#include <stdlib.h>

int main()
{
    void if_30();
    if_30();

    return 0;
}

void if_30()
{
   int n;
   printf(" n = "); scanf("%d", &n);

   if ((n % 2) == 0) printf("positive ");
   else printf("negative ");
   if (n > 99) printf("three-digit ");
   else if ((99 >= n) && (n > 9)) printf("two-digit ");
   else if (n <= 9) printf("one-digit ");
}

void if_29()
{
    int n;
    printf(" n = "); scanf("%d", &n);

    if(n == 0) printf("zero" );
    else
    {
       if(n > 0) printf("positive ");
       else printf("negative ");
       if ((n % 2) == 0) printf("even ");
       else printf("not even ");
    }
}


void if_28()
{
    int year;
    printf(" year = "); scanf("%d", &year);

    int f =365;

    if(year % 4 == 0)
    {
        f = 366;
        if(year % 100 == 0 && year % 400 != 0)
        {
            f = 365;
        }
    }
    printf(" f = %d\n", f);
}

void if_27() /////////?
{
    double x;
    printf(" x = "); scanf("%lf", &x);

    int f = 0;
    if(x >= 0)
    {
        int y = x;
        if(y % 2 == 0) f = 1;
        if(y % 2 != 0) f = -1;
    }




   /* int f;

    if(x < 0)
    {
        f = 0;
    }
    else if(((int)x % 2) == 0)
    {
        f = 1;
    }
    else
    {
        f = -1;
    } */
    printf(" f = %d\n", f);
}

void if_26()
{
    double x;
    printf(" x = "); scanf("%lf", &x);

    double f = x * x;
    if(x <= 0) f = -x;
    if(x >= 2) f = 4;

    printf(" f = %lf\n", f);
}


void if_25()
{
    int x;
    printf(" x = "); scanf("%d", &x);

    int f = -3 * x;
    if(x < -2 || x > 2) f = 2 * x;

    printf(" f = %d\n", f);
}



void if_24()
{
    double x;
    printf(" x = "); scanf("%lf", &x);

    double f = 6 - x;
    if(x > 0) f = 2 * sin(x);

    printf(" f = %lf\n", f);
}


void if_23()
{
    int x1, x2, x3, y1, y2, y3;
    printf(" x1 = "); scanf("%d", &x1);
    printf(" y1 = "); scanf("%d", &y1);
    printf(" x2 = "); scanf("%d", &x2);
    printf(" y2 = "); scanf("%d", &y2);
    printf(" x3 = "); scanf("%d", &x3);
    printf(" y3 = "); scanf("%d", &y3);

    int x4 = x1;
    if(x1 == x3) x4 = x2;
    if(x1 == x2) x4 = x3;

    int y4 = y1;
    if(y1 == y3) y4 = y2;
    if(y1 == y2) y4 = y3;


    printf("\n");
    printf(" x4 = %d\n", x4);
    printf(" y4 = %d\n", y4);

   /* if((x1 == x2) && (y1 == y3))
    {
        printf("\n");
        printf(" x4 = %d\n", x3);
        printf(" y4 = %d\n", y2);
    }
    else if((x1 == x3) && (y1 == y2))
    {
        printf("\n");
        printf(" x4 = %d\n", x2);
        printf(" y4 = %d\n", y3);
    }*/

}

void if_22()
{
    double OX, OY;
    printf(" OX = "); scanf("%lf", &OX);
    printf(" OY = "); scanf("%lf", &OY);

    if(OX > 0 && OY > 0)
    {
        printf(" 1\n");
    }
    else if(OX < 0 && OY > 0)
    {
        printf(" 2\n");
    }
    else if(OX < 0 && OY < 0)
    {
        printf(" 3\n");
    }
    else
    {
        printf(" 4\n");
    }
}

void if_21()
{
    int OX, OY;
    printf(" OX = "); scanf("%d", &OX);
    printf(" OY = "); scanf("%d", &OY);

    if(OX == 0 && OY == 0)
    {
        printf(" 0\n");
    }
    else if(OX != 0 && OY == 0)
    {
        printf(" 1\n");
    }
    else if(OX == 0 && OY != 0)
    {
        printf(" 2\n");
    }
    else
    {
        printf(" 3\n");
    }
}

void if_20()
{
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    if(abs(a - b) < abs(a - c))
    {
        printf(" b %d\n", abs(a - b));
    }
    else
    {
        printf(" c %d\n", abs(a - c));
    }
}

void if_19()
{
    int a, b, c, d;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);
    printf(" d = "); scanf("%d", &d);

    if((a < b && b == c && c == d) || (a > b && b == c && c == d))
    {
        printf(" 1\n");
    }
    if((b < a && a == c && c == d) || (b > a && a == c && c == d))
    {
        printf(" 2\n");
    }
    if((c < a && a == b && b == d) || (c > a && a == b && b == d))
    {
        printf(" 3\n");
    }
    if((d < a && a == b && b == c) || (d > a && a == b && b == c))
    {
        printf(" 4\n");
    }
}

void if_18()
{
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    if((a < b && b == c) || (a > b && b == c))
    {
        printf(" 1\n");
    }
    if((b < a && a == c) || (b > a && a == c))
    {
        printf(" 2\n");
    }
    if((c < b && a == b) || (c > b && a == b))
    {
        printf(" 3\n");
    }
}

void if_17()
{
    double a, b, c;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);
    printf(" c = "); scanf("%lf", &c);

    if((a < b && b < c) || (a > b && b > c))
    {
        a *= 2;
        b *= 2;
        c *= 2;

        printf(" a * 2 = %lf\n", a);
        printf(" b * 2 = %lf\n", b);
        printf(" c * 2 = %lf\n", c);
    }
    else
    {
        a *= -1;
        b *= -1;
        c *= -1;

        printf(" a * (-1) = %lf\n", a);
        printf(" b * (-1) = %lf\n", b);
        printf(" c * (-1) = %lf\n", c);
    }

}

void if_16()
{
    double a, b, c;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);
    printf(" c = "); scanf("%lf", &c);

    /////////////////
    if(a < b && b < c)
    {
        a *= 2;
        b *= 2;
        c *= 2;

        printf(" a * 2 = %lf\n", a);
        printf(" b * 2 = %lf\n", b);
        printf(" c * 2 = %lf\n", c);
    }
    else
    {
        a *= -1;
        b *= -1;
        c *= -1;

        printf(" a * (-1) = %lf\n", a);
        printf(" b * (-1) = %lf\n", b);
        printf(" c * (-1) = %lf\n", c);
    }

}

void if_15()
{
    double a, b, c;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);
    printf(" c = "); scanf("%lf", &c);

    /////////////////
    if(a < b && a < c)
    {
        printf(" b + c =  %lf\n", b + c);
    }
    if(b < a && b < c)
    {
        printf(" a + c =  %lf\n", a + c);
    }
    if(c < b && c < a)
    {
        printf(" b + a =  %lf\n", b + a);
    }
}

void if_14()
{
    double a, b, c;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);
    printf(" c = "); scanf("%lf", &c);

    /////////////////
    if(a < b && a < c)
    {
        printf(" a\n");
    }
    if(b < a && b < c)
    {
        printf(" b\n");
    }
    if(c < b && c < a)
    {
        printf(" c\n");
    }

    /////////////////////////
    if(a > b && a > c)
    {
        printf(" a\n");
    }
    if(b > a && b > c)
    {
        printf(" b\n");
    }
    if(c > b && c > a)
    {
        printf(" c\n");
    }
}

void if_13_a()////////////////////
{
    double a, b, c;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);
    printf(" c = "); scanf("%lf", &c);

    double min = a;
    if(b < min) min = b;
    if(c < min) min = c;

    double max = a;
    if(b > max) max = b;
    if(c > max) max = c;

    double mid = a + b + c - min - max;
    printf(" mid = %lf\n", mid);
}

void if_13()///////////////
{
    double a, b, c;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);
    printf(" c = "); scanf("%lf", &c);

    double mid = a;
    if(a < b && b < c || c < b && b < a) mid = b;
    if(a < c && c < b || b < c && c < a) mid = c;

    printf(" mid = %lf\n", mid);

    /*
    if((a > b && a < c) || (a < b && a > c))
    {
        printf(" a\n");
    }
    if((b > a && b < c) || (b < a && b > c))
    {
        printf(" b\n");
    }
    if((c > b && c < a) || (c < b && c > a))
    {
        printf(" c\n");
    }
    */
}

void if_12()
{
    double a, b, c, d, e;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);
    printf(" c = "); scanf("%lf", &c);
    printf(" d = "); scanf("%lf", &d);
    printf(" e = "); scanf("%lf", &e);

    double min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    if(d < min) min = d;
    if(e < min) min = e;

    printf(" min = %d\n", min);

    /*
    if(a > b && a > c)
    {
        printf(" a\n");
    }
    if(b > a && b > c)
    {
        printf(" b\n");
    }
    if(c > b && c > a)
    {
        printf(" c\n");
    }
    */
}

void if_11()
{
    int a, b;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);

    if(a > b)
    {
        b = a;

        printf(" %d %d\n", a, b);
    }
    else if(a < b)
    {
        a = b;

        printf(" %d %d\n", a, b);
    }
    else
    {
        a = 0;
        b = 0;

        printf(" %d %d\n", a, b);
    }
}

void if_10()
{
    int a, b;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);

    if(a != b)
    {
        a = a + b;
        b = a;

        printf(" %d %d\n", a, b);
    }
    else
    {
        a = 0;
        b = 0;

        printf(" %d %d\n", a, b);
    }
}

void if_09()//
{
    double a, b;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);

    if(a > b)
    {
        double c;
        c = a;
        a = b;
        b = c;

        printf(" %lf %lf\n", a, b);
    }
    else
    {
        printf(" %lf %lf\n", a, b);
    }
}

void if_08()//
{
    int a, b;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);

    if(a > b)
    {
        printf(" %d %d\n", a, b);
    }
    if(b > a)
    {
        printf(" %d %d\n", b, a);
    }
}

void if_07()//
{
    int a, b;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);

    if(a < b)
    {
        printf(" %d\n", 1);
    }
    else
    {
        printf(" %d\n", 2);
    }
}

void if_06()
{
    int a, b;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);

    if(a > b)
    {
        printf(" a > b\n");
    }
    else
    {
        printf(" b > a\n");
    }
}

void if_05()
{
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    int count_p_n = 0;
    int count_n_n = 0;
    if(a > 0)
    {
        count_p_n++;
    }
    else
    {
        count_n_n++;
    }
    if(b > 0)
    {
        count_p_n++;
    }
    else
    {
        count_n_n++;
    }
    if(c > 0)
    {
        count_p_n++;
    }
    else
    {
        count_n_n++;
    }

    printf(" count_p_n = %d\n", count_p_n);
    printf(" count_n_n = %d\n", count_n_n);
}

void if_04()
{
    int a, b, c;
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);
    printf(" c = "); scanf("%d", &c);

    int count_p_n = 0;

    if(a > 0)
    {
        count_p_n++;
    }
    if(b > 0)
    {
        count_p_n++;
    }
    if(c > 0)
    {
        count_p_n++;
    }

    printf(" count_p_n = %d\n", count_p_n);
}

void if_03()
{
    double a;
    printf(" a = "); scanf("%lf", &a);

    if(a > 0)
    {
        a++;
    }
    else if(a < 0)
    {
        a -= 2;
    }
    else
    {
        a = 10;
    }

    printf(" a = %lf\n", a);
}

void if_02()
{
    double a;
    printf(" a = "); scanf("%lf", &a);

    if(a > 0)
    {
        a++;
    }
    else
    {
        a -= 2;
    }

    printf(" a = %lf\n", a);
}


void if_01()
{
    double a;
    printf(" a = "); scanf("%lf", &a);

    if(a > 0)
    {
        a++;
    }

    printf(" a = %lf\n", a);
}


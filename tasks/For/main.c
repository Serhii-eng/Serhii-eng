#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.14159265358979323846
int main()
{
    setlocale(LC_ALL, "UKR");
    system("chcp 1251 >> nul");
    void for_38();
    for_38();
    return 0;
}

void test()
{
    int x = 3;
    int y = x++;// y = 3; x = 4;

    x = 3;
    y = ++x; // x = 4; y = 4;
}


void for_40()
{
    int A, B;
    printf("A: ");   scanf("%i", &A);
    printf("B: ");   scanf("%i", &B);

    int count = 0;
    for(int i = A; i <= B; i++)
    {
        count++;
        for(int j = 0; j < count; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}


void for_39()
{
    int A, B;
    printf("A: ");   scanf("%i", &A);
    printf("B: ");   scanf("%i", &B);

    for(int i = A; i <= B; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}


void for_38()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    int pow = N;
    double rez = 0;
    for(int i = 1; i <= N; i++)
    {
        double mul = 1;
        for(int j = 0; j < pow; j++)
        {
           mul = mul * i;
        }
        pow--;
        rez = rez + mul;
    }
    printf("sum = %f\n", rez);

    return 0;

}



void for_37()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double rez = 0;
    for(int i = 1; i <= N; i++)
    {
        double mul = 1;
        for(int j = 0; j < i; j++)
        {
           mul = mul * i;
        }

        rez = rez + mul;
        printf("%f\n", rez);
    }

    return 0;

}


void for_36()
{
    int N, K;
    printf("N: ");   scanf("%i", &N);
    printf("K: ");   scanf("%i", &K);

    double rez = 0;
    for(int i = 1; i <= N; i++)
    {
       double mul = 1;
        for(int j = 0; j < K; j++)
        {
           mul = mul * i;
        }

        rez = rez + mul;
        printf("%f\n", rez);
    }

    return 0;

}


void for_35()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double A1 = 1.0;
    double A2 = 2.0;
    double A3 = 3.0;

    double A;
    for(int i = 4; i <= N; i++)
    {
        A = A3 + A2 - (2 * A1);
        printf("A%d = %f\n", i, A);
        A1 = A2;
        A2 = A3;
        A3 = A;
    }

    return 0;
}



void for_34()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double A1 = 1.0;
    double A2 = 2.0;
    double A;
    for(int i = 3; i <= N; i++)
    {
        A = (A1 + 2 * A2) / 3;
        printf("A%d = %f\n", i, A);
        A1 = A2;
        A2 = A;
    }

    return 0;
}



void for_33()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    int F1 = 1;
    int F2 = 1;
    int F;

    for(int i = 3; i <= N; i++)
    {
        F = F1 + F2;
        printf("F%d = %d\n", i, F);
        F1 = F2;
        F2 = F;
    }

    return 0;
}


void for_32()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    int K = 1;
    double A = 1;
    for(int i = 0; i < N; i++)
    {
        A = (A + 1) / K;
        printf("A%d = %f\n", K, A);
        K++;
    }

    return 0;
}


void for_31()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    int n = 1;
    double A = 2.0;
    for(int i = 0; i < N; i++)
    {
        A = 2 + 1.0 / A;
        printf("A%d = %.15lf\n", n, A);
        n++;
    }

    return 0;
}


void for_30()
{
    int N;
    double A, B;
    printf("A: ");   scanf("%lf", &A);
    printf("B: ");   scanf("%lf", &B);
    printf("N: ");   scanf("%d", &N);

    double H =(B - A) / N;
    double x = A;
    for(int i = 0; i <= N; i++)
    {
        double F = 1 - sin(x);
        printf("%lf; %lf \n", x, F);
        x = x + H;
    }

    return 0;
}



void for_29()
{
    int N;
    double A, B;
    printf("A: ");   scanf("%lf", &A);
    printf("B: ");   scanf("%lf", &B);
    printf("N: ");   scanf("%i", &N);

    double H =(B - A) / N;
    double X = A;
    for(int i = 0; i <= N; i++)
    {
        printf("X = %0.2f amount of points = %d\n", X, i + 1);
        X = X + H;
    }

    return 0;
}


void for_28()
{
    int N;
    double X;
    printf("X: ");   scanf("%lf", &X);
    printf("N: ");   scanf("%i", &N);

    double sum = 1 + (X / 2); //Сума ітерацій.
    double nom = 1; //Частина виразу яка множиться на X в степені в чисельнику.
    double den = 1; // Знаменник.
    double pow = X; // Х в степені.
    double sign = 1;
    int n = 1;
    for(int i = 0; i < N; i++)
    {
        sign = -sign;
        nom = nom * (2 * n - 1);
        pow = pow * X;
        den = den * 2 * n;
        sum = sum + (nom * pow) / (den * (2 * (n + 1))) * sign;
        n++;
    }

    printf("%f \n ", sqrt(X + 1));
    printf("%f \n ",sum);

    return 0;
}


void for_27()
{
    int N;
    double X;
    printf("X: ");   scanf("%lf", &X);
    printf("N: ");   scanf("%i", &N);

    double sum = X; //Сума ітерацій.
    double nom = 1; //Частина виразу яка множиться на X в степені в чисельнику.
    double den = 1; // Знаменник.
    double pow = X; // Х в степені.
    int n = 1;
    for(int i = 0; i < N; i++)
    {
        nom = nom * (2 * n - 1);
        pow = pow * X * X;
        den = den * 2 * n;
        sum = sum + (nom * pow) / (den * (2 * n + 1));
        n++;
    }

    printf("%f \n ", asin(X));
    printf("%f \n ",sum);

    return 0;
}


void for_26()
{
    int N;
    double X;
    printf("X: ");   scanf("%lf", &X);
    printf("N: ");   scanf("%i", &N);


    double sum = 0;
    double sign = 1;
    double nom = X; //Чисельник.
    double den = 1; // Знаменник.
    for(int i = 0; i < N; i++)
    {
        sum = sum + nom / den * sign;
        nom = nom * X * X;
        den = den + 2;
        sign = -sign;
    }

    printf("%f \n ", atan(X));
    printf("%f \n ",sum);

    return 0;

}


void for_25()
{
    int N;
    double X;
    printf("X: ");   scanf("%lf", &X);
    printf("N: ");   scanf("%i", &N);

    double sum = 0;
    double sign = 1;
    double nom = X; //Чисельник.
    double den = 1; // Знаменник.

    for(int i = 0; i < N; i++)
    {
        sum = sum + nom / den * sign;
        nom = nom * X;
        sign = -sign;
        den++;
    }

    printf("%f \n ",log(1 + X));
    printf("%f \n ",sum);

    return 0;
}


void for_24()
{
    int N;
    double X;
    printf("X: ");   scanf("%lf", &X);
    printf("N: ");   scanf("%i", &N);

    X = fmod(X, 2 * PI);
    double sum = 0;
    double sign = 1;
    double nom = 1; //Чисельник.
    double den = 1; // Знаменник.
    double m = 1;

    for(int i = 0; i < N; i++)
    {
        sum = sum + nom / den * sign;
        sign = -sign;
        nom = nom * X * X;
        den = den * m * (m + 1);
        m += 2;
    }

    printf("%f \n ",cos(X));
    printf("%f \n ",sum);

    return 0;
}


void for_23() //???? Незрозуміла умова.
{
    int N;
    double X;
    printf("X: ");   scanf("%lf", &X);
    printf("N: ");   scanf("%i", &N);


    double sum = 0;
    double sign = 1;
    double nom = X; //Чисельник.
    double den = 1; // Знаменник.
    double m = 2;
    for(int i = 0; i < N; i++)
    {
        sum = sum + nom / den * sign;
        nom = nom * X * X;
        den = den * m * (m + 1);
        m = m + 2;

        sign = -sign;
    }

    printf("%f \n ",sin(X));
    printf("%f \n ",sum);

    return 0;
}


void for_22()
{
    int N;
    double X;
    printf("X: ");   scanf("%lf", &X);
    printf("N: ");   scanf("%i", &N);

    double rez = 1;
    double sum = 1 + X;
    double pow = X;

    for (int i = 2; i <= N; i++)
    {
       X *= pow;
       rez *= (double)i;
       sum += (X / rez);
       printf("sum: %lf\n", sum);
    }
}

void for_21()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double rez = 1;
    double sum = 1;

    for (int i = 1; i <= N; i++)
    {
       rez *= (double)i;
       sum += 1 / rez;
       printf("sum: %lf\n", sum);
    }
}

void for_20()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double rez = 1;
    double sum = 0;

    for (int i = 1; i <= N; i++)
    {
       rez *= (double)i;
       sum += rez;
       printf("sum: %lf\n", sum);
    }
}

void for_19()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double rez = 1;

    for (int i = 1; i <= N; i++)
    {
       rez *= (double)i;
       printf("rez: %lf\n", rez);
    }
}

void for_18()
{
    int N;
    double A;
    printf("A: ");   scanf("%lf", &A);
    printf("N: ");   scanf("%i", &N);

    int neg = -1;
    double rez = 1 + A * neg;
    double deg = A;


    for (int i = 1; i < N; i++)
    {
       deg *= A;
       rez += deg;
       printf("rez: %lf\n", rez);
       deg *= neg;
    }
}

void for_17()
{
    int N;
    double A;
    printf("A: ");   scanf("%lf", &A);
    printf("N: ");   scanf("%i", &N);

    double rez = 1 + A;
    double deg = A;

    for (int i = 1; i < N; i++)
    {
       deg *= A;
       rez += deg;
       printf("rez: %lf\n", rez);
    }
}

void for_16()
{
    int N;
    double A;
    printf("A: ");   scanf("%lf", &A);
    printf("N: ");   scanf("%i", &N);

    double rez = A;
    for (int i = 1; i < N; i++)
    {
       rez *= A;
       printf("rez: %lf\n", rez);
    }
}

void for_15()
{
    int N;
    double A;
    printf("A: ");   scanf("%lf", &A);
    printf("N: ");   scanf("%i", &N);

    double rez = A;
    for (int i = 1; i < N; i++)
    {
       rez *= A;
    }\

    printf("rez: %lf\n", rez);
}

void for_14()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    int rez = 0;
    for (int i = 1; i <= (2 * N - 1); i+=2)
    {
       rez += i;
       printf("rez: %i\n", rez);
    }

}

void for_13()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double rez = 0;
    double x = 1.1;
    double sign = 1;
    for (int i = 0; i <= N; i++)
    {
       rez += x * sign;
       x = x + 0.1;
       sign = -sign;//Чередування знаків. (+ -)
    }

    printf("rez: %i\n", rez);
}

void for_12()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double rez = 1;
    double x = 1.1;
    for (int i = 0; i <= N; i++)
    {
       rez *= x ;
       x = x + 0.1;
    }

    printf("rez: %i\n", rez);
}


void for_11()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    int sum = 0;
    for (int i = 0; i <= N; i++)
    {
        sum += (N + i) * (N + i);
    }

    printf("res: %i\n", sum);

    return 0;
}

void for_10()
{
    int N;
    printf("N: ");   scanf("%i", &N);

    double res = 0;
    for (int i = 1; i <= N; i++)
    {
        res += 1.0 / (double)i;
    }

    printf("res: %lf\n", res);

    return 0;
}

void for_09()
{
    int A, B;
    printf("A: ");   scanf ("%i", &A);
    printf("B: ");   scanf ("%i", &B);


    int res = 0;
    for (int i = A; i <= B; i++)
    {
        res += i * i;
    }

    printf("res: %i\n", res);

    return 0;
}

void for_08()
{
    int A, B;
    printf("A: ");   scanf ("%i", &A);
    printf("B: ");   scanf ("%i", &B);


    int mul = 1;
    for (int i = A; i <= B; i++)
    {
        mul *= i;
    }

    printf("mul: %i\n", mul);

    return 0;
}

void for_07()
{
    int A, B;
    printf("A:");   scanf ("%i", &A);
    printf("B:");   scanf ("%i", &B);


    int sum = 0;
    for (int i = A; i <= B; i++)
    {
        sum += i;
    }

    printf("sum: %i\n", sum);

    return 0;
}

void for_06()
{
    double price;
    printf("price: ");  scanf ("%lf", &price);

    double  weight = 1.2;
    for (int i = 0; i < 5; i++)
    {
        double cost = weight * price;
        printf("%.3lf kg: $%.2lf\n", weight, cost);
        weight += 0.2;
    }
}

void for_05()
{
    double price;
    printf("price: ");   scanf ("%lf", &price);

    double  weight = 0.1;
    for (int i = 0; i < 10; i++)
    {
        double cost = weight * price;
        printf("%.3lf kg: $%.2lf\n", weight, cost);
        weight += 0.1;
    }

}

void for_04()
{
    double A;
    printf("A:");   scanf ("%lf", &A);

    double a = A;
    for (int i = 1; i <= 10; i++)
    {
        printf("A: %lf\n", a);
        a = a + A;
    }
    return 0;
}

void for_03()
{
    int A, B;

    printf("A:");   scanf ("%i", &A);
    printf("B:");   scanf ("%i", &B);

    int cnt = 0;
    for  (int i = B-1; i > A; i--)
    {
        printf("%i\n", i);
        cnt++;
    }
    printf("cnt: %i\n", cnt);
    return 0;
}

void for_02()
{
    int A, B;

    printf("A:");   scanf ("%i", &A);
    printf("B:");   scanf ("%i", &B);

    int cnt = 0;
    for  (int i = A; i <= B; i++)
    {
        printf("%i\n", i);
        cnt++;
    }
    printf("cnt: %i\n", cnt);
    return 0;
}

void for_01()
{
    int K, N;
    printf(" Число К = ");  scanf("%i", &K);
    printf(" N раз = ");    scanf("%i", &N);

    for(int i = 0; i < N; i++)
    {
        printf("%i\n", K);
    }
    return 0;
}

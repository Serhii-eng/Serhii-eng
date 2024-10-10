#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.1415926535
int main()
{
    void while_30a();
    while_30a();
    return 0;
}


void while_30a()
{
    int A, B, C;
    printf("A: ");  scanf("%i", &A);
    printf("B: ");  scanf("%i", &B);
    printf("C: ");  scanf("%i", &C);

    int a = 0;
    while(A >= C)
    {
        a++;
        A -= C;
    }

    int b = 0;
    while(B >= C)
    {
        b++;
        B -= C;
    }

    int count = 0;
    while(a > 0)
    {
        count += b;
        a--;
    }

    printf("number of squeres = %i", count);
    return 0;
}


void while_30()
{
    int A, B, C;
    printf("A: ");  scanf("%i", &A);
    printf("B: ");  scanf("%i", &B);
    printf("C: ");  scanf("%i", &C);

    int count = 0;
    int temp = 0;
    while (A >= C)
    {
        A = A - C;

        temp = B;
        while(temp >= C)
        {
            temp = temp - C;
            count++;
        }
    }

    printf("number of squeres = %i", count);
    return 0;
}


void while_29() //Епсілон, це число яким вимірюється погрішність?
{
    double e;
    printf("e: ");  scanf("%lf", &e);

    double A = 1;
    double A1 = 2;
    double A2;
    int K = 1;
    while ( fabs(A - A1) >= e)
    {
        K++;
        A2 = A1;
        A1 = A;
        A = (A2 + 2 * A1) / 3;
        printf("A_K-1 = %lf A_K = %lf K = %i\n", A1, A, K);
    }

    printf("A_K-1 = %lf A_K = %lf K = %i", A1, A, K);
    return 0;
}


void while_28a() //Епсілон, це число яким вимірюється погрішність?
{
    double e;
    printf("e: ");  scanf("%lf", &e);

    double A = 2;
    int K = 1;
    double dif = 0;
    printf("A%d = %lf\n", K, A);
    while (1)
    {
        K++;
        double A1 = A;
        A = 2 + 1 / A1;
        printf("A%d = %lf\n", K, A);
        dif = fabs(A - A1);
        if(dif < e) break;
    }
    printf("dif = %.15lf\n", dif);

    return 0;
}


void while_28() //Епсілон, це число яким вимірюється погрішність?
{
    double e;
    printf("e: ");  scanf("%lf", &e);

    double A = 2, A1 = 0, buf = 0;
    int K = 1;
    while ( fabs(A - A1) >= e)
    {
        K++;
        A1 = A;
        A = 2 + 1 / A1;
    }

    printf("A_K = %lf, A_K-1 = %lf, K = %i", A, A1, K);
    return 0;
}


void while_27()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int F = 0, F1 = 1, F2 = 1;
    int K = 2;
    while(F < N)
    {
       F = F1 + F2;
       F1 = F2;
       F2 = F;
       K++;
    }

    printf("K = %i", K);
    return 0;
}


void while_26()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int F = 0, F1 = 1, F2 = 1;
    int buf;
    while(F <= N)
    {
       buf = F1;
       F = F1 + F2;
       F1 = F2;
       F2 = F;
    }

    printf("F_K-1 = %i, F_K+1 = %i", buf, F);
    return 0;
}


void while_25()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int F = 0, F1 = 1, F2 = 1;
    while(F <= N)
    {
       F = F1 + F2;
       F1 = F2;
       F2 = F;
    }

    printf("F_K+1 = %i", F);
    return 0;
}


void while_24a()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int F = 0, F1 = 1, F2 = 1;
    while(F < N)
    {
       F = F1 + F2;
       F1 = F2;
       F2 = F;
    }
    bool ok = F == N;
    printf("N is number Fibonachi - %s", ok ? "true" : "false");
    return 0;
}


void while_24()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int F = 0, F1 = 1, F2 = 1;
    int K = 3;
    bool f_or_t = false;
    while(F <= N)
    {
       F = F1 + F2;
       if(F == N) f_or_t = true;
       F1 = F2;
       F2 = F;
       K++;
    }

    printf("N is number Fibonachi - %s", f_or_t ? "true" : "false");
    return 0;
}


void while_23a()
{
    int A, B;
    printf("A: ");  scanf("%d", &A);
    printf("B: ");  scanf("%d", &B);

    A = abs(A);
    B = abs(B);

    while(A != B)
    {
        if(A > B)
        {
            A = A - B;
        }
        else
        {
            B = B - A;
        }
    }

    printf("NOD: %d", A);
    return 0;
}



void while_23()
{
    int A, B;
    printf("A: ");  scanf("%i", &A);
    printf("B: ");  scanf("%i", &B);

    if(A < B)
    {
       A = A + B;
       B = A - B;
       A = A - B;
    }

    int rez = 1;
    while(rez != 0)
    {
        rez = A % B;
        A = B;
        B = rez;
    }

    printf("NOD: %i", A);
    return 0;
}


void while_22()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int k = 2;
    bool ok = true;
    int n = sqrt(N) + 1;

    while(k <= n)
    {
        if(n % k == 0)
        {
            ok = false;
            break;
        }
        k++;
    }

    printf("%d is prime - %s.", N, ok  ? "true" : "false");
    return 0;
}


void while_21() //if(d % 2 > 1) як порівняти?
{
    int N;
    printf("N: ");  scanf("%i", &N);

    bool t_or_f = false;
    int mul = 1;
    int d = 0;
    while(mul <= N)
    {
        d = ((N / mul ) % 10);
        mul = mul * 10;
        if(d % 2) t_or_f = true;
    }

    printf("Digit two in number - is %s.", t_or_f ? "true" : "false");
    return 0;
}


void while_20()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    bool ok = false;
    int mul = 1;
    int d = 0;
    while(mul <= N)
    {
        d = ((N / mul ) % 10);
        mul = mul * 10;
        if(d == 2)
        {
             ok = true;
             break;
        }
    }

    printf("Digit two number - is %s.", ok ? "true" : "false");
    return 0;
}


void while_19a()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int n = N;
    int S = 0;
    while(n != 0)
    {
        int D = n % 10;
        S = S * 10 + D;
        n = n / 10;
    }
    printf("\nS = %d \n", S);
    return 0;
}


void while_19()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int count = 0;
    int mul = 1;
    int s = 0;
    while(mul <= N)
    {
        s = s * 10;
        s = s + ((N / mul ) % 10);
        mul = mul * 10;
        count++;
    }

    printf("Turn number = %d", s);
    return 0;
}


void while_18a()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int n = N;
    int K = 0;
    int S = 0;
    while(n != 0)
    {
        int D = n % 10;
        S += D;
        K++;
        printf("%d ", D);
        n = n / 10;
    }
    printf("\nS = %d  K = %d ", S, K);
    return 0;
}


void while_18()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int count = 0;
    int mul = 1;
    int s = 0;
    while(mul <= N)
    {
        s = s + ((N / mul ) % 10);
        mul = mul * 10;
        count++;
    }

    printf(" Sum = %d, Count = %d ", s, count);
    return 0;
}


void while_17a()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int n = N;
    while(n != 0)
    {
        int D = n % 10;
        printf("%d ", D);
        n = n / 10;
    }

    return 0;
}


void while_17()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int mul = 1;
    int D = 0;
    while(mul <= N)
    {
        D = (N / mul ) % 10;
        mul = mul * 10;
        printf("%d ", D);
    }

    return 0;
}


void while_16()
{
    double P;
    printf("0 < 50 < P: ");  scanf("%lf", &P);

    int K = 0;
    double day = 10;
    double total_way = 0;
    while(total_way < 200)
    {
        K++;
        total_way += day;
        printf("K = %d, day = %lf, total_way = %f\n", K, day, total_way);
        day = day + day*P/100;
    }
    return 0;
}


void while_15()
{
    double P;
    double money, want;

    printf("money: ");  scanf("%lf", &money);
    printf("0 < 25 < P: ");  scanf("%lf", &P);
    printf("want: ");  scanf("%lf", &want);

    int monthes = 0;

    while(money < want)
    {
        monthes++;
        money = money + money * (P / 100);
    }

    printf("years = %lf, money = %f\n", monthes / 12.0, money);
    return 0;
}



void while_14()
{
    double A;
    printf("A: ");  scanf("%lf", &A);

    double K = 0;
    double rez = 0;
    while((K + 1) < A)
    {
        K++;
        rez = rez + (1 / K);
    }

    printf("K = %f, rez = %f\n", K, rez);
    return 0;
}


void while_13()
{
    double A;
    printf("A: ");  scanf("%lf", &A);

    double K = 0;
    double rez = 0;
    while(rez <= A)
    {
        K++;
        rez = rez + (1 / K);
    }

    printf("K = %f, rez = %f\n", K, rez);
    return 0;
}


void while_12()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int K = 1;
    double rez = 0;
    while(rez + K <= N)
    {
        rez = rez + K;
        K++;
    }

    printf("K = %f", rez);
    return 0;
}


void while_11()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int K = 1;
    double rez = 0;
    while(rez < N)
    {
        rez = rez + K;
        K++;
    }

    printf("K = %f", rez);
    return 0;
}


void while_10()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    double K = 1;
    do
    {
        K = K * 3;
    }
    while(K * 3 <= N);

    printf("K = %f", K);
    return 0;
}


void while_09()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    double K = 1;
    while(K < N)
    {
        K = K * 3;
    }

    printf("K = %f", K);
    return 0;
}


void while_08()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int K = 0;
    while(K * K < N)
    {
        K++;
    }
    K--;
    printf("K = %f", K);
    return 0;
}


void while_07()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int K = 0;
    while(K * K <= N)
    {
        K++;
    }

    printf("K = %f", K);
    return 0;
}


void while_06()
{
    int N;
    printf("N: ");  scanf("%i", &N);


    double rez = 1;
    while(N >= 2)
    {
        rez = rez * N;
        N = N - 2;
    }

    printf("2 factorial = %f", rez);
    return 0;
}

void while_06a()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int K = 0;
    double rez = 1;
    while(K < N)
    {
        rez = rez * (N - K);
        K = K + 2;
    }

    printf("2 factorial = %f", rez);
    return 0;
}

void while_05()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int K = 0;
    int count = 0;
    while(N > 1)
    {

        N = N / 2;
        K++;
    }

    printf("2 pow = %d", K);
    return 0;
}

// 81 = 1 * 3 * 3 * 3 * 3
void while_04()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    bool ans = true;
    while(N > 1)
    {
       if(N % 3 != 0)
       {
           ans = false;
           break;
       }
       N = N / 3;
    }

    printf("False");
    return 0;
}


void while_03()
{
    int N, K;
    printf("N: ");  scanf("%i", &N);
    printf("K: ");  scanf("%i", &K);

    int count = 0;
    while(N > K)
    {
        N = N - K;
        count++;
    }

    printf("%d count, %d change", count, N);
    return 0;
}


void while_01_02()
{
    double A, B;
    printf("A: ");  scanf("%i", &A);
    printf("B: ");  scanf("%i", &B);

    int count = 0;
    while(A >= B)
    {
        A = A - B;
        count++;
    }

    printf("%d count, %lf change", count, A);
    return 0;
}




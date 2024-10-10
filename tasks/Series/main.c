#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define PI 3.1415926535

int main()
{
    srand(time(NULL)); //функція для генерації рандомних чисел.
    void series_07();
    series_07();

    return 0;
}


series_30() //Діапазон випадкових цілих чисел.
{
    int from = -10;
    int to = 21;
    int K, N;
    printf("K: ");  scanf("%d", &K);
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    for(int i = 0; i < K; i++)
    {
        int sum = 0;
        for(int j = 0; j < N; j++)
        {
            int n = from + rand() % (to - from);
            printf("%d ", n);
            sum = sum + n;
        }

        printf("        sum: %d\n", sum);
    }
}


series_29()
{
    int K, N;
    printf("K: ");  scanf("%d", &K);
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int n;
    int i = 0;
    int sum = 0;
    while(i < K)
    {

        for(int j = 0; j < N; j++)
        {
            printf("n: ");  scanf("%d", &n);
            sum = sum + n;
        }
        i++;
        printf("\n");

    }
    printf("sum: %d\n\n", sum);
}


series_28()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    double n;
    int i = 0;
    double mul = 1;
    while(i < N)
    {
        printf("n: ");  scanf("%lf", &n);

        for(int j = i; j < N; j++)
        {
           mul = mul * n;
        }
        i++;

        printf("mul: %lf\n\n", mul);
        mul = 1;
    }
}


series_27()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    double n;
    int i = 0;
    double mul = 1;
    while(i < N)
    {
        printf("n: ");  scanf("%lf", &n);

        i++;
        for(int j = 0; j < i; j++)
        {
           mul = mul * n;
        }

        printf("mul: %lf\n\n", mul);
        mul = 1;
    }
}


series_26()
{
    int K, N;
    printf("K: ");  scanf("%d", &K);
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    double n;
    int i = 0;
    double mul = 1;
    while(i < N)
    {
        printf("n: ");  scanf("%lf", &n);


        for(int i = 0; i < K; i++)
        {
           mul = mul * n;
        }
        i++;

        printf("mul: %lf\n\n", mul);
        mul = 1;

    }
}


series_25()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int n;
    int i = 0;
    int sum = 0;
    int temp = 0;
    bool ok = false;
    while(i < N)
    {
        printf("n: ");  scanf("%d", &n);


        if( n == 0 && ok == false)
        {
            ok = true;
        }
        else if( n != 0 && ok == true)
        {
            temp = temp + n;
        }
        else if(n == 0 && ok == true)
        {
            sum = sum + temp;
            temp = 0;
        }
        i++;

    }
    printf("\nsumma: %d", sum);
}



series_24()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int n;
    int i = 0;
    int sum = 0;
    bool ok = false;
    while(i < N)
    {
        printf("n: ");  scanf("%d", &n);

        if( n == 0 && ok == false)
        {
            ok = true;
        }
        else if( n != 0 && ok == true)
        {
            sum = sum + n;
        }
        else
        {
            ok = false;
        }

        i++;
    }
    printf("\nsumma: %d", sum);
}



series_23()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int i = 1;
    double n, n1, n2;
    double numb = 0;
    while(i <= N)
    {
        n2 = n1;
        n1 = n;
        printf("n: ");  scanf("%lf", &n);

        if(n2 == n1 && n1 == n && i % 3 == 0)
        {
            numb = n;
            break;
        }
        else if(n2 != n && n1 == n && i % 3 == 0)
        {
            numb = n1;
            break;
        }
        else if(n2 != n1 && n1 != n && i % 3 == 0)
        {
            numb = n2;
            break;
        }

        i++;
    }
    printf("\nnumber: %.2lf", numb);
}


series_22()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int i = 0;
    double n, n1;
    double numb = 0;
    while(i < N)
    {
        n1 = n;
        printf("n: ");  scanf("%lf", &n);

        if(n > n1 && i > 0)
        {
            numb = n;
            break;
        }
        i++;
    }
    printf("\nnumber: %.2lf", numb);
}


series_21()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int i = 0;
    double n, n1;
    bool ok = true;
    while(i < N)
    {
        n1 = n;
        printf("n: ");  scanf("%lf", &n);

        if(n < n1 && i > 0)
        {
            ok = false;
        }
        i++;
    }
    printf("\nok: %s", ok ? "true" : "false");
}



series_20()
{

    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int i = 0;
    int n, n1;
    int K = 0;
    while(i < N)
    {
        n1 = n;
        printf("n: ");  scanf("%d", &n);

        if(n > n1 && i > 0)
        {
            printf("%d\n", n1);
            K++;
        }
        i++;
    }
    printf("\nK: %d", K);
}


series_19()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int i = 0;
    int n, n1;
    int K  = 0;
    while(i < N)
    {
        n1 = n;
        printf("n: ");  scanf("%d", &n);

        if(n < n1 && i > 0)
        {
           printf("%d\n", n);
           K++;
        }
        i++;
    }
    printf("\nK: %d", K);
}


series_18()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int i = 0;
    int n, n1;
    while(i < N)
    {
        n1 = n;
        printf("n: ");  scanf("%d", &n);

        if(n != n1 && i > 0) printf("%d\n", n1);
        if(i == N - 1) printf("%d\n", n);
        i++;
    }
}


series_17()
{
    double B;
    int N;
    printf("B: ");  scanf("%lf", &B);
    printf("N: ");  scanf("%d", &N);
    printf("\n");
    int i = 0;
    double n;
    bool t_or_f = false;
    while(i < N)
    {

        printf("n: ");  scanf("%lf", &n);

        if(n >= B && t_or_f == false)
        {
            printf("\nB = %lf\n", B);
            t_or_f = true;
        }
        if(n < B && i == N - 1 && t_or_f == false)
        {
            printf("n%d = %lf\n", i, n);
            printf("B = %lf\n", B);
            break;
        }
        i++;
        printf("n%d = %lf\n", i, n);
    }
}


series_16()
{
    int K;
    printf("K: ");  scanf("%d", &K);
    printf("\n");
    int n;
    int i = 0;
    int number;
    while(1)
    {
        printf("n: ");  scanf("%d", &n);
        i++;
        if(n == 0)
        {
            break;
        }
        if(n > K)
        {
           number = i;
        }
    }
    printf("\nlastest number n > K = %d", number);
}



series_15()
{
    int K;
    printf("K: ");  scanf("%d", &K);
    int n;
    int i = 0;
    while(1)
    {
        printf("n: ");  scanf("%d", &n);
        i++;
        if(n == 0)
        {
            i = 0;
            break;
        }
        if(n > K)
        {
            printf("\ni = %d", i);
            break;
        }
    }
}


series_14()
{
    int K;
    printf("K: ");  scanf("%d", &K);
    int n;
    int i = 0;
    while(1)
    {
        printf("n: ");  scanf("%d", &n);
        if(n == 0) break;
        if(n < K) i++;
    }
    printf("\ni = %d", i);
}



series_13()
{
    int n = 1;
    int i = 0;
    while(1)
    {
        printf("n: ");  scanf("%d", &n);
        if(n == 0) break;
        printf("%d \n", n);
        if(n % 2 == 0 && n > 0) i++;
    }
    printf("\ni = %d", i);
}


series_12()
{
    int n = 1;
    int i = 0;
    while(1)
    {
        printf("n%d: ", i + 1);  scanf("%d", &n);
        if(n == 0) break;
        printf("n: %d \n", n);
        i++;
    }
    printf("\ni = %d", i);
}


series_11()
{
    int N, K;
    printf("N: ");  scanf("%i", &N);
    printf("K: ");  scanf("%i", &K);

    int n;
    bool t_or_f = false;
    for(int i = 0; i < N; i++)
    {
        printf("n%i: ", i + 1);  scanf("%i", &n);

        if(n < K) t_or_f = true;
        else t_or_f = false;

        printf("%s\n", t_or_f ? "true" : "false");
    }

    printf("\n");
}


series_10()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int n;
    bool t_or_f = false;
    for(int i = 0; i < N; i++)
    {
        printf("n%i: ", i + 1);  scanf("%i", &n);

        if(n > 0) t_or_f = true;
        else t_or_f = false; //Нуль рахується як false.

        printf("%s\n", t_or_f ? "true" : "false");
    }
}



series_09()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int n;
    int K =0;
    for(int i = 0; i < N; i++)
    {
        printf("n%i: ", i + 1);  scanf("%i", &n);
        if(n % 2 != 0)
        {
            printf("odd number: %i\n", n);
            K++;
        }
    }

    printf("\n");
    printf("K = %i", K);

}


series_08()
{
    int N;
    printf("N: ");  scanf("%i", &N);

    int n;
    int K =0;
    for(int i = 0; i < N; i++)
    {
        printf("n%i: ", i + 1);  scanf("%i", &n);
        if(n % 2 == 0)
        {
            printf("even number: %i\n", n);
            K++;
        }
    }

    printf("\n");
    printf("K = %i", K);

}

int Round(double x)
{
    return x + 0.5;
}


series_07() //Округлення, різні види.
{
    int N;
    double rez = 0;
    double temp;

    printf("N: ");  scanf("%i", &N);  printf("\n");

    int sum = 0;
    double n;
    for(int i = 0; i < N; i++)
    {
       printf("n%i: ", i+1);  scanf("%lf", &n);

       int x = Round(n);
       int y = floor(n);
       int z = ceil(n);
       int w = n;

       printf("x = %d\n", x);
       printf("y = %d\n", y);
       printf("z = %d\n", z);
       printf("w = %d\n", w);
       sum = sum + (int)n;
    }

    printf("\n");
    printf("sum = %i", sum);

}


series_06()
{
    int N;
    double rez = 0;

    printf("N: ");  scanf("%i", &N);  printf("\n");

    double sum = 1;
    double n;
    for(int i = 0; i < N; i++)
    {
       printf("n%i: ", i+1);  scanf("%lf", &n);
       n = fmod(n, (double)((int)n));
       printf("%.2lf\n", n);
       sum = sum * n;
    }

    printf("\n");
    printf("sum = %.2lf", sum);
}


series_05()
{
    int N;
    double rez = 0;

    printf("N: ");  scanf("%i", &N);  printf("\n");

    int sum = 0;
    double n;
    for(int i = 0; i < N; i++)
    {
       printf("n%i: ", i+1);  scanf("%lf", &n);
       printf("%.2lf\n",(double)((int)n));
       sum = sum + (int)n;
    }

    printf("\n");
    printf("sum = %i", sum);
}


series_04()
{
    int N;
    double rez = 0;

    printf("N: ");  scanf("%i", &N);  printf("\n");

    double mul = 1;
    double sum = 0;
    double n;
    for(int i = 0; i < N; i++)
    {
       printf("n%i: ", i+1);  scanf("%lf", &n);
       sum = sum + n;
       mul = mul * n;
    }

    printf("\n");
    printf("sum = %.2lf mul = %.2lf", sum, mul);
}


series_03()
{
    double N;
    double rez = 0;

    for(int i = 0; i < 10; i++)
    {
       printf("N%i: ", i+1);  scanf("%lf", &N);
       rez = rez + N;
    }
    rez = rez / 10.0;

    printf("\n");
    printf("rez: %.2lf", rez);
}


series_02()
{
    double N;
    double rez = 1;

    for(int i = 0; i < 10; i++)
    {
       printf("N%i: ", i+1);  scanf("%lf", &N);
       rez = rez * N;
    }

    printf("\n");
    printf("rez: %.2lf", rez);
}


series_01()
{
    double N;
    double rez = 0;

    for(int i = 0; i < 10; i++)
    {
       printf("N%i: ", i+1);  scanf("%lf", &N);
       rez = rez + N;
    }

    printf("\n");
    printf("rez: %.2lf", rez);
}

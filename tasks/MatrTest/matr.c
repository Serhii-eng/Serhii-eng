#include "intset.h"
#include "matr.h"
#include "matr_tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void matr1()
{
    Matr M;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = 10 * i;
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%3.0lf ", M[i][j]);
        }
        puts("");
    }
}


void matr2()
{
    Matr M;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = 5 * j;
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%3.0lf ", M[i][j]);
        }
        puts("");
    }

}


void matr3()
{
    Matr M;
    Array A;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    for(int i = 0; i < m; i++)
    {
        A[i] = -5 + rand() % 16;
    }

    for(int i = 0; i < m; i++)
    {
        printf("%3.0lf ", A[i]);
    }
    puts("");
    puts("");

    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < m; i++)
        {
            M[i][j] = A[i];
        }
    showMatr(M, m, n);
    }
}


void matr3a()
{
    Matr M;
    Array A;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    for(int i = 0; i < m; i++)
    {
        A[i] = -5 + rand() % 16;
    }

    for(int i = 0; i < m; i++)
    {
        printf("%3.0lf ", A[i]);
    }
    puts("");
    puts("");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = A[i];
        }
        showMatr(M, m, n);
    }
}


void matr4()
{
    Matr M;
    Array A;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    for(int j = 0; j < n; j++)
    {
        A[j] = -5 + rand() % 16;
    }

    for(int j = 0; j < n; j++)
    {
        printf("%3.0lf ", A[j]);
    }
    puts("");
    puts("");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = A[j];
        }
    showMatr(M, m, n);
    }
}


void matr5()
{
    Matr M;
    Array A;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    for(int i = 0; i < m; i++)
    {
        A[i] = -5 + rand() % 16;
    }

    for(int i = 0; i < m; i++)
    {
        printf("%3.0lf ", A[i]);
    }
    puts("");

    int d;
    printf("d = ");    scanf("%d", &d);
    puts("");

    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        sum = sum + A[i];
        for(int j = 0; j < n; j++)
        {
            M[i][j] = sum;
            sum = sum + d;
        }
        showMatr(M, m, n);
    }
}

void matr6()
{
    Matr M;
    Array A;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    for(int j = 0; j < n; j++)
    {
        A[j] = -5 + rand() % 16;
    }

    for(int j = 0; j < n; j++)
    {
        printf("%3.0lf ", A[j]);
    }
    puts("");

    double d;
    printf("d = ");    scanf("%lf", &d);
    puts("");

    for(int j = 0; j < n; j++)
    {
        double sum = 0;
        sum = sum + A[j];
        for(int i = 0; i < m; i++)
        {
            M[i][j] = sum;
            sum = sum * d;
        }
        showMatr(M, m, n);
    }
}


void matr7()
{
    Matr M;
    Array A;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = -5 + rand() % 16;;
        }
    }

    showMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    puts("");

    int a = 0;
    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        sum = sum + A[i];
        for(int j = 0; j < n; j++)
        {
            if(j == k)
            {
                A[a++] = M[i][j];
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        printf("%3.0lf ", A[i]);
    }
}


void matr8()
{
    Matr M;
    Array A;

    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = -5 + rand() % 16;
        }
    }

    showMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    puts("");

    int a = 0;
    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        sum = sum + A[i];
        for(int j = 0; j < n; j++)
        {
            if(i == k)
            {
                A[a++] = M[i][j];
            }
        }
    }

    for(int j = 0; j < n; j++)
    {
        printf("%3.0lf ", A[j]);
    }
}


void matr9()
{
    Matr M;
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = -5 + rand() % 16;
        }
    }

    showMatr(M, m, n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j+=2)
        {
            printf("%3.0lf ", M[i][j]);
        }
        puts("");
    }
}


void matr10()
{
    Matr M;
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = -5 + rand() % 16;
        }
    }

    showMatr(M, m, n);

    for(int j = 0; j < n; j++)
    {
        for(int i = 1; i < m; i+=2)
        {
            printf("%3.0lf ", M[i][j]);
        }
        puts("");
    }
}


void matr11()
{
    Matr M;
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    puts("");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = -5 + rand() % 16;
        }
    }

    showMatr(M, m, n);

    for(int i = 0; i < m; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < n; j++)
            {
                printf("%3.0lf ", M[i][j]);
            }
        }

        if(i % 2 != 0)
        {
            for(int j = n-1; j >= 0; j--)
            {
                printf("%3.0lf ", M[i][j]);
            }
        }
        puts("");
    }
}


void matr12()
{
    Matr M;
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    puts("");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = -5 + rand() % 16;
        }
    }
    showMatr(M, m, n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j % 2 == 0)
            {
                printf("%3.0lf ", M[i][j]);
            }

            if(j % 2 != 0)
            {
                printf("%3.0lf ", M[m-i-1][j]);
            }
        }

        puts("");
    }
}


void matr13()
{
    Matr A;
    int m;
    printf("m = ");    scanf("%d", &m);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = -5 + rand() % 16;
        }
    }
    showMatr(A, m, m);

    //temp = 1;
    for(int k = 1; k <= m; k++)
    {
        int i = k - 1;
        int j = k - 1;
        for(j = 0; j <= m-k; j++)
        {
            printf("%3.0lf ", A[i][j]);
        }

        for(i = k; i < m; i++)
        {
            printf("%3.0lf ", A[i][m-k]);
        }

        puts("");
    }
}


void matr14()
{
    Matr A;
    int m;
    printf("m = ");    scanf("%d", &m);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = -5 + rand() % 16;
        }
    }
    showMatr(A, m, m);

    //temp = 1;
    for(int k = 1; k <= m; k++)
    {
        int i = k - 1;
        int j = k - 1;
        for(i = 0; i <= m-k; i++)
        {
            printf("%3.0lf ", A[i][j]);
        }

        for(j = k; j < m; j++)
        {
            printf("%3.0lf ", A[m-k][j]);
        }

        puts("");
    }
}


void matr15()
{
    Matr A;
    int m;
    printf("m = ");    scanf("%d", &m);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = -5 + rand() % 16;
        }
    }
    showMatr(A, m, m);

    for(int k = 1; k <= m; k++)
    {
        int i = k - 1;
        int j = k - 1;
        for(j = k-1; j <= m-k; j++)
        {
            printf("%3.0lf ", A[i][j]);
        }

        for(i = k; i < m-k+1; i++)
        {
            printf("%3.0lf ", A[i][m-k]);
        }

        for(j = m-k-1; j >= k-1; j--)
        {
            printf("%3.0lf ", A[m-k][j]);
        }

        for(i = m-k-1; i >= k; i--)
        {
            printf("%3.0lf ", A[i][k-1]);
        }

        puts("");
    }
}


void matr16()
{
    Matr A;
    int m;
    printf("m = ");    scanf("%d", &m);

    puts("");

     for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            A[i][j] = -5 + rand() % 16;
        }
    }
    showMatr(A, m, m);

    for(int k = 1; k <= m; k++)
    {
        int i = k - 1;
        int j = k - 1;
        for(i = k-1; i <= m-k; i++)
        {
            printf("%3.0lf ", A[i][j]);
        }

        for(j = k; j < m-k+1; j++)
        {
            printf("%3.0lf ", A[m-k][j]);
        }

        for(i = m-k-1; i >= k-1; i--)
        {
            printf("%3.0lf ", A[i][m-k]);
        }

        for(j = m-k-1; j >= k; j--)
        {
            printf("%3.0lf ", A[k-1][j]);
        }

        puts("");
    }
}


void matr17()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    double sum = 0;
    double mul = 1;
    for(int j = 0; j < n; j++)
    {
        sum += M[k][j];
        mul *= M[k][j];
    }

    printf("sum = %lf\n", sum);
    printf("mul = %lf\n", mul);

    deleteDynamicMatr(&M, m, n);

    system("pause");
}


void matr18()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    double sum = 0;
    double mul = 1;
    for(int i = 0; i < m; i++)
    {
        sum += M[i][k];
        mul *= M[i][k];
    }

    printf("sum = %lf\n", sum);
    printf("mul = %lf\n", mul);

    deleteDynamicMatr(&M, m, n);

    system("pause");
}


void matr19()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int i = 0; i < m; i++)
    {
        double sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += M[i][j];
        }

        printf("sum string %d = %lf\n", i, sum);
    }


    deleteDynamicMatr(&M, m, n);

    system("pause");
}

void matr20()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int j = 0; j < n; j++)
    {
        double mul = 1;
        for(int i = 0; i < m; i++)
        {
            mul *= M[i][j];
        }

        printf("mul column %d = %lf\n", j, mul);
    }


    deleteDynamicMatr(&M, m, n);

    system("pause");
}


void matr21()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int i = 1; i < m; i+=2)
    {
        double sum = 0;
        double ariph = 0;
        for(int j = 0; j < n; j++)
        {
            sum += M[i][j];
        }
        ariph = sum / n;

        printf("ariph string %d = %lf\n", i, ariph);
    }


    deleteDynamicMatr(&M, m, n);

    system("pause");
}


void matr22()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int j = 0; j < n; j+=2)
    {
        double sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum += M[i][j];
        }

        printf("sum column %d = %lf\n", j, sum);
    }

    deleteDynamicMatr(&M, m, n);
}


void matr23()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int i = 0; i < m; i++)
    {
        double min = M[i][0];
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] < min)
            min = M[i][j];
        }

        printf("min in string %d = %lf\n", i, min);
    }

    deleteDynamicMatr(&M, m, n);
}


void matr24()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int j = 0; j < n; j++)
    {
        double max = M[0][j];
        for(int i = 0; i < m; i++)
        {
            if(M[i][j] > max)
            max = M[i][j];
        }

        printf("max in column %d = %lf\n", j, max);
    }

    deleteDynamicMatr(&M, m, n);
}


void matr25()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int num_string = 0;
    double max_string;
    for(int j = 0; j < n; j++)
    {
        max_string += M[0][j];
    }

    for(int i = 0; i < m; i++)
    {
        double max = 0;
        for(int j = 0; j < n; j++)
        {
            max += M[i][j];
        }
        if(max > max_string)
        {
            max_string = max;
            num_string = i;
        }
    }

    printf("max string in matrix %d = %lf\n", num_string, max_string);

    deleteDynamicMatr(&M, m, n);
}


void matr26()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int num_string = 0;
    double min_string = 1;
    for(int i = 0; i < m; i++)
    {
        min_string *= M[i][0];
    }

    for(int j = 0; j < n; j++)
    {
        double min = 1;
        for(int i = 0; i < m; i++)
        {
            min *= M[i][j];
        }
        if(min < min_string)
        {
            min_string = min;
            num_string = j;
        }
    }

    printf("min column in matrix %d = %lf\n", num_string, min_string);

    deleteDynamicMatr(&M, m, n);
}


void matr27()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    double* A = createDblArray(m);
    int a = 0;
    for(int i = 0; i < m; i++)
    {
        double min = M[i][0];
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] < min) min = M[i][j];
        }
        A[a++] = min;
    }

    double max = A[0];
    for(int i = 0; i < m; i++)
    {
        if(A[i] > max) max = A[i];
    }

    printf("max between min strings matrix = %.2lf\n", max);

    deleteDynamicMatr(&M, m, n);
    free(A);
}


void matr28()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    double* A = createDblArray(m);
    int a = 0;
    for(int i = 0; i < m; i++)
    {
        double max = M[i][0];
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] > max) max = M[i][j];
        }
        A[a++] = max;
    }

    double min = A[0];
    for(int i = 0; i < m; i++)
    {
        if(A[i] < min) min = A[i];
    }

    printf("min between max strings matrix = %.2lf\n", min);

    deleteDynamicMatr(&M, m, n);
    free(A);
}


void matr29()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    double* A = createDblArray(m);
    int a = 0;
    for(int i = 0; i < m; i++)
    {
        double sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += M[i][j];
        }
        A[a++] = sum / n;
    }

    int* B = createIntArray(m);
    int b = 0;
    for(int i = 0; i < m; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] < A[i]) cnt++;
        }
        B[b++] = cnt;
    }

    for(int i = 0; i < m; i++)
    {
        printf("amount of smoller then ariph in strings %d = %d\n", i, B[i]);
    }


    deleteDynamicMatr(&M, m, n);
    free(A);
    free(B);
}


void matr30()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    double* A = createDblArray(n);
    int a = 0;
    for(int j = 0; j < n; j++)
    {
        double sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum += M[i][j];
        }
        A[a++] = sum / n;
    }

    int* B = createIntArray(n);
    int b = 0;
    for(int j = 0; j < n; j++)
    {
        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            if(M[i][j] > A[i]) cnt++;
        }
        B[b++] = cnt;
    }

    for(int i = 0; i < n; i++)
    {
        printf("amount of bigger then ariph in strings %d = %d\n", i, B[i]);
    }

    deleteDynamicMatr(&M, m, n);
    free(A);
    free(B);
}


void matr31()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    MatrInfo mInfo = getMatrInfo(M, m, n);
    double ariph = mInfo.average;
    double different = fabs(M[0][0] - ariph);
    int pos_i = 0;
    int pos_j = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double temp = fabs(M[i][j] - ariph);
            if(temp < different)
            {
                different = temp;
                pos_i = i;
                pos_j = j;
            }
        }
    }

    printf("value close to the arithmetic mean = %.2lf\n", M[pos_i][pos_j]);
    printf("position i = %d\n", pos_i);
    printf("position j = %d\n", pos_j);
    printf("different = %.2lf\n", different);

    deleteDynamicMatr(&M, m, n);
}


void matr32()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int pos_string = -1;
    for(int i = 0; i < m; i++)
    {
        int cnt_positive = 0;
        int cnt_negative = 0;
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] > 0)
            {
                cnt_positive++;
            }
            if(M[i][j] < 0)
            {
                cnt_negative++;
            }
        }

        if(cnt_positive == cnt_negative && cnt_positive > 0 && cnt_negative > 0)
        {
            pos_string = i;
            break;
        }
    }

    printf("position string = %d\n", pos_string);

    deleteDynamicMatr(&M, m, n);
}


void matr33()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int pos_string = -1;
    for(int j = 0; j < n; j++)
    {
        int cnt_positive = 0;
        int cnt_negative = 0;
        for(int i = 0; i < m; i++)
        {
            if(M[i][j] > 0)
            {
                cnt_positive++;
            }
            if(M[i][j] < 0)
            {
                cnt_negative++;
            }
        }

        if(cnt_positive == cnt_negative && cnt_positive > 0 && cnt_negative > 0)
        {
            pos_string = j;
        }
    }

    printf("position string = %d\n", pos_string);

    deleteDynamicMatr(&M, m, n);
}


void matr34()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, -20, 20);
    showDynamicIntMatr(M, m, n);

    int pos_string= -1;
    for(int i = 0; i < m; i++)
    {
        int cnt_even = 0;
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] % 2 == 0)
            {
                cnt_even++;
            }
        }

        if(cnt_even == n)
        {
            pos_string = i;
        }
    }

    printf("position string = %d\n", pos_string);

    deleteDynamicIntMatr(&M, m, n);
}


void matr35()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, -20, 20);
    showDynamicIntMatr(M, m, n);

    int pos_column = -1;
    for(int j = 0; j < n; j++)
    {
        int cnt_odd = 0;
        for(int i = 0; i < m; i++)
        {
            if(M[i][j] % 2 != 0)
            {
                cnt_odd++;
            }
        }

        if(cnt_odd == m)
        {
            pos_column = j;
            break;
        }
    }

    printf("position column = %d\n", pos_column);

    deleteDynamicIntMatr(&M, m, n);
}


void matr36()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 101);
    showDynamicIntMatr(M, m, n);

    int amount_strings = 0;
    for(int i = 1; i < m; i++)
    {
        bool same = true;
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(M[0][k] == M[i][j])
                {
                    same = true;
                    break;
                }
                else
                {
                    same = false;
                }
            }

            if(same == false)
            {
                break;
            }
        }
        if(same)
        {
            printf("number = %d\n", i);
            amount_strings++;
        }
    }

    printf("amount of strings = %d\n", amount_strings);

    deleteDynamicIntMatr(&M, m, n);
}


void matr36a()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 9);
    showDynamicIntMatr(M, m, n);

    IntSet s0 = createIntSet(n);
    for(int j = 0; j < n; j++) insertToIntSet(&s0, M[0][j]);
    showIntSet(&s0);

    int cnt = 0;
    for(int i = 1; i < m; i++)
    {
        IntSet si = createIntSet(n);
        for(int j = 0; j < n; j++) insertToIntSet(&si, M[i][j]);
        showIntSet(&si);
        if(isIntSetsEquale(&s0, &si)) cnt++;
        deleteIntSet(&si);
    }

    printf("cnt = %d\n", cnt);

    deleteIntSet(&s0);
    deleteDynamicIntMatr(&M, m, n);
}


void matr36b()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 5);
    showDynamicIntMatr(M, m, n);

    int cnt = 0;
    for(int i = 1; i < m; i++)
    {
        if(isRowsSimilar(M, m, n, 0, i)) cnt++;
    }

    printf("cnt = %d\n", cnt);

    deleteDynamicIntMatr(&M, m, n);
}


void matr36c()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 5);
    showDynamicIntMatr(M, m, n);

    int cnt = 0;
    for(int i = 1; i < m; i++)
    {
        if(isRowsSimilar_manyCycles(M, m, n, 0, i)) cnt++;
    }

    printf("cnt = %d\n", cnt);

    deleteDynamicIntMatr(&M, m, n);
}


void matr37()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 101);
    showDynamicIntMatr(M, m, n);

    int amount_colums = 0;
    for(int j = 0; j < n-1; j++)
    {
        bool same = true;
        for(int i = 0; i < m; i++)
        {
            for(int k = 0; k < m; k++)
            {
                if(M[k][n-1] == M[i][j])
                {
                    same = true;
                    break;
                }
                else
                {
                    same = false;
                }
            }

            if(same == false)
            {
                break;
            }
        }
        if(same)
        {
            printf("number = %d\n", j);
            amount_colums++;
        }
    }

    printf("amount of colums = %d\n", amount_colums);

    deleteDynamicIntMatr(&M, m, n);
}


void matr38()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 101);
    showDynamicIntMatr(M, m, n);

    int amount_diff_strings = 0;
    for(int p = 0; p < m-1; p++)
    {
        bool same = false;
        for(int i = p+1; i < m; i++)
        {
            for(int k = 0; k < n-1; k++)
            {
                for(int j = k+1; j < n; j++)
                {
                    if(M[i][j] == M[p][k])
                    {
                        same = true;
                        j = n;
                        k = n;
                        i = m;
                    }
                }
            }

        }

        if(same == false) amount_diff_strings++;
    }

    printf("amount of colums = %d\n", amount_diff_strings);

    deleteDynamicIntMatr(&M, m, n);
}


void matr39()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 101);
    showDynamicIntMatr(M, m, n);

    int amount_diff_strings = 0;
    for(int p = 0; p < n-1; p++)
    {
        bool same = false;
        for(int j = p+1; j < n; j++)
        {
            for(int k = 0; k < m-1; k++)
            {
                for(int i = k+1; i < m; i++)
                {
                    if(M[i][j] == M[k][p])
                    {
                        same = true;
                        j = n;
                        k = n;
                        i = m;
                    }
                }
            }

        }

        if(same == false) amount_diff_strings++;
    }

    printf("amount of different colums = %d\n", amount_diff_strings);

    deleteDynamicIntMatr(&M, m, n);
}


void matr40()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 10);
    showDynamicIntMatr(M, m, n);

    int last_string = -1;
    int max_amount = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            int amount = 1;
            for(int k = j+1; k < n; k++)
            {
                if(M[i][k] == M[i][j])
                {
                    amount++;

                    if(amount >= max_amount)
                    {
                        max_amount = amount;
                        last_string = i;
                    }
                }
            }
        }
    }

    printf("max amount = %d\n", max_amount);
    printf("last string = %d\n", last_string);

    deleteDynamicIntMatr(&M, m, n);
}


void matr41()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 10);
    showDynamicIntMatr(M, m, n);

    int first_string = -1;
    int max_amount = 0;
    for(int j = n-1; j >= 0; j--)
    {
        for(int i = 0; i < m-1; i++)
        {
            int amount = 1;
            for(int k = i+1; k < m; k++)
            {
                if(M[k][j] == M[i][j])
                {
                    amount++;

                    if(amount >= max_amount)
                    {
                        max_amount = amount;
                        first_string = j;
                    }
                }
            }
        }
    }

    printf("max amount = %d\n", max_amount);
    printf("last string = %d\n", first_string);

    deleteDynamicIntMatr(&M, m, n);
}


void matr42()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n);
    fillDynamicIntMatrRnd(M, m, n, 0, 10);
    showDynamicIntMatr(M, m, n);

    int strings = 0;
    for(int i = 0; i < m; i++)
    {
        bool ok = true;
        for(int j = 1; j < n; j++)
        {
            if(M[i][j-1] > M[i][j])
            {
                ok = false;
            }
        }

        if(ok)
        {
            strings++;
        }
    }

    printf("strings = %d\n", strings);

    deleteDynamicIntMatr(&M, m, n);
}


void matr43()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicIntMatr M = createDynamicIntMatr_zero(m, n); //Що значить попередження?
    fillDynamicIntMatrRnd(M, m, n, 0, 10);
    showDynamicIntMatr(M, m, n);

    int strings = 0;
    for(int j = 0; j < n; j++)
    {
        bool ok = true;
        for(int i = 1; i < m; i++)
        {
            if(M[i-1][j] < M[i][j])
            {
                ok = false;
            }
        }

        if(ok)
        {
            strings++;
        }
    }

    printf("strings = %d\n", strings);

    deleteDynamicIntMatr(&M, m, n);
}


void matr44()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr_zero(m, n);
    fillDynamicMatrRnd(M, m, n, 0, 10);
    showDynamicMatr(M, m, n);

    bool set = false;
    double min_value = 0;
    for(int i = 0; i < m; i++)
    {
        bool check_1 = true;
        bool check_2 = true;
        for(int j = 1; j < n; j++)
        {
            if(M[i][j-1] > M[i][j])
            {
                check_1 = false;
            }
            if(M[i][j-1] < M[i][j])
            {
                check_2 = false;
            }
        }

        if(check_1 || check_2)
        {
            if(set == false)
            {
                min_value = M[i][0];
                set = true;
            }
            for(int j = 0; j < n; j++)
            {
                if(M[i][j] < min_value)
                {
                    min_value = M[i][j];
                }
            }
        }
    }

    printf("min_value = %.2lf\n", min_value);

    deleteDynamicMatr(&M, m, n);
}


void matr45()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr_zero(m, n);
    fillDynamicMatrRnd(M, m, n, 0, 10);
    showDynamicMatr(M, m, n);

    bool set = false;
    double max_value = 0;
    for(int j = 0; j < n; j++)
    {
        bool check_1 = true;
        bool check_2 = true;
        for(int i = 1; i < m; i++)
        {
            if(M[i-1][j] > M[i][j])
            {
                check_1 = false;
            }
            if(M[i-1][j] < M[i][j])
            {
                check_2 = false;
            }
        }

        if(check_1 || check_2)
        {
            if(set == false)
            {
            max_value = M[0][j];
                set = true;
            }
            for(int i = 0; i < m; i++)
            {
                if(M[i][j] > max_value)
                {
                    max_value = M[i][j];
                }
            }
        }
    }

    printf("max_value = %.2lf\n", max_value);

    deleteDynamicMatr(&M, m, n);
}


void matr46()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr_zero(m, n);
    fillDynamicMatrRnd(M, m, n, 0, 10);
    showDynamicMatr(M, m, n);

    double max_min = 0;
    for(int i = 0; i < m; i++)
    {
        int pos_j = 0;
        double max_value = M[i][0];
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] > max_value)
            {
                max_value = M[i][j];
                pos_j = j;
            }
        }

        double min_value = M[0][pos_j];
        for(int k = 0; k < m; k++)
        {
            if(M[k][pos_j] < min_value)
            {
                min_value = M[k][pos_j];
            }
        }

        if(max_value == min_value)
        {
            max_min = max_value;
            break;
        }
    }

    printf("max_min = %.2lf\n", max_min);

    deleteDynamicMatr(&M, m, n);
}


void matr47()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr_zero(m, n);
    fillDynamicMatrRnd(M, m, n, 0, 10);
    showDynamicMatr(M, m, n);

    int row1, row2;
    printf("row1 = ");    scanf("%d", &row1);
    printf("row2 = ");    scanf("%d", &row2);
    swapRowDynamicMatr(M, m, n, row1, row2);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr48()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr_zero(m, n);
    fillDynamicMatrRnd(M, m, n, 0, 10);
    showDynamicMatr(M, m, n);

    int column1, column2;
    printf("column1 = ");    scanf("%d", &column1);
    printf("column2 = ");    scanf("%d", &column2);
    swapColumnDynamicMatr(M, m, n, column1, column2);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr49()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr_zero(m, n);
    fillDynamicMatrRnd(M, m, n, 0, 10);
    showDynamicMatr(M, m, n);

    for(int i = 0; i < m; i++)
    {
        double min, max;
        min = max = M[i][0];
        int pos_min, pos_max;
        pos_min = pos_max = 0;
        for(int j = 0; j < n; j++)
        {
            if(M[i][j] < min)
            {
                min = M[i][j];
                pos_min = j;
            }

            if(M[i][j] > max)
            {
                max = M[i][j];
                pos_max = j;
            }
        }
        double temp;
        temp = M[i][pos_min];
        M[i][pos_min] = M[i][pos_max];
        M[i][pos_max] = temp;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr50()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr_zero(m, n);
    fillDynamicMatrRnd(M, m, n, 0, 10);
    showDynamicMatr(M, m, n);

    for(int j = 0; j < n; j++)
    {
        double min, max;
        min = max = M[0][j];
        int pos_min, pos_max;
        pos_min = pos_max = 0;
        for(int i = 0; i < m; i++)
        {
            if(M[i][j] < min)
            {
                min = M[i][j];
                pos_min = i;
            }

            if(M[i][j] > max)
            {
                max = M[i][j];
                pos_max = i;
            }
        }
        double temp;
        temp = M[pos_min][j];
        M[pos_min][j] = M[pos_max][j];
        M[pos_max][j] = temp;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr51()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    MatrInfo mInfo = getMatrInfo(M, m, n);
    swapRowDynamicMatr(M, m, n, mInfo.min_row, mInfo.max_row);
    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr52()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    MatrInfo mInfo = getMatrInfo(M, m, n);
    swapColumnDynamicMatr(M, m, n, mInfo.min_column, mInfo.max_column);
    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr53()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);
    bool positive_column = false;
    int pos_column = -1;
    for(int j = 1; j < n; j++)
    {
        if(isColumnPositive(M, j, m))
        {
            positive_column = true;
            pos_column = j;
        }
    }

    if(positive_column)
    {
        swapColumnDynamicMatr(M, m, n, 0, pos_column);
    }
    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr54()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int num_column;
    printf("num_column = ");    scanf("%d", &num_column);
    for(int j = 0; j < n; j++)
    {
        if(isColumnNegative(M, j, m))
        {
            swapColumnDynamicMatr(M, m, n, j, num_column);
            break;
        }
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr55()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int j = 0;
    while(j < n)
    {
        int i = 0;
        int k = m-1;
        while(i < k)
        {
            double temp = M[i][j];
            M[i++][j] = M[k][j];
            M[k--][j] = temp;
        }

        j++;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr56()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int i = 0;
    while(i < m)
    {
        int j = 0;
        int k = n-1;
        while(j < k)
        {
            double temp = M[i][j];
            M[i][j++] = M[i][k];
            M[i][k--] = temp;
        }

        i++;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr57()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int i = 0;
    int p = m/2;
    while(p < m)
    {
        int j = 0;
        int k = n/2;
        while(k < n)
        {
            double temp = M[i][j];
            M[i][j] = M[p][k];
            M[p][k] = temp;

            j++;
            k++;
        }

        i++;
        p++;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr58()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int i = 0;
    int p = m/2;
    while(p < m)
    {
        int j = 0;
        int k = n/2;
        while(k < n)
        {
            double temp = M[i][k];
            M[i][k] = M[p][j];
            M[p][j] = temp;

            j++;
            k++;
        }

        i++;
        p++;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr59()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int i = 0;
    int p = m-1;
    while(i <= p)
    {
        int j = 0;
        while(j < n)
        {
            double temp = M[i][j];
            M[i][j] = M[p][j];
            M[p][j] = temp;

            j++;
        }

        i++;
        p--;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr60()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int i = 0;
    while(i < m)
    {
        int j = 0;
        int k = n-1;
        while(j <= k)
        {
            double temp = M[i][j];
            M[i][j] = M[i][k];
            M[i][k] = temp;

            j++;
            k--;
        }

        i++;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr61()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    deleteRowDynamicMatr(&M, &m, &n, k);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr62()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    deleteColumnDynamicMatr(&M, &m, &n, k);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr63()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    MatrInfo mInfo = getMatrInfo(M, m, n);

    deleteRowDynamicMatr(&M, &m, &n, mInfo.min_row);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr64()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    MatrInfo mInfo = getMatrInfo(M, m, n);

    deleteColumnDynamicMatr(&M, &m, &n, mInfo.max_column);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr65()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int j = 0; j < n; j++)
    {
        if(isColumnPositive(M, j, m))
        {
            deleteColumnDynamicMatr(&M, &m, &n, j);
            break;
        }
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr66()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    bool negative_column = false;
    int pos_column = -1;
    for(int j = 0; j < n; j++)
    {
        if(isColumnNegative(M, j, m))
        {
            negative_column = true;
            pos_column = j;
        }
    }
    if(negative_column)
    {
        deleteColumnDynamicMatr(&M, &m, &n, pos_column);
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr67()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int j = n-1; j >= 0; j--)
    {
        if(isColumnPositive(M, j, m))
        {
            deleteColumnDynamicMatr(&M, &m, &n, j);
        }
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr68()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    addRowDynamicMatr_zero(&M, &m, &n, k);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr69()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int k;
    printf("k = ");    scanf("%d", &k);
    addRowDynamicMatr_zero(&M, &m, &n, k);

    for(int j = 0; j < n; j++)
    {
        M[k][j] = 1;
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr70()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);


    MatrInfo mInfo = getMatrInfo(M, m, n);

    addRowDynamicMatr_zero(&M, &m, &n, mInfo.max_row);

    for(int j = 0; j < n; j++)
    {
        M[mInfo.max_row][j] = M[mInfo.max_row+1][j];
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr71()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);


    MatrInfo mInfo = getMatrInfo(M, m, n);

    addColumnDynamicMatr_zero(M, &m, &n, mInfo.min_column);

    for(int i = 0; i < m; i++)
    {
        M[i][mInfo.min_column] = M[i][mInfo.min_column+1];
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr72()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int j = 0; j < n; j++)
    {
        if(isColumnPositive(M, j, m))
        {
            addColumnDynamicMatr_zero(M, &m, &n, j);

            for(int k = 0; k < m; k++)
            {
                M[k][j] = 1;
            }
            break;
        }
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr72a()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int column = -1;
    for(int j = 0; j < n; j++)
    {
        if(isColumnPositive(M, j, m))
        {
            column = j;
            break;
        }
    }

    if(column != -1)
    {
       addColumnDynamicMatr_value(M, &m, &n, column, 1);
    }
    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}



void matr73()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);


    bool negative_column = false;
    int pos_column = -1;
    for(int j = 0; j < n; j++)
    {
        if(isColumnNegative(M, j, m))
        {
            negative_column = true;
            pos_column = j;
        }
    }

    if(negative_column)
    {
        addColumnDynamicMatr_zero(M, &m, &n, pos_column+1);
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr74()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);


    DynamicMatr M2 = createDynamicMatr_zero(m, n);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
           if(!is_local_min_Matr(M, m, n, i, j)) M2[i][j] = M[i][j];
        }
    }

    deleteDynamicMatr(&M, m, n);

    M = M2;
    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void putToMapLocalMin(DynamicMatr M1, DynamicCharMatr M2, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(is_local_min_Matr1(M1, m, n, i, j)) M2[i][j] = 1;
        }
    }
}


void setZeroInLocalMin(DynamicMatr M1, DynamicCharMatr M2, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(M2[i][j] == 1) M1[i][j] = 0;
        }
    }
}


//Влаштувати пошук, та на мапі позначити де стоять мінімуми.
void matr74b()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    DynamicCharMatr M2 = createDynamicCharMatr_zero(m, n);

    putToMapLocalMin(M, M2, m, n);

    setZeroInLocalMin(M, M2, m, n);

    deleteDynamicMatr(&M2, m, n);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr75()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);


    DynamicMatr M2 = createDynamicMatr_zero(m, n);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
           if(!is_local_max_Matr(M, m, n, i, j)) M2[i][j] = M[i][j];
           else M2[i][j] = M[i][j] * -1;
        }
    }

    showDynamicMatr(M2, m, n);

    deleteDynamicMatr(&M, m, n);
    deleteDynamicMatr(&M2, m, n);
}



int counterLocalMax(DynamicMatr M, int m, int n)
{
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(is_local_max_Matr1(M, m, n, i, j)) cnt++;
        }
    }

    return cnt;
}


Pos_point* createPos_points(int amount_coordinates)
{
    Pos_point* A = (Pos_point*) malloc(sizeof(Pos_point) * amount_coordinates);
    for(int i = 0; i < amount_coordinates; i++)
    {
        A[i].i = -1;
        A[i].j = -1;
    }

    return A;
}


void getPos_points(DynamicMatr M, Pos_point* points, int m, int n)
{
    int p = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(is_local_max_Matr1(M, m, n, i, j))
            {
                (&points[p])->i = i;
                (&points[p])->j = j;
                p++;
            }
        }
    }
}


void setPos_pointsToMatr(DynamicMatr M, Pos_point* points, int amount_coordinates)
{
    for(int i = 0; i < amount_coordinates; i++)
    {
        M[(&points[i])->i][(&points[i])->j] *= -1;
    }
}

void deletePos_points(Pos_point* points)
{
    free(points);
}

//Порахувати кількість максимумів
//Створити список структур поінтів з інтів як масив
//Відповідно до списка опрацювати вказані позиції у матриці
void matr75b()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    int amount = counterLocalMax(M, m, n);

    Pos_point* points = createPos_points(amount);

    getPos_points(M, points, m, n);

    setPos_pointsToMatr(M, points, amount);

    showDynamicMatr(M, m, n);

    deletePos_points(points);
    deleteDynamicMatr(&M, m, n);
}


void sortIncFirstElemStringDynamicMatr(DynamicMatr M, int m, int n)
{
    for(int i = 0; i < m-1; i++)
    {
        for(int k = i+1; k < m; k++)
        {
            if(M[k][0] < M[i][0]) swapRowDynamicMatr(M, m, n, i, k);
        }
    }
}


void matr76()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    sortIncFirstElemStringDynamicMatr(M, m, n);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr77()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    sortDecLastElemColumnDynamicMatr(M, m, n);

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr78()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int i = 0; i < m-1; i++)
    {
       int pos_min_1 = posMinInStringDynamicMatr(M, m, n, i);

        for(int k = i+1; k < m; k++)
        {
            int pos_min_2 = posMinInStringDynamicMatr(M, m, n, k);

            if(M[k][pos_min_2] > M[i][pos_min_1])
            {
                swapRowDynamicMatr(M, m, n, i, k);
            }
        }
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr79()
{
    int m, n;
    printf("m = ");    scanf("%d", &m);
    printf("n = ");    scanf("%d", &n);

    DynamicMatr M = createDynamicMatr(m, n);
    fillDynamicMatrRnd(M, m, n, -5, 5);
    showDynamicMatr(M, m, n);

    for(int j = 0; j < n-1; j++)
    {
       int pos_max_1 = posMaxInColumnDynamicMatr(M, m, n, j);

        for(int k = j+1; k < n; k++)
        {
            int pos_max_2 = posMaxInColumnDynamicMatr(M, m, n, k);

            if(M[pos_max_2][k] < M[pos_max_1][j])
            {
                swapColumnDynamicMatr(M, m, n, j, k);
            }
        }
    }

    showDynamicMatr(M, m, n);

    deleteDynamicMatr(&M, m, n);
}


void matr80()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    double* A = createOneDimentinalMatr_zero(m, n);
    fillOneDimentinalMatr(A, m, n, 0, 5);
    showOneDimentinalMatr(A, m, n);

    double temp = 0;
     for(int i = 0; i < m; i++)
    {
          temp += getValueOneDimentinalMatr(A, m, i, i);
    }

    printf("diag %.2lf ", temp);
    free(A);
}


void matr81()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    double* A = createOneDimentinalMatr_zero(m, n);
    fillOneDimentinalMatr(A, m, n, 0, 5);
    showOneDimentinalMatr(A, m, n);

    double temp = 0;

     for(int i = 0; i < m; i++)
    {
          temp += getValueOneDimentinalMatr(A, m, i, m-i-1);
    }
    temp /= m;

    printf("diag %lf ", temp);
    free(A);
}


void matr82a()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    double* A = createOneDimentinalMatr_zero(m, n);
    fillOneDimentinalMatr(A, m, n, 0, 5);
    showOneDimentinalMatr(A, m, n);

    double temp = 0;
    int i = 0;
    int j = m-1;
    int u = m-1;
    int y = 0;
    while(i < m && j < m && i >= 0 && j >=0)
    {
        while(i < m && j < m && i >= 0 && j >= 0)
        {
            double watch = getValueOneDimentinalMatr(A, m, i, j);
            temp += getValueOneDimentinalMatr(A, m, i, j);
            j++;
            i++;
        }


        if(y > 0) y++;
        if(i == m && j == n) y++;
        if(y == 0) i = 0;
        i = y;

        if(u > 0) u--;
        if(j > n-1) j = u;
        else j = 0;
    }



    printf("diag %lf ", temp);
    free(A);


}void matr82b()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > -m; d--)
    {
        double sum = sumParallelMainDiagonalM(&Matr, d);
        printf("%.2lf  ", sum);
    }

    deleteM(&Matr);
}


void matr83()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > -m; d--)
    {
        double sum = sumParallelSideDiagonalM(&Matr, d);
        printf("%.2lf  ", sum);
    }

    deleteM(&Matr);
}


void matr84()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > -m; d--)
    {
        double ariph = ariphParallelMainDiagonalM(&Matr, d);
        printf("%.2lf  ", ariph);
    }

    deleteM(&Matr);
}


void matr85()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > -m; d--)
    {
        double ariph = ariphParallelSideDiagonalM(&Matr, d);
        printf("%.2lf  ", ariph);
    }

    deleteM(&Matr);
}


void matr86()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > -m; d--)
    {
        double min = minParallelMainDiagonalM(&Matr, d);
        printf("%.2lf  ", min);
    }

    deleteM(&Matr);
}


void matr87()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > -m; d--)
    {
        double max = maxParallelSideDiagonalM(&Matr, d);
        printf("%.2lf  ", max);
    }

    deleteM(&Matr);
}

//Видаляти масив і обнуляти змінні
void matr88()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = -1; d > -m; d--)
    {
        zeroMainDiagonalM(&Matr, d);
    }

    showM(&Matr);

    deleteM(&Matr);
}

void matr89()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > 0; d--)
    {
        zeroMainDiagonalM(&Matr, d);
    }

    showM(&Matr);

    deleteM(&Matr);
}


void matr90()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = 0; d > -n; d--)
    {
        zeroSideDiagonalM(&Matr, d);
    }

    showM(&Matr);

    deleteM(&Matr);
}


void matr91()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d >= 0; d--)
    {
        zeroMainDiagonalM(&Matr, d);
    }

    showM(&Matr);

    deleteM(&Matr);
}


void matr92()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > 0; d--)
    {
        zeroMainDiagonalM(&Matr, d);
        zeroSideDiagonalM(&Matr, d);
    }

    showM(&Matr);

    deleteM(&Matr);
}


void matr93()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");
    for(int d = n-1; d > 0; d--)
    {
        zeroMainDiagonalM(&Matr, d);
    }
    for(int d = -1; d > -m; d--)
    {
        zeroSideDiagonalM(&Matr, d);
    }


    showM(&Matr);

    deleteM(&Matr);
}


void matr94()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");

    for(int d = 0; d > -m; d--)
    {
        zeroMainDiagonalM(&Matr, d);
    }
    for(int d = n-1; d >= 0; d--)
    {
        zeroSideDiagonalM(&Matr, d);
    }


    showM(&Matr);

    deleteM(&Matr);
}


void matr95()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");

    for(int d = 0; d > -m; d--)
    {
        zeroMainDiagonalM(&Matr, d);
        zeroSideDiagonalM(&Matr, d);
    }


    showM(&Matr);

    deleteM(&Matr);
}


void matr96()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");

    transpositionRelativeToMainDiagonalM(&Matr, m, n);

    showM(&Matr);

    deleteM(&Matr);
}


void matr97()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");

    transpositionRelativeToSideDiagonalM(&Matr, m, n);

    showM(&Matr);

    deleteM(&Matr);
}


void matr98()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");

    transpositionRelativeToSideDiagonalM(&Matr, m, n);
    transpositionRelativeToMainDiagonalM(&Matr, m, n);

    showM(&Matr);

    deleteM(&Matr);
}


void matr99()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");

    positiveRotate90degreeM(&Matr, m, n);

    showM(&Matr);

    deleteM(&Matr);
}


void matr100()
{
    int m;
    printf("m = ");    scanf("%d", &m);
    int n = m;

    OneDim Matr = createM_zero(m, n);
    fillM(&Matr, -5, 5);
    showM(&Matr);

    puts("");

    negativeRotate90degreeM(&Matr, m, n);

    showM(&Matr);

    deleteM(&Matr);
}
//Написати дві функції дзеркало навколо вертикальної і горизонтальної осі.
//Для квадратної матриці транспонування, це відзеркалення навкого головної діагоналі, елемент з індексами [i][j] має помінятися місцями з [j] [i].

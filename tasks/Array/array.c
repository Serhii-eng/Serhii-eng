#include "array_tools.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define PI 3.1415926535
//#define N 100
const int N = 100;
void Array1()
{
    int from = 1;
    int to = 10;
    int n = from + rand() % (to - from);
    printf("N: %d\n\n", n);

    int A[N];
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        A[i] = cnt;
        printf("A[%d]: %d\n", i+1, A[i]);
        cnt +=2;
    }
}


void Array2()
{
    int from = 1;
    int to = 10;
    int n = from + rand() % (to - from);
    printf("N: %d\n\n", n);

    int A[N];
    int cnt = 2;
    for(int i = 0; i < n; i++)
    {
        A[i] = cnt;
        cnt *=2;
    }

    for(int i = 0; i < n; i++)
    {
        printf("A[%d]: %d\n", i+1, A[i]);
    }
}


void Array3()
{
    int from = 1;
    int to = 10;
    int n = from + rand() % (to - from);
    printf("n: %d\n\n", n);

    from = 1;
    to = 6;
    int A = from + rand() % (to - from);
    printf("A: %d\n", A);

    from = 1;
    to = 6;
    int D = from + rand() % (to - from);
    printf("D: %d\n\n", D);

    int B[N];
    B[0] = A;
    for(int i = 1; i < n; i++)
    {
        B[i] = B[i-1] + D;
    }

    for(int i = 0; i < n; i++)
    {
        printf("B[%d]: %d\n", i+1, B[i]);
    }
}


void Array4()
{

    int n;
    printf("n: "); scanf("%d", &n);

    double A;
    printf("A: ");   scanf("%lf", &A);

    double D;
    printf("D: "); scanf("%lf", &D);

    double B[N];
    double mul = A;
    for(int i = 0; i < n; i++)
    {
        B[i] = mul;
        printf("B[%d]: %lf\n", i, B[i]);
        mul = A * D;
        D = D * D;
    }
}


void Array5()
{
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);

    srand(t);

    int from = 3;
    int to = 16;
    int n = from + rand() % (to - from);
    printf("n: %d\n\n", n);

    int A[N];
    A[0] = 1;
    A[1] = 1;
    for(int i = 2; i < n; i++)
    {
        A[i] = A[i-2] + A[i-1];
        printf("n%d: %d\n", i+1, A[i]);
    }
}

void Array6()
{
    int from = 3;
    int to = 16;
    int n = 10;
    printf("N: %d\n\n", n);

    from = 1;
    to = 6;
    int A = from + rand() % (to - from);
    printf("A: %d\n\n", A);

    from = 1;
    to = 6;
    int B = from + rand() % (to - from);
    printf("B: %d\n\n", B);
// 3 2 5 10 20 40 80
    int a[N];
    a[0] = A;
    a[1] = B;
    a[2] = A + B;
    for(int i = 3; i < n; i++)
    {
        a[i] = a[i-1] << 1;
    }

     for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}


void Array7()
{
    int n;
    printf(" n = ");    scanf("%d", &n);

    double* A = createDblArray(n);
    showDblArray(A, n);
    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    for(int i = n-1; i >= 0; i--)
    {
        printf("%.2lf ", A[i]);
    }
    puts("");

    free(A);
}


void Array8()
{
    int from = 1;
    int to = 11;
    int n = from + rand() % (to - from);
    printf("N: %d\n\n", n);

    int a[N];
    int K = 0;
    for(int i = 0; i < n; i++)
    {
        a[i] = i+1;
        if(a[i] % 2 != 0)
        {
            printf("a[%d] = %d\n", i, a[i]);
            K++;
        }
    }
    printf("\nK = %d\n", K);
}


void Array9()
{
    int from = 1;
    int to = 11;
    int n = from + rand() % (to - from);
    printf("N: %d\n\n", n);

    int a[N];
    int K = 0;
    for(int i = n-1; i >= 0; i--)
    {
        a[i] = i+1;
        if(a[i] % 2 == 0)
        {
            printf("a[%d] = %d\n", i, a[i]);
            K++;
        }
    }
    printf("\nK = %d\n", K);
}


void Array10()
{
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);

    srand(t);

    int from = 1;
    int to = 11;
    int n = from + rand() % (to - from);
    printf("N: %d\n\n", n);

    int a[N];
    for(int i = 0; i < n; i++)
    {
        a[i] = i+1;
        if(a[i] % 2 == 0)
        {
            printf("a[%d] = %d\n", i, a[i]);
        }
    }

     puts("");

    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] % 2 != 0)
        {
            printf("a[%d] = %d\n", i, a[i]);
        }
    }
}


void Array11()
{
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);

    srand(t);

    int from = 1;
    int to = 11;
    int n = from + rand() % (to - from);
    printf("N: %d\n\n", n);

    from = 1;
    to = 4;
    int K = from + rand() % (to - from);
    printf("K: %d\n\n", K);

    int A[N];
    for(int i = 0; i < n; i++)
    {
        A[i] = i+1;
    }

    for(int i = 0; i < n; i += K)
    {
            printf("A[%d] = %d\n", i, A[i]);
    }
}


void Array12()
{
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);

    srand(t);

    int from = 1;
    int to = 11;
    int n;
    while(true)
    {
        from = 1;
        to = 11;
        n = from + rand() % (to - from);
        if(n % 2 == 0)
        {
            printf("N: %d\n\n", n);
            break;
        }
    }

    int A[N];
    for(int i = 0; i < n; i++)
    {
        A[i] = i+1;
    }

    for(int i = 1; i < n; i += 2)
    {
            printf("A[%d] = %d\n", i, A[i]);
    }
}


void Array13()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    for(int i = n-2; i > 0; i -= 2)
    {
        printf("A[%d] = %.2lf\n", i, A[i]);
    }
}


void Array14()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    for(int i = 0; i < n; i+=2)
    {
        printf("%d ", A[i]);
    }

    for(int i = 1; i < n; i+=2)
    {
        printf("%d ", A[i]);
    }

    free(A);
}


void Array15()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    int i;
    for(i = 0; i < n; i+=2)
    {
        printf("%.2lf ", A[i]);
    }
    i = n - (n % 2)-1;

    int k = (n - 1) / 2 * 2;
    for(int i = k; i >= 0; i-=2)
    {
        printf("%.2lf ", A[i]);
    }

    free(A);
}


void Array16()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    int j = 0;
    int k = n-1;
    while(j <= k)
    {
        printf("%.2lf ", A[j]);
        if(j != k) printf("%.2lf ", A[k]);
        j++;
        k--;
    }

    free(A);
}


void Array17()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    int j = 0;
    int k = n-1;
    int t = 0;
    while(j <= k)
    {
        if(t == 0) printf("%.2lf ", A[j++]);
        if(t == 1) printf("%.2lf ", A[j++]);
        if(t == 2) printf("%.2lf ", A[k--]);
        if(t == 3) printf("%.2lf ", A[k--]);

        t++;
        if(t == 4) t = 0;
    }
}


void Array18()
{
    int n;
    printf("N = "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

   int ans = 0;
   for(int i = 0; i < n-1; i++)
   {
       if(A[i] < A[n-1])
       {
           ans = A[i];
           break;
       }
   }


    printf("ans = %d", ans);

    free(A);
}


void Array19()
{
    int n = 10;

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 51);
    showIntArray(A, n);

    puts("");

    int num = 0;
    for(int i = 1; i < n-1; i++)
    {
        if(A[0] < A[i] && A[n-1] > A[i])
            num = i+1;
    }

    printf("number of element = %d", num);

    free(A);
}

void Array19a()
{
    int n = 10;

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 51);
    showIntArray(A, n);

    puts("");

    int num = -1;
    for(int i = n-2; i > 0; i--)
    {
        if(A[0] < A[i] && A[n-1] > A[i])
        {
            num = i+1;
            break;
        }
    }

    printf("number of element = %d", num);

    free(A);
}



void Array20()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 51);
    showDblArray(A, n);

    int K, L;
    printf("K = "); scanf("%d", &K);
    printf("L = "); scanf("%d", &L);

    double sum = 0;
    int cnt = 0;
    for(int i = K; i <= L; i++)
    {
        sum = sum + A[i];
        cnt++;
    }

    double average = sum / cnt;

    printf("suma of elements = %lf\n", sum);
    printf("average of elements = %lf\n", average);

    free(A);
}


void Array21()
{
    int from = 10;
    int to = 41;
    int K = from + rand() % (to - from);
    printf("K: %d", K);

    puts("");

    from = 20;
    to = 51;
    int L = from + rand() % (to - from);
    printf("L: %d", L);

    puts("");

    from = 30;
    to = 51;
    int n = from + rand() % (to - from);
    printf("N: %d", n);

    puts("");
    puts("");

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 51);
    showDblArray(A, n);

    puts("");
    double middle = 0;
    if(1 <= K && K <= L && L <= n)
    {
    double sum = 0;
    double cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(K <= A[i] && A[i] <= L)
            {
                sum = sum + A[i];
                cnt++;
            }
        }
        middle = sum / cnt;
    }

    printf("middle ariphmeticals = %lf", middle);

    free(A);
}


void Array22()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 51);
    showDblArray(A, n);

    int K, L;
    printf("K = "); scanf("%d", &K);
    printf("L = "); scanf("%d", &L);

    double sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < K || i > L)
        {
            sum = sum + A[i];
            cnt++;
        }
    }

    double average = sum / cnt;

    printf("suma of elements = %lf\n", sum);
    printf("average of elements = %lf\n", average);

    free(A);
}


void Array22a()
{
    int n;
    printf("N = "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 51);
    showDblArray(A, n);

    int K, L;
    printf("K = "); scanf("%d", &K);
    printf("L = "); scanf("%d", &L);

    double sum = 0;
    int cnt = 0;
    for(int i = 0; i < K; i++)
    {
            sum = sum + A[i];
            cnt++;
    }
    for(int i = L+1; i < n; i++)
    {
            sum = sum + A[i];
            cnt++;
    }

    double average = sum / cnt;

    printf("suma of elements = %lf\n", sum);
    printf("average of elements = %lf\n", average);

    free(A);
}


void Array23()
{
    int from = 10;
    int to = 41;
    int K = from + rand() % (to - from);
    printf("K: %d", K);

    puts("");

    from = 20;
    to = 51;
    int L = from + rand() % (to - from);
    printf("L: %d", L);

    puts("");

    from = 30;
    to = 51;
    int n = from + rand() % (to - from);
    printf("N: %d", n);

    puts("");
    puts("");

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 51);
    showDblArray(A, n);

    puts("");
    double middle = 0;
    if(1 <= K && K <= L && L <= n)
    {
    double sum = 0;
    double cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if( A[i] < K || L < A[i])
            {
                sum = sum + A[i];
                cnt++;
            }
        }
        if(cnt > 0)
            middle = sum / cnt;
    }

    printf("middle ariphmeticals = %lf", middle);

    free(A);
}


void Array24()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    int* A = createIntArray(n);

    for(int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i); scanf("%d", &A[i]);
    }

    int D = A[1] - A[0];
    bool ok = true;
    for(int i = 2; i < n; i++)
    {
        int d = A[i] - A[i-1];
        if(d != D)
        {
            ok = false;
            break;
        }
    }

     puts("");
     if(ok)
     {
        printf("D = %d", D);
     }
     else
     {
         puts("it's not a progression");
     }

    free(A);
}


void Array25()
{
    Array4();
    puts("");
    puts("////////////////");
    puts("");

    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);

    for(int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i); scanf("%lf", &A[i]);
    }

    double a = A[0];
    double temp;
    double D = temp = A[1] / A[0];
    double mul = 0;
    for(int i = 1; i < n; i++)
    {
        mul = a * temp;
        temp = temp * temp;
        if(A[i] != mul)
        {
            D = 0;
            break;
        }
    }

    puts("");

    printf("D = %lf", D);

    free(A);
}


void Array26()
{
    int n;
    printf("N = "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -10, 11);
    showIntArray(A, n);

    int pos = -1;
    for(int i = 1; i < n; i++)
    {
        if(abs(A[i-1] % 2) == abs(A[i] % 2))
        {
            pos = i;
            break;
        }
    }

    printf("pos = %d\n", pos);

    free(A);
}


void Array27()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);

    for(int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i); scanf("%lf", &A[i]);
    }

    int num = 0;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] > 0 && flag == 0)
        {
            flag = 1;
            continue;
        }
        if(A[i] < 0 && flag == 1)
        {
            flag = 0;
            continue;
        }
        num = i;
        break;
    }

    printf("num = %d", num);

    free(A);
}


void Array27a()
{
    int n;
    printf("N = "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -10, 11);
    showIntArray(A, n);

    int pos = -1;
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] * A[i] > 0)
        {
            pos = i;
            break;
        }
    }

    printf("pos = %d\n", pos);

    free(A);
}


void Array28()
{
    int n;
    printf("N = "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -10, 11);
    showIntArray(A, n);

    int min = A[0];
    for(int i = 2; i < n; i+=2)
    {
        if(A[i] < min)
        {
            min = A[i];
        }
    }

    puts("");
    printf("min = %d", min);

    free(A);
}


void Array29()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);

    for(int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i); scanf("%lf", &A[i]);
    }

    int max;
    int num;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            max = A[i];
            num = i;
            continue;
        }
        if(A[i] > max && i % 2 == 0)
        {
            max = A[i];
            num = i;
        }
    }

    puts("");
    printf("min = %d", max);
    puts("");
    printf("num = %d", num);

    free(A);
}


void Array30()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    int from = 1;
    int to = 16;
    for(int i = 0; i < n; i++)
    {
        A[i] = from + rand() % (to - from);
        printf("%.1lf ", A[i]);
    }

    puts("");
    puts("");

    int cnt = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(A[i] > A[i+1])
        {
            printf("%d ", i);
            cnt++;
        }
    }

    puts("");
    printf("cnt = %d", cnt);

    free(A);
}


void Array31()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    int from = 1;
    int to = 16;
    for(int i = 0; i < n; i++)
    {
        A[i] = from + rand() % (to - from);
        printf("%.1lf ", A[i]);
    }

    puts("");
    puts("");

    int cnt = 0;
    for(int i = n-1; i > 0; i--)
    {
        if(A[i] > A[i-1])
        {
            printf("%d ", i);
            cnt++;
        }
    }

    puts("");
    printf("cnt = %d", cnt);

    free(A);
}


void Array32()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, 1, 21);
    showDblArray(A, n);

    puts("");

    for(int i = 0; i < n; i++)
    {
        if(is_local_min(A, n, i))
        {
            printf("%d ", i);
            break;
        }
    }

    free(A);
}


void Array33()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, 1, 21);
    showDblArray(A, n);

    puts("");

    int num = 0;
    for(int i = 1; i < n-1; i++)
    {
        if(A[i-1] < A[i] && A[i] > A[i+1])
        {
            num = i;
        }
    }
            printf("%d ", num);

    free(A);
}


void Array34() // Передивитись//////////
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, -20, 21);
    showDblArray(A, n);

    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(is_local_min(A, n, i))
        {
            k++;
        }
    }

    double* B = createDblArray(k);

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(is_local_min(A, n, i))
        {
            B[j++] = A[i];
        }
    }
    showDblArray(B, k);

    double max = B[0];
    for(int i = 1; i < k; i++)
    {
        if(B[i] > max)
        {
            max = B[i];
        }
    }
    printf("max = %.2lf\n", max);

    free(A);
    free(B);
}


void Array35()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, 1, 21);
    showDblArray(A, n);

    puts("");

    bool first = true;
    double min = 0;
    int num = 0;
    for(int i = 1; i < n-1; i++)
    {
        if(A[i-1] < A[i] && A[i] > A[i+1])
        {
           if(first)
           {
               min = A[i];
               num = i;
               first = false;
           }
           else if(A[i] < min)
           {
               min = A[i];
               num = i;
           }
        }
    }

    printf("min = %.2lf\n", min);
    printf("num = %d", num);

    free(A);
}


void Array36()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, 1, 21);
    showDblArray(A, n);

    puts("");

    double _max = 0;
    bool first = true;
    int num = 0;
    for(int i = 1; i < n-1; i++)
    {
        if(!is_local_max(A, n, i) && !is_local_min(A, n, i))
        {
            if(first)
            {
                _max = A[i];
                num = i;
                first = false;
            }
            else if(A[i] > _max)
            {
                _max = A[i];
                num = i;
            }
        }
    }

    printf("max = %.2lf\n", _max);
    printf("num = %d", num);

    free(A);
}


int Array38a(double* A, int n)
{
    int cnt = 0;
    int flag = 0;
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] > A[i])
        {
            flag = 1;
        }
        if(A[i-1] <= A[i] && flag == 1 || i == n-1 && flag == 1)
        {
            flag = 0;
            cnt++;
        }
    }

    return cnt;
}


void Array37()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, 1, 21);
    showDblArray(A, n);

    puts("");

    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(is_local_max(A, n, i)) cnt++;
    }
    printf("count = %d", cnt);

    free(A);
}


void Array38() //переробив
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, 1, 21);
    showDblArray(A, n);

    puts("");

    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(is_local_min(A, n, i)) cnt++;
    }

    printf("count = %d", cnt);

    free(A);
}


void Array39() //переробив
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);


    fillDblArrayRnd(A, n, 1, 21);
    showDblArray(A, n);

    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(!is_local_min(A, n, i) && !is_local_max(A, n, i)) cnt++;
    }

    printf("count = %d", cnt);

    free(A);
}


void Array40()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);

    fillDblArrayRnd(A, n, -20, 21);
    showDblArray(A, n);

    double R;
    printf("R: "); scanf("%lf", &R);
    puts("");

    int pos = 0;
    double num = A[0];
    double min_diff = fabs(R - A[0]);
    for(int i = 0; i < n; i++)
    {
        double diff = fabs(R - A[i]);
        if(diff < min_diff)
        {
            min_diff = diff;
            num = A[i];
            pos = i;
        }
    }

    printf("pos = %d\n", pos);
    printf("num = %.2lf\n", num);
    printf("diff = %.2lf", min_diff);

    free(A);
}


void Array41()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);

    fillDblArrayRnd(A, n, -5, 21);
    showDblArray(A, n);

    puts("");

    double first = A[0];
    double second = A[1];
    double sum = A[0] + A[1];
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] + A[i] > sum)
        {
            sum = A[i-1] + A[i];
            first = A[i-1];
            second = A[i];
        }
    }

    printf("first = %.2lf\n", first);
    printf("second = %.2lf\n", second);
    printf("suma = %.2lf\n", sum);

    free(A);
}


void Array42() //переробив
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    double* A = createDblArray(n);

    fillDblArrayRnd(A, n, -20, 21);
    showDblArray(A, n);

    double R;
    printf("R: "); scanf("%lf", &R);

    puts("");

    double first = A[0];
    double second = A[1];
    double min_diff = fabs(R - (A[0] + A[1]));
    for(int i = 2; i < n; i++)
    {
        double diff = fabs(R - (A[i-1] + A[i]));
        if(diff < min_diff)
        {
            min_diff = diff;
            first = A[i-1];
            second = A[i];
        }
    }

    printf("first = %.2lf\n", first);
    printf("second = %.2lf\n", second);
    printf("diff = %.2lf", min_diff);

    free(A);
}


void Array43a()
{
    int n;
    printf("N: "); scanf("%d", &n);

    puts("");

    int* A = createIntArray(n);

    fillIntArrayRnd(A, n, -3, 4);
    sort_Int_Array(A, n);

    showIntArray(A, n);

    puts("");

    int counter = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] != A[i]) counter++;
    }

    printf("counter = %d", counter);

    free(A);
}


void Array44() //переробив з транспозицією
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);

    transposition_Int_Array(A, n);

    int x = rand() %  n;
    int y = rand() %  n;
    A[x] = A[y];

    showIntArray(A, n);

    int first = -1;
    int second = -1;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i] == A[j])
            {
                first = i;
                second = j;
                i = n;
            }
        }
    }
    printf("first = %d\n", first);
    printf("second = %d\n", second);


    free(A);
}


void Array45()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);

    fillDblArrayRnd(A, n, -20, 21);

    puts("");

    showDblArray(A, n);

    double diff = fabs(A[0] - A[1]);
    int first = -1;
    int second = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j) continue;
            if(fabs(fabs(A[i]) - fabs(A[j])) < diff)
            {
                diff = fabs(fabs(A[i]) - fabs(A[j]));
                if(i < j)
                {
                    first = i;
                    second = j;
                }
                else
                {
                    first = j;
                    second = i;
                }
            }
        }
    }
    printf("first = %d\n", first);
    printf("second = %d\n", second);

    free(A);
}


void Array46()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);

    fillDblArrayRnd(A, n, -20, 21);

    puts("");

    showDblArray(A, n);

    double R;
    printf("R: "); scanf("%lf", &R);
    R = fabs(R);

    double diff = -1;
    if(n > 0)
    {
        diff = fabs(R - (fabs(A[0]) + fabs(A[1])));
    }
    double first = -1;
    double second = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(fabs(R - (fabs(A[i]) + fabs(A[j]))) < diff)
            {
                diff = fabs(R - (fabs(A[i]) + fabs(A[j])));
                if(i < j)
                {
                    first = A[i];
                    second = A[j];
                }
                else
                {
                    first = A[j];
                    second = A[i];
                }
            }
        }
    }
    printf("first = %.2lf\n", first);
    printf("second = %.2lf\n", second);

    free(A);
}


void Array47()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);

    fillIntArrayRnd(A, n, -20, 21);

    puts("");

    showIntArray(A, n);

    int cnt = n;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(A[i] == A[j])
            {
                cnt--;
                break;
            }
        }
    }
    printf("count = %d\n", cnt);

    free(A);
}


void Array48()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);

    fillIntArrayRnd(A, n, -20, 21);

    puts("");

    showIntArray(A, n);

    puts("");

    int amount = 0;
    for(int i = 0; i < n; i++)
    {
    int cnt = 1;
        for(int j = i; j < n; j++)
        {
            if(i == j) continue;
            if(A[i] == A[j]) cnt++;
        }
        if(cnt > amount) amount = cnt;
    }
    // чому змінна маючи нульове значення cnt = cnt / cnt то буде 1?
    printf("max amount = %d\n", amount);

    free(A);
}


void Array48b() //Рахує кількість чисел які повторюються
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);

    fillIntArrayRnd(A, n, -20, 21);

    puts("");

    showIntArray(A, n);

    puts("");

    int* B = createIntArray(n);

    copy_Int_Array(A, B, n);

    sort_Int_Array(B, n);

    showIntArray(B, n);

    int total = 0;
    for(int i = 0; i < n-1; i++)
    {
        int cnt = 1;
        for(int j = i+1; j < n; j++)
        {
            if(B[i] == B[j])
            {
                cnt++;
                if(B[i] != B[j+1])
                {
                    total += cnt;
                    i = j;
                    break;
                }
            }
        }
    }

    printf("total = %d\n", total);

    free(A);
}


void Array49()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);

    for(int i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);    scanf("%d", &A[i]);
    }

    showIntArray(A, n);


    int num = -1;
    for(int i = 0; i < n; i++)
    {
        int ok = 0;
        for(int j = 0; j < n; j++)
        {
            if(A[j] == i+1)
            {
                ok++;
            }
            if(ok > 1)
            {
                num = j;
                goto stop;
            }
        }
        if(ok < 1)
        {
            num = i;
            stop: break;
        }
    }

    printf("number = %d", num);

    free(A);
}


void Array50()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);

    transposition_Int_Array(A, n);

    showIntArray(A, n);

    int cnt = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i] > A[j]) cnt++;
        }
    }

    printf("cnt = %d", cnt);

    free(A);
}


void Array51()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);
    double* B = createDblArray(n);

    fillDblArrayRnd(A, n, -20, 21);
    fillDblArrayRnd(B, n, -20, 21);

    showDblArray(A, n);
    showDblArray(B, n);

    for(int i = 0; i < n; i++)
    {
        swap_Dbl_Values(&A[i], &B[i]);
    }

    puts("");

    showDblArray(A, n);
    showDblArray(B, n);

    free(A);
    free(B);
}


void Array52()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);

    fillDblArrayRnd(A, n, -20, 21);

    double k = 5;
    double* B = createDblArray(n);
    for(int i = 0; i < n; i++)
    {
        if(A[i] < k)    B[i] = A[i] * 2;
        else    B[i] = A[i] / 2;
    }

    puts("");

    showDblArray(A, n);
    showDblArray(B, n);

    free(A);
    free(B);
}


void Array53()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -20, 21);
    showDblArray(A, n);

    double* B = createDblArray(n);
    fillDblArrayRnd(B, n, -20, 21);
    showDblArray(B, n);


    double* C = createDblArray(n);
    for(int i = 0; i < n; i++)
    {
        if(A[i] >= B[i]) C[i] = A[i];
        else C[i] = B[i];
    }

    puts("");

    showDblArray(C, n);

    free(A);
    free(B);
    free(C);
}


void Array54()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -20, 21);
    puts("");
    showIntArray(A, n);
    puts("");

    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i]%2 == 0) k++;
    }

    int* B = createIntArray(k);
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i]%2 == 0) B[j++] = A[i];
    }

    printf("size of array B = %d\n\n", k);
    showIntArray(B, k);

    free(A);
    free(B);
}


void Array55()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -20, 21);
    puts("");
    showIntArray(A, n);
    puts("");

    int k = n - (n/2);
    int* B = createIntArray(k);
    int j = 0;
    for(int i = 0; i < n; i+=2)
    {
        B[j++] = A[i];
    }

    printf("size of array B = %d\n\n", k);
    showIntArray(B, k);

    free(A);
    free(B);
}


void Array56()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -20, 21);
    puts("");
    showIntArray(A, n);
    puts("");

    int k = n/3;
    int* B = createIntArray(k);
    int j = 0;
    for(int i = 2; i < n; i+=3)
    {
        B[j++] = A[i];
    }

    printf("size of array B = %d\n\n", k);
    showIntArray(B, k);

    free(A);
    free(B);
}


void Array57()
{
    int n;
    printf("N: "); scanf("%d", &n);

    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -20, 21);
    puts("");
    showIntArray(A, n);
    puts("");

    int* B = createIntArray(n);
    int j = 0;
    for(int i = 1; i < n; i+=2)
    {
        B[j++] = A[i];
    }

    for(int i = 0; i < n; i+=2)
    {
        B[j++] = A[i];
    }

    showIntArray(B, n);

    free(A);
    free(B);
}


void Array58()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -20, 21);
    puts("");
    showDblArray(A, n);
    puts("");

    double sum = 0;
    double* B = createDblArray(n);
    for(int i = 0; i < n; i++)
    {
        sum = sum + A[i];
        B[i] = sum;
    }

    showDblArray(B, n);

    free(A);
    free(B);
}


void Array59()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, 21);
    puts("");
    showDblArray(A, n);
    puts("");

    double sum = 0;
    double* B = createDblArray(n);
    for(int i = 0; i < n; i++)
    {
        sum = sum + A[i];
        B[i] = sum / (i+1);
    }

    showDblArray(B, n);

    free(A);
    free(B);
}


void Array60()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, 21);
    puts("");
    showDblArray(A, n);
    puts("");

    int j = 0;
    double sum = 0;
    double* B = createDblArray(n);
    for(int i = n-1; i >= 0; i--)
    {
        sum = sum + A[i];
        B[j++] = sum;
    }

    showDblArray(B, n);

    free(A);
    free(B);
}


void Array61()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, 21);
    puts("");
    showDblArray(A, n);
    puts("");

    int j = 0;
    double sum = 0;
    double* B = createDblArray(n);
    for(int i = n-1; i >= 0; i--)
    {
        sum = sum + A[i];
        B[j++] = sum / (n-i);
    }

    showDblArray(B, n);

    free(A);
    free(B);
}



void Array62()
{
    int n;
    printf("N: "); scanf("%d", &n);

    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -20, 21);
    puts("");
    showDblArray(A, n);
    puts("");

    int b = 0;
    int c = 0;

    for(int i = 0; i < n; i++)
    {
        if(A[i] > 0) b++;
        else if(A[i] < 0) c++;
    }
    int k = 0;
    int j = 0;
    double* B = createDblArray(b);
    double* C = createDblArray(c);
    for(int i = 0; i < n; i++)
    {
        if(A[i] > 0) B[k++] = A[i];
        else if(A[i] < 0) C[j++] = A[i];
    }

    printf("size B = %d\n", b);
    showDblArray(B, b);
    printf("size C = %d\n", c);
    showDblArray(C, c);

    free(A);
    free(B);
    free(C);
}


void Array63() //Зробити 64ту задачу, через функцію.
{
    int n, m;
    printf("N: "); scanf("%d", &n);
    printf("M: "); scanf("%d", &m);

    double* A = createDblArray(n);
    double* B = createDblArray(m);
    fillDblArrayRnd(A, n, -20, 21);
    fillDblArrayRnd(B, m, -20, 21);
    sort_Dbl_Array(A, n);
    sort_Dbl_Array(B, m);

    showDblArray(A, n);
    showDblArray(B, m);

    double* C = merge_two_sorted_Dbl_Arrays(A, B, n, m);

    showDblArray(C, n+m);

    free(A);
    free(B);
    free(C);
}


void Array64() //Зробив задачу, через функцію.
{
    int a, b, c;
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);

    double* A = createDblArray(a);
    double* B = createDblArray(b);
    double* C = createDblArray(c);
    fillDblArrayRnd(A, a, -20, 21);
    fillDblArrayRnd(B, b, -20, 21);
    fillDblArrayRnd(C, c, -20, 21);
    dec_sort_Dbl_Array(A, a);
    dec_sort_Dbl_Array(B, b);
    dec_sort_Dbl_Array(C, c);

    showDblArray(A, a);
    showDblArray(B, b);
    showDblArray(C, c);
    double* AB = createDblArray(a+b);
    //dec_sort_two_Dbl_Arrays(A, B, AB, a, b);

    double* D = createDblArray(a+b+c);
    //dec_sort_two_Dbl_Arrays(AB, C, D, a+b, c);

    showDblArray(D, a+b+c);

    free(A);
    free(B);
    free(C);
    free(D);
    free(AB);
}


void Array65()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);
    double Ak = A[K];
    for(int i = 0; i < n; i++)
    {
        A[i] = A[i] + Ak;
    }
     showDblArray(A, n);

    free(A);
}


void Array66()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -10, 11);
    showIntArray(A, n);

    int even_num = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
        {
            even_num = A[i];
            break;
        }
    }
    printf("even_num = %d\n", even_num);

    for(int i = 0; i < n; i++)
    {
        A[i] = A[i] + even_num;
    }
    showIntArray(A, n);

    free(A);
}


void Array67()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -10, 11);
    showIntArray(A, n);

    int even_num = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 != 0)
        {
            even_num = A[i];
        }
    }
    printf("even_num = %d\n", even_num);

    for(int i = 0; i < n; i++)
    {
        A[i] = A[i] + even_num;
    }
    showIntArray(A, n);

    free(A);
}


void Array68()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int min_pos = 0;
    int max_pos = 0;
    double min, max;
    min = max = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] < min)
        {
            min = A[i];
            min_pos = i;
        }
        if(A[i] > max)
        {
            max = A[i];
            max_pos = i;
        }
    }

    A[min_pos] = max;
    A[max_pos] = min;
    showDblArray(A, n);

    free(A);
}


void Array69()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    for(int i = 1; i < n; i+=2)
    {
        swap_Dbl_Values(&A[i-1], &A[i]);
    }

    showDblArray(A, n);

    free(A);
}

void Array70()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    for(int i = 0; i < n/2; i++)
    {
        swap_Dbl_Values(&A[i], &A[n/2+i]);
    }

    showDblArray(A, n);

    free(A);
}


void Array71()//Переробив з функциєю.
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    reverse_Dbl_Array(A, n, 0, n-1);
    showDblArray(A, n);

    free(A);
}


void Array72()//Переробив з функциєю.
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K, L;
    printf("K: "); scanf("%d", &K);
    printf("L: "); scanf("%d", &L);

    reverse_Dbl_Array(A, n, K, L);
    showDblArray(A, n);

    free(A);
}


void Array73()//Переробив з функциєю.
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K, L;
    printf("K: "); scanf("%d", &K);
    printf("L: "); scanf("%d", &L);

    reverse_Dbl_Array(A, n, K+1, L-1);
    showDblArray(A, n);

    showDblArray(A, n);

    free(A);
}


void Array74()//Переробив з функциєю.
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int from = get_min_pos_Dbl_Array(A, n);
    int to = get_max_pos_Dbl_Array(A, n);
    if(from > to)
    {
        swap_Int_Values(&from, &to);
    }

    for(int i = from+1; i < to; i++)
    {
        A[i] = 0;
    }

    showDblArray(A, n);

    free(A);
}


void Array75()//Переробив з функциєю.
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int a = get_min_pos_Dbl_Array(A, n);
    int b = get_max_pos_Dbl_Array(A, n);
    if(a > b)
    {
        swap_Int_Values(&a, &b);
    }

    reverse_Dbl_Array(A, n, a, b);

    showDblArray(A, n);

    free(A);
}


void Array76() //переробити використовуючи додатковий масив.
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);
    char* map = (char*) malloc(n);
    for(int i = 0; i < n; i++)
    {
        map[i] = '0';
        if(is_local_max(A, n, i)) map[i] = '1';
    }
    for(int i = 0; i < n; i++)
    {
        putchar(map[i]);
    }
    puts("");

    for(int i = 0; i < n; i++)
    {
        if(map[i] == '1')
        {
            A[i] = 0;
        }
    }

    showDblArray(A, n);

    free(A);
}


void Array77()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(is_local_min(A, n, i)) A[i] = A[i] * A[i];
    }

    showDblArray(A, n);

    free(A);
}


void Array78()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);
    double* B = createDblArray(n);

    B[0] = (A[0] + A[1]) / 2;
    B[n-1] = (A[n-1] + A[n-2]) / 2;
    for(int i = 1; i < n-1; i++)
    {
        B[i] = (A[i-1] + A[i] + A[i+1]) / 3;
    }
    free(A);
    A = B;
    showDblArray(A, n);

    free(A);
}


void Array79()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K = 1;
    shift_right_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}


void Array80()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K = 1;
    shift_left_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}


void Array81()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);
    shift_right_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}

void Array82()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);
    shift_left_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}


void Array83()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K = 1;
    cyclic_shift_right_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}


void Array84()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K = 1;
    cyclic_shift_left_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}


void Array85()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);
    cyclic_shift_right_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}


void Array86()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);
    cyclic_shift_left_side_Dbl_Array(A, n, K);

    showDblArray(A, n);

    free(A);
}


void Array87()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, n);
    sort_Dbl_Array(A, n);
    A[0] = rand() % n;

    showDblArray(A, n);

    for(int i = 1; i < n; i++)
    {
        if(A[i-1] > A[i])
        {
            swap_Dbl_Values(&A[i-1], &A[i]);
        }
        showDblArray(A, n);
    }

    free(A);
}


void Array88()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, n);
    sort_Dbl_Array(A, n);
    A[n-1] = rand() % n;

    showDblArray(A, n);

    for(int i = n-1; i > 0; i--)
    {
        if(A[i-1] > A[i])
        {
            swap_Dbl_Values(&A[i-1], &A[i]);
        }
        showDblArray(A, n);
    }

    free(A);
}


void Array89()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, n);
    dec_sort_Dbl_Array(A, n);
    A[rand() % n] = rand() % n;

    showDblArray(A, n);

     for(int i = 1; i < n; i++)
    {
        if(A[i-1] < A[i])
        {
            swap_Dbl_Values(&A[i-1], &A[i]);
        }
        showDblArray(A, n);
    }

    for(int i = n-1; i > 0; i--)
    {
        if(A[i-1] < A[i])
        {
            swap_Dbl_Values(&A[i-1], &A[i]);
        }
        showDblArray(A, n);
    }

    free(A);
}


void Array90() //Переписати функцію переписавши в масив правильного розміру
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, n);
    showDblArray(A, n);

    int k;
    printf("K: "); scanf("%d", &k);
    remove_from_Dbl_Array(&A, &n, k);
    showDblArray(A, n);

    free(A);
}


void Array91()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 0, n);
    showDblArray(A, n);

    int k, l;
    printf("K: "); scanf("%d", &k);
    printf("L: "); scanf("%d", &l);
    int diff = l - k;
    for(int i = 0; i <= diff; i++)
    {
        remove_from_Dbl_Array(&A, &n, k);
    }

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array92()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 0, n);
    showIntArray(A, n);

    /*
    int i = 0;
    while(i < n)
    {
        if(A[i] % 2 == 0) i++;
        else delete_elem_Int_Array(A, &n, i);
    }
    */

    for(int i = n-1; i >= 0; i--)
    {
        if(A[i] % 2 != 0)
        {
            remove_from_Int_Array(&A, &n, i);
        }
    }

    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array93()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

    int NN = (n-1)/2*2;//Остання парна позиція в масиві.
    //int NN = n/2*2-1;//Остання не парна позиція в масиві.
    for(int i = NN; i >= 0; i-=2)
    {
        remove_from_Int_Array(&A, &n, i);
    }

    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array94() //Переробити
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

    int NN = n/2*2-1;//Остання не парна позиція в масиві.
    for(int i = NN; i >= 0; i-=2)
    {
        remove_from_Int_Array(&A, &n, i);

    }


    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array95()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 4);
    showIntArray(A, n);

//    int i = 1;
//    while(i < n)
//    {
//        if(A[i-1] == A[i]) delete_elem_Int_Array(A, &n, i);
//        else i++;
//    }

    for(int i = n-1; i > 0; i--)
    {
        if(A[i-1] == A[i]) remove_from_Int_Array(&A, &n, i);
    }

    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array96() //Передивитись
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

//    for(int i = 0; i < n-1; i++)
//    {
//        int j = i+1;
//        while(j < n)
//        {
//            if(A[i] == A[j]) delete_elem_Int_Array(A, &n, j);
//            else j++;
//        }
//    }

    for(int i = n-1; i > 0; i--)
    {
        bool ok = false;
        for(int j = 0; j < i; j++)
        {
            if(A[j] == A[i])
            {
                ok = true;
                break;
            }
        }
        if(ok) remove_from_Int_Array(&A, &n, i);
    }

    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array97()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

    reverse_Int_Array(A, n, 0, n-1);
    for(int i = n-1; i > 0; i--)
    {
        bool ok = false;
        for(int j = 0; j < i; j++)
        {
            if(A[j] == A[i])
            {
                ok = true;
                break;
            }
        }
        if(ok) remove_from_Int_Array(&A, &n, i);
    }
    reverse_Int_Array(A, n, 0, n-1);

    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array98()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

    for(int i = n-1; i > 0; i--)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(A[j] == A[i])
            {
                cnt++;
            }
        }

        if(cnt == 2)
        {
            int x = A[i];
            for(int k = n-1; k >= 0; k--)
            {
                if(A[k] == x)
                {
                    remove_from_Int_Array(&A, &n, k);
                }
            }
            i-=cnt-1;
        }
    }

//    int del;
//    printf("del if amount smoller than: "); scanf("%d", &del);
//    int k = n;
//    int* B = createIntArray(k);
//    for(int i = 0; i < n-1; i++)
//    {
//        int cnt = 0;
//        if(B[i] == 0)
//        {
//            cnt = 1;
//            for(int j = i+1; j < n; j++)
//            {
//                if(A[j] == A[i])
//                {
//                    cnt++;
//                }
//            }
//        }
//        if(B[i] == 0 && cnt >= del)
//        {
//            B[i] = 1;
//            for(int j = i+1; j < n; j++)
//            {
//                if(A[j] == A[i])
//                {
//                    B[j] = 1;
//                }
//            }
//        }
//    }
//
//    showIntArray(B, n);
//
//    for(int i = 0; i < n; i++)
//    {
//        if(B[i] == 0)
//        {
//            delete_elem_Int_Array(A, &n, i);
//            delete_elem_Int_Array(B, &k, i);
//            i--;
//        }
//    }

    printf("Size array = %d\n", n);

    showIntArray(A, n);

    free(A);
    //free(B);
}


void Array99()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

    int del;
    printf("del if amount smoller than: "); scanf("%d", &del);
    int k = n;
    int* B = createIntArray(k);
    for(int i = 0; i < n-1; i++)
    {
        int cnt = 0;
        if(B[i] == 0)
        {
            cnt = 1;
            for(int j = i+1; j < n; j++)
            {
                if(A[j] == A[i])
                {
                    cnt++;
                }
            }
        }
        if(B[i] == 0 && cnt >= del)
        {
            B[i] = 1;
            for(int j = i+1; j < n; j++)
            {
                if(A[j] == A[i])
                {
                    B[j] = 1;
                }
            }
        }
    }

    showIntArray(B, n);

    for(int i = 0; i < n; i++)
    {
        if(B[i] == 1)
        {
            delete_elem_Int_Array(A, &n, i);
            delete_elem_Int_Array(B, &k, i);
            i--;
        }
    }

    printf("Size array = %d\n", n);

    showIntArray(A, n);

    free(A);
    free(B);
}


void Array100()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 10);
    showIntArray(A, n);

    int del;
    printf("del if amount smoller than: "); scanf("%d", &del);
    int k = n;
    int* B = createIntArray(k);
    for(int i = 0; i < n-1; i++)
    {
        int cnt = 0;
        if(B[i] == 0)
        {
            cnt = 1;
            for(int j = i+1; j < n; j++)
            {
                if(A[j] == A[i])
                {
                    cnt++;
                }
            }
        }
        if(B[i] == 0 && cnt < del || cnt > del)
        {
            B[i] = 1;
            for(int j = i+1; j < n; j++)
            {
                if(A[j] == A[i])
                {
                    B[j] = 1;
                }
            }
        }
    }

    showIntArray(B, n);

    for(int i = 0; i < n; i++)
    {
        if(B[i] == 0)
        {
            delete_elem_Int_Array(A, &n, i);
            delete_elem_Int_Array(B, &k, i);
            i--;
        }
    }

    printf("Size array = %d\n", n);

    showIntArray(A, n);

    free(A);
    free(B);
}


void Array101()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 10);
    showDblArray(A, n);

    int k;
    printf("K: "); scanf("%d", &k);
    double value = 0;
    insert_into_Dbl_Array(&A, &n, k, value);

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array102()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 10);
    showDblArray(A, n);

    int k;
    printf("K: "); scanf("%d", &k);
    double value = 0;
    insert_into_Dbl_Array(&A, &n, k+1, value);

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array103()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 10);
    showDblArray(A, n);

    int pos_min = get_min_pos_Dbl_Array(A, n);
    inserting_elem_Dbl_Array(A, &n, pos_min);

    int pos_max = get_max_pos_Dbl_Array(A, n);
    inserting_elem_Dbl_Array(A, &n, pos_max+1);

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array104()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 10);
    showDblArray(A, n);


    int k, m;
    printf("K: "); scanf("%d", &k);
    printf("M: "); scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        inserting_elem_Dbl_Array(A, &n, k);
    }



    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array105()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 10);
    showDblArray(A, n);


    int k, m;
    printf("K: "); scanf("%d", &k);
    printf("M: "); scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        inserting_elem_Dbl_Array(A, &n, k+1);
    }

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array106()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 10);
    showDblArray(A, n);

    for(int i = 0; i < n; i+=2)
    {
        double temp = A[i];
        inserting_elem_Dbl_Array(A, &n, i+1);
        i++;
        A[i] = temp;
    }

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array107()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, 1, 10);
    showDblArray(A, n);

    for(int i = 1; i < n; i+=2)
    {
        for(int j = 0; j < 2; j++)
        {
            double temp = A[i];
            inserting_elem_Dbl_Array(A, &n, i+1);
            i++;
            A[i] = temp;
        }
    }

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array108()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(A[i] > 0)
        {
            inserting_elem_Dbl_Array(A, &n, i);
            i++;
        }
    }

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array109()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(A[i] < 0)
        {
            inserting_elem_Dbl_Array(A, &n, i+1);
            i++;
        }
    }

    printf("Size array = %d\n", n);
    showDblArray(A, n);

    free(A);
}


void Array110()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -10, 11);
    showIntArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
        {
            int temp = A[i];
            inserting_elem_Int_Array(A, &n, i+1);
            i++;
            A[i] = temp;
        }
    }

    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array111()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, -10, 11);
    showIntArray(A, n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(A[i] % 2 != 0)
            {
                int temp = A[i];
                inserting_elem_Int_Array(A, &n, i+1);
                i++;
                A[i] = temp;
            }
        }
    }

    printf("Size array = %d\n", n);
    showIntArray(A, n);

    free(A);
}


void Array112()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    buble_sort_Dbl_Array(A, n);

    showDblArray(A, n);

    free(A);
}


void Array113()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    selection_sort_Dbl_Array(A, n);

    free(A);
}


void Array114()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    insertion_sort_Dbl_Array(A, n);

    free(A);
}


void Array115()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);
    fillDblArrayRnd(A, n, -10, 11);
    showDblArray(A, n);

    int* I = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        I[i] = i;
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(A[I[j]] > A[I[j+1]])
            {
                swap_Int_Values(&I[j], &I[j+1]);
            }
        }
        showIntArray(I, n);
    }

    showDblArray(A, n);

    free(A);
    free(I);
}


void Array116()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int N = get_number_of_series(A, n);
    int* B = createIntArray(N);
    int* C = createIntArray(N);

    for(int i = 0; i < N; i++)
    {
        B[i] = get_series_length(A, n, i);
        if(serials_error != 0)
        {
            puts("serias is absent");
        }
        C[i] = get_series_value(A, n, i);
        if(serials_error != 0)
        {
            puts("serias is absent");
        }
    }
    showIntArray(B, N);
    showIntArray(C, N);

    free(A);
    free(B);
    free(C);
}


void Array117()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int N = get_number_of_series(A, n);
    for(int i = N-1; i >= 0; i--)
    {
        int pos = get_series_position(A, n, i);
        insert_into_Int_Array(&A, &n, pos, 0);
    }

    showIntArray(A, n);

    free(A);
}


void Array118()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);


    int N = get_number_of_series(A, n);
    reverse_Int_Array(A, n, 0, n-1);
    for(int i = N-1; i >= 0; i--)
    {
        int pos = get_series_position(A, n, i);
        insert_into_Int_Array(&A, &n, pos, 0);
    }
    reverse_Int_Array(A, n, 0, n-1);

    showIntArray(A, n);

    free(A);
}


void Array118a()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);


    int N = get_number_of_series(A, n);
    for(int i = N-1; i >= 0; i--)
    {
        int pos = get_series_position(A, n, i);
        int length = get_series_length(A, n, i);
        insert_into_Int_Array(&A, &n, pos+length, 0);
    }

    showIntArray(A, n);

    free(A);
}


void Array119()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);


    int N = get_number_of_series(A, n);
    for(int i = 0; i < N; i++)
    {
        int pos = get_series_position(A, n, i);
        insert_into_Int_Array(&A, &n, pos, A[pos]);
    }

    showIntArray(A, n);

    free(A);
}


void Array120()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);


    int N = get_number_of_series(A, n);
    for(int i = N-1; i >= 0; i--)
    {
        int pos = get_series_position(A, n, i);
        remove_from_Int_Array(&A, &n, pos);
    }

    showIntArray(A, n);

    free(A);
}


void Array121()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);


        int length = get_series_length(A, n, K);
        int pos = get_series_position(A, n, K);
        int value = get_series_value(A, n, K);
        for(int i = 0; i < length; i++)
        {
            insert_into_Int_Array(&A, &n, pos, value);
        }


    showIntArray(A, n);

    free(A);
}


void Array122()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);

    int pos = get_series_position(A, n, K);
    int length = get_series_length(A, n, K);
    for(int  i = 0; i < length; i++)
    {
        remove_from_Int_Array(&A, &n, pos);
    }
//    for(int i = pos+length-1; i >= pos; i--)
//    {
//        remove_from_Int_Array(&A, &n, i);
//    }

    showIntArray(A, n);

    free(A);
}


void Array123()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 1, 4);
    showIntArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);

    swap_Series_a(&A, n, 0, K);

    showIntArray(A, n);

    free(A);
}


void Array124()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int K;
    printf("K: "); scanf("%d", &K);

    int N = get_number_of_series(A, n);
    swap_Series(&A, n, K, N-1);

    showIntArray(A, n);

    free(A);
}


void Array125()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 0, 4);
//    for(int i = 0; i < n; i++)
//    {
//        printf("A[%i] = ", i);  scanf("%d", &A[i]);
//    }
    showIntArray(A, n);

    int L;
    printf("L: "); scanf("%d", &L);

    int N = get_number_of_series(A, n);
    int m = 0;
    for(int i = 0; i < N; i++)
    {
        int length = get_series_length(A, n, i);
        if(length < L)
        {
            m++;
        }
        else
        {
            m+=length;
        }
    }

    int* B = createIntArray(m);

    int b = 0;
    for(int i = 0; i < N; i++)
    {
        int length = get_series_length(A, n, i);
        if(length < L)
        {
            B[b++] = 0;
        }
        else
        {
            int value = get_series_value(A, n, i);
            for(int j = 0; j < length; j++)
            {
                B[b++] = value;
            }
        }
    }
    free(A);
    A = B;
    n = m;

    showIntArray(A, n);

    free(A);
}


void Array126()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int L;
    printf("L: "); scanf("%d", &L);

    for(int i = N-1; i >= 0; i--)
    {
        int length = get_series_length(A, n, i);
        if(length == L)
        {
            replace_Series_array(&A, &n, i);
        }
    }

    showIntArray(A, n);

    free(A);
}


void Array127()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int L;
    printf("L: "); scanf("%d", &L);

    for(int i = N-1; i >= 0; i--)
    {
        int length = get_series_length(A, n, i);
        if(length > L)
        {
            replace_Series_array(&A, &n, i);
        }
    }

    showIntArray(A, n);

    free(A);
}


void Array128()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    fillIntArrayRnd(A, n, 0, 4);

//    for(int i = 0; i < n; i++)
//    {
//        printf("A[%i] = ", i);  scanf("%d", &A[i]);
//    }
    showIntArray(A, n);

    int N = get_number_of_series(A, n);
    int first_max_length = get_series_length(A, n, 0);
    int first_pos_max = 0;
    for(int i = 0; i < N; i++)
    {
        int length = get_series_length(A, n, i);
        if(length > first_max_length)
        {
            first_max_length = length;
            first_pos_max = i;
        }
    }

    int pos = get_series_position(A, n, first_pos_max);
    insert_into_Int_Array(&A, &n, pos, A[pos]);

    showIntArray(A, n);

    free(A);
}


void Array129()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int N = get_number_of_series(A, n);
    int last_max = get_series_length(A, n, 0);
    int last_pos_max = 0;
    for(int i = 1; i < N; i++)
    {
        int length = get_series_length(A, n, i);
        if(length >= last_max)
        {
            last_max = get_series_length(A, n, i);
            last_pos_max = i;
        }
    }

    int pos = get_series_position(A, n, last_pos_max);
    int value = get_series_value(A, n, last_pos_max);
    insert_into_Int_Array(&A, &n, pos, value);



    showIntArray(A, n);

    free(A);
}


void Array130()
{
    int n;
    printf("N: "); scanf("%d", &n);
    int* A = createIntArray(n);
    for(int i = 0; i < n; i++)
    {
        printf("A[%i] = ", i);  scanf("%d", &A[i]);
    }
    showIntArray(A, n);

    int N = get_number_of_series(A, n);
    int max = get_series_length(A, n, 0);
    int pos_max = 0;
    for(int i = 1; i < N; i++)
    {
        int length = get_series_length(A, n, i);
        if(length >= max)
        {
            max = length;
            pos_max = i;
        }
    }

    for(int i = N-1; i >= 0; i--)
    {
        int length = get_series_length(A, n, i);
        if(length == max)
        {
            int pos = get_series_position(A, n, i);
            int value = get_series_value(A, n, i);
            insert_into_Int_Array(&A, &n, pos, value);
        }
    }

    showIntArray(A, n);

    free(A);
}


void Array131()
{
    printf("Enter parametres array A of random points\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* points = createDblArrayOfPoints(n);

    int from, to;
    printf("from: "); scanf("%d", &from);
    printf("to: "); scanf("%d", &to);
    fillDblArrayOfRandomPoints(points, from, to, n);

    showDblArrayOfPoints(points, n);

    printf("Enter coordinates of point B\n");

    double x, y;
    printf("x: "); scanf("%lf", &x);
    printf("y: "); scanf("%lf", &y);

    Point point = createDblPoint(x, y);
    puts("");

    int pos = 0;
    double min_length = get_length_between_points(&point, &points[0]);
    for(int i = 0; i < n; i++)
    {
        double R = get_length_between_points(&point, &points[i]);
        printf("R = %.2lf\n", R);
        if(R < min_length)
        {
            pos = i;
            min_length = R;
        }
    }

    printf("min_length = %.2lf\n", min_length);
    printf("Possition Array A = %d\n", pos);
    showDblPoint(&points[pos]);
}


void Array132()
{
    printf("Enter parametres array A of random points\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* points = createDblArrayOfPoints(n);
    fillDblArrayOfRandomPoints(points, -10, 10, n);

    showDblArrayOfPoints(points, n);

    Point zero = createDblPoint(0, 0);
    puts("");
    Point result = zero;
    double max_length = 0;
    for(int i = 0; i < n; i++)
    {
        int quarter = get_Quarter(points[i]);
        if(quarter == 2)
        {
            double R = get_length_between_points(&zero, &points[i]);
            if(R > max_length)
            {
                result = points[i];
                max_length = R;
            }
        }
    }

    showDblPoint(&result);
    printf("distance = %lf", max_length);
}


void Array133()
{
    printf("Enter array A of points\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* points = createDblArrayOfPoints(n);

    fillDblArrayOfRandomPoints(points, -10, 10, n);

    showDblArrayOfPoints(points, n);

    Point zero = createDblPoint(0, 0);

    double min_length = -1;
    Point result = zero;
    for(int i = 0; i < n; i++)
    {
        int quarter = get_Quarter(points[i]);
        if(quarter == 1 || quarter == 3)
        {
            min_length = get_length_between_points(&zero, &points[i]);
            result = points[i];
            break;
        }
    }
    if(min_length != -1)
    {
        for(int i = 0; i < n; i++)
        {
            int quarter = get_Quarter(points[i]);
            if(quarter == 1 || quarter == 3)
            {
                double R = get_length_between_points(&zero, &points[i]);
                if(R < min_length)
                {
                    result = points[i];
                    min_length = R;
                }
            }
        }
    }

    showDblPoint(&result);
    printf("distance = %lf", min_length);
}


void Array134()
{
    printf("Enter array A of points\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* points = createDblArrayOfPoints(n);

    fillDblArrayOfRandomPoints(points, -10, 10, n);

    /*
    for(int i = 0; i < n; i++)
    {
        double x, y;
        printf("x: "); scanf("%lf", &x);
        printf("y: "); scanf("%lf", &y);
        enterDblArrayOfRandomPoints(&points[i], x, y);
        puts("");
    }
    /**/

    showDblArrayOfPoints(points, n);
    puts("");

    int pos_1 = -1;
    int pos_2 = -1;
    double max_length = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            double R = get_length_between_points(&points[i], &points[j]);
            if(R > max_length)
            {
                max_length = R;
                pos_1 = i;
                pos_2 = j;
            }
        }
    }


        showDblPoint(&points[pos_1]);
        showDblPoint(&points[pos_2]);
        printf("Max length between points = %.2lf\n", max_length);
}


void Array134a()
{
    printf("Enter array A of points\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* points = createDblArrayOfPoints(n);

    fillDblArrayOfRandomPoints(points, -10, 10, n);
    showDblArrayOfPoints(points, n);

    Point A = points[0];
    Point B = points[1];
    double max_dist = get_length_between_points(&A, &B);
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            double dist = get_length_between_points(&points[i], &points[j]);
            if(dist > max_dist)
            {
                max_dist = dist;
                A = points[i];
                B = points[j];
            }
        }
    }

    showDblPoint(&A);
    showDblPoint(&B);
    printf("Max length between points = %.2lf\n", max_dist);
}


void Array135()
{
    int N1;
    printf("N: "); scanf("%d", &N1);
    Point* A = createDblArrayOfPoints(N1);
    fillDblArrayOfRandomPoints(A, -10, 10, N1);
    showDblArrayOfPoints(A, N1);

    int N2;
    printf("N: "); scanf("%d", &N2);
    Point* B = createDblArrayOfPoints(N2);
    fillDblArrayOfRandomPoints(B, -10, 10, N2);
    showDblArrayOfPoints(B, N2);

    Point a = A[0];
    Point b = B[0];
    double min_length = get_length_between_points(&a, &b);
    for(int i = 0; i < N1; i++)
    {
        for(int j = 0; j < N2; j++)
        {
            double R = get_length_between_points(&A[i], &B[j]);
            if(R < min_length)
            {
                min_length = R;
                a = A[i];
                b = B[j];
            }
        }
    }

    printf("Min length between points = %.2lf\n", min_length);
    showDblPoint(&a);
    showDblPoint(&b);
}


void Array136()
{
    printf("Enter array of points A\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* A = createDblArrayOfPoints(n);
    puts("");

    for(int i = 0; i < n; i++)
    {
        double x, y;
        printf("x: "); scanf("%lf", &x);
        printf("y: "); scanf("%lf", &y);
        enterDblArrayOfRandomPoints(&A[i], x, y);
        puts("");
    }

    showDblArrayOfPoints(A, n);
    puts("");

    int pos = 0;
    double sum_of_min_length;
    for(int i = 0; i < n; i++)
    {
        double sum = 0;
        for(int j = 0; j < n; j++)
        {
            double R = get_length_between_points(&A[i], &A[j]);
            sum = sum + R;
        }
        if( i == 0)
        {
            sum_of_min_length = sum;
        }
        else
        {
            if(sum < sum_of_min_length)
            {
                sum_of_min_length = sum;
                pos = i;
            }
        }
    }

    printf("Min sum length between points = %.2lf\n", sum_of_min_length);
    showDblPoint(&A[pos]);
}


void Array137()
{
    printf("Enter amount of points array A\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* A = createDblArrayOfPoints(n);

    int from, to;
    printf("from: "); scanf("%d", &from);
    printf("to: "); scanf("%d", &to);
    fillDblArrayOfRandomPoints(A, from, to, n);

    printf("Array  A\n");
    showDblArrayOfPoints(A, n);
    puts("");

    int count = 0;
    int pos_1 = 0;
    int pos_2 = 1;
    int pos_3 = 2;
    double max_p = get_Perimetr_of_Triagle(&A[0], &A[1], &A[2]);

    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                count++;
                double P = get_Perimetr_of_Triagle(&A[i], &A[j], &A[k]);
                if(P > max_p)
                {
                    max_p = P;
                    pos_1 = i;
                    pos_2 = j;
                    pos_3 = k;
                }
            }
        }
    }

    printf("count = %d\n", count);
    printf("Maximal perimetr of triagle = %lf\n", max_p);
    showDblPoint(&A[pos_1]);
    showDblPoint(&A[pos_2]);
    showDblPoint(&A[pos_3]);
}


void Array138()
{
    printf("Enter amount of points array A\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point* A = createDblArrayOfPoints(n);

    int from, to;
    printf("from: "); scanf("%d", &from);
    printf("to: "); scanf("%d", &to);
    fillDblArrayOfRandomPoints(A, from, to, n);

    printf("Array  A\n");
    showDblArrayOfPoints(A, n);
    puts("");

    int count = 0;
    int pos_1 = 0;
    int pos_2 = 1;
    int pos_3 = 2;
    double min_p = get_Perimetr_of_Triagle(&A[0], &A[1], &A[2]);

    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                count++;
                double P = get_Perimetr_of_Triagle(&A[i], &A[j], &A[k]);
                if(P < min_p)
                {
                    min_p = P;
                    pos_1 = i;
                    pos_2 = j;
                    pos_3 = k;
                }
            }
        }
    }

    printf("count = %d\n", count);
    printf("Minimal perimetr of triagle = %lf\n", min_p);
    showDblPoint(&A[pos_1]);
    showDblPoint(&A[pos_2]);
    showDblPoint(&A[pos_3]);
}


void Array139()
{
    printf("Enter amount of points array A\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point_int* A = createIntArrayOfPoints(n);

    int from, to;
    printf("from: "); scanf("%d", &from);
    printf("to: "); scanf("%d", &to);
    fillIntArrayOfRandomPoints(A, from, to, n);

    printf("Array  A\n");
    showIntArrayOfPoints(A, n);
    puts("");

    TFuncXY defenition_of_function_sort = compareX;

    qsort(A, n, sizeof(Point_int), compareX);

    showIntArrayOfPoints(A, n);
}


void Array140()
{
    printf("Enter amount of points array A\n");

    int n;
    printf("N: "); scanf("%d", &n);
    Point_int* A = createIntArrayOfPoints(n);

    int from, to;
    printf("from: "); scanf("%d", &from);
    printf("to: "); scanf("%d", &to);
    fillIntArrayOfRandomPoints(A, from, to, n);

    printf("Array  A\n");
    showIntArrayOfPoints(A, n);
    puts("");

    TFuncXY defenition_of_function_sort = compareXplusY;

    qsort(A, n, sizeof(Point_int), defenition_of_function_sort);

    showIntArrayOfPoints(A, n);
}


typedef bool (*Compare_func)(double a, double b);


void sortDblArray(double* A, int n, Compare_func comparator)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(comparator(A[i], A[j]))
            {
                swap_Dbl_Values(&A[i], &A[j]);
            }
        }
    }
}


bool comp_up(double a, double b)
{
    return a > b;
}


bool comp_down(double a, double b)
{
    return a < b;
}

bool comp_even_first(double a, double b)
{
    int aa = a;
    int bb = b;
    return aa % 2 != 0 && bb % 2 == 0;
}


bool comp_odd_first(double a, double b)
{
    int aa = a;
    int bb = b;
    return aa % 2 == 0 && bb % 2 != 0;
}


bool comp_odd_first_round(double a, double b)
{
    int aa = round(a);
    int bb = round(b);
    return aa % 2 == 0 && bb % 2 != 0;
}


void Array141()
{
    int n;
    printf("N: "); scanf("%d", &n);
    double* A = createDblArray(n);

    fillDblArrayRnd(A, n, -5, 10);
    showDblArray(A, n);

    sortDblArray(A, n, comp_up);
    showDblArray(A, n);

    sortDblArray(A, n, comp_down);
    showDblArray(A, n);

    sortDblArray(A, n, comp_even_first);
    showDblArray(A, n);

    sortDblArray(A, n, comp_odd_first);
    showDblArray(A, n);

    sortDblArray(A, n, comp_odd_first_round);
    showDblArray(A, n);
}



//Почати тему показчики на функцію.










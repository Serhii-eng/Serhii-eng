#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.1415926535


int main()
{
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);

    srand(t);

    void Minmax30();
    Minmax30();

    return 0;
}


void Minmax30()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int cnt = 0;
    int amount = 0;
    int position = 0;
    int previous_num = 0;
    int num_first_elem = 0;
    int flag = 0;
    int flag_start_min = 0;
    int max_previos_position = 0;
    for(int i = 1; i <= N; i++)
    {
        from = 1;
        to = 26;
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1) previous_num = n;

        if(max_previos_position < previous_num && max_previos_position < n && previous_num < n && i > 1)
        {
            if(flag == 0)
            {
                flag = 1;
                position = i - 1;
                amount++;
            }
            amount++;
        }
        if(position != 0 && previous_num >= n || N == i && position != 0)
        {
            if(cnt > amount)
            {
                cnt = amount;
                num_first_elem = position;
            }

            if(amount > 1 && flag_start_min == 0)
            {
                cnt = amount;
                num_first_elem = position;
                flag_start_min = 1;
            }

            position = 0;
            amount = 0;
            flag = 0;
        }

        if(max_previos_position < previous_num && i > 1)
            max_previos_position = previous_num;
        previous_num = n;

    }

    printf("\nnum_first_elem: %d", num_first_elem);
    printf("\ncnt: %d", cnt);
}


void Minmax29()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int cnt = 0;
    int amount = 0;
    int position = 0;
    int previous_num = 0;
    int num_first_elem = 0;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        from = 1;
        to = 26;
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1) previous_num = n;

        if(previous_num > n && i > 1)
        {
            if(flag == 0)
            {
                flag = 1;
                position = i - 1;
                amount++;
            }
            amount++;
        }
        if(previous_num <= n || N == i)
        {
            if(cnt <= amount)
            {
                cnt = amount;
                num_first_elem = position;
            }
            position = 0;
            amount = 0;
            flag = 0;
        }
        if(n < previous_num) previous_num = n;
    }

    printf("\nnum_first_elem: %d", num_first_elem);
    printf("\ncnt: %d", cnt);
}


void Minmax28()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int cnt = 0;
    int amount = 0;
    int position = 0;
    int previous_num = 0;
    int num_first_elem = 0;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        from = 0;
        to = 2;
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(previous_num == 1 && n == 1 && i > 1)
        {
            if(flag == 0)
            {
                flag = 1;
                position = i - 1;
                amount++;
            }
            amount++;
        }
        if(n != 1 || N == i)
        {
            if(cnt <= amount)
            {
                cnt = amount;
                num_first_elem = position;
            }
            position = 0;
            amount = 0;
            flag = 0;
        }
        previous_num = n;
    }

    printf("\nnum_first_elem: %d", num_first_elem);
    printf("\ncnt: %d", cnt);
}


void Minmax27a()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int cnt = 0;
    int temp_1 = 0;
    int temp_2 = 0;
    int previous_num = 0;
    int num_first_elem = 0;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        from = 0;
        to = 2;
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);


        if(previous_num == n && i>1)
        {
            if(flag == 0)
            {
                temp_1 = i-1;
                flag = 1;
            }
            temp_2++;
        }
        else
        {
            if(cnt < temp_2+1)
            {
                cnt = temp_2+1;
                num_first_elem = temp_1;
            }

            temp_2 = 0;
            flag = 0;
        }

        previous_num = n;
    }

    printf("\nnum_first_elem: %d", num_first_elem);
    printf("\ncnt: %d", cnt);
}


void Minmax27()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int cnt = 0;
    int temp_1 = 0;
    int temp_2 = 0;
    int previous_num = 0;
    int num_first_elem = 0;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        from = 0;
        to = 2;
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);


        if(previous_num == n && i>1)
        {
            if(flag == 0)
            {
                temp_1 = i-1;
                flag = 1;
            }
            temp_2++;
        }
        else
        {
            if(cnt < temp_2+1)
            {
                cnt = temp_2+1;
                num_first_elem = temp_1;
            }

            temp_2 = 0;
            flag = 0;
        }

        previous_num = n;
    }

    printf("\nnum_first_elem: %d", num_first_elem);
    printf("\ncnt: %d", cnt);
}


void Minmax26()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int cnt = 0;
    int temp = 0;
    int even_num;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        even_num = n % 2;
        if(even_num == 0)
        {
            temp++;
        }
        else
        {
            if(cnt < temp) cnt = temp;
            temp = 0;
        }
    }

    printf("\ncnt: %d", cnt);
}


void Minmax25()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);

    int num_1 = 0;
    int num_2 = 0;
    int min_1 = 0;
    int min_2 = 0;
    int cnt_min_1 = 0;
    int cnt_min_2 = 0;
    int min_mul = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        num_2 = num_1;
        num_1 = n;

        if(i == 2)
        {
            min_mul = num_1 * num_2;
        }



        if(num_1 * num_2 < min_mul)
        {
            min_mul = num_1 * num_2;
            min_1 = num_1;
            min_2 = num_2;
            cnt_min_1 = i;
            cnt_min_2 = i-1;
        }
    }

    printf("\nmin_mul: %d\n", min_mul);
    printf("\nmin_2: %d", min_2);
    printf("\nmin_1: %d\n", min_1);
    printf("\ncnt_min_2: %d", cnt_min_2);
    printf("\ncnt_min_1: %d", cnt_min_1);
}


void Minmax24()
{
    int from = 2;
    int to = 21;
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);

    int num_1 = 0;
    int num_2 = 0;
    int max_sum = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        num_2 = num_1;
        num_1 = n;
        if(num_1 + num_2 > max_sum) max_sum = num_1 + num_2;
    }

    printf("\nmax_sum: %d", max_sum);
}


void Minmax23()
{
    int from = 4;
    int to = 21; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);

    int max_1 = 0;
    int max_2 = 0;
    int max_3 = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);



        if(max_1 < n)
        {
            max_3 = max_2;
            max_2 = max_1;
            max_1 = n;
        }
    }

    printf("\nmax_1: %d", max_1);
    printf("\nmax_2: %d", max_2);
    printf("\nmax_3: %d", max_3);
}



void Minmax22()
{
    int from = 3;
    int to = 16; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);

    int min_1;
    int min_2;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1)
        {
            min_1 = n;
        }
        min_2 = min_1;
        if(n < min_1)
        {
            min_1 = n;
        }

    }
    printf("\nmin_1: %d", min_1);
    printf("\nmin_2: %d", min_2);
}


void Minmax21()
{
    int from = 3;
    int to = 16; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);

    int min;
    int max;
    int sum = 0;
    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1)
        {
            min = max = n;
        }
        if(n < min)
        {
            min = n;
        }
        if(n > max)
        {
            max = n;
        }
        if(n > min && n < max)
        {
            sum += n;
            cnt++;
        }
    }
    int middle_sum = sum / cnt;
    printf("\middle sum: %d", middle_sum);
}


void Minmax20()
{
    int from = 1;
    int to = 11; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);

    int min;
    int max;
    int cnt_min = 0;
    int cnt_max = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1)
        {
            min = max = n;
        }
        if(n < min)
        {
            min = n;
            cnt_min++;
        }
        if(n > max)
        {
            max = n;
            cnt_max++;
        }
    }

        printf("\ncount min: %d", cnt_min);
        printf("\ncount max: %d", cnt_max);
}


void Minmax19()
{
    int from = 1;
    int to = 11; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int min = 0;
    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1)
        {
            min = n;
        }
        if(n < min)
        {
            cnt++;
        }
    }

        printf("\ncount min: %d", cnt);
}


void Minmax18()
{
    int from = 1;
    int to = 11; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int max = 0;
    int cnt = 0;
    int temp = 0;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1)
        {
            max = n;
        }
        if(n <= max && flag == 1)
        {
            temp++;
        }
        if(n > max && flag == 0)
        {
            max = n;
            flag = 1;
        }
        if(n > max && flag == 1)
        {
            cnt = temp;
            flag = 2;
        }

    }

        printf("\nmax (count) max: %d", cnt);
}


void Minmax17()
{
    int from = 1;
    int to = 11; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int max = 0;
    int cnt_max = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1)
        {
            max = n;
        }
        if(n > max)
        {
            cnt_max = 0;
        }
        if(n < max)
        {
            cnt_max++;
        }
    }

        printf("\ncount: %d", cnt_max);
}


void Minmax16()
{
    int from = 1;
    int to = 11; //для повного діапазону верхній гран. на 1 більше.
    int N = from + rand() % (to - from);
    printf("N: %d\n\n", N);


    int min = 0;
    int cnt_max = 0;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n = from + rand() % (to - from);
        printf("n: %d\n", n);

        if(i == 1)
        {
            min = n;
            cnt_max = i;
        }
        if(n > min && flag == 0)
        {
            cnt_max = i;
        }
         if(n < min)
        {
            flag = 1;
        }
    }

        printf("\ncount max: %d", cnt_max);
}


void Minmax15()
{
    int from = 5;
    int to = 11; //для повного діапазону верхній гран. на 1 більше.
    int B = from + rand() % (to - from);
    printf("B: %d\n\n", B);

    from = 15;
    to = 21; //для повного діапазону верхній гран. на 1 більше.
    int C = from + rand() % (to - from);
    printf("C: %d\n\n", C);

    int max = 0;
    int cnt_max;
    int flag = 0;
    for(int i = 1; i <= 10; i++)
    {
        int n = rand() % 25 + 1;
        printf("n: %d\n", n);

        if(B <= n && C >= n && flag == 0)
        {
            max = n;
            cnt_max = i;
            flag = 1;
        }
         if(n > max && B <= n && C >= n && flag == 1)
        {
            max = n;
            cnt_max = i;
        }
    }

        printf("\nmax: %d", max);
        printf("\ncount: %d", cnt_max);
}


void Minmax14()
{
    int B = rand() % 10 + 1;
    printf("B: %d\n\n", B);

    int min = 0;
    int cnt_min = 0;
    int flag = 0;
    for(int i = 1; i <= 10; i++)
    {
        int n = rand() % 15 + 1;
        printf("n: %d\n", n);

        if(n > B && flag == 0)
        {
            min = n;
            cnt_min = i;
            flag = 1;
        }
         if(n < min && n > B && flag == 1)
        {
            min = n;
            cnt_min = i;
        }
    }

        printf("\nmin: %d", min);
        printf("\ncount: %d", cnt_min);
}


void Minmax13()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int max = 0;
    int cnt_max;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if(n%2 != 0 && flag == 0)
        {
            max = n;
            cnt_max = i;
            flag = 1;
        }
         if(n > max && n%2 != 0 && flag == 1)
        {
            max = n;
            cnt_max = i;
            flag = 2;
        }
    }

        printf("\nmax: %d", max);
        printf("\ncount: %d", cnt_max);
}


void Minmax12()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min = 0;
    int cnt_min;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if( n > 0 && flag == 0)
        {
            min = n;
            cnt_min = i;
            flag = 1;
        }
         if(n < min && n > 0)
        {
            min = n;
            cnt_min = i;
        }
    }

        printf("\nmin: %d", min);
        printf("\ncount: %d", cnt_min);
}


void Minmax11()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min = 0;
    int max = 0;
    int cnt_min;
    int cnt_max;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if(i == 1)
        {
            min = max = n;
            cnt_min = cnt_max = i;
        }
         if(n < min)
        {
            min = n;
            cnt_min = i;
        }
         if(n > max)
        {
            max = n;
            cnt_max = i;
        }
    }

    if(cnt_min > cnt_max)
    {
        printf("\nmin: %d", min);
        printf("\ncount: %d", cnt_min);
    }
    if(cnt_min < cnt_max)
    {
        printf("\nmax: %d", max);
        printf("\ncount: %d", cnt_max);
    }
    if(cnt_min && cnt_max == 1)
    {
        printf("\nall numbers are the same 0");
    }
}


void Minmax10()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min_first;
    int cnt_min_first;
    int max_first;
    int cnt_max_first;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if(i == 1)
        {
            min_first = max_first = n;
            cnt_min_first = cnt_max_first = i;
        }
         if(n < min_first && flag == 0)
        {
            min_first = n;
            cnt_min_first = i;
            flag = 1;
        }
         if(n > max_first && flag == 0)
        {
            max_first = n;
            cnt_max_first = i;
            flag = 1;
        }

    }

    if(cnt_min_first != 1)
    {
        printf("\nmin_first: %d", min_first);
        printf("\ncount: %d", cnt_min_first);
    }
    if(cnt_max_first != 1)
    {
        printf("\nmax_first: %d", max_first);
        printf("\ncount: %d", cnt_max_first);
    }
     if(cnt_min_first && cnt_max_first == 1)
    {
        printf("\nall numbers are the same");
    }
}



void Minmax9()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int max_first;
    int max;
    int cnt_max_first;
    int cnt_max;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if(i == 1)
        {
            max = max_first = n;
            cnt_max = cnt_max_first = i;
        }
         if(n > max && flag == 0)
        {
            max_first = n;
            cnt_max_first = i;
            flag = 1;
        }
        if(n > max)
        {
            max = n;
            cnt_max = i;
        }

    }
    printf("\nmax_first: %d", max_first);
    printf("\ncount: %d", cnt_max_first);
    printf("\n");
    printf("\nmax: %d", max);
    printf("\ncount: %d", cnt_max);
}


void Minmax8()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min_first;
    int min;
    int cnt_min_first;
    int cnt_min;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if(i == 1)
        {
            min = min_first = n;
            cnt_min = cnt_min_first = i;
        }
         if(n < min && flag == 0)
        {
            min_first = n;
            cnt_min_first = i;
            flag = 1;
        }
        if(n < min)
        {
            min = n;
            cnt_min = i;
        }

    }
    printf("\nmin_first: %d", min_first);
    printf("\ncount: %d", cnt_min_first);
    printf("\n");
    printf("\nmin: %d", min);
    printf("\ncount: %d", cnt_min);
}



void Minmax7()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min;
    int max;
    int cnt_min;
    int cnt_max;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if(i == 1)
        {
            min = max = n;
            cnt_min = cnt_max = i;
        }
        if(n < min)
        {
            min = n;
            cnt_min = i;

        }
        if(n > max && flag == 0)
        {
            max = n;
            cnt_max = i;
            flag = 1;
        }
    }
    printf("\nmax: %d", max);
    printf("\ncount: %d", cnt_max);
    printf("\n");
    printf("\nmin_first: %d", min);
    printf("\ncount: %d", cnt_min);
}



void Minmax6()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min;
    int max;
    int cnt_min;
    int cnt_max;
    int flag = 0;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);

        if(i == 1)
        {
            min = max = n;
            cnt_min = cnt_max = i;
        }
        if(n < min && flag == 0)
        {
            min = n;
            cnt_min = i;
            flag = 1;
        }
        if(n > max)
        {
            max = n;
            cnt_max = i;
        }
    }
    printf("\nmin_first: %d", min);
    printf("\ncount: %d", cnt_min);
    printf("\n");
    printf("\nmax: %d", max);
    printf("\ncount: %d", cnt_max);
}


void Minmax5()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int P;
    int max_P;
    int cnt;
    for(int i = 0; i < N; i++)
    {
        int m, v;
        printf("m: ");  scanf("%d", &m);
        printf("v: ");  scanf("%d", &v);
        printf("\n");

        P = m / v;
        if(i == 0)
        {
            max_P = P;
            cnt = i+1;
        }
        if(P > max_P)
        {
            max_P = P;
            cnt = i+1;
        }
    }
    printf("\nmax_P: %d", max_P);
    printf("\ncount: %d", cnt);
}


void Minmax4()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min;
    int cnt;
    for(int i = 1; i <= N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);
        if(i == 1)
        {
            min = n;
            cnt = i;
        }
        if(n < min)
        {
            min = n;
            cnt = i;
        }
    }
    printf("\nnumber of min: %d", cnt);
}


void Minmax3()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int P;
    int max_P;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        printf("a: ");  scanf("%d", &a);
        printf("b: ");  scanf("%d", &b);
        printf("\n");

        P = (a + b) * 2;
        if(i == 0) max_P = P;
        if(P > max_P) max_P = P;
    }
    printf("\nmax_P: %d", max_P);
}


void Minmax2()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int S;
    int min_S;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        printf("a: ");  scanf("%d", &a);
        printf("b: ");  scanf("%d", &b);
        printf("\n");

        S = a * b;
        if(i == 0) min_S = S;
        if(S < min_S) min_S = S;
    }
    printf("\nmin_S: %d", min_S);
}


void Minmax1()
{
    int N;
    printf("N: ");  scanf("%d", &N);
    printf("\n");

    int min, max;
    for(int i = 0; i < N; i++)
    {
        int n;
        printf("n: ");  scanf("%d", &n);
        if(i == 0) min = max = n;
        if(n < min) min = n;
        if(n > max) max = n;
    }
    printf("\nmin: %d\n", min);
    printf("max: %d", max);
}

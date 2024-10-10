#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <math.h>

#define PI	3.14159265358979323846

int get_month_days(int m, int y);
bool is_leap_year(int y);

int main()
{
    setlocale(LC_ALL, "Rus");
    system("chcp 1251 >> nul");
    void case_20();
    case_20();

    return 0;
}

void case_20()
{
    int d, m;

    printf(" ����: ");  scanf ("%i", &d);
    printf(" �����: "); scanf ("%i", &m);

    if((20 <= d && m == 1) || (d <= 18 && m == 2)) printf(" �������");
    if((19 <= d && m == 2) || (d <= 20 && m == 3)) printf(" ����");
    //////
    else if((21 <= d && 31 >= d && m == 3) || (1 <= d && 19 >= d && m == 4))
    {
        printf(" ����");
    }
    else if((21 <= d && 30 >= d && m == 4) || (1 <= d && 20 >= d && m == 5))
    {
        printf(" �����");
    }
    else if((21 <= d && 31 >= d && m == 5) || (1 <= d && 21 >= d && m == 6))
    {
        printf(" ��������");
    }
     else if((22 <= d && 30 >= d && m == 6) || (1 <= d && 22 >= d && m == 7))
    {
        printf(" ���");
    }
     else if((23 <= d && 31 >= d && m == 7) || (1 <= d && 22 >= d && m == 8))
    {
        printf(" ���");
    }
     else if((23 <= d && 31 >= d && m == 8) || (1 <= d && 22 >= d && m == 9))
    {
        printf(" ����");
    }
     else if((23 <= d && 30 >= d && m == 9) || (1 <= d && 22 >= d && m == 10))
    {
        printf(" ����");
    }
    else if((23 <= d && 31 >= d && m == 10) || (1 <= d && 22 >= d && m == 11))
    {
        printf(" ��������");
    }
    else if((23 <= d && 31 >= d && m == 11) || (1 <= d && 21 >= d && m == 12))
    {
        printf(" �������");
    }
    else if((22 <= d && 31 >= d && m == 12) || (1 <= d && 19 >= d && m == 1))
    {
        printf(" �������");
    }
}

void case_15()
{
   int m, n;

   printf(" �����: ");  scanf ("%i", &m);
   printf(" �����: ");  scanf ("%i", &n);

   switch(m)
   {
       case 1: printf(" ���� "); break;
       case 2: printf(" ����� "); break;
       case 3: printf(" ����� "); break;
       case 4: printf(" ����� "); break;
       default: printf(" Error ");
   }
   switch(n)
   {
       case 6: printf(" ����� "); break;
       case 7: printf(" ���� "); break;
       case 8: printf(" ����� "); break;
       case 9: printf(" ������ "); break;
       case 10: printf(" ������ "); break;
       case 11: printf(" ����� "); break;
       case 12: printf(" ���� "); break;
       case 13: printf(" ������ "); break;
       case 14: printf(" ��� "); break;
       default: printf(" Error ");
   }
}

void case_14()
{
    int n;
    float x, a, r1, r2, s;
    printf(" ����� ��������: ");  scanf ("%i", &n);
    printf(" ��������: ");        scanf ("%f", &x);

    switch (n)
    {
    case 1:
        a = x;
        r1 = a * sqrt(3) / 6;
        r2 = 2 * r1;
        s = a * a * sqrt(3) / 4;
        printf("%f %f %f\n", r1, r2, s);
        break;
    case 2:
        r1 = x;
        a = r1 * 6 / sqrt(3);
        r2 = 2 * r1;
        s = a * a * sqrt(3) / 4;
        printf("%f %f %f\n", a, r2, s);
        break;
    case 3:
        r2 = x;
        r1 = r2 / 2;
        a = r1 * 6 / sqrt(3);
        s = a * a * sqrt(3) / 4;
        printf("%f %f %f\n", a, r1, s);
        break;
    case 4:
        s = x;
        a = sqrt(s * 4 / sqrt(3));
        r1 = a * sqrt(3) / 6;
        r2 = 2 * r1;
        printf("%f %f %f\n", a, r1, r2);
        break;
    }
}

void case_13()
{
    int n;
    float x, a, c, h, s;
    printf("����� ��������:");    scanf ("%i", &n);
    printf("��������:");            scanf ("%f", &x);

    switch (n)
    {
    case 1:
        a = x;
        c = a * sqrt(2);
        h = c / 2;
        s = c * h / 2;
        printf("%f %f %f\n", c, h, s);
        break;
    case 2:
        c = x;
        a = c / sqrt(2);
        h = c / 2;
        s = c * h / 2;
        printf("%f %f %f\n", a, h, s);
        break;
    case 3:
        h = x;
        c = 2 * h;
        a = c / sqrt(2);
        s = c * h / 2;
        printf("%f %f %f\n", a, c, s);
        break;
    case 4:
        s = x;
        h = sqrt(s);
        c = 2 * h;
        a = c / sqrt(2);
        printf("%f %f %f\n", a, c, h);
        break;
    }
}

void case_12()
{
    char n;
    float x, r, d, l, s;
    printf(" ����� ��������(r, d, l, s): ");  scanf ("%c", &n); getchar();
//    char S[100];
//    printf(" S: ");                    scanf ("%s", S); puts(S);
    printf(" ��������: ");                    scanf ("%f", &x);

    r = d = l = s = 0;

    switch (n) {
    case 'r':
        r = x;
        d = 2 * r;
        l = 2 * 3.14 * r;
        s = 3.14 * r * r;
        break;
    case 'd':
        r = x / 2;
        d = x;
        l = 2 * 3.14 * r;
        s = 3.14 * r * r;
        break;
    case 'l':
        r = x / 2 * 3.14;
        d = 2 * r;
        l = x;
        s = 3.14 * r * r;
        break;
    case 's':
        r = sqrt(x / 3.14);
        d = 2 * r;
        l = 2 * 3.14 * r;
        s = x;
        break;
    default: printf("Error");
    }

    printf(" r = %f\n d = %f\n l = %f\n s = %f\n", r, d, l, s);
}

case_11()
{
 int N_1, N_2;
 char c;

 printf(" ����������� = "); scanf("%c", &c);
 printf(" �������_1 = "); scanf("%d", &N_1);
 printf(" �������_2 = "); scanf("%d", &N_2);

 if ((-1 > N_1) || (2 < N_1) || (-1 > N_2) || (2 < N_2)) {puts(" Error"); return 1;} //���� ������������ ������ ������������ ����������� ������.

 // ��� ������� �������� �������� �, �, �, �?
 /*
 if ( strncmp ( c, '�', 2) == 0 )
{
  printf(" ��� = ");
}
*/

 switch(c)
 {

    case 'N':

        switch(N_1 + N_2)
        {
            case  1: c = 'W'; break;

            case -2:
            case  2: c = 'S'; break;

            case  3:
            case -1: c = 'E'; break;
        }
        break;

    case 'E':

        switch(N_1 + N_2)
        {
            case  1: c = 'N'; break;

            case -2:
            case  2: c = 'W'; break;

            case  3:
            case -1: c = 'S'; break;
        }
        break;

    case 'S':

        switch(N_1 + N_2)
        {

            case  1: c = 'E'; break;

            case -2:
            case  2: c = 'N'; break;

            case  3:
            case -1: c = 'W'; break;
        }
        break;

    case 'W':

        switch(N_1 + N_2)
        {

            case  1: c = 'S'; break;

            case -2:
            case  2: c = 'E'; break;

            case  3:
            case -1: c = 'N'; break;
        }
        break;

 }

 printf(" ����������� ������: %c\n", c);
 }

void case_10_a()
{
    int x = 0;
    int y = 0;
    char dir = 'N';

    while(1)
    {
        system("cls");

        printf(" x = %d   y = %d   dir = %c\n", x, y, dir );

        char command;
        printf(" command(L, R, G) = ");    command = getchar();getchar();//scanf("%c", &command);

        switch(command)
        {
        case 'L':
            switch(dir)
            {
                case 'N': dir = 'W'; break;
                case 'W': dir = 'S'; break;
                case 'S': dir = 'E'; break;
                case 'E': dir = 'N'; break;
            }
            break;
        case 'R':
            switch(dir)
            {
                case 'N': dir = 'E'; break;
                case 'W': dir = 'N'; break;
                case 'S': dir = 'W'; break;
                case 'E': dir = 'S'; break;
            }
            break;
        case 'G':
            switch(dir)
            {
                case 'N': y++; break;
                case 'W': x--; break;
                case 'S': y--; break;
                case 'E': x++; break;
            }
            break;
        }
    }

}


case_10()
{
    int n;
    char c;

    printf(" ����������� = ");
    scanf("%c", &c);
    printf(" ������� = ");
    scanf("%d", &n);

    if ((-1 > n) || (1 < n))
    {
        puts(" Error");    //���� ������������ ������ ������������ ����������� ������.
        return 1;
    }

// ��� ������� �������� �������� �, �, �, �?
    /*
    if ( strncmp ( c, '�', 2) == 0 )
    {
     printf(" ��� = ");
    }
    */

    switch(c)
    {

    case '�':

        switch(n)
        {
        case  1:
            c = '�';
            break;
        case  0:
            c = '�';
            break;
        case -1:
            c = '�';
            break;
        }
        break;

    case '�':

        switch(n)
        {
        case  1:
            c = '�';
            break;
        case  0:
            c = '�';
            break;
        case -1:
            c = '�';
            break;
        }
        break;

    case '�':

        switch(n)
        {
        case  1:
            c = '�';
            break;
        case  0:
            c = '�';
            break;
        case -1:
            c = '�';
            break;
        }
        break;

    case '�':

        switch(n)
        {
        case  1:
            c = '�';
            break;
        case  0:
            c = '�';
            break;
        case -1:
            c = '�';
            break;
        }
        break;

    }

    printf(" ����������� ������: %c\n", c);
}

case_09_a()
{
    int D, M, Y;
    printf(" D = ");    scanf("%d", &D);
    printf(" M = ");    scanf("%d", &M);
    printf(" Y = ");    scanf("%d", &Y);

    if(D < get_month_days(M, Y))
    {
        D++;
    }
    else
    {
        D = 1;
        M++;
        if(M == 13)
        {
            M = 1;
            Y++;
        }
    }

    printf("��������� ���� %02d/%02d/%04d\n", D, M, Y);
}

case_09()
{
     int D, M, Y;
     printf(" D = "); scanf("%d", &D);
     printf(" M = "); scanf("%d", &M);
     printf(" Y = "); scanf("%d", &Y);

 if (D < 1 || D > 31 || M < 1 || M > 12) {puts("Error"); return 1;} //���� ������������ ������ ������������ ���� ���� �����.


    if((D == 31) && (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12))
    {
        M++;
        D = 1;
        if(M == 13)
        {
            D = 1;
            M = 1;
            Y++;
        }
    }
    else if((D == 30) && (M == 4 || M == 6 || M == 9 || M == 11))
    {
        M++;
        D = 1;
    }
    else if((D == 28) || (D ==29) && (M == 2))
    {
        int B; // ��� �������� ����������� ����� ���������� ��� �������.
        B = get_month_days(M, Y);
        if(B > D)
        {
           printf(" ��� ������� ���� ��������� ���� ������� ����� 29 �����, ������� ���������� ����.");
           return 1;
        }
        if(B < D)
        {
           printf(" ��� ������� ���� ��������� ���� ������� ����� 28 �����, ������� ���������� ����.");
           return 1;
        }
    }
    else
    {
        D++;
    }

 /*
   switch (M)
   {
       case 1:
       case 3:
       case 5:
       case 7:
       case 8:
       case 10:
       case 12:
           if (D == 31)
           {
              D = 0;
           }
           break;

       case 4:
       case 6:
       case 9:
       case 11:
           if (D == 30)
           {
              D = 0;
           }
           break;

       case 2:
           if (D == 28)
           {
              D = 0;
           }
           break;
   }

   if (D == 0) //���� D = 0, �� ��������� �� ������� if (m==12) m=1;
    {
       if (M == 12)
       {
          M = 1;
       }
       else
       {
          M++;
       }
    }

   D++;
   */
   printf("���������� ���� %02d/%02d/%04d\n", D, M, Y);
   return 0;
}

void case_08()
{
    int D, M, Y;
    printf(" D = ");    scanf("%d", &D);
    printf(" M = ");    scanf("%d", &M);
    printf(" Y = ");    scanf("%d", &Y);


    if(D > 1)
    {
        D--;
    }
    else
    {
        M = M - 1;
        if(M == 0)
        {
            M = 12;
            Y--;
        }
        D = get_month_days(M, Y);
    }

    printf("���������� ���� %02d/%02d/%04d\n", D, M, Y);
}


case_07()
{
    int N;
    double M;
    printf(" N = "); scanf("%d", &N);
    printf(" M = "); scanf("%lf", &M);

    switch(N)
    {
        case 1: printf(" ��������� - ��������� %.2lf\n", M * 1); break;
        case 2: printf(" ���������� - ��������� %.2lf\n", M / 1000000); break;
        case 3: printf(" ����� - ��������� %.2lf\n", M / 1000); break;
        case 4: printf(" ����� - ��������� %.2lf\n", M * 1000); break;
        case 5: printf(" ������� - ��������� %.2lf\n", M * 100); break;
        default: puts("Error");
    }
}


case_06()
{
    int N;
    double L;
    printf(" N = "); scanf("%d", &N);
    printf(" L = "); scanf("%lf", &L);

    switch(N)
    {
        case 1: printf(" �������� - ���� %.2lf\n", L / 10); break;
        case 2: printf(" �������� - ���� %.2lf\n", L * 1000); break;
        case 3: printf(" ���� - ���� %.2lf\n", L * 1); break;
        case 4: printf(" ��������� - ���� %.2lf\n", L / 1000); break;
        case 5: printf(" ��������� - ���� %.2lf\n", L / 100); break;
        default: puts("Error");
    }

}

case_05()
{
    int n, a, b;
    printf(" n = "); scanf("%d", &n);
    printf(" a = "); scanf("%d", &a);
    printf(" b = "); scanf("%d", &b);

    switch(n)
    {
        case 1: printf(" �������� %d\n", a + b); break;
        case 2: printf(" ��������� %d\n", a - b); break;
        case 3: printf(" ��������� %d\n", a * b); break;
        case 4: printf(" ������� %d\n", a / b); break;
        default: puts("Error");
    }

}

case_04()
{
    int m, y;
    printf(" m = "); scanf("%d", &m);
    printf(" y = "); scanf("%d", &y);

    int day_count = get_month_days(m, y);
    printf(" ʳ������ ��� %d\n", day_count);
}

int get_month_days(int m, int y)
{
    switch(m)
    {
        case 1: return 31;
        case 2: return is_leap_year(y) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

bool is_leap_year(int y)
{
    bool f = false; //�� ����������� ��� 365

    if(y % 4 == 0)
    {
        f = true; //����������� ��� 366
        if(y % 100 == 0 && y % 400 != 0)
        {
            f = false; //�� ����������� ��� 365
        }
    }
    return f;
}

case_03()
{
    int n;
    printf(" n = "); scanf("%d", &n);

    switch(n)
    {
        case 12:
        case 1:
        case 2: puts("����"); break;
        case 3:
        case 4:
        case 5: puts("�����"); break;
        case 6:
        case 7:
        case 8: puts("˳��"); break;
        case 9:
        case 10:
        case 11: puts("����"); break;
        default: puts("Error");
    }

}

case_02()
{
    int k;
    printf(" k = "); scanf("%d", &k);

    switch(k)
    {
        case 1: puts("�����"); break;
        case 2: puts("�������������������"); break;
        case 3: puts("�����������������"); break;
        case 4: puts("������"); break;
        case 5: puts("�������"); break;
        default: puts("Error");
    }

}

case_01()
{
    int n;
    printf(" n = "); scanf("%d", &n);

    switch(n)
    {
        case 1: puts("�����i���"); break;
        case 2: puts("�i������"); break;
        case 3: puts("�����"); break;
        case 4: puts("������"); break;
        case 5: puts("�'������"); break;
        case 6: puts("������"); break;
        case 7: puts("�����"); break;
        default: puts("Error");
    }

}

#include "proc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define PI 3.1415926535


int main()
{

//proc01
/*
    for(int i = 0; i < 5; i++)
    {
        double A, B;
        printf("A: "); scanf("%lf", &A);
        PowerA3(A, &B);
        printf("%lf\n", B);
    }
*/


//Proc02
/*
    double A, B, C, D;
    for(int i = 0; i < 5; i++)
    {
        printf("A: "); scanf("%lf", &A);
        PowerA234(A, &B, &C, &D);
        printf("%lf %lf %lf\n", B, C, D);
    }
*/


//Proc03
/*
    double A, B, C, D;

    printf("A: "); scanf("%lf", &A);
    printf("B: "); scanf("%lf", &B);
    printf("C: "); scanf("%lf", &C);
    printf("D: "); scanf("%lf", &D);

    double AMean, GMean;
    Mean(A, B, &AMean, &GMean);
    printf("%lf %lf\n", AMean, GMean);
    Mean(A, C, &AMean, &GMean);
    printf("%lf %lf\n", AMean, GMean);
    Mean(A, D, &AMean, &GMean);
    printf("%lf %lf\n", AMean, GMean);
*/


//Proc04
/*
    for(int i = 0; i < 3; i++)
    {
        double a, P, S;
        printf("a: "); scanf("%lf", &a);
        TriaglePS(a, &P, &S);
        printf("P = %lf S = %lf\n", P, S);
    }
*/


//Proc05
/*
    for(int i = 0; i < 3; i++)
    {
        double x1, y1, x2, y2;
        printf("x1: "); scanf("%lf", &x1);
        printf("y1: "); scanf("%lf", &y1);
        printf("x2: "); scanf("%lf", &x2);
        printf("y2: "); scanf("%lf", &y2);

        double P, S;
        RectPS(x1, y1, x2, y2, &P, &S);
        printf("P = %lf S = %lf\n", P, S);
    }
*/


//Proc06
/*
    for(int i = 0; i < 5; i++)
    {
        int K;
        printf("K: "); scanf("%d", &K);

        int C, S;
        DigitCountSum(K, &C, &S);
        printf("C = %d S = %d\n\n", C, S);
    }
*/


//Proc07
/*
    for(int i = 0; i < 5; i++)
    {
        int K;
        printf("K: "); scanf("%d", &K);

        InvertDigits(&K);
        printf("InvertDigits = %d\n\n", K);
    }
*/



//Proc08
/*
        int K, D1, D2;
        printf("K: "); scanf("%d", &K);
        printf("\n");

        printf("D1: "); scanf("%d", &D1);
        AddRightDigit(D1, &K);
        printf("AddRightDigit = %d\n\n", K);

        printf("D2: "); scanf("%d", &D2);
        AddRightDigit(D2, &K);
        printf("AddRightDigit = %d\n\n", K);
*/


//Proc09
/*
    int K, D1, D2;
    printf("K: ");  scanf("%d", &K);
    printf("\n");

    printf("D1: "); scanf("%d", &D1);
    AddLeftDigit(D1, &K);
    printf("AddLeftDigit = %d\n\n", K);

    printf("D2: "); scanf("%d", &D2);
    AddLeftDigit(D2, &K);
    printf("AddLeftDigit = %d\n\n", K);
*/


    //Proc10
/*
    double A, B, C, D;
    printf("A: ");  scanf("%lf", &A);
    printf("B: ");  scanf("%lf", &B);
    printf("C: ");  scanf("%lf", &C);
    printf("D: ");  scanf("%lf", &D);

    Swap(&A, &B);
    Swap(&C, &D);
    Swap(&B, &C);

    printf("\n");
    printf("A: %lf\n", A);
    printf("B: %lf\n", B);
    printf("C: %lf\n", C);
    printf("D: %lf\n", D);
*/


    //Proc11
/*
    double A, B, C, D;
    printf("A: ");  scanf("%lf", &A);
    printf("B: ");  scanf("%lf", &B);
    printf("C: ");  scanf("%lf", &C);
    printf("D: ");  scanf("%lf", &D);

    Minmax(&A, &B);
    Minmax(&C, &D);
    Minmax(&A, &C);
    Minmax(&B, &D);

    printf("\n");
    printf("Min: %lf\n", A);
    printf("Max: %lf\n", D);
*/


    //Proc12
/*
    double A1, B1, C1;
    printf("A1: ");  scanf("%lf", &A1);
    printf("B1: ");  scanf("%lf", &B1);
    printf("C1: ");  scanf("%lf", &C1);

    double A2, B2, C2;
    printf("\n");
    printf("A2: ");  scanf("%lf", &A2);
    printf("B2: ");  scanf("%lf", &B2);
    printf("C2: ");  scanf("%lf", &C2);

    SortInc3(&A1, &B1, &C1);
    SortInc3(&A2, &B2, &C2);

    printf("\n");
    printf("A1: %lf\n", A1);
    printf("B1: %lf\n", B1);
    printf("C1: %lf\n", C1);

    printf("\n");
    printf("A2: %lf\n", A2);
    printf("B2: %lf\n", B2);
    printf("C2: %lf\n", C2);
*/


    //Proc13
/*
    double A1, B1, C1;
    printf("A1: ");  scanf("%lf", &A1);
    printf("B1: ");  scanf("%lf", &B1);
    printf("C1: ");  scanf("%lf", &C1);

    double A2, B2, C2;
    printf("\n");
    printf("A2: ");  scanf("%lf", &A2);
    printf("B2: ");  scanf("%lf", &B2);
    printf("C2: ");  scanf("%lf", &C2);

    SortDec3(&A1, &B1, &C1);
    SortDec3(&A2, &B2, &C2);

    printf("\n");
    printf("A1: %lf\n", A1);
    printf("B1: %lf\n", B1);
    printf("C1: %lf\n", C1);

    printf("\n");
    printf("A2: %lf\n", A2);
    printf("B2: %lf\n", B2);
    printf("C2: %lf\n", C2);
*/


    //Proc14
/*
    double A1, B1, C1;
    printf("A1: ");  scanf("%lf", &A1);
    printf("B1: ");  scanf("%lf", &B1);
    printf("C1: ");  scanf("%lf", &C1);

    double A2, B2, C2;
    printf("\n");
    printf("A2: ");  scanf("%lf", &A2);
    printf("B2: ");  scanf("%lf", &B2);
    printf("C2: ");  scanf("%lf", &C2);

    ShiftRight3(&A1, &B1, &C1);
    ShiftRight3(&A2, &B2, &C2);

    printf("\n");
    printf("A1: %lf\n", A1);
    printf("B1: %lf\n", B1);
    printf("C1: %lf\n", C1);

    printf("\n");
    printf("A2: %lf\n", A2);
    printf("B2: %lf\n", B2);
    printf("C2: %lf\n", C2);
*/


     //Proc15
/*
    double A1, B1, C1;
    printf("A1: ");  scanf("%lf", &A1);
    printf("B1: ");  scanf("%lf", &B1);
    printf("C1: ");  scanf("%lf", &C1);

    double A2, B2, C2;
    printf("\n");
    printf("A2: ");  scanf("%lf", &A2);
    printf("B2: ");  scanf("%lf", &B2);
    printf("C2: ");  scanf("%lf", &C2);

    ShiftLeft3(&A1, &B1, &C1);
    ShiftLeft3(&A2, &B2, &C2);

    printf("\n");
    printf("A1: %lf\n", A1);
    printf("B1: %lf\n", B1);
    printf("C1: %lf\n", C1);

    printf("\n");
    printf("A2: %lf\n", A2);
    printf("B2: %lf\n", B2);
    printf("C2: %lf\n", C2);
*/

//Proc 16
/*
int Sign(double X)
{
    if(X > 0) return 1;
    if(X < 0) return -1;
    return 0;
}
*/


//Proc 17
/*
int RootsCount(double A, double B, double C)
{
    double D = B * B - 4 * A * C;
    if(D > 0) return 2;
    if(D < 0) return 0;
    return 1;
}
*/


//Proc 18
/*
double CircleS(double R)
{
    double S = PI * R * R;
    return S;
}
*/


//Proc 19
/*
double RingS(double R1, double R2)
{
    double S1 = CircleS(R1);
    double S2 = CircleS(R2);
    return S1 - S2;
}
*/


//Proc 20
/*
double TriagleP(double a, double h)
{
    double b = sqrt(a/2 * a/2 + h * h);
    return a+b+b;
}
*/


//Proc 21
/*
int SumRange(int A, int B)
{
    int sum = 0;
    for(;A <= B; A++) {sum = sum + A;}
    return sum;
}
*/


//Proc 22
/*
double Calc(double A, double B, char Op)
{
    if(Op == '-') return A - B;
    if(Op == '*') return A * B;
    if(Op == '/') return A / B;
    if(Op == '+') return A + B;
    return 0;
}
*/


//Proc 23
/*
int Quarter(double x, double y)
{
    if(x > 0 && y > 0) return 1;
    else if(x < 0 && y > 0) return 2;
    else if(x < 0 && y < 0) return 3;
    else return 4;
}
*/


//Proc 24
/*
bool Even(int K)
{
    return K % 2 == 0;
}
*/


//Proc 25
/*
bool IsSquare(int K)
{
    int p = 0;
    while(p * p < K)
    {
        p++;
    }
    return p*p == K;
}
*/


//Proc 26
/*
bool IsPower5(int K)
{
    double temp = K;
    for (;temp >= 5; temp /= 5);
    return temp == 1;
}
*/


//Proc 26a
/*
bool IsPower5a(int K)
{
    while(K > 1)
    {
        if(K % 5 != 0) return false;
        K /= 5;
    }
    return true;
}
*/


//Proc 27
/*
bool IsPowerN(int K, int N)
{
    double temp = K;
    for (;temp >= N; temp /= N);
    return temp == 1;
}
*/

/*
bool IsPowerNa(int K, int N)
{
    while(K > 1)
    {
        if(K % N != 0) return false;
        K /= N;
    }
    return true;
}
*/

//Proc 28
/*
bool IsPrime(int N)
{
    for(int i = 2; i < sqrt(N)+1; i++)
    {
        if(K % i == 0) return false;
    }
    return true;
}
*/


//Proc 29
/*
int DigitCount(int K)
{
    if(K == 0) return 1;
    int cnt = 0;
    while(K != 0)
    {
        cnt++;
        K = K / 10;
    }
    return cnt;
}
*/


//Proc 30
/*
int DigitN(int K, int N)
{
    int count = 0;
    while(K != 0)
    {
        int digit = K % 10;
        if(count == N) return digit;
        K = K / 10;
        count++;
    }
    return 0;
}
*/


//Proc 31
/*
bool IsPalindrom(int K)
{
   int p = K;
   InvertDigits(&p);
   return K == p;
}
*/


//Proc 32
/*
double DegToRad(double D)
{
    return PI / 180.0 * D;
}
*/


//Proc 33
/*
double RadToDeg(double R)
{
    return 180.0 / PI * R;
}
*/


//Proc 34
/*
double Fact(int N)
{
   double n = 1;
    for(int i = 1; i <= N; i++)
    {
        n = n * i;
    }
    return n;
}
*/


//Proc 35
/*
double Fact2(int N)
{
   double n = 1;
   if(N % 2 != 0)
    {
        for(int i = 1; i <= N; i+=2)
        {
            n = n * i;
        }
    }
    else
    {
       for(int i = 2; i <= N; i+=2)
        {
            n = n * i;
        }
    }
    return n;
}
*/


//Proc 35a
/*
double aFact2(int N)
{
   double n = 1;
   int start = 1;
   if(N % 2 == 0) start = 2;
     for(int i = start; i <= N; i+=2)
     {
         n = n * i;
     }

    return n;
}
*/


//Proc 36
/*
int Fib(int N)
{
    if(N <= 0) return 0;
    if(N < 3) return 1;
    int F, F1 = 1, F2 = 1;
    for(int i = 3; i <= N; i++)
    {
        F = F2 + F1;
        F2 = F1;
        F1 = F;
    }
    return F;
}
*/


//Proc 37
/*
double Power1(double A, double B)
{
    return A > 0 ? exp(B * log(A)) : 0;
}
*/


//Proc 38
/*
double Power2(double A, int N)
{
    if(N == 0) return 1;

    if(N > 0)
    {
	double a = 1;
        for(int i = 0; i < N; i++) a = a * A;
        return a;
    }

    if(N < 0)
    {
	double a = 1;
        for(int i = 0; i < -N; i++)  a = a * A;
        return 1.0 / a;
    }
}
*/


//Proc 39
/*
double Power3(double A, double B)
{

    if(B - (int)B == 0)
    {
        return Power2(A, B);
    }
    else
    {
        return Power1(A, B);
    }
}
*/


//Proc 40
/*
double Exp1(double x, double e)
{
double sum = 0;
double pow = 1;
double fact = 1;
double i = 1;
while(true)
{
    double temp = pow / fact;
    sum = sum + temp;
    if(fabs(temp) < e) break;
    pow = pow * x;
    fact = fact * i;
    i++;
}
return sum;
}
*/


//Proc 41
/*
double Sin1(double x, double e)
{
double epsil = 1;
double sin = 0;
double pow = x;
double fact = 1;
double i = 1;
double sign = 1;

while(epsil > e)
{
    epsil = pow / fact;
    sin = sin + epsil * sign;
    pow = pow * x * x;
    i = i + 2;
    fact = fact * (i-1) * i;
    sign = sign * -1;
}
return sin;
}
*/


//Proc 42
/*
double Cos1(double x, double e)
{
double epsil = 1;
double sin = 0;
double pow = 1;
double fact = 1;
double i = 0;
double sign = 1;

while(epsil > e)
{
    i++;
    epsil = pow / fact;
    sin = sin + epsil * sign;
    pow = pow * x * x;
    fact = fact * i * (i+1);
    sign = sign * -1;
    i++;
}
return cos;
}
*/


//Proc 43
/*
double Ln1(double x, double e)
{
double epsil = 1;
double sum = 0;
double num = x;
double den = 1;
double sign = 1;

while(epsil > e)
{
    epsil = num / den;
    sum = sum + epsil * sign;
    num = num * x;
    sign = -sign;
    den++;
}
return sum;
}
*/


//Proc 44
/*
double Arctg1(double x, double e)
{
double epsil = 1;
double sum = 0;
double num = x;
double den = 1;
double sign = 1;

while(epsil > e)
{
    epsil = num / den;
    sum = sum + epsil * sign;
    num = num * x * x;
    sign = -sign;
    den = den + 2;
}
return sum;
}
*/


//Proc 45
/*
double Power4(double x, double a, double e)
{
    double sum = 0;
    double num = 1;
    double den = 1;
    double k = 0;

    while(true)
    {
        double dod = num / den;
        sum = sum + dod;
        if(fabs(dod) < e) break;
        num = num * x * (a - k);
        k++;
        den = den * k;
    }
    return sum;
}
*/


//Proc 46
/*
int NOD2(int A, int B)
{
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

    return A;
}
*/





    return 0;
}



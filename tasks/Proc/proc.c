#include "proc.h"

//Proc01

void PowerA3(double A, double *B)
{
    *B = A * A * A;
}



//Proc02

void PowerA234(double A, double *B, double *C, double *D)
{
    *B = A * A;
    *C = A * A * A;
    *D = A * A * A * A;
}



//Proc03

void Mean(double X, double Y, double *AMean, double *GMean)
{
    *AMean = (X+Y) / 2;
    *GMean = sqrt(X*Y);
}



//Proc04

void TriaglePS(double a, double *P, double *S)
{
    *P = 3 * a;
    *S = a * a * sqrt(3.0 / 4.0);
}



//Proc05

void RectPS(double x1, double y1, double x2, double y2, double *P, double *S)
{
    double a = fabs(x1 - x2);
    double b = fabs(y1 - y2);
    *P = 2 * (a + b);
    *S = a * b;
}



//Proc06

void DigitCountSum(int K, int *C, int *S)
{
    *C = 0;
    *S = 0;
    while(K != 0)
    {
        *S = *S + (K%10);
        K = K / 10;
        *C = *C + 1;
    }
}



//Proc07

void InvertDigits(int *K)
{
    int I = 0;
    while(true)
    {
        I = (I + (*K % 10));
        *K = *K / 10;
        if(*K == 0) break;
        I = I * 10;
    }
    *K = I;
}

//Proc07a

void aInvertDigits(int *K)
{
    int S = 0;
    while(*K != 0)
    {
        S = S*10 + *K%10;
        *K = *K / 10;
    }
    *K = S;
}


//Proc08

void AddRightDigit(int D, int *K)
{
    *K = *K * 10 + D;
}


//Proc09

void AddLeftDigit(int D, int *K)//120
{
    AddRightDigit(1, K);//1201
    aInvertDigits(K);//1021
    AddRightDigit(D, K);//1021D
    aInvertDigits(K);//D1201
    *K = *K / 10;//D120
}



//Proc10

void Swap(double *X, double *Y)
{
    double t = *X;
    *X = *Y;
    *Y = t;
}



//Proc11

void Minmax(double *X, double *Y)
{
    if(*X > *Y)
    {
        Swap(X, Y);
    }
}


//Proc12

void SortInc3(double *A, double *B, double *C)
{
    Minmax(A, B);
    Minmax(B, C);
    Minmax(A, B);
}



//Proc13

void SortDec3(double *A, double *B, double *C)
{
    Minmax(C, B);
    Minmax(B, A);
    Minmax(C, B);
}



//Proc14

void ShiftRight3(double *A, double *B, double *C)
{
    Swap(B, C);
    Swap(A, B);
}



//Proc15
void ShiftLeft3(double *A, double *B, double *C)
{
    Swap(A, B);
    Swap(B, C);
}


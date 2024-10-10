#ifndef PROC_H_INCLUDED
#define PROC_H_INCLUDED

void PowerA3(double A, double *B);
void PowerA234(double A, double *B, double *C, double *D);
void Mean(double X, double Y, double *AMean, double *GMean);
void TriaglePS(double a, double *P, double *S);
void RectPS(double x1, double y1, double x2, double y2, double *P, double *S);
void DigitCountSum(int K, int *C, int *S);
void InvertDigits(int *K);
void AddRightDigit(int D, int *K);
void AddLeftDigit(int D, int *K);
void Swap(double *X, double *Y);
void Minmax(double *X, double *Y);
void SortInc3(double *A, double *B, double *C);
void SortDec3(double *A, double *B, double *C);
void ShiftRight3(double *A, double *B, double *C);
void ShiftLeft3(double *A, double *B, double *C);
/////////////////////////////////////////////////////////////
//int Sign(double X);                               //Proc 16
//int RootsCount(double A, double B, double C);     //Proc 17
//double CircleS(double R);                         //Proc 18
//double RingS(double R1, double R2);               //Proc 19
//double TriagleP(double a, double h);              //Proc 20
//int SumRange(int A, int B);                       //Proc 21
//double Calc(double A, double B, int Op);          //Proc 22
//int Quarter(double x, double y);                  //Proc 23
//bool Even(int K);                                 //Proc 24
//bool IsSquare(int K);                             //Proc 25
//bool IsPower5(int K);                             //Proc 26
//bool IsPowerN(int K, int N);                      //Proc 27
//bool IsPrime(int N);                              //Proc 28
//int DigitCount(int K);                            //Proc 29
//int DigitN(int K, int N);                         //Proc 30
//bool IsPalindrom(int K);                          //Proc 31
//double DegToRad(double D);                        //Proc 32
//double RadToDeg(double R);                        //Proc 33
//double Fact(int N);                               //Proc 34
//double Fact2(int N);                              //Proc 35
//int Fib(int N);                                   //Proc 36
//double Power1(double A, double B);                //Proc 37
//double Power2(double A, int N);                   //Proc 38
//double Power3(double A, double B);                //Proc 39
//double Exp1(double x, double e);                  //Proc 40
//double Sin1(double x, double e);                  //Proc 41
//double Cos1(double x, double e);                  //Proc 42
//double Ln1(double x, double e);                   //Proc 43
//double Arctg1(double x, double e);                //Proc 44
//double Power4(double x, double a, double e);      //Proc 45
//int NOD2(int A, int B);                           //Proc 46

#endif // PROC_H_INCLUDED

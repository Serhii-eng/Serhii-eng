#ifndef MATR_TOOLS_H_INCLUDED
#define MATR_TOOLS_H_INCLUDED

#include <stdbool.h>

#define N 100

typedef double Matr[N][N];
typedef double Array[N];
typedef double** DynamicMatr;
typedef int** DynamicIntMatr;
typedef char** DynamicCharMatr;

typedef struct
{
    double min;
    int min_row;    int min_column;
    double max;
    int max_row;
    int max_column;
    double sum;
    double average;
} MatrInfo;

typedef struct
{
    int i;
    int j;
} Pos_point;

typedef struct
{
    double* M;
    int m;
    int n;
} OneDim;

MatrInfo getMatrInfo(DynamicMatr M, int m, int n);

void showMatr(Matr M, int m, int n);
void showDynamicMatr(DynamicMatr M, int m, int n);
void showDynamicIntMatr(DynamicIntMatr M, int m, int n);
double** createDynamicMatr(int m, int n);
double** createDynamicMatr_zero(int m, int n);
char** createDynamicCharMatr_zero(int m, int n);
void fillDynamicMatrRnd(DynamicMatr M, int m, int n,int from, int to);
void fillDynamicIntMatrRnd(DynamicIntMatr M, int m, int n, int from, int to);
void deleteDynamicMatr(DynamicMatr *M, int m, int n);
void deleteDynamicIntMatr(DynamicIntMatr *M, int m, int n);
void swapRowDynamicMatr(DynamicMatr M, int m, int n, int row1, int row2);
void swapColumnDynamicMatr(DynamicMatr M, int m, int n, int column1, int column2);
void deleteRowDynamicMatr(DynamicMatr *M, int* m, int* n, int row);
void deleteColumnDynamicMatr(DynamicMatr *M, int* m, int* n, int column);
double* createDblArray(int n);
int* createIntArray(int n);
bool isRowsSimilar(DynamicIntMatr M, int m, int n, int row1, int row2);
bool isRowsSimilar_manyCycles(DynamicIntMatr M, int m, int n, int row1, int row2);
bool isColumnPositive(DynamicMatr M, int j, int m);
bool isColumnNegative(DynamicMatr M, int j, int m);
void addRowDynamicMatr_zero(DynamicMatr *M, int* m, int* n, int row);
void addColumnDynamicMatr_zero(DynamicMatr M, int* m, int* n, int column);
void addColumnDynamicMatr_value(DynamicMatr M, int* m, int* n, int column, double value);
bool is_local_min_Matr(DynamicMatr M, int m, int n, int pos_i, int pos_j);
bool is_local_max_Matr(DynamicMatr M, int m, int n, int pos_i, int pos_j);
int posMinInStringDynamicMatr(DynamicMatr M, int m, int n, int pos_i);
int posMaxInColumnDynamicMatr(DynamicMatr M, int m, int n, int pos_j);
double* createOneDimentinalMatr_zero(int m, int n);
double getValueOneDimentinalMatr(double* M, int m, int pos_i, int pos_j);
void setValueOneDimentinalMatr(double* M, int m, int pos_i, int pos_j, double value);

OneDim createM_zero(int m, int n);
void fillM(OneDim* Matr, int from, int to);
double getValueM(OneDim* Matr, int pos_i, int pos_j);
void setValueM(OneDim* Matr, int pos_i, int pos_j, double value);
void showM(OneDim* Matr);
void deleteM(OneDim* Matr);
double sumParallelMainDiagonalM(OneDim* Matr, int d);
double sumParallelSideDiagonalM(OneDim* Matr, int d);
double ariphParallelMainDiagonalM(OneDim* Matr, int d);
double ariphParallelSideDiagonalM(OneDim* Matr, int d);
double minParallelMainDiagonalM(OneDim* Matr, int d);
double maxParallelSideDiagonalM(OneDim* Matr, int d);
void zeroMainDiagonalM(OneDim* Matr, int d);
void transpositionRelativeToMainDiagonalM(OneDim* Matr, int m, int n);
void transpositionRelativeToSideDiagonalM(OneDim* Matr, int m, int n);
void positiveRotate90degreeM(OneDim* Matr, int m, int n);
void negativeRotate90degreeM(OneDim* Matr, int m, int n);
void mirrorImageHorizontalAxis(OneDim* Matr, int m, int n);





#endif // MATR_TOOLS_H_INCLUDED

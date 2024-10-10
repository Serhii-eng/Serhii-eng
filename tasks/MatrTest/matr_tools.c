#include "intset.h"
#include "matr_tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void showMatr(Matr M, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%3.0lf ", M[i][j]);
        }
        puts("");
    }
    puts("");
}


void showDynamicMatr(DynamicMatr M, int m, int n)
{
   for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%5.2lf ", M[i][j]);
        }
        puts("");
    }
    puts("");
}


void showDynamicIntMatr(DynamicIntMatr M, int m, int n)
{
   for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%3d ", M[i][j]);
        }
        puts("");
    }
    puts("");
}


double** createDynamicMatr(int m, int n)
{
    double** M = (double**) malloc(sizeof(double*) * m);

    for(int i = 0; i < m; i++)
    {
        M[i] = (double*) malloc(sizeof(double) * n);
    }

    return M;
}


double** createDynamicMatr_zero(int m, int n)
{
    double** M = (double**) malloc(sizeof(double*) * m);

    for(int i = 0; i < m; i ++)
    {
        M[i] = (double*) malloc(sizeof(double) * n);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
    }

    return M;
}


int** createDynamicIntMatr_zero(int m, int n)
{
    int** M = (int**) malloc(sizeof(int*) * m);

    for(int i = 0; i < m; i ++)
    {
        M[i] = (int*) malloc(sizeof(int) * n);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
    }

    return M;
}


char** createDynamicCharMatr_zero(int m, int n)
{
    char** M = (char**) malloc(sizeof(char*) * m);

    for(int i = 0; i < m; i++)
    {
        M[i] = (char*) malloc(sizeof(char) * n);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = 0;
        }
    }

    return M;
}


void deleteDynamicMatr(DynamicMatr *M, int m, int n)
{
    for(int i = 0; i < m; i ++)
    {
        free((*M)[i]);
    }

    free(*M);

    *M = NULL;
}


void deleteDynamicIntMatr(DynamicIntMatr *M, int m, int n)
{
    for(int i = 0; i < m; i ++)
    {
        free((*M)[i]);
    }

    free(*M);

    *M = NULL;
}


void fillDynamicMatrRnd(DynamicMatr M, int m, int n, int from, int to)
{
   for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = (from*100 + rand() % ((from-to) * 100)) / 100.0;
        }
    }
}


void fillDynamicIntMatrRnd(DynamicIntMatr M, int m, int n, int from, int to)
{
   for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = from + rand() % (to - from);
        }
    }
}


void swapRowDynamicMatr(DynamicMatr M, int m, int n, int row1, int row2)
{
    double* temp = M[row1];
    M[row1] = M[row2];
    M[row2] = temp;
}


void swapColumnDynamicMatr(DynamicMatr M, int m, int n, int column1, int column2)
{
    if(column1 == column2) return;

    for(int i = 0; i < m; i++)
    {
        double temp = M[i][column1];
        M[i][column1] = M[i][column2];
        M[i][column2] = temp;
    }
}


void deleteRowDynamicMatr(DynamicMatr *M, int* m, int* n, int row)
{
    int m2 = *m;
    double** M2 = (double**) malloc(sizeof(double*) * (m2-1));

    int a = 0;
    for(int i = 0; i < m2; i ++)
    {
        if(i != row) M2[a++] = (*M)[i];
    }

    free((*M)[row]);
    free(*M);

    *M = M2;

    (*m)--;
}


void deleteColumnDynamicMatr(DynamicMatr *M, int* m, int* n, int column)
{
    for(int i = 0; i < *m; i ++)
    {
         double* M_temp = (double*) malloc(sizeof(double) * (*n)-1);
         //double watch = 0;
         int k = 0;
         for(int j = 0; j < *n; j++)
         {
             if(j != column)
             {
                M_temp[k++] = (*M)[i][j];
                //watch = (*M)[i][j];
             }
         }
         free((*M)[i]);
         (*M)[i] = M_temp;
    }

    (*n)--;
}


MatrInfo getMatrInfo(DynamicMatr M, int m, int n)
{
    MatrInfo mInfo;

    mInfo.max_column = 0;
    mInfo.max_row = 0;
    mInfo.min_row = 0;
    mInfo.min_column = 0;
    mInfo.sum = 0;
    mInfo.min = M[0][0];
    mInfo.max = M[0][0];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mInfo.sum += M[i][j];
            if(M[i][j] < mInfo.min)
            {
                mInfo.min = M[i][j];
                mInfo.min_row = i;
                mInfo.min_column = j;
            }

            if(M[i][j] > mInfo.max)
            {
                mInfo.max = M[i][j];
                mInfo.max_row = i;
                mInfo.max_column = j;
            }
        }
    }

    mInfo.average = mInfo.sum / (m*n);

    return mInfo;
}


double* createDblArray(int n)
{
    double* A = (double*)malloc(sizeof(double) * n);
    for(int i = 0; i < n; i++)
    {
        A[i] = 0;
    }
    return A;
}


int* createIntArray(int n)
{
    int* A = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        A[i] = 0;
    }
    return A;
}


bool isRowsSimilar(DynamicIntMatr M, int m, int n, int row1, int row2)
{
    IntSet s1 = createIntSet(n);
    for(int j = 0; j < n; j++) insertToIntSet(&s1, M[row1][j]);

    IntSet s2 = createIntSet(n);
    for(int j = 0; j < n; j++) insertToIntSet(&s2, M[row2][j]);

    bool ok = isIntSetsEquale(&s1, &s2);

    deleteIntSet(&s1);
    deleteIntSet(&s2);
    return ok;
}


bool isRowsSimilar_manyCycles(DynamicIntMatr M, int m, int n, int row1, int row2)
{
    for(int j = 0; j < n; j++)
    {
        bool ok = false;
        for(int k = 0; k < n; k++)
        {
            if(M[row1][j] == M[row2][k])
            {
                ok = true;
                break;
            }
        }
        if(!ok) return false;
    }

    for(int j = 0; j < n; j++)
    {
        bool ok = false;
        for(int k = 0; k < n; k++)
        {
            if(M[row2][j] == M[row1][k])
            {
                ok = true;
                break;
            }
        }
        if(!ok) return false;
    }
    return true;
}


bool isColumnPositive(DynamicMatr M, int j, int m)
{
    for(int i = 0; i < m; i++)
    {
        if(M[i][j] < 0) return false;
    }

    return true;
}


bool isColumnNegative(DynamicMatr M, int j, int m)
{
    for(int i = 0; i < m; i++)
    {
        if(M[i][j] > 0) return false;
    }

    return true;
}


void addRowDynamicMatr_zero(DynamicMatr *M, int* m, int* n, int row)
{
    int m2 = *m;
    double** M2 = (double**) malloc(sizeof(double*) * (m2+1));

    int a = 0;
    for(int i = 0; i < m2; i++)
    {
        if(i == row) a++;
        M2[a++] = (*M)[i];
    }

    M2[row] = (double*) malloc(sizeof(double) * (*n));
    for(int j = 0; j < *n; j++)
    {
        M2[row][j] = 0;
    }

    free(*M);

    *M = M2;

    (*m)++;


}


void addColumnDynamicMatr_zero(DynamicMatr M, int* m, int* n, int column)
{
    addColumnDynamicMatr_value(M, m, n, column, 0);
}


void addColumnDynamicMatr_value(DynamicMatr M, int* m, int* n, int column, double value)
{
    int m2 = *m;
    int n2 = *n;


    for(int i = 0; i < m2; i++)
    {
        int a = 0;
        double* M2 = (double*) malloc(sizeof(double) * (n2+1));
        for(int j = 0; j < n2; j++)
        {
            if(j == column)
            {
                M2[a++] = value;
            }
            M2[a++] = M[i][j];
        }

        free(M[i]);
        M[i] = M2;
    }

    (*n)++;
}


bool is_local_min_Matr(DynamicMatr M, int m, int n, int pos_i, int pos_j)
{
    int i = pos_i;
    int j = pos_j;

    //Перевірка
    if(i < 0 || j < 0)       return false;

    //Кути матриці.
    if(i == 0 && j == 0)     return M[i][j] < M[i][j+1] && M[i][j] < M[i+1][j+1] && M[i][j] < M[i+1][j];
    if(i == 0 && j == n-1)   return M[i][j] < M[i][j-1] && M[i][j] < M[i+1][j-1] && M[i][j] < M[i+1][j];
    if(i == m-1 && j == 0)   return M[i][j] < M[i-1][j] && M[i][j] < M[i-1][j-1] && M[i][j] < M[i][j+1];
    if(i == m-1 && j == n-1) return M[i][j] < M[i-1][j] && M[i][j] < M[i-1][j-1] && M[i][j] < M[i][j-1];

    //Границі матриці в які не входять кути.
    if(i == 0 && j > 0)      return M[i][j] < M[i][j-1] && M[i][j] < M[i+1][j-1] && M[i][j] < M[i+1][j] && M[i][j] < M[i+1][j+1] && M[i][j] < M[i][j+1];
    if(i > 0 && j == 0)      return M[i][j] < M[i-1][j] && M[i][j] < M[i-1][j+1] && M[i][j] < M[i][j+1] && M[i][j] < M[i+1][j+1] && M[i][j] < M[i+1][j];
    if(i > 0 && j == n-1)    return M[i][j] < M[i-1][j] && M[i][j] < M[i-1][j-1] && M[i][j] < M[i][j-1] && M[i][j] < M[i+1][j-1] && M[i][j] < M[i+1][j];
    if(i == m-1 && j > 0)    return M[i][j] < M[i][j-1] && M[i][j] < M[i-1][j-1] && M[i][j] < M[i-1][j] && M[i][j] < M[i-1][j+1] && M[i][j] < M[i][j+1];

    //Cередина матриці.
    if(i > 0 && j > 0)
    {
        return M[i][j] < M[i-1][j] && M[i][j] < M[i-1][j+1] && M[i][j] < M[i][j+1] && M[i][j] < M[i+1][j+1]
        && M[i][j] < M[i+1][j] && M[i][j] < M[i+1][j-1] && M[i][j] < M[i][j-1] && M[i][j] < M[i-1][j-1];
    }
}


bool is_local_max_Matr(DynamicMatr M, int m, int n, int pos_i, int pos_j)
{
    int i = pos_i;
    int j = pos_j;

    //Перевірка
    if(i < 0 || j < 0)       return false;

    //Кути матриці.
    if(i == 0 && j == 0)     return M[i][j] > M[i][j+1] && M[i][j] > M[i+1][j+1] && M[i][j] > M[i+1][j];
    if(i == 0 && j == n-1)   return M[i][j] > M[i][j-1] && M[i][j] > M[i+1][j-1] && M[i][j] > M[i+1][j];
    if(i == m-1 && j == 0)   return M[i][j] > M[i-1][j] && M[i][j] > M[i-1][j-1] && M[i][j] > M[i][j+1];
    if(i == m-1 && j == n-1) return M[i][j] > M[i-1][j] && M[i][j] > M[i-1][j-1] && M[i][j] > M[i][j-1];

    //Границі матриці в які не входять кути.
    if(i == 0 && j > 0)      return M[i][j] > M[i][j-1] && M[i][j] > M[i+1][j-1] && M[i][j] > M[i+1][j] && M[i][j] > M[i+1][j+1] && M[i][j] > M[i][j+1];
    if(i > 0 && j == 0)      return M[i][j] > M[i-1][j] && M[i][j] > M[i-1][j+1] && M[i][j] > M[i][j+1] && M[i][j] > M[i+1][j+1] && M[i][j] > M[i+1][j];
    if(i > 0 && j == n-1)    return M[i][j] > M[i-1][j] && M[i][j] > M[i-1][j-1] && M[i][j] > M[i][j-1] && M[i][j] > M[i+1][j-1] && M[i][j] > M[i+1][j];
    if(i == m-1 && j > 0)    return M[i][j] > M[i][j-1] && M[i][j] > M[i-1][j-1] && M[i][j] > M[i-1][j] && M[i][j] > M[i-1][j+1] && M[i][j] > M[i][j+1];

    //Cередина матриці.
    if(i > 0 && j > 0)
    {
        return M[i][j] > M[i-1][j] && M[i][j] > M[i-1][j+1] && M[i][j] > M[i][j+1] && M[i][j] > M[i+1][j+1]
        && M[i][j] > M[i+1][j] && M[i][j] > M[i+1][j-1] && M[i][j] > M[i][j-1] && M[i][j] > M[i-1][j-1];
    }
}


bool is_local_max_Matr1(DynamicMatr M, int m, int n, int pos_i, int pos_j)
{
    int i1 = pos_i - 1; if(i1 < 0) i1 = 0;
    int j1 = pos_j - 1; if(j1 < 0) j1 = 0;
    int i2 = pos_i + 1; if(i2 >= m) i2 = m-1;
    int j2 = pos_j + 1; if(j1 >= n) j2 = n-1;

    for(int i = i1; i <= i2; i++)
    {
        for(int j = j1; j <= j2; j++)
        {
            if(i == pos_i && j == pos_j) continue;
            if(M[i][j] >= M[pos_i][pos_j]) return false;
        }
    }
    return true;
}


bool is_local_min_Matr1(DynamicMatr M, int m, int n, int pos_i, int pos_j)
{
    int i1 = pos_i - 1; if(i1 < 0) i1 = 0;
    int j1 = pos_j - 1; if(j1 < 0) j1 = 0;
    int i2 = pos_i + 1; if(i2 >= m) i2 = m-1;
    int j2 = pos_j + 1; if(j1 >= n) j2 = n-1;

    for(int i = i1; i <= i2; i++)
    {
        for(int j = j1; j <= j2; j++)
        {
            if(i == pos_i && j == pos_j) continue;
            if(M[i][j] <= M[pos_i][pos_j]) return false;
        }
    }
    return true;
}


void sortDecLastElemColumnDynamicMatr(DynamicMatr M, int m, int n)
{
    for(int j = 0; j < n-1; j++)
    {
        for(int k = j+1; k < n; k++)
        {
            if(M[m-1][k] > M[m-1][j]) swapColumnDynamicMatr(M, m, n, j, k);
        }
    }
}


int posMinInStringDynamicMatr(DynamicMatr M, int m, int n, int pos_i)
{
    double min = M[pos_i][0];
    int pos_min = 0;
    for(int j = 0; j < n; j++)
    {
        if(M[pos_i][j] < min)
        {
            min = M[pos_i][j];
            pos_min = j;
        }
    }

    return pos_min;
}


int posMaxInColumnDynamicMatr(DynamicMatr M, int m, int n, int pos_j)
{
    double max = M[0][pos_j];
    int pos_max = 0;
    for(int i = 0; i < m; i++)
    {
        if(M[i][pos_j] > max)
        {
            max = M[i][pos_j];
            pos_max = i;
        }
    }

    return pos_max;
}


double* createOneDimentinalMatr_zero(int m, int n) //Передавати параметры матриці в структурі.
{
    //Створити змінну структурного типу
    double* M = (double*) malloc(sizeof(double) * m*n);

    for(int i = 0; i < m*n; i++)
    {
        M[i] = 0;
    }

    return M;
}


void fillOneDimentinalMatr(double* M, int m, int n, int from, int to)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i*m + j] = (from*100 + rand() % ((from-to) * 100)) / 100.0;
        }
    }
}


double getValueOneDimentinalMatr(double* M, int m, int pos_i, int pos_j)
{
    return M[pos_i*m + pos_j];
}


void setValueOneDimentinalMatr(double* M, int m, int pos_i, int pos_j, double value)
{
    M[pos_i*m + pos_j] = value;
}


void showOneDimentinalMatr(double* M, int m, int n)
{
    puts("");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%.2lf ", M[i*m + j]);
        }
        puts("");
    }
}


OneDim createM_zero(int m, int n)
{
    OneDim Matr;

    Matr.m = m;
    Matr.n = n;
    Matr.M = (double*) malloc(sizeof(double) * m*n);

    for(int i = 0; i < m*n; i++)
    {
        Matr.M[i] = 0;
    }

    return Matr;
}


void fillM(OneDim* Matr, int from, int to)
{
    int m = Matr->m;
    int n = Matr->n;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Matr->M[i*m + j] = (from*100 + rand() % ((from-to) * 100)) / 100.0;
        }
    }
}


double getValueM(OneDim* Matr, int pos_i, int pos_j)
{
    int m = Matr->m;
    return Matr->M[pos_i*m + pos_j];
}


void setValueM(OneDim* Matr, int pos_i, int pos_j, double value)
{
    int m = Matr->m;
    Matr->M[pos_i*m + pos_j] = value;
}


void showM(OneDim* Matr)
{
    int m = Matr->m;
    int n = Matr->n;

    puts("");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%5.2lf ", Matr->M[i*m + j]);
        }
        puts("");
    }
}


double sumParallelMainDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = 0;

    if(d > 0) j = d;
    if(d < 0) i = -d;

    double sum = 0;
    while(i < m && j < n)
    {
        sum += getValueM(Matr, i, j);

        i++;
        j++;
    }

    return sum;
}


double sumParallelSideDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = n-1;

    if(d > 0) j = (n-1) - d;
    if(d < 0) i = -d;

    double sum = 0;
    while(i < m && j >= 0)
    {
        sum += getValueM(Matr, i, j);

        i++;
        j--;
    }

    return sum;
}


double ariphParallelMainDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = 0;

    if(d > 0) j = d;
    if(d < 0) i = -d;

    int cnt = 0;
    double sum = 0;
    while(i < m && j < n)
    {
        sum += getValueM(Matr, i, j);

        i++;
        j++;
        cnt++;
    }

    return sum/cnt;
}


double ariphParallelSideDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = n-1;

    if(d > 0) j = (n-1) - d;
    if(d < 0) i = -d;

    int cnt = 0;
    double sum = 0;
    while(i < m && j >= 0)
    {
        sum += getValueM(Matr, i, j);

        i++;
        j--;
        cnt++;
    }

    return sum / cnt;
}


double minParallelMainDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = 0;

    if(d > 0) j = d;
    if(d < 0) i = -d;

    double min = getValueM(Matr, i, j);
    while(i < m && j < n)
    {
        double value = getValueM(Matr, i, j);
        if(value < min) min = value;

        i++;
        j++;
    }

    return min;
}


double maxParallelSideDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = n-1;

    if(d > 0) j = (n-1) - d;
    if(d < 0) i = -d;

    double max = getValueM(Matr, i, j);
    while(i < m && j >= 0)
    {
        double value = getValueM(Matr, i, j);
        if(value > max) max = value;

        i++;
        j--;
    }

    return max;
}





void zeroMainDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = 0;

    if(d > 0) j = d;
    if(d < 0) i = -d;

    while(i < m && j < n)
    {
        setValueM(Matr, i, j, 0.0);

        i++;
        j++;
    }
}


double zeroSideDiagonalM(OneDim* Matr, int d)
{
    int m = Matr->m;
    int n = Matr->n;

    int i = 0;
    int j = n-1;

    if(d > 0) j = (n-1) - d;
    if(d < 0) i = -d;

    while(i < m && j >= 0)
    {
        setValueM(Matr, i, j, 0.0);

        i++;
        j--;
    }
}


void deleteM(OneDim* Matr)
{
    free(Matr->M);
    Matr->m = 0;
    Matr->m = 0;
}


void transpositionRelativeToMainDiagonalM(OneDim* Matr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < i; j++)
        {
            double temp = getValueM(Matr, i, j);
            setValueM(Matr, i, j, getValueM(Matr, j, i));
            setValueM(Matr, j, i, temp);
        }
    }
}


void transpositionRelativeToSideDiagonalM(OneDim* Matr, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = n-1; j > m-i-1; j--)
        {
            double temp = getValueM(Matr, i, j);
            setValueM(Matr, i, j, getValueM(Matr, n-j-1, m-i-1));
            setValueM(Matr, n-j-1, m-i-1, temp);
        }
    }
}


void positiveRotate90degreeM(OneDim* Matr, int m, int n)
{
    transpositionRelativeToMainDiagonalM(Matr, m, n);
    mirrorImageHorizontalAxis(Matr, m, n);
}


void negativeRotate90degreeM(OneDim* Matr, int m, int n)
{
    transpositionRelativeToSideDiagonalM(Matr, m, n);
    mirrorImageHorizontalAxis(Matr, m, n);
}


void mirrorImageHorizontalAxis(OneDim* Matr, int m, int n)
{
    int i = 0;
    int p = m-1;
    while(i <= p)
    {
        int j = 0;
        while(j < n)
        {
            double temp = getValueM(Matr, i, j);
            setValueM(Matr, i, j, getValueM(Matr, p, j));
            setValueM(Matr, p, j, temp);

            j++;
        }

        i++;
        p--;
    }
}






#include <stdio.h>
#include <stdlib.h>

void showMatr(double** M, int m, int n)
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

double** createMatr(int m, int n)
{
    double** M = (double**) malloc(sizeof(double*) * m);

    for(int i = 0; i < m; i++)
    {
        M[i] = (double*) malloc(sizeof(double) * n);
    }

    return M;
}

void deleteMatr(double** M, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        free(M[i]);
    }
    free(M);
}

double getDet(double** M, int m){
    for (int k=1; k<m; k++){
        int p = k-1;
        double zn = M[p][p];
        for (int i=k; i<m; i++){
            double ch = M[i][p];
            for (int j=0; j<m; j++){
                M[i][j] = M[i][j] - M[p][j]*ch/zn;
            }
        }
    }

    double det = 1.0;
    for (int k=0; k<m; k++){
        det *= M[k][k];
    }
}

int main()
{
    int m = 3;
    printf("m = "); scanf("%d", &m);
    int n = m + 1;

    double** M = createMatr(m, n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("M[%d][%d] = ", i, j);
            scanf("%lf", &M[i][j]);
        }
    }
    showMatr(M, m, n);

    for(int k=1; k<m; k++){
        int p = k-1;
        double zn = M[p][p];
        for (int i=k; i<m; i++){
            double ch = M[i][p];
            for (int j=0; j<=m; j++){
                M[i][j] = M[i][j] - M[p][j]*ch/zn;
            }
        }
    }

    showMatr(M, m, n);

    double* X = (double*) malloc(sizeof(double) * m);

    double Mkn, Xk, Xj, Mkj, Mkk;

    for(int i = 0; i < m; i++) X[i] = 0;
    for(int k = m-1; k >= 0; k--)
    {
        X[k] = M[k][n-1];

        for(int j = k+1; j < n-1; j++)
        {
            X[k] = X[k] - X[j] * M[k][j];
        }

        X[k] /= M[k][k];
    }

    for (int i = 0; i < m; i++)
    {
        printf("X%d = %.3lf\n", i, X[i]);
    }

   // printf(" D = %.3lf\n", det);
    deleteMatr(M, m, n);
    return 0;
}


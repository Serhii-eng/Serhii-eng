#include "array_tools.h"
#include <stdlib.h>

int serials_error = 0;

int* createIntArray(int n)
{
    int* A = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        A[i] = 0;
    }
    return A;
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


void fillIntArrayRnd(int* A, int n, int from, int to)
{
    for(int i = 0; i < n; i++)
    {
        A[i] = from + rand() % (to - from);
    }
}


void fillDblArrayRnd(double* A, int n, int from, int to)
{
    for(int i = 0; i < n; i++)
    {
        A[i] = (100*from + rand() % ((to - from)*100)) / 100.0;
    }
}


void showIntArray(int* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    puts("");
}


void showDblArray(double* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%.2lf ", A[i]);
    }
    puts("");
}


bool is_local_min(double* A, int n, int pos)
{
    if(pos == 0) return A[0] < A[1];
    if(pos == n-1) return A[n-1] < A[n-2];
    return A[pos-1] > A[pos] && A[pos] < A[pos+1];
}

bool is_local_max(double* A, int n, int pos)
{
    if(pos == 0) return A[0] > A[1];
    if(pos == n-1) return A[n-1] > A[n-2];
    return A[pos-1] < A[pos] && A[pos] > A[pos+1];
}


void swap_Int_Values(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}


void swap_Dbl_Values(double* x, double* y)
{
    double t = *x;
    *x = *y;
    *y = t;
}


void sort_Int_Array(int* A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                swap_Int_Values(&A[i], &A[j]);
            }
        }
    }
}


void sort_Dbl_Array(double* A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                swap_Dbl_Values(&A[i], &A[j]);
            }
        }
    }
}


void dec_sort_Dbl_Array(double* A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i] < A[j])
            {
                swap_Dbl_Values(&A[i], &A[j]);
            }
        }
    }
}


void copy_Int_Array(int* A, int* B, int n)
{
    for(int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
}


void copy_Dbl_Array(double* A, double* B, int n)
{
    for(int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
}

void transposition_Int_Array(int* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        A[i] = i+1;
    }

    for(int i = 0; i < n; i++)
    {
        int x = rand() % n;
        int y = rand() % n;
        swap_Int_Values(&A[x], &A[y]);
    }
}


void transposition_Dbl_Array(double* A, int n)
{
    for(int i = 0; i < n; i++)
    {
        A[i] = i+1;
    }

    for(int i = 0; i < n; i++)
    {
        int x = rand() % n;
        int y = rand() % n;
        swap_Dbl_Values(&A[x], &A[y]);
    }
}


void min_value_Int_Array(int* A, int n, int* min_1, int* min_pos)
{
    *min_pos = 0;
    *min_1 = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] < *min_1)
        {
            *min_1 = A[i];
            *min_pos = i;
        }
    }
}


void max_value_Int_Array(int* A, int n, int* max_1, int* max_pos)
{
    *max_pos = 0;
    *max_1 = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] > *max_1)
        {
            *max_1 = A[i];
            *max_pos = i;
        }
    }
}


void min_value_Dbl_Array(double* A, int n, double* min_1, int* min_pos)
{
    *min_pos = 0;
    *min_1 = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] < *min_1)
        {
            *min_1 = A[i];
            *min_pos = i;
        }
    }
}


void max_value_Dbl_Array(double* A, int n, double* max_1, int* max_pos)
{
    *max_pos = 0;
    *max_1 = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] > *max_1)
        {
            *max_1 = A[i];
            *max_pos = i;
        }
    }
}


void shift_right_side_Dbl_Array(double* A, int n, int shift_by)
{
    for(int i = 0; i < shift_by; i++)
    {

        for(int j = n-1; j > i; j--)
        {
            A[j] = A[j-1];
        }
        A[i] = 0;

    }
}


void shift_left_side_Dbl_Array(double* A, int n, int shift_by)
{
    for(int i = 0; i < shift_by; i++)
    {

        for(int j = 0; j < n-i; j++)
        {
            A[j] = A[j+1];
        }
        A[n-1] = 0;

    }
}


void cyclic_shift_right_side_Dbl_Array(double* A, int n, int shift_by)
{
    for(int i = 0; i < shift_by; i++)
    {
        double temp = A[n-1];
        for(int j = n-1; j > 0; j--)
        {
            A[j] = A[j-1];
        }
        A[0] = temp;

    }
}


void cyclic_shift_left_side_Dbl_Array(double* A, int n, int shift_by)
{
    for(int i = 0; i < shift_by; i++)
    {
        double temp = A[0];
        for(int j = 0; j < n; j++)
        {
            A[j] = A[j+1];
        }
        A[n-1] = temp;

    }
}


void inc_sort_two_Dbl_Arrays(double* A, double* B, double* C, int n, int m)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n && j < m)
    {
        if(A[i] < B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }

    while(i < n)
    {
        C[k] = A[i];
        i++;
        k++;
    }

     while(j < m)
    {
        C[k] = B[j];
        j++;
        k++;
    }
}


double* merge_two_sorted_Dbl_Arrays(double* A, double* B, int n, int m)
{
    int i = 0;
    int j = 0;
    int k = 0;
    double* C = (double*) malloc((n+m) * sizeof(double));
    while(i < n && j < m)
    {
        if(A[i] > B[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = B[j];
            j++;
            k++;
        }
    }

    while(i < n)
    {
        C[k] = A[i];
        i++;
        k++;
    }

     while(j < m)
    {
        C[k] = B[j];
        j++;
        k++;
    }
    return C;
}


void reverse_Dbl_Array(double* A, int n, int from, int to)
{
    if(from < 0) return;
    if(from >= n) return;
    if(to < 0) return;
    if(to >= n) return;

    int i = from;
    int j = to;
    while(i < j)
    {
       swap_Dbl_Values(&A[i++], &A[j--]);
    }
}


void reverse_Int_Array(int* A, int n, int from, int to)
{
    int i = from;
    int j = to;
    while(i < j)
    {
       swap_Int_Values(&A[i], &A[j]);
       i++;
       j--;
    }
}



int get_min_pos_Dbl_Array(double* A, int n)
{
    int min_pos = 0;
    double min = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] < min)
        {
            min = A[i];
            min_pos = i;
        }
    }
    return min_pos;
}


int get_max_pos_Dbl_Array(double* A, int n)
{
    int max_pos = 0;
    double max = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
            max_pos = i;
        }
    }
    return max_pos;
}

void delete_elem_Dbl_Array(double* A, int* n, int k)
{
    for(int i = k+1; i < *n; i++)
    {
        A[i-1] = A[i];
    }
    *n -= 1;
}


void delete_elem_Int_Array(int* A, int* n, int k)
{
    for(int i = k+1; i < *n; i++)
    {
        A[i-1] = A[i];
    }
    *n -= 1;
}


void remove_from_Int_Array(int** adrA, int* n, int k)
{
    int NN = *n;
    int* B = (int*) malloc(sizeof(int) * (NN-1));

    int j = 0;
    for(int i = 0; i < NN; i++)
    {
        if(i != k) B[j++] = (*adrA)[i];
    }
    free(*adrA);

    *adrA = B;
    //*n = NN-1;
    (*n)--;
}


void remove_from_Dbl_Array(double** adrA, int* n, int k)
{
    int NN = *n;
    double* B = (double*) malloc(sizeof(double) * (NN-1));

    int j = 0;
    for(int i = 0; i < NN; i++)
    {
        if(i != k) B[j++] = (*adrA)[i];
    }
    free(*adrA);

    *adrA = B;
    //*n = NN-1;
    (*n)--;
}


void inserting_elem_Dbl_Array(double* A, int* n, int k)
{
    *n+=1;
    for(int i = *n-1; i > k; i--)
    {
        A[i] = A[i-1];
    }
    A[k] = 0;
}


void inserting_elem_Int_Array(int* A, int* n, int k)
{
    *n+=1;
    for(int i = *n-1; i > k; i--)
    {
        A[i] = A[i-1];
    }
    A[k] = 0;
}


void insert_into_Dbl_Array(double** adrA, int* n, int pos, double value)
{
    (*n)++;
    int NN = *n;
    double* B = (double*) malloc(sizeof(double) * NN);

    int j = 0;
    for(int i = 0; i < NN; i++)
    {
        if(i != pos )
        {
            B[j++] = (*adrA)[i];
        }
        else
        {
            B[j++] = value;
            B[j++] = (*adrA)[i];
        }
    }
    free(*adrA);

    *adrA = B;
}


void insert_into_Int_Array(int** adrA, int* n, int pos, int value)
{
    int N = *n;
    int* A = *adrA;

    int* B = (int*) malloc(sizeof(int) * (N+1));

    for(int i = 0; i < N; i++)
    {
        if(i < pos)
        {
            B[i] = A[i];
        }
        else
        {
            B[i+1] = A[i];
        }
    }
    B[pos] = value;
    *n = N+1;
    free(*adrA);
    *adrA = B;
}


int* insert_into_Int_Array_returned(int* adrA, int* n, int pos, int value)
{
    int N = *n;
    int* B = (int*) malloc(sizeof(int) * (N+1));
    for(int i = 0; i < N; i++)
    {
        if(i < pos)
        {
            B[i] = adrA[i];
        }
        else
        {
            B[i+1] = adrA[i];
        }
    }
    B[pos] = value;
    *n = N+1;
    free(adrA);
    return B;
}



void buble_sort_Dbl_Array(double* A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(A[j] > A[j+1]) swap_Dbl_Values(&A[j], &A[j+1]);
        }
        showDblArray(A, n);
    }
}


void selection_sort_Dbl_Array(double* A, int n)
{
   for(int i = n-1; i > 0; i--)
    {
        int pos_max = get_max_pos_Dbl_Array(A, i+1);
        swap_Dbl_Values(&A[pos_max], &A[i]);
        showDblArray(A, n);
    }
}


void insertion_sort_Dbl_Array(double* A, int n)
{
   for(int i = 1; i < n; i++)
    {
        double temp = A[i];
        int j=i;
        while(j > 0 && A[j-1] > temp)
        {
            A[j] = A[j-1];
            j--;
        }
        A[j] = temp;
        showDblArray(A, n);
    }
}


int* get_lenth_series_Int_Array(int* A, int n, int* b)
{
    //Підрахунок кількості елементів масиву.
    *b = 0;
    if(A[0] != A[1]) *b+=1;
    else if(A[n-2] != A[n-1]) *b+=1;
    for(int i = 1; i < n-1; i++)
    {
        if(A[i] != A[i+1] && i > 0 && i < n-1) *b+=1;
    }
    int* B = (int*) malloc((*b) * sizeof(int));

    //Кількості чисел в серіях
    *b = 0;
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        if(i == 0 && A[0] != A[1])
        {
            B[*b] = cnt;
            *b+=1;
            cnt = 1;
        }
        else if(i == n-1)
        {
            B[*b] = cnt;
            *b+=1;
            cnt = 1;
        }
        else if(A[i] != A[i+1] && i > 0 && i < n-1)
        {
            B[*b] = cnt;
            *b+=1;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }

    return B;
 }


 int* get_value_elem_seria_Int_Array(int* A, int n, int* c)
{
    //Підрахунок кількості різних чисел масиву.
    *c = 0;
    if(A[0] != A[1]) *c+=1;
    else if(A[n-2] != A[n-1]) *c+=1;
    for(int i = 1; i < n-1; i++)
    {
        if(A[i] != A[i+1] && i > 0 && i < n-1) *c+=1;
    }
    int* C = (int*) malloc((*c) * sizeof(int));

    //Значення повторюючих чисел в серіях.
    *c = 0;
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        if(i == 0 && A[0] != A[1])
        {
            C[*c] = A[i];
            *c+=1;
            cnt = 1;
        }
        else if(i == n-1)
        {
            C[*c] = A[i];
            *c+=1;
            cnt = 1;
        }
        else if(A[i] != A[i+1] && i > 0 && i < n-1)
        {
            C[*c] = A[i];
            *c+=1;
            cnt = 1;
        }
    }

    return C;
 }


 int get_number_of_series(int* A, int n)
 {
     int count = 1;
     for(int i = 1; i < n; i++)
     {
         if(A[i-1] != A[i])
         {
             count++;
         }
     }
     return count;
 }


 int get_series_position(int* A, int n, int sn)
 {
     if(sn == 0) return 0;
     int cnt = 0;
     for(int i = 1; i < n; i++)
     {
         if(A[i-1] != A[i])
         {
             cnt++;
             if(cnt == sn) return i;
         }
     }
     return -1;
 }

 int get_series_length(int* A, int n, int sn)
 {
     int pos = get_series_position(A, n, sn);
     if(pos == -1)
     {
         serials_error = 1;
         return 0;
     }
     serials_error = 0;

     int cnt = 0;
     for(int i = pos; i < n; i++)
     {
         if(A[i] == A[pos])
         {
             cnt++;
         }
         else
         {
             break;
         }
     }
     return cnt;
 }


 int get_series_value(int* A, int n, int sn)
 {
     int pos = get_series_position(A, n, sn);
     if(pos == -1)
     {
         serials_error = 1;
         return 0;
     }
     serials_error = 0;
     return A[pos];
}


void swap_Series(int** adrA, int n, int from, int to)
{
    int* A = *adrA;
    int N = get_number_of_series(A, n);

    if(from < 0 || from > N || to < 0 || to > N)
    {
        serials_error = 1;
        return 0;
    }
    serials_error = 0;

    int* B = (int*) malloc(sizeof(int) * n);
    int b = 0;

    for(int i = 0; i < N; i++)
    {
        int pos;
        int length;

        if(i != from && i != to)
        {
            pos = get_series_position(A, n, i);
            length = get_series_length(A, n, i);
            for(int i = pos; i < pos+length; i++)
            {
                B[b++] = A[i];
            }
        }
        if(i == from)
        {
            pos = get_series_position(A, n, to);
            length = get_series_length(A, n, to);
            for(int i = pos; i < pos+length; i++)
            {
                B[b++] = A[i];
            }
        }
        if(i == to)
        {
            pos = get_series_position(A, n, from);
            length = get_series_length(A, n, from);
            for(int i = pos; i < pos+length; i++)
            {
                B[b++] = A[i];
            }
        }
    }

    free(*adrA);
    *adrA = B;
}


void swap_Series_a(int** adrA, int n, int s1, int s2)
{
    int* A = *adrA;
    int N = get_number_of_series(A, n);

    if(s1 < 0 || s1 > N || s2 < 0 || s2 > N)
    {
        serials_error = 1;
        return 0;
    }
    serials_error = 0;

    int* B = (int*) malloc(sizeof(int) * n);
    int b = 0;

    for(int i = 0; i < N; i++)
    {
        int k = i;
        if(i == s1) k = s2;
        if(i == s2) k = s1;

        int value = get_series_value(A, n, k);
        int length = get_series_length(A, n, k);
        for(int j = 0; j < length; j++)
        {
            B[b++] = value;
        }
    }

    free(*adrA);
    *adrA = B;
}


void replace_Series_array(int** adrA, int* n, int k)
{
    int NN = *n;
    int* A = *adrA;
    int N = get_number_of_series(A, NN);
    if(k >= N || k < 0)
    {
        serials_error = 1;
        return 0;
    }
    serials_error = 0;

    int length = get_series_length(A, NN, k);
    int* B = (int*) malloc(sizeof(int) * (NN-length+1));
    int b = 0;

    for(int i = 0; i < N; i++)
    {
        if(i != k)
        {
            int pos = get_series_position(A, NN, i);
            int length = get_series_length(A, NN, i);
            for(int i = pos; i < pos+length; i++)
            {
                B[b++] = A[i];
            }
        }
        if(i == k)
        {
            B[b++] = 0;
        }
    }

    *n = NN-length+1;
    free(*adrA);
    *adrA = B;
}


Point createDblPoint(double x, double y)
{
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

Point* createDblArrayOfPoints(int n)
{
    Point* A = (Point*) malloc(sizeof(Point) * n);

    for(int i = 0; i < n; i++)
    {
        A[i].x = 0;
        A[i].y = 0;
    }

    return A;
}


Point_int* createIntArrayOfPoints(int n)
{
    Point_int* A = (Point_int*) malloc(sizeof(Point_int) * n);

    for(int i = 0; i < n; i++)
    {
        A[i].x = 0;
        A[i].y = 0;
    }

    return A;
}


void fillDblArrayOfRandomPoints(Point* points, int from, int to, int n)
{
    for(int i = 0; i < n; i++)
    {
        points[i] = createPointRnd(from, to);
        //poins[i].x = (100*from + rand() % ((to - from)*100)) / 100.0; //Як присвоїти через адресу, чи є така форма points[i]->x =
        //poins[i].y = (100*from + rand() % ((to - from)*100)) / 100.0;
    }
}


void fillIntArrayOfRandomPoints(Point_int* points, int from, int to, int n)
{
    for(int i = 0; i < n; i++)
    {
        points[i] = createIntPointRnd(from, to);
        //poins[i].x = (100*from + rand() % ((to - from)*100)) / 100.0; //Як присвоїти через адресу, чи є така форма points[i]->x =
        //poins[i].y = (100*from + rand() % ((to - from)*100)) / 100.0;
    }
}


void enterDblArrayOfRandomPoints(Point* poins, double x, double y)
{
        poins->x = x;
        poins->y = y;
}


void showDblPoint(const Point *point)
{
    printf("(%.2lf, %.2lf) ", point->x, point->y);
}


void showIntArrayPoint(const Point_int *point)
{
    printf("(%d, %d) ", point->x, point->y);
}


void showDblArrayOfPoints(const Point *point, int n)
{
    for(int i = 0; i < n; i++)
    {
        showDblPoint(&point[i]);
        puts("");
    }
    puts("---------------");
}


void showIntArrayOfPoints(const Point_int *point, int n)
{
    for(int i = 0; i < n; i++)
    {
        showIntArrayPoint(&point[i]);
        puts("");
    }
    puts("---------------");
}


double get_length_between_points(const Point* A, const Point* B)
{
    double dx = A->x - B->x;
    double dy = A->y - B->y;

    return sqrt(dx*dx + dy*dy);
}

int get_Quarter(Point p)
{
    if(p.x > 0 && p.y > 0) return 1;
    if(p.x < 0 && p.y > 0) return 2;
    if(p.x < 0 && p.y < 0) return 3;
    if(p.x > 0 && p.y < 0) return 4;
    return 0;
}


double get_Perimetr_of_Triagle(const Point* point_1, const Point* point_2, const Point* point_3)
{

    double AB = get_length_between_points(point_1, point_2);
    double BC = get_length_between_points(point_2, point_3);
    double AC = get_length_between_points(point_1, point_3);

    return AB + BC + AC;
}


Point createPointRnd(int from, int to)
{
    Point point;
    point.x = (100*from + rand() % ((to - from)*100)) / 100.0;
    point.y = (100*from + rand() % ((to - from)*100)) / 100.0;
    return point;
}


Point_int createIntPointRnd(int from, int to)
{
    Point_int point;
    point.x = from + rand() % (to - from);
    point.y = from + rand() % (to - from);
    return point;
}


int compareX(const Point_int* XY1, const Point_int* XY2)
{
    //const Point_int *x = X1;
    //const Point_int *xx = X2;

    return XY1->x - XY2->x;
}


int compareXplusY(const Point_int* XY1, const Point_int* XY2)
{
    return (XY1->x + XY1->y) - (XY2->x + XY2->y);
}


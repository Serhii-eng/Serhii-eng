#ifndef ARRAY_TOOLS_H_INCLUDED
#define ARRAY_TOOLS_H_INCLUDED

#include <stdbool.h>

typedef struct
{
    double x;
    double y;
} Point;

typedef struct
{
    int x;
    int y;
} Point_int;

extern int serials_error;

int* createIntArray(int n);
double* createDblArray(int n);
void fillIntArrayRnd(int* A, int n, int from, int to);
void fillDblArrayRnd(double* A, int n, int from, int to);
void showIntArray(int* A, int n);
void showDblArray(double* A, int n);
bool is_local_min(double* A, int n, int pos);
bool is_local_max(double* A, int n, int pos);
void swap_Int_Values(int* x, int* y);
void swap_Dbl_Values(double* x, double* y);
void sort_Int_Array(int* A, int n);
void sort_Dbl_Array(double* A, int n);
void copy_Int_Array(int* A, int* B, int n);
void copy_Dbl_Array(double* A, double* B, int n);
void transposition_Int_Array(int* A, int n);
void transposition_Dbl_Array(double* A, int n);
void min_value_Int_Array(int* A, int n, int* min_1, int* min_pos);
void max_value_Int_Array(int* A, int n, int* max_1, int* max_pos);
void min_value_Dbl_Array(double* A, int n, double* min_1, int* min_pos);
void max_value_Dbl_Array(double* A, int n, double* max_1, int* max_pos);
void shift_right_side_Dbl_Array(double* A, int n, int shift_by);
void shift_left_side_Dbl_Array(double* A, int n, int shift_by);
void cyclic_shift_right_side_Dbl_Array(double* A, int n, int shift_by);
void cyclic_shift_left_side_Dbl_Array(double* A, int n, int shift_by);
void inc_sort_two_Dbl_Arrays(double* A, double* B, double* C, int n, int m);
double* merge_two_sorted_Dbl_Arrays(double* A, double* B, int n, int m);
void reverse_Dbl_Array(double* A, int n, int from, int to);
int get_min_pos_Dbl_Array(double* A, int n);
int get_max_pos_Dbl_Array(double* A, int n);
void delete_elem_Dbl_Array(double* A, int* n, int k);
void delete_elem_Int_Array(int* A, int* n, int k);
void remove_from_Int_Array(int** adrA, int* n, int k);
void remove_from_Dbl_Array(double** adrA, int* n, int k);
void inserting_elem_Dbl_Array(double* A, int* n, int k);
void inserting_elem_Int_Array(int* A, int* n, int k);
void insert_into_Dbl_Array(double** A, int* n, int pos, double value);
void insert_into_Int_Array(int** adrA, int* n, int pos, int value);
int* insert_into_Int_Array_returned(int* adrA, int* n, int pos, int value);
void buble_sort_Dbl_Array(double* A, int n);
void selection_sort_Dbl_Array(double* A, int n);
void insertion_sort_Dbl_Array(double* A, int n);
int* get_lenth_series_Int_Array(int* A, int n, int* b);
int* get_value_elem_seria_Int_Array(int* A, int n, int* b);
int get_number_of_series(int* A, int n);
int get_series_position(int* A, int n, int sn);
int get_series_length(int* A, int n, int sn);
int get_series_value(int* A, int n, int sn);
void swap_Series(int** adrA, int n, int from, int to);
Point createDblPoint(double x, double y);
Point* createDblArrayOfPoints(int n);
void fillDblArrayOfRandomPoints(Point* points, int from, int to, int n);
void enterDblArrayOfRandomPoints(Point* poins, double x, double y);
void showDblPoint(const Point *point);
void showDblArrayOfPoints(const Point *point, int n);
double get_length_between_points(const Point* point, const Point* points);
bool identify_Occurrences_In_A_Quarter(const Point* point, int quarter);
double get_Perimetr_of_Triagle(const Point* point_1, const Point* point_2, const Point* point_3);
Point createPointRnd(int from, int to);
int get_Quarter(Point p);
Point_int createIntPointRnd(int from, int to);
void fillIntArrayOfRandomPoints(Point_int* points, int from, int to, int n);
Point_int* createIntArrayOfPoints(int n);
void showIntArrayPoint(const Point_int *point);
void showIntArrayOfPoints(const Point_int *point, int n);
typedef int (*TFuncXY)(const Point_int*, const Point_int*);
int compareX(const Point_int* X1, const Point_int* X2);
int compareXplusY(const Point_int* XY1, const Point_int* XY2);



#endif // ARRAY_TOOLS_H_INCLUDED

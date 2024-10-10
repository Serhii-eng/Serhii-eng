#include "intset.h"

void SortIntArray(int* A, int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (A[i]>A[j]){
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
}

int SearchInIntArray(int* A, int n, int value){
    for(int i=0; i < n; i++){
        if (A[i]==value) return i;
    }
    return -1;
}

IntSet createIntSet(int capacity){
    IntSet set;
    set.capacity = capacity;
    set.n = 0;
    set.A = (int*) malloc(sizeof(int)*capacity);
    return set;
}

void deleteIntSet(IntSet *set){
    free(set->A);
}

bool isIntSetEmpty(IntSet *set){
    if (set->n == 0) return true;
    return false;
}

bool isValueInIntSet(IntSet *set, int value){
    if (SearchInIntArray(set->A, set->n, value)==-1) return false;
    return true;
}

void insertToIntSet(IntSet *set, int value){
    if (isValueInIntSet(set, value))return;

    if (set->n < set->capacity){
        set->A[set->n] = value;
        set->n++;
        SortIntArray(set->A, set->n);
    }
}

void removeFromIntSet(IntSet *set, int value){
    int pos = SearchInIntArray(set->A, set->n, value);
    if (pos != -1){
        for (int i=pos; i<set->n-1; i++){
            set->A[i] = set->A[i+1];
        }
        set->n--;
    }
}

void showIntSet(IntSet *set){
    for(int i=0; i < set->n; i++){
        printf("%d ", set->A[i]);
    }
    puts("");
}

bool isIntSetsEquale(IntSet *s1, IntSet *s2){
    if (s1->n != s2->n) return false;
    for(int i=0; i < s1->n; i++){
        if (s1->A[i] != s2->A[i]) return false;
    }
    return true;
}


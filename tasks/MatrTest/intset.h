#ifndef INTSET_H
#define INTSET_H

#define bool int;
#define true 1;
#define false 0;

typedef struct {
    int *A;
    int n;
    int capacity;
} IntSet;

IntSet createIntSet(int capacity);
void deleteIntSet(IntSet *set);
bool isIntSetEmpty(IntSet *set);
bool isValueInIntSet(IntSet *set, int value);
void insertToIntSet(IntSet *set, int value);
void removeFromIntSet(IntSet *set, int value);
bool isIntSetsEquale(IntSet *s1, IntSet *s2);
void showIntSet(IntSet *set);


#endif // INTSET_H

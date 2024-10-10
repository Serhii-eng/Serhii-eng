#include "charstack.h"
#include <stdio.h>
#include <stdlib.h>

CharStack createCharStack(int capacity)
{
    CharStack stack;
    stack.stack_pointer = 0;
    stack.N = capacity;
    stack.s = (char*) malloc(sizeof(char) * capacity);
    return stack;
}


int pushToCharStack(CharStack *st, char c)
{
    if(st->stack_pointer >= st-> N) return 1;
    st->s[st->stack_pointer] = c;
    st->stack_pointer++;
    return 0;
}


char popFromCharStack(CharStack *st)
{
    if(st->stack_pointer == 0) return '\0';
    st->stack_pointer--;
    return st->s[st->stack_pointer];
}


char pickFromCharStack(CharStack *st)
{
    if(st->stack_pointer == 0) return '\0';
    return st->s[st->stack_pointer-1];
}


int sizeOfCharStack(CharStack *st)
{
    return st->stack_pointer;
}


void deleteCharStack(CharStack *st)
{
    free(st->s);
}


void showCharStack(CharStack *st)
{
    system("cls");
    puts("--stack--");

    for(int i = st->stack_pointer-1; i >= 0; i--)
    {
        printf("%d -> %c\n", i, st->s[i]);
    }
}




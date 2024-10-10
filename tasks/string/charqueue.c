#include "charqueue.h"
#include <stdio.h>
#include <stdlib.h>

CharQueue createCharQueue(int capacity)
{
    CharQueue queue;
    queue.queue_pointer = 0;
    queue.N = capacity;
    queue.s = (char*) malloc(sizeof(char) * capacity);
    return queue;
}


int enqueueToCharQueue(CharQueue *st, char c)
{
    if(st->queue_pointer >= st->N) return 1;
    st->s[st->queue_pointer] = c;
    st->queue_pointer++;
    return 0;
}


char dequeueFromCharQueue(CharQueue *st)
{
    if(st->queue_pointer == 0) return '\0';
    char c = st->s[0];
    for(int i = 1; i < st->queue_pointer; i++)
    {
        st->s[i-1] = st->s[i];
    }
    st->queue_pointer--;
    return c;
}


char pickFromCharQueue(CharQueue *st)
{
    if(st->queue_pointer == 0) return '\0';
    return st->s[0];
}


int sizeOfCharQueue(CharQueue *st)
{
    return st->queue_pointer;
}


void deleteCharQueue(CharQueue *st)
{
    free(st->s);
}


void showCharQueue(CharQueue *st)
{
    //system("cls");
    puts("--queue--");

    for(int i = 0; i < st->queue_pointer; i++)
    {
        printf("%d -> %c\n", i, st->s[i]);
    }
}

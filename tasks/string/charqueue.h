#ifndef CHARQUEUE_H
#define CHARQUEUE_H


typedef struct
{
    char* s;
    int N;
    int queue_pointer;
}CharQueue;

CharQueue createCharQueue(int capacity);
int enqueueToCharQueue(CharQueue *st, char c);
char dequeueFromCharQueue(CharQueue *st);
char pickFromCharQueue(CharQueue *st);
int sizeOfCharQueue(CharQueue *st);
void deleteCharQueue(CharQueue *st);
void showCharQueue(CharQueue *st);

#endif // CHARQUEUE_H

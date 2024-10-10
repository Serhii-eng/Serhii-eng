#ifndef CHARSTACK_
#define CHARSTACK_


typedef struct
{
   char *s;
   int N;
   int stack_pointer;
}CharStack;

CharStack createCharStack(int capacity);
int pushToCharStack(CharStack *st, char c);
char popFromCharStack(CharStack *st);
char pickFromCharStack(CharStack *st);
int sizeOfCharStack(CharStack *st);
void deleteCharStack(CharStack *st);
void showCharStack(CharStack *st);

#endif // CHARSTACK_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void rundom_numbers(int a[], int N);
void bubble_sort(int a[], int b[], int N);
void number_of_digits(int b[], int c[], int N);
void insertion_sort(int a[], int N);


int main(void)
{

    const int N = 50;
    int a[N], b[N];
    int *c = (int*)malloc(N * sizeof(int));
    if (c == NULL) { printf("Memory not allocated\n"); exit(1); }



    rundom_numbers(a, N);

    printf("\n\n");

    //Сортування бульбашкою
    bubble_sort(a, b, N);        //Виклик функції сортування

    printf("\n\n");

    number_of_digits(b, c, N);  // Кількість цифр

    //Сортування вибором
    selection_sort(a, N);

    insertion_sort(a, N);

    free(c);

}

void rundom_numbers(int a[], int N)
{
    srand(time(0));
    int t = rand() % 200;
    printf("\n[%d]\n\n",t);
    //Цифру можна підставляти одну ту саму для пошуку помилки.
    srand(t);

    for (int i = 0; i < N; i++)
    {
        a[i] = (rand() % 25 + 1);
        printf("%d ",a[i]);
    }
}

void bubble_sort(int a[], int b[], int N) //сортування бульбашкою.
{
    for(int i = 0; i < N; i++)
    {
        b[i] = a[i]; //Копіювання з масиву "a" в "b"
    }

    int buf;
    int bool = 1;
    while(bool == 1)
    {
        bool = 0;
        for (int i = 0; i < N; i++)
        {
            if(b[i] > b[i + 1])
            {
                buf = b[i];
                b[i] = b[i + 1];
                b[i + 1] = buf;
                bool = 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", b[i]);
    }
}




void number_of_digits(int b[], int c[], int N)
{

    int step = 0;
    int counter = 0;
    int buf_counter = 1;
    for(int i = 0; i < N; i++)
    {
        if(b[i] == b[i+1])
        {
            c[step] = buf_counter;
            c[step + 1] = b[i];
            buf_counter++;
        }
        else
        {
            c[step] = buf_counter;
            c[step + 1] = b[i];
            step += 2;
            buf_counter = 1;
            counter++;
        }
    }


    int *d = (int*)realloc(c, counter * 2 * sizeof(int));
    if (d == NULL) { printf("Memory not allocated\n"); exit(1); }

    printf("\n\n");

    for (int i = 0; i < counter * 2; i += 2)
    {
        printf("%d %d\n", d[i], d[i + 1]);
    }

    printf("\n\n");

    printf(" %d", counter);

    free(d);
}


void selection_sort(int a[], int N)      //Сортування вибором
{

    int *e = (int*)malloc(N * sizeof(int));
    if (e == NULL) { printf("Memory not allocated\n"); exit(1); }

     for(int i = 0; i < N; i++)
    {
        e[i] = a[i]; //Копіювання з масиву "a" в "e"
    }

    int min, temp;

    for(int i = 0; i < N; i++)
    {
        min = i;

        for(int j = N - 1; j > i; j--)
        {


            if(e[j] < e[min])
            {
                min = j;
            }
        }
        temp = e[i];
        e[i] = e[min];
        e[min] = temp;
    }

    printf("\n\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d ", e[i]);
    }

    printf("\n\n");

    free(e);




   // сортування вибором, спосіб не працює!

/*

     for(int i = 0; i < N; i++)
    {
        e[i] = a[i]; //Копіювання з масиву "a" в "e"
    }

    int min;

    for(int i = 0; i < N; i++)
    {
        int position_j = 0;
        int min = e[i];

        for(int j = N - 1; j > i; j--)
        {


            if(e[j] <= min)
            {
                min = a[j];
                position_j = j;
            }
        }
        e[position_j] = e[i];
        e[i] = min;
        position_j = 0;
        min = 0;
    }

    printf("\n\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d ", e[i]);
    }

    printf("\n\n");

*/






/*
  int c[N];
  int step = 0;
  int counter = 0;
  int buf_counter = 1;
  for(int i = 0; i < N; i++)
    {

      if(b[i] == b[i+1])
        {
          c[step] = buf_counter;
          c[step + 1] = b[i];
          buf_counter++;
        }
      else
        {
          c[step] = buf_counter;
          c[step + 1] = b[i];
          step += 2;
          buf_counter = 1;
          counter++;
        }
    }

   int d[counter];
   for(int i = 0; i < counter*2; i++)
    d[i] = c[i];

  printf("\n\n");

  for (int i = 0; i < counter*2; i += 2)
        {
          printf("%d %d\n", d[i], d[i + 1]);
        }

  printf("\n\n");

  printf(" %d", counter);
  */
}

void insertion_sort(int a[], int N)      //Сортування вcтавками
{
   int *f = (int*)malloc(N * sizeof(int));
   if (f == NULL) { printf("Memory not allocated\n"); exit(1); }


   for(int i = 0; i < N; i++)
   {
       f[i] = a[i];
   }



   for(int i = 1; i < N; i++)
   {
           int temp, j, buf_j, buf_j_1;
           j = i;
           while(f[j - 1] >= f[j] && j != 0)
           {
               temp = f[j - 1]; f[j - 1] = f[j]; f[j] = temp;

               buf_j = f[j];
               buf_j_1 = f[j-1];
               j--;
           }
   }


    printf("\n\n");

    for (int i = 0; i < N; i++)
    {
        printf("%d ", f[i]);
    }

    printf("\n\n");

    free(f);
}


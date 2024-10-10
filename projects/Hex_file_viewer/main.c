#include <stdio.h>
#include <stdlib.h>

const int N = 16;//шіснадцятковий формат.

void HexFileViewer(const char* filename, int add_from, int add_to){ //Діапазон адреси повинен вводитись в 16-м форматі.

    /*-------------------------------------------------------------------*/

    if(add_from > add_to)
    {
        int tmp = add_from;
        add_from = add_to;
        add_to = tmp;
    }

    int from_round = (add_from < N) ? 0 : add_from - (add_from % N);
    int to_round = add_to;
    if(add_to > 0){
        while(to_round % N != 0){
            to_round++;
        }
    }
    else{
        to_round = 0;
    }

    /*-------------------------------------------------------------------*/

    FILE *f = fopen(filename, "rb");

    fseek(f, from_round*sizeof(char), SEEK_SET);

    int n;
    char buf[N];
    //printf("%p\n", buf);
    int addr = from_round;
    while (n = fread(buf, sizeof(char), N, f)){

        if(addr >= to_round && to_round != 0) break;

        printf("%08X:", addr);

        for (int i=0; i<N; i++){
            if (i == N/2) printf("|");

            if (i<n){
                if(i == N/2){ //Потрібно для правильного позиціонування шіснатцяткового байту саме на 9-й позиції в рядку.
                    printf("%02X", buf[i]);
                }
                else{ //Потрібно для правильного позиціонування шіснатцяткового байту окрія 9-й позиції в рядку.
                    printf(" %02X", buf[i]);
                }
            }
            else {
                printf("   ");
            }
        }

        if(n < 16){ //Потрібно для правильного позиціювання '|' в кінці файлу і перед ASCII.
            printf("| ");

        }
        else{ //Потрібно для правильного позиціювання '|' в середині файлу і перед ASCII.
            printf(" | ");
        }

        for (int i=0; i<n; i++){
            char c = buf[i];
            if ( (0 <= c && c < 32) || c==127) {
                c = '.';
            }
            printf("%c", c);
        }

        puts("");
        addr += 16;
    }
}

int main()
{
    char filename[500] = "D:\\Lenguage C\\Lesson 13\\file.txt";
    //char filename[500] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    //printf("filename: "); gets(filename); //задати шлях та ім'я файлу який хочемо прочитати.

    //Діапазон адреси повинен вводитись в 16-м форматі.
    int add_from, add_to; //якщо ввести нулі, то файл прочитається ціляком.
    printf("add from = "); scanf("%x", &add_from); //почати читати від адреси
    printf("add to = "); scanf("%x", &add_to); //читати до адреси.

    HexFileViewer(filename, add_from, add_to);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

const int N = 16;//�������������� ������.

void HexFileViewer(const char* filename, int add_from, int add_to){ //ĳ������ ������ ������� ��������� � 16-� ������.

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
                if(i == N/2){ //������� ��� ����������� �������������� ��������������� ����� ���� �� 9-� ������� � �����.
                    printf("%02X", buf[i]);
                }
                else{ //������� ��� ����������� �������������� ��������������� ����� ���� 9-� ������� � �����.
                    printf(" %02X", buf[i]);
                }
            }
            else {
                printf("   ");
            }
        }

        if(n < 16){ //������� ��� ����������� ������������ '|' � ���� ����� � ����� ASCII.
            printf("| ");

        }
        else{ //������� ��� ����������� ������������ '|' � ������� ����� � ����� ASCII.
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
    //printf("filename: "); gets(filename); //������ ���� �� ��'� ����� ���� ������ ���������.

    //ĳ������ ������ ������� ��������� � 16-� ������.
    int add_from, add_to; //���� ������ ���, �� ���� ����������� �������.
    printf("add from = "); scanf("%x", &add_from); //������ ������ �� ������
    printf("add to = "); scanf("%x", &add_to); //������ �� ������.

    HexFileViewer(filename, add_from, add_to);

    return 0;
}

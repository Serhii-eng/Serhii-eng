#include "string_plus.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>


//��������� ������ �� ��������� ������ ������.
//2-� �����.


int main()
{
    char str[]="        mnbvm        segr     fkjeho    ";

    normalize(str);

    puts(str);

    character_insertion(str);

    puts(str);

    return 0;
}

//�������� �������, ��� �� ���� �����, ����� �������� ������ � ������� �������.





























//��������� ������ �� ��������� ���� ������.
//2-� �����.
/*
int main()
{

    char str[]=" mnbvm       segr     fkjeho";
    char str_wiut_spc[256] = {0};
    unsigned char step = 0;

    //fgets(str, 256, stdin);

    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == 32 && str[i + 1] != 32)
        {
            str_wiut_spc[step] = 32;
            step++;
        }
        if(str[i] != 32)
        {
            str_wiut_spc[step] = str[i];
            step++;
        }

    }

    for(int i = 0; i < strlen(str); i++)
    {
         printf("%c",  str_wiut_spc[i]);
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_DAYS_WEEK     7 //ѳ� ��� �����
#define NUM_OF_MONTHS    12 //���������� ������ � ����

//������ �� ������ ������� ������ �����, ���������� ����� �����, �� ����� ��� �����.
#define M_HIGH            8
#define M_WIDTH          21

//������ �������� �������
#define G_M_WIDTH       145
#define G_M_HIGH        145

//��� ��������� �� ������ ���� ����� �� �������� 3.
#define START_POS_MON_H   4 //������� �� ����� ����� �������������� ������������� �����.
#define START_POS_MON_W   3 //������� �� ����� ����� �������������� ������������� �����.


bool is_leap_year(int y)
{
    bool f = false; //�� ���������� �� 365

    if(y % 4 == 0)
    {
        f = true; //���������� �� 366
        if(y % 100 == 0 && y % 400 != 0)
        {
            f = false; //�� ����������� ��� 365
        }
    }
    return f;
}


int get_month_days(int m, int y)
{
    switch(m)
    {
        case 1: return 31;
        case 2: return is_leap_year(y) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}


int getStartDayWeekOfMonth(int month, int year) //������ ���� ����� ������� �������� ����.
{
    //������������� �������� ���������� � 15.10.1582, ���� ����� ���� �'������.
    //�� ����� ������ �� 0 ... 6, (�������� ... �����).
    //�'������ ������ �������� 4-� ���� �����.

    int D, W, M, Y;
    Y = 1582;
    M = 10;
    D = 15;
    W = 4;

    while(true)
    {
        if(D < get_month_days(M, Y))
        {
            D++;
        }
        else
        {
            D = 1;
            M++;
            if(M == 13)
            {
                M = 1;
                Y++;
            }
        }

        if(W < NUM_DAYS_WEEK-1) W++;
        else W = 0;

        if(Y >= year) //�������� �� �� �������� �������� ��������
        {
            if(M >= month) //�������� �� ����� �������� ��������� ��������
            {
                break;
            }
        }
    }

    return W;
}


void cleanMatr(char M[M_HIGH][M_WIDTH]) //���������� ������� ��������.
{
    for(int i = 0; i < M_HIGH; i++)
    {
        for(int j = 0; j < M_WIDTH; j++)
        {
            M[i][j] = ' ';
        }
    }
}


void cleanGeneralMatr(char G_M[G_M_HIGH][G_M_WIDTH]) //���������� ������� ��������.
{
    for(int i = 0; i < G_M_HIGH; i++)
    {
        for(int j = 0; j < G_M_WIDTH; j++)
        {
            G_M[i][j] = ' ';
        }
    }
}


void putZeroToFirstPosString(char M[M_HIGH][M_WIDTH])
{
    for(int i = 0; i < M_HIGH; i++)
    {
        M[i][0] = '\0';
    }
}


void RemoveAllZero(char M[M_HIGH][M_WIDTH])
{
    for(int i = 0; i < M_HIGH; i++)
    {
        int len = strlen(M[i]);
        M[i][len] = ' ';
    }
}


/*---------------------------------------------------------------------*/
//���� ������� ����� � ���� ���� ������������� ������� ������ ����� ���������� ����� �����, �� ���� �� �����.
//����� ���� ������� ��, �� ����� - ���� �� ������ ��������� �������.
//��������� ������� ����� ���������� � ����.
void createNewMonth(char M[M_HIGH][M_WIDTH], int year, int month)
{
    //� ����� ��� ����� ���������� �����.
    int start_day_week_month = getStartDayWeekOfMonth(month+1, year);
    //printf("start day = %d %d\n", start_day_week_month, month+1);

    //������ ��� �� � ��� �����.
    int month_have_days = get_month_days(month+1, year);
    //printf("month have days = %d %d\n", month_have_days, month+1);

    cleanMatr(M);
    putZeroToFirstPosString(M);

    char* month_n[] = { "January","February", "March","April", "May","June",
            "July", "August","September","October", "November","December"};



    int len_tx_month = strlen(month_n[month]);
    sprintf(M[0], "%*s", (M_WIDTH - len_tx_month-1)/2 + len_tx_month, month_n[month]);/*������� ����� �������� \n*/


    //sprintf(M[0], "%*s", 20, month_n[month]);/*������� ����� �������� \n*/

    char* days_w = {"Mo Tu We Th Fr Sa Su"};
    sprintf(M[1], "%s", days_w);/*������� ����� �������� \n*/


    char buf[10] = {0}; //����� ��� ���������� ������� ����� �� ���������.
    for(int i = 0; i < start_day_week_month; i++) //���������� ���� ������� � ������� ����� ����� ��� ���� ��� ������ ����������� ����� ����� ����� � ��������� ��� �����
    {
        sprintf(buf, "   ");
        strcat(M[2], buf);
    }

    int number = 1; //����� �����
    for(int i = 2; i < M_HIGH; i++) //� ���� ������ �������� ���� ������������ ����� ����� �� ����� ��� �����
    {
        int j;
        if(i == 2) j = start_day_week_month; //����������� ���������� ������� ����� � ����������� ����.

        for(j; j < NUM_DAYS_WEEK; j++)
        {

            ////////////////���� ��� ���������� �����
            if(j < NUM_DAYS_WEEK-1) sprintf(buf, "%2d ", number);  //��������� ���������� ������� �����, �� ���� ��������.
            else sprintf(buf, "%2d", number); //���������� �������� ������� � ����� ��� ������.
            ////////////////

            strcat(M[i], buf);//������� ��������� � �����, ����� ��� ���������� ����������.

            number++;

            if(number > month_have_days)  //���� ����� ���� �� ����, �� ��������, � ��� ��� �� ��� � ���� ���������� �����.
            {
                i = M_HIGH;
                break;
            }
        }

        j = 0;
    }

    RemoveAllZero(M); //�������� �� ��� ���������  ���� ������� ����� �������.
}
/*---------------------------------------------------------------------*/


void test_fun_show_month(char M[M_HIGH][M_WIDTH])
{
    for(int i = 0; i < M_HIGH; i++)
    {
        for(int j = 0; j < M_WIDTH; j++)
        {
            printf("%c", M[i][j]);
        }
        printf("\n");
    }
}


void testFunShowGeneralMatr(char G_M[G_M_HIGH][G_M_WIDTH], int size_h)//�������� ²���������
{
    for(int i = 0; i < size_h; i++)
        printf("%s", G_M[i]);
}


//(�������) ��� ������ ������� ������ ����� � �������� �������, �� ������� ��������.
void putMonthMatrToGeneralMatr(char dst[G_M_HIGH][G_M_WIDTH], char src[M_HIGH][M_WIDTH], int pos_h, int pos_w)
{
    for(int i = 0; i < M_HIGH; i++)
    {
        for(int j = 0; j < M_WIDTH; j++)
        {
            dst[pos_h + i][pos_w + j] = src[i][j];
        }
    }
}


//(�������) ���������� ����� ������ �� �������� ��������� - (��-��� ������ �� �����., ���� ������� �� ������ ����.).
void setFrameToCalendar(char src[G_M_HIGH][G_M_WIDTH], int num_goriz_print, int size_h, int size_w, int start_pos_h, int start_pos_w)
{
    //��������� ���������� �� ������� �������.
    start_pos_h -= 1;
    start_pos_w -= 2;

    //�������� ����� �� �������� �� ���������� �� ������ ������ �����.
    const int vert_grad = 9;
    const int goriz_grad = 23;

    //���������� �������������� ��� �����

    //������������ '+' �� ����� �������.
    src[start_pos_h][start_pos_w] = '+'; //'+' � ����� ��������� ���.
    src[start_pos_h][size_w] = '+';      //'+' � ������� ��������� ���.
    src[size_h-1][start_pos_w] = '+';      //'+' � ����� �������� ���.
    src[size_h-1][size_w] = '+';           //'+' � ������� �������� ���.

    for(int i = start_pos_h; i < size_h; i+=vert_grad)
    {
        int dis_str_pos_w = start_pos_w+1; //������� �� ����������, ��� ������������ '+'��.

        for(int k = 0; k < num_goriz_print; k++)//��-��� ������ �� �����.
        {
            for(int j = 0; j < goriz_grad; j++)//��� �� ��� ��� ����� � ������.
            {
                if( (i == start_pos_h || i == size_h-1) && (k != num_goriz_print-1 || j != goriz_grad-1))//������� ���� ������ �� ����� ����� �������, �� �������� '+'
                    src[i][j + dis_str_pos_w] = '-';
                else if(j != goriz_grad-1 && i != start_pos_h && i != size_h-1) //�����. �� � ������� ����.
                    src[i][j + dis_str_pos_w] = '-';
                else if(k != num_goriz_print-1 || j != goriz_grad-1) //����� � ������� �����.
                    src[i][j + dis_str_pos_w] = '+';
            }
            dis_str_pos_w += goriz_grad;

        }
    }

    //������������ ������������ ��� �������
     for(int i = start_pos_h+1; i < size_h-1; i++)
    {
        int dis_str_pos_w = start_pos_w; //������� �� ����������, ��� ������������ '|'.

        for(int k = 0; k <= num_goriz_print; k++)//��-��� ������ �� �����.
        {
            if((i-start_pos_h) % vert_grad != 0)//������������ ����. ��� � ������� ����.
                src[i][dis_str_pos_w] = '|';
            else if(k == 0 || k == num_goriz_print)//������������ ����. ��� ����� ����.
                src[i][dis_str_pos_w] = '|';

            dis_str_pos_w += goriz_grad;//������ ���� �� ����� ������ ����� �� �����.
        }
    }
}

//������� ��� ������ ��������� � ��������� ����.
void writeCalendarToFile(char src[G_M_HIGH][G_M_WIDTH], int size_h, char* arg_dir_file, int year)
{
    //������ ��-��� ��� � ����� �� ����� � ��������� exe.
    char t[100];
    strcpy(t, arg_dir_file);
    int N = 0;
    char* w = strtok(t, ":\\.");
    while(w)
    {
        w = strtok(NULL, ":\\.");
        N++;
    }

    //��������� ���� �� ����� � ���������, �� �������� �����.
    char st[100];
    strcpy(st, arg_dir_file);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, ":\\.");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, ":\\.");
    }

    //���������� ����� ��� ������ ����� � ����������.
    char file_name[100] = {0}; //���� � ����� ������ �����.
    for(int i = 0; i < N-2; i++)
    {
            strcat(file_name, words[i]);
            if(i == 0) strcat(file_name, ":");
            strcat(file_name, "\\");
    }
    char y[20];
    sprintf(y, "Calendar %d.txt", year); //���������� �������� ������� � ����� ��� ������.
    strcat(file_name, y);

    free(words);

    //����� ��������� � ����.
    FILE* f = fopen(file_name, "wt");

    int k = 0;
    while (k < size_h)
    {
        fputs(src[k], f);
        k++;
    }
    fclose(f);
}


int main(int n, char** v)
{
    if(n < 2)
    {
        puts("few parametrs");
        puts("The programm start with at least 1 parametr 'year'");
        puts("In general program have 4 parameters ('year', gorizon month '1'-'6', frame '1' or '0', write to file 'f' or not write any other symbol.");
        return 0;
    }

    int Y = atoi(v[1]);
    //printf("Y = %d\n", Y);
    if(v[1][0] != '0' && Y == 0)
    {
        puts("wrong year");
        return 0;
    }

    int num_goriz_print = 3;
    if(n > 2)
    {
        int k = atoi(v[2]);
        if(k != 0) num_goriz_print = k;
    }

    //printf("Enter year: ");
    //scanf("%d", &Y);//��� ����.
    //printf("Enter number for gorizon print months 1 ... 6: ");
    //scanf("%d", &num_goriz_print);//��� ������� ������ ��� ��������������� �����.

    bool frame = false;
    if(n > 3)
    {
        int k = atoi(v[3]);
        if(k == 1) frame = true;
    }

    bool write = false;
    if(n > 4)
    {
        if(v[4][0] == 'f') write = true;
    }

    //������� ��� ������ �����.
    char M[M_HIGH][M_WIDTH] = {0};

    //�������� ������� ��� ���� ������.
    char G_M[G_M_HIGH][G_M_WIDTH];
    //�������� �������� ����. (������������ ������).
    cleanGeneralMatr(G_M);

    //���������� �������� ������� �������.
    int cnt_m = 0; // �������� ������.
    int pos_h = START_POS_MON_H; // ������� ����� � �������� ������� �� ��������
    const int vert_grad = 9;
    const int goriz_grad = 23;
    for(int i = 0; i < NUM_OF_MONTHS; i++)
    {
        int pos_w = START_POS_MON_W; //������� ����� � �������� ������� �� ����������
        for(int j = 0; j < num_goriz_print; j++)
        {
            createNewMonth(M, Y, cnt_m);
            putMonthMatrToGeneralMatr(G_M, M, pos_h, pos_w);

            cnt_m++;
            pos_w += goriz_grad;

            if(cnt_m == NUM_OF_MONTHS) //���� � �������� ������� ��������� 12 ������ - ��������.
            {
                i = NUM_OF_MONTHS;
                break;
            }
        }

        pos_h += vert_grad;
    }


    //���������� ��������� ������, ������� �� ������ �������.
    int cnt = 0; // �������� ������.
    int size_h = START_POS_MON_H; // �������� ������ �������� ������� ��� �����.
    int size_w = (START_POS_MON_W-2) + (goriz_grad * num_goriz_print) ; // �������� ������ �������� ������� ��� �����.
    for(int i = 0; i < NUM_OF_MONTHS; i++)
    {
        size_h += vert_grad;

        for(int j = 0; j < num_goriz_print; j++)
        {
            cnt++;

            if(cnt == NUM_OF_MONTHS) //���� � �������� ������� ��������� 12 ������ - ��������.
            {
                i = NUM_OF_MONTHS;
                break;
            }
        }
    }

    //������������ �� ��� ���������� � ������ ����� ���.����.
    char year[10];
    sprintf(year, "%d", Y);
    int len_year = strlen(year);
    sprintf(G_M[START_POS_MON_H-3], "%*s\n", (size_w + START_POS_MON_W - len_year - 1)/2 + len_year, year);

    //������������ '\n', �� '\0' � ���� ������� ����� �������� �������.
    for(int i = 0; i < size_h; i++)
    {
        G_M[i][size_w+2] = '\n';
        G_M[i][size_w+3] = '\0';
    }

    //(�������) ���������� ����� ������ �� ������� ����������.
    //(��-��� ������ �� �����., ���� ������� �� ������ ����., ������� ������� ����� �� ����� �� �����).
    if(frame) setFrameToCalendar(G_M, num_goriz_print, size_h, size_w, START_POS_MON_H, START_POS_MON_W);

    //�������� �������
    testFunShowGeneralMatr(G_M, size_h);

    //�� ²��� 1:28��. �������� ����ֲ� ��� ������ ������� ��� ����� ������� ̲����.
    //�������� � ����
    if(write) writeCalendarToFile(G_M, size_h, v[0], Y);

    return 0;
}


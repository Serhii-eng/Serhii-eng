#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_DAYS_WEEK     7 //—≥м дн≥в тижн€
#define NUM_OF_MONTHS    12 //ƒванадц€ть м≥с€ц≥в в роц≥

//Ўирина та висота матриц≥ одного м≥с€ц€, враховуючи назву м≥с€ц€, та назву дн≥в тижн€.
#define M_HIGH            8
#define M_WIDTH          21

//–озм≥ри загальноњ матриц≥
#define G_M_WIDTH       145
#define G_M_HIGH        145

//оба параметри не можуть бути менше за значенн€ 3.
#define START_POS_MON_H   4 //позиц≥€ по висот≥ зв≥дки починатимутьс€ заповнюватись м≥с€ц≥.
#define START_POS_MON_W   3 //позиц≥€ по ширин≥ зв≥дки починатимутьс€ заповнюватись м≥с€ц≥.


bool is_leap_year(int y)
{
    bool f = false; //Ќе високосний р≥к 365

    if(y % 4 == 0)
    {
        f = true; //¬исокосний р≥к 366
        if(y % 100 == 0 && y % 400 != 0)
        {
            f = false; //Ќе высокостный год 365
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


int getStartDayWeekOfMonth(int month, int year) //¬знати день тижн€ початку заданого року.
{
    //√ригор≥анський календар починаЇтьс€ з 15.10.1582, день тижн€ була п'€тниц€.
    //ƒн≥ тижн€ рахуЇмо в≥д 0 ... 6, (понед≥лок ... нед≥л€).
    //ѕ'€тн€цю будемо рахувати 4-м днем тижн€.

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

        if(Y >= year) //ѕерев≥рка чи р≥к дос€гнув заданого значенн€
        {
            if(M >= month) //ѕерев≥рка чи м≥с€ць дос€гнув заданного значенн€
            {
                break;
            }
        }
    }

    return W;
}


void cleanMatr(char M[M_HIGH][M_WIDTH]) //«аповненн€ матриц≥ проб≥лами.
{
    for(int i = 0; i < M_HIGH; i++)
    {
        for(int j = 0; j < M_WIDTH; j++)
        {
            M[i][j] = ' ';
        }
    }
}


void cleanGeneralMatr(char G_M[G_M_HIGH][G_M_WIDTH]) //«аповненн€ матриц≥ проб≥лами.
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
//ƒаЇмо функц≥њ масив в €кий буде заповнюватись матриц€ одного м≥с€ц€ враховуючи назву м≥с€ц€, та його дн≥ тижн€.
//“акож даЇмо функц≥њ р≥к, та м≥с€ць - €ким ми хочемо заповнити матрицю.
//Ќумерац≥€ першого м≥с€ц€ починаЇтьс€ з нул€.
void createNewMonth(char M[M_HIGH][M_WIDTH], int year, int month)
{
    //« €кого дн€ тижн€ починаЇтьс€ м≥с€ць.
    int start_day_week_month = getStartDayWeekOfMonth(month+1, year);
    //printf("start day = %d %d\n", start_day_week_month, month+1);

    //—к≥льки дн≥в маЇ в соб≥ м≥с€ць.
    int month_have_days = get_month_days(month+1, year);
    //printf("month have days = %d %d\n", month_have_days, month+1);

    cleanMatr(M);
    putZeroToFirstPosString(M);

    char* month_n[] = { "January","February", "March","April", "May","June",
            "July", "August","September","October", "November","December"};



    int len_tx_month = strlen(month_n[month]);
    sprintf(M[0], "%*s", (M_WIDTH - len_tx_month-1)/2 + len_tx_month, month_n[month]);/*ћќ∆Ћ»¬ќ “–≈Ѕј ѕ–»Ѕ–ј“» \n*/


    //sprintf(M[0], "%*s", 20, month_n[month]);/*ћќ∆Ћ»¬ќ “–≈Ѕј ѕ–»Ѕ–ј“» \n*/

    char* days_w = {"Mo Tu We Th Fr Sa Su"};
    sprintf(M[1], "%s", days_w);/*ћќ∆Ћ»¬ќ “–≈Ѕј ѕ–»Ѕ–ј“» \n*/


    char buf[10] = {0}; //буфер дл€ заповненн€ кожного числа по окремоств≥.
    for(int i = 0; i < start_day_week_month; i++) //заповн€Їмо пуст≥ позиц≥њ в першому р€дку м≥с€ц€ дл€ того щоб почати заповнювати перше число м≥с€ц€ з потр≥бного дн€ тижн€
    {
        sprintf(buf, "   ");
        strcat(M[2], buf);
    }

    int number = 1; //число м≥с€ц€
    for(int i = 2; i < M_HIGH; i++) //в двох перших позиц≥€х буде заповнватись назва м≥с€ц€ та назва дн≥в тижн€
    {
        int j;
        if(i == 2) j = start_day_week_month; //позиц≥онуЇмо формуванн€ початку м≥с€ц≥ у внутр≥шньому цикл≥.

        for(j; j < NUM_DAYS_WEEK; j++)
        {

            ////////////////блок дл€ заповненн€ р€дку
            if(j < NUM_DAYS_WEEK-1) sprintf(buf, "%2d ", number);  //посл≥довне заповненн€ позиц≥й р€дку, вс≥ окр≥м останньоњ.
            else sprintf(buf, "%2d", number); //заповненн€ останньоњ позиц≥њ в р€дку без проб≥лу.
            ////////////////

            strcat(M[i], buf);//кладемо поступово в р€док, число €ке сформовано попередньо.

            number++;

            if(number > month_have_days)  //€кщо м≥с€ць доб≥г до к≥нц€, то виходимо, в цей час ми вже в к≥нц≥ зовн≥шнього циклу.
            {
                i = M_HIGH;
                break;
            }
        }

        j = 0;
    }

    RemoveAllZero(M); //видалити вс≥ нул≥ терм≥нанти  к≥нц≥ кожного р€дка матриц≥.
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


void testFunShowGeneralMatr(char G_M[G_M_HIGH][G_M_WIDTH], int size_h)//ќЅћ≈∆≈Ќ≈ ¬≤ƒ“¬ќ–≈ЌЌя
{
    for(int i = 0; i < size_h; i++)
        printf("%s", G_M[i]);
}


//(функц≥€) дл€ запису матриц≥ одного м≥с€ц€ в загальну матрицю, по заданим позиц≥€м.
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


//(функц≥€) формуванн€ рамки табиц≥ по заданому параметру - (к≥л-сть м≥с€ц≥в по гориз., факт довжина та ширина матр.).
void setFrameToCalendar(char src[G_M_HIGH][G_M_WIDTH], int num_goriz_print, int size_h, int size_w, int start_pos_h, int start_pos_w)
{
    //поправочн≥ коф≥ц≥Їнти на зм≥щенн€ таблиц≥.
    start_pos_h -= 1;
    start_pos_w -= 2;

    //градац≥€ крок≥в по вертикал≥ та горизонтал≥ на матриц одного м≥с€ц€.
    const int vert_grad = 9;
    const int goriz_grad = 23;

    //формуванн€ горизонтальних л≥н≥й рамки

    //встановленн€ '+' по кутам таблиц≥.
    src[start_pos_h][start_pos_w] = '+'; //'+' в л≥вому верхньому кут≥.
    src[start_pos_h][size_w] = '+';      //'+' в правому верхньому кут≥.
    src[size_h-1][start_pos_w] = '+';      //'+' в л≥вому нижньому кут≥.
    src[size_h-1][size_w] = '+';           //'+' в правому нижньому кут≥.

    for(int i = start_pos_h; i < size_h; i+=vert_grad)
    {
        int dis_str_pos_w = start_pos_w+1; //зм≥щенн€ по горизонтал≥, дл€ проставл€нн€ '+'с≥в.

        for(int k = 0; k < num_goriz_print; k++)//к≥л-сть м≥с€ц≥в по гориз.
        {
            for(int j = 0; j < goriz_grad; j++)//л≥н≥€ м≥ж або над одним з м≥с€ц≥в.
            {
                if( (i == start_pos_h || i == size_h-1) && (k != num_goriz_print-1 || j != goriz_grad-1))//друкуЇмо саму верхню та нижню риски таблиц≥, не зад≥ваючи '+'
                    src[i][j + dis_str_pos_w] = '-';
                else if(j != goriz_grad-1 && i != start_pos_h && i != size_h-1) //гориз. л≥н≥њ с середин≥ табл.
                    src[i][j + dis_str_pos_w] = '-';
                else if(k != num_goriz_print-1 || j != goriz_grad-1) //плюси в середин≥ рамки.
                    src[i][j + dis_str_pos_w] = '+';
            }
            dis_str_pos_w += goriz_grad;

        }
    }

    //встановленн€ вертикальних л≥н≥й таблиц≥
     for(int i = start_pos_h+1; i < size_h-1; i++)
    {
        int dis_str_pos_w = start_pos_w; //зм≥щенн€ по горизонтал≥, дл€ проставл€нн€ '|'.

        for(int k = 0; k <= num_goriz_print; k++)//к≥л-сть м≥с€ц≥в по гориз.
        {
            if((i-start_pos_h) % vert_grad != 0)//проставл€нн€ верт. л≥н≥й в середин≥ табл.
                src[i][dis_str_pos_w] = '|';
            else if(k == 0 || k == num_goriz_print)//проставл€нн€ верт. л≥н≥й ззовн≥ табл.
                src[i][dis_str_pos_w] = '|';

            dis_str_pos_w += goriz_grad;//робимо крок на розм≥р одного м≥с€ц€ по гориз.
        }
    }
}

//‘ункц≥€ дл€ запису календар€ в текстовий файл.
void writeCalendarToFile(char src[G_M_HIGH][G_M_WIDTH], int size_h, char* arg_dir_file, int year)
{
    //–ахуЇмо к≥л-сть сл≥в в шл€ху до файлу з програмою exe.
    char t[100];
    strcpy(t, arg_dir_file);
    int N = 0;
    char* w = strtok(t, ":\\.");
    while(w)
    {
        w = strtok(NULL, ":\\.");
        N++;
    }

    //розд≥л€Їмо шл€х до файлу з програмою, по окремому слову.
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

    //формуванн€ шл€ху дл€ нового файлу з календарем.
    char file_name[100] = {0}; //шл€х ≥ назва нового файлу.
    for(int i = 0; i < N-2; i++)
    {
            strcat(file_name, words[i]);
            if(i == 0) strcat(file_name, ":");
            strcat(file_name, "\\");
    }
    char y[20];
    sprintf(y, "Calendar %d.txt", year); //заповненн€ останньоњ позиц≥њ в р€дку без проб≥лу.
    strcat(file_name, y);

    free(words);

    //запис календар€ у файл.
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
    //scanf("%d", &Y);//¬в≥д року.
    //printf("Enter number for gorizon print months 1 ... 6: ");
    //scanf("%d", &num_goriz_print);//¬в≥д к≥лькост≥ м≥с€ц≥в дл€ горизонтального друку.

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

    //ћатриц€ дл€ одного м≥с€ц€.
    char M[M_HIGH][M_WIDTH] = {0};

    //«агальна матриц€ дл€ всих м≥с€ц≥в.
    char G_M[G_M_HIGH][G_M_WIDTH];
    //ќчищенн€ загальноњ матр. (проставл€нн€ проб≥л≥в).
    cleanGeneralMatr(G_M);

    //«аповненн€ загальноњ матриц≥ м≥с€ц€ми.
    int cnt_m = 0; // л≥чильник м≥с€ц≥в.
    int pos_h = START_POS_MON_H; // позиц≥€ м≥с€ц€ в загальн≥й матриц≥ по вертикал≥
    const int vert_grad = 9;
    const int goriz_grad = 23;
    for(int i = 0; i < NUM_OF_MONTHS; i++)
    {
        int pos_w = START_POS_MON_W; //позиц≥€ м≥с€ц€ в загальн≥й матриц≥ по горизонтал≥
        for(int j = 0; j < num_goriz_print; j++)
        {
            createNewMonth(M, Y, cnt_m);
            putMonthMatrToGeneralMatr(G_M, M, pos_h, pos_w);

            cnt_m++;
            pos_w += goriz_grad;

            if(cnt_m == NUM_OF_MONTHS) //коли в загальн≥й матриц≥ заповнено 12 м≥с€ц≥в - виходимо.
            {
                i = NUM_OF_MONTHS;
                break;
            }
        }

        pos_h += vert_grad;
    }


    //¬изначенн€ фактичних разм≥р≥в, довжини та ширини матриц≥.
    int cnt = 0; // л≥чильник м≥с€ц≥в.
    int size_h = START_POS_MON_H; // фактична висота загальноњ матриц≥ без рамки.
    int size_w = (START_POS_MON_W-2) + (goriz_grad * num_goriz_print) ; // фактична ширина загальноњ матриц≥ без рамки.
    for(int i = 0; i < NUM_OF_MONTHS; i++)
    {
        size_h += vert_grad;

        for(int j = 0; j < num_goriz_print; j++)
        {
            cnt++;

            if(cnt == NUM_OF_MONTHS) //коли в загальн≥й матриц≥ заповнено 12 м≥с€ц≥в - виходимо.
            {
                i = NUM_OF_MONTHS;
                break;
            }
        }
    }

    //¬становлюЇмо р≥к над календарем в перший р€док заг.матр.
    char year[10];
    sprintf(year, "%d", Y);
    int len_year = strlen(year);
    sprintf(G_M[START_POS_MON_H-3], "%*s\n", (size_w + START_POS_MON_W - len_year - 1)/2 + len_year, year);

    //¬становленн€ '\n', та '\0' в к≥нц≥ кожного р€дка загальноњ матриц≥.
    for(int i = 0; i < size_h; i++)
    {
        G_M[i][size_w+2] = '\n';
        G_M[i][size_w+3] = '\0';
    }

    //(функц≥€) формуванн€ рамки табиц≥ по заданим параметрам.
    //(к≥л-сть м≥с€ц≥в по гориз., факт довжина та ширина матр., стартов≥ позиц≥њ рамки по висот≥ та ширин≥).
    if(frame) setFrameToCalendar(G_M, num_goriz_print, size_h, size_w, START_POS_MON_H, START_POS_MON_W);

    //показуЇмо матрицю
    testFunShowGeneralMatr(G_M, size_h);

    //ѕќ ¬≤ƒ≈ќ 1:28хв. ƒќ–ќЅ»“» ‘”Ќ ÷≤ё ƒЋя ¬«я““я ѕ≈–Ўќ√ќ ƒЌя “»∆Ќя  ќ∆Ќќ√ќ ћ≤—я÷я.
    //записати у файл
    if(write) writeCalendarToFile(G_M, size_h, v[0], Y);

    return 0;
}


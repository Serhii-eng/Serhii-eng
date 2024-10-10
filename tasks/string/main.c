#include "charqueue.h"
#include "charstack.h"
#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void string1(){
    char c;
    printf("c = "); scanf("%c", &c);

    int code = c;

    char q = code;

    printf("q = %c, code = %d\n", q, code);
}


void string2(){
    int code;
    printf("c = "); scanf("%d", &code);

    char c = code;

    printf("c = %c\n", c);
}

void string3(){
    char c;
    printf("c = "); scanf("%c", &c);

    printf("c-1 = %c\n", c-1);
    printf("c+1 = %c\n", c+1);
}


void string4(){
    int n;
    printf("n = "); scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("%c ", 'A'+i);
    }
    puts("");
}


void string5(){
    int n;
    printf("n = "); scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("%c ", 'z'-i);
    }
    puts("");
}


void string6(){
    char c;
    printf("c = "); scanf("%c", &c);

    printf("c-1 = %c\n", c-1);
    printf("c+1 = %c\n", c+1);
}


void string7(){
    char s[100];
    printf(" s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);

    printf("first code = %d\n", s[0]);
    printf("last code = %d\n", s[len-1]);
}


void string8()
{
    int n;
    printf("n = "); scanf("%d", &n); getchar();

    char c;
    printf("c = "); scanf("%c", &c);

    char s[100];
    for (int i=0; i<n; i++)
    {
        s[i] = c;
    }
    s[n] = 0;

    printf("%s\n", s);
}


void string9()
{
    int n;
    printf("n = "); scanf("%d", &n); getchar();

    char c1, c2;
    printf(" c1 = "); scanf("%c", &c1); getchar();
    printf(" c2 = "); scanf("%c", &c2);

    char s[100];
    for (int i = 0; i < n; i++)
    {
        if(i%2) s[i] = c2;
        else    s[i] = c1;
    }
    s[n] = 0;

    printf("%s\n", s);
}


void string10()
{
    char s[100];
    printf("s = "); gets(s);

    int i = 0;
    int p = strlen(s)-1;
    while(i < p)
    {
        char c = s[i];
        s[i] = s[p];
        s[p] = c;
        i++;
        p--;
    }

    printf("%s\n", s);
}


void string11()
{
    char s[100];
    printf("s = "); gets(s);

    int a = 0;
    int len = strlen(s);
    char s1[100];
    for (int i = 0; i < len; i++)
    {
        s1[a++] = s[i];
        s1[a++] = ' ';
    }
    s1[a] = 0;


    printf("%s\n", s1);
}


void string12()
{
    char s[100];
    printf("s = "); gets(s);

    int n;
    printf("n = "); scanf("%d", &n);

    int a = 0;
    int len = strlen(s);
    char s1[100];
    for (int i = 0; i < len; i++)
    {
        s1[a++] = s[i];

        if(i == len-1) break;

        for(int j = 0; j < n; j++)
        {
            s1[a++] = '*';
        }
    }
    s1[a] = 0;


    printf("%s\n", s1);
}


void string13()
{
    char s[100];
    printf(" s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for (int i=0; i<len; i++)
    {
        if (isDigit(s[i])) cnt++;
    }

    printf("cnt = %d\n", cnt);
}


void string14()
{
    char s[100];
    printf(" s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for (int i=0; i<len; i++)
    {
        if (isUppercase(s[i])) cnt++;
    }

    printf("cnt = %d\n", cnt);
}


void string15()
{
    char s[100];
    printf(" s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for (int i=0; i<len; i++)
    {
        if(isLowercase(s[i])) cnt++;
    }

    printf("cnt = %d\n", cnt);
}


void string16()
{
    char s[100];
    printf(" s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for (int i=0; i<len; i++)
    {
        s[i] = tolower(s[i]);
    }

    printf("%s\n", s);
}


void string17()
{
    char s[100];
    printf(" s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for (int i=0; i<len; i++)
    {
        s[i] = toUpper(s[i]);
    }

    printf("%s\n", s);
}


void string18()
{
    char s[100];
    printf(" s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for (int i=0; i<len; i++)
    {
        if (isLowercase(s[i]))
        {
            s[i] = toUpper(s[i]);
        }
        else if (isUppercase(s[i]))
        {
            s[i] = toLower(s[i]);
        }
    }

    printf("%s\n", s);
}


void string19()
{
    char s[100];
    printf(" s = "); gets(s);

   // printf("%d\n", isNumberFractioOrInteger(s));

    int is_number = 1;
    int len = strlen(s);
    int cnt = 0;
    int cnt_1 = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] != '.' && !isdigit(s[i]))
        {
            is_number = 0;
            break;
        }
        if(s[i] ==  '.') cnt++;
        if(isDigit(s[i])) cnt_1++;
    }

    if(cnt > 1) is_number = 0;
    if(cnt_1 == 0) is_number = 0;

    if(is_number)
    {
        if(cnt == 0) puts("int");
        if(cnt == 1) puts("double");
    }
    else
    {
        puts("NaN");
    }
}


void string20()
{
    int number;
    printf("n = "); scanf("%d", &number);

    char s[100];
    //convertNumberToString(number, &s);
    sprintf(s, "%+04d", number);

    puts(s);
}


void string21()
{
    int number;
    printf("n = "); scanf("%d", &number);

    char s[100];
    convertReverseNumberToString(number, s);

    puts(s);
}


void string22()
{
    char s[100];
    printf("s = "); gets(s);

    int sum = sunOfDigitsInString(s);

    printf("%d", sum);
}


void string23()
{
    char s[100];
    printf("s = "); gets(s);

    //int rez = plusOrMinusMathOperation(s);
    int sum = s[0]-48;// 4
    int len = strlen(s);
    for(int i = 1; i < len; i+=2)
    {
        if(s[i] == '+') sum += s[i+1]-48;
        if(s[i] == '-') sum -= s[i+1]-48;
    }

    printf("sum = %d", sum);
}


void string24()
{
    //char s[] = "1100"; //0xc;
    char s[100];
    printf("s = "); gets(s);

    int len = strlen(s);
    int w = 1;
    int x = 0;
    for (int i=len-1; i>=0; i--){
        if (s[i]=='1'){
            x += w;
        }
        w += w;
    }

    printf(" x = %d\n", x);

    return 0;
}


void string25()
{
    //char s[] = "12";
    char s[100];
    printf("s = "); gets(s);

    unsigned int x = atoi(s);

    unsigned int check = x;
    int amount_bits = 0;
    for(int i=0; i<32; i++)
    {
        check = check >> 1;
        amount_bits++;
        if(check <= 0) break;
    }

    while(amount_bits % 4 != 0) amount_bits++;

    char ans[33] = {0};
    for(int i=0; i<32; i++){

        if (x%2==1)
            ans[amount_bits-i-1] = '1';
        else
            ans[amount_bits-i-1] = '0';
        x = x >> 1;
    }

    puts(ans);
}


void string26()
{
    char s[100];
    printf("s = "); gets(s);

    int n;
    printf("n = "); scanf("%d", &n);

    char s1[100];
    s1[0] = '\0';
    //strcpy(s1, s);
    int len = strlen(s);

    if(len >= n)
    {
        strcat(s1, s + len-n);
    }
    else
    {
        s1[n-len] = '\0';
        for(int i = 0; i < n-len; i++)  s1[i] = '.';
        strcat(s1, s);
    }

    strcpy(s, s1);

    puts(s);
}


void string27()
{
    char s1[50];
    char s2[50];
    printf("s1 = "); gets(s1);
    printf("s2 = "); gets(s2);

    int N1, N2;
    printf("N1 = "); scanf("%d", &N1);
    printf("N2 = "); scanf("%d", &N2); getchar();

    char s[100];
    strncpy(s, s1, N1);
    s[N1] = '\0';
    strcat(s, s2 + strlen(s2)-N2);
    puts(s);
}


void string28()
{
    char s[100];
    printf("s = "); gets(s);

    char c;
    printf("c = "); scanf("%c", &c);

    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == c)
        {
            for(int j = len-1; j >= i; j--)
            {
                s[j+1] = s[j];
            }
            s[++len] = '\0';
            i++;
        }
    }

    puts(s);
}


void string29()
{
    char s[100];
    char s0[100];
    printf("s = "); gets(s);
    printf("s0 = "); gets(s0);

    char c;
    printf("c = "); scanf("%c", &c);

    int len = strlen(s);
    for(int i = len-1; i >= 0; i--)
    {
        if(s[i] == c)
        {
            insertStringInString(s, s0, i);

        }
    }

    puts(s);
}


void string30()
{
    char s[100];
    char s0[100];
    printf("s = "); gets(s);
    printf("s0 = "); gets(s0);

    char c;
    printf("c = "); scanf("%c", &c);

    int len = strlen(s);
    for(int i = len-1; i >= 0; i--)
    {
        if(s[i] == c)
        {
            insertStringInString(s, s0, i+1);

        }
    }

    puts(s);
}


void string31()
{
    char s[100];
    char s0[100];
    printf("s = "); gets(s);
    printf("s0 = "); gets(s0);

    if(NULL == strstr(s,s0))
        printf("false");
    else
        printf("true");
}


void string32()
{
    char s[100];
    char s0[100];
    printf("s = "); gets(s);
    printf("s0 = "); gets(s0);

    int count = entryStrInStr(s, s0);


    printf("count = %d", count);
}


void string33()
{
    char s[100];
    char s0[100];
    printf("s = "); gets(s);
    printf("s0 = "); gets(s0);

    deleteFirstStrInStr(s, s0);

    puts(s);
}


void string34()
{
    char s[100];
    char s0[100];
    printf("s = "); gets(s);
    printf("s0 = "); gets(s0);

    deleteLastStrInStr(s, s0);

    puts(s);
}


void string35()
{
    char s[100];
    char s0[100];
    printf("s = "); gets(s);
    printf("s0 = "); gets(s0);

    deleteAllStrInStr(s, s0);

    puts(s);
}


void string36()
{
    char s[100];
    char s1[100];
    char s2[100];
    printf("s = "); gets(s);
    printf("s1 = "); gets(s1);
    printf("s2 = "); gets(s2);

    replaceFirstStrInStr(s, s1, s2);

    puts(s);
}


void string37()
{
    char s[100];
    char s1[100];
    char s2[100];
    printf("s = "); gets(s);
    printf("s1 = "); gets(s1);
    printf("s2 = "); gets(s2);

    replaceLastStrInStr(s, s1, s2);

    puts(s);
}


void string38()
{
    char s[100];
    char s1[100];
    char s2[100];
    printf("s = "); gets(s);
    printf("s1 = "); gets(s1);
    printf("s2 = "); gets(s2);

    replaceAllStrInStr(s, s1, s2);

    puts(s);
}


void string39()
{
    char s[100];
    printf("s = "); gets(s);


    int ok = 0;
    int j = 0;
    char ps[100] = {0};
    if(getNumberOfSpaces(s) > 1)
    {
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(is_space(s[i]))
            {
                ok++;
                i++;
            }
            if(ok == 1)
            {
                ps[j++] = s[i];
            }
        }
    }

    puts(ps);
}


void string40()
{
    char s[100];
    printf("s = "); gets(s);

    int cnt = 0;
    int start_pos;
    int finish_pos;
    int len = strlen(s);
    for(int i = 1; i < len; i++)
    {
        if(!isspace(s[i-1]) && isspace(s[i]))
        {
            cnt++;
            if(cnt == 1) start_pos = i+1;
            if(cnt > 1) finish_pos = i;
        }
    }

    if(cnt > 1)
    {
        int j = 0;
        char ps[100] = {0};
        for(int i = start_pos; i < finish_pos; i++)
            ps[j++] = s[i];

        puts(ps);
    }

}


void string41()
{
    char s[100];
    printf("s = "); gets(s);

    int cnt = 0;

    cnt = calcWord(s);

    printf("cnt = %d", cnt);
}


void string41a()
{
    char s[100];
    printf("s = "); gets(s);


    char* word = strtok(s, " \t");

    int N = 0;
    while(word)
    {
        word = strtok(NULL, " \t");
        N++;
    }
    printf("N = %d", N);
}


void string42()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos != -1)
        {
            if(s[st_pos] == s[st_pos + ln_W-1]) cnt++;
            i = i + ln_W;
        }
    }

    printf("cnt = %d\n", cnt);
}


void string42a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        int len = strlen(words[i]);
        if(words[i][0] == words[i][len-1]) cnt++;
    }

    printf("cnt = %d", cnt);
    free(words);

}


void string43()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    char c = 'А';
    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos != -1)
        {
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                if(s[j] == c)
                {
                    cnt++;
                    break;
                }

            }
            i = i + ln_W;
        }
    }

    printf("cnt = %d\n", cnt);
}


void string43a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    int cnt = 0;
    char c = 'А';
    for(int i = 0; i < N; i++)
    {
        int len = strlen(words[i]);
        for(int j = 0; j < len; j++)
        {
            if(words[i][j] == c)
            {
                cnt++;
                break;
            }

        }
    }

    printf("cnt = %d", cnt);
    free(words);

}


void string44()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    char c = 'А';
    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos != -1)
        {
            int temp_cnt = 0;
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                if(s[j] == c) temp_cnt++;
            }
            if(temp_cnt == 3) cnt++;
            i = i + ln_W;
        }
    }

    printf("cnt = %d\n", cnt);
}


void string44a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    int cnt = 0;
    char c = 'А';
    for(int i = 0; i < N; i++)
    {
        int t_cnt = 0;
        int len = strlen(words[i]);
        for(int j = 0; j < len; j++)
        {
            if(words[i][j] == c) t_cnt++;
        }
        if(t_cnt == 3) cnt++;
    }

    printf("cnt = %d", cnt);
    free(words);

}


void string45()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    int ok = 0;
    int min_length = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos != -1)
        {
            int temp_cnt = 0;
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                temp_cnt++;
            }

            if(ok == 0)
            {
                min_length = temp_cnt;
                ok = 1;
            }
            if(temp_cnt < min_length) min_length = temp_cnt;

            i = i + ln_W;
        }
    }

    printf("min_length = %d\n", min_length);
}


void string45a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    int word_length = strlen(words[0]);
    for(int i = 1; i < N; i++)
    {
        int len = strlen(words[i]);
        if(len < word_length) word_length = len;
    }

    printf("word_length = %d", word_length);
    free(words);

}


void string46()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    int ok = 0;
    int max_length = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos != -1)
        {
            int temp_cnt = 0;
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                temp_cnt++;
            }

            if(ok == 0)
            {
                max_length = temp_cnt;
                ok = 1;
            }
            if(temp_cnt > max_length) max_length = temp_cnt;

            i = i + ln_W;
        }
    }

    printf("max_length = %d\n", max_length);
}


void string46a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    int word_length = strlen(words[0]);
    for(int i = 1; i < N; i++)
    {
        int len = strlen(words[i]);
        if(len > word_length) word_length = len;
    }

    printf("word_length = %d", word_length);
    free(words);
}


void string47()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    int p = 0;
    char st[100] = {0};
    int ok_space = 0;
    int cnt_word = 0;
    int calcword = calcWord(s);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos == -1 && ok_space == 0 && cnt_word < calcword)
        {
            st[p++] = '.';
            ok_space = 1;

        }
        if(st_pos != -1)
        {
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                st[p++] = s[j];
            }

            cnt_word++;
            ok_space = 0;

            i = i + ln_W-1;
        }
    }

    puts(st);
}


void string47a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    int p = 0;
    char st[100] = {0};
    for(int i = 0; i < N; i++)
    {
        int len = strlen(words[i]);
        for(int j = 0; j < len; j++)
        {
            st[p++] = words[i][j];
        }
        if(i < N-1) st[p++] = '.';
    }

    puts(st);
    free(words);

}


void string48()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    int p = 0;
    char st[100] ={0};
    int cnt_word = 0;
    int calcword = calcWord(s);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos == -1 && cnt_word > 0 && cnt_word < calcword)
        {
            st[p++] = s[i];

        }
        if(st_pos != -1)
        {
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                if(s[st_pos] == s[j] && j > st_pos) st[p++] = '.';
                else
                    st[p++] = s[j];
            }

            cnt_word++;

            i = i + ln_W-1;
        }
    }

    puts(st);
}


void string48a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    for(int i = 0; i < N; i++)
    {
        int len = strlen(words[i]);
        for(int j = 1; j < len; j++)
        {
            if(words[i][0] == words[i][j]) words[i][j] = '.';
        }
        if(i < N-1) words[i][len] = ' ';
    }

    puts(s);
    free(words);

}


void string49()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int p = 0;
    char st[100] ={0};
    int cnt_word = 0;
    int calcword = calcWord(s);
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos == -1 && cnt_word > 0 && cnt_word < calcword)
        {
            st[p++] = s[i];
        }
        if(st_pos != -1)
        {
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                if(s[st_pos+ln_W-1] == s[j] && j < st_pos+ln_W-1) st[p++] = '.';
                else
                    st[p++] = s[j];
            }

            cnt_word++;

            i = i + ln_W-1;
        }
    }

    puts(st);
}


void string49a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(s, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }

    for(int i = 0; i < N; i++)
    {
        int len = strlen(words[i]);
        for(int j = len-2; j >= 0; j--)
        {
            if(words[i][len-1] == words[i][j]) words[i][j] = '.';
        }
        if(i < N-1) words[i][len] = ' ';
    }

    puts(s);
    free(words);

}


void string50()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);


    int p = 0;
    int ok_space = 0;
    char st[100] ={0};
    int calcword = calcWord(s);
    int cnt_word = calcword;
    int len = strlen(s);
    for(int i = len-1; i >= 0; i--)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos == -1 && cnt_word > 0 && cnt_word <= calcword && ok_space == 0)
        {
            st[p++] = s[i];
            ok_space = 1;
        }
        if(st_pos != -1)
        {
            for(int j = st_pos; j < st_pos+ln_W; j++)
            {
                    st[p++] = s[j];
            }

            ok_space = 0;
            cnt_word--;

            i = i - ln_W-1;
        }
    }

    puts(st);
}


void string50a()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpperAndLower(s);

    char st[100];
    strcpy(st, s);

    int N = calcWord(st);
    char** words = (char*) malloc(sizeof(char*) * N);

    char* word = strtok(st, " \t");
    int i = 0;
    while(word)
    {
        words[i] = word;
        word = strtok(NULL, " \t");
        i++;
    }
    int u = 0;
    int k = N-1;
    while(u < k)
    {
        char* t = words[u];
        words[u] = words[k];
        words[k] = t;
        u++;
        k--;
    }

    int p = 0;
    char str[100] = {0};
    for(int i = 0; i < N; i++)
    {
        int len = strlen(words[i]);
        for(int j = 0; j < len; j++)
        {
            str[p++] = words[i][j];
        }
        str[p++] = ' ';

        if(i == N-1) break;
    }

    puts(str);
    free(words);
}


void string51()
{
    char s[100];
    printf("s = "); gets(s);

    checkRusUpper(s);

    int N = calcWord(s);
    char** words = (char*) malloc(sizeof(char*) * N);

    int p = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int st_pos = startPosWord(s, i);
        int ln_W = lengthWord(s, i);
        if(st_pos != -1)
        {

            words[p++] = &s[i];
            i = i + ln_W;
        }
    }

    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(strCmp(words[i], words[j]) > 0)
            {
                char* t = words[i];
                words[i] = words[j];
                words[j] = t;
            }
        }
    }

    int k = 0;
    char st[100] ={0};
    for(int i = 0; i < N; i++)
    {
        int ln_W = lengthWord(words[i], 0);
        for(int j = 0; j < ln_W; j++)
        {
            st[k++] = words[i][j];
        }

        if(i == N-1) break;
        st[k++] = ' ';
    }

    puts(st);

    free(words);
}


void string51a()
{
    char s[100];
    printf("s = "); gets(s);

    int N = calcWord(s);

    char** words = (char*) malloc(sizeof(char*) * N);

    char S[100];
    strcpy(S, s);

    char* word = strtok(S, " \t\n");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, " \t\n");
    }

//    for(int i = 0; i < N; i++)
//    {
//        puts(words[i]);
//    }

    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(strcmp(words[i], words[j]) > 0)
            {
                char* t = words[i];
                words[i] = words[j];
                words[j] = t;
            }
        }
    }

//    for(int i = 0; i < N; i++)
//    {
//        puts(words[i]);
//    }

//    char ans[100] = {'h', 'e', 'l', 'l', 'o', '\0'};
//    char ans[100] = "hello";
    char ans[100] = {0};
    for(int i = 0; i < N; i++)
    {
        strcat(ans, words[i]);
        if(i != N-1) strcat(ans, ".");
    }

    puts(ans);
    free(words);
//    for(int i = 0; i < N; i++)
//    {
//        int pos = getWordPos(s, i);
//        int len = getWordLen(s, i);
//        char word[50];
//        getWord(s, i, word);
//        printf("%d  %d  %d  %s\n", i, pos, len, word);
//    }
}


void string52()
{
    char s[100];
    printf("s = "); gets(s);

    int N = calcWord(s);
    for(int i = 0; i < N; i++)
    {
        int pos = getWordPos(s, i);
        s[pos] = toUpper(s[pos]);
    }

    puts(s);
}


void string53()
{
    char s[100];
    printf("s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(isPunct(s[i])) cnt++;
    }

    printf("cnt = %d", cnt);
}


void string54()
{
    char s[100];
    printf("s = "); gets(s);

    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(isVowel(s[i])) cnt++;
    }

    printf("cnt = %d", cnt);
}


void string55()
{
    char s[100];
    printf("s = "); gets(s);

    int NW = 0;
    int max = 0;
    int N = calcWord(s);
    for(int i = 0; i < N; i++)
    {
            int W_len = getWordLen(s, i);
            if(W_len > max)
            {
                max = W_len;
                NW = i;
            }
    }

    if(max > 0)
    {
        char word[100] = {0};
        getWord(s, NW, word);
        puts(word);
    }
}


void string55a()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100];
    strcpy(st, s);

    int N = calcWord(st);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, " \t\n.?!,;:-()[]{}'\"/");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, " \t\n.?!,;:-()[]{}'\"/");
    }

    int NW = 0;
    int max = 0;
    for(int j = 0; j < N; j++)
    {
            int W_len = strlen(words[j]);
            if(W_len > max)
            {
                max = W_len;
                NW = j;
            }
    }
    puts(words[NW]);
}


void string56()
{
    char s[100];
    printf("s = "); gets(s);

    int ok = 0;
    int NW = 0;
    int min = 0;
    int N = calcWord(s);
    for(int i = 0; i < N; i++)
    {
            int W_len = getWordLen(s, i);
            if(ok == 0)
            {
                min = W_len;
                ok = 1;
            }
            if(W_len <= min)
            {
                min = W_len;
                NW = i;
            }
    }

    if(min > 0)
    {
        char word[100] = {0};
        getWord(s, NW, word);
        puts(word);
    }
}


void string56a()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100];
    strcpy(st, s);

    int N = calcWord(st);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, " \t\n.?!,;:-()[]{}'\"/");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, " \t\n.?!,;:-()[]{}'\"/");
    }

    int NW = 0;
    int min = 0;
    for(int j = 0; j < N; j++)
    {
            int W_len = strlen(words[j]);
            if(j == 0)
            {
                min = W_len;
            }
            if(W_len <= min)
            {
                min = W_len;
                NW = j;
            }
    }

    puts(words[NW]);
}


void string57()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100];
    strcpy(st, s);

    int N = calcNormWord(st);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, " \t\n");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, " \t\n");
    }

    int u = 0;
    char S[100] = {0};
    for(int j = 0; j < N; j++)
    {
        int len = strlen(words[j]);
        for(int k = 0; k < len; k++)
        {
            S[u++] = words[j][k];
        }
        if(j == N-1) break;
        S[u++] = ' ';
    }

    puts(S);
}


void string58()
{
    char s[100];
    printf("s = "); gets(s);

    char t[100];
    strcpy(t, s);
    int N = 0;
    char* w = strtok(t, ":\\.");
    while(w)
    {
        w = strtok(NULL, ":\\.");
        N++;
    }

    char st[100];
    strcpy(st, s);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, ":\\.");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, ":\\.");
    }

    puts(words[N-2]);
    puts("");
}


void string59()
{
    char s[100];
    printf("s = "); gets(s);

    char t[100];
    strcpy(t, s);
    int N = 0;
    char* w = strtok(t, ":\\.");
    while(w)
    {
        w = strtok(NULL, ":\\.");
        N++;
    }

    char st[100];
    strcpy(st, s);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, ":\\.");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, ":\\.");
    }

    puts(words[N-1]);
    puts("");
}


void string60()
{
    char s[100];
    printf("s = "); gets(s);

    char t[100];
    strcpy(t, s);
    int N = 0;
    char* w = strtok(t, ":\\.");
    while(w)
    {
        w = strtok(NULL, ":\\.");
        N++;
    }

    char st[100];
    strcpy(st, s);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, ":\\.");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, ":\\.");
    }

    if(N > 3) puts(words[1]);
    if(N == 3) puts("\\");
}


void string61()
{
    char s[100];
    printf("s = "); gets(s);

    char t[100];
    strcpy(t, s);
    int N = 0;
    char* w = strtok(t, ":\\.");
    while(w)
    {
        w = strtok(NULL, ":\\.");
        N++;
    }

    char st[100];
    strcpy(st, s);
    char** words = (char*) malloc(sizeof(char*) * N);
    char* word = strtok(st, ":\\.");
    int i = 0;
    while(word)
    {
        words[i++] = word;
        word = strtok(NULL, ":\\.");
    }

    if(N > 3) puts(words[N-3]);
    if(N == 3) puts("\\");
}


void string62()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100];
    strcpy(st, s);

    cipher(st, 1);

    puts(st);
}


void string63()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100];
    strcpy(st, s);

    int k;
    printf("K = "); scanf("%d", &k);
    cipher(st, k);

    puts(st);
}


void string64()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100];
    strcpy(st, s);

    int k;
    printf("K = "); scanf("%d", &k);
    recipher(st, k);

    puts(st);
}


void string65()
{
    char s[100];
    printf("s = "); gets(s);

    char c;
    printf("C = "); scanf("%c", &c); getchar();

    char st[100];
    strcpy(st, s);

    int k = s[0] - c;

    recipher(st, k);

    puts(st);
}


void string66()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100] = {0};
    int p = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(i % 2 != 0)
        {
            st[p++] = s[i];
        }
    }

    for(int j = len-1; j >= 0; j--)
    {
        if(j % 2 == 0)
        {
            st[p++] = s[j];
        }
    }

    puts(st);
}


void string67()
{
    char s[100];
    printf("s = "); gets(s);

    char st[100] = {0};
    int p = 1;
    int len = strlen(s);
    for(int i = 0; i < len/2; i++)
    {
            st[p] = s[i];
            p+=2;
    }

    p = 0;

    for(int j = len-1; j >= len/2; j--)
    {
            st[p] = s[j];
            p+=2;
    }

    puts(st);
}


void string68()
{
    char s[100];
    printf("s = "); gets(s);

    int pos = 0;
    int len = strlen(s);
    for(int i = 0; i < len-1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(!isLat(s[i])) break;
            if(isLat(s[j]))
            {
                if(s[i] > s[j])
                {
                    pos = j;
                    i = len-1;
                    break;
                }
            }
        }
    }

    printf("pos = %d", pos);
}


void string69()
{
    char s[100];
    printf("s = "); gets(s);

    int pos = 0;
    int cnt_right = 0;
    int cnt_left = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(') cnt_right++;
        if(s[i] == ')') cnt_left++;

        if(cnt_left > cnt_right)
        {
            pos = i;
            break;
        }
    }

    if(cnt_right > cnt_left) pos = -1;

    printf("pos = %d", pos);
}


void string70()
{
    char s[100];
    printf("s = "); gets(s);

    int r_b_cnt_right = 0;
    int r_b_cnt_left = 0;

    int s_b_cnt_right = 0;
    int s_b_cnt_left = 0;

    int b_cnt_right = 0;
    int b_cnt_left = 0;

    int pos = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(') r_b_cnt_right++;
        if(s[i] == ')') r_b_cnt_left++;
        if(r_b_cnt_left > r_b_cnt_right)
        {
            pos = i;
            break;
        }

        if(s[i] == '[') s_b_cnt_right++;
        if(s[i] == ']') s_b_cnt_left++;
        if(s_b_cnt_left > s_b_cnt_right)
        {
            pos = i;
            break;
        }

        if(s[i] == '{') b_cnt_right++;
        if(s[i] == '}') b_cnt_left++;
        if(b_cnt_left > b_cnt_right)
        {
            pos = i;
            break;
        }
    }

    if(r_b_cnt_right > r_b_cnt_left) pos = -1;
    if(s_b_cnt_right > s_b_cnt_left) pos = -1;
    if(b_cnt_right > b_cnt_left) pos = -1;

    printf("pos = %d", pos);
}


void string70a()
{
    char s[100];
    printf("s = "); gets(s);

    CharStack st = createCharStack(100);

    int pos = -1;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            pushToCharStack(&st, s[i]);
        }

        if(s[i] == ')')
        {
            if(pickFromCharStack(&st) == '(')
            {
                popFromCharStack(&st);
            }
            else
            {
                pos = i;
                break;
            }
        }

        if(s[i] == ']')
        {
            if(pickFromCharStack(&st) == '[')
            {
                popFromCharStack(&st);
            }
            else
            {
                pos = i;
                break;
            }
        }

        if(s[i] == '}')
        {
            if(pickFromCharStack(&st) == '{')
            {
                popFromCharStack(&st);
            }
            else
            {
                pos = i;
                break;
            }
        }
    }

    if(sizeOfCharStack(&st) && pos == -1) pos = -2;

    printf("pos = %d", pos);

    deleteCharStack(&st);
}


void queue()
{
    CharQueue st = createCharQueue(100);

    enqueueToCharQueue(&st, 'a');
    enqueueToCharQueue(&st, 'b');
    enqueueToCharQueue(&st, 'c');
    enqueueToCharQueue(&st, 'd');

    printf("sizeOfCharQueue = %d\n", sizeOfCharQueue(&st));

    puts("--------");

    showCharQueue(&st);

    puts("--------");

    printf("pickFromCharQueue = %c\n", pickFromCharQueue(&st));
    printf("pickFromCharQueue = %c\n", pickFromCharQueue(&st));

    puts("--------");

    printf("dequeueFromCharQueue = %c\n", dequeueFromCharQueue(&st));
    printf("dequeueFromCharQueue = %c\n", dequeueFromCharQueue(&st));

    puts("--------");

    showCharQueue(&st);

    printf("dequeueFromCharQueue = %c\n", dequeueFromCharQueue(&st));
    printf("dequeueFromCharQueue = %c\n", dequeueFromCharQueue(&st));

    showCharQueue(&st);

    puts("--------");

    enqueueToCharQueue(&st, 'b');
    printf("dequeueFromCharQueue = %c\n", dequeueFromCharQueue(&st));

    deleteCharQueue(&st);
}


int main()
{
    setlocale(LC_ALL, "UKR");
    system("chcp 1251 > nul");
    //Попрацювати з побітовими операціями
    queue();
    return 0;
}



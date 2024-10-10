#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void tex_file_03()
{
    char fileName[] = "file_03.txt";

    FILE* f = fopen(fileName, "wt");

    int n;
    printf(" n = "); scanf("%d", &n);

    char s[50] = {0};
    for (int i = 0; i < n; i++)
    {
        s[i] = 'A' + i;
        fprintf(f, "%s", s);

        for (int j = i+1; j < n; j++)
        {
            fprintf(f, "%c", '*');
        }

        fputc('\n', f);
    }

    fclose(f);

}


void tex_file_04()
{
    char fileName[] = "file_04.txt";

    FILE* f = fopen(fileName, "rt");
    char s[200];
    int str_counter = 0;
    int chr_counter = 0;
    while (fgets(s, 200, f))
    {
        str_counter++;

        removeEOLN(s);
        int len = strlen(s);
        chr_counter += len;
    }
    fclose(f);

    printf("str_counter = %d\n", str_counter);
    printf("chr_counter = %d", chr_counter);
}


void text_file_05a()
{
    char S[200] = {0};
    printf("S = ");
    gets(S);
    printf(S);

    char fileName1[] = "file_04.txt";
    char fileName2[] = "file_05.txt";

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName2, "wt");
    char s[200];

    while(fgets(s, 200, f))
    {
        fputs(s, g);
        fputs("-----\n", g);
    }
    fputs(S, g);
    fclose(f);
    fclose(g);
}


void text_file_05b()
{
    char S[200] = {0};
    printf("S = ");
    gets(S);
    printf(S);

    char fileName1[] = "file_04.txt";
    char fileName2[] = "file_05.txt";

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName2, "wt");
    char s[200];

    while(fgets(s, 200, f))
    {
        fputs(s, g);
        fputs("-----\n", g);
    }
    fputs(S, g);
    fclose(f);
    fclose(g);
}


//append
void text_file_06()
{
    char s[200] = {0};
    printf("File 1 (s) = ");
    gets(s);
    printf(s);

    char S[200] = {0};
    printf("File 2 (S) = ");
    gets(S);
    printf(S);

    char fileName1[] = "file_06a.txt";
    char fileName2[] = "file_06b.txt";

    FILE* f = fopen(fileName1, "wt");
    fputs(s, f);
    fputc('\n', f);
    fclose(f);

    FILE* g = fopen(fileName2, "wt");
    fputs(S, g);
    fputc('\n', g);
    fclose(g);

    g = fopen(fileName2, "rt");
    fgets(s, 200, g);
    fclose(g);

    f = fopen(fileName1, "at");
    fputs(s, f);
    fputc('\n', f);
    fclose(f);
}


void text_file_06a()
{
    char fileName1[] = "file_06a.txt";
    char fileName2[] = "file_06b.txt";

    FILE* f = fopen(fileName1, "at");
    FILE* g = fopen(fileName2, "rt");

    char s[200];
    while(fgets(s, 200, g))
    {
        fputs(s, f);
    }

    fclose(f);
}


void text_file_07()
{
    char fileName1[] = "file_07.txt";

    showTextFile(fileName1);

    //Ввод рядка
    char S[200] = {0};
    printf("String (S) = ");
    gets(S);
    printf(S);
    printf("\n");
    //

    char fileName_tmp[] = "tmp.tmp";

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    fputs(S, g);
    fputc('\n', g);

    char buf[200];
    while (fgets(buf, 200, f)){
        fputs(buf, g);
    }
    fclose(f);
    fclose(g);

    remove(fileName1);
    rename(fileName_tmp, fileName1);

    clearScreen();
    showTextFile(fileName1);

//    fileCopyFast(fileName_tmp, fileName1);
//    remove(fileName_tmp);
}


void text_file_08()
{
    char fileName1[] = "file_08a.txt";
    char fileName2[] = "file_08b.txt";

    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);
    //createNewFile(fileName2);

    FILE* f = fopen(fileName1, "rt");
    FILE* h = fopen(fileName2, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    while (fgets(buf, 200, h)){
        fputs(buf, g);
    }

    while (fgets(buf, 200, f)){
        fputs(buf, g);
    }
    fclose(f);
    fclose(h);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_09()
{
    char fileName1[] = "file_09.txt";
    char fileName_tmp[] = "tmp.tmp";

    int k;
    printf("K = "); scanf("%d", &k);

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];
    while (fgets(buf, 200, f))
    {
        if(i == k) fputc('\n', g);
        fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_10()
{
    char fileName1[] = "file_10.txt";
    char fileName_tmp[] = "tmp.tmp";

    int k;
    printf("K = "); scanf("%d", &k);

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];
    while (fgets(buf, 200, f))
    {
        fputs(buf, g);
        if(i == k) fputc('\n', g);
        i++;
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_11()
{
    char fileName1[] = "file_10.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    while (fgets(buf, 200, f))
    {
        fputs(buf, g);
        if(isLineEmpty(buf)) fputc('\n', g);
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_12()
{
    char fileName1[] = "file_12.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    //Ввод рядка
    char S[200] = {0};
    printf("String (S) = ");
    gets(S);
    printf(S);
    printf("\n");
    //

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    while (fgets(buf, 200, f))
    {
        if(isLineEmpty(buf))
        {
            fputs(S, g);
            fputc('\n', g);
        }
        else
        {
            fputs(buf, g);
        }
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_13()
{
    char fileName1[] = "file_13.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];
    while (fgets(buf, 200, f))
    {
        if(i != 0) fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_14()
{
    char fileName1[] = "file_14.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    int cnt_lines = getAmountLinesOfFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];

    while (fgets(buf, 200, f))
    {
        if(i != cnt_lines-1) fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_15()
{
    char fileName1[] = "file_15.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];

    while (fgets(buf, 200, f))
    {
        if(i != k) fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_16()
{
    char fileName1[] = "file_16.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    while (fgets(buf, 200, f))
    {
        if(!isLineEmpty(buf)) fputs(buf, g);
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_17()
{
    char fileName1[] = "file_17a.txt";
    char fileName2[] = "file_17b.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);
    //createNewFile(fileName2);

    int cnt_lines_1 = getAmountLinesOfFile(fileName1);
    int cnt_lines_2 = getAmountLinesOfFile(fileName2);

    FILE* f = fopen(fileName1, "rt");
    FILE* h = fopen(fileName2, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf_1[200];
    char buf_2[200];
    while (fgets(buf_1, 200, f) && fgets(buf_2, 200, h))
    {
        removeEOLN(buf_1);
        fputs(buf_1, g);
        fputs(buf_2, g);
    }
    fclose(f);
    fclose(h);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_18()
{
    char fileName1[] = "file_18.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    while (fgets(buf, 200, f))
    {
        int len = strlen(buf);
        for(int i = k; i < len; i++)
        fputc(buf[i], g);
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_19()
{
    char fileName1[] = "file_19.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    while (fgets(buf, 200, f))
    {
        switchAllCase(buf);
        fputs(buf, g);
    }
    fclose(f);
    fclose(g);

    fileCopyFast(fileName_tmp, fileName1);
}


void text_file_20()
{
    char fileName1[] = "file_20.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    while (fgets(buf, 200, f))
    {
        normalize(buf);
        fputs(buf, g);
        fputc('\n', g);
    }
    fclose(f);
    fclose(g);

    remove(fileName1);
    rename(fileName_tmp, fileName1);

    clearScreen();
    showTextFile(fileName1);
}


void text_file_21()
{
    char fileName1[] = "file_21.txt";
    char fileName_tmp[] = "tmp.tmp";

    int cnt_lines = getAmountLinesOfFile(fileName1);

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];
    while (fgets(buf, 200, f))
    {
        if(i < cnt_lines - 3) fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    remove(fileName1);
    rename(fileName_tmp, fileName1);

    clearScreen();
    showTextFile(fileName1);
}


void text_file_22()
{
    char fileName1[] = "file_22.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    int cnt_lines = getAmountLinesOfFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];
    while (fgets(buf, 200, f))
    {
        if(i < cnt_lines - k) fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    remove(fileName1);
    rename(fileName_tmp, fileName1);

    clearScreen();
    showTextFile(fileName1);
}


void text_file_23()
{
    char fileName1[] = "file_23.txt";
    char fileName2[] = "file_23b.txt";

    int k;
    printf("K = "); scanf("%d", &k);

    int cnt_lines = getAmountLinesOfFile(fileName1);

    createNewFile(fileName2);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName2, "wt");

    int i = 0;
    char buf[200];
    int cnt = 0;
    bool ok = false;
    while (fgets(buf, 200, f))
    {
        int len = strlen(buf);
        for(int i = 0; i < len; i++) printf(" %d", buf[i]);
        printf("\n");
        if(i >= cnt_lines - k) fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    clearScreen();
    showTextFile(fileName2);
}


void text_file_24()
{
    char fileName1[] = "file_24.txt";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");

    char buf[200];
    int cnt = 0;
    bool ok = false;
    while (fgets(buf, 200, f))
    {
        if(isNewParagraph(buf, &ok)) cnt++;
    }
    fclose(f);

    clearScreen();
    showTextFile(fileName1);

    printf("paragraph = %d", cnt);
}


void text_file_24a()
{
    char fileName1[] = "file_24.txt";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");

    char line[200];
    int cnt = 0;
    bool prev_empty = true;
    while (fgets(line, 200, f))
    {
        if(!isLineEmpty(line) && prev_empty)
        {
            cnt++;
        }

        prev_empty = false;
        if(isLineEmpty(line))
        {
            prev_empty = true;
        }
    }
    fclose(f);

    clearScreen();
    showTextFile(fileName1);

    printf("paragraph = %d", cnt);
}


void text_file_25()
{
    char fileName1[] = "file_25.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    int cnt = 0;
    bool ok = false;
    while (fgets(buf, 200, f))
    {
        if(isNewParagraph(buf, &ok)) cnt++;

        if(cnt == k && ok == true) continue;

        fputs(buf, g);
    }
    fclose(f);
    fclose(g);

    remove(fileName1);
    rename(fileName_tmp, fileName1);

    clearScreen();
    showTextFile(fileName1);
}


void text_file_25a()
{
    char fileName1[] = "file_25.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    clearScreen();
    showTextFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char line[200];
    int cnt = -1;
    bool prev_empty = true;
    while (fgets(line, 200, f))
    {
        if(!isLineEmpty(line))
        {
            if(prev_empty)
            {
                cnt++;
            }

            if(cnt != k)
            {
                fputs(line, g);
            }
            prev_empty = false;
        }
        else
        {
            fputs(line, g);
            prev_empty = true;
        }
    }
    fclose(f);
    fclose(g);

//    remove(fileName1);

    clearScreen();
    showTextFile(fileName_tmp);

    remove(fileName_tmp);
}


void text_file_26()
{
    char fileName1[] = "file_26.txt";

    //createNewFile(fileName1);

    clearScreen();
    showTextFile(fileName1);

    FILE* f = fopen(fileName1, "rt");

    char line[200];
    int cnt = 0;
    bool ok = false;
    while (fgets(line, 200, f))
    {
        if(isRedLine(line)) cnt++;
    }
    fclose(f);

    printf("paragraph = %d", cnt);
}


void text_file_27()
{
    char fileName1[] = "file_27.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    char buf[200];
    int cnt = 0;
    bool ok_1 = false;
    bool ok_2 = false;
    while (fgets(buf, 200, f))
    {
        if(isNewParagraphWithRedLine(buf, &ok_1)) cnt++;
        isNewParagraph(buf, &ok_2);//ця функція допомаає залишати пусті рядки в заданому абзаці

        if(cnt == k && ok_1 == true && ok_2 == true) continue;

        fputs(buf, g);
    }
    fclose(f);
    fclose(g);

    remove(fileName1);
    rename(fileName_tmp, fileName1);

    clearScreen();
    showTextFile(fileName1);
}


void text_file_27a()
{
    char fileName1[] = "file_27.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    clearScreen();
    showTextFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int cnt = -1;
    char line[200];
    while (fgets(line, 200, f))
    {
        if(isLineEmpty(line))
        {
            fputs(line, g);
        }
        else
        {
            if(isRedLine(line))
            {
                cnt++;
            }
            if(cnt != k)
            {
                fputs(line, g);
            }
        }

    }
    fclose(f);
    fclose(g);

    clearScreen();
    showTextFile(fileName_tmp);

    remove(fileName_tmp);
}


void text_file_28()
{
    char fileName1[] = "file_28.txt";
    char fileName_tmp[] = "tmp.tmp";

    //createNewFile(fileName1);

    int cnt_lines = getAmountLinesOfFile(fileName1);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName_tmp, "wt");

    int i = 0;
    char buf[200];
    bool ok = false;
    while (fgets(buf, 200, f))
    {
        if(isNewParagraphWithRedLine(buf, &ok))
        {
            if(i > 0 && i < cnt_lines) fputc('\n', g);
        }

        fputs(buf, g);
        i++;
    }
    fclose(f);
    fclose(g);

    remove(fileName1);
    rename(fileName_tmp, fileName1);

    clearScreen();
    showTextFile(fileName1);
}


void text_file_29()
{
    char fileName1[] = "file_29.txt";

    //createNewFile(fileName1);

    FILE* f = fopen(fileName1, "rt");

    //Знаходимо саме довше слово в тексті
    int max = 0;
    char buf[200];
    while (fgets(buf, 200, f))
    {
        int N = calcWord(buf);
        for(int i = 0; i < N; i++)
        {
            int W_len = getWordLen(buf, i);
            if(W_len > max) max = W_len;
        }
    }
    fclose(f);

    //Знаходимо саме перше та саме довше слово в тексті якщо таких слів декілька.
    f = fopen(fileName1, "rt");

    char word[100];
    while (fgets(buf, 200, f))
    {
        int N = calcWord(buf);
        for(int i = 0; i < N; i++)
        {
            int W_len = getWordLen(buf, i);
            if(W_len == max) getWord(buf, i, word);
        }
    }
    fclose(f);

    clearScreen();
    showTextFile(fileName1);

    printf("Word = %s\n", word);
    printf("Max word length = %d\n", max);
}


void text_file_30()
{
    char fileName1[] = "file_30.txt";

    //createNewFile(fileName1);

    //Взнаємо довжину найкоротшого слова в першому рядку для подальшого порівняння слів.
    FILE* f = fopen(fileName1, "rt");

    int min = 0;
    char buf[200];
    char word[100];
    fgets(buf, 200, f);
    int N = calcWord(buf);
    for(int i = 0; i < N; i++)
    {
        int W_len = getWordLen(buf, i);
        if(i == 0) min = W_len;
        if(W_len < min)
        {
            min = W_len;
            getWord(buf, i, word);
        }
    }

    //Взнаємо довжину найкоротшого слова по всих рядках
    while (fgets(buf, 200, f))
    {
        int N = calcWord(buf);
        for(int i = 0; i < N; i++)
        {
            int W_len = getWordLen(buf, i);
            if(W_len < min)
            {
                min = W_len;
                getWord(buf, i, word);
            }
        }
    }
    fclose(f);

    clearScreen();
    showTextFile(fileName1);

    printf("Word = %s\n", word);
    printf("Min word length = %d\n", min);
}


void text_file_31()
{
    char fileName1[] = "file_31.txt";
    char fileName2[] = "file_31a.txt";

    //createNewFile(fileName1);

    clearScreen();
    showTextFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName2, "wt");

    char buf[200];
    char word[100];
    while (fgets(buf, 200, f))
    {
        int N = calcNormWord(buf);
        for(int i = 0; i < N; i++)
        {
            int W_len = getNormWordLen(buf, i);
            if(W_len == k)
            {
                getNormWord(buf, i, word);
                fputs(word, g);
                fputc('\n', g);
            }
        }
    }
    fclose(f);
    fclose(g);

    //clearScreen();
    showTextFile(fileName2);
}


void text_file_31a()
{
    char fileName1[] = "file_31.txt";
    char fileName2[] = "file_31a.txt";

    //createNewFile(fileName1);

    clearScreen();
    showTextFile(fileName1);

    int k;
    printf("K = "); scanf("%d", &k);

//    char delimiters[33] = {0};
//    for(int i = 0; i < 33; i++)
//    {
//        delimiters[i] = i+1;
//    }

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName2, "wt");

    char word[100];
    while (fscanf(f, "%s", word) != EOF)
    {
        int len = strlen(word);
        for(int i = 0; i < len; i++)
        {
            if(isPunct(word[i]))
            {
                word[i] = 0;
                break;
            }
        }
        len = strlen(word);
        if(len == k)
        {
            puts(word);
            fputs(word, g);
            fputs("\n", g);
        }
    }
    fclose(f);
    fclose(g);

    //clearScreen();
    showTextFile(fileName2);
}


void text_file_32()//Передивитись задачу.
{
    char fileName1[] = "file_32.txt";
    char fileName2[] = "file_32a.txt";

    //createNewFile(fileName1);
    //createNewFile(fileName2);

    clearScreen();
    showTextFile(fileName1);

    char c;
    printf("Enter symbol = "); scanf("%c", &c);
    while(!isSymbol(c) && isUpC(c))
    scanf("%c", &c);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName2, "wt");

    char buf[200];
    char word[100];
    while (fgets(buf, 200, f))
    {
        int N = calcNormWord(buf);
        for(int i = 0; i < N; i++)
        {
            getNormWord(buf, i, word);

            if(word[0] == c)
            {
                fputs(word, g);
                fputc('\n', g);
            }
            if(c == (char)switchOneCase(word[0]))//краще свіч перейминувати
            {
                fputs(word, g);
                fputc('\n', g);
            }
        }
    }
    fclose(f);
    fclose(g);

    //clearScreen();
    showTextFile(fileName2);
}


void text_file_33()
{
    char fileName1[] = "file_33.txt";
    char fileName2[] = "file_33a.txt";

//    createNewFile(fileName1);
//    createNewFile(fileName2);

    clearScreen();
    showTextFile(fileName1);

    char c;
    printf("Enter symbol = "); scanf("%c", &c);
    while(!isSymbol(c) && isLoC(c))
    scanf("%c", &c);

    FILE* f = fopen(fileName1, "rt");
    FILE* g = fopen(fileName2, "wt");

    char buf[200];
    char word[100];
    while (fgets(buf, 200, f))
    {
        int N = calcNormWord(buf);
        for(int i = 0; i < N; i++)
        {
            getNormWord(buf, i, word);

            if(word[0] == c)
            {
                fputs(word, g);
                fputc('\n', g);
            }
            if(c == (char)switchOneCase(word[0]))
            {
                fputs(word, g);
                fputc('\n', g);
            }
        }
    }
    fclose(f);
    fclose(g);

    //clearScreen();
    showTextFile(fileName2);
}


int main()
{
    system("chcp 1251>nul");
    setlocale(LC_ALL, "UKR");

    text_file_31a();

    return 0;
}

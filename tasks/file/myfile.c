#include "myfile.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include <string.h>
#include <stdbool.h>

const int N = 40;

void createFileIntRnd(int from, int to, int number, const char* file_name)
{
    //відкриття файлу для запису
    FILE* f = fopen(file_name, "wb");
    if(!f)
    {
        puts("can't open the file for writing");
        return 1;
    }
    //

    int i = 0;
    while(i < number)
    {
        int y = from + rand() % (to - from);
        fwrite(&y, sizeof(y), 1, f);
        i++;
    }

    fclose(f);
}


void createFileDoubleRnd(int from, int to, int number, const char* file_name)
{
    //відкриття файлу для запису
    FILE* f = fopen(file_name, "wb");
    if(!f)
    {
        puts("can't open the file for writing");
        return 1;
    }
    //

    int i = 0;
    while(i < number)
    {
        double y = (from*100 + rand() % ((from-to) * 100)) / 100.0;
        fwrite(&y, sizeof(y), 1, f);
        i++;
    }

    fclose(f);
}


void showFileNumInt(const char* file_name)
{
    //показати вміст створеного цілочисельного файла
    printf("%s: ", file_name);
    FILE* f = fopen(file_name, "rb");
    int buf;
    while(fread(&buf, sizeof(buf), 1, f))
    {
        printf("%d ", buf);
    }
    puts("");

    fclose(f);
}


void showFileNumDouble(const char* file_name)
{
    //показати вміст створеного дійсночисельного файла
    FILE* f = fopen(file_name, "rb");
    double buf;
    while(fread(&buf, sizeof(buf), 1, f))
    {
        printf("%.2lf ", buf);
    }
    puts("");

    fclose(f);
}


int quantityIntInFile(const char* file_name)
{
    //скільки цілочисельних елементів в файлі
    FILE* f = fopen(file_name, "rb");
    int x;
    int quantity = 0;
    while(fread(&x, sizeof(x), 1, f))
    {
        quantity++;
    }
    fclose(f);
    //printf("number of elements in file = %d", count_elem);
    //puts("");
    return quantity;
    //

}


int quantityDoubleInFile(const char* file_name)
{
    //скільки дійсночисельних елементів в файлі
    FILE* f = fopen(file_name, "rb");
    double x;
    int quantity = 0;
    while(fread(&x, sizeof(x), 1, f))
    {
        quantity++;
    }
    fclose(f);
    //printf("number of elements in file = %lf", count_elem);
    //puts("");
    return quantity;
    //
}


int getFileLengthInBytes(const char* file_name)
{
    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        return 0;
    }

    fseek(f, 0, SEEK_END);

    int N = ftell(f);
    fclose(f);
    return N;
}


int getIntElemFromFile(const char* file_name, int pos)
{
    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        return 0;
    }

    int x;
    fseek(f, sizeof(x) * pos, SEEK_SET);
    fread(&x, 1, sizeof(x), f);

    fclose(f);
    return x;
}


double getDblElemFromFile(const char* file_name, int pos)
{
    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        return 0;
    }

    double x;
    fseek(f, sizeof(x) * pos, SEEK_SET);
    fread(&x, 1, sizeof(x), f);

    fclose(f);
    return x;
}

//Cтворюється новий файл якщо файл існував з такою ж назвою, то видаляється
//Також можна стерати данні заміною файлу на пустий
void createEmptyFile(const char* file_name)
{
    FILE* f = fopen(file_name, "wb");
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        return 0;
    }

    fclose(f);
}


void writeDblElemInFile(const char* file_name, double elem, int pos)
{
    FILE* f = fopen(file_name, "wb");
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        return 0;
    }

    fseek(f, sizeof(elem) * pos, SEEK_SET);
    fwrite(&elem, sizeof(elem), 1, f);

    fclose(f);
}

//функція дозволяє оновлювати, дописувати данні, тільки в існуючий файл.
void addIntElemInExistFile(const char* file_name, int elem, int pos)
{
    FILE* f = fopen(file_name, "r+b"); //r+ дозволяти оновлювати, дописувати або читати данні, тільки в існуючий файл.
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        exit(1);
    }

    fseek(f, sizeof(elem) * pos, SEEK_SET);
    fwrite(&elem, sizeof(elem), 1, f);

    fclose(f);
}


//функція дозволяє оновлювати, дописувати данні, тільки в існуючий файл.
void addDblElemInExistFile(const char* file_name, double elem, int pos)
{
    FILE* f = fopen(file_name, "r+b"); //r+ дозволяти оновлювати, дописувати або читати данні, тільки в існуючий файл.
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        exit(1);
    }

    fseek(f, sizeof(elem) * pos, SEEK_SET);
    fwrite(&elem, sizeof(elem), 1, f);

    fclose(f);
}


int is_local_min_dbl(const char* file_name, int n, int pos)
{

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        return 0;
    }

    double a_0;
    double a_1;
    double a_2;

    if(pos == 0)
    {
        fread(&a_0, 1, sizeof(double), f);
        fread(&a_1, 1, sizeof(double), f);

        fclose(f);

        return a_0 < a_1;
    }
    if(pos == n-1)
    {
        for(int i = 0; i < pos-1; i++){
            fread(&a_0, 1, sizeof(double), f);
        }

        fread(&a_1, 1, sizeof(double), f);
        fread(&a_0, 1, sizeof(double), f);

        fclose(f);

        return a_1 > a_0;
    }

    for(int i = 1; i < pos; i++){
            fread(&a_0, 1, sizeof(double), f);
        }

    fread(&a_0, 1, sizeof(double), f);
    fread(&a_1, 1, sizeof(double), f);
    fread(&a_2, 1, sizeof(double), f);

    fclose(f);

    return a_0 > a_1 && a_1 < a_2;
}


int is_local_max_dbl(const char* file_name, int n, int pos)
{

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cannot open file: %s", file_name);
        return 0;
    }

    double a_0;
    double a_1;
    double a_2;

    if(pos == 0)
    {
        fread(&a_0, 1, sizeof(double), f);
        fread(&a_1, 1, sizeof(double), f);

        fclose(f);

        return a_0 > a_1;
    }
    if(pos == n-1)
    {
        for(int i = 0; i < pos-1; i++){
            fread(&a_0, 1, sizeof(double), f);
        }

        fread(&a_1, 1, sizeof(double), f);
        fread(&a_0, 1, sizeof(double), f);

        fclose(f);

        return a_1 < a_0;
    }

    for(int i = 1; i < pos; i++){
            fread(&a_0, 1, sizeof(double), f);
        }

    fread(&a_0, 1, sizeof(double), f);
    fread(&a_1, 1, sizeof(double), f);
    fread(&a_2, 1, sizeof(double), f);

    fclose(f);

    return a_0 < a_1 && a_1 > a_2;
}


void is_local_min_dbl_better(const char* file_name, const char* file_name_pos)
{
    FILE* f = fopen(file_name, "rb");
    if(!f){
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_pos, "wb");
    if(!g){
        printf("Cant open file: %s\n", file_name_pos);
        fclose(f);
        exit(2);
    }

    int i = 0;
    double a, b, c;
    fread(&a, sizeof(a), 1, f);
    fread(&b, sizeof(b), 1, f);
    if(a < b){
        fwrite(&i, sizeof(i), 1, g);
    }
    while(fread(&c, sizeof(c), 1, f)){
        i++;
        if(a > b && b < c){
            fwrite(&i, sizeof(i), 1, g);
        }
        a = b;
        b = c;
    }
    if(c < a){
        i++;
        fwrite(&i, sizeof(i), 1, g);
    }
    fclose(f);
    fclose(g);
}


void is_local_max_dbl_better(const char* file_name, const char* file_name_pos)
{
    FILE* f = fopen(file_name, "rb");
    if(!f){
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_pos, "wb");
    if(!g){
        printf("Cant open file: %s\n", file_name_pos);
        fclose(f);
        exit(2);
    }

    int i = 0;
    double a, b, c;
    fread(&a, sizeof(a), 1, f);
    fread(&b, sizeof(b), 1, f);
    if(a > b){
        fwrite(&i, sizeof(i), 1, g);
    }
    while(fread(&c, sizeof(c), 1, f)){
        i++;
        if(a < b && b > c){
            fwrite(&i, sizeof(i), 1, g);
        }
        a = b;
        b = c;
    }
    if(c > a){
        i++;
        fwrite(&i, sizeof(i), 1, g);
    }
    fclose(f);
    fclose(g);
}


void swapIntElemInFile(const char* file_name, int i, int j)
{
    int temp_i = getIntElemFromFile(file_name, i);
    int temp_j = getIntElemFromFile(file_name, j);
    addIntElemInExistFile(file_name, temp_j, i);
    addIntElemInExistFile(file_name, temp_i, j);
}


int fileCopy(const char* src, const char* dst)
{
    FILE* f = fopen(src, "rb");
    if(!f) return 0;

    FILE* g = fopen(dst, "wb");
    if(!g)
    {
        fclose(f);
        return 0;
    }

    char c;
    while(fread(&c, sizeof(c), 1, f))
    {
        fwrite(&c, sizeof(c), 1, g);
    }

    fclose(f);
    fclose(g);

    return 1;
}


int fileCopyFast(const char* src, const char* dst)
{
    FILE* f = fopen(src, "rb");
    if(!f) return 0;

    FILE* g = fopen(dst, "wb");
    if(!g)
    {
        fclose(f);
        return 0;
    }

    char s[1024];
    int n;
    while(n = fread(s, sizeof(char), sizeof(s), f))
    {
        //printf("n = %d\n", n);
        fwrite(s, sizeof(char), n, g);
    }

    fclose(f);
    fclose(g);

    return 1;
}


int fileCopyFastAddInEnd(const char* src, const char* dst)
{
    FILE* f = fopen(src, "rb");
    if(!f) return 0;

    FILE* g = fopen(dst, "ab");
    if(!g)
    {
        fclose(f);
        return 0;
    }

    char s[1024];
    int n;
    while(n = fread(s, sizeof(char), sizeof(s), f))
    {
        //printf("n = %d\n", n);
        fwrite(s, sizeof(char), n, g);
    }

    fclose(f);
    fclose(g);

    return 1;
}

int getPosMinInDblFile(const char *file_name, double *min_value)
{
    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        exit(1);
    }

    double temp;
    double min;
    int n = 0;
    int pos_min = 0;
    while( fread(&temp, sizeof(double), 1, f) )
    {
        if(n == 0) min = temp;

        if(temp < min)
        {
            min = temp;
            pos_min = n;
        }

        n++;
    }

    fclose(f);

    *min_value = min;

    return pos_min;
}


void CopyDouleFileExceptPos(const char* src, const char* dst, int pos)
{
    FILE* f = fopen(src, "rb");
    if(!f) exit(1);

    FILE* g = fopen(dst, "wb");
    if(!g)
    {
        fclose(f);
        exit(2);
    }

    int i = 0;
    double temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {
        if(i != pos) fwrite(&temp, sizeof(temp), 1, g);
        i++;
    }

    fclose(f);
    fclose(g);
}


void sortIncDblFile(const char* file_name)
{
    FILE* f = fopen("tmp.sorted", "wb");
    if(!f)
    {
        fclose(f);
        exit(1);
    }

    fileCopyFast(file_name, "tmp.buf1");


    int n = getFileLengthInBytes("tmp.buf1") / sizeof(double);

    int i = 0;
    while(i < n)
    {
        double min_value;
        int pos = getPosMinInDblFile("tmp.buf1", &min_value);

        fwrite(&min_value, sizeof(min_value), 1, f);
        CopyDouleFileExceptPos("tmp.buf1", "tmp.buf2", pos);
        fileCopyFast("tmp.buf2", "tmp.buf1");

        i++;
    }

    fclose(f);

    fileCopyFast("tmp.sorted", file_name);

    remove("tmp.sorted");
    remove("tmp.buf1");
    remove("tmp.buf2");
}


void mergeTwoSortedIncDblFiles(const char* src_1, const char* src_2, const char* dst)
{
    FILE* f = fopen(src_1, "rb");
    if(!f)
    {
        exit(1);
    }

    FILE* h = fopen(src_2, "rb");
    if(!h)
    {
        fclose(f);
        exit(2);
    }

    FILE* g = fopen(dst, "wb");
    if(!h)
    {
        fclose(f);
        fclose(h);
        exit(2);
    }
    double buf_1, buf_2;
    int ok_1 = fread(&buf_1, sizeof(buf_1), 1, f);
    int ok_2 = fread(&buf_2, sizeof(buf_2), 1, h);

    while(ok_1 && ok_2)
    {
        double temp;

        if(buf_1 < buf_2)
        {
            temp = buf_1;
            fwrite(&temp, sizeof(temp), 1, g);
            ok_1 = fread(&buf_1, sizeof(buf_1), 1, f);
        }
        else
        {
            temp = buf_2;
            fwrite(&temp, sizeof(temp), 1, g);
            ok_2 = fread(&buf_2, sizeof(buf_2), 1, h);
        }
    }

    while(ok_1)
    {
        double temp;
        temp = buf_1;
        fwrite(&temp, sizeof(temp), 1, g);
        ok_1 = fread(&buf_1, sizeof(buf_1), 1, f);
    }

    while(ok_2)
    {
        double temp;
        temp = buf_2;
        fwrite(&temp, sizeof(temp), 1, g);
        ok_2 = fread(&buf_2, sizeof(buf_2), 1, h);
    }

    fclose(f);
    fclose(h);
    fclose(g);
}


void revDblFile(const char* file_name)
{
    int n = getFileLengthInBytes(file_name)/sizeof(double);
    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);

    int i = 0;
    int j = n-1;
    while (i<j){
        double a, b;
        fseek(f, i*sizeof(double), SEEK_SET);
        fread(&a, sizeof(a), 1, f);
        fseek(f, j*sizeof(double), SEEK_SET);
        fread(&b, sizeof(b), 1, f);

        fseek(f, i*sizeof(double), SEEK_SET);
        fwrite(&b, sizeof(b), 1, f);
        fseek(f, j*sizeof(double), SEEK_SET);
        fwrite(&a, sizeof(a), 1, f);
        i++;
        j--;
    }

    fclose(f);
}


void sortIncDblFileWithSeek(const char* file_name)
{
    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);

    int n = getFileLengthInBytes(file_name)/sizeof(double);

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            double a, b;
            fseek(f, i*sizeof(double), SEEK_SET);
            fread(&a, sizeof(a), 1, f);
            fseek(f, j*sizeof(double), SEEK_SET);
            fread(&b, sizeof(b), 1, f);

            if(a > b)
            {
                fseek(f, i*sizeof(double), SEEK_SET);
                fwrite(&b, sizeof(b), 1, f);
                fseek(f, j*sizeof(double), SEEK_SET);
                fwrite(&a, sizeof(a), 1, f);
            }
        }
    }

    fclose(f);
}


void addToEndIntFileToArchive(const char* src, const char* dst)
{
    FILE* f = fopen(src, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* g = fopen(dst, "ab");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(1);
    }

    int n = getFileLengthInBytes(src)/sizeof(int);

    fwrite(&n, sizeof(int), 1, g);

    int buf_r, buf_w;
    while(fread(&buf_r, sizeof(buf_r), 1, f))
    {
        buf_w = buf_r;
        fwrite(&buf_w, sizeof(buf_w), 1, g);
    }

    fclose(f);
    fclose(g);
}


void addToEndDblFileToArchive(const char* src, const char* dst)
{
    FILE* f = fopen(src, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* g = fopen(dst, "ab");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(1);
    }

    double n = getFileLengthInBytes(src)/sizeof(double);

    fwrite(&n, sizeof(double), 1, g);

    double buf_r, buf_w;
    while(fread(&buf_r, sizeof(buf_r), 1, f))
    {
        buf_w = buf_r;
        fwrite(&buf_w, sizeof(buf_w), 1, g);
    }

    fclose(f);
    fclose(g);
}


int getAmountOfIntFilesArchive(const char* file)
{
    FILE* f = fopen(file, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int cnt = 0;
    int pos_n;
    while(fread(&pos_n, sizeof(pos_n), 1, f))
    {
        int n = pos_n;
        for(int i = 0; i < n; i++)
        {
            fread(&pos_n, sizeof(pos_n), 1, f);
        }

        cnt++;
    }

    fclose(f);

    return cnt;
}


int getAmountOfDblFilesArchive(const char* file)
{
    FILE* f = fopen(file, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int cnt = 0;
    double pos_n;
    while(fread(&pos_n, sizeof(pos_n), 1, f))
    {
        int n = pos_n;
        for(int i = 0; i < n; i++)
        {
            fread(&pos_n, sizeof(pos_n), 1, f);
        }

        cnt++;
    }

    fclose(f);

    return cnt;
}


void getIntFileFromArchive(const char* src, int num, const char* dst)
{
    FILE* f = fopen(src, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* g = fopen(dst, "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    int cnt = 0;
    int pos_n;
    while(fread(&pos_n, sizeof(pos_n), 1, f))
    {
        int n = pos_n;
        for(int i = 0; i < n; i++)
        {
            fread(&pos_n, sizeof(pos_n), 1, f);

            if(cnt == num)
            {
                int buf_w = pos_n;
                fwrite(&buf_w, sizeof(buf_w), 1, g);
            }
        }

        cnt++;
    }

    fclose(f);
    fclose(g);
}


void getDblFileFromArchive(const char* src, int num, const char* dst)
{
    FILE* f = fopen(src, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* g = fopen(dst, "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    int cnt = 0;
    double pos_n;
    while(fread(&pos_n, sizeof(pos_n), 1, f))
    {
        double n = pos_n;
        for(int i = 0; i < n; i++)
        {
            fread(&pos_n, sizeof(pos_n), 1, f);

            if(cnt == num)
            {
                double buf_w = pos_n;
                fwrite(&buf_w, sizeof(buf_w), 1, g);
            }
        }

        cnt++;
    }

    fclose(f);
    fclose(g);
}


void deleteIntFileFromArchive(const char* file, int num)
{
    FILE* f = fopen(file, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* g = fopen("tmp.tmp", "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    int cnt = 0;
    int pos_n;
    while(fread(&pos_n, sizeof(pos_n), 1, f))
    {
        int n = pos_n;

        if(cnt != num)
        {
            fwrite(&n, sizeof(n), 1, g);
        }

        for(int i = 0; i < n; i++)
        {
            fread(&pos_n, sizeof(pos_n), 1, f);

            if(cnt != num)
            {
                int buf_w = pos_n;
                fwrite(&buf_w, sizeof(buf_w), 1, g);
            }
        }

        cnt++;
    }

    fclose(f);
    fclose(g);

    fileCopyFast("tmp.tmp", file);
}


void deleteDblFileFromArchive(const char* file, int num)
{
    FILE* f = fopen(file, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* g = fopen("tmp.tmp", "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    int cnt = 0;
    double pos_n;
    while(fread(&pos_n, sizeof(pos_n), 1, f))
    {
        double n = pos_n;

        if(cnt != num)
        {
            fwrite(&n, sizeof(n), 1, g);
        }

        for(int i = 0; i < n; i++)
        {
            fread(&pos_n, sizeof(pos_n), 1, f);

            if(cnt != num)
            {
                double buf_w = pos_n;
                fwrite(&buf_w, sizeof(buf_w), 1, g);
            }
        }

        cnt++;
    }

    fclose(f);
    fclose(g);

    fileCopyFast("tmp.tmp", file);
}


void insertIntFileToArchive(const char* dst, int num, const char* src)
{
    int amount_elem_of_src = getFileLengthInBytes(src)/sizeof(int);

    FILE* f = fopen(dst, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* h = fopen(src, "rb");
    if(!h)
    {
        printf("File can not open for read");
        fclose(f);
        exit(2);
    }

    FILE* g = fopen("tmp.tmp", "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        fclose(h);
        exit(3);
    }

    int cnt = 0; //лічильник для розуміння, на позиції якого файлу архіву знаходемося в циклі(while).
    int buf_r, buf_w;
    while(fread(&buf_r, sizeof(buf_r), 1, f))
    {
        if(cnt == num) //додавання файлу в архів, умова виконується якщо позиція вставки файлу в архів (num) знаходиться в діапазоні позицій архіву.
        {
            int buf_r2, buf_w2, n2;
            buf_w2 = n2 = amount_elem_of_src;
            fwrite(&buf_w2, sizeof(buf_w2), 1, g);

            for(int i = 0; i < n2; i++)
            {
                fread(&buf_r2, sizeof(buf_r2), 1, h);
                buf_w2 = buf_r2;
                fwrite(&buf_w2, sizeof(buf_w2), 1, g);
            }
        }
        //на цьому місці відбувається переписування основної частини архіву (dst), без файлу (src).
        buf_w = buf_r;
        fwrite(&buf_w, sizeof(buf_w), 1, g);

        int n = buf_r;
        for(int i = 0; i < n; i++)
        {
            fread(&buf_r, sizeof(buf_r), 1, f);
            buf_w = buf_r;
            fwrite(&buf_w, sizeof(buf_w), 1, g);
        }

        cnt++;
    }

    if(cnt == num) //заходимо сюди, якщо файл додається в самий кінець архіву
    {
        int buf_r2, buf_w2, n2;
            buf_w2 = n2 = amount_elem_of_src;
            fwrite(&buf_w2, sizeof(buf_w2), 1, g);

            for(int i = 0; i < n2; i++)
            {
                fread(&buf_r2, sizeof(buf_r2), 1, h);
                buf_w2 = buf_r2;
                fwrite(&buf_w2, sizeof(buf_w2), 1, g);
            }
    }

    fclose(f);
    fclose(h);
    fclose(g);

    fileCopyFast("tmp.tmp", dst);
}


void insertDblFileToArchive(const char* dst, int num, const char* src)
{
    double amount_elem_of_src = getFileLengthInBytes(src)/sizeof(double);

    FILE* f = fopen(dst, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE* h = fopen(src, "rb");
    if(!h)
    {
        printf("File can not open for read");
        fclose(f);
        exit(2);
    }

    FILE* g = fopen("tmp.tmp", "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        fclose(h);
        exit(3);
    }

    int cnt = 0; //лічильник для розуміння, на позиції якого файлу архіву знаходемося в циклі(while).
    double buf_r, buf_w;
    while(fread(&buf_r, sizeof(buf_r), 1, f))
    {
        if(cnt == num) //додавання файлу в архів, умова виконується якщо позиція вставки файлу в архів (num) знаходиться в діапазоні позицій архіву.
        {
            double buf_r2, buf_w2, n2;
            buf_w2 = n2 = amount_elem_of_src;
            fwrite(&buf_w2, sizeof(buf_w2), 1, g);

            for(int i = 0; i < n2; i++)
            {
                fread(&buf_r2, sizeof(buf_r2), 1, h);
                buf_w2 = buf_r2;
                fwrite(&buf_w2, sizeof(buf_w2), 1, g);
            }
        }
        //на цьому місці відбувається переписування основної частини архіву (dst), без файлу (src).
        buf_w = buf_r;
        fwrite(&buf_w, sizeof(buf_w), 1, g);

        double n = buf_r;
        for(int i = 0; i < n; i++)
        {
            fread(&buf_r, sizeof(buf_r), 1, f);
            buf_w = buf_r;
            fwrite(&buf_w, sizeof(buf_w), 1, g);
        }

        cnt++;
    }

    if(cnt == num) //заходимо сюди, якщо файл додається в самий кінець архіву
    {
        double buf_r2, buf_w2, n2;
            buf_w2 = n2 = amount_elem_of_src;
            fwrite(&buf_w2, sizeof(buf_w2), 1, g);

            for(int i = 0; i < n2; i++)
            {
                fread(&buf_r2, sizeof(buf_r2), 1, h);
                buf_w2 = buf_r2;
                fwrite(&buf_w2, sizeof(buf_w2), 1, g);
            }
    }

    fclose(f);
    fclose(h);
    fclose(g);

    fileCopyFast("tmp.tmp", dst);
}


void addToEndIntElemToFile(const char* file, int elem)
{
    FILE* f = fopen(file, "ab");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    fwrite(&elem, sizeof(elem), 1, f);

    fclose(f);
}


void addToEndDblElemToFile(const char* file, double elem)
{
    FILE* f = fopen(file, "ab");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    fwrite(&elem, sizeof(elem), 1, f);

    fclose(f);
}


void createA55(int n, const char* arh_name)
{
    //Виділили пам'ять від n імен файлів
    char** names = (char**) malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++)
    {
        names[i] = (char*) malloc(20);
    }

    //Придумаємо (синтезуємо) імена для файлів
    for(int i = 0; i < n; i++)
    {
        sprintf(names[i], "filename%02d.dat", i+1);
    }

//    for(int i = 0; i < n; i++)
//    {
//        puts(names[i]);
//    }
    /*--------------------------------------*/

    for(int i = 0; i < n; i++)
    {
        int N = 3 + rand() % 8;
        createFileIntRnd(0, 10, N, names[i]);
    }

//    for(int i = 0; i < n; i++)
//    {
//        showFileNumInt(names[i]);
//    }

    /*--------------------------------------*/

    FILE* f = fopen(arh_name, "wb");

    for(int i = 0; i < n; i++)
    {
        int len = getFileLengthInBytes(names[i]) / sizeof(int);
        fwrite(&len, sizeof(len), 1, f);

        FILE* g = fopen(names[i], "rb");
        int x;
        for(int j = 0; j < len; j++)
        {
            fread(&x, sizeof(x), 1, g);
            fwrite(&x, sizeof(x), 1, f);
        }
        fclose(g);
    }

    fclose(f);

    /*--------------------------------------*/

    for(int i = 0; i < n; i++)
    {
        remove(names[i]);
    }

    for(int i = 0; i < n; i++)
    {
        free(names[i]);
    }
    free(names);
}


void createCharFile(const char* name, int n, int from, int to)
{
    FILE* f = fopen(name, "wb");
    for(int i = 0; i < n; i++)
    {
        int c = from + rand() % (to - from);
        fputc(c, f);
    }
    fclose(f);
}


void showCharFile(const char* name)
{
    printf("%s: ", name);

    FILE* f = fopen(name, "rb");

    int c;
    while((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }
    puts("");

    fclose(f);
}


int is_Space(int c)
{
    return c == 32;
}


void sortIncIntFileSymbolsWithSeek(const char* file_name)
{
    int n = getFileLengthInBytes(file_name);

    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);


    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            char a, b;
            fseek(f, i*sizeof(a), SEEK_SET);
            a = fgetc(f);
            fseek(f, j*sizeof(a), SEEK_SET);
            b = fgetc(f);

            if(a > b)
            {
                fseek(f, i*sizeof(a), SEEK_SET);
                fputc(b, f);
                fseek(f, j*sizeof(a), SEEK_SET);
                fputc(a, f);
            }
        }
    }

    fclose(f);
}


void createFileOfStrings(const char* file_name, int from, int to, int num_str, int str_len)
{
    FILE* f = fopen(file_name, "wb");

    char str[40] = "";
    for(int i = 0; i < num_str; i++)
    {
        for(int j = 0; j < str_len; j++)
        {
            str[j] = from + rand() % (to - from);

        }

        str[str_len] = 0;
        fwrite(str, sizeof(str), 1, f);
    }

    fclose(f);
}


void createFileOfStringsWithRandLength(const char* file_name, int from, int to, int num_str, int str_len)
{
    FILE* f = fopen(file_name, "wb");

    int rand_len;
    char str[40] = "";
    for(int i = 0; i < num_str; i++)
    {
        rand_len = rand() % (str_len+1);
        for(int j = 0; j < rand_len; j++)
        {
            str[j] = from + rand() % (to - from);

        }

        str[rand_len] = 0;
        fwrite(str, sizeof(str), 1, f);
    }

    fclose(f);
}


void showFileOfStrings(const char* file_name)
{
    FILE* g = fopen(file_name, "rb");

    char str[40] = "";
    while(fread(str, sizeof(str), 1, g))
    {
        puts(str);
    }

    fclose(g);
}

char getCharByPosInString(const char* s, int pos)
{
    return s[pos];
}


void sortIncStringFileWithSeek(const char* file_name)
{
    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);

    char a[40] = "";
    char b[40] = "";
    //тут працює через жопу, як правельно зробити?
    //якщо будуть різні розміри буферів під рядки в функції create і тут, то все попливе..
    int n = getFileLengthInBytes(file_name)/sizeof(a);

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            fseek(f, i*sizeof(a), SEEK_SET);
            fread(a, sizeof(a), 1, f);
            fseek(f, j*sizeof(b), SEEK_SET);
            fread(b, sizeof(b), 1, f);

            if(a[0] > b[0])
            {
                fseek(f, i*sizeof(b), SEEK_SET);
                fwrite(b, sizeof(b), 1, f);
                fseek(f, j*sizeof(a), SEEK_SET);
                fwrite(a, sizeof(a), 1, f);
            }
        }
    }

    fclose(f);
}


void sortIncStringByLengthFileWithSeek(const char* file_name)
{
    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);

    char a[40] = "";
    char b[40] = "";
    //тут працює через жопу, як правельно зробити?
    //якщо будуть різні розміри буферів під рядки в функції create і тут, то все попливе..
    int n = getFileLengthInBytes(file_name)/sizeof(a);

    for(int i = 0; i < n-1; i++)
    {

        for(int j = i+1; j < n; j++)
        {
            int len_a;
            int len_b;

            fseek(f, i*sizeof(a), SEEK_SET);
            fread(a, sizeof(a), 1, f);
            len_a = strlen(a);
            fseek(f, j*sizeof(b), SEEK_SET);
            fread(b, sizeof(b), 1, f);
            len_b = strlen(b);

            if(len_a > len_b)
            {
                fseek(f, i*sizeof(b), SEEK_SET);
                fwrite(b, sizeof(b), 1, f);
                fseek(f, j*sizeof(a), SEEK_SET);
                fwrite(a, sizeof(a), 1, f);
            }
        }
    }

    fclose(f);
}


void sortDecStringsFileOfDatasWithSeek(const char* file_name)
{
    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);

    char a[40] = "";
    char b[40] = "";
    //якщо будуть різні розміри буферів під рядки в функції create і тут, то все попливе..
    int n = getFileLengthInBytes(file_name)/sizeof(a);

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {

            fseek(f, i*sizeof(a), SEEK_SET);
            fread(a, sizeof(a), 1, f);
            int data_a = getYear(a)*10000 + getMonth(a)*100 + getDay(a);

            fseek(f, j*sizeof(b), SEEK_SET);
            fread(b, sizeof(b), 1, f);
            int data_b = getYear(b)*10000 + getMonth(b)*100 + getDay(b);

            if(data_a < data_b)
            {
                fseek(f, i*sizeof(b), SEEK_SET);
                fwrite(b, sizeof(b), 1, f);
                fseek(f, j*sizeof(a), SEEK_SET);
                fwrite(a, sizeof(a), 1, f);
            }
        }
    }

    fclose(f);
}


void revStringFile(const char* file_name)
{
    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);

    char a[N];
    char b[N];

    int n = getFileLengthInBytes(file_name)/sizeof(a);

    int i = 0;
    int j = n-1;
    while (i<j){

        fseek(f, i*sizeof(a), SEEK_SET);
        fread(a, sizeof(a), 1, f);
        fseek(f, j*sizeof(b), SEEK_SET);
        fread(b, sizeof(b), 1, f);

        fseek(f, i*sizeof(b), SEEK_SET);
        fwrite(b, sizeof(b), 1, f);
        fseek(f, j*sizeof(a), SEEK_SET);
        fwrite(a, sizeof(a), 1, f);
        i++;
        j--;
    }

    fclose(f);
}


void createStringData(char* str_data, int day, int month, int year)
{
    sprintf(str_data, "%02d/%02d/%04d", day, month, year);
}


bool is_leap_year(int y)
{
    bool f = false; //Не высокостный год 365

    if(y % 4 == 0)
    {
        f = true; //Высокостный год 366
        if(y % 100 == 0 && y % 400 != 0)
        {
            f = false; //Не высокостный год 365
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


void createStringOfRandData(char* str_data, int from_year, int to_year)
{
    int year = from_year + rand() % (to_year - from_year);
    int month = (rand() % 12)+1;
    int day = (rand() % get_month_days(month, year)) + 1;
    createStringData(str_data, day, month, year);
}


void createFileOfRandData(const char* file_name, int num_str, int from_year, int to_year)
{
    FILE *f = fopen(file_name, "wb");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    char buf[N];
    int i = 0;
    while(i < num_str)
    {
        createStringOfRandData(buf, from_year, to_year);
        fwrite(buf, sizeof(buf), 1, f);
        i++;
    }

    fclose(f);
}


void showFileOfChar(const char* file_name)
{
    //показати вміст створеного цілочисельного файла
    printf("%s: ", file_name);
    FILE* f = fopen(file_name, "rb");
    char buf;
    while(fread(&buf, sizeof(buf), 1, f))
    {
        printf("%c", buf);
    }
    puts("");

    fclose(f);
}


int getDay(char* str_data)
{
    char str[15];
    int len = strlen(str_data);
    strcpy(str, str_data);
    str[len] = 0;

    char* str_day = strtok(str, "//");

    return atoi(str_day);
}


int getMonth(char* str_data)
{
    char str[15];
    int len = strlen(str_data);
    strcpy(str, str_data);
    str[len] = 0;

    char* str_month = strtok(str, "//");
    str_month = strtok(NULL, "//");

    return atoi(str_month);
}


int getYear(char* str_data)
{
    char str[15];
    int len = strlen(str_data);
    strcpy(str, str_data);
    str[len] = 0;

    char* str_year = strtok(str, "//");
    str_year = strtok(NULL, "//");
    str_year = strtok(NULL, "//");

    return atoi(str_year);
}


//Функції для сортування дат//
//------------------------------------------------//
Date createDate(int d, int m, int y){
    Date date = {0};
    sprintf(date.str, "%04d.%02d.%02d", y, m, d);
    return date;
}

void showDateR(Date date){
    printf(date.str);
}

void showDate(Date date){
    int d = getDay2(date);
    int m = getMonth2(date);
    int y = getYear2(date);
    printf("%02d.%02d.%04d", d, m, y);
}
void showDateLn(Date date){
    int d = getDay2(date);
    int m = getMonth2(date);
    int y = getYear2(date);
    printf("%02d.%02d.%04d\n", d, m, y);
}

void showDateRLn(Date date){
    printf("%s\n", date.str);
}

int getDay2(Date date){
    return atoi(date.str + 8);
}

int getMonth2(Date date){
    return atoi(date.str + 5);
}

int getYear2(Date date){
    return atoi(date.str + 0);
}

Date setDay(const Date date, int day){
    int m = getMonth2(date);
    int y = getYear2(date);
    sprintf(date.str, "%04d.%02d.%02d", y, m, day);
    return date;
}

Date setMonth(const Date date, int month){
    int d = getDay2(date);
    int y = getYear2(date);
    sprintf(date.str, "%04d.%02d.%02d", y, month, d);
    return date;
}

Date setYear(const Date date, int year){
    int d = getDay2(date);
    int m = getMonth2(date);
    sprintf(date.str, "%04d.%02d.%02d", year, m, d);
    return date;
}

int cmpDates(Date d1, Date d2){
    return strcmp(d1.str, d2.str);
}

void createFileOfRandData2(const char* file_name, int num_str, int from_year, int to_year)
{
    FILE *f = fopen(file_name, "wb");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    int i = 0;
    Date date;
    while(i < num_str)
    {
        int year = from_year + rand() % (to_year - from_year);
        int month = (rand() % 12)+1;
        int day = (rand() % get_month_days(month, year)) + 1;
        date = createDate(day, month, year);
        fwrite(&date, sizeof(date), 1, f);
        i++;
    }

    fclose(f);
}


void showFileOfDateLn(const char* file_name)
{
    FILE* g = fopen(file_name, "rb");

    Date date;
    while(fread(&date, sizeof(date), 1, g))
    {
        showDateLn(date);
    }

    fclose(g);
}


void sortDecStringsFileOfDatasWithSeek2(const char* file_name)
{
    FILE* f = fopen(file_name, "rb+");
    if(!f) exit(1);

    Date a, b;
    int n = getFileLengthInBytes(file_name)/sizeof(a);

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            fseek(f, i*sizeof(a), SEEK_SET);
            fread(&a, sizeof(a), 1, f);

            fseek(f, j*sizeof(b), SEEK_SET);
            fread(&b, sizeof(b), 1, f);

            if (cmpDates(a, b) < 0)
            {
                fseek(f, i*sizeof(b), SEEK_SET);
                fwrite(&b, sizeof(b), 1, f);
                fseek(f, j*sizeof(a), SEEK_SET);
                fwrite(&a, sizeof(a), 1, f);
            }
        }
    }

    fclose(f);
}


void createFileOfDblRndMatr(const char* fname, int m, int n, int from, int to)
{
    FILE *f = fopen(fname, "wb");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    fwrite(&m, sizeof(m), 1, f);
    fwrite(&n, sizeof(n), 1, f);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double x = (from*100 + rand() % ((from-to) * 100)) / 100.0;
            fwrite(&x, sizeof(x), 1, f);
        }
    }

    fclose(f);
}


void showFileOfDblMatr(const char* fname)
{
    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int m, n;
    fread(&m, sizeof(m), 1, f);
    fread(&n, sizeof(n), 1, f);

    printf("\n");
    printf("m = %d\n", m);
    printf("n = %d\n", n);
    printf("\n");

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            double x;
            fread(&x, sizeof(x), 1, f);
            printf("%5.1lf ", x);
        }
        printf("\n\n");
    }

    fclose(f);
}


double getElemOfFileMatr(const char* fname, int i, int j)
{
    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int m, n;
    fread(&m, sizeof(m), 1, f);
    fread(&n, sizeof(n), 1, f);

    double x = 0;
    if(i > m || n < j) return x;

    int size = sizeof(x);
    fseek(f, size*i*n + size*j, SEEK_CUR);
    fread(&x, sizeof(x), 1, f);

    fclose(f);

    return x;
}


void getSizeOfMatr(const char* fname, int *m, int *n)
{
    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    fread(m, sizeof(*m), 1, f);
    fread(n, sizeof(*n), 1, f);
}


void transpositionFileOfDblMatr(const char* fname)
{
    FILE *f = fopen("tmp.tmp", "wb");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    int m, n;
    getSizeOfMatr(fname, &m, &n);

    fwrite(&n, sizeof(n), 1, f);
    fwrite(&m, sizeof(m), 1, f);

    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < m; i++)
        {
            double x = getElemOfFileMatr(fname, i, j);
            fwrite(&x, sizeof(x), 1, f);
        }
    }

    //double x = getElemOfFileMatr(fname, 1, 1);
    fclose(f);

    fileCopyFast("tmp.tmp", fname);
}


void setElemToExistFileMatr(const char* fname, int i, int j, double elem)
{
    FILE *f = fopen(fname, "r+b");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int m, n;
    fread(&m, sizeof(m), 1, f);
    fread(&n, sizeof(n), 1, f);

    double x = 0;
    if(i > m || n < j) return x;

    int size = sizeof(x);
    fseek(f, size*i*n + size*j, SEEK_CUR);
    fwrite(&x, sizeof(x), 1, f);

    fclose(f);

    return x;
}


void zeroMainDiagonalM(const char* fname, int d)
{
    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int m;
    int n;
    fread(&m, sizeof(m), 1, f);
    fread(&n, sizeof(n), 1, f);

    int i = 0;
    int j = 0;

    if(d > 0) j = d;
    if(d < 0) i = -d;

    while(i < m && j < n)
    {
        setElemToExistFileMatr(fname, i, j, 0.0);

        i++;
        j++;
    }
}


void createFileWithHighTriagleMatr(const char* fname, int m, int n, int from, int to)
{
    createFileOfDblRndMatr(fname, m, n, from, to);

    for(int d = -1; d > -m; d--)
    {
        zeroMainDiagonalM(fname, d);
    }
}


void createFileWithLowTriagleMatr(const char* fname, int m, int n, int from, int to)
{
    createFileOfDblRndMatr(fname, m, n, from, to);

    for(int d = 1; d < n; d++)
    {
        zeroMainDiagonalM(fname, d);
    }
}


void createFileWithThreeDiagMatr(const char* fname, int m, int n, int from, int to)
{
    createFileOfDblRndMatr(fname, m, n, from, to);

    for(int d = 2; d < n; d++)
    {
        zeroMainDiagonalM(fname, d);
    }

    for(int d = -2; d > -m; d--)
    {
        zeroMainDiagonalM(fname, d);
    }
}






























#include "myfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void file01()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file01.dat";
    puts(file_name);

    FILE* f = fopen(file_name, "wb");
    if(!f)
    {
        puts("false");
        //return 1;
    }
    else
    {
        puts("true");
        fclose(f);
    }
}


void file02()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    puts(file_name);

    FILE* f = fopen(file_name, "wb");
    if(!f)
    {
        puts("can't open the file");
        //return 1;
    }
    else
    {
        puts("file is open");
    }

    int n;
    printf(" N = ");
    scanf("%d", &n);


    int x = 2;
    for(int i = 0; i < n; i++)
    {
        fwrite(&x, sizeof(i), 1, f);
        x+=2;
    }
    fclose(f);

    f = fopen(file_name, "rb");
    if (!f)
    {
        puts("cant read the file");
        return 2;
    }
    else
    {
        puts("file is read");
    }

    while(fread(&x, sizeof(x), 1, f))
    {
        printf("%d ", x);
    }
    fclose(f);
}


void file03()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file03.dat";
    puts(file_name);

    FILE* f = fopen(file_name, "wb");
    if(!f)
    {
        puts("can't open the file");
        //return 1;
    }
    else
    {
        puts("file is open");
    }

    double a, d;
    printf(" A = ");
    scanf("%lf", &a);
    printf(" D = ");
    scanf("%lf", &d);
    double x = a;
    for(int i = 0; i < 10; i++)
    {
        fwrite(&x, sizeof(x), 1, f);
        x+=d;
    }
    fclose(f);

    f = fopen(file_name, "rb");
    if (!f)
    {
        puts("cant read the file");
        return 2;
    }
    else
    {
        puts("file is read");
    }

    while(fread(&x, sizeof(x), 1, f))
    {
        printf("%lf ", x);
    }
    fclose(f);
}


void file04()
{
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\file01.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file03.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\file04.dat";

    char** files[4];
    files[0] = file_name_0;
    files[1] = file_name_1;
    files[2] = file_name_2;
    files[3] = file_name_3;
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        puts(files[i]);

        FILE* f = fopen(files[i], "rb");
        if(f)
        {
            cnt++;
            fclose(f);
        }
    }

    printf("files = %d", cnt);
}


void file04a()
{
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\file01.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file03.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\file04.dat";

    int cnt = 0;

    FILE* f = fopen(file_name_0, "rb");
    if(f)
    {
        cnt++;
        fclose(f);
    }

    f = fopen(file_name_1, "rb");
    if(f) cnt++;
    fclose(f);

    f = fopen(file_name_2, "rb");
    if(f) cnt++;
    fclose(f);

    f = fopen(file_name_3, "rb");
    if(f) cnt++;
    fclose(f);

    printf("files = %d", cnt);
}


void file05()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";

    int cnt = 0;
    FILE* f = fopen(file_name, "rb");
    if (!f)
    {
        puts("cant read the file");
        cnt = -1;
    }
    else
    {
        puts("file is read");
    }

    int x;
    while(fread(&x, sizeof(x), 1, f))
    {
        cnt++;
        printf("%d ", x);
    }

    puts("");
    printf("values = %d", cnt);

    fclose(f);
}


void file06()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";

    FILE* f = fopen(file_name, "rb");
    if (!f)
    {
        puts("cant read the file");
        return 2;
    }
    else
    {
        puts("file is read");
    }

    int k;
    printf(" K = ");
    scanf("%d", &k);

    int x;
    int cnt = 0;
    int num = -1;
    while(fread(&x, sizeof(x), 1, f))
    {
        if(cnt == k) num = x;
        cnt++;
    }

    puts("");
    printf("elem = %d ", num);

    fclose(f);
}


void file07()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    //файл читаэться з 2-ї задачі
    FILE* f = fopen(file_name, "rb");
    if (!f)
    {
        puts("cant read the file");
        return 2;
    }
    else
    {
        puts("file is read");
    }
    //скільки елементів в файлі
    int x;
    int amount = 0;
    while(fread(&x, sizeof(x), 1, f))
    {
        amount++;
        //printf("%d ", x);
    }
    puts("");
    fclose(f);
    //

    //вивід на екран
    int y;
    int cnt = 0;
    f = fopen(file_name, "rb");
    while(fread(&y, sizeof(y), 1, f))
    {
        if(cnt < 2) printf("%d ", y);
        if(cnt >= amount-2) printf("%d ", y);
        cnt++;
    }
    fclose(f);
    //
}


void file08()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    //файл читаэться з 2-ї задачі
    FILE* f = fopen(file_name, "rb");
    if (!f)
    {
        puts("cant read the file");
        return 2;
    }
    else
    {
        puts("file is read");
    }
    //

    //скільки елементів в файлі
    int x;
    int amount = 0;
    while(fread(&x, sizeof(x), 1, f))
    {
        amount++;
        printf("%d ", x);
    }
    puts("");
    fclose(f);
    //

    //відкриття файлу для запису
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file08.dat";
    FILE* f2 = fopen(file_name_2, "wb");
    if(!f)
    {
        puts("can't open the file for writing");
        return 1;
    }
    else
    {
        puts("file is open for writing");
    }
    //

    //запис данних
    int y;
    int cnt = 0;
    f = fopen(file_name, "rb");
    while(fread(&y, sizeof(y), 1, f))
    {
        if(cnt < 1) fwrite(&y, sizeof(y), 1, f2);
        if(cnt > amount-2) fwrite(&y, sizeof(y), 1, f2);
        cnt++;
    }
    fclose(f);
    fclose(f2);
    //

    //читання створеного та записаного файла
    int z;
    f2 = fopen(file_name_2, "rb");
    while(fread(&z, sizeof(z), 1, f2))
    {
        printf("%d ", z);
    }

    fclose(f2);
    //
}


void file09()
{
    char file_name_a[] = "D:\\Lenguage C\\Lesson 13\\Files\\file09_a.dat";
    char file_name_b[] = "D:\\Lenguage C\\Lesson 13\\Files\\file09_b.dat";
    FILE* f_a = fopen(file_name_a, "rb");
    FILE* f_b = fopen(file_name_b, "rb");

    if(f_a && !f_b)
    {
        printf("file 'file09_a' is present\n");
        fclose(f_b); //закриття файлу як для читання щоб відкрити як для запису.

        //скільки елементів в файлі
        double x;
        int amount = 0;
        while(fread(&x, sizeof(x), 1, f_a))
        {
            printf("%lf ", x);
            amount++;
        }
        puts("");
        fclose(f_a);
        //

        //відкриття файлу для запису
        f_b = fopen(file_name_b, "wb");
        if(!f_b)
        {
            puts("can't open the file for writing");
            return 1;
        }
        else
        {
            puts("file is open for writing");
        }
        //

        //запис данних
        double y;
        int cnt = 0;
        f_a = fopen(file_name_a, "rb");
        while(fread(&y, sizeof(y), 1, f_a))
        {
            if(cnt < 1) fwrite(&y, sizeof(y), 1, f_b);
            if(cnt > amount-2) fwrite(&y, sizeof(y), 1, f_b);
            cnt++;
        }
        fclose(f_a);
        fclose(f_b);
        //

        //читання створеного та записаного файла
        double z;
        f_b = fopen(file_name_b, "rb");
        while(fread(&z, sizeof(z), 1, f_b))
        {
            printf("%lf ", z);
        }
        fclose(f_b);
        //
    }

    if(f_b && !f_a)
    {
        printf("file 'file09_b' is present\n");
        fclose(f_a); //закриття файлу як для читання щоб відкрити як для запису.

        //скільки елементів в файлі
        double x;
        int amount = 0;
        while(fread(&x, sizeof(x), 1, f_b))
        {
            printf("%lf ", x);
            amount++;
        }
        puts("");
        fclose(f_b);
        //

        //відкриття файлу для запису
        f_a = fopen(file_name_a, "wb");
        if(!f_a)
        {
            puts("can't open the file for writing");
            return;
        }
        else
        {
            puts("file is open for writing");
        }
        //

        //запис данних
        double y;
        int cnt = 0;
        f_b = fopen(file_name_b, "rb");
        while(fread(&y, sizeof(y), 1, f_b))
        {
            if(cnt < 1) fwrite(&y, sizeof(y), 1, f_a);
            if(cnt > amount-2) fwrite(&y, sizeof(y), 1, f_a);
            cnt++;
        }
        fclose(f_a);
        fclose(f_b);
        //

        //читання створеного та записаного файла
        double z;
        f_a = fopen(file_name_a, "rb");
        while(fread(&z, sizeof(z), 1, f_a))
        {
            printf("%lf ", z);
        }
        fclose(f_a);
        //
    }
}


void file10()
{
    //скільки елементів в файлі
    char file_name_a[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    FILE* f_a = fopen(file_name_a, "rb");
    int x;
    int count_elem = 0;
    while(fread(&x, sizeof(x), 1, f_a))
    {
        printf("%d ", x);
        count_elem++;
    }
    rewind(f_a);
    //
    puts("");

    //запис данних
    char file_name_b[] = "D:\\Lenguage C\\Lesson 13\\Files\\file10.dat";
    FILE* f_b = fopen(file_name_b, "wb");
    int y;
    int i = count_elem-1;
    while(i >= 0)
    {
        fseek(f_a, sizeof(y)*i, SEEK_SET);
        fread(&y, sizeof(y), 1, f_a);
        fwrite(&y, sizeof(y), 1, f_b);
        i--;
    }
    //

    fclose(f_a);
    fclose(f_b);

    //long size = ftell(f_a); // поточне положення покажчика в байтах

    //читання створеного та записаного файла
    int z;
    f_b = fopen(file_name_b, "rb");
    while(fread(&z, sizeof(z), 1, f_b))
    {
        printf("%d ", z);
    }
    //
    fclose(f_b);
}


void file11()
{
    //скільки елементів в файлі
    char file_name_a[] = "D:\\Lenguage C\\Lesson 13\\Files\\file03.dat";
    FILE* f_a = fopen(file_name_a, "rb");
    double x;
    int count_elem = 0;
    while(fread(&x, sizeof(x), 1, f_a))
    {
        printf("%lf ", x);
        count_elem++;
    }
    rewind(f_a);
    //

    puts("");

    //запис данних
    char file_name_b[] = "D:\\Lenguage C\\Lesson 13\\Files\\file11_a.dat";
    char file_name_c[] = "D:\\Lenguage C\\Lesson 13\\Files\\file11_b.dat";
    FILE* f_b = fopen(file_name_b, "wb");
    FILE* f_c = fopen(file_name_c, "wb");

    int i = 0;
    while(i < count_elem)
    {
        double y;
        if(i%2!=0)
        {
            fseek(f_a, sizeof(y)*i, SEEK_SET);
            fread(&y, sizeof(y), 1, f_a);
            fwrite(&y, sizeof(y), 1, f_b);
        }
        else
        {
            fseek(f_a, sizeof(y)*i, SEEK_SET);
            fread(&y, sizeof(y), 1, f_a);
            fwrite(&y, sizeof(y), 1, f_c);
        }

        i++;
    }
    //

    fclose(f_a);
    fclose(f_b);
    fclose(f_c);


    //читання створених та записаних файлів
    double buf;
    f_b = fopen(file_name_b, "rb");
    while(fread(&buf, sizeof(buf), 1, f_b))
    {
        printf("%lf ", buf);
    }
    fclose(f_b);

    puts("");

    f_c = fopen(file_name_c, "rb");
    while(fread(&buf, sizeof(buf), 1, f_c))
    {
        printf("%lf ", buf);
    }
    //
    fclose(f_c);
}


void file12()
{
    //скільки елементів в файлі
    char file_name_a[] = "D:\\Lenguage C\\Lesson 13\\Files\\file02.dat";
    FILE* f_a = fopen(file_name_a, "rb");
    int x;
    int count_elem = 0;
    while(fread(&x, sizeof(x), 1, f_a))
    {
        printf("%d ", x);
        count_elem++;
    }
    rewind(f_a);
    //

    puts("");

    //запис данних
    char file_name_b[] = "D:\\Lenguage C\\Lesson 13\\Files\\file12_a.dat";
    char file_name_c[] = "D:\\Lenguage C\\Lesson 13\\Files\\file12_b.dat";
    FILE* f_b = fopen(file_name_b, "wb");
    FILE* f_c = fopen(file_name_c, "wb");

    int i = 0;
    while(i < count_elem)
    {
        int y;
        fseek(f_a, sizeof(y)*i, SEEK_SET);
        fread(&y, sizeof(y), 1, f_a);

        if(y%2==0)
            fwrite(&y, sizeof(y), 1, f_b);
        else
            fwrite(&y, sizeof(y), 1, f_c);

        i++;
    }
    //

    fclose(f_a);
    fclose(f_b);
    fclose(f_c);


    //читання створених та записаних файлів
    int buf;
    f_b = fopen(file_name_b, "rb");
    while(fread(&buf, sizeof(buf), 1, f_b))
    {
        printf("%d ", buf);
    }
    fclose(f_b);

    puts("");

    f_c = fopen(file_name_c, "rb");
    while(fread(&buf, sizeof(buf), 1, f_c))
    {
        printf("%d ", buf);
    }
    //
    fclose(f_c);
}


void file13()
{
    //створення файлу з рамдомними цілими числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file13.dat";
    //createFileIntRnd(-10, 10, 20, file_name);
    //

    showFileNumInt(file_name);

    int count_elem = quantityIntInFile(file_name);

    //запис данних
    char file_name_a[] = "D:\\Lenguage C\\Lesson 13\\Files\\file13_a.dat";
    char file_name_b[] = "D:\\Lenguage C\\Lesson 13\\Files\\file13_b.dat";
    FILE* f = fopen(file_name, "rb");
    FILE* f_a = fopen(file_name_a, "wb");
    FILE* f_b = fopen(file_name_b, "wb");

    int i = count_elem-1;
    while(i >= 0)
    {
        int y;
        fseek(f, sizeof(y)*i, SEEK_SET);
        fread(&y, sizeof(y), 1, f);

        if(y > 0)
            fwrite(&y, sizeof(y), 1, f_a);
        if(y < 0)
            fwrite(&y, sizeof(y), 1, f_b);

        i--;
    }
    //

    fclose(f);
    fclose(f_a);
    fclose(f_b);

    showFileNumInt(file_name_a);
    showFileNumInt(file_name_b);
}


void file14()
{
    //створення файлу з рамдомними дійсними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file14.dat";
    createFileDoubleRnd(0, 10, 20, file_name);
    //

    showFileNumDouble(file_name);

    int count_elem = quantityDoubleInFile(file_name);

    FILE* f = fopen(file_name, "rb");

    int i = 0;
    double sum = 0;
    while(i < count_elem)
    {
        double y;
        fseek(f, sizeof(y)*i, SEEK_SET);
        fread(&y, sizeof(y), 1, f);
        sum += y;
        i++;
    }

    printf("ariph = %lf", sum/count_elem);

    fclose(f);
}


void file15()
{
    //створення файлу з рамдомними дійсними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file14.dat";
    createFileDoubleRnd(0, 10, 4, file_name);
    //

    showFileNumDouble(file_name);

    int count_elem = quantityDoubleInFile(file_name);

    FILE* f = fopen(file_name, "rb");

    int i = 0;
    double sum = 0;
    while(i < count_elem)
    {
        if(i%2==0)
        {
            double y;
            fseek(f, sizeof(y)*i, SEEK_SET);
            fread(&y, sizeof(y), 1, f);
            sum += y;
        }
        i++;
    }

    printf("sum = %lf", sum);

    fclose(f);
}


void file16()
{
    //створення файлу з рамдомними цілими числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file14.dat";
    createFileIntRnd(0, 5, 10, file_name);
    //

    showFileNumInt(file_name);

    int count_elem = getFileLengthInBytes(file_name) / sizeof(int);

    int cnt = 1;
    for(int i = 1; i < count_elem; i++)
    {
        int temp_1, temp_2;
        temp_1 = getIntElemFromFile(file_name, i-1);
        temp_2 = getIntElemFromFile(file_name, i);

        if(temp_1 != temp_2) cnt++;
    }

    printf("seria = %d", cnt);
}


void file17()//Якщо дати багато елементів, то довго працює 2000
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file17.dat";
    createFileIntRnd(0, 5, 2000, file_name);
    showFileNumInt(file_name);

    char file_name_length_series[] = "D:\\Lenguage C\\Lesson 13\\Files\\file17_length_series.dat";
    char file_name_number_in_series[] = "D:\\Lenguage C\\Lesson 13\\Files\\file17_number_in_series.dat";
    createEmptyFile(file_name_length_series);
    createEmptyFile(file_name_number_in_series);

    int j = 0;
    int cnt = 1;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(int);

    int temp_1, temp_2;

    for(int i = 1; i < count_elem; i++)
    {
        temp_1 = getIntElemFromFile(file_name, i-1);
        temp_2 = getIntElemFromFile(file_name, i);

        if(temp_1 != temp_2)
        {
            addIntElemInExistFile(file_name_length_series, cnt, j);
            addIntElemInExistFile(file_name_number_in_series, temp_1, j);
            j++;
            cnt = 0;

        }

        cnt++;

        if(i == count_elem-1)
        {
            addIntElemInExistFile(file_name_length_series, cnt, j);
            addIntElemInExistFile(file_name_number_in_series, temp_2, j);

        }
    }

    puts("");
    showFileNumInt(file_name_length_series);
    showFileNumInt(file_name_number_in_series);
}


void file17a()//Якщо дати багато елементів, то довго працює 2000
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file17.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file17_2.dat";

    createFileIntRnd(0, 5, 20, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Can not open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Can not open file: %s\n", file_name_2);
        fclose(f);
        exit(2);
    }

    int len = 1;
    int prev, x;
    fread(&prev, sizeof(prev), 1, f);
    while(fread(&x, sizeof(x), 1, f))
    {
        if(x != prev)
        {
            fwrite(&len, sizeof(len), 1, g);
            len = 1;
        }
        else
        {
            len++;
        }
        prev = x;
    }
    fwrite(&len, sizeof(len), 1, g);

    fclose(f);
    fclose(g);

    puts("");
    showFileNumInt(file_name_2);
}


void file18()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file18.dat";
    createFileDoubleRnd(0, 11, 10, file_name);
    showFileNumDouble(file_name);

    int count_elem = getFileLengthInBytes(file_name) / sizeof(double);

    int pos_local_min;
    for(int i = 0; i < count_elem; i++)
    {
        if(is_local_min_dbl(file_name, count_elem, i))
        {
            pos_local_min = i;
            break;
        }
    }

    puts("");

    printf("position of local minimum = %d\n", pos_local_min);
    printf("local minimum number = %lf", getDblElemFromFile(file_name, pos_local_min));

}


void file18a()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file18.dat";
    createFileDoubleRnd(0, 11, 10, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Can not open file: %s\n", file_name);
        exit(1);
    }

    double a, b, c, min;
    fread(&a, sizeof(double), 1, f);
    fread(&b, sizeof(double), 1, f);
    if(a < b)
    {
        min = a;
    }
    else
    {
        while(fread(&c, sizeof(double), 1, f))
        {
            if(a > b && b < c)
            {
                min = b;
                break;
            }
            a = b;
            b = c;
        }

        if(c < b) min = c;
    }


    fclose(f);

    printf("the first local min = %lf", min);

}


void file19()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file18.dat";
    createFileDoubleRnd(0, 11, 10, file_name);
    showFileNumDouble(file_name);

    int count_elem = getFileLengthInBytes(file_name) / sizeof(double);

    int pos_local_max;
    for(int i = 0; i < count_elem; i++)
    {
        if(is_local_max_dbl(file_name, count_elem, i))
        {
            pos_local_max = i;
            break;
        }
    }

    puts("");

    printf("position of local maximum = %d\n", pos_local_max);
    printf("local maximum number = %lf", getDblElemFromFile(file_name, pos_local_max));
}


void file20()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file18.dat";
    createFileDoubleRnd(0, 11, 10, file_name);
    showFileNumDouble(file_name);

    int count_elem = getFileLengthInBytes(file_name) / sizeof(double);

    int cnt = 0;
    for(int i = 0; i < count_elem; i++)
    {
        if(is_local_min_dbl(file_name, count_elem, i) ||
                is_local_max_dbl(file_name, count_elem, i))
        {
            cnt++;
        }
    }

    puts("");

    printf("cnt = %d", cnt);
}


void file21()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file21.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    int count_elem = getFileLengthInBytes(file_name) / sizeof(double);

    char file_name_pos[] = "D:\\Lenguage C\\Lesson 13\\Files\\file21_pos.dat";
    createEmptyFile(file_name_pos);
    int pos_in_file = 0;
    for(int i = 0; i < count_elem; i++)
    {
        if(is_local_max_dbl(file_name, count_elem, i))
        {
            addIntElemInExistFile(file_name_pos, i, pos_in_file);
            pos_in_file++;
        }
    }

    int count_elem_pos = getFileLengthInBytes(file_name_pos) / sizeof(int);
    for(int i = 0; i < count_elem_pos-1; i++)
    {
        for(int j = i+1; j < count_elem_pos; j++)
        {
            int temp_i_pos = getIntElemFromFile(file_name_pos, i);
            int temp_j_pos = getIntElemFromFile(file_name_pos, j);
            double temp_i_dbl = getDblElemFromFile(file_name, temp_i_pos);
            double temp_j_dbl = getDblElemFromFile(file_name, temp_j_pos);

            if(temp_i_dbl > temp_j_dbl)
            {
                swapIntElemInFile(file_name_pos, i, j);
            }
        }
    }



    puts("");

    showFileNumInt(file_name_pos);
}


void file21a()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file21.dat";
    char file_name_pos[] = "D:\\Lenguage C\\Lesson 13\\Files\\file21_pos.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_pos, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_pos);
        fclose(f);
        exit(2);
    }

    int i = 0;
    double a, b, c;
    fread(&a, sizeof(a), 1, f);
    fread(&b, sizeof(b), 1, f);
    if(a < b)
    {
        fwrite(&i, sizeof(i), 1, g);
    }
    while(fread(&c, sizeof(c), 1, f))
    {
        i++;
        if(a > b && b < c)
        {
            fwrite(&i, sizeof(i), 1, g);
        }
        a = b;
        b = c;
    }
    if(c < a)
    {
        i++;
        fwrite(&i, sizeof(i), 1, g);
    }
    fclose(f);
    fclose(g);
    puts("");

    showFileNumDouble(file_name);
    showFileNumInt(file_name_pos);
}


void file21b()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file21.dat";
    char file_name_pos[] = "D:\\Lenguage C\\Lesson 13\\Files\\file21_pos.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    is_local_min_dbl_better(file_name, file_name_pos);

    puts("");

    showFileNumDouble(file_name);
    showFileNumInt(file_name_pos);
}


void file22()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file22.dat";
    char file_name_pos[] = "D:\\Lenguage C\\Lesson 13\\Files\\file22_pos.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    int count_elem = getFileLengthInBytes(file_name) / sizeof(double);

    int pos_in_file = 0;
    createEmptyFile(file_name_pos);
    for(int i = count_elem-1; i >= 0; i--)
    {
        if(is_local_min_dbl(file_name, count_elem, i) ||
                is_local_max_dbl(file_name, count_elem, i))
        {
            addIntElemInExistFile(file_name_pos, i, pos_in_file);
            pos_in_file++;
        }
    }

    puts("");

    showFileNumDouble(file_name);
    showFileNumInt(file_name_pos);
}


void file24()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file22.dat";
    char file_name_pos[] = "D:\\Lenguage C\\Lesson 13\\Files\\file23_pos.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_pos, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_pos);
        fclose(f);
        exit(2);
    }

    int cnt = 1;
    double a, b;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(double); //кількість елементів потрібна для перевірки останніх двух елементів.
    int counter_pos = 1; // номер ітерації циклу потрібно для перевірки останніх двух елементів.
    int flag_rise_or_fall = 0; // 0 флаг не задіяно, 1 зростання, 2 спадання.
    fread(&a, sizeof(a), 1, f);
    while(fread(&b, sizeof(b), 1, f))
    {
        if(a < b && flag_rise_or_fall != 2)
        {
            flag_rise_or_fall = 1;
            cnt++;
        }
        if(a > b && flag_rise_or_fall != 1)
        {
            flag_rise_or_fall = 2;
            cnt++;
        }


        if(a > b && flag_rise_or_fall == 1 && cnt > 1)
        {
            fwrite(&cnt, sizeof(cnt), 1, g);
            flag_rise_or_fall = 0;
            cnt = 1;
        }
        if(a < b && flag_rise_or_fall == 2 && cnt > 1)
        {
            fwrite(&cnt, sizeof(cnt), 1, g);
            flag_rise_or_fall = 0;
            cnt = 1;
        }

        //Перевірка 2-х останніх елементів на передостанній ітерації циклу.
        if(counter_pos == count_elem-2 && cnt < 2 && (a < b || a > b))
        {
            cnt++;
            fwrite(&cnt, sizeof(cnt), 1, g);
        }

        a = b;
        counter_pos++;
    }

    fclose(f);
    fclose(g);

    puts("");
    showFileNumInt(file_name_pos);
}


void file24a()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file18.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file18_2.dat";
    createFileDoubleRnd(0, 11, 10, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Can not open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Can not open file: %s\n", file_name_2);
        exit(2);
    }

    double a, b, c;
    fread(&a, sizeof(double), 1, f);
    fread(&b, sizeof(double), 1, f);
    int len = 1;
    while(fread(&c, sizeof(double), 1, f))
    {
        if(a > b && b < c || a < b && b > c)
        {
            len++;
            fwrite(&len, sizeof(int), 1, g);
            len = 1;
        }
        else
        {
            len++;
        }
        a = b;
        b = c;
    }
    if(c < b) len++;
    fwrite(&len, sizeof(int), 1, g);

    fclose(f);
    fclose(g);

    showFileNumInt(file_name_2);

}


void file25a()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file25a.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "r+b");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    double x;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(double); //кількість елементів потрібна для перевірки останніх двух елементів.
    for(int i = 0; i < count_elem; i++)
    {
        x = getDblElemFromFile(file_name, i);
        x = x * x;
        addDblElemInExistFile(file_name, x, i);
    }

    fclose(f);

    puts("");
    showFileNumDouble(file_name);
}


void file25b()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\file25_b1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file25_b2.dat";
    createFileDoubleRnd(0, 10, 10, file_name_1);
    showFileNumDouble(file_name_1);

    FILE* f = fopen(file_name_1, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name_1);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(2);
    }

    double x;
    while(fread(&x, sizeof(x), 1, f))
    {
        double x2 = x * x;
        fwrite(&x2, sizeof(x2), 1, g);
    }

    fclose(f);
    fclose(g);

    remove(file_name_1);

    if(rename(file_name_2, file_name_1) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumDouble(file_name_1);
}


void file26a()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file26.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    double x;
    double min, max;
    int i = 1;
    int pos_min = 0;
    int pos_max = 0;
    fread(&x, sizeof(x), 1, f);
    min = max = x;
    while(fread(&x, sizeof(x), 1, f))
    {
        if(x < min)
        {
            min = x;
            pos_min = i;
        }
        if(x > max)
        {
            max = x;
            pos_max = i;
        }

        i++;
    }

    fclose(f);

    addDblElemInExistFile(file_name, max, pos_min); //set
    addDblElemInExistFile(file_name, min, pos_max);

    puts("");
    showFileNumDouble(file_name);
}


void file26b()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file26.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file26_2.dat";
    createFileDoubleRnd(0, 10, 10, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    double x;
    double min, max;
    int i = 1;
    int pos_min = 0;
    int pos_max = 0;
    fread(&x, sizeof(x), 1, f);
    min = max = x;
    while(fread(&x, sizeof(x), 1, f))
    {
        if(x < min)
        {
            min = x;
            pos_min = i;
        }
        if(x > max)
        {
            max = x;
            pos_max = i;
        }

        i++;
    }
    //fclose(f);

//    f = fopen(file_name, "rb");
//    if(!f){
//        printf("Cant open file: %s\n", file_name);
//        exit(1);
//    }

    rewind(f);

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }
    int j = 0;
    while(fread(&x, sizeof(x), 1, f))
    {
        if(j == pos_min)
            fwrite(&max, sizeof(x), 1, g);
        else if(j == pos_max)
            fwrite(&min, sizeof(x), 1, g);
        else
            fwrite(&x, sizeof(x), 1, g);

        j++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumDouble(file_name);
}


void file27()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file27.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file27_2.dat";
    createFileIntRnd(0, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }
    int i = 0;
    int j = getFileLengthInBytes(file_name) / sizeof(int); //кількість елементів потрібна для перевірки останніх двух елементів.
    j -= 1;
    int x;
    while(i <= j)
    {
        fseek(f, sizeof(x) * i, SEEK_SET);
        fread(&x, sizeof(x), 1, f);
        fwrite(&x, sizeof(x), 1, g);

        if(i == j) break;

        fseek(f, sizeof(x) * j, SEEK_SET);
        fread(&x, sizeof(x), 1, f);
        fwrite(&x, sizeof(x), 1, g);

        i++;
        j--;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file28()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file28.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file28_2.dat";
    createFileDoubleRnd(0, 10, 11, file_name);
    showFileNumDouble(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    double temp;
    double a, b, c;
    fread(&a, sizeof(double), 1, f);
    fwrite(&a, sizeof(double), 1, g);//запис першого не заміненого елемента
    fread(&b, sizeof(double), 1, f);
    while(fread(&c, sizeof(double), 1, f))
    {
        temp = (a + b + c) / 3.0;
        fwrite(&temp, sizeof(double), 1, g);
        a = b;
        b = c;
    }

    fwrite(&c, sizeof(double), 1, g);//запис останього не заміненого елемента

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumDouble(file_name);
}


void file29()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file29.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file29_2.dat";
    createFileIntRnd(0, 10, 57, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int i = 0;
    int temp;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(int); //кількість елементів потрібна для перевірки останніх двух елементів.
    int j = (count_elem - 50) / 2;
    if(j < 0) j = 0;
    fseek(f, sizeof(temp) * j, SEEK_SET);
    while(fread(&temp, sizeof(temp), 1, f))
    {
        if(i >= 50) break;
        fwrite(&temp, sizeof(temp), 1, g);
        i++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file30()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file30.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file30_2.dat";
    createFileIntRnd(0, 10, 50, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int i = 0;
    int temp;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(int); //кількість елементів потрібна для перевірки останніх двух елементів.
    count_elem /= 2;
    while(fread(&temp, sizeof(temp), 1, f))
    {
        if(i >= count_elem) break;
        fwrite(&temp, sizeof(temp), 1, g);
        i++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file31()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file31.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file31_2.dat";
    createFileIntRnd(0, 10, 57, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int temp;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(int); //кількість елементів потрібна для перевірки останніх двух елементів.
    int j = count_elem - 50;
    if(j < 0) j = 0;
    fseek(f, sizeof(temp) * j, SEEK_SET);
    while(fread(&temp, sizeof(temp), 1, f))
    {
        fwrite(&temp, sizeof(temp), 1, g);
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file32()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file32.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file32_2.dat";
    createFileIntRnd(0, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int temp;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(int); //кількість елементів потрібна для перевірки останніх двух елементів.
    int j = count_elem / 2;
    fseek(f, sizeof(temp) * j, SEEK_SET);
    while(fread(&temp, sizeof(temp), 1, f))
    {
        fwrite(&temp, sizeof(temp), 1, g);
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file33()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file33.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file33_2.dat";
    createFileIntRnd(0, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }
    int i = 0;
    int temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {
        if(i % 2 != 0) //Не чотні числа записуємо
        {
            fwrite(&temp, sizeof(temp), 1, g);
        }
        i++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file34()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file34.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file34_2.dat";
    createFileIntRnd(-10, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {
        if(temp >= 0) //Видалення всих отрицательних чисел
        {
            fwrite(&temp, sizeof(temp), 1, g);
        }
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file35()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file35.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file35_2.dat";
    createFileIntRnd(0, 10, 45, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int temp = 0;
    int count_elem = getFileLengthInBytes(file_name) / sizeof(int); //кількість елементів потрібна для перевірки останніх двух елементів.
    int j = 50 - count_elem;
    if(j < 0) j = 0;
    for(int i = 0; i < j; i++)
    {
        fwrite(&temp, sizeof(temp), 1, g);
    }

    while(fread(&temp, sizeof(temp), 1, f))
    {
        fwrite(&temp, sizeof(temp), 1, g);
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file36()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file36.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file36_2.dat";
    createFileIntRnd(0, 10, 5, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int temp;
    for(int i = 0; i < 2; i++)
    {
        while(fread(&temp, sizeof(temp), 1, f))
        {
            fwrite(&temp, sizeof(temp), 1, g);
        }
        rewind(f);
    }


    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file37()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file37.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file37_2.dat";
    createFileIntRnd(0, 10, 5, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }

    int temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {
        fwrite(&temp, sizeof(temp), 1, g);
    }
    rewind(f);

    int count_elem = getFileLengthInBytes(file_name) / sizeof(int);
    for(int i = count_elem-1; i >= 0; i--)
    {
        fseek(f, sizeof(temp) * i, SEEK_SET);
        fread(&temp, sizeof(temp), 1, f);
        fwrite(&temp, sizeof(temp), 1, g);

    }


    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file38()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file38.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file38_2.dat";
    createFileIntRnd(0, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }
    int i = 0;
    int temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {
        fwrite(&temp, sizeof(temp), 1, g);

        if(i % 2 != 0) //Не чотні числа записуємо
        {
            fwrite(&temp, sizeof(temp), 1, g);
        }
        i++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file39()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file39.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file39_2.dat";
    createFileIntRnd(0, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }
    int i = 0;
    int temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {
        fwrite(&temp, sizeof(temp), 1, g);

        if(5 <= i && i <= 10) //Не чотні числа записуємо
        {
            fwrite(&temp, sizeof(temp), 1, g);
        }
        i++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void file40()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file40.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file40_2.dat";
    createFileIntRnd(0, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }
    int i = 0;
    int temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {

        if(i % 2 == 0) //Не чотні числа записуємо
        {
            int t = 0;
            fwrite(&t, sizeof(temp), 1, g);
            fwrite(&t, sizeof(temp), 1, g);
        }
        else
        {
            fwrite(&temp, sizeof(temp), 1, g);
        }
        i++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}



void file41()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file41.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file41_2.dat";
    createFileIntRnd(-10, 10, 10, file_name);
    showFileNumInt(file_name);

    FILE* f = fopen(file_name, "rb");
    if(!f)
    {
        printf("Cant open file: %s\n", file_name);
        exit(1);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        printf("Cant open file: %s\n", file_name_2);
        fclose(f);
        exit(1);
    }
    int i = 0;
    int temp;
    while(fread(&temp, sizeof(temp), 1, f))
    {

        if(temp > 0) //Не чотні числа записуємо
        {
            int t = 0;
            fwrite(&t, sizeof(temp), 1, g);
            fwrite(&t, sizeof(temp), 1, g);
            fwrite(&t, sizeof(temp), 1, g);
        }
        else
        {
            fwrite(&temp, sizeof(temp), 1, g);
        }
        i++;
    }

    fclose(f);
    fclose(g);

    remove(file_name);

    if(rename(file_name_2, file_name) != 0)
    {
        printf("Cant rename file: %s\n", file_name_2);
        exit(3);
    }

    puts("");
    showFileNumInt(file_name);
}


void test()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file41.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file41_2.dat";
    createFileIntRnd(-10, 10, 10, file_name);
    showFileNumInt(file_name);

    fileCopyFast(file_name, file_name_2);
    puts("");
    showFileNumInt(file_name_2);
}


void file42()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file42.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file42_2.dat";
    createFileIntRnd(-10, 10, 10, file_name);
    createFileIntRnd(-10, 10, 10, file_name_2);
    showFileNumInt(file_name);
    showFileNumInt(file_name_2);

    fileCopyFast(file_name, "tmp.tmp");
    fileCopyFast(file_name_2, file_name);
    fileCopyFast("tmp.tmp", file_name_2);

    remove("tmp.tmp");

    puts("");
    showFileNumInt(file_name);
    showFileNumInt(file_name_2);
}


void file43()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\file43.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file43_2.dat";
    createFileIntRnd(-10, 10, 10, file_name);
    showFileNumInt(file_name);

    fileCopyFast(file_name, file_name_2);


    puts("");
    showFileNumInt(file_name_2);
}


void file44()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\file44_1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file44_2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\file44_3.dat";
    createFileIntRnd(-10, 10, 10, file_name_1);
    createFileIntRnd(-10, 10, 20, file_name_2);
    createFileIntRnd(-10, 10, 16, file_name_3);
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);

    FILE* f = fopen(file_name_1, "rb");
    if(!f)
    {
        exit(1);
    }
    FILE* g = fopen(file_name_2, "rb");
    if(!f)
    {
        fclose(f);
        exit(2);
    }
    FILE* h = fopen(file_name_3, "rb");
    if(!f)
    {
        fclose(f);
        fclose(g);
        exit(2);
    }

    FILE** open_files[3] = {&f, &g, &h};

    char s[1024];
    int n1, n2, n3;
    n1 = n2 = n3 = 0;
    int* numbers[] = {&n1, &n2, &n3};
    for(int i = 0; i < 3; i++)
    {
        int n_buf;
        while(n_buf = fread(s, sizeof(char), sizeof(s), *open_files[i]))
        {
            *numbers[i] += n_buf;
        }
        n_buf = 0;
        fclose(*open_files[i]);
    }

    //шукаэмо мінімальний та максимальний розмір файлу
    int min_pos, max_pos;
    int min_size, max_size;
    min_size = max_size = *numbers[0];
    min_pos = max_pos = 0;
    for(int i = 0; i < 3; i++)
    {
        if(*numbers[i] < min_size)
        {
            min_size = *numbers[i];
            min_pos = i;
        }
        if(*numbers[i] > max_size)
        {
            max_size = *numbers[i];
            max_pos = i;
        }
        printf("n = %d\n", *numbers[i]);
    }

    printf("min_pos = %d\n\n", min_pos);
    printf("max_pos = %d\n", max_pos);

    char** files[3] = {file_name_1, file_name_2, file_name_3};

    fileCopyFast(files[min_pos], files[max_pos]);


    puts("");
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);
}


void file45()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\file44_1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\file44_2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\file44_3.dat";
    createFileIntRnd(-10, 10, 30, file_name_1);
    createFileIntRnd(-10, 10, 50, file_name_2);
    createFileIntRnd(-10, 10, 10, file_name_3);
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);

    int min, max;
    int pos_min, pos_max = 0;
    char** files[3] = {file_name_1, file_name_2, file_name_3};
    min = max = getFileLengthInBytes(files[0]);
    for(int i = 1; i < 3; i++)
    {
        int temp = getFileLengthInBytes(files[i]);
        if(temp < min)
        {
            min = temp;
            pos_min = i;
        }
        if(temp > max)
        {
            max = temp;
            pos_max = i;
        }
    }

    puts("");
    printf("pos min : %d\n", pos_min);
    printf("size min : %d\n", min);
    printf("pos max: %d\n", pos_max);
    printf("size max: %d\n", max);

    fileCopyFast(files[pos_max], files[pos_min]);

    puts("");
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);
}


void file46()
{
    //Створення файлу з рандомними числами
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\S3.dat";
    char file_name_4[] = "D:\\Lenguage C\\Lesson 13\\Files\\S4.dat";
    createFileIntRnd(-10, 10, 50, file_name_1);
    createFileIntRnd(-10, 10, 30, file_name_2);
    createFileIntRnd(-10, 10, 50, file_name_3);
    createFileIntRnd(-10, 10, 10, file_name_4);
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);
    showFileNumInt(file_name_4);
    puts("");

    int N;
    printf("N <= 4: ");
    scanf("%d", &N);

    char** files[4] = {file_name_1, file_name_2, file_name_3, file_name_4};
    for(int i = 0; i < N; i++)
    {
        fileCopyFastAddInEnd(files[i], file_name_0);
    }

    puts("");
    showFileNumInt(file_name_0);

    remove(file_name_0);
}


void file47()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";
    createFileIntRnd(-10, 10, 5, file_name_1);
    createFileIntRnd(-10, 10, 5, file_name_2);
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);

    fileCopyFast(file_name_2, "tmp.tmp");

    fileCopyFastAddInEnd(file_name_1, file_name_2);
    fileCopyFastAddInEnd("tmp.tmp", file_name_1);
    remove("tmp.tmp");

    puts("");
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    remove(file_name_1);
    remove(file_name_2);
}


void file48()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\SA.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\SB.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\SC.dat";
    char file_name_4[] = "D:\\Lenguage C\\Lesson 13\\Files\\SD.dat";
    createFileIntRnd(-10, 10, 5, file_name_1);
    createFileIntRnd(-10, 10, 5, file_name_2);
    createFileIntRnd(-10, 10, 5, file_name_3);
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);

    FILE* f = fopen(file_name_1, "rb");
    if(!f)
    {
        exit(1);
    }
    FILE* g = fopen(file_name_2, "rb");
    if(!g)
    {
        fclose(f);
        exit(2);
    }
    FILE* h = fopen(file_name_3, "rb");
    if(!h)
    {
        fclose(f);
        fclose(g);
        exit(3);
    }
    FILE* j = fopen(file_name_4, "ab");
    if(!j)
    {
        fclose(f);
        fclose(g);
        fclose(h);
        exit(4);
    }
    int x, y, z;
    while(fread(&x, sizeof(x), 1, f))
    {
        int buf = x;
        fwrite(&buf, sizeof(buf), 1, j);

        fread(&y, sizeof(y), 1, g);
        buf = y;
        fwrite(&buf, sizeof(buf), 1, j);

        fread(&z, sizeof(z), 1, h);
        buf = z;
        fwrite(&buf, sizeof(buf), 1, j);
    }

    fclose(f);
    fclose(g);
    fclose(h);
    fclose(j);

    puts("");
    showFileNumInt(file_name_4);

    remove(file_name_4);
}


void file49()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\SA.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\SB.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\SC.dat";
    char file_name_4[] = "D:\\Lenguage C\\Lesson 13\\Files\\SD.dat";
    char file_name_5[] = "D:\\Lenguage C\\Lesson 13\\Files\\SE.dat";
    createFileIntRnd(0, 10, 10, file_name_1);
    createFileIntRnd(0, 10, 5, file_name_2);
    createFileIntRnd(0, 10, 6, file_name_3);
    createFileIntRnd(0, 10, 9, file_name_4);
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);
    showFileNumInt(file_name_4);

    FILE* f = fopen(file_name_1, "rb");
    if(!f)
    {
        exit(1);
    }
    FILE* g = fopen(file_name_2, "rb");
    if(!g)
    {
        fclose(f);
        exit(2);
    }
    FILE* h = fopen(file_name_3, "rb");
    if(!h)
    {
        fclose(f);
        fclose(g);
        exit(3);
    }
    FILE* j = fopen(file_name_4, "rb");
    if(!j)
    {
        fclose(f);
        fclose(g);
        fclose(h);
        exit(4);
    }
    FILE* k = fopen(file_name_5, "ab");
    if(!k)
    {
        fclose(f);
        fclose(g);
        fclose(h);
        fclose(j);
        exit(5);
    }
    int x, y, z, u;
    while(
        fread(&x, sizeof(x), 1, f) &&
        fread(&y, sizeof(y), 1, g) &&
        fread(&z, sizeof(z), 1, h) &&
        fread(&u, sizeof(u), 1, j)
    )
    {
        int buf = x;
        fwrite(&buf, sizeof(buf), 1, k);

        buf = y;
        fwrite(&buf, sizeof(buf), 1, k);

        buf = z;
        fwrite(&buf, sizeof(buf), 1, k);

        buf = u;
        fwrite(&buf, sizeof(buf), 1, k);
    }

    fclose(f);
    fclose(g);
    fclose(h);
    fclose(j);
    fclose(k);

    puts("");
    showFileNumInt(file_name_5);

    remove(file_name_5);
}


void file50a()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\S3.dat";

    createFileDoubleRnd(0, 10, 10, file_name_1);
    createFileDoubleRnd(0, 10, 5, file_name_2);

    sortIncDblFile(file_name_1);
    sortIncDblFile(file_name_2);

    showFileNumDouble(file_name_1);
    showFileNumDouble(file_name_2);

    mergeTwoSortedIncDblFiles(file_name_1, file_name_2, file_name_3);

    showFileNumDouble(file_name_3);
}


void file50b()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\S3.dat";

    createFileDoubleRnd(0, 10, 10, file_name_1);
    createFileDoubleRnd(0, 10, 5, file_name_2);

    sortIncDblFileWithSeek(file_name_1);
    sortIncDblFileWithSeek(file_name_2);

    showFileNumDouble(file_name_1);
    showFileNumDouble(file_name_2);

    mergeTwoSortedIncDblFiles(file_name_1, file_name_2, file_name_3);

    showFileNumDouble(file_name_3);
}



void file51()
{
    //Створення файлу з рандомними числами
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\S3.dat";
    char file_name_4[] = "D:\\Lenguage C\\Lesson 13\\Files\\S4.dat";

    createFileDoubleRnd(0, 10, 10, file_name_1);
    createFileDoubleRnd(0, 10, 5, file_name_2);
    createFileDoubleRnd(0, 10, 7, file_name_3);

    sortIncDblFile(file_name_1);
    sortIncDblFile(file_name_2);
    sortIncDblFile(file_name_3);

    showFileNumDouble(file_name_1);
    showFileNumDouble(file_name_2);
    showFileNumDouble(file_name_3);

    mergeTwoSortedIncDblFiles(file_name_1, file_name_2, "tmp.tmp");
    mergeTwoSortedIncDblFiles("tmp.tmp", file_name_3, file_name_4);

    remove("tmp.tmp");

    revDblFile(file_name_4);

    puts("");
    showFileNumDouble(file_name_4);
}


void file52()
{
    //Створення файлу з рандомними числами
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\S3.dat";
    char file_name_4[] = "D:\\Lenguage C\\Lesson 13\\Files\\S4.dat";

    createFileIntRnd(0, 10, 2, file_name_1);
    createFileIntRnd(0, 10, 3, file_name_2);
    createFileIntRnd(0, 10, 4, file_name_3);
    createFileIntRnd(0, 10, 5, file_name_4);

    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);
    showFileNumInt(file_name_4);

    int N;
    printf("N <= 4: ");
    scanf("%d", &N);

    FILE* f = fopen(file_name_0, "ab");
    if(!f) exit(1);

    fwrite(&N, sizeof(N), 1, f);

    char** files[4] = {file_name_1, file_name_2, file_name_3, file_name_4};
    for(int i = 0; i < N; i++)
    {
        int length = getFileLengthInBytes(files[i]) / sizeof(int);
        fwrite(&length, sizeof(length), 1, f);
    }

    fclose(f);

    for(int i = 0; i < N; i++)
    {
        fileCopyFastAddInEnd(files[i], file_name_0);
    }

    puts("");
    showFileNumInt(file_name_0);
}


void file53()
{
    //Створення файлу з рандомними числами
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\S.dat";
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";

    file52();//функція для створення файлу-архіву

    int N;
    puts("");
    printf("N > 0: ");
    scanf("%d", &N);

    FILE* f = fopen(file_name_0, "rb");
    if(!f)
    {
        exit(1);
    }

    int number_of_files;
    fread(&number_of_files, sizeof(number_of_files), 1, f);
    if(N > number_of_files)
    {
        remove(file_name_0);
        fclose(f);
        exit(2);
    }

    FILE* h = fopen(file_name, "wb");
    if(!h)
    {
        fclose(f);
        exit(3);
    }

    int start_pos = 0;
    int finish_pos = 0;

    //розрахунок відступів для розархівування файлу
    for(int i = 1; i <= number_of_files; i++)
    {
        int temp;
        fread(&temp, sizeof(temp), 1, f);

        if(i < N) start_pos += temp;
        if(i == N) finish_pos = temp;
    }

    //переcування вказівника до початку читання файлу з архіву
    for(int i = 0; i < start_pos; i++)
    {
        int temp;
        fread(&temp, sizeof(temp), 1, f);
    }

    //запис заданих елементів з архіву в інший файл
    for(int i = 0; i < finish_pos; i++)
    {
        int temp_r, temp_w;
        fread(&temp_r, sizeof(temp_r), 1, f);
        temp_w = temp_r;
        fwrite(&temp_w, sizeof(temp_w), 1, h);
    }

    fclose(f);
    fclose(h);

    showFileNumInt(file_name);

    remove(file_name_0);
}


void file54()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\S.dat";
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";

    file52();//функція для створення файлу-архіву

    FILE* f = fopen(file_name_0, "rb");
    if(!f)
    {
        exit(1);
    }

    FILE* h = fopen(file_name, "wb");
    if(!h)
    {
        fclose(f);
        exit(2);
    }

    //кількість файлів в архіві
    int number_of_files;
    fread(&number_of_files, sizeof(number_of_files), 1, f);

    //розрахунок відступів для розархівування файлу
    int pos_el_fls[5] = {0};
    for(int i = 0; i < number_of_files; i++)
    {
        int temp;
        fread(&temp, sizeof(temp), 1, f);

        pos_el_fls[i] = temp;
    }

    //розрахунок відступів для розархівування файлу
    for(int i = 0; i < number_of_files; i++)
    {
        double ariph = 0;
        //запис заданих елементів з архіву в інший файл
        for(int j = 0; j < pos_el_fls[i]; j++)
        {
            int temp_r;
            fread(&temp_r, sizeof(temp_r), 1, f);
            ariph += temp_r;

        }
        double temp_w = ariph / pos_el_fls[i];
        fwrite(&temp_w, sizeof(temp_w), 1, h);
    }

    fclose(f);
    fclose(h);

    showFileNumDouble(file_name);

    remove(file_name_0);
}


void file55()
{
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";
    char file_name_3[] = "D:\\Lenguage C\\Lesson 13\\Files\\S3.dat";
    char file_name_4[] = "D:\\Lenguage C\\Lesson 13\\Files\\S4.dat";

    createFileIntRnd(0, 10, 2, file_name_1);
    createFileIntRnd(0, 10, 3, file_name_2);
    createFileIntRnd(0, 10, 4, file_name_3);
    createFileIntRnd(0, 10, 5, file_name_4);

    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
    showFileNumInt(file_name_3);
    showFileNumInt(file_name_4);

    int N;
    printf("N <= 4: ");
    scanf("%d", &N);

    FILE* h = fopen(file_name_0, "wb");
    if(!h)
    {
        exit(1);
    }

    char** files[4] = {file_name_1, file_name_2, file_name_3, file_name_4};
    for(int i = 0; i < N; i++)
    {
        int length = getFileLengthInBytes(files[i]) / sizeof(int);
        fwrite(&length, sizeof(length), 1, h);

        FILE* f = fopen(files[i], "rb");
        if(!f)
        {
            exit(1);
        }

        int temp_r, temp_w;
        while(fread(&temp_r, sizeof(temp_r), 1, f))
        {
            temp_w = temp_r;
            fwrite(&temp_w, sizeof(temp_w), 1, h);
        }

        fclose(f);
    }

    fclose(h);

    showFileNumInt(file_name_0);
}


void file56()
{
    char file_name[] = "D:\\Lenguage C\\Lesson 13\\Files\\S.dat";
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";

    file55();

    int N;
    printf("\nN = "); scanf("%d", &N);

    FILE* f = fopen(file_name_0, "rb");
    if(!f)
    {
        exit(1);
    }

    FILE* h = fopen(file_name, "wb");
    if(!h)
    {
        fclose(f);
        exit(2);
    }

    for(int i = 1; i <= N; i++)
    {
        int length;
        fread(&length, sizeof(length), 1, f);

        for(int j = 0; j < length; j++)
        {
            int check_N;
            int temp_r, temp_w;
            check_N = fread(&temp_r, sizeof(temp_r), 1, f);

            if(!check_N) //якщо N більше за кількість файлів в архіві
            {
                fclose(f);
                fclose(h);
                remove(file_name);
                exit(3);
            }

            if(i == N)
            {
                temp_w = temp_r;
                fwrite(&temp_w, sizeof(temp_w), 1, h);
            }
        }
    }

    fclose(f);
    fclose(h);

    showFileNumInt(file_name);
}


void file57a()
{
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";

    file55();

    FILE* f = fopen(file_name_0, "rb");
    if(!f)
    {
        exit(1);
    }

    FILE* h = fopen(file_name_1, "wb");
    if(!h)
    {
        fclose(f);
        exit(2);
    }

    FILE* g = fopen(file_name_2, "wb");
    if(!g)
    {
        fclose(f);
        fclose(h);
        exit(2);
    }

    int length;
    while(fread(&length, sizeof(length), 1, f))
    {
        int temp_r, temp_w;
        temp_w = length;
        fwrite(&temp_w, sizeof(temp_w), 1, h);

        int i = 0;
        while(i < length)
        {
            fread(&temp_r, sizeof(temp_r), 1, f);
            temp_w = temp_r;
            fwrite(&temp_w, sizeof(temp_w), 1, g);

            i++;
        }
    }

    fclose(f);
    fclose(h);
    fclose(g);

    puts("");
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
}


void test01()
{
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\t1.dat";

    //createNewEmtyFile(file_name_1);
    //createFileIntRnd(0, 10, 1, file_name_0);
    //addToEndIntFileToArchive(file_name_0, file_name_1);
    //remove(file_name_1);
    int i = getAmountOfIntFilesArchive(file_name_1);
    printf("n = %d\n", i);

    //getIntFileFromArchive(file_name_1, 3, file_name_0);

    //deleteIntFileFromArchive(file_name_1, 0);

    //insertIntFileToArchive(file_name_1, 0, file_name_0);

    puts("");
    showFileNumInt(file_name_0);
    showFileNumInt(file_name_1);
}


void file57b()
{
    char file_name_0[] = "D:\\Lenguage C\\Lesson 13\\Files\\S0.dat";
    char file_name_1[] = "D:\\Lenguage C\\Lesson 13\\Files\\S1.dat";
    char file_name_2[] = "D:\\Lenguage C\\Lesson 13\\Files\\S2.dat";

    file55();

    createEmptyFile(file_name_1);
    createEmptyFile(file_name_2);

    int amount_files = getAmountOfIntFilesArchive(file_name_0);

    for(int i = 0; i < amount_files; i++)
    {
        getIntFileFromArchive(file_name_0, i, "tmp.tmp");

        int amount_elem = getFileLengthInBytes("tmp.tmp")/sizeof(int);

        int begin_elem = getIntElemFromFile("tmp.tmp", 0);
        int last_elem = getIntElemFromFile("tmp.tmp", amount_elem-1);

        addToEndIntElemToFile(file_name_1, begin_elem);
        addToEndIntElemToFile(file_name_2, last_elem);
    }

    puts("");
    showFileNumInt(file_name_1);
    showFileNumInt(file_name_2);
}


void file57c()
{
    char arh_file_name[50] = "arh.dat";

    createA55(2, arh_file_name);
    showFileNumInt(arh_file_name);

    /*--------------------------------------*/

    int N = getAmountOfIntFilesArchive(arh_file_name);

    char fa[50] = "file57a.dat";
    char fb[50] = "file57b.dat";

    FILE* f1 = fopen(fa, "wb");
    FILE* f2 = fopen(fb, "wb");

    for(int i = 0; i < N; i++)
    {
        char tmp_file[20] = "tmp.tmp";
        getIntFileFromArchive(arh_file_name, i, tmp_file);
        int len = getFileLengthInBytes(tmp_file) / sizeof(int);
        int first = getIntElemFromFile(tmp_file, 0);
        int last = getIntElemFromFile(tmp_file, len-1);
        fwrite(&first, sizeof(first), 1, f1);
        fwrite( &last, sizeof(last), 1, f2);
    }

    fclose(f1);
    fclose(f2);

    showFileNumInt(fa);
    showFileNumInt(fb);

    remove(arh_file_name);
    remove(fa);
    remove(fb);
}


void file58()
{
    char fname[] = "file58.txt";
    int n;
    printf(" n = "); scanf("%d", &n);
    puts("");

    createCharFile(fname, n, 32, 123);
    showCharFile(fname);

    FILE* f = fopen(fname, "rb");
    FILE* g = fopen("tmp.tmp", "wb");

    int c;
    while((c = fgetc(f)) != EOF)
    {
        if(is_Space(c))
        {
            break;
        }
        fputc(c, g);
    }

    fclose(f);
    fclose(g);

    fileCopyFast("tmp.tmp", fname);

    showCharFile(fname);

    remove(fname);
}


void file59()
{
    char fname[] = "file59.txt";
    int n;
    printf(" n = "); scanf("%d", &n);
    puts("");

    createCharFile(fname, n, 32, 123);
    showCharFile(fname);

    FILE* f = fopen(fname, "rb");

    int c;
    int i = 0;
    int last_sp;
    while((c = fgetc(f)) != EOF)
    {
        if(is_Space(c))
        {
            last_sp = i;
        }
        i++;
    }

    rewind(f);
    FILE* g = fopen("tmp.tmp", "wb");

    int c2;
    int j = 0;
    while((c2 = fgetc(f)) != EOF)
    {
        if(j >= last_sp)
        {
            break;
        }
        fputc(c2, g);
        j++;
    }

    fclose(f);
    fclose(g);

    fileCopyFast("tmp.tmp", fname);

    showCharFile(fname);

    remove(fname);
}


void file60()
{
    char fname[] = "file60.txt";
    int n;
    printf(" n = "); scanf("%d", &n);
    puts("");

    createCharFile(fname, n, 32, 123);
    showCharFile(fname);

    FILE* f = fopen(fname, "rb");

    int c;
    int i = 0;
    int last_sp;
    while((c = fgetc(f)) != EOF)
    {
        if(is_Space(c))
        {
            last_sp = i;
            break;
        }
        i++;
    }

    rewind(f);
    FILE* g = fopen("tmp.tmp", "wb");

    int c2;
    int j = 0;
    while((c2 = fgetc(f)) != EOF)
    {
        if(j >= last_sp)
        {
            break;
        }
        fputc(c2, g);
        j++;
    }

    fclose(f);
    fclose(g);

    fileCopyFast("tmp.tmp", fname);

    showCharFile(fname);

    remove(fname);
}


void file61()
{
    char fname[] = "file61.txt";
    int n;
    printf(" n = "); scanf("%d", &n);
    puts("");

    createCharFile(fname, n, 32, 123);
    showCharFile(fname);

    FILE* f = fopen(fname, "rb");

    int c;
    int i = 0;
    int last_sp;
    while((c = fgetc(f)) != EOF)
    {
        if(is_Space(c))
        {
            last_sp = i;
        }
        i++;
    }

    rewind(f);
    FILE* g = fopen("tmp.tmp", "wb");

    int c2;
    int j = 0;
    while((c2 = fgetc(f)) != EOF)
    {
        if(j > last_sp)
        {
            fputc(c2, g);
        }
        j++;
    }

    fclose(f);
    fclose(g);

    fileCopyFast("tmp.tmp", fname);

    showCharFile(fname);

    remove(fname);
}


void file62()
{
    char fname[] = "file62.txt";
    int n;
    printf(" n = "); scanf("%d", &n);
    puts("");

    createCharFile(fname, n, 32, 123);
    showCharFile(fname);

    sortIncIntFileSymbolsWithSeek(fname);

    showCharFile(fname);

    remove(fname);
}


void file63()
{
    char fname[] = "file63.txt";
    char fname_s[] = "file63s.txt";
    char fname_c[] = "file63c.txt";

    createFileOfStringsWithRandLength(fname, 32, 123, 5, 10);
    showFileOfStrings(fname);
    puts("");

    int k;
    printf("K = "); scanf("%d" ,&k);

    FILE* f = fopen(fname, "rb");
    FILE* g = fopen(fname_s, "wb");
    FILE* h = fopen(fname_c, "wb");

    char str[40] = {0};
    while(fread(str, sizeof(str), 1, f))
    {
        char tmp_str[40];
        strncpy(tmp_str, str, k); tmp_str[k] = 0;
        fwrite(tmp_str, sizeof(tmp_str), 1, g);

        char c = 32;
        if(strlen(str) > k) c = str[k];
        fputc(c, h);
    }

    fclose(f);
    fclose(g);
    fclose(h);

    puts("");
    showFileOfStrings(fname_s);
    showFileOfChar(fname_c);

    remove(fname);
    remove(fname_s);
    //remove(fname_c);
}


void file64()
{
    char fname[] = "file64.txt";
    char fname_2[] = "file64_2.txt";

    createFileOfStringsWithRandLength(fname, 32, 123, 10, 10);
    showFileOfStrings(fname);
    puts("");

    createEmptyFile(fname_2);
    fileCopyFast(fname, fname_2);

    sortIncStringByLengthFileWithSeek(fname_2);

    showFileOfStrings(fname_2);

    remove(fname);
    remove(fname_2);
}


void file65()
{
    char fname[] = "file65.txt";
    char fname_2[] = "file65_2.txt";

    createFileOfStringsWithRandLength(fname, 32, 123, 10, 10);
    showFileOfStrings(fname);
    puts("");

    createEmptyFile(fname_2);
    fileCopyFast(fname, fname_2);

    sortIncStringByLengthFileWithSeek(fname_2);

    revStringFile(fname_2);

    showFileOfStrings(fname_2);

    remove(fname);
    remove(fname_2);
}


void file66()
{
    char fname[] = "file66.txt";
    char fname_2[] = "file66_2.txt";

    createFileOfStringsWithRandLength(fname, 32, 123, 10, 10);
    showFileOfStrings(fname);
    puts("");

    createEmptyFile(fname_2);
    fileCopyFast(fname, fname_2);

    sortIncStringFileWithSeek(fname_2);

    showFileOfStrings(fname_2);

    remove(fname);
    remove(fname_2);
}


void file67()
{
    char fname[] = "file67.txt";
    char fname_a[] = "file67_a.txt";
    char fname_b[] = "file67_b.txt";

    createFileOfRandData(fname, 10, 1990, 2000);

    showFileOfStrings(fname);
    puts("");

    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE *g = fopen(fname_a, "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    FILE *h = fopen(fname_b, "wb");
    if(!h)
    {
        printf("File can not open for write");
        fclose(f);
        fclose(g);
        exit(3);
    }


    char buf[40];
    while(fread(buf, sizeof(buf), 1, f))
    {
    char data[40];
    char* word = strtok(buf, "//");

    int len = strlen(word);
    strcpy(data, word);
    data[len] = 0;
    fwrite(data, sizeof(data), 1, g);

    word = strtok(NULL, "//");

    len = strlen(word);
    strcpy(data, word);
    data[len] = 0;
    fwrite(data, sizeof(data), 1, h);
    }

    fclose(f);
    fclose(g);
    fclose(h);

    showFileOfStrings(fname_a);
    puts("");
    showFileOfStrings(fname_b);

    remove(fname_a);
    remove(fname_b);
}


void file68()
{
    char fname[] = "file68.txt";
    char fname_a[] = "file68_a.txt";
    char fname_b[] = "file68_b.txt";

    createFileOfRandData(fname, 10, 1990, 2000);

    showFileOfStrings(fname);
    puts("");

    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE *g = fopen(fname_a, "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    FILE *h = fopen(fname_b, "wb");
    if(!h)
    {
        printf("File can not open for write");
        fclose(f);
        fclose(g);
        exit(3);
    }

    char buf[40];
    while(fread(buf, sizeof(buf), 1, f))
    {
        int a = getMonth(buf);
        int b = getYear(buf);

        fwrite(&a, sizeof(a), 1, g);
        fwrite(&b, sizeof(b), 1, h);
    }

    fclose(f);
    fclose(g);
    fclose(h);

    showFileNumInt(fname_a);
    showFileNumInt(fname_b);

    remove(fname);
    remove(fname_a);
    remove(fname_b);
}


void file69()
{
    char fname[] = "file69.txt";
    char fname_a[] = "file69_a.txt";

    createFileOfRandData(fname, 10, 1990, 2000);

    showFileOfStrings(fname);
    puts("");

    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE *g = fopen(fname_a, "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    char buf[40];
    while(fread(buf, sizeof(buf), 1, f))
    {
        int month = getMonth(buf);
        if(6 <= month && month <= 8)
        fwrite(&buf, sizeof(buf), 1, g);
    }

    fclose(f);
    fclose(g);

    showFileOfStrings(fname_a);

    remove(fname);
    remove(fname_a);
}


void file70()
{
    char fname[] = "file70.txt";
    char fname_winter[] = "file70_a.txt";

    createFileOfRandData(fname, 10, 1990, 2000);

    showFileOfStrings(fname);
    puts("");

    char copy_f[] = "tmp.tmp";
    fileCopyFast(fname, copy_f);

    revStringFile(copy_f);

    FILE *f = fopen(copy_f, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE *g = fopen(fname_winter, "wb");
    if(!g)
    {
        printf("File can not open for write");
        fclose(f);
        exit(2);
    }

    char buf[40];
    while(fread(buf, sizeof(buf), 1, f))
    {
        int month = getMonth(buf);
        if(month == 12 || month == 1 || month == 2)
        fwrite(&buf, sizeof(buf), 1, g);
    }

    fclose(f);
    fclose(g);

    showFileOfStrings(fname_winter);

    remove(fname);
    remove(fname_winter);
}


void file71()
{
    char fname[] = "file71.txt";

    createFileOfRandData(fname, 10, 1990, 2000);

    showFileOfStrings(fname);
    puts("");

    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int i = 0;
    int min = 0;
    int pos = -1;
    char buf[40];
    while(fread(buf, sizeof(buf), 1, f))
    {
        int month = getMonth(buf);
        if(3 <= month && month <=5)
        {
            int temp = month*100 + getDay(buf);

            if(min == 0) //записуємо саму першу весінню дату для подальшого порівняння
            {
                min = temp;
                pos = i;
            }

            if(temp < min) //шукаэмо рядок з самою ранньою весною
            {
                min = temp;
                pos = i;
            }
        }

        i++;
    }

    if(pos != -1)
    {
        rewind(f);
        fseek(f, sizeof(buf) * pos, SEEK_CUR);
        fread(buf, sizeof(buf), 1, f);
        puts(buf);
    }
    else
    {
        puts("");
    }

    fclose(f);

    remove(fname);
}


void file72()
{
    char fname[] = "file72.txt";

    createFileOfRandData(fname, 10, 1990, 2000);

    showFileOfStrings(fname);
    puts("");

    FILE *f = fopen(fname, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    int i = 0;
    int max = 0;
    int pos = -1;
    char buf[40];
    while(fread(buf, sizeof(buf), 1, f))
    {
        int month = getMonth(buf);
        if(9 <= month && month <= 11)
        {
            int temp = month*100 + getDay(buf);
            if(temp > max) //шукаэмо рядок з самою пізноьою осінню
            {
                max = temp;
                pos = i;
            }
        }

        i++;
    }

    if(pos != -1)
    {
        rewind(f);
        fseek(f, sizeof(buf) * pos, SEEK_CUR);
        fread(buf, sizeof(buf), 1, f);
        puts(buf);
    }
    else
    {
        puts("");
    }

    fclose(f);

    remove(fname);
}


void file73a()
{
    char fname[] = "file73a.txt";

    createFileOfRandData(fname, 10, 1990, 2000);

    showFileOfStrings(fname);
    puts("");

    sortDecStringsFileOfDatasWithSeek(fname);

    showFileOfStrings(fname);

    remove(fname);
}


void file73b()
{
    char fname[] = "file73b.txt";

    createFileOfRandData2(fname, 10, 1990, 2025);

    showFileOfDateLn(fname);
    puts("");

    sortDecStringsFileOfDatasWithSeek2(fname);

    showFileOfDateLn(fname);

    remove(fname);
}


void file74()
{
    char fname[] = "file74.txt";

    int m;
    printf("m = "); scanf("%d", &m);

    createFileOfDblRndMatr(fname, m, m, -5, 5);

    showFileOfDblMatr(fname);

    int i, j;
    printf("i = "); scanf("%d", &i);
    printf("j = "); scanf("%d", &j);

    double x = getElemOfFileMatr(fname, i, j);
    printf("elem = %2.1lf", x);

    remove(fname);
}


void file75()
{
    char fname[] = "file75.txt";

    int m;
    printf("m = "); scanf("%d", &m);

    createFileOfDblRndMatr(fname, m, m, -5, 5);

    showFileOfDblMatr(fname);

    transpositionFileOfDblMatr(fname);

    showFileOfDblMatr(fname);

    remove(fname);
}


void file76()
{
    char Sa[] = "file76_Sa.txt";
    char Sb[] = "file76_Sb.txt";
    char Sc[] = "file76_Sc.txt";

    int m;
    printf("m = "); scanf("%d", &m);

    createFileOfDblRndMatr(Sa, m, m, 0, 5);
    createFileOfDblRndMatr(Sb, m, m, 0, 5);

    printf("\n");
    printf("Matr A:");
    showFileOfDblMatr(Sa);
    printf("Matr B:");
    showFileOfDblMatr(Sb);

    FILE *f = fopen(Sa, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE *g = fopen(Sb, "rb");
    if(!g)
    {
        printf("File can not open for read");
        fclose(f);
        exit(1);
    }

    FILE *h = fopen(Sc, "wb");
    if(!h)
    {
        printf("File can not open for write");
        fclose(f);
        fclose(g);
        exit(1);
    }

    int am, an;
    fread(&am, sizeof(am), 1, f);
    fread(&an, sizeof(an), 1, f);
    int bn, bp;
    fread(&bn, sizeof(bn), 1, g);
    fread(&bp, sizeof(bp), 1, g);

    if(am != bp || an != bn || am != an)
    {
        fclose(f);
        fclose(g);
        fclose(h);

        remove(Sa);
        remove(Sb);
        remove(Sc);

        exit(1);
    }

    fwrite(&am, sizeof(am), 1, h);
    fwrite(&bp, sizeof(bp), 1, h);

    for(int k = 0; k < an; k++)
    {
        for(int i = 0; i < am; i++)
        {
            double sum = 0;
            for(int j = 0; j < bp; j++)
            {
                double a = getElemOfFileMatr(Sa, k, j);
                double b = getElemOfFileMatr(Sb, j, i);
                sum += a * b;
            }
            fwrite(&sum, sizeof(sum), 1, h);
        }
    }

    fclose(f);
    fclose(g);
    fclose(h);

    printf("Matr C:");
    showFileOfDblMatr(Sc);

    remove(Sa);
    remove(Sb);
    remove(Sc);
}


void file77()
{
    char fname[] = "file74.txt";

    int m, n;
    printf("m = "); scanf("%d", &m);
    printf("n = "); scanf("%d", &n);

    createFileOfDblRndMatr(fname, m, n, -5, 5);

    showFileOfDblMatr(fname);

    int i, j;
    printf("i = "); scanf("%d", &i);
    printf("j = "); scanf("%d", &j);

    double x = getElemOfFileMatr(fname, i, j);
    printf("elem = %2.1lf", x);

    remove(fname);
}


void file78()//останні рядки заповнює нулями
{
    char fname[] = "file78.txt";
    char fname_n[] = "file78_n.txt";

    int m, n;
    printf("m = "); scanf("%d", &m);
    printf("n = "); scanf("%d", &n);

    createFileOfDblRndMatr(fname, m, n, -5, 5);

    showFileOfDblMatr(fname);

    fileCopyFast(fname, fname_n);

    transpositionFileOfDblMatr(fname_n);

    showFileOfDblMatr(fname_n);

    remove(fname);
    remove(fname_n);
}


void file79()
{
    char Sa[] = "file76_Sa.txt";
    char Sb[] = "file76_Sb.txt";
    char Sc[] = "file76_Sc.txt";

    int m1, n1, m2, n2;
    printf("m1 = "); scanf("%d", &m1);
    printf("n1 = "); scanf("%d", &n1);
    printf("m2 = "); scanf("%d", &m2);
    printf("n2 = "); scanf("%d", &n2);

    createFileOfDblRndMatr(Sa, m1, n1, 0, 5);
    createFileOfDblRndMatr(Sb, m2, n2, 0, 5);

    printf("\n");
    printf("Matr A:");
    showFileOfDblMatr(Sa);
    printf("Matr B:");
    showFileOfDblMatr(Sb);

    FILE *f = fopen(Sa, "rb");
    if(!f)
    {
        printf("File can not open for read");
        exit(1);
    }

    FILE *g = fopen(Sb, "rb");
    if(!g)
    {
        printf("File can not open for read");
        fclose(f);
        exit(1);
    }

    FILE *h = fopen(Sc, "wb");
    if(!h)
    {
        printf("File can not open for write");
        fclose(f);
        fclose(g);
        exit(1);
    }

    int am, an;
    fread(&am, sizeof(am), 1, f);
    fread(&an, sizeof(an), 1, f);
    int bn, bp;
    fread(&bn, sizeof(bn), 1, g);
    fread(&bp, sizeof(bp), 1, g);

    if(an != bn)
    {
        fclose(f);
        fclose(g);
        fclose(h);

        remove(Sa);
        remove(Sb);
        remove(Sc);

        exit(1);
    }

    fwrite(&am, sizeof(am), 1, h);
    fwrite(&bp, sizeof(bp), 1, h);

    for(int k = 0; k < an; k++)
    {
        for(int i = 0; i < am; i++)
        {
            double sum = 0;
            for(int j = 0; j < bp; j++)
            {
                double a = getElemOfFileMatr(Sa, k, j);
                double b = getElemOfFileMatr(Sb, j, i);
                sum += a * b;
            }
            fwrite(&sum, sizeof(sum), 1, h);
        }
    }

    fclose(f);
    fclose(g);
    fclose(h);

    printf("Matr C:");
    showFileOfDblMatr(Sc);

    remove(Sa);
    remove(Sb);
    remove(Sc);
}


void file80()
{
    char Sa[] = "file80_Sa.txt";
    char Sb[] = "file80_Sb.txt";

    int m, n;
    printf("m = "); scanf("%d", &m);
    printf("n = "); scanf("%d", &n);

    createFileWithHighTriagleMatr(Sa, m, n, 0, 5);

    showFileOfDblMatr(Sa);

    FILE *f = fopen(Sb, "wb");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    for(int d = 0; d < n; d++)
    {
        int i = 0;
        int j = 0;

        if(d > 0) j = d;
        if(d < 0) i = -d;

        while(i < m && j < n)
        {
            double x = getElemOfFileMatr(Sa, i, j);
            fwrite(&x, sizeof(x), 1, f);

            i++;
            j++;
        }
    }

    fclose(f);

    showFileNumDouble(Sb);

    remove(Sa);
    remove(Sb);
}


void file81()
{
    char Sa[] = "file81_Sa.txt";
    char Sb[] = "file81_Sb.txt";

    int m, n;
    printf("m = "); scanf("%d", &m);
    printf("n = "); scanf("%d", &n);

    createFileWithLowTriagleMatr(Sa, m, n, 0, 5);

    showFileOfDblMatr(Sa);

    FILE *f = fopen(Sb, "wb");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    for(int d = 0; d > -m; d--)
    {
        int i = 0;
        int j = 0;

        if(d > 0) j = d;
        if(d < 0) i = -d;

        while(i < m && j < n)
        {
            double x = getElemOfFileMatr(Sa, i, j);
            fwrite(&x, sizeof(x), 1, f);

            i++;
            j++;
        }
    }

    fclose(f);

    showFileNumDouble(Sb);

    remove(Sa);
    remove(Sb);
}


void file82()
{
    char Sa[] = "file81_Sa.txt";
    char Sb[] = "file81_Sb.txt";

    int m, n;
    printf("m = "); scanf("%d", &m);
    printf("n = "); scanf("%d", &n);

    createFileWithThreeDiagMatr(Sa, m, n, 0, 5);

    showFileOfDblMatr(Sa);

    FILE *f = fopen(Sb, "wb");
    if(!f)
    {
        printf("File can not open for write");
        exit(1);
    }

    for(int d = 1; d > -2; d--)
    {
        int i = 0;
        int j = 0;

        if(d > 0) j = d;
        if(d < 0) i = -d;

        while(i < m && j < n)
        {
            double x = getElemOfFileMatr(Sa, i, j);
            fwrite(&x, sizeof(x), 1, f);

            i++;
            j++;
        }
    }

    fclose(f);

    showFileNumDouble(Sb);

    remove(Sa);
    remove(Sb);
}



int main()
{
    system("chcp 1251>>NULL");
    srand(time(NULL));
    int t = rand() % 200 + 1;
    printf("\n[%d]\n\n",t);
    srand(t);

    file76();

    return 0;
}




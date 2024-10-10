#include "string_plus.h"
#include<string.h>


int is_space(char c)
{
    return 0 <= c && c <= 32;
}


void remove_symbol(char *s, int pos)
{
    int lenth = strlen(s);
    for(int i = pos; i < lenth; i++)
    {
        s[i] = s[i + 1];
    }
}


void left_trim(char *s)
{
    int lenth = strlen(s);
    while(lenth > 0 && is_space(s[0]))
    {
        remove_symbol(s, 0);
        lenth--;
    }
}


void right_trim(char *s)
{
    int lenth = strlen(s);
    while(lenth > 0 && is_space(s[lenth - 1]))
    {
        remove_symbol(s, lenth - 1);
        lenth--;
    }
}


void all_trim(char *s)
{
    left_trim(s);
    right_trim(s);
}


void normalize(char *s)
{
    all_trim(s);
    int lenth = strlen(s);
    for(int i = lenth - 1; i > 0; i--)
    {
        if(is_space(s[i]) && is_space(s[i - 1]))
        {
            remove_symbol(s, i);
        }
    }
}


void character_insertion(char *s)
{
    int pos;
    char c;
    printf("Enter symbol  ");
    c = getchar();
    printf("\nEnter position ");
    scanf("%d", &pos);

    int lenth = strlen(s);
    for(int i = lenth; pos - 1 <= i; i--)
    {
        s[i + 1] = s[i];
    }
    s[pos - 1] = c;

    printf("\n");

}

#include "mystring.h"

int isDigit(char c)
{
    return '0' <= c && c <='9';
}

int isUppercase(char c)
{
    if(('A' <= c && c <='Z')) return 1;

    if('À' <= c && c <='ß') return 2;

    if('¥' == c || 'ª' == c || '¯' == c || '²' == c)
    return (unsigned char)c;

    return 0;
}

int isLowercase(char c)
{
    if('a' <= c && c <='z') return 1;

    if('à' <= c && c <='ÿ') return 2;

    if('´' == c || 'º' == c || '¿' == c || '³' == c)
    return (unsigned char)c;

    return 0;
}


int indexOf(const char* s, char c)
{
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == c) return i;
    }
    return -1;
}


unsigned char toLower(char c)
{
    char abc[] = "abcdefghijklmnopqrstuvwxyzàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";

    int pos = indexOf(ABC, c);
    if(pos!= -1) return abc[pos];
    return c;





    /*
    if(isUppercase(c) == 1) return c + 32;

    if(isUppercase(c) == 2) return c + 32;

    if('¥' == c) return c + 15;
    if('ª' == c) return c + 16;
    if('¯' == c) return c + 16;
    if('²' == c) return c + 1;

    return c;
    */
}


unsigned char toUpper(char c)
{
    char abc[] = "abcdefghijklmnopqrstuvwxyzàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";

    int pos = indexOf(abc, c);
    if(pos!= -1) return ABC[pos];
    return c;





    /*
    if(isUppercase(c) == 1) return c + 32;

    if(isUppercase(c) == 2) return c + 32;

    if('¥' == c) return c + 15;
    if('ª' == c) return c + 16;
    if('¯' == c) return c + 16;
    if('²' == c) return c + 1;

    return c;
    */
}

/*
unsigned char toUpper(char c)
{
    if(isLowercase(c) == 1) return c - 32;

    if(isLowercase(c) == 2) return c - 32;

    if('´' == c) return c - 15;
    if('º' == c) return c - 16;
    if('¿' == c) return c - 16;
    if('³' == c) return c - 1;

    return c;
}
*/

int convertCharacterToDigit(char c)
{
    if(isDigit(c)) return c - 48;

    return c;
}


int convertStringToNumber(char s[])
{
    int d = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        d = d * 10;
        d = d + convertCharacterToDigit(s[i]);
        if(d < 0) return -1;
    }

    return d;
}


int isNumberIntegerInString(char s[])
{
    int ok = 1;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(!isDigit(s[i])) return 0;
    }
    return 1;
}


int isNumberFractionalInString(char s[])
{
    int point = 0;
    int len = strlen(s);
    if(!(isDigit(s[0]) && isDigit(s[len-1]))) return 0;
    for(int i = 1; i < len-1; i++)
    {
       if(s[i] == '.') point++;
       if(isDigit(s[i]) == 0 && s[i] != '.') return 0;
    }
    if(point == 1) return 1;
    else return 0;
}

int isNumberFractioOrInteger(char s[])
{
    if(isNumberFractionalInString(s) == 0 && isNumberIntegerInString(s) == 0) return 0;

    if(isNumberIntegerInString(s)) return 1;

    if(isNumberFractionalInString(s)) return 2;
}


int getAmountOfDigitsInNumber(int  number)
{
    if(number == 0) return 1;
    int count = 0;
    while(number > 0)
    {
        number /= 10;
        count++;
    }

    return count;
}


char convertDigitToCharacter(int d)
{
    return d + 48;
}


void convertNumberToString(int number, char s[])
{
    if(number == 0) s[0] = '0';

    int amount = getAmountOfDigitsInNumber(number);
    s[amount--] = '\0';

    int i = 0;
    while(number > 0)
    {
        s[amount--] = convertDigitToCharacter(number % 10);
        number = number / 10;
    }
}


void convertReverseNumberToString(int number, char s[])
{
    int i = 0;
    if(number == 0) s[i++] = '0';
    while(number > 0)
    {
        s[i++] = convertDigitToCharacter(number % 10);
        number = number / 10;
    }

    s[i] = '\0';
}


int sunOfDigitsInString(char s[])
{
    if(!isNumberIntegerInString(s)) return -1;

    int sum = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        sum += convertCharacterToDigit(s[i]);
    }

    return sum;
}


int plusOrMinusMathOperation(char s[])
{
    //ïåğåâ³ğêà êîğåêòíîãî ââåäåííÿ
    int ok = 1;
    int second_ok = 0;
    int len = strlen(s);
    if(!(isDigit(s[0]) && isDigit(s[len-1]))) ok = 0;
    for(int i = 1; i < len-1; i++)
    {
        if(s[i] == '+' || s[i] == '-') second_ok = 1;
        if(!(isDigit(s[i]) || '+' == s[i] || '-' == s[i])) ok = 0;
        if(('+' == s[i] || '-' == s[i]) && ('+' == s[i+1] || '-' == s[i+1])) ok = 0;
    }
    if(!ok || !second_ok)
    {
        puts("Incorrect enter");
        return 0;
    }

    //Äîäàâàííÿ, â³äí³ìàííÿ
    int i = 0;
    int rez = 0;
    while(i < len)
    {
        char buff_operation = 0;
        if(s[i] == '+') buff_operation = s[i++];
        if(s[i] == '-') buff_operation = s[i++];

        int buff = 0;
        while(isDigit(s[i]))
        {
            buff *= 10;
            buff += convertCharacterToDigit(s[i]);
            i++;
        }

        if(buff_operation == '+') rez += buff;
        else if(buff_operation == '-') rez -= buff;
        else rez = buff;
    }

    return rez;
}


double convertStringToFractionalNumber(char s[])
{
    if(!isNumberFractionalInString(s)) return 0;

    double integer = 0;
    int  pos_fract;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '.')
        {
            pos_fract = i+1;
            break;
        }

        integer *= 10;
        integer += convertCharacterToDigit(s[i]);
    }

    int amount_fract = 0;
    double fractional = 0;
    for(int i = pos_fract; i < len; i++)
    {
        fractional *= 10;
        fractional += convertCharacterToDigit(s[i]);
        amount_fract++;
    }
    double div = 1;
    for(int i = 0; i < amount_fract; i++) div *= 10;

    return integer + fractional / div;
}

//òğåáà ïîÿñíåííÿ ïî ÷èñëàì double, ñê³ëüêè âñüîãî ìîæå çíàê³â çáåğ³ãàòè ñê³ëüêè ö³ëèõ çíàê³â ñê³ëüêè äğîáíèõ.
double convertFractionalNumberToString(double number, int precision, char s[])
{
    if(precision > 15) return -1;

    int integer = number;
    double fractional = number - integer;
    int amount_int = getAmountOfDigitsInNumber(integer);
    for(int i = amount_int-1; i >= 0; i--)
    {
        s[i] = convertDigitToCharacter(integer % 10);
        integer /= 10;
    }

    s[amount_int] = '.';

    int d;
    for(int i = 0; i <= precision; i++)
    {
        fractional *= 10;
        d = fractional;
        fractional -= d;
        s[amount_int + 1 + i] = convertDigitToCharacter(d);
    }

    s[amount_int+precision+1] = '\0';
}

void insertCharInString(char s[], char c, int pos)
{
    int len = strlen(s);
    for(int i = len; i >= pos; i--)
    {
        s[i+1] = s[i];
    }
    s[pos] = c;
}


void insertStringInString(char s[], char s0[], int pos)
{
    int len0 = strlen(s0);
    for(int j = len0-1; j >= 0 ; j--)
    {
        insertCharInString(s, s0[j], pos);
    }
}


int entryStrInStr(const char s[], const char s0[])
{
    int len = strlen(s);
    int len0 = strlen(s0);
    int cnt = 0;
    for(int i = 0; i < len ; i++)
    {
        int ok = 1;
        if(s[i] == s0[0])
        {
            for(int j = 1; j < len0; j++)
            {
                if(s[i+j] != s0[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) cnt++;
            i += len0-1;
        }
    }

    return cnt;
}


void deleteCharacterInString(char s[], int pos)
{
    int len = strlen(s);
    for(int i = pos; i < len; i++)
    {
        s[i] = s[i+1];
    }
}


void deleteCharactersInString(char s[], int from, int to)
{
    int len = strlen(s);
    for(int i = 0; i < to-from; i++)
    {
       deleteCharacterInString(s, from);
    }
}


void deleteFirstStrInStr(char s[], const char s0[])
{
    int len = strlen(s);
    int len0 = strlen(s0);
    for(int i = 0; i < len ; i++)
    {
        int ok = 1;
        if(s[i] == s0[0])
        {
            for(int j = 1; j < len0; j++)
            {
                if(s[i+j] != s0[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                deleteCharactersInString(s, i, i+len0);
                break;
            }
        }
    }
}


void deleteLastStrInStr(char s[], const char s0[])
{
    int len = strlen(s);
    int len0 = strlen(s0);
    int pos = -1;
    for(int i = 0; i < len ; i++)
    {
        int ok = 1;
        if(s[i] == s0[0])
        {
            for(int j = 1; j < len0; j++)
            {
                if(s[i+j] != s0[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) pos = i;
        }
    }

    if(pos > -1)   deleteCharactersInString(s, pos, pos+len0);
}


void deleteAllStrInStr(char s[], const char s0[])
{
    int len = strlen(s);
    int len0 = strlen(s0);
    for(int i = 0; i < len ; i++)
    {
        int ok = 1;
        if(s[i] == s0[0])
        {
            for(int j = 1; j < len0; j++)
            {
                if(s[i+j] != s0[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                deleteCharactersInString(s, i, i+len0);
                len -= len0;
            }
        }
    }
}


void replaceFirstStrInStr(char s[], const char s1[], const char s2[])
{
    int len = strlen(s);
    int len1 = strlen(s1);
    for(int i = 0; i < len ; i++)
    {
        int ok = 1;
        if(s[i] == s1[0])
        {
            for(int j = 1; j < len1; j++)
            {
                if(s[i+j] != s1[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                deleteCharactersInString(s, i, i+len1);
                insertStringInString(s, s2, i);
                break;
            }
        }
    }
}


void replaceLastStrInStr(char s[], const char s1[], const char s2[])
{
    int len = strlen(s);
    int len1 = strlen(s1);
    int pos = -1;
    for(int i = 0; i < len ; i++)
    {
        int ok = 1;
        if(s[i] == s1[0])
        {
            for(int j = 1; j < len1; j++)
            {
                if(s[i+j] != s1[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)  pos = i;
        }
    }

    if(pos > -1)
    {
        deleteCharactersInString(s, pos, pos+len1);
        insertStringInString(s, s2, pos);
    }
}


void replaceAllStrInStr(char s[], const char s1[], const char s2[])
{
    int len = strlen(s);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i = 0; i < len ; i++)
    {
        int ok = 1;
        if(s[i] == s1[0])
        {
            for(int j = 1; j < len1; j++)
            {
                if(s[i+j] != s1[j])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                deleteCharactersInString(s, i, i+len1);
                insertStringInString(s, s2, i);
                len = len - len1 + len2;
                i += len2-1;
            }
        }
    }
}


int is_space(char c)
{
    return 0 <= c && c <= 32;
}


int getNumberOfSpaces(char s[])
{
    int cnt = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(is_space(s[i])) cnt++;
    }

    return cnt;
}


int isRus(char c)
{
    char rus[] = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    int n = sizeof(rus);
    for(int i = 0; i < n; i++)
    {
        if(rus[i] == c)
        {
            return 1;
        }
    }

    return 0;
}


int isLat(char c)
{
    char lat[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    return indexOf(lat, c) != -1;
}


int isUpC(char c)
{
    char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
    for(int i = 0; i < 59; i++)
    {
        if(upper_case[i] == c)
        {
            return 1;
        }
    }

    return 0;
}


int isLoC(char c)
{
    char lower_case[] = "abcdefghijklmnopqrstuvwxyzàáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    for(int i = 0; i < 59; i++)
    {
        if(lower_case[i] == c)
        {
            return 1;
        }
    }

    return 0;
}


void checkRusUpper(char s[])
{
    int ok = 1;
    do
    {
        ok = 1;
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(!((isRus(s[i]) && isUpC(s[i])) || is_space(s[i])))
            {
                ok = 0;
                break;
            }
        }

        if(len == 0) ok = 0;

        if(!ok)
        {
            puts("incorrect enter");
            gets(s);
        }
    }
    while(!ok);
}


void checkRusUpperAndLower(char s[])
{
    int ok = 1;
    do
    {
        ok = 1;
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(!((isRus(s[i]) && (isUpC(s[i]) || isLoC(s[i]))) || is_space(s[i])))
            {
                ok = 0;
                break;
            }
        }

        if(len == 0) ok = 0;

        if(!ok)
        {
            puts("incorrect enter");
            gets(s);
        }
    }
    while(!ok);
}


int calcWord(char s[])
{
    int cnt = 0;
    int len = strlen(s);
    for(int i = 1; i <= len; i++)
        if(!isPunct(s[i-1]) && !isdigit(s[i-1]) && !is_space(s[i-1]) && (is_space(s[i]) || isdigit(s[i]) || isPunct(s[i]))) cnt++;
    return cnt;
}


int calcNormWord(char s[])
{
    int cnt = 0;
    int len = strlen(s);
    for(int i = 1; i <= len; i++)
        if(!is_space(s[i-1]) && is_space(s[i])) cnt++;
    return cnt;
}

//
int getWordPos(const char *s, int nw)
{
    int len = strlen(s);
    char* S = (char*) malloc(sizeof(char) * (len+2));
    strcpy(S, " ");
    strcat(S, s);
    int cnt = 0;
    for(int i = 1; i < len; i++)
    {
        if(is_space(S[i-1]) && !is_space(S[i]))
        {
            if(cnt == nw)
            {
                free(S);
                return i-1;
            }
            cnt++;
        }
    }
    free(S);
    return -1;
}

//
int getWordLen(const char* s, int nw)
{
    int pos = getWordPos(s, nw);
    if(pos == -1) return 0;
    int cnt = 0;
    int i = pos;
    while(!is_space(s[i]) && !isPunct(s[i]) && !isdigit(s[i]))
    {
        cnt++;
        i++;
    }
    return cnt;
}

//
void getWord(const char* s, int nw, char* word)
{
    word[0] = 0;
    int pos = getWordPos(s, nw);
    if(pos == -1) return;
    int len = getWordLen(s, nw);
    int j = 0;
    for(int i = pos; i < pos+len; i++)
    {
        word[j++] = s[i];
    }
    word[j] = 0;
}


int isPunct(char c)
{
    char puncts[] = ".?!,;:-()[]{}'\"/\\";
    //return strchr(puncts, c);
    return indexOf(puncts, c) != -1;
}


int isVowel(char c)
{
    char vowels[] = "àóîèıûÿşå¸ÀÓÎÈİÛßŞÅ¨";
    //return strchr(puncts, c);
    return indexOf(vowels, c) != -1;
}


int isWord(const char* s, int nw)
{
    int pos = getWordPos(s, nw);
    if(pos == -1) return 0;
    int len = getWordLen(s, nw);
    for(int i = pos; i < pos+len; i++)
    {
        if(isPunct(s[i]) || isdigit(s[i]))
        {
            return 0;
        }
    }

    return 1;
}


int startPosWord(const char s[], int pos)
{
    if(pos > strlen(s)) return -1;
    if(is_space(s[pos]) && !is_space(s[pos+1])) return -1;
    if(is_space(s[pos]) && is_space(s[pos+1])) return -1;

    for(int i = pos; i > 0; i--)
    {
        if(is_space(s[i-1]) && !is_space(s[i])) return i;
    }

    return 0;
}


int lengthWord(const char s[], int pos)
{
    int start_pos = startPosWord(s, pos);
    if(start_pos == -1) return -1;

    int cnt = 1;
    int len = strlen(s);
    for(int i = start_pos;  i < len; i++)
    {
        if(!is_space(s[i]) && is_space(s[i+1])) break;
        cnt++;
    }

    return cnt;
}


int strCmp(const char s1[], const char s2[])
{
    int lenW_1 = lengthWord(s1, 0);
    int lenW_2 = lengthWord(s2, 0);

    int n = (lenW_1 < lenW_2) ? lenW_1 : lenW_2;

    for(int i = 0; i < n; i++)
    {
        if(s1[i] < s2[i]) return -1;
        if(s1[i] > s2[i]) return 1;
    }

    if(lenW_1 < lenW_2) return 1;
    if(lenW_1 > lenW_2) return -1;

    return 0;
}


void cipher(unsigned char *s, int key)
{
    if(key == 0) return;

    char rus_big[] = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
    char rus_small[] = "àáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    int len_big = strlen(rus_big);
    int len_small = strlen(rus_small);

    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int pos_big = indexOf(rus_big, s[i]);
        int pos_small = indexOf(rus_small, s[i]);
        if(pos_big != -1)
        {
            s[i] = 'À' + (pos_big + key) % len_big;
        }
        if(pos_small != -1)
        {
            s[i] = 'à' + (pos_small + key) % len_small;
        }
    }
}


void recipher(unsigned char *s, int key)
{
    if(key == 0) return;

    char rus_big[] = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
    char rus_small[] = "àáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ";
    int len_big = strlen(rus_big);
    int len_small = strlen(rus_small);

    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int pos_big = indexOf(rus_big, s[i]);
        int pos_small = indexOf(rus_small, s[i]);
        if(pos_big != -1)
        {
            s[i] = 'À' + ((pos_big + len_big - key) % len_big);
        }
        if(pos_small != -1)
        {
            s[i] = 'à' + ((pos_small + len_small - key) % len_small);
        }
    }
}









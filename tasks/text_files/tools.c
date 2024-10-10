#include "tools.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void removeEOLN(char* s)
{
    int len = strlen(s);
    if(s[len-1] == '\n') s[len-1] = 0;
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


int createNewFile(const char* src)
{
    FILE* f = fopen(src, "wb");
    if(!f)
    {
        fclose(f);
        return 0;
    }
    else
    {
        fclose(f);
        return 1;
    }
}


int getAmountLinesOfFile(const char* src)
{
    FILE* f = fopen(src, "rt");

    int i = 0;
    char buf[200];
    while (fgets(buf, 200, f)) i++;

    fclose(f);

    return i;
}


/*-------------------------*///–Ó·ÓÚ‡ Á ÒËÏ‚ÓÎ‡ÏË
int isUppercase(char c)
{
    if(('A' <= c && c <='Z')) return 1;

    if('¿' <= c && c <='ﬂ') return 2;

    if('•' == c || '™' == c || 'Ø' == c || '≤' == c)
    return (unsigned char)c;

    return 0;
}

int isLowercase(char c)
{
    if('a' <= c && c <='z') return 1;

    if('‡' <= c && c <='ˇ') return 2;

    if('¥' == c || '∫' == c || 'ø' == c || '≥' == c)
    return (unsigned char)c;

    return 0;
}


int isRus(char c)
{
    char rus[] = "¿¡¬√ƒ≈®∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ‡·‚„‰Â∏ÊÁËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ";
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


int isSymbol(char c)
{
    return isRus(c) || isLat(c);
}


int isUpC(char c)
{
    char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¡¬√ƒ≈®∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ";
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
    char lower_case[] = "abcdefghijklmnopqrstuvwxyz‡·‚„‰Â∏ÊÁËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ";
    for(int i = 0; i < 59; i++)
    {
        if(lower_case[i] == c)
        {
            return 1;
        }
    }

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
    char abc[] = "abcdefghijklmnopqrstuvwxyz‡·‚„‰Â∏ÊÁËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ∫ø≥¥";
    char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¡¬√ƒ≈®∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ™Ø≤•";

    int pos = indexOf(ABC, c);
    if(pos!= -1) return abc[pos];
    return c;
}


unsigned char toUpper(char c)
{
    char abc[] = "abcdefghijklmnopqrstuvwxyz‡·‚„‰Â∏ÊÁËÈÍÎÏÌÓÔÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ∫ø≥¥";
    char ABC[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¡¬√ƒ≈®∆«»… ÀÃÕŒœ–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ™Ø≤•";

    int pos = indexOf(abc, c);
    if(pos!= -1) return ABC[pos];
    return c;
}


unsigned char switchOneCase(char c)
{
   if(isLowercase(c)) return toUpper(c);
   if(isUppercase(c)) return toLower(c);
   return c;
}


void switchAllCase(char* s)
{
    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        s[i] = switchOneCase(s[i]);
    }
}


/*--------------------*///–Ó·ÓÚ‡ Á ÔÓ·≥Î‡ÏË
//(‚Ë‰‡Îˇ∫ ‚Ò≥ Ú‡·ÛÎˇˆ≥ø ÔÓ·≥ÎË Ú‡ \n ‚≥‰ 0 ‰Ó 32)
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
/*--------------------------*///Í≥ÌÂˆ¸ Ó·ÓÚË Á ÔÓ·≥Î‡ÏË

void showTextFile(const char* src)
{
    int max_length = getLongestLineLength(src);

    FILE* f = fopen(src, "rt");
    if(!f)
    {
        printf("Function showTextFile(src) can not found: %s\n", src);
        exit(1);
    }

    printf("File: %s\n", src);
    char l[200] = " +";
    for(int i = 0; i <= max_length; i++) l[i+2] = '-';
    l[2+max_length+1] = '+';
    l[2+max_length+2] = 0;
    puts(l);
    char buf[200];
    while(fgets(buf, sizeof(buf), f))
    {
        removeEOLN(buf);
        expandLine(buf, max_length);
        printf(" | %s|\n", buf);
    }
    puts(l);
    fclose(f);
}


void clearScreen()
{
    system("CLS");
}


int getLongestLineLength(const char* src)
{
    FILE* f = fopen(src, "rt");
    if(!f)
    {
        printf("Function getLongestLineLength(src) can not found: %s\n", src);
        exit(1);
    }

    int max_length = 0;
    char buf[200];
    while(fgets(buf, sizeof(buf), f))
    {
        int len = strlen(buf);
        if(len > max_length) max_length = len;
    }

    fclose(f);
    return max_length;
}


void expandLine(char* s, int new_len)
{
    int len = strlen(s);
    while(len < new_len)
    {
        s[len] = ' ';
        s[len+1] = 0;
        len++;
    }
}


bool isLineEmpty(char* s)
{
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
//        if(s[i] > 32 || s[i] < 0) return false; //ÕÂ ÔÛÒÚËÈ ˇ‰ÓÍ
        if(s[i] < 0 || 32 < s[i]) return false; //ÕÂ ÔÛÒÚËÈ ˇ‰ÓÍ
    }
    return true; //œÛÒÚËÈ ˇ‰ÓÍ
}


bool isNewParagraph(char* s, bool* ok)//‰Ó ·ÛÎÂ‚Óø ÁÏ≥ÌÌÓø ÔÓ‚ËÌÂÌ ·ÛÚË ÔËÒ‚Ó∫ÌËÈ false, ÁÏ≥ÌÌ‡ ÁÌ‡˜ËÚ¸ ˘Ó ÏË ÁÌ‡ıÓ‰ËÏÓÒˇ ‚ ÒÂÂ‰ËÌ≥ ‡·Á‡ˆÛ
{
    if(*ok == false)//ÔÓÔ‡‰‡∫ÏÓ Ò˛‰Ë ÔË ÔÓ˜‡ÚÍÓ‚≥ ÚÂÍÒÚÛ ≥ ÔË ‰ÓÒˇ„ÌÂÌ≥ ≥Ì¯Ó„Ó ‡·Á‡ˆÛ
    {
        if(!isLineEmpty(s))
        {
            *ok = true; //ˇ‰ÓÍ
            return true;
        }
        else
        {
            *ok = false;
            return false;
        }
    }
    else
    {
        if(isLineEmpty(s))
        {
            *ok = false;
            return false;
        }
        else
        {
            return false;
        }
    }
}


bool isRedLine(char* s)
{
    int len = strlen(s);
    if(len < 6) return false;

    for(int i = 0; i < 5; i++)
    {
        if(!is_space(s[i])) return false;
    }

    return !is_space(s[5]);
}


bool isNewParagraphWithRedLine(char* s, bool* ok)//‰Ó ·ÛÎÂ‚Óø ÙÛÌÍˆ≥ø ÔÓ‚ËÌÂÌ ·ÛÚË ÔËÒ‚Ó∫ÌËÈ false, ÁÏ˚ÌÌ‡ ÁÌ‡˜ËÚ¸ ˘Ó ÏË ÁÌ‡ıÓ‰ËÏÓÒˇ ‚ ÒÂÂ‰ËÌ≥ ‡·Á‡ˆÛ
{
    if(*ok == false)//ÔÓÔ‡‰‡∫ÏÓ Ò˛‰Ë ÔË ÔÓ˜‡ÚÍÓ‚≥ ÚÂÍÒÚÛ ≥ ÔË ‰ÓÒˇ„ÌÂÌ≥ ≥Ì¯Ó„Ó ‡·Á‡ˆÛ
    {
        if(isRedLine(s))
        {
            *ok = true; //ˇ‰ÓÍ
            return true;
        }
        else
        {
            *ok = false;
            return false;
        }
    }
    else
    {
        if(!isRedLine(s))
        {
            *ok = false;
            return false;
        }
        else
        {
            return false;
        }
    }
}


/*--------------------*///œÓ˜‡ÚÓÍ Ó·ÓÚË Á≥ ÒÎÓ‚‡ÏË


int calcWord(char s[])
{
    int cnt = 0;
    int len = strlen(s);
    for(int i = 1; i <= len; i++)
        if(!is_space(s[i-1]) && is_space(s[i])) cnt++;
    return cnt;
}


int calcNormWord(char s[])
{
    int cnt = 0;
    int len = strlen(s);
    for(int i = 1; i <= len; i++)
        if(!isPunct(s[i-1]) && !isdigit(s[i-1]) && !is_space(s[i-1]) && (is_space(s[i]) || isdigit(s[i]) || isPunct(s[i]))) cnt++;
    return cnt;
}


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


int getNormWordPos(const char *s, int nw)
{
    int len = strlen(s);
    char* S = (char*) malloc(sizeof(char) * (len+2));
    strcpy(S, " ");
    strcat(S, s);
    int cnt = 0;
    for(int i = 1; i < len; i++)
    {
        if((is_space(S[i-1]) || isdigit(S[i-1]) || isPunct(S[i-1]))  &&  (!is_space(S[i]) || isdigit(S[i]) || isPunct(S[i])))
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


int getWordLen(const char* s, int nw) //‚ÒÂ ÚÂ ˘Ó ÓÁ‰≥ÎÂÌÓ ÔÓ·≥Î‡ÏË Á≥ ÁÌ‡Í‡ÏË ÔÛÌÍÚÛ‡ˆ≥ø Ú‡ ˆËÙ‡ÏË
{
    int pos = getWordPos(s, nw);
    if(pos == -1) return 0;
    int cnt = 0;
    int i = pos;
    while(!is_space(s[i]))
    {
        cnt++;
        i++;
    }
    return cnt;
}


int getNormWordLen(const char* s, int nw) //‚ÒÂ ÚÂ ˘Ó ÓÁ‰≥ÎÂÌÓ ÔÓ·≥Î‡ÏË Á≥ ÁÌ‡Í‡ÏË ÔÛÌÍÚÛ‡ˆ≥ø Ú‡ ˆËÙ‡ÏË
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


void getNormWord(const char* s, int nw, char* word)
{
    word[0] = 0;
    int pos = getNormWordPos(s, nw);/////////
    if(pos == -1) return;
    int len = getNormWordLen(s, nw);
    int j = 0;
    for(int i = pos; i < pos+len; i++)
    {
        word[j++] = s[i];
    }
    word[j] = 0;
}//ƒÓÓ·ËÚË Ô≥‰ ˆ˛ ÙÛÌÍˆ≥˛ ÌÓÏ‡Î¸Ì≥ ÙÛÌÍˆ≥ø


int isPunct(char c)
{
    char puncts[] = ".?!,;:-()[]{}'\"/\\";
    //return strchr(puncts, c);
    return indexOf(puncts, c) != -1;
}


int isVowel(char c)
{
    char vowels[] = "‡ÛÓË˝˚ˇ˛Â∏¿”Œ»›€ﬂﬁ≈®";
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
/*-------------------------*/// ≥ÌÂˆ¸ Ó·ÓÚË  Á≥ ÒÎÓ‚‡ÏË


/*-------------------------*///–Ó·ÓÚ‡ Á ÒËÏ‚ÓÎ‡ÏË










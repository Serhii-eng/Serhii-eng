#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

int isDigit(char c);
int isUppercase(char c);
int isLowercase(char c);
unsigned char toLower(char c);
unsigned char toUpper(char c);
int convertCharacterToDigit(char c);
int convertStringToNumber(char s[]);
int isNumberIntegerInString(char s[]);
int isNumberFractionalInString(char s[]);
int isNumberFractioOrInteger(char s[]);
int getAmountOfDigitsInNumber(int  number);
char convertDigitToCharacter(int d);
void convertNumberToString(int number, char s[]);
void convertReverseNumberToString(int number, char s[]);
int sunOfDigitsInString(char s[]);
int plusOrMinusMathOperation(char s[]);
double convertStringToFractionalNumber(char s[]);
double convertFractionalNumberToString(double number, int precision, char s[]);
void insertCharInString(char s[], char c, int pos);
void insertStringInString(char s[], char s0[], int pos);
int entryStrInStr(const char s[], const char s0[]);
void deleteCharacterInString(char s[], int pos);
void deleteFirstStrInStr(char s[], const char s0[]);
void deleteLastStrInStr(char s[], const char s0[]);
void deleteAllStrInStr(char s[], const char s0[]);
void replaceFirstStrInStr(char s[], const char s1[], const char s2[]);
void replaceLastStrInStr(char s[], const char s1[], const char s2[]);
int is_space(char c);
int getNumberOfSpaces(char s[]);
int isRus(char c);
int isLat(char c);
int isUpC(char c);
int isLoC(char c);
void checkRusUpper(char s[]);
void checkRusUpperAndLower(char s[]);
int calcWord(char s[]);
int getWordPos(const char *s, int nw);
int getWordLen(const char* s, int nw);
void getWord(const char* s, int nw, char* word);
int isPunct(char c);
int isVowel(char c);
int isWord(const char* s, int nw);
int startPosWord(const char s[], int pos);
int lengthWord(const char s[], int pos);
int strCmp(const char s1[], const char s2[]);
void cipher(unsigned char *s, int key);
void recipher(unsigned char *s, int key);










#endif // MYSTRING_H_INCLUDED

//перетворити рядок в ціле число
//перетворити ціле число в рядок

#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <stdbool.h>

void removeEOLN(char* s);
int createNewFile(const char* src);
int getAmountLinesOfFile(const char* src);

//������ � ���������
int isRus(char c);
int isLat(char c);
int isSymbol(char c);
int isUppercase(char c);
int isLowercase(char c);
int isUpC(char c);
int isLoC(char c);
unsigned char toLower(char c);
unsigned char toUpper(char c);
int indexOf(const char* s, char c);
unsigned char switchOneCase(char c);
void switchAllCase(char* s);

//������ � ��������
int is_space(char c);
void remove_symbol(char *s, int pos);
void left_trim(char *s);
void right_trim(char *s);
void all_trim(char *s);
void normalize(char *s);

//������ � ������������ ������
void showTextFile(const char* src);
void clearScreen();
int getLongestLineLength(const char* src);
void expandLine(char* s, int new_len); //�������� ������� �����

//������ � ��������
bool isLineEmpty(char* s);
bool isNewParagraph(char* s, bool* ok);
bool isRedLine(char* s);
bool isNewParagraphWithRedLine(char* s, bool* ok);

//������ � �������
int calcWord(char s[]);
int calcNormWord(char s[]);
int getWordPos(const char *s, int nw);
int getNormWordPos(const char *s, int nw);
int getWordLen(const char* s, int nw); //��� �� �� �������� �������� � ������� ���������� �� �������
int getNormWordLen(const char* s, int nw); //���� ����� ��� ����� ���������� � ����
void getWord(const char* s, int nw, char* word);
void getNormWord(const char* s, int nw, char* word);
int isPunct(char c);
int isVowel(char c);
int isWord(const char* s, int nw);
int startPosWord(const char s[], int pos);
int lengthWord(const char s[], int pos);







#endif // TOOLS_H_INCLUDED

#include "common.h"
#include <windows.h>

void setCur(int y, int x){//��������� ���������� ������� � ������
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //������� GetStdHandle(STD_OUTPUT_HANDLE) ������� ������ ���� ������
    //�������   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
    //���������� ���������� �� �� ������ (coord), �� ����� ��� ������ � ��������.
}

void hidecursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


void showcursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

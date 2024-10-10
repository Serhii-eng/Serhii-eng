#include "common.h"
#include <windows.h>

void setCur(int y, int x){//процедура переміщення курсора в консолі
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //функція GetStdHandle(STD_OUTPUT_HANDLE) повертає адресу нашої консолі
    //функція   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
    //встановлює координати які ми задаємо (coord), по адресі яку приймає в аргумент.
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

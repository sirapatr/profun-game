#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "fuc.h"

void gotoxy(int x, int y) {
    COORD c = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

/*

int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

int setFont() {
    int newWidth = 28, newHeight = 28;
    CONSOLE_FONT_INFOEX fontStructure = { 0 };
    fontStructure.cbSize = sizeof(fontStructure);
    fontStructure.dwFontSize.X = newWidth;
    fontStructure.dwFontSize.Y = newHeight;
    wcscpy(fontStructure.FaceName, L"Arial");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetCurrentConsoleFontEx(hConsole, true, &fontStructure);
    system("pause");
}

*/
#pragma once
#ifndef __FUC_H__
#define __FUC_H__

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>

/*

#define screen_x 112
#define screen_y 25

HANDLE wHnd;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };

*/

void gotoxy(int x, int y);
void setcursor(bool visible);
void setcolor(int fg, int bg);
//int setConsole(int x, int y);

#endif
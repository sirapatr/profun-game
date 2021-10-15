#pragma once
#ifndef __FUC_H__
#define __FUC_H__

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
void gotoxy(int x, int y);
void setcursor(bool visible);
void setcolor(int fg, int bg);

#endif
#pragma once
#ifndef __DRAW_H__
#define __DRAW_H__

typedef struct _WALL{
    bool have = true;
    bool isUse = false;
    bool top = false;
    bool down = false;
    bool left = false;
    bool right = false;
    int xh;
    int yup;
    int yd;
    int xl;
    int yv;
    int xr;
} WALL;

extern WALL w[1] ;

void Del_player(int x, int y);
void draw_player(int x, int y);


void draw_wall(int i , int x, int y);
void del_wall(int i);
void re_wall(int i, int a);

void draw_mon(int x, int y);
void del_mon(int x, int y);

void draw_food();
void exfood(int a);
void draw_morefood();

void draw_menu();
void draw_point(int x, int y);
void Del_point(int x, int y);
void draw_score(int score);
void draw_Time(int Time);
void draw_name();
void Darw_scoreboard();

#endif
#pragma once

#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__

typedef struct _MONS
{
    int x, y;
    bool monlife = false;
    int dirx = 1,diry = 0;
}MONS;

extern MONS m[6];
void spawn_monster();
void mon_dir(int i, int x, int y);
void mon_move(int i, int x, int y);

#endif
#pragma once

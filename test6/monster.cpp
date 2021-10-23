#include "fuc.h"
#include "map.h"
#include "monster.h"
#include "draw.h"

MONS m[6];

void spawn_monster() {
    for (int i = 0; i < 5; i++) {
        while (!m[i].monlife) {
            m[i].y = rand() %(ROW-2) + 1;
            m[i].x = rand() %(COL-2) + 1;
            if (map[m[i].y][m[i].x] != '#' && map[m[i].y][m[i].x] != 'O') {
                draw_mon(m[i].x, m[i].y);
                m[i].monlife = true;
            }
        }
    }
}

void mon_dir(int i,int x, int y) {
    if (m[i].monlife) {
        int dir = rand() % 4 + 1;
        if (dir == 1) {
            m[i].diry = 0;
            m[i].dirx = 1;
        }
        else if (dir == 2) {
            m[i].diry = 0;
            m[i].dirx = -1;
        }
        else if (dir == 3) {
            m[i].diry = -1;
            m[i].dirx = 0;
        }
        else {
            m[i].diry = 1;
            m[i].dirx = 0;
        }
    }


}

void mon_move(int i,int x ,int y) {
    del_mon(m[i].x, m[i].y);
    if(map[m[i].y+ m[i].diry][m[i].x] != '#' && map[m[i].y + m[i].diry][m[i].x] != 'O') {
        m[i].y += m[i].diry;
    }
    else {
        mon_dir(i, x, y);
    }
    if (map[m[i].y][m[i].x + m[i].dirx] != '#' && map[m[i].y][m[i].x + m[i].dirx] != 'O') {
        m[i].x += m[i].dirx;
    }
    else {
        mon_dir(i, x, y);
    }
    
    draw_mon(m[i].x, m[i].y);


}
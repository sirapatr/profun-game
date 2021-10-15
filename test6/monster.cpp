#include "fuc.h"
#include "map.h"
#include "monster.h"
#include "draw.h"

MONS m[6];

void spawn_monster() {
    for (int i = 1; i <= 5; i = 1) {
        while (!m[i].monlife) {
            m[i].y = rand() %(ROW-2) + 1;
            m[i].x = rand() %(COL-2) + 1;
            if (map[m[i].y][m[i].x] != '#' && map[m[i].y][m[i].x] != 'O') {
                setcolor(2, 0);
                draw_mon(m[i].x, m[i].y);
                setcolor(7, 0);
                m[i].monlife = true;
            }
        }
    }
}

void mon_dir(int i,int x, int y) {
    if (m[i].monlife) {
        if (m[i].y < y) {
            m[i].diry = 1;
        }
        else if (m[i].y > y) {
            m[i].diry = -1;
        }
    }


}

void mon_move(int i,int x ,int y) {
    del_mon(m[i].x, m[i].y);
    if(map[m[i].y+ m[i].diry][m[i].x] != '#' && map[m[i].y + m[i].diry][m[i].x] != 'O') {
        m[i].y += m[i].diry;
    }
    else if (map[m[i].y][m[i].x + m[i].dirx] != '#' && map[m[i].y][m[i].x + m[i].dirx] != 'O') {
        m[i].x += m[i].dirx;
    }
    else {
        mon_dir(i,x,y);
    }
    draw_mon(m[i].x, m[i].y);


}
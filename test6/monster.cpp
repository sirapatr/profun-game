#include "fuc.h"
#include "map.h"
#include "monster.h"
#include "draw.h"

MONS m[6];

void spawn_monster() {
    for (int i = 0; i < 5; i++) {
        while (!m[i].monlife) {
            m[i].y = rand() %(ROW-2) + 4;
            m[i].x = rand() %(COL-2) + 5;
            if (map[m[i].y][m[i].x] != ' ' ) {
                setcolor(2, 0);
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

void mon_moveToPy(int i,int x,int y) {
    del_mon(m[i].x, m[i].y);
    if (y > m[i].y) {
        m[i].diry = 1;
        m[i].dirx = 0;
    }
    else if( y < m[i].y ){
        m[i].diry = -1;
        m[i].dirx = 0;
    }
    else {
        m[i].diry = 0;
        }

    if (m[i].diry != 0 && (map[m[i].y + m[i].diry][m[i].x] == ' ' || map[m[i].y + m[i].diry][m[i].x] == 'P')){
        m[i].y += m[i].diry;
    }
    else {
        if (x > m[i].x) {
            m[i].dirx = 1;
        }
        else if (x < m[i].x) {
            m[i].dirx = -1;
        }
        else {
            m[i].dirx = 0;
        }
    }
    if (map[m[i].y][m[i].x + m[i].dirx] == ' ' || map[m[i].y][m[i].x + m[i].dirx] != 'P') {
        m[i].x += m[i].dirx;
    }


    draw_mon(m[i].x, m[i].y);
}

void mon_moveToPx(int i, int x, int y) {
    del_mon(m[i].x, m[i].y);
    if (x > m[i].x) {
        m[i].dirx = 1;
        m[i].diry = 0;
    }
    else if (x < m[i].x) {
        m[i].dirx = -1;
        m[i].diry = 0;
    }
    else {
        m[i].dirx = 0;
    }

    if (m[i].dirx != 0 && ( map[m[i].y][m[i].x + m[i].dirx] == ' ' || map[m[i].y][m[i].x + m[i].dirx] == 'P')) {
        m[i].x += m[i].dirx;
    }
    else {
        if (y > m[i].y) {
            m[i].diry = 1;
        }
        else if (y < m[i].y) {
            m[i].diry = -1;
        }
        else {
            m[i].diry = 0;
        }
    }
    if (map[m[i].y + m[i].diry][m[i].x] != ' ' || map[m[i].y + m[i].diry][m[i].x] == 'P') {
        m[i].y += m[i].diry;
    }

    draw_mon(m[i].x, m[i].y);
}

void mon_moveTolmX(int i ,int x ,int y) {
    if (y - 2 <= m[i].y && m[i].y <= y + 2 && x - 5 <= m[i].x && m[i].x <= x + 5) {
        mon_moveToPx(i, x, y);
    }
    else {
        mon_move(i, x, y);
    }

}

void mon_moveTolmY(int i, int x, int y) {
    if (y - 2 <= m[i].y && m[i].y <= y + 2 && x - 5 <= m[i].x && m[i].x <= x + 5) {
        mon_moveToPy(i, x, y);
    }
    else {
        mon_move(i, x, y);
    }

}

void mon_move(int i,int x ,int y) {
    del_mon(m[i].x, m[i].y);
    if(map[m[i].y+ m[i].diry][m[i].x] == ' ' || map[m[i].y + m[i].diry][m[i].x] != 'P') {
        m[i].y += m[i].diry;
    }
    else {
        mon_dir(i, x, y);
    }
    if(map[m[i].y][m[i].x + m[i].dirx] == ' ' || map[m[i].y][m[i].x + m[i].dirx] == 'P') {
        m[i].x += m[i].dirx;
    }
    else {
        mon_dir(i, x, y);
    }
    
    draw_mon(m[i].x, m[i].y);


}
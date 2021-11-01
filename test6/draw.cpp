#include "fuc.h"
#include "map.h"
#include "score.h"
#include "draw.h"

WALL w[1];

//player
void Del_player(int x, int y) { 
    gotoxy(x, y);
    printf(" ");
}

void draw_player(int x, int y) {
    gotoxy(x, y);
    printf("P");
}

//wall



void draw_wall(int i, int x, int y) {
    if (!w[i].isUse) {
        setcolor(5, 0);
        w[i].xh = x;
        w[i].yd = y + 1;
        w[i].yup = y - 1;
        w[i].xr = x + 1;
        w[i].yv = y;
        w[i].xl = x - 1;
        if (map[w[i].yd][w[i].xh] == ' ') {
            gotoxy(w[i].xh, w[i].yd);
            printf("W");
            map[w[i].yd][w[i].xh] = 'W';
            w[i].down = true;
        }
        if (map[w[i].yup][w[i].xh] == ' ') {
            gotoxy(w[i].xh, w[i].yup);
            printf("W");
            map[w[i].yup][w[i].xh] = 'W';
            w[i].top = true;
        }
        if (map[w[i].yv][w[i].xr] == ' ') {
            gotoxy(w[i].xr, w[i].yv);
            printf("W");
            map[w[i].yv][w[i].xr] = 'W';
            w[i].right = true;
        }
        if (map[w[i].yv][w[i].xl] == ' ') {
            gotoxy(w[i].xl, w[i].yv);
            printf("W");
            map[w[i].yv][w[i].xl] = 'W';
            w[i].left = true;
        }
        setcolor(7, 0);
        w[i].isUse = true;
    }
}

void del_wall(int i) {
    if (w[i].down) {
        gotoxy(w[i].xh, w[i].yd);
        printf(" ");
        map[w[i].yd][w[i].xh] = ' ';
        w[i].down = false;
    }
    if (w[i].top) {
        gotoxy(w[i].xh, w[i].yup);
        printf(" ");
        map[w[i].yup][w[i].xh] = ' ';
        w[i].top = false;
    }
    if (w[i].left) {
        gotoxy(w[i].xl, w[i].yv);
        printf(" ");
        map[w[i].yv][w[i].xl] = ' ';
        w[i].left = false;
    }
    if (w[i].right) {
        gotoxy(w[i].xr, w[i].yv);
        printf(" ");
        map[w[i].yv][w[i].xr] = ' ';
        w[i].right = false;
    }
}

//monster

void draw_mon(int x, int y) {
    map[y][x] = 'M';
    gotoxy(x, y);
    printf("M");
    setcolor(7, 0);
}

void del_mon(int x, int y) {
    map[y][x] = ' ';
    gotoxy(x, y);
    printf(" ");
}

//food

void draw_food() {
    bool goodfood = false;
    int x, y;
    while (goodfood == false) {
        y = rand() % (ROW-2) + 1;
        x = rand() % (COL-2) + 1;
        if (map[y][x] == ' ') {
            gotoxy(x, y);
            printf("O");
            map[y][x] = 'O';
            goodfood = true;
        }
    }

}

void draw_morefood() {
    bool goodfood = false;
    int x, y;
    while (goodfood == false) {
        y = rand() % (ROW - 2) + 1;
        x = rand() % (COL - 2) + 1;
        if (map[y][x] == ' ') {
            gotoxy(x, y);
            setcolor(8, 0);
            printf("D");
            setcolor(7, 0);
            map[y][x] = 'D';
            goodfood = true;
        }
    }

}

void exfood(int a) {
    int goodexf = rand() % 40 + 1;
    if (a % goodexf == 0) {
        draw_morefood();
    }
}

//menu

void draw_menu() {
    gotoxy(42, 3);
    printf("Tester");
    gotoxy(42, 5);
    printf("start");
    gotoxy(40, 6);
    printf("scoreBroad");
}

void draw_name() {
    gotoxy(40, 3);
    printf("Tester");
    gotoxy(30, 5);
    printf("type your name ");
    scanf("%s",ra[5].name);
}

void draw_point(int x, int y) {
    gotoxy(x, y);
    printf("<--");
}


void Del_point(int x, int y) {
    gotoxy(x, y);
    printf("   ");
}

//side bar

void draw_score(int score) {
    int x = 100, y = 1;
    gotoxy(x, y);
    printf("score %d", score);
}

void draw_Time(int Time) {
    int si = 100, sj = 3;
    gotoxy(si, sj);
    printf("Time %03d", Time / 10);
}

void draw_skill(int i) {
    int si = 100, sj = 5;
    gotoxy(si, sj);
    if (!w[i].isUse) {
        printf("build wall!");
    }
    else {
        printf("go get more");
    }
}

//scoreboard

void Darw_scoreboard() {
    gotoxy(43, 7);
    printf("scoreboard");
    gotoxy(40, 9);
    printf("%s %d",ra[0].name,ra[0].point);
    gotoxy(40, 11);
    printf("%s %d", ra[1].name, ra[1].point);
    gotoxy(40, 13);
    printf("%s %d", ra[2].name, ra[2].point);
    gotoxy(40, 15);
    printf("%s %d", ra[3].name, ra[3].point);
    gotoxy(40, 17);
    printf("%s %d", ra[4].name, ra[4].point);
}
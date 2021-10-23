#include "fuc.h"
#include "map.h"
#include "score.h"


//player
void Del_player(int x, int y) { 
    gotoxy(x, y);
    printf(" ");
}

void draw_player(int x, int y) {
    gotoxy(x, y);
    printf("P");
}


void draw_mon(int x, int y) {
    map[y][x] = 'M';
    gotoxy(x, y);
    setcolor(2, 0);
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
        if (map[y][x] != '#' && map[y][x] != 'M') {
            gotoxy(x, y);
            printf("O");
            map[y][x] = 'O';
            goodfood = true;
        }
    }

}

void exfood(int a) {
    int goodexf = rand() % 10 + 1;
    if (a % goodexf == 0) {
        draw_food();
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
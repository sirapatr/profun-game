#include "fuc.h"
#include "map.h"
#include "draw.h"
#include "score.h"
#include "monster.h"


int main()
{
    //setConsole(screen_x, screen_y);

    char ch = ' ';
    setcursor(0);
    srand(time(NULL));
    scoreboard();

    bool start = false;
    bool play = true;

    while(!start){

        //menu
        draw_menu();
        draw_point(57, 5);
        do {
            if (_kbhit()) {
                ch = _getch();
                if (ch == 'w') {
                    draw_point(57,5);
                    Del_point(60, 6);
                    play = true;
                }
                if (ch == 's') {
                    draw_point(60, 6);
                    Del_point(57, 5);
                    play = false;
                }
                if (ch == ' ') {                  
                        break;
                }
                if (ch == 'x') {
                    start = true;
                }
                fflush(stdin);
            }
            Sleep(100);

        } while (ch != 'x');
        system("cls");

        //scoreboard
        if(!play) {
            startscoreboard();
            play = true;
        }
    
    
        //gameplay
        else {
            howToMove();
            int x = 1, y = 1, a = 0, Time = 300, foodcount = 10;
            make_map();
            draw_player(x, y);
            for (int i = 1; i <= foodcount; i++) {
                draw_food();
            }
            draw_score(a);
            draw_Time(Time);
            draw_skill(0);
            spawn_monster();

            do {
                if (_kbhit()) {
                    ch = _getch();

                    if (ch == 'w' && map[y - 1][x] != '#') {
                        Del_player(x, y); draw_player(x, --y);
                    }

                    if (ch == 'a' && map[y][x - 1] != '#') {
                        Del_player(x, y); draw_player(--x, y);
                    }

                    if (ch == 's' && map[y + 1][x] != '#') {
                        Del_player(x, y); draw_player(x, ++y);
                    }

                    if (ch == 'd' && map[y][x + 1] != '#') {
                        Del_player(x, y); draw_player(++x, y);
                    }
                    if (ch == 'e' && !w[0].isUse) {
                        draw_wall(0, x, y);
                        w[0].isUse = true;
                        draw_skill(0);
                    }
                    fflush(stdin);
                    if (map[y][x] == 'O') {
                        a++;
                        Time += 100;
                        map[y][x] = ' ';
                        if (a % 10 == 0 && foodcount > 1 ) {
                            foodcount--;
                        }
                        else {
                            draw_food();
                        }
                        exfood(a);
                        if (w[0].isUse) {
                            del_wall(0);
                        }
                        draw_score(a);
                        if (a % 6 == 5 && w[0].isUse) {
                            w[0].isUse = false;
                            draw_skill(0);
                        }
                    }

                    if (map[y][x] == 'D') {
                        foodcount++;
                        map[y][x] = ' ';
                        draw_food();
                    }

                }
                if (map[y][x] != 'M') {
                    for (int i = 0; i < 3; i++) {
                        setcolor(2, 0);
                        mon_move(i, x, y);
                    }
                    setcolor(4, 0);
                    mon_moveTolmY(3, x, y);
                    setcolor(4, 0);
                    mon_moveTolmY(4, x, y);
                }
                else { Time = 0; }
                Sleep(100);
                Time--;
                draw_Time(Time);


            } while (ch != 'p' && Time > 0);
            system("cls");
            Beep(400, 500);
            draw_name();
            system("cls");
            ra[5].point = a;
            rerankscore();
            scoreboardwrite();
            play = false;
        }
    }
    return 0;
}
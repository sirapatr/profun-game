#include "fuc.h"
#include "map.h"
#include "draw.h"
#include "score.h"
#include "monster.h"

int main()
{
    char ch = ' ';
    setcursor(0);
    srand(time(NULL));
    scoreboard();

    bool start = false;
    bool play = true;
    bool board = false;

    while(!start){

        //menu
        draw_menu();
        draw_point(47, 5);
        do {
            if (_kbhit()) {
                ch = _getch();
                if (ch == 'w') {
                    draw_point(47,5);
                    Del_point(50, 6);
                    play = true;
                    board = false;
                }
                if (ch == 's') {
                    draw_point(50, 6);
                    Del_point(47, 5);
                    play = false;
                    board = true;
                }
                if (ch == ' ') {
                    if (play || board) {
                        break;
                    }
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
        while(board) {
            Darw_scoreboard();
            do {
                if (_kbhit()) {
                    ch = _getch();
                    if (ch == ' ') {
                        board = false;
                        system("cls");
                    }
                }
            } while (ch != ' ');
        }
    
    
        //gameplay
        while (play) {
            int x = 1, y = 1, a = 0, Time = 300;
            make_map();
            draw_player(x, y);
            draw_food();
            draw_score(a);
            draw_Time(Time);
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
                    fflush(stdin);
                    if (map[y][x] == 'O') {
                        a++;
                        Time += 100;
                        map[y][x] = ' ';
                        draw_food();
                        exfood(a);
                        draw_score(a);
                    }

                    

                }
                if (map[y][x] != 'M') {
                    for (int i = 0; i < 5; i++) {
                        mon_move(i, x, y);
                    }
                }
                else { Time = 0; }
                Sleep(100);
                Time--;
                draw_Time(Time);


            } while (ch != 'p' && Time > 0);
            system("cls");
            draw_name();
            system("cls");
            ra[5].point = a;
            rerankscore();
            play = false;
        }
    }
    return 0;
}
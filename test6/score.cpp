#include "fuc.h"
#include "score.h"

RANKING ra[6];

void scoreboard()
{

    FILE* fp;
    int r = 0;
    fp = fopen("scoreboard.txt", "r");
    while (fscanf(fp, "%s %d\n", ra[r].name, &(ra[r].point)) != EOF) {
        r++;
    }
 fclose(fp);
    
}

void scoreboardwrite()
{

    FILE* fp;
    int r = 0;
    fp = fopen("scoreboard.txt", "w");
    for (int r = 0; r < 5;r++) {
        fprintf(fp, "%s %d\n", ra[r].name, ra[r].point);
    }
    fclose(fp);

}

void rerankscore() {
    int point;
    char name[50];
    for (int i = 5; i > 0; i--) {
        if (ra[i].point >= ra[i - 1].point) {
        	
            point = ra[i - 1].point;
            strcpy(name, ra[i-1].name);
            
            ra[i - 1].point = ra[i].point;
            strcpy(ra[i - 1].name, ra[i].name);
            
            ra[i].point = point;
            strcpy(ra[i].name,name);
        }

    }

}

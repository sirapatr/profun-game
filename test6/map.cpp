#include "fuc.h"
#include "map.h"

char map[ROW][COL];

void readMap(char *filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    int r=0;
    
    while (fscanf(fp, "%[^\n] ", map[r]) != EOF) {
        r++;
    }
    fclose(fp);
}



void make_map()
{
	int mapno= rand() %3 +1;
	char s[25];
	sprintf(s,"map/map%02d.txt",mapno);
	printf("%s\n",s);
	readMap(s);
	setcolor(1, 0);
	gotoxy(0, 0);
	for (int i=0; i<ROW; i++) {
		printf("%s\n", map[i]);
	}
	setcolor(7, 0);
}

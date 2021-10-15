#pragma once
#ifndef __MAP_H__
#define __MAP_H__
#define ROW 22
#define COL 92

extern char map[ROW][COL];

void readMap(char* filename);
void make_map();


#endif
#pragma once

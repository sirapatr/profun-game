#pragma once
#ifndef __SCORE_H__
#define __SCORE_H__

typedef struct {
    char name[20];
    int point;
} RANKING;

extern RANKING ra[6];
void rerankscore();
void scoreboard();
void scoreboardwrite();

#endif
#pragma once

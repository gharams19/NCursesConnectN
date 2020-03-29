//
// Created by Gharam Alsaedi on 2/3/19.
// hello

#include "CursorTrackedWindow.h"

#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H

typedef struct Board_Struct {
    char **theBoard;
    int numRows;
    int numCols;
    char blankChar;
    int neededToWin;
} Board;

Board makeBoard(int numRows, int numCols, char blankChar, int win);

void cleanUpBoard(Board *board);

void logBoard(FILE *fp, CursorTrackedWindow *win);

void logPlayArea(FILE *fp, CursorTrackedWindow *win , bool end, int playerTurn);

#endif //NCURSESCONNECTN_BOARD_H

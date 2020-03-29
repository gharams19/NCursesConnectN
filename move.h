//
// Created by Gharam Alsaedi on 2/3/19.
//

#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H

#include "CursorTrackedWindow.h"
#include "board.h"


typedef struct Move_Struct {
    int row, col;
    char marker;
} Move;

void getValidMove(Board *board, int playerTurn, CursorTrackedWindow *playArea, FILE *fp, CursorTrackedWindow* boardWindow, CursorTrackedWindow* announceArea);

int rowToDrop(Board board, int col);

void placeMove(Move move, Board *board, CursorTrackedWindow *win);

int changeTurn(int playerTurn);

#endif //NCURSESCONNECTN_MOVE_H

//
// Created by Gharam Alsaedi on 2/4/19.
//

#ifndef NCURSESCONNECTN_WIN_H
#define NCURSESCONNECTN_WIN_H

#include <stdbool.h>
#include "board.h"
#include "move.h"

bool VerticalWin(Board board, char currPlayer);

bool HorizontalWin(Board board, char currPlayer);

bool MajorDiagonal(Board board, char currPlayer);

bool MinorDiagonal(Board board, char currPlayer);

bool CheckWinner(Board board, char currPlayer);

bool CheckTie(Board board);

bool isGameOver(Board board, int currPlayer);

void declareWinner(Board board, int playerTurn, FILE *fp);


#endif //NCURSESCONNECTN_WIN_H

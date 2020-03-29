//
// Created by Gharam Alsaedi on 2/3/19.
//

#include <stdlib.h>
#include "board.h"
#include <string.h>

Board makeBoard(int rows, int cols, char blankChar, int win) {
    Board board;
    board.theBoard = (char **) malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; ++i) {
        board.theBoard[i] = (char *) malloc(cols * sizeof(char));
        for (int j = 0; j < cols; ++j) {
            board.theBoard[i][j] = blankChar;
        }
    }
    board.numCols = cols;
    board.numRows = rows;
    board.neededToWin = win;
    board.blankChar = blankChar;
    return board;
}


void cleanUpBoard(Board *board) {

    for (int row = 0; row < board->numRows; ++row) {
        free(board->theBoard[row]);
    }
    free(board->theBoard);
    board->theBoard = NULL;
    board->numRows = 0;
    board->numCols = 0;
}


void logPlayArea(FILE *fp, CursorTrackedWindow *win, bool end , int playerTurn) {
    if(end) {
        if(playerTurn == 0) {

            werase(win->cursesWin);
            mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol, 'O');
            wmove(win->cursesWin, win->cursorRow, win->cursorCol);
        }
        else{
            werase(win->cursesWin);
            mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol, 'X');
            wmove(win->cursesWin, win->cursorRow, win->cursorCol);
        }
    }
    int numRows = getNumRows(win), numCols = getNumCols(win);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            fprintf(fp, "%c", (char) mvwinch(win->cursesWin, i, j));
        }
    }
    fprintf(fp, "%c", '\n');
    wmove(win->cursesWin, win->cursorRow, win->cursorCol);
}

void logBoard(FILE *fp, CursorTrackedWindow *win) {
    int numRows = getNumRows(win), numCols = getNumCols(win);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            fprintf(fp, "%c", (char) mvwinch(win->cursesWin, i, j));
        }
        fprintf(fp, "%c", '\n');
    }
    wmove(win->cursesWin, win->cursorRow, win->cursorCol);
}





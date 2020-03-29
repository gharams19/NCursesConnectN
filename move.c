//
// Created by Gharam Alsaedi on 2/3/19.
//
#include <ncurses.h>
#include "move.h"
#include "board.h"
#include "InputValidation.h"
#include "CursorTrackedWindow.h"
#include "win.h"

void getValidMove(Board *board, int playerTurn, CursorTrackedWindow *playArea, FILE *fp, CursorTrackedWindow* boardWindow, CursorTrackedWindow* announceArea) {
    Move move;


    while (true) {
        int input = wgetch(playArea->cursesWin);
        if (input == 'a' || input == 'j') {
            if (playArea->cursorCol > 0) {
                playArea->cursorCol -= 1;
                wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                werase(playArea->cursesWin);
                if (playerTurn == 0) {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'X');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                } else {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'O');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                }
                logPlayArea(fp, playArea,false,playerTurn);
                logBoard(fp, boardWindow);
                logPlayArea(fp, announceArea,false,playerTurn);
                fprintf(fp,"%c",'\n');

            } else if (playArea->cursorCol == 0) {
                playArea->cursorCol = board->numCols - 1;
                wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                werase(playArea->cursesWin);

                if (playerTurn == 0) {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'X');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                } else {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'O');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                }
                logPlayArea(fp, playArea,false,playerTurn);
                logBoard(fp, boardWindow);
                logPlayArea(fp, announceArea,false,playerTurn);
                fprintf(fp,"%c",'\n');


            }
        } else if (input == 's' || input == 'k') {
            if (playArea->cursorCol < board->numCols - 1) {
                playArea->cursorCol += 1;
                wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);


                werase(playArea->cursesWin);

                if (playerTurn == 0) {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'X');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                } else {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'O');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                }
                logPlayArea(fp, playArea,false,playerTurn);
                logBoard(fp, boardWindow);
                logPlayArea(fp, announceArea,false,playerTurn);
                fprintf(fp,"%c",'\n');


            } else if (playArea->cursorCol >= board->numCols - 1) {
                playArea->cursorCol = 0;

                wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);


                werase(playArea->cursesWin);

                if (playerTurn == 0) {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'X');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);


                } else {
                    mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'O');
                    wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

                }
                logPlayArea(fp, playArea,false,playerTurn);
                logBoard(fp, boardWindow);
                logPlayArea(fp, announceArea,false,playerTurn);
                fprintf(fp,"%c",'\n');
            }
        } else if ((input == ' ' || input == '\n') &&
                   !isFull(board, playArea->cursorCol)) {
            move.row = rowToDrop(*board, playArea->cursorCol);
            move.col = playArea->cursorCol;
            move.marker = "XO"[playerTurn];
            werase(playArea->cursesWin);
            placeMove(move, board, boardWindow);


            if (playerTurn == 0) {
                mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'O');
                wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

            } else {
                mvwaddch(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol, 'X');
                wmove(playArea->cursesWin, playArea->cursorRow, playArea->cursorCol);

            }
            if(!isGameOver(*board,playerTurn)) {
                logPlayArea(fp, playArea, false, playerTurn);
                logBoard(fp, boardWindow);
                logPlayArea(fp, announceArea, false, playerTurn);
                fprintf(fp, "%c", '\n');
            }


            return;

        }
        else{
            if(!isGameOver(*board,playerTurn)) {
                logPlayArea(fp, playArea, false, playerTurn);
                logBoard(fp, boardWindow);
                logPlayArea(fp, announceArea, false, playerTurn);
                fprintf(fp, "%c", '\n');
            }
        }







        wrefresh(playArea->cursesWin);


    }
}


int rowToDrop(Board board, int col) {
    for (int r = board.numRows - 1; r >= 0; r--) {
        if (board.theBoard[r][col] == '*') {
            return r;
        }
    }
    return -1;
}

void placeMove(Move move, Board *board, CursorTrackedWindow *win) {

    board->theBoard[move.row][move.col] = move.marker;
    win->cursorCol = move.col;
    win->cursorRow = move.row;
    addCharacter(win, move.marker);
    wrefresh(win->cursesWin);
}


int changeTurn(int playerTurn) {
    if (playerTurn == 0) {
        return 1;
    } else {
        return 0;
    }

}


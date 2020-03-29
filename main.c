#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include "CursorTrackedWindow.h"
#include "board.h"
#include "move.h"
#include "win.h"


void readArgs(char **argv, int *numRows, int *numCols, int *neededTowin) {
    *numRows = atoi(argv[1]);
    *numCols = atoi(argv[2]);
    *neededTowin = atoi(argv[3]);
}

int main(int argc, char *argv[]) {

    int numRows, numCols, neededTowin;
    readArgs(argv, &numRows, &numCols, &neededTowin);
    char *fileName = argv[4];

    initscr();
    noecho();
    cbreak();

    CursorTrackedWindow boardWindow = newCursorTrackedWindow(numRows, numCols, 1, 0);
    CursorTrackedWindow playArea = newCursorTrackedWindow(1, numCols, 0, 0);
    CursorTrackedWindow announceArea = newCursorTrackedWindow(1, numCols, numRows + 1, 0);
    fillWindow(&boardWindow, '*');

    keypad(playArea.cursesWin, true);
    wrefresh(playArea.cursesWin);
    wrefresh(boardWindow.cursesWin);

    Board board = makeBoard(numRows, numCols, '*', neededTowin);
    int playerTurn = 0;

    FILE *fp = fopen(fileName, "w");
    moveAndAddCharacter(&playArea, playArea.cursorCol, playArea.cursorRow, 'X');
    logPlayArea(fp, &playArea,false,playerTurn);
    logBoard(fp, &boardWindow);
    logPlayArea(fp, &announceArea,false,playerTurn);
    fprintf(fp,"%c",'\n');



    while (!isGameOver(board, playerTurn)) {

        wmove(playArea.cursesWin, playArea.cursorRow, playArea.cursorCol);
        getValidMove(&board, playerTurn, &playArea, fp,&boardWindow,&announceArea);

        playerTurn = changeTurn(playerTurn);

//        if (!isGameOver(board, playerTurn)) {
//            logPlayArea(fp, &playArea, false,playerTurn);
//            logBoard(fp, &boardWindow);
//            logPlayArea(fp, &announceArea,false,playerTurn);
//            fprintf(fp,"%c",'\n');
//        }



    }
    logPlayArea(fp, &playArea, true,playerTurn);
    logBoard(fp, &boardWindow);
    declareWinner(board, playerTurn, fp);

    delwin(boardWindow.cursesWin);
    delwin(playArea.cursesWin);
    delwin(announceArea.cursesWin);
    endwin();

    fclose(fp);

    cleanUpBoard(&board);


    return 0;
}

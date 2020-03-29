//
// Created by Gharam Alsaedi on 2/4/19.
//

#include <stdlib.h>
#include "win.h"

bool VerticalWin(Board board, char currPlayer) {
    int n;
    char cur;
    for (int i = 0; i < board.numRows; i++) {
        for (int j = 0; j <= board.numCols - board.neededToWin ; j++) {
            n =0;
            cur = board.theBoard[i][j];
            if(cur == board.blankChar){
                continue;
            }
            for (int k = 0; k <board.neededToWin ; k++) {
                if(cur != board.theBoard[i][j+k]){
                    break;
                }
                n++;
                if(n == board.neededToWin){
                    return true;
                }
            }
        }
    }
    return false;


}

bool HorizontalWin(Board board, char currPlayer) { //works
int n;
char cur;
    for (int i = 0; i <= board.numRows - board.neededToWin; i++) {
        for (int j = 0; j <board.numCols ; j++) {
            n = 0;
            cur = board.theBoard[i][j];
            if(cur == board.blankChar){
                continue;
            }
            for (int k = 0; k <board.neededToWin ; k++) {
                if(cur != board.theBoard[i + k][j]){
                    break;
                }
                n++;
                if(n == board.neededToWin){
                    return true;
                }
            }
        }
    }
    return false;

}


bool MajorDiagonal(Board board, char currPlayer) {

    int count;
    for (int r = 0; r < board.numRows - board.neededToWin; r++) {
        count = 0;
        int row, col;
        for (row = r, col = 0; row < board.numRows && col < board.numCols; row++, col++) {
            if (board.theBoard[row][col] == currPlayer) {
                count++;
                if (count >= board.neededToWin) return true;
            } else {
                count = 0;
            }
        }
    }

    for (int colStart = 1; colStart < board.numCols - board.neededToWin; colStart++) {
        count = 0;
        int row, col;
        for (row = 0, col = colStart; row < board.numRows && col < board.numCols; row++, col++) {
            if (board.theBoard[row][col] == currPlayer) {
                count++;
                if (count >= board.neededToWin) return true;
            } else {
                count = 0;
            }
        }
    }
    return false;
}


bool MinorDiagonal(Board board, char currPlayer) {
    int count;
    for (int r = board.numRows - 1; r >= 0; r--) {
        count = 0;
        int row, col;
        for (row = r, col = 0; row >= 0 && col < board.numCols; row--, col++) {
            if (board.theBoard[row][col] == currPlayer) {
                count++;
                if (count >= board.neededToWin) return true;
            } else {
                count = 0;
            }
        }
    }

    for (int colStart = 1; colStart < board.numCols - board.neededToWin; colStart++) {
        count = 0;
        int row, col;
        for (row = board.numRows - 1, col = colStart; row >= 0 && col < board.numCols; row--, col++) {
            if (board.theBoard[row][col] == currPlayer) {
                count++;
                if (count >= board.neededToWin) return true;
            } else {
                count = 0;
            }
        }
    }
    return false;
}


bool CheckWinner(Board board, char currPlayer) {
    return (MinorDiagonal(board, currPlayer) || MajorDiagonal(board, currPlayer) || VerticalWin(board, currPlayer) || HorizontalWin(board, currPlayer));

}


bool CheckTie(Board board) {
    for (int c = 0; c < board.numCols; ++c) {
        if (board.theBoard[0][c] == '*') {
            return false;
        }

    }
    return true;
}

bool isGameOver(Board board, int currPlayer) {

    return (CheckWinner(board, 'X') || CheckWinner(board, 'O') || CheckTie(board));
}

void declareWinner(Board board, int playerTurn, FILE *fp) {
    bool win1 = CheckWinner(board, 'X');
    bool win2 = CheckWinner(board, 'O');

    if (win1 || win2) {
        if(playerTurn == 1) {

            fprintf(fp, "%s", "Player 1 won! ");
            fprintf(fp, "%c", '\n');
        }
        else{
            fprintf(fp, "%s", "Player 2 won! ");
            fprintf(fp, "%c", '\n');
        }


    }
    else {
        fprintf(fp, "%s", "Tie Game ");
        fprintf(fp, "%c", '\n');


    }

}

//
// Created by Gharam Alsaedi on 2/5/19.
//

#include <stdio.h>
#include <ctype.h>
#include "InputValidation.h"
#include "board.h"

bool is_valid_format(int num_args_read, int num_args_needed) {
    bool valid = num_args_read == num_args_needed;
    char c;


    do {
        scanf("%c", &c);
        if (!isspace(c)) {
            valid = false;
        }
    } while (c != '\n');

    return valid;
}

bool is_in_bounds(int val, int lower_bound, int upper_bound) {
    return val >= lower_bound && val <= upper_bound;
}

bool isFull(struct Board_Struct *board, int col) {
    if (board->theBoard[0][col] == '*') {
        return false;
    } else {
        return true;
    }
}
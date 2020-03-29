//
// Created by Gharam Alsaedi on 2/5/19.
//

#ifndef NCURSESCONNECTN_INPUTVALIDATION_H
#define NCURSESCONNECTN_INPUTVALIDATION_H

#include <stdbool.h>
#include "board.h"

bool is_valid_format(int num_args_read, int num_args_needed);

bool is_in_bounds(int val, int lower_bound, int upper_bound);

bool isFull(Board *board, int col);

#endif //NCURSESCONNECTN_INPUTVALIDATION_H

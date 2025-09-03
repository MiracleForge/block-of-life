#ifndef GAME_H
#define GAME_H

#include "config.h"

void handle_game_state(MenuState *current_state);

int **game_initialization(int *cols, int *rows, CellData *cell_info);
void game_logic(int *cols, int *rows, int **cell_matrix, CellData *cell_info);
#endif

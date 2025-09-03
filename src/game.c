#include "../include/config.h"
#include <stdio.h>
#include <stdlib.h>

int **game_initialization(int *cols, int *rows, CellData *cell_info) {
  int **matrix = NULL;

  *cols = terminal_size.ws_col - 2;
  *rows = terminal_size.ws_row - 2;

  matrix = malloc(*rows * sizeof(int *));
  if (!matrix) {
    fprintf(stderr, "ERROR: malloc failed while allocating rows\n");
    exit(1);
  }

  for (int i = 0; i < *rows; i++) {
    matrix[i] = calloc(*cols, sizeof(int));
    if (!matrix[i]) {
      fprintf(stderr, "ERROR: malloc failed while allocating row %d\n", i);
      for (int j = 0; j < i; j++)
        free(matrix[j]);
      free(matrix);
      exit(1);
    }
  }

  return matrix;
}

void handle_game_state(MenuState *current_state) {
  int ch = getchar();

  switch (*current_state) {

  case MENU_START:
    if (ch == 's' || ch == 'c') {
      *current_state = (ch == 's') ? MENU_GAME_RUN : MENU_OPTIONS;
    }
    break;

  case MENU_GAME_RUN:
    if (ch == 'p' || ch == 'q')
      *current_state = (ch == 'p') ? MENU_PAUSE : MENU_GAME_QUIT;
    break;

  case MENU_PAUSE:
    if (ch == 'r' || ch == 'm' || ch == 'q')
      *current_state = (ch == 'r')   ? MENU_GAME_RUN
                       : (ch == 'm') ? MENU_START
                                     : MENU_GAME_QUIT;
    break;

  case MENU_OPTIONS:
    if (ch == 'b')
      // TODO: Adicionar as opções customizáveis
      *current_state = MENU_GAME_QUIT;
    break;

  case MENU_GAME_OVER:
    // TODO: Adicionar as opções customizáveis
    *current_state = MENU_GAME_QUIT;
    break;

  default:
  MENU_GAME_QUIT:
    // TODO: Adicionar as opções customizáveis
    *current_state = MENU_GAME_QUIT;
    break;
  }
}

void game_logic(int *cols, int *rows, int **cell_matrix, CellData *cell_info) {
  printf("GAME RUNNING");
};

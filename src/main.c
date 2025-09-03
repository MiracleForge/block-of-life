#include "../include/config.h"
#include "../include/draw.h"
#include "../include/game.h"
#include "../include/utils.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int **cell_matrix = NULL;
int rows = 0, cols = 0;

void handle_sigint(int sig) {
  if (cell_matrix) {
    for (int r = 0; r < rows; r++) {
      free(cell_matrix[r]);
    }
    free(cell_matrix);
    cell_matrix = NULL;
  }
  reset_input_mode();
  exit(0);
}

int main() {

  if (set_input_mode() != 0) {
    fprintf(stderr, "⚡ Oops! Terminal input mode setup failed.\n");
    return 1;
  }

  if (signal(SIGINT, handle_sigint) == SIG_ERR ||
      signal(SIGWINCH, handle_resize) == SIG_ERR) {
    fprintf(stderr, "⚡ Failed to register signal handlers!\n");
    reset_input_mode();
    return 1;
  }

  MenuState current_state = MENU_START;
  MenuState prev_state = MENU_START;
  CellData cell_info = {0, 0, 0, 0};

  fd_set fds;
  struct timeval tv;

  while (current_state != MENU_GAME_QUIT) {
    UpdateTerminalSize();
    clearScreen();
    drawHeader(&current_state, &cell_info);
    drawGameBoxCentered(&current_state);

    if (current_state == MENU_GAME_RUN && prev_state != MENU_GAME_RUN) {
      cell_matrix = game_initialization(&cols, &rows, &cell_info);
    }

    if (current_state == MENU_GAME_RUN && cell_matrix != NULL) {
      game_logic(&cols, &rows, cell_matrix, &cell_info);
    }

    fflush(stdout);

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    tv.tv_sec = 0;
    tv.tv_usec = 16667; // ~60 FPS

    int result = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    if (result > 0 && FD_ISSET(STDIN_FILENO, &fds)) {
      handle_game_state(&current_state);
    }

    prev_state = current_state;
  }

  if (cell_matrix) {
    for (int r = 0; r < rows; r++) {
      free(cell_matrix[r]);
    }
    free(cell_matrix);
    cell_matrix = NULL;
  }

  reset_input_mode();
  return 0;
}

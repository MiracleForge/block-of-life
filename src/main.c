#include "../include/config.h"
#include "../include/draw.h"
#include "../include/game.h"
#include "../include/utils.h"
#include <bits/types/struct_timeval.h>
#include <signal.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {

  if (set_input_mode() != 0) {
    fprintf(stderr, "ERROR: Failed to set terminal input mode\n");
    return 1;
  }

  if (signal(SIGINT, handle_sigint) == SIG_ERR ||
      signal(SIGWINCH, handle_resize) == SIG_ERR) {
    fprintf(stderr, "ERROR: Failed to register signal handlers\n");
    reset_input_mode();
    return 1;
  }

  MenuState current_state = MENU_START;
  CellData cell_info = {0, 0, 0, 2};
  fd_set fds;
  struct timeval tv;

  while (current_state != MENU_GAME_QUIT) {
    UpdateTerminalSize();
    clearScreen();
    drawHeader(&current_state, &cell_info);
    drawGameBoxCentered(&current_state);
    fflush(stdout);

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    tv.tv_sec = 0;
    tv.tv_usec = 16667; // ~60 FPS

    int result = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

    if (result > 0 && FD_ISSET(STDIN_FILENO, &fds)) {
      handle_game_state(&current_state);
    }
  }

  reset_input_mode();
  return 0;
}

#include "../include/config.h"
#include "../include/draw.h"
#include "../include/game.h"
#include "../include/utils.h"
#include <bits/types/struct_timeval.h>
#include <signal.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

struct timeval tv;
fd_set fds;

MenuState current_state = MENU_START;
CellData cell_info = {
    .aliveCells = 0, .deadCells = 0, .cellsType1 = 0, .cellsType2 = 2};

int main() {

  set_input_mode();
  signal(SIGINT, handle_sigint);
  signal(SIGWINCH, handle_resize);

  while (current_state != MENU_GAME_QUIT) {
    UpdateTerminalSize();
    clearScreen();
    drawHeader(&current_state, &cell_info);
    drawGameBoxCentered(&current_state);
    fflush(stdout);

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    tv.tv_sec = 0;
    tv.tv_usec = 16667; // ~60 FPS (1/60 s)

    int result = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

    if (result > 0 && FD_ISSET(STDIN_FILENO, &fds)) {
      handle_game_state(&current_state);
    }
  }

  reset_input_mode();
  return 0;
}

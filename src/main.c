#include "../include/draw.h"
#include "../include/utils.h"
#include <bits/types/struct_timeval.h>
#include <ctype.h>
#include <signal.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

struct timeval tv;
fd_set fds;

int main() {
  int quit = 0;
  int needs_redraw = 1; // flag to controw when to draw
  MenuState current_state = MENU_START;

  set_input_mode();
  signal(SIGINT, handle_sigint);

  while (!quit) {
    if (needs_redraw) {
      clearScreen();
      drawHeader(current_state);
      drawGameBoxCentered();
      fflush(stdout);
      needs_redraw = 0;
    }

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    tv.tv_sec = 0;
    tv.tv_usec = 16667; // ~60 FPS (1/60 s)

    int result = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

    if (result > 0 && FD_ISSET(STDIN_FILENO, &fds)) {
      int ch = getchar();
      if (tolower(ch) == 'q') {
        quit = 1;
      }
      needs_redraw = 1;
    }
  }

  reset_input_mode();
  return 0;
}

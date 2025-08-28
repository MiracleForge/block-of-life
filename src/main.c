#include "../include/draw.h"
#include "../include/utils.h"
#include <signal.h>
#include <unistd.h>

int main() {
  int quit = 0;
  set_input_mode();
  signal(SIGINT, handle_sigint);

  while (!quit) {
    clearScreen();
    drawHeader();
    drawGameBox();
    sleep(3);
  }

  reset_input_mode();
  return 0;
}

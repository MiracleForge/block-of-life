#include "../include/draw.h"
#include "../include/utils.h"
#include <stdio.h>
#include <unistd.h>

int main() {
  int quit = 0;
  set_input_mode();

  while (!quit) {
    clearScreen();
    printf("WELLCOME TO GAME OF LIFE\n");
    drawGameBox();
    sleep(3);
  }

  reset_input_mode();
  return 0;
}

#include "../include/config.h"
#include <asm-generic/ioctls.h>
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

void drawGameBox() {
  // top
  printf("┏");
  for (int t = 0; t < COLLUMS; t++)
    printf("━");
  printf("┓\n");
  // vertical lines
  for (int r = 0; r < ROWS; r++) {
    printf("┃");
    for (int t = 0; t < COLLUMS; t++)
      printf(" "); // internal space
    printf("┃\n");
  }
  // base
  printf("┗");
  for (int t = 0; t < COLLUMS; t++)
    printf("━");
  printf("┛\n");
}

void drawHeader() {
  const char *header = "WELLCOME TO GAME OF LIFE\n";
  const char *footer = "--------------------------------";
  // printf("%*s\n" $COLLUMS, header);
  UpdateTerminalSize();

  int padding_center = (terminal_size.ws_col - strlen(header)) / 2;

  printf("%*s%s", padding_center, "", header);
}

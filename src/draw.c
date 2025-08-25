#include "../include/config.h"
#include <stdio.h>

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
      printf(" "); // espaço interno
    printf("┃\n");
  }

  // base
  printf("┗");
  for (int t = 0; t < COLLUMS; t++)
    printf("━");
  printf("┛\n");
}

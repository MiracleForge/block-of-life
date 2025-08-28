#include "../include/config.h"
#include <asm-generic/ioctls.h>
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

void drawGameBoxCentered() {
  int box_width = terminal_size.ws_col - PADDING;
  int box_height = terminal_size.ws_row - PADDING_TOP;

  int left_padding = (terminal_size.ws_col - box_width - 2) / 2;
  if (left_padding < 0)
    left_padding = 0;

  // Top border
  printf("\n");
  printf("%*s┏", left_padding, "");
  for (int t = 0; t < box_width; t++)
    printf("━");
  printf("┓\n");

  // Vertical lines
  for (int r = 0; r < box_height; r++) {
    printf("%*s┃", left_padding, "");
    for (int t = 0; t < box_width; t++)
      printf(" ");
    printf("┃\n");
  }

  // Bottom border
  printf("%*s┗", left_padding, "");
  for (int t = 0; t < box_width; t++)
    printf("━");
  printf("┛\n");
}

int getPaddingCenter(const char *string) {
  return (terminal_size.ws_col - strlen(string)) / 2;
}

void drawHeader() {
  const char *header = "WELLCOME TO GAME OF LIFE\n";
  const char *footer = "--------------------------------";
  char *menuOptions = "(s) Start          (c)Configurations          (q)Quit";
  // printf("%*s\n" $COLLUMS, header);
  UpdateTerminalSize();

  int padding_center = getPaddingCenter(header);
  int options_centered = getPaddingCenter(menuOptions);
  printf("\n%*s%s", padding_center, "", header);

  printf("\n%*s%s", options_centered, "", menuOptions);
}

#include "../include/draw.h"
#include "../include/config.h"
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

void drawGameBoxCentered(MenuState *current_state) {
  if (*current_state != MENU_GAME_RUN)
    return;

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

void drawHeader(MenuState *current_state) {

  UpdateTerminalSize();
  const char *header = "WELCOME TO GAME OF LIFE\n";
  int padding_header = getPaddingCenter(header);
  printf("\n%*s%s", padding_header, "", header);

  Menu menus[] = {
      {MENU_START, "(s) Start          (c) Configurations          (q) Quit"},
      {MENU_OPTIONS, "(1) Option A      (2) Option B               (b) Back"},
      {MENU_PAUSE, "(r) Resume         (q) Quit to Main Menu"},
      {MENU_GAME_OVER, "Game Over! Press (m) to return to main menu"},
      {MENU_GAME_RUN, "Alive cells     %s     Death cells     %s      Species "
                      "cells   %s      (p) Pause"}};

  int menus_data_lenght = sizeof(menus) / sizeof(menus[0]);

  for (int h = 0; h < menus_data_lenght; h++) {
    if (menus[h].state == *current_state) {
      printf("%*s%s\n", getPaddingCenter(menus[h].text), "", menus[h].text);
      break;
    }
  }
}

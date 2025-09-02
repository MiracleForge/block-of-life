#include "../include/draw.h"
#include "../include/config.h"
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>

static const Menu menus[] = {
    {MENU_START, "(s) Start          (c) Configurations          (q) Quit"},
    {MENU_OPTIONS, "(1) Option A      (2) Option B               (b) Back"},
    {MENU_PAUSE, "(r) Resume         (q) Quit to Main Menu"},
    {MENU_GAME_OVER, "Game Over! Press (m) to return to main menu"},
    {MENU_GAME_RUN, ""}};

void drawGameBoxCentered(MenuState *current_state) {
  if (*current_state != MENU_GAME_RUN)
    return;

  int box_width = terminal_size.ws_col - PADDING;
  int box_height = terminal_size.ws_row - PADDING_TOP;

  int left_padding = (terminal_size.ws_col - box_width - 2) / 2;
  if (left_padding < 0)
    left_padding = 0;

  // Top border
  putchar('\n');
  // Top border
  printf("%*s%s", left_padding, "", "┏");
  for (int t = 0; t < box_width; t++)
    printf("%s", "━");
  printf("%s\n", "┓");

  // Vertical lines
  for (int r = 0; r < box_height; r++) {
    printf("%*s%s", left_padding, "", "┃");
    for (int t = 0; t < box_width; t++)
      putchar(' ');
    printf("%s\n", "┃");
  }

  // Bottom border
  printf("%*s%s", left_padding, "", "┗");
  for (int t = 0; t < box_width; t++)
    printf("%s", "━");
  printf("%s\n", "┛");
}

int getPaddingCenter(const char *string) {
  int pad = (terminal_size.ws_col - strlen(string)) / 2;
  return pad > 0 ? pad : 0;
}

void drawHeader(MenuState *current_state, CellData *cell_info) {

  const char *header = "WELCOME TO GAME OF LIFE\n";
  printf("%*s%s", getPaddingCenter(header), "", header);

  if (*current_state == MENU_GAME_RUN) {
    char buffer[256];
    snprintf(buffer, sizeof(buffer),
             "Alive cells %d   Death cells %d   Species cells %d   (p) Pause",
             cell_info->aliveCells, cell_info->deadCells,
             cell_info->cellsType2);
    printf("%*s%s\n", getPaddingCenter(buffer), "", buffer);
    return;
  }

  switch (*current_state) {
  case MENU_START:
    printf("%*s%s\n", getPaddingCenter(menus[0].text), "", menus[0].text);
    break;
  case MENU_OPTIONS:
    printf("%*s%s\n", getPaddingCenter(menus[1].text), "", menus[1].text);
    break;
  case MENU_PAUSE:
    printf("%*s%s\n", getPaddingCenter(menus[2].text), "", menus[2].text);
    break;
  case MENU_GAME_OVER:
    printf("%*s%s\n", getPaddingCenter(menus[3].text), "", menus[3].text);
    break;
  default:
    break;
  }
}

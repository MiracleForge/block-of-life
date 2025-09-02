#ifndef DRAW_H
#define DRAW_H
#include "config.h"

typedef struct {
  MenuState state;
  const char *text;
} Menu;

void drawGameBoxCentered(MenuState *current_state);
void drawHeader(MenuState *current_state, CellData *cell_info);

#endif

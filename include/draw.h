#ifndef DRAW_H
#define DRAW_H
#include "config.h"

typedef struct {
  MenuState state;
  const char *text;
} Menu;

void drawGameBoxCentered(void);
void drawHeader(MenuState current_state);

#endif

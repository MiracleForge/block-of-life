#ifndef DRAW_H
#define DRAW_H
typedef enum { MENU_START, MENU_OPTIONS, MENU_PAUSE, MENU_GAME_OVER } MenuState;

typedef struct {
  MenuState state;
  const char *text;
} Menu;

void drawGameBoxCentered(void);
void drawHeader(MenuState current_state);

#endif

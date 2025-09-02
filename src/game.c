#include "../include/config.h"
#include <stdio.h>

void handle_game_state(MenuState *current_state) {
  int ch = getchar();

  switch (*current_state) {

  case MENU_START:
    if (ch == 's' || ch == 'c') {
      *current_state = (ch == 's') ? MENU_GAME_RUN : MENU_OPTIONS;
    }
    break;

  case MENU_GAME_RUN:
    if (ch == 'p' || ch == 'q')
      *current_state = (ch == 'p') ? MENU_PAUSE : MENU_GAME_QUIT;
    break;

  case MENU_PAUSE:
    if (ch == 'r' || ch == 'm' || ch == 'q')
      *current_state = (ch == 'r')   ? MENU_GAME_RUN
                       : (ch == 'm') ? MENU_START
                                     : MENU_GAME_QUIT;
    break;

  case MENU_OPTIONS:
    // TODO: Adicionar as opções customizáveis
    *current_state = MENU_GAME_QUIT;
    break;

  case MENU_GAME_OVER:
    // TODO: Adicionar as opções customizáveis
    *current_state = MENU_GAME_QUIT;
    break;

  default:
  MENU_GAME_QUIT:
    // TODO: Adicionar as opções customizáveis
    *current_state = MENU_GAME_QUIT;
    break;
  }
}

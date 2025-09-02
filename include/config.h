#ifndef CONFIG_H
#define CONFIG_H

#include <sys/ioctl.h>

#define PADDING 4
#define PADDING_TOP 8

typedef enum {
  MENU_START,
  MENU_OPTIONS,
  MENU_PAUSE,
  MENU_GAME_OVER,
  MENU_GAME_RUN,
  MENU_GAME_QUIT
} MenuState;

typedef struct {
  int aliveCells;
  int deadCells;
  int cellsType1;
  int cellsType2;
} CellData;

extern struct winsize terminal_size;

void UpdateTerminalSize();
#endif

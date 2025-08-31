#ifndef CONFIG_H
#define CONFIG_H

#include <sys/ioctl.h>

#define PADDING 4
#define PADDING_TOP 8

typedef enum { MENU_START, MENU_OPTIONS, MENU_PAUSE, MENU_GAME_OVER } MenuState;

extern struct winsize terminal_size;

void UpdateTerminalSize();
#endif

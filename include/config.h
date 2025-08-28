#ifndef CONFIG_H
#define CONFIG_H

#include <sys/ioctl.h>

extern struct winsize terminal_size;

void UpdateTerminalSize();

#define ROWS 20
#define COLLUMS 150

#endif

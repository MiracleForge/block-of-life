#ifndef CONFIG_H
#define CONFIG_H

#include <sys/ioctl.h>

#define PADDING 4
#define PADDING_TOP 6
extern struct winsize terminal_size;

void UpdateTerminalSize();
#endif

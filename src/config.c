#include "../include/config.h"
#include <sys/ioctl.h>
#include <unistd.h>

struct winsize terminal_size;

void UpdateTerminalSize() { ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size); }

void initConfig() { UpdateTerminalSize(); }

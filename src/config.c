#include "../include/config.h"
#include <sys/ioctl.h>
#include <unistd.h>

struct winsize terminal_size;

void handle_resize(int sig) {
  (void)sig;
  UpdateTerminalSize();
}

void UpdateTerminalSize() {
  static unsigned short last_cols = 0;
  static unsigned short last_rows = 0;

  struct winsize ws;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

  if (ws.ws_col != last_cols || ws.ws_row != last_rows) {
    terminal_size = ws;
    last_cols = ws.ws_col;
    last_rows = ws.ws_row;
  }
}

void initConfig() { UpdateTerminalSize(); }

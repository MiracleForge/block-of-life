#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
struct termios saved_attributes;

void reset_input_mode(void) {
  tcsetattr(STDIN_FILENO, TCSANOW, &saved_attributes);
  printf("\033[?25h");
}

void set_input_mode() {
  struct termios tattr;

  // is a terminal?
  if (!isatty(STDIN_FILENO)) {
    fprintf(stderr, "Not a terminal");
    exit(EXIT_FAILURE);
  }
  // save terminal attributes for late
  tcgetattr(STDIN_FILENO, &saved_attributes);
  atexit(reset_input_mode);

  tcgetattr(STDIN_FILENO, &tattr);
  tattr.c_lflag &= ~(ICANON | ECHO); /* Clear ICANON and ECHO. */
  tattr.c_cc[VMIN] = 1;
  tattr.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);

  printf("\033[?25l");
}

void clearScreen() {
  const char *CLEAR_SCREEN_ANSI = "\033[H\033[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, strlen(CLEAR_SCREEN_ANSI));
  printf("\033[%d;%dH", (1), (1));
}

void handle_sigint(int sig) {
  reset_input_mode();
  exit(1);
}

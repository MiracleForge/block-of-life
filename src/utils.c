#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

struct termios saved_attributes;

void reset_input_mode(void) {
  tcsetattr(STDIN_FILENO, TCSANOW, &saved_attributes);
  printf("\033[?25h");
  printf("\e[1;1H\e[2J");
}

int set_input_mode(void) {
  struct termios tattr;

  if (!isatty(STDIN_FILENO)) {
    fprintf(stderr, "Not a terminal\n");
    return -1; // erro
  }

  if (tcgetattr(STDIN_FILENO, &saved_attributes) == -1) {
    perror("tcgetattr");
    return -1;
  }

  if (atexit(reset_input_mode) != 0) {
    fprintf(stderr, "Erro ao registrar atexit\n");
    return -1;
  }

  if (tcgetattr(STDIN_FILENO, &tattr) == -1) {
    perror("tcgetattr");
    return -1;
  }

  tattr.c_lflag &= ~(ICANON | ECHO);
  tattr.c_cc[VMIN] = 1;
  tattr.c_cc[VTIME] = 0;

  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr) == -1) {
    perror("tcsetattr");
    return -1;
  }

  printf("\033[?25l");
  return 0;
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

#include "../include/config.h"
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  size_t n_options;
  size_t *opt_len; // array of sizes
  char **option;   // array of pointers to options
  char *ending;
} Menu;

void drawGameBox() {
  // top
  printf("┏");
  for (int t = 0; t < COLLUMS; t++)
    printf("━");
  printf("┓\n");
  // vertical lines
  for (int r = 0; r < ROWS; r++) {
    printf("┃");
    for (int t = 0; t < COLLUMS; t++)
      printf(" "); // internal space
    printf("┃\n");
  }
  // base
  printf("┗");
  for (int t = 0; t < COLLUMS; t++)
    printf("━");
  printf("┛\n");
}

char *resize_opt(size_t full_len, const char *opt_text) {
  if (opt_text == NULL)
    return NULL;
  size_t opt_len = strlen(opt_text);
  size_t start = (full_len - opt_len) / 2;
  char *out = malloc(1 + start + opt_len);
  if (out == NULL)
    return NULL;
  size_t i = 0;
  for (; i < (full_len - opt_len) / 2; i += 1)
    out[i] = ' ';
  out[i] = 0; // terminate string
  strcpy(out + start, opt_text);
  return out;
}

size_t so_get_option(Menu *M) {
  int option = 0;
  do {
    printf("%s\n\n", M->title);
    for (size_t n = 0; n < M->n_options; n += 1)
      printf("%s - %2zu\n\n", M->option[n], 1 + n);
    printf("\nYour Option:_ ");
    char line[200];
    char *p = fgets(line, sizeof(line), stdin);
    size_t opt = atoi(line);
    if (opt <= M->n_options) {
      printf("%s\n", M->ending);
      return opt;
    }
  } while (1);
  return 0;
}

int so_show_menu(Menu *M, const char *msg) {
  if (M == NULL)
    return -1;
  if (msg != NULL)
    printf("%s", msg);
  printf("\
\n\
    %zu options in this menu.\n\
\n\
      Title  is \"%s\"\n\
      Ending is \"%s\"\n\
\n\
    Options:\n\
\n",
         M->n_options, M->title, M->ending);
  //
  for (size_t n = 0; n < M->n_options; n += 1)
    printf("\t%zu: \"%s\"\t[%zu]\n", n, M->option[n], M->opt_len[n]);
  printf("[...]\n");
  return 0;
}

Menu *so_create_menu(const char *title, const char *ending,
                     const size_t n_options, ...) {
  va_list args;
  Menu *M = malloc(sizeof(Menu));
  if (M == NULL)
    return NULL;
  // process title and ending
  M->title = malloc(1 + strlen(title));
  strcpy(M->title, title);
  M->ending = malloc(1 + strlen(ending));
  strcpy(M->ending, ending);
  M->n_options = n_options;
  // allocate required arrays
  M->opt_len = malloc(n_options * sizeof(size_t));
  M->option = (char **)malloc(n_options * sizeof(char *));
  va_start(args, n_options);
  for (size_t n = 0; n < n_options; n += 1) {
    char *one = resize_opt(strlen(M->title), va_arg(args, char *));
    M->option[n] = malloc(1 + strlen(one));
    strcpy(M->option[n], one);
    free(one);
    M->opt_len[n] = strlen(M->option[n]);
  };
  va_end(args);
  return M;
}

Menu *so_destroy_menu(Menu *M) {
  fprintf(stderr, "\n\t** destroying Menu\n");
  if (M == NULL)
    return NULL;
  free(M->title);
  free(M->ending);
  free(M->opt_len);
  for (size_t n = 0; n < M->n_options; n += 1)
    free(M->option[n]);
  free(M->option);
  free(M);
  return NULL;
}

void drawHeader() {

  int so_show_menu(Menu *, const char *);
  // printf("WELLCOME TO GAME OF LIFE\n");
  const char *header = "WELLCOME TO GAME OF LIFE";
  const char *footer = "--------------------------------";

  Menu *one = so_create_menu(header, footer, 5, "LOAD", "CLEAR", "LIST",
                             "FOUNDP", "QUIT");

  Menu *so_destroy_menu(Menu *);
  // so_show_menu(one, "just testing\n\n");

  size_t my_opt = so_get_option(one);
  // printf("\t\tOption was %zu\n", my_opt);

  so_destroy_menu(one);
}

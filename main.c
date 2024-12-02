#include <stdlib.h>
#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#include <unistd.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#define ROW_NUMBER 30
#define COLUMNS_NUMBER 10

int Draw_Tittle(char* title) {
    printf("\33[1;33m");
    printf("%s\n\n", title);
    printf("\33[0m");
    return 0;
}

int Draw_Grid (int row_number, int collums_number, int *cellmap) {
  int _cell_position = 0;

     for (int y = 0; y < collums_number; y++) {
         for (int i = 0; i < row_number; i++) {
           _cell_position++;
           
             if (cellmap[_cell_position -1] == 1) {
                printf("[█]");                
             } else {
                printf("[ ]");
             }
         }  
        printf("\n");
     }
    return 0;
}

void update(int *cell_map) {
    for (int i = 0; i < ROW_NUMBER * COLUMNS_NUMBER; i++) {
        if (cell_map[i] == 1) {
            cell_map[i] = 0;
        }  
     }
}

int main () {
    int *cell_map = malloc (ROW_NUMBER * COLUMNS_NUMBER * sizeof(int));
    int game_running = 1;
    int exit;
    int interation = 0;
    int row  = 15;
    int columns = 5;
    int start_point = (row * COLUMNS_NUMBER) + columns;
    char user_input[10];

    printf("Inter a integer: \n");
    
    fgets(user_input, sizeof(user_input), stdin);
    int user_value = atoi(user_input);
    printf("user input : %d\n", user_value); 
    if (cell_map == NULL) {
        printf("Fail to alocate memory!\n");
        return 1;
    }

    for (int i = 0; i < ROW_NUMBER * COLUMNS_NUMBER; i++) {
        cell_map[i] = 0;        
    }
    cell_map[start_point] = 1;

    Draw_Tittle("Welcome to Game of Life");
   // scanf("Press q to cancel %d", &exit);
    while (game_running) {
      clrscr();  
      Draw_Grid(ROW_NUMBER, COLUMNS_NUMBER, cell_map);
      sleep(1);
      update(cell_map);    
 }
        
    free(cell_map);
    return 0;   
   }

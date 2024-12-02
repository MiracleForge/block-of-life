#include <stdio.h>

#define ROW_NUMBER 29
#define COLLUNS_NUMBER 10

int Draw_Tittle(char* title) {
    printf("\33[1;33m");
    printf("%s\n\n", title);
    printf("\33[0m");
    return 0;
}

int Draw_Grid (int row_number, int collums_number, int alive_cell) {
  int _cell_position = 0;

     for (int y = 0; y < collums_number; y++) {
         for (int i = 0; i < row_number; i++) {
           _cell_position++;
           
             if (alive_cell == _cell_position) {
                printf("[█]");                
             } else {
                printf("[ ]");
             }
         }  
        printf("\n");
     }
    return 0;
}

 

int main () {

    Draw_Tittle("Welcome to Game of Life");
    Draw_Grid(ROW_NUMBER, COLLUNS_NUMBER, 8);
    return 1;
}

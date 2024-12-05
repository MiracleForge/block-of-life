#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define clrscr() printf("\e[1;1H\e[2J")

#define ROW_NUMBER 30
#define COLUMNS_NUMBER 10

// Desenha o título do jogo
int Draw_Tittle(char* title) {
    printf("\33[1;33m");
    printf("%s\n\n", title);
    printf("\33[0m");
    return 0;
}

// Inicializa a matriz com valores aleatórios
int Inicializing(int *cellmap) {
    for (int i = 0; i < ROW_NUMBER * COLUMNS_NUMBER; i++) {
        cellmap[i] = rand() % 2;
    }

    Draw_Tittle("Bem-vindo ao Jogo da Vida");
    return 0;
}

// Desenha a grade na tela
int Draw_Grid(int row_number, int columns_number, int *cellmap) {
    for (int y = 0; y < row_number; y++) {
        for (int x = 0; x < columns_number; x++) {
            int index = y * columns_number + x;
            if (cellmap[index] == 1) {
                printf("[█]");
            } else {
                printf("[ ]");
            }
        }
        printf("\n");
    }
    return 0;
}

// Conta o número de vizinhos vivos ao redor de uma célula
int count_neighbors(int *cellmap, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Ignora a própria célula
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < ROW_NUMBER && ny >= 0 && ny < COLUMNS_NUMBER) {
                count += cellmap[nx * COLUMNS_NUMBER + ny];
            }
        }
    }
    return count;
}

// Atualiza a matriz com base nas regras do Jogo da Vida
void update(int *cellmap) {
    int *new_map = malloc(ROW_NUMBER * COLUMNS_NUMBER * sizeof(int));
    if (new_map == NULL) {
        printf("Falha ao alocar memória para o novo estado!\n");
        return;
    }

    for (int y = 0; y < ROW_NUMBER; y++) {
        for (int x = 0; x < COLUMNS_NUMBER; x++) {
            int index = y * COLUMNS_NUMBER + x;
            int neighbors = count_neighbors(cellmap, y, x);

            if (cellmap[index] == 1) { // Célula viva
                if (neighbors < 2 || neighbors > 3) {
                    new_map[index] = 0; // Morre
                } else {
                    new_map[index] = 1; // Permanece viva
                }
            } else { // Célula morta
                if (neighbors == 3) {
                    new_map[index] = 1; // Torna-se viva
                } else {
                    new_map[index] = 0; // Permanece morta
                }
            }
        }
    }

    // Copia o novo estado para o mapa original
    for (int i = 0; i < ROW_NUMBER * COLUMNS_NUMBER; i++) {
        cellmap[i] = new_map[i];
    }

    free(new_map);
}

int main() {
    int *cell_map = malloc(ROW_NUMBER * COLUMNS_NUMBER * sizeof(int));
    if (cell_map == NULL) {
        printf("Falha ao alocar memória!\n");
        return 1;
    }

    Inicializing(cell_map);

    int game_running = 1;
    while (game_running) {
        clrscr();
        Draw_Grid(ROW_NUMBER, COLUMNS_NUMBER, cell_map);
        sleep(1);
        update(cell_map);
    }

    free(cell_map);
    return 0;
}


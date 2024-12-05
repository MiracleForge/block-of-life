# Game of Life in C

This is a simple project where I am trying to implement **Conway's Game of Life** in C. The goal is to simulate an environment where cells live, die, or reproduce based on specific rules.

## Description

Currently, the implementation generates a **stable** pattern formed by **4 cells** together, known as the **Block**. This pattern is one of the simplest stable patterns in the Game of Life, where the cells do not move and remain in the same configuration after each iteration.

## How It Works

The rules of Conway's Game of Life are as follows:

- **A live cell with fewer than 2 neighbors dies** (due to loneliness).
- **A live cell with 2 or 3 neighbors remains alive**.
- **A live cell with more than 3 neighbors dies** (due to overpopulation).
- **A dead cell with exactly 3 live neighbors becomes alive** (reproduction).

## Current State of the Project

At the moment, the program generates a random initial configuration of cells. However, the only observed result so far is the **stable combination of 4 cells**, known as the **Block**.


This configuration does not change after iterations, meaning the program is still in an early stage and needs improvement in logic to generate other dynamic patterns from the Game of Life.

## How to Run

1. Compile the code with a C compiler, for example:
    ```bash
    gcc -o game_of_life game_of_life.c
    ```

2. Run the program:
    ```bash
    ./game_of_life
    ```

3. The program will display the current state of the cell matrix in the console.

## Conclusion

While the program works correctly for the **Block** stable pattern, there is much to be done to improve the logic, such as allowing for more patterns to evolve and optimizing the code's performance. Feel free to contribute or suggest improvements!


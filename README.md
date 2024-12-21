# Block of Life

**Block of Life** is a simple C program that simulates the Game of Life, a cellular automaton devised by the British mathematician John Horton Conway. This project was created to help me improve my C programming skills and learn how to publish software as a .deb package.

## Features

- Implements the Game of Life algorithm.
- Simple terminal-based interface for visualizing the simulation.
- Easily customizable grid size and number of iterations.

## Installation

To install the `.deb` package, follow these steps:

1. Download the `.deb` package from the [Releases](https://github.com/MiracleForge/block-of-life/releases/download/v1.0.0/block-of-life_1.0-1_amd64.deb) section.
   
2. Install the package using the following command:

   ```bash
   sudo dpkg -i block-of-life_1.0-1_amd64.deb

If there are missing dependencies, run:

sudo apt-get install -f

Run the program:

block-of-life

The program will display the current state of the cell matrix in the console.

Conclusion

While the program works correctly for the Block stable pattern, there is much to be done to improve the logic, such as allowing for more patterns to evolve and optimizing the code's performance. Feel free to contribute or suggest improvements!
Goal of the Project

The primary goal of this project was to:

    Improve my C programming skills: This project was an opportunity to deepen my understanding of C and strengthen my ability to write efficient and clean C code.

    Learn how to publish a software package: I wanted to learn how to package a C program as a .deb file and make it available for installation on Debian-based systems like Ubuntu.

Contributing

Feel free to fork the repository and submit pull requests if you have any improvements or suggestions. Contributions are welcome!


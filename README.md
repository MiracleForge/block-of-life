# Block of Life

**Block of Life** is a simple C program that simulates the **Game of Life**, a cellular automaton devised by the British mathematician John Horton Conway. This project was created as a way to improve my C programming skills and to learn how to package software into a **.deb** package for Debian/Ubuntu-based systems.

## ✨ Features

* Implements the Game of Life algorithm.
* Simple terminal-based interface for visualizing the simulation.
* Random initialization of cells.
* Configurable grid size and iterations.

## 📦 Installation (Debian / Ubuntu)

1. Download the **.deb** package from the Releases section.
2. Install the package with the following command:

```bash
sudo dpkg -i block-of-life_*.deb
```

3. If there are missing dependencies, run:

```bash
sudo apt-get install -f
```

## 🚀 Usage

After installation, you can run the program with:

```bash
block-of-life
```

## 🛠️ Building from Source

### Prerequisites

* GCC compiler
* Make
* dpkg-dev (for creating .deb packages)

### Compilation

1. Clone the repository:
```bash
[git clone https://github.com/MiracleForge/block-of-life.git
cd block-of-life
```

2. Compile the program:
```bash
gcc -o block-of-life.c block-of-life
```

3. Run the program:
```bash
./block-of-life
```

### Creating a .deb Package

To create your own .deb package:

```bash
make package
```

## 🎮 How to Play

The Game of Life follows these simple rules:

1. Any live cell with fewer than two live neighbors dies (underpopulation).
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies (overpopulation).
4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

## 📁 Project Structure

```
block-of-life/
├── src/
│   ├── main.c
│   ├── game_of_life.c
│   └── game_of_life.h
├── debian/
│   ├── control
│   ├── changelog
│   └── rules
├── Makefile
├── README.md
└── LICENSE
```
## Upcoming Features
🎯 Planned Updates (v2.0)
### Enhanced Command Line Interface

Auto-sizing: Grid automatically adapts to terminal dimensions
Pattern library: Built-in famous Conway patterns (Glider, Gosper Gun, Pulsar, etc.)
Color support: Colorized output for better visualization

### Advanced Game of Life Features

Cell aging: Visual representation of cell age with different colors/symbols
Statistics tracking: Population graphs, stability detection, period analysis

### Performance & Usability

Export options: Generate GIF animations, PNG snapshots, or CSV data
Configuration files: Save preferred settings and patterns

### 🛠️ Technical Improvements

Package managers: Available on homebrew, snap, and flatpak

🎯 Planned Updates (v3.0)
### Enhanced Command Line Interface

Interactive mode: Pause, step through, and modify simulation in real-time

### Advanced Game of Life Features

Zoom functionality: Focus on specific regions of large grids
Toroidal topology: Wrap-around edges for infinite-like behavior
Multiple rule sets: Support for different cellular automaton rules (B3/S23, HighLife, etc.)
Zoom functionality: Focus on specific regions of large grids

### Performance & Usability

Optimized algorithms: Sparse matrix representation for large grids
Multi-threading: Parallel computation for faster iterations
Memory efficiency: Dynamic allocation based on active regions

### 🛠️ Technical Improvements

Cross-platform: Windows and macOS support
Package managers: Available on homebrew, snap, and flatpak
Using OpenGl

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 🙏 Acknowledgments

* John Horton Conway for creating the Game of Life
* The open-source community for inspiration and tools

## 📧 Contact

Paulo Henrique Moreira Rosado - paulomoreirarosado@hotmail.com

# Rubik's Cube Solver Project

## Overview
This project is a comprehensive Rubik's Cube Solver implemented in C++ that supports multiple solving algorithms such as Depth-First Search (DFS), Breadth-First Search (BFS), Iterative Deepening Depth-First Search (IDDFS), and Iterative Deepening A* (IDA*). The solver can shuffle, jumble, and solve Rubik's cubes using advanced data representations and algorithms.

## Folder Structure
```
RubixCuberSolver
|-- Dataset
|   |-- cornerDepth5V1.txt
|
|-- Pattern
|   |-- CornerPatternDatabase
|   |-- Database
|   |-- DB_Maker
|   |-- nibble_array
|   |-- Permutation Indexer
|
|-- Solvers
|   |-- BFS_Solver.h
|   |-- DFS_Solver.h
|   |-- IDAStart_Solver.h
|   |-- IDDFS_Solver.h
|
|-- Generic_Rubix_Cube_Solver.cpp
|-- Generic_Rubix_Cube_Solver.h
|-- Rubiks1DRepresentation.cpp
|-- Rubiks3DRepresentation.cpp
|-- RubiksBitBoardRepresentation.cpp
|-- main.cpp
```

## Features
- **Custom Rubik's Cube Representation:**
    - Includes multiple cube representations like 1D, 3D, and Bitboard for efficient manipulation.
- **Solving Algorithms:**
    - Depth-First Search (DFS)
    - Breadth-First Search (BFS)
    - Iterative Deepening DFS (IDDFS)
    - Iterative Deepening A* (IDA*)
- **Interactive Modes:**
    - Shuffle the cube with a random sequence of moves.
    - Apply custom moves to jumble the cube.
    - Solve the cube interactively using the selected algorithm.
- **Pattern Database:**
    - Leverages precomputed databases for efficient IDA* solving.

## Getting Started
### Prerequisites
- C++17 or higher
- A C++ compiler like g++ or clang++
- CMake for building the project

### Build Instructions
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd RubixCuberSolver
   ```
2. Create a build directory and compile:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Run the executable:
   ```bash
   ./RubixCuberSolver
   ```

## Usage
When you run the program, a menu is displayed with the following options:

1. **Shuffle Cube:**
    - Input a depth value to shuffle the cube randomly.
2. **Jumble Your Cube:**
    - Manually input a sequence of moves to jumble the cube.
3. **Solve Using DFS:**
    - Solve the cube using Depth-First Search.
4. **Solve Using BFS:**
    - Solve the cube using Breadth-First Search.
5. **Solve Using IDDFS:**
    - Solve the cube using Iterative Deepening DFS.
6. **Solve Using IDA*:**
    - Solve the cube using Iterative Deepening A* algorithm with the help of a pattern database.
7. **Exit:**
    - Exit the program.

## Key Classes
### Generic_Rubix_Cube_Solver
Defines the base Rubik's Cube interface with:
- **Enums:**
    - `FACE`: Cube face types (UP, LEFT, RIGHT, etc.).
    - `COLOR`: Cube colors (WHITE, GREEN, etc.).
    - `MOVE`: Move types (`L`, `LPRIME`, `R2`, etc.).
- **Core Methods:**
    - `getColor(FACE, row, col)`: Get the color of a specific cube face.
    - `isSolved()`: Check if the cube is solved.
    - `move(MOVE)`: Apply a move to the cube.
    - `randomShuffleCube(times)`: Shuffle the cube randomly.

### Solvers
Each solver is implemented in its respective `.h` file:
- **DFS_Solver:** Performs Depth-First Search with a configurable depth.
- **BFS_Solver:** Implements Breadth-First Search to find the solution.
- **IDDFS_Solver:** Combines DFS and depth-limited iterations for solving.
- **IDAStart_Solver:** Uses the A* algorithm with iterative deepening, leveraging a precomputed pattern database.

## Example
1. Shuffle the cube with depth 5:
   ```
   Enter the depth for shuffling the cube (e.g., 5): 5
   Shuffle moves: F U R' D2 B L
   ```
2. Solve using IDA*:
   ```
   MOVES TO SOLVE USING IDA* with depth 5: L' B' D2 R U' F'
   ```

## Contributors
- Syed Israr Ahmed

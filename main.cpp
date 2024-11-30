#include <bits/stdc++.h>
#include "./Rubiks3DRepresentation.cpp"
#include "./Rubiks1DRepresentation.cpp"
#include "./RubiksBitBoardRepresentation.cpp"
#include "./Solvers/DFS_Solver.h"
#include "./Solvers/BFS_Solver.h"
#include "Solvers/IDAStart_Solver.h"
#include "Solvers/IDDFS_Solver.h"

using namespace std;

// Function to perform a random shuffle of the cube
void shuffleCube(Rubiks3DArray& cube) {
    int shuffleDepth;
    cout << "Enter the depth for shuffling the cube (e.g., 5): ";
    cin >> shuffleDepth;

    vector<Generic_Rubix_Cube_Solver::MOVE> shuffle_moves = cube.randomShuffleCube(shuffleDepth);
    cube.print();
    cout << "Shuffle moves: ";
    for (auto move : shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";

}

// Function to solve the cube using DFS
void solveUsingDFS(Rubiks3DArray& cube) {
    int depth = 3;
    DFSSolver<Rubiks3DArray, Rubiks3DArray::Hash3d> dfs_solver(cube, depth);
    vector<Generic_Rubix_Cube_Solver::MOVE> movesToSolve = dfs_solver.solve();
    dfs_solver.rubikCubeSolver.print();
    cout << "MOVES TO SOLVE USING DFS with depth " << depth << ": ";
    for (auto move : movesToSolve) {
        cout << cube.getMove(move) << " ";
    }
    cout << endl;
}

// Function to solve the cube using BFS
void solveUsingBFS(Rubiks3DArray& cube) {
    int depth = 4;
    BFSSolver<Rubiks3DArray, Rubiks3DArray::Hash3d> bfsSolver(cube);
    vector<Rubiks3DArray::MOVE> solve_moves = bfsSolver.solve();
    bfsSolver.rubiksCube.print();
    cout << "MOVES TO SOLVE USING BFS with depth " << depth << ": ";
    for (auto move : solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
}

// Function to solve the cube using IDDFS
void solveUsingIDDFS(Rubiks3DArray& cube) {
    int depth = 5;
    IDDFS_Solver<Rubiks3DArray, Rubiks3DArray::Hash3d> iddfs_solver(cube, depth);
    vector<Generic_Rubix_Cube_Solver::MOVE> iddfs_moves = iddfs_solver.solve();
    iddfs_solver.rubiksCube.print();
    cout << "MOVES TO SOLVE USING IDDFS with depth " << depth << ": ";
    for (auto move : iddfs_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
}

// Function to solve the cube using IDA* algorithm
void solveUsingIDAStar(Rubiks3DArray& cube) {
    int depth = 7;

    string path = "C:\\Users\\Asus\\CLionProjects\\RubixCuberSolver\\Dataset2\\cornerDepth5V1.txt";
    IDAStart_Solver<Rubiks3DArray, Rubiks3DArray::Hash3d> idaStar(
        cube, path);
    vector<Generic_Rubix_Cube_Solver::MOVE> solve_moves = idaStar.solve();
    cout << "MOVES TO SOLVE USING IDA* with depth " << depth << ": ";
    for (auto move : solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
}

// Menu function to interact with the user
void displayMenu() {
    cout << "Choose an option: \n";
    cout << "1. Shuffle Cube\n";
    cout << "2. Solve Using DFS\n";
    cout << "3. Solve Using BFS\n";
    cout << "4. Solve Using IDDFS\n";
    cout << "5. Solve Using IDA*\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to drive the program
int main() {
    Rubiks3DArray cube;  // Create an instance of your Rubik's Cube representation
    int choice = -1;

    while (choice != 0) {
        displayMenu();  // Show the menu to the user
        cin >> choice;

        switch (choice) {
            case 1:
                shuffleCube(cube);
                break;
            case 2:
                solveUsingDFS(cube);
                break;
            case 3:
                solveUsingBFS(cube);
                break;
            case 4:
                solveUsingIDDFS(cube);
                break;
            case 5:
                solveUsingIDAStar(cube);
                break;
            case 0:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

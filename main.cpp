#include <bits/stdc++.h>
#include "./Rubiks3DRepresentation.cpp"
#include "./Rubiks1DRepresentation.cpp"
#include "./RubiksBitBoardRepresentation.cpp"
#include "Pattern/CornerPatternDatabase/CornerPatternDatabase.h"
#include "./Solvers/DFS_Solver.h"
#include "./Solvers/BFS_Solver.h"
#include "Solvers/IDAStart_Solver.h"
#include "Solvers/IDDFS_Solver.h"

using namespace std;

int shuffleDepth;

void shuffleCube(Bit_representation &cube) {
    cout << "Enter the depth for shuffling the cube (e.g., 5): ";
    cin >> shuffleDepth;

    vector<Generic_Rubix_Cube_Solver::MOVE> shuffle_moves = cube.randomShuffleCube(shuffleDepth);
    cube.print();

    cout << "Shuffle moves: ";
    for (auto move : shuffle_moves) {
        cout << cube.getMove(move) << " ";
    }
    cout << "\n";
}

void jumbleYourCube(Bit_representation &cube) {
    cout << "Enter your custom moves as space-separated values (e.g., f u rPrime). Enter 'done' to finish: \n";
    vector<string> operations;
    string input;

    while (cin >> input && input != "done") {
        operations.push_back(input);
    }

    shuffleDepth = operations.size();
    for (const auto &move : operations) {
        if (move == "f") cube.f();
        else if (move == "fPrime") cube.fPrime();
        else if (move == "f2") cube.f2();
        else if (move == "u") cube.u();
        else if (move == "uPrime") cube.uPrime();
        else if (move == "u2") cube.u2();
        else if (move == "l") cube.l();
        else if (move == "lPrime") cube.lPrime();
        else if (move == "l2") cube.l2();
        else if (move == "r") cube.r();
        else if (move == "rPrime") cube.rPrime();
        else if (move == "r2") cube.r2();
        else if (move == "d") cube.d();
        else if (move == "dPrime") cube.dPrime();
        else if (move == "d2") cube.d2();
        else if (move == "b") cube.b();
        else if (move == "bPrime") cube.bPrime();
        else if (move == "b2") cube.b2();
        else {
            cout << "Invalid move: " << move << ". Skipping...\n";
        }
    }

    cube.print();
    cout << "Cube jumbled successfully with " << shuffleDepth << " moves!\n";
}

void solveUsingDFS(Bit_representation &cube) {
    int depth = shuffleDepth + 2;
    DFSSolver<Bit_representation, HashBitboard> dfs_solver(cube, depth);
    vector<Generic_Rubix_Cube_Solver::MOVE> movesToSolve = dfs_solver.solve();

    dfs_solver.rubikCubeSolver.print();

    cout << "MOVES TO SOLVE USING DFS with depth " << depth << ": ";
    for (auto move : movesToSolve) {
        cout << cube.getMove(move) << " ";
    }
    cout << endl;
}

void solveUsingBFS(Bit_representation &cube) {
    int depth = shuffleDepth + 3;
    BFSSolver<Bit_representation, HashBitboard> bfsSolver(cube);
    vector<Rubiks3DArray::MOVE> solve_moves = bfsSolver.solve();

    bfsSolver.rubiksCube.print();

    cout << "MOVES TO SOLVE USING BFS with depth " << depth << ": ";
    for (auto move : solve_moves) {
        cout << cube.getMove(move) << " ";
    }
    cout << "\n";
}

void solveUsingIDDFS(Bit_representation &cube) {
    int depth = shuffleDepth;
    IDDFS_Solver<Bit_representation, HashBitboard> iddfs_solver(cube, depth);
    vector<Generic_Rubix_Cube_Solver::MOVE> iddfs_moves = iddfs_solver.solve();

    iddfs_solver.rubiksCube.print();

    cout << "MOVES TO SOLVE USING IDDFS with depth " << depth << ": ";
    for (auto move : iddfs_moves) {
        cout << cube.getMove(move) << " ";
    }
    cout << "\n";
}

void solveUsingIDAStar(Bit_representation &cube) {
    int depth = shuffleDepth;

    string path = "C:\\Users\\Asus\\OneDrive\\Desktop\\RubixCuberSolver\\Dataset\\cornerDepth5V1.txt";
    IDAStart_Solver<Bit_representation, HashBitboard> idaStar(cube, path);
    vector<Generic_Rubix_Cube_Solver::MOVE> solve_moves = idaStar.solve();

    cout << "MOVES TO SOLVE USING IDA* with depth " << depth << ": ";
    for (auto move : solve_moves) {
        cout << cube.getMove(move) << " ";
    }
    cout << "\n";
}

void displayMenu() {
    cout << "Choose an option: \n";
    cout << "1. Shuffle Cube\n";
    cout << "2. Jumble Your Cube\n";
    cout << "3. Solve Using DFS\n";
    cout << "4. Solve Using BFS\n";
    cout << "5. Solve Using IDDFS\n";
    cout << "6. Solve Using IDA*\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Bit_representation cube;
    int choice = -1;

    while (choice != 0) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                shuffleCube(cube);
                break;
            case 2:
                jumbleYourCube(cube);
                break;
            case 3:
                solveUsingDFS(cube);
                break;
            case 4:
                solveUsingBFS(cube);
                break;
            case 5:
                solveUsingIDDFS(cube);
                break;
            case 6:
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
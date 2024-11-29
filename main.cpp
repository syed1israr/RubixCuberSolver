#include <bits/stdc++.h>
#include "./Rubiks3DRepresentation.cpp"
#include "./Rubiks1DRepresentation.cpp"
#include "./RubiksBitBoardRepresentation.cpp"
#include "./Solvers/DFS_Solver.h"
#include "./Solvers/BFS_Solver.h"
#include "Solvers/IDDFS_Solver.h"

using namespace std;

signed main() {
    Rubiks3DArray ob1;
    Rubiks3DArray ob2;


     // Uncomment the following code blocks to test specific functionalities

     // Example of using operations on Rubik's cube
     ob2.l();
     ob2.l2();
     ob2 = ob1;
     ob2.l();

     // Using unordered_map with Rubik's cube objects
     // unordered_map<Rubiks3DArray, bool, Rubiks3DArray::Hash3d> mp1;
     // mp1[ob1] = true;
     // if (mp1[ob1]) cout << "CUBE1 IS PRESENT\n";
     // else cout << "CUBE1 IS NOT PRESENT\n";
     // if (mp1[ob2]) cout << "CUBE2 IS PRESENT\n";
     // else cout << "CUBE2 IS NOT PRESENT\n";

     // Shuffle and print moves
     // vector<Generic_Rubix_Cube_Solver::MOVE> MovestoShuffle = ob1.randomShuffleCube(5);
     // ob1.print();
     // cout << "MOVES During Shuffle DFS : ";
     // for (auto move : MovestoShuffle) {
     //     cout << ob1.getMove(move) << " ";
     // }
     // cout << endl;

     // Solve using DFS
     // DFSSolver<Rubiks3DArray, Rubiks3DArray::Hash3d> dfs_solver(ob1, 6);
     // vector<Generic_Rubix_Cube_Solver::MOVE> MovesToSolve = dfs_solver.solve();
     // dfs_solver.rubikCubeSolver.print();
     // cout << "MOVES TO SOLVE USING DFS : ";
     // for (auto move : MovesToSolve) {
     //     cout << ob1.getMove(move) << " ";
     // }
     // cout << endl;


    // BFS Solver demonstration

    vector<Rubiks3DArray::MOVE> shuffle_moves = ob1.randomShuffleCube(5);
    ob1.print();
    cout << "MOVES During Shuffle  BFS : ";
    for (auto move : shuffle_moves) cout << ob1.getMove(move) << " ";
    cout << "\n";

    // BFSSolver<Rubiks3DArray, Rubiks3DArray::Hash3d> bfsSolver(ob1);
    // vector<Rubiks3DArray::MOVE> solve_moves = bfsSolver.solve();
    // bfsSolver.rubiksCube.print();
    // cout << " MOVES TO SOLVE USING BFS : ";
    // for (auto move : solve_moves) cout << ob1.getMove(move) << " ";
    // cout << "\n";



    // IDDFS Solver
    IDDFS_Solver<Rubiks3DArray,Rubiks3DArray::Hash3d> IDDFS_Solver(ob1,6);
    vector<Generic_Rubix_Cube_Solver::MOVE> IDDFS_moves = IDDFS_Solver.solve();
    IDDFS_Solver.rubiksCube.print();
    cout << " MOVES TO SOLVE USING IDDFS : ";
    for (auto move : IDDFS_moves) cout << ob1.getMove(move) << " ";
    cout << "\n";

}

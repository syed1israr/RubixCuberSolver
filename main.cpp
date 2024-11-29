#include <bits/stdc++.h>
#include "./Rubiks3DRepresentation.cpp"
#include "./Rubiks1DRepresentation.cpp"
#include "./RubiksBitBoardRepresentation.cpp"
#include "./Solvers/DFS_Solver.h"
using namespace std;
signed main() {

    Rubiks3DArray ob1;
    Rubiks3DArray ob2;


    // ob2.l();
    // ob2.l2();
    // ob2 =  ob1;
    // ob2.l();
    //
    // unordered_map<Rubiks3DArray, bool, Rubiks3DArray::Hash3d> mp1;
    // mp1[ob1] = true;
    // if (mp1[ob1]) cout<<"CUBE1 IS PRESENT\n";
    // else cout<<"CUBE1 IS NOT PRESENT\n";
    // if (mp1[ob2]) cout<<"CUBE2 IS PRESENT\n";
    // else cout<<"CUBE2 IS NOT PRESENT\n";

    vector<Generic_Rubix_Cube_Solver::MOVE> MovestoShuffle = ob1.randomShuffleCube(2);
    ob1.print();
    cout<<"MOVES During Shuffle : ";
    for (auto move  : MovestoShuffle) {
        cout<< ob1.getMove(move)<<" ";
    }
    cout<<endl;
    DFSSolver<Rubiks3DArray , Rubiks3DArray::Hash3d> dfs_solver(ob1,3);
    vector<Generic_Rubix_Cube_Solver::MOVE> MovesToSolve = dfs_solver.solve();
    dfs_solver.rubikCubeSolver.print();
    cout<<"MOVES TO Solve  : ";
    for (auto move : MovesToSolve) {
        cout<< ob1.getMove(move)<<" ";
    }
    cout<<endl;




}
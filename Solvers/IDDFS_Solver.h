//
// Created by Asus on 29-11-2024.
//
#include <bits/stdc++.h>
using namespace std;
#include "DFS_Solver.h"
#include "../Generic_Rubix_Cube_Solver.h"

#ifndef IDDFS_SOLVER_H
#define IDDFS_SOLVER_H

template <typename T, typename H>
class IDDFS_Solver {
private:
        int max_depth;
        vector<Generic_Rubix_Cube_Solver::MOVE> moves;

public:
        T rubiksCube;

        IDDFS_Solver(T _rubiksCube, int _max_depth = 7) {
                rubiksCube = _rubiksCube;
                max_depth = _max_depth;
        }

        vector<Generic_Rubix_Cube_Solver::MOVE> solve() {
                for (int i = 1; i <= max_depth; i++) {
                        DFSSolver<T, H> dfs_solver(rubiksCube, i);
                        moves = dfs_solver.solve();
                        if (dfs_solver.rubikCubeSolver.isSolved()) {
                                rubiksCube = dfs_solver.rubikCubeSolver;
                                break;
                        }
                }
                return moves;
        }
};

#endif // IDDFS_SOLVER_H

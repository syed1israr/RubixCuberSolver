
#include <bits/stdc++.h>
#include "../Generic_Rubix_Cube_Solver.h"


#ifndef DFS_SOLVER_H
#define DFS_SOLVER_H


template <typename T, typename H>
class DFSSolver {
private:
    vector<Generic_Rubix_Cube_Solver::MOVE> moves;
    int max_search_depth;

    // DFS code to find the solution
    bool dfs(int depth) {
        if (rubikCubeSolver.isSolved()) return true;
        if (depth > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            rubikCubeSolver.move(Generic_Rubix_Cube_Solver::MOVE(i));
            moves.push_back(Generic_Rubix_Cube_Solver::MOVE(i));
            if (dfs(depth + 1)) return true;
            moves.pop_back();
            rubikCubeSolver.invert(Generic_Rubix_Cube_Solver::MOVE(i));
        }
        return false;
    }

public:
    T rubikCubeSolver;
    // if doesnt work , change it to normal State
    DFSSolver(T _rubikCubeSolver, int _max_search_depth = 8) {
        rubikCubeSolver = _rubikCubeSolver;
        max_search_depth = _max_search_depth;
    }

    vector<Generic_Rubix_Cube_Solver::MOVE> solve() {
        dfs(1);
        return moves;
    }
};


#endif

//
// Created by Asus on 29-11-2024.
//
#include <bits/stdc++.h>
#include "../Generic_Rubix_Cube_Solver.h"

#ifndef BFS_SOLVER_H
#define BFS_SOLVER_H

template <typename T, typename H>
class BFSSolver {
private:
    vector<Generic_Rubix_Cube_Solver::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, Generic_Rubix_Cube_Solver::MOVE, H> move_done;

    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();

            if (node.isSolved()) {
                return node;
            }

            for (int i = 0; i < 18; i++) {
                auto curr_move = Generic_Rubix_Cube_Solver::MOVE(i);
                node.move(curr_move);

                if (!visited[node]) {
                    visited[node] = true;
                    move_done[node] = curr_move;
                    q.push(node);
                }

                node.invert(curr_move);
            }
        }

        return rubiksCube;
    }

public:
    T rubiksCube;

    BFSSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;
    }

    vector<Generic_Rubix_Cube_Solver::MOVE> solve() {
        T solved_cube = bfs();
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;

        while (!(curr_cube == rubiksCube)) {
            Generic_Rubix_Cube_Solver::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }

        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif // BFS_SOLVER_H

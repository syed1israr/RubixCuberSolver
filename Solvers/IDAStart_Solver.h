
#ifndef IDASTART_SOLVER_H
#define IDASTART_SOLVER_H

#include "../Generic_Rubix_Cube_Solver.h"
#include "../Patterns/CornerPatternDatabase.h"
#include "./Dummy.h"




template<typename T ,typename H>
class  IDAStart_Solver {
public:
    Dummy<Bit_representation> cornerDB;
    vector<Generic_Rubix_Cube_Solver::MOVE> moves;
    unordered_map<T,Generic_Rubix_Cube_Solver::MOVE,H> moves_done;
    unordered_map<T,bool,H>visited;
    struct Node {
        T cube;
        int depth;
        int estimate;

        Node(T _cube ,int _depth , int _estimate) : cube(_cube),depth(_depth),estimate(_estimate) {};

    };

    struct compareCube {
        bool operator()(pair<Node,int> const &p1,pair<Node,int> const &p2 ) {
            auto n1 = p1.first;
            auto n2 = p2.first;
            if ( n1.depth + n1.estimate  ==  n2.depth + n2.estimate ) {
                return n1.estimate > n2.estimate;
            }else return n1.depth + n1.estimate >  n2.depth + n2.estimate;
        }
    };

    void resetStructure() {
        moves_done.clear();
        visited.clear();
        moves.clear();
    }

    pair<T,int>IDAStar(int bound) {
        priority_queue<pair<Node, int>, vector<pair<Node, int>>, compareCube> pq;
        Node start = Node(rubiksCube, 0, cornerDB.getEstimate(rubiksCube));
        pq.push(make_pair(start, 0));
        int next_bound = 100;
        while (!pq.empty()) {
            auto p = pq.top();
            Node node = p.first;
            pq.pop();

            if (visited[node.cube]) continue;

            visited[node.cube] = true;
            moves_done[node.cube] = Generic_Rubix_Cube_Solver::MOVE(p.second);

            if (node.cube.isSolved()) return make_pair(node.cube, bound);
            node.depth++;
            for (int i = 0; i < 18; i++) {
                auto curr_move = Generic_Rubix_Cube_Solver::MOVE(i);
                node.cube.move(curr_move);
                if (!visited[node.cube]) {
                    node.estimate = cornerDB.getEstimate(node.cube);
                    if (node.estimate + node.depth > bound) {
                        next_bound = min(next_bound, node.estimate + node.depth);
                    } else {
                        pq.push(make_pair(node, i));
                    }
                }
                node.cube.invert(curr_move);
            }

        }
        return make_pair(rubiksCube, next_bound);
    }

    public:
    T rubiksCube;

    IDAStart_Solver(T _rubiksCube ) { // string filename
        rubiksCube = _rubiksCube;
        // cornerDB.fromFile(filename);
    }

    vector<Generic_Rubix_Cube_Solver::MOVE> solve() {
        int bound = 1;
        auto p = IDAStar(bound);
        while (p.second != bound) {
            resetStructure();
            bound = p.second;
            p = IDAStar(bound);
        }
        T solved_cube = p.first;
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while (!(curr_cube == rubiksCube)) {
            Generic_Rubix_Cube_Solver::MOVE curr_move = moves_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};
#endif //IDASTART_SOLVER_H

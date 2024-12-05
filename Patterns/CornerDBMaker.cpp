//
// Created by Asus on 30-11-2024.
//

#include "CornerDBMaker.h"
using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName) {
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore() {
    Bit_representation cube;
    queue<Bit_representation> queue;
    queue.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;

    while (!queue.empty()) {
        int n = queue.size();
        curr_depth++;
        if (curr_depth == 9) break; // Stop BFS after 9 levels

        for (int counter = 0; counter < n; counter++) {
            Bit_representation cube = queue.front();
            queue.pop();

            for (int i = 0; i < 18; i++) {
                auto curr_move = Generic_Rubix_Cube_Solver::MOVE(i);

                // Apply move
                cube.move(curr_move);

                // Check and update depth in CornerPatternDatabase
                if ((int)cornerDB.getNumMoves(cube) > curr_depth) {
                    cornerDB.setNumMoves(cube, curr_depth);
                    queue.push(cube); // Add the new state to the queue
                }

                // Revert move to restore the cube's original state
                cube.invert(curr_move);
            }
        }
    }

    // Save the corner pattern database to the specified file
    cornerDB.toFile(fileName);
    return true;
}

//
// Created by Asus on 05-12-2024.
//

#include "DB_maker.h"


using namespace std;

DB_maker::DB_maker(string _fileName) {
    fileName = _fileName;
}

DB_maker::DB_maker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

bool DB_maker::bfsAndStore() {
    Bit_representation cube;
    queue<Bit_representation> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty()) {
        int n = q.size();
        curr_depth++;
        if (curr_depth == 9) break;
        for (int counter = 0; counter < n; counter++) {
            Bit_representation node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = Bit_representation::MOVE(i);
                node.move(curr_move);
                if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}
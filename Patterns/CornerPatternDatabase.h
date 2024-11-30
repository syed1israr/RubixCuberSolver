//
// Created by Asus on 30-11-2024.
//

#ifndef CORNERPATTERNDATABASE_H
#define CORNERPATTERNDATABASE_H
using namespace std;
#include "../Generic_Rubix_Cube_Solver.h"
#include "PatternDatabase.h"
#include "./PermutationIndexer.h"

class CornerPatternDatabase : public PatternDatabase {

    typedef Generic_Rubix_Cube_Solver::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const Generic_Rubix_Cube_Solver& cube) const;

};



#endif //CORNERPATTERNDATABASE_H

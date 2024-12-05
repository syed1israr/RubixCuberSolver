//
// Created by Asus on 05-12-2024.
//

#ifndef CORNERPATTERNDATABASE_H
#define CORNERPATTERNDATABASE_H
#include "../../Generic_Rubix_Cube_Solver.h"
#include "../Database/Pattern_Database.h"
#include "../Permutation Indexer/Permutation_Indexer.h"
using namespace std;


class CornerPatternDatabase : public Pattern_Database{
    typedef Generic_Rubix_Cube_Solver::FACE F;
    Permutation_Indexer<8> permIndexer;
public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const Generic_Rubix_Cube_Solver& cube) const;
};



#endif //CORNERPATTERNDATABASE_H

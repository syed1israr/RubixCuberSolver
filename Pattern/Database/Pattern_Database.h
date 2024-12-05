//
// Created by Asus on 05-12-2024.
//

#ifndef PATTERN_DATABASE_H
#define PATTERN_DATABASE_H
#include "../../Generic_Rubix_Cube_Solver.h"
#include "../nibble_array/nibble.h"
#include <bits/stdc++.h>

class Pattern_Database {
    nibble database;
    size_t size;
    size_t numItems;

    Pattern_Database();

public:
    Pattern_Database(const size_t size);
    Pattern_Database(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const Generic_Rubix_Cube_Solver &cube) const = 0;

    virtual bool setNumMoves(const Generic_Rubix_Cube_Solver &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const Generic_Rubix_Cube_Solver &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

    virtual vector<uint8_t> inflate() const;

    virtual void reset();
};



#endif //PATTERN_DATABASE_H

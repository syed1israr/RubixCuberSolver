//
// Created by Asus on 30-11-2024.
//

#ifndef PATTERNDATABASE_H
#define PATTERNDATABASE_H
#include "NibbleArray.h"
#include "../Generic_Rubix_Cube_Solver.h"
#include  "bits/stdc++.h"

class PatternDatabase {
    NibbleArray db;
    size_t size;
    size_t numItems;

    PatternDatabase();

    public:
    PatternDatabase(const size_t size);
    PatternDatabase(const size_t size, uint8_t init_val);

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



#endif //PATTERNDATABASE_H

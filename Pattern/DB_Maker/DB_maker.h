//
// Created by Asus on 05-12-2024.

#ifndef DB_MAKER_H
#define DB_MAKER_H
#include "../CornerPatternDatabase/CornerPatternDatabase.h"
#include "../../RubiksBitBoardRepresentation.cpp"
using namespace std;

class DB_maker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;
public:
    DB_maker(string _fileName);
    DB_maker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};



#endif //DB_MAKER_H

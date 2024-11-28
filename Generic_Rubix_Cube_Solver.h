//
// Created by Asus on 25-11-2024.
//

#ifndef GENERIC_RUBIX_CUBE_SOLVER_H
#define GENERIC_RUBIX_CUBE_SOLVER_H

#include "bits/stdc++.h"

using namespace std;

class Generic_Rubix_Cube_Solver {
public:
    enum  class FACE {
        UP ,
        LEFT,
        RIGHT,
        DOWN,
        BACK,
        FRONT
    };
    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L,LPRIME,L2,
        R,RPRIME,R2,
        U,UPRIME,U2,
        D,DPRIME,D2,
        F,FPRIME,F2,
        B,BPRIME,B2
    };

    virtual  COLOR getColor(FACE face,unsigned row , unsigned col) const = 0;

    virtual bool isSolved() const = 0;

    static char getColorLetter(COLOR color);

    static string getMove(MOVE ind);
    void print() ;

    vector<MOVE>randomShuffleCube(unsigned int times);
    Generic_Rubix_Cube_Solver &move(MOVE ind);
    Generic_Rubix_Cube_Solver &invert(MOVE ind);



    virtual  Generic_Rubix_Cube_Solver &f() = 0;
    virtual  Generic_Rubix_Cube_Solver &fPrime() = 0;
    virtual  Generic_Rubix_Cube_Solver &f2() = 0;
    virtual  Generic_Rubix_Cube_Solver &u() = 0;
    virtual  Generic_Rubix_Cube_Solver &uPrime() = 0;
    virtual  Generic_Rubix_Cube_Solver &u2() = 0;
    virtual  Generic_Rubix_Cube_Solver &l() = 0 ;
    virtual  Generic_Rubix_Cube_Solver &lPrime() = 0;
    virtual  Generic_Rubix_Cube_Solver &l2() = 0;
    virtual  Generic_Rubix_Cube_Solver &r() = 0;
    virtual  Generic_Rubix_Cube_Solver &d() = 0;
    virtual  Generic_Rubix_Cube_Solver &dPrime() = 0;
    virtual  Generic_Rubix_Cube_Solver &d2() = 0;
    virtual  Generic_Rubix_Cube_Solver &rPrime() = 0;
    virtual  Generic_Rubix_Cube_Solver &r2() = 0;
    virtual  Generic_Rubix_Cube_Solver &b() = 0;
    virtual  Generic_Rubix_Cube_Solver &bPrime() = 0;
    virtual  Generic_Rubix_Cube_Solver &b2() = 0;

    string getCornerColorString(uint8_t ind) ;
    uint8_t getCornerIndex(uint8_t ind) ;
    uint8_t getCornerOrientation(uint8_t ind) ;
};



#endif //GENERIC_RUBIX_CUBE_SOLVER_H

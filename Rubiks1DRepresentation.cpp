#include "Generic_Rubix_Cube_Solver.h"
//
// Created by Asus on 28-11-2024.
//


class Rubiks1DRepresentation : public Generic_Rubix_Cube_Solver {
    private:
    static inline int getIndex(int x, int y, int z) {
        return (x*9) + (y*3) + z;
    }
    void rotateFace(int idx) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i*3 + j] = cube[getIndex(idx,i,j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[getIndex(idx, 0, i)] = temp_arr[getIndex(0, 2 - i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(idx, i, 2)] = temp_arr[getIndex(0, 0, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(idx, 2, 2 - i)] = temp_arr[getIndex(0, i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(idx, 2 - i, 0)] = temp_arr[getIndex(0, 2, 2 - i)];
    }
    public:
    char cube[54] = {};
    Rubiks1DRepresentation() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i*9+j*3+k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[getIndex((int)face, (int)row, (int)col)];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }

    };

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[getIndex(i, j, k)] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
        return true;
    }


    Generic_Rubix_Cube_Solver &u() override {
        this->rotateFace(0);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = temp_arr[i];

        return *this;
    };
    Generic_Rubix_Cube_Solver &u2() override {
        this->u();
        this->u();
        return *this;
    };
    Generic_Rubix_Cube_Solver &uPrime() override {
        this->u();
        this->u();
        this->u();
        return *this;
    };

    Generic_Rubix_Cube_Solver &l() override {
        this->rotateFace(1);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    };
    Generic_Rubix_Cube_Solver &l2() override {
        this->l();
        this->l();
        return *this;
    };
    Generic_Rubix_Cube_Solver &lPrime() override {
        this->l();
        this->l();
        this->l();
        return *this;
    };
    Generic_Rubix_Cube_Solver &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    };
    Generic_Rubix_Cube_Solver &f2() override {
        this->f();
        this->f();
        return *this;
    };
    Generic_Rubix_Cube_Solver &fPrime() override {
        this->f();
        this->f();
        this->f();
        return *this;
    };
    Generic_Rubix_Cube_Solver &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    };
    Generic_Rubix_Cube_Solver &r2() override {
        this->r();
        this->r();
        return *this;
    };
    Generic_Rubix_Cube_Solver &rPrime() override {
        this->r();
        this->r();
        this->r();
        return *this;
    };

    Generic_Rubix_Cube_Solver &b() override {
        this->rotateFace(4);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    };

    Generic_Rubix_Cube_Solver &bPrime() override {
        this->b();
        this->b();
        this->b();
        return *this;
    };
    Generic_Rubix_Cube_Solver &b2() override {
        this->b();
        this->b();
        return *this;
    };

    Generic_Rubix_Cube_Solver &d() override {
        this->rotateFace(5);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    };
    Generic_Rubix_Cube_Solver &dPrime() override {
        this->d();
        this->d();
        this->d();
        return *this;
    };
    Generic_Rubix_Cube_Solver &d2() override {
        this->d();
        this->d();
        return *this;
    };


    bool operator==(const Rubiks1DRepresentation &r1) const {
        for (int i = 0; i < 54; i++) {
            if ( cube[i] != r1.cube[i]) return false;
        }
        return true;
    }
    Rubiks1DRepresentation &operator=(const Rubiks1DRepresentation &r1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = r1.cube[i];

        }
        return *this;
    }
    struct  Hash1D {
        size_t operator()(const Rubiks1DRepresentation &r1) {
            string str = "";
            for (int i = 0; i < 54; i++) str+=(r1.cube[i]);
            return hash<string>()(str);
        }
    };
};
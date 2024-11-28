//
// Created by Asus on 28-11-2024.
//

#include "Generic_Rubix_Cube_Solver.h"

class Rubiks3DArray : public  Generic_Rubix_Cube_Solver {
    private:
    void rotateFace(int ind) {
        char temp_arr[3][3] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2-i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2-i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2-i][0] = temp_arr[2][2-i];
    }
    public:
    char cube[6][3][3];
    Rubiks3DArray() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'G':
                return COLOR::GREEN;
            case 'R':
                return COLOR::RED;
            case 'Y':
                return COLOR::YELLOW;
            case 'W':
                return COLOR::WHITE;
            default:
                return COLOR::ORANGE;
        }
    };

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    return false;
                }
            }
        }
    };

    Generic_Rubix_Cube_Solver &u() override {
        this->rotateFace(0);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2-i];
        for (int i = 0; i < 3; i++) cube[4][0][2-i] = cube[1][0][2-i];
        for (int i = 0; i < 3; i++) cube[1][0][2-i] = cube[2][0][2-i];
        for (int i = 0; i < 3; i++) cube[2][0][2-i] = cube[3][0][2-i];
        for (int i = 0; i < 3; i++) cube[3][0][2-i] = temp_arr[i];
        return *this;
    };

    Generic_Rubix_Cube_Solver &uPrime() override {
        this->u();
        this->u();
        this->u();
        return *this;
    };

    Generic_Rubix_Cube_Solver &u2() override {
        this->u();
        this->u();
        return *this;
    };

    Generic_Rubix_Cube_Solver &l() override {
        this->rotateFace(1);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2-i][2];
        for (int i = 0; i < 3; i++) cube[4][2-i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    };
    Generic_Rubix_Cube_Solver &lPrime() override {
        this->l();
        this->l();
        this->l();
        return *this;
    };
    Generic_Rubix_Cube_Solver &l2() override {
        this->l();
        this->l();
        return *this;
    };

    Generic_Rubix_Cube_Solver &f() override {
        this->rotateFace(2);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2-i][2];
        for (int i = 0; i < 3; i++) cube[1][2-i][2] = cube[5][0][2-i];
        for (int i = 0; i < 3; i++) cube[5][0][2-i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];
        return *this;
    };
    Generic_Rubix_Cube_Solver &fPrime() override {
        this->f();
        this->f();
        this->f();
        return *this;
    }
    Generic_Rubix_Cube_Solver &f2() override {
        this->f();
        this->f();
        return *this;
    };

    Generic_Rubix_Cube_Solver &r() override {
        this->rotateFace(3);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2-i][2];
        for (int i = 0; i < 3; i++) cube[0][2-i][2] = cube[2][2-i][2];
        for (int i = 0; i < 3; i++) cube[2][2-i][2] = cube[5][2-i][2];
        for (int i = 0; i < 3; i++) cube[5][2-i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];
        return *this;
    };
    Generic_Rubix_Cube_Solver &rPrime() override {
        this->r();
        this->r();
        this->r();
        return *this;
    };
    Generic_Rubix_Cube_Solver &r2() override {
        this->r();
        this->r();
        return *this;
    };
    Generic_Rubix_Cube_Solver &b() override {
        this->rotateFace(4);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2-i];
        for (int i = 0; i < 3; i++) cube[0][0][2-i] = cube[3][2-i][2];
        for (int i = 0; i < 3; i++) cube[3][2-i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];
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
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];
        return *this;
    };
    Generic_Rubix_Cube_Solver &dPrime() override {
        this->d();
        this->d();
        this->d();
        return *this;
    }
    Generic_Rubix_Cube_Solver &d2() override {
        this->d();
        this->d();
        return *this;
    }

    bool operator==(const Rubiks3DArray &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    Rubiks3DArray &operator=(const Rubiks3DArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }

    struct  Hash3d {
        size_t operator()(const Rubiks3DArray &r1) const {
            string str = "";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        str += to_string(r1.cube[i][j][k]);
                    }
                }
            }
            return hash<string>()(str);
        }
    };

};
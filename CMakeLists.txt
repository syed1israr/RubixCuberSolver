cmake_minimum_required(VERSION 3.30)
project(RubixCuberSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubixCuberSolver main.cpp
        Generic_Rubix_Cube_Solver.cpp
        Generic_Rubix_Cube_Solver.h
        Rubiks3DRepresentation.cpp
        Rubiks1DRepresentation.cpp
)

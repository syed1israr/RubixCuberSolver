cmake_minimum_required(VERSION 3.30)
project(RubixCuberSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubixCuberSolver main.cpp
        GenericRubixCube.cpp
        GenericRubixCube.h)

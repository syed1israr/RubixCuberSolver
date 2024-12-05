cmake_minimum_required(VERSION 3.30)
project(RubixCuberSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubixCuberSolver main.cpp
        Generic_Rubix_Cube_Solver.cpp
        Generic_Rubix_Cube_Solver.h
        Rubiks3DRepresentation.cpp
        Rubiks1DRepresentation.cpp
        RubiksBitBoardRepresentation.cpp
        Solvers/DFS_Solver.h
        Solvers/BFS_Solver.h
        Solvers/IDDFS_Solver.h
        Solvers/IDAStart_Solver.h
        Patterns/CornerDBMaker.cpp
        Patterns/CornerDBMaker.h
        Patterns/CornerPatternDatabase.cpp
        Patterns/CornerPatternDatabase.h
        Patterns/PatternDatabase.cpp
        Patterns/PatternDatabase.h
        Patterns/math.cpp
        Patterns/math.h
        Patterns/NibbleArray.cpp
        Patterns/NibbleArray.h
        Patterns/PermutationIndexer.h
        Solvers/Dummy.h
)

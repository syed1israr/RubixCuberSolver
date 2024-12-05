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
        Solvers/Dummy.h
        Pattern/nibble_array/nibble.cpp
        Pattern/nibble_array/nibble.h
        Pattern/Database/Pattern_Database.cpp
        Pattern/Database/Pattern_Database.h
        "Pattern/Permutation Indexer/Math.cpp"
        "Pattern/Permutation Indexer/Math.h"
        "Pattern/Permutation Indexer/Permutation_Indexer.h"
        Pattern/CornerPatternDatabase/CornerPatternDatabase.cpp
        Pattern/CornerPatternDatabase/CornerPatternDatabase.h
)

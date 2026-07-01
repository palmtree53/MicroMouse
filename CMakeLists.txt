cmake_minimum_required(VERSION 4.2)
project(cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        cpp main.cpp
        src/TestClass.cpp
        src/TestClass.h
        src/Simulation/Simulation.cpp
        src/Simulation/Simulation.h
        src/Simulation/Grid.h
        src/Simulation/Location.cpp
        src/Simulation/Location.h
        src/Simulation/Direction.h
        src/Simulation/Cell.h
        src/Simulation/Maze.cpp
        src/Simulation/Maze.h
        src/View/MazeView.cpp
        src/View/MazeView.h
        src/Simulation/Robot.cpp
        src/Simulation/Robot.h
        src/Controller/SimulationController.cpp
        src/Controller/SimulationController.h
        src/Adapter/GridLoader.cpp
        src/Adapter/GridLoader.h
        src/Simulation/algorithms/ExplorationAlgorithm.cpp
        src/Simulation/algorithms/ExplorationAlgorithm.h
        src/Simulation/UnknownCell.h
        src/Simulation/AbstractCell.h
        src/Simulation/RobotCell.h
        src/Simulation/AbstractCell.cpp
        src/Simulation/algorithms/ExplorationAlgRandom.cpp
        src/Simulation/algorithms/ExplorationAlgRandom.h
        src/Simulation/algorithms/ExplorationAlgSimpleDFS.cpp
        src/Simulation/algorithms/ExplorationAlgSimpleDFS.h
        src/Simulation/algorithms/OptimizationAlgorithm.cpp
        src/Simulation/algorithms/OptimizationAlgorithm.h
        src/Simulation/algorithms/OptimizationAlgorithmBFS.cpp
        src/Simulation/algorithms/OptimizationAlgorithmBFS.h
)

target_include_directories(cpp PRIVATE
        third_party
)

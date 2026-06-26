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
        src/Simulation/Cell.cpp
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
)

target_include_directories(cpp PRIVATE
        third_party
)

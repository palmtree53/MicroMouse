cmake_minimum_required(VERSION 4.2)
project(cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        cpp main.cpp
        src/Simulation/Simulation.cpp
        src/Simulation/Simulation.h
        src/Simulation/Grid.h
        src/Simulation/Location.cpp
        src/Simulation/Location.h
        src/Simulation/Direction.h
        src/Simulation/MazeCell.h
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
        src/Simulation/AbstractCell.h
        src/Simulation/RobotCell.h
        src/Simulation/AbstractCell.cpp
        src/Simulation/RobotDfsExplorer.cpp
        src/Simulation/RobotDfsExplorer.h
        src/Simulation/RobotBFSOptimizerNew.cpp
        src/Simulation/RobotBFSOptimizerNew.cpp
        src/Simulation/RobotState.h
        src/View/MenuView.cpp
        src/View/MenuView.h
        src/Simulation/GameState.h
        src/View/MazePreview.cpp
        src/View/MazePreview.h
        src/Simulation/RobotRandomExplorer.cpp
        src/Simulation/RobotRandomExplorer.h
)

target_include_directories(cpp PRIVATE
        third_party
)
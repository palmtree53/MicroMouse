//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_SIMULATION_H
#define CPP_SIMULATION_H
#include "Cell.h"
#include "Maze.h"
#include "Robot.h"
#include <iostream>

//todo change everything that keeps hardcoded 16x16 grid
//todo kto wie gdzie znajduje się robot? robot? labirynt? czy symulacja?
class Simulation {

public:
    // Simulation(
    //     const Grid<Cell>& grid,
    //     Robot robot = Robot(Location(0, 8)),
    //     Location startPosition = Location(0, 8),
    //     Location endPosition = Location(8, 8)
    // );

    Simulation(
        const Maze& maze,
        Robot robot
    );
    void nextStep();
    [[nodiscard]] bool gameEnded() const;
    [[nodiscard]] Location getRobotLocation() const;
    [[nodiscard]] Maze getMaze() const;

private:
    Maze maze;
    Robot robot;
};



#endif //CPP_SIMULATION_H

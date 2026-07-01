//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_SIMULATION_H
#define CPP_SIMULATION_H
#include "Cell.h"
#include "Maze.h"
#include "Robot.h"
#include <iostream>

#include "algorithms/ExplorationAlgorithm.h"

//todo change everything that keeps hardcoded 16x16 grid
//todo kto wie gdzie znajduje się robot? robot? labirynt? czy symulacja?
class Simulation {

public:

    Simulation(
        const Maze& maze,
        const Robot& robot
    );
    // void nextStep();
    // [[nodiscard]] bool gameEnded() const;
    [[nodiscard]] Location getRobotLocation() const;
    [[nodiscard]] const Maze& getMaze() const;
     Robot& getRobot();

private:
    Maze maze;
    Robot robot;
    // ExplorationAlgorithm algorithm; polimorfizm - dodac tutaj albo w robocie
};



#endif //CPP_SIMULATION_H

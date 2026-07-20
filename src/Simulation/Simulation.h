//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_SIMULATION_H
#define CPP_SIMULATION_H
#include "Maze.h"
#include "Robot.h"

class Simulation {

public:

    Simulation(
        Maze& maze,
        Robot* robot
    );
    void nextStep();
    // [[nodiscard]] bool gameEnded() const;
    [[nodiscard]] Location getRobotLocation() const;
    [[nodiscard]] const Maze& getMaze() const;
    [[nodiscard]] const Robot * getRobot() const;

    [[nodiscard]] bool isFinished() const;

    // [[nodiscard]] Grid<RobotCell> getRobotMaze() const;

    // Robot& getRobot();
    ~Simulation() { delete robot; }
    Simulation(const Simulation&) = delete;
    Simulation& operator=(const Simulation&) = delete;
    Simulation(Simulation&& other) noexcept
            : maze(std::move(other.maze)), robot(other.robot) {
        other.robot = nullptr;
    }
    Simulation& operator=(Simulation&& other) noexcept {
        if (this != &other) {
            delete robot;
            maze = std::move(other.maze);
            robot = other.robot;
            other.robot = nullptr;
        }
        return *this;
    }

    // [[nodiscard]] int getExplorationStepNumber() const;
    // [[nodiscard]] int getOptimizationStepNumber() const;

private:
    Maze maze;
    Robot* robot;
};



#endif //CPP_SIMULATION_H

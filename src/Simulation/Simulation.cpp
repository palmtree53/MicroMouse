//
// Created by aleks on 14.04.2026.
//

#include "Simulation.h"
#include <iostream>

using namespace std;

Simulation::Simulation(
        Maze& maze,
        Robot* robot
    ): maze(maze), robot(robot) {
    cout<<"initializing simualtion"<<endl;
    cout<<"robot's initial location: "<<robot->getLocation().x()<<", "<<robot->getLocation().y()<<endl;
    cout<<"end initialization"<<endl<<endl;
}

Simulation::Simulation(Simulation&& other) noexcept
        : maze(std::move(other.maze)), robot(other.robot) {
    other.robot = nullptr;
}

Simulation& Simulation::operator=(Simulation&& other) noexcept {
    if (this != &other) {
        delete robot;
        maze = std::move(other.maze);
        robot = other.robot;
        other.robot = nullptr;
    }
    return *this;
}

Simulation::~Simulation() { delete robot; }

bool Simulation::nextStep() const {
    auto stepResult = robot->nextStep(maze.possibleMoves(robot->getLocation()), maze.containsGoal(robot->getLocation()));
    cout<<"next step, robot location: "<<robot->getLocation().x()<<", "<<robot->getLocation().y()
    <<"     exploration steps: "<<robot->getStepNumber()
    <<"     opptimization steps: "<<robot->getOptimalPathStepNumber()
    <<"     dead end count: "<<robot->getDeadEndCount()<<" "
    <<endl<<endl;
    cout << "\033[J"; //for when some contents are shorter
    return stepResult;
}



[[nodiscard]] const Maze& Simulation::getMaze() const {
    return maze;
}

[[nodiscard]] const Robot * Simulation::getRobot() const {
    return robot;
}



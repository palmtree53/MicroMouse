//
// Created by aleks on 14.04.2026.
//

#include "Simulation.h"

Simulation::Simulation(
        const Maze& maze,
        const Robot& robot
    ): maze(maze), robot(robot) {
    cout<<"initializing simualtion"<<endl;
    //todo assertions for start location and end location
    cout<<"end location : "<<maze.getEnd().x()<<", "<<maze.getEnd().y()<<endl;
    cout<<"start location: "<<maze.getStart().x()<<", "<<maze.getStart().y()<<endl;
    cout<<"robot location: "<<robot.getLocation().x()<<", "<<robot.getLocation().y()<<endl;
    cout<<"end initialization"<<endl<<endl;
};

// void Simulation::nextStep() {
//     set<Direction> possibleDirections = maze.possibleDirections(robot.getLocation());
//     robot.move(possibleDirections);
//     cout<<"next step, robot location: "<<robot.getLocation().x()<<", "<<robot.getLocation().y()<<endl;
// }

// [[nodiscard]] bool Simulation::gameEnded() const {
//     return robot.getLocation() == maze.getEnd();
// }


[[nodiscard]] Location Simulation::getRobotLocation() const {
    return robot.getLocation();
}

[[nodiscard]] const Maze& Simulation::getMaze() const {
    return maze;
}

Robot& Simulation::getRobot() {return robot;}
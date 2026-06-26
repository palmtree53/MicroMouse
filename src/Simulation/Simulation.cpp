//
// Created by aleks on 14.04.2026.
//

#include "Simulation.h"


//create simulation based on parameters
Simulation::Simulation(
    //settings
    const Grid<Cell>& grid,
    const Robot robot = Robot(Location(0, 8)),
    const Location startPosition = Location(0, 8),
    const Location endPosition = Location(8, 8)
): maze(grid, startPosition, endPosition), robot(robot){
    cout<<"initializing simualtion"<<endl;
    //todo assertions for start location and end location
    cout<<"end location : "<<endPosition.x()<<", "<<endPosition.y()<<endl;
    cout<<"start location: "<<startPosition.x()<<", "<<startPosition.y()<<endl;
    cout<<"robot location: "<<robot.getLocation().x()<<", "<<robot.getLocation().y()<<endl;
    cout<<"end initialization"<<endl<<endl;
}

void Simulation::nextStep() {
    robot.move();
    cout<<"next step, robot location: "<<robot.getLocation().x()<<", "<<robot.getLocation().y()<<endl;
}

[[nodiscard]] bool Simulation::gameEnded() const {
    return robot.getLocation() == maze.getEnd();
}


[[nodiscard]] Location Simulation::getRobotLocation() const {
    return robot.getLocation();
}

[[nodiscard]] Maze Simulation::getMaze() const {
    return maze;
}
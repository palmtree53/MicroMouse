//
// Created by aleks on 14.04.2026.
//

#ifndef CPP_SIMULATION_H
#define CPP_SIMULATION_H
#include <iostream>
#include <ostream>

#include "Cell.h"
#include "Maze.h"
#include "Robot.h"

//todo change everything that keeps hardcoded 16x16 grid
//todo kto wie gdzie znajduje się robot? robot? labirynt? czy symulacja?
class Simulation {

public:
    //create simulation based on parameters
    Simulation(
        //settings
        const Grid<Cell, 16, 16> grid = Grid<Cell, 16, 16>(),
        Robot robot = Robot(),
        Location startPosition = Location(0, 8),
        Location endPosition = Location(8, 8)
    ): maze(grid, startPosition, endPosition), robot(robot), robotLocation(startPosition) {
        cout<<"initializing simualtion"<<endl;
        //todo assertions for start location and end location
        cout<<"end location : "<<endPosition.x()<<", "<<endPosition.y()<<endl;
        cout<<"start location: "<<startPosition.x()<<", "<<startPosition.y()<<endl;
        cout<<"robot location: "<<robotLocation.x()<<", "<<robotLocation.y()<<endl;
        cout<<"end initialization"<<endl<<endl;
    }

    void nextStep() {
            robotLocation = robot.move(robotLocation);
            cout<<"next step, robot location: "<<robotLocation.x()<<", "<<robotLocation.y()<<endl;
    }

    bool gameEnded() {
        return robotLocation == maze.getEnd();
    }


    [[nodiscard]] Location getRobotLocation() const {
        return robotLocation;
    }

    [[nodiscard]] Maze getMaze() const {
        return maze;
    }

    // [[nodiscard]] Robot getRobot() const {
    //     return robot;
    // }

private:
    Location robotLocation;
    Maze maze;
    Robot robot;

};



#endif //CPP_SIMULATION_H

//
// Created by aleks on 21.06.2026.
//

#include "SimulationController.h"




Simulation SimulationController::create() {

    //settings
    auto maze = loadMaze("../resources/maze1.json"); //change paths to working directory if if necessary
    auto robot = Robot(maze.getStart());
    //todo walidacje labiryntu
    auto simulation = Simulation(maze, robot);


    cout<<"Simulation initialized"<<endl;
    view.draw(simulation.getMaze(), simulation.getRobotLocation());

    return simulation;
}


void SimulationController::run(Simulation &simulation) {
    do {
        simulation.nextStep();
        view.draw(simulation.getMaze(), simulation.getRobotLocation());
    } while (!simulation.gameEnded());
    cout<<"Game Ended"<<endl;

    //todo assertionts if robot is moving or game not ended or non-ending loop

    view.draw(simulation.getMaze(), simulation.getRobotLocation());
}